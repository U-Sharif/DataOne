#include "gpiohandler.h"

// CONSTRUCTOR
GPIOHandler::GPIOHandler(QObject *parent) :
    QThread(parent)
{
    // Defaults.
    ReaderStartTrigger = NoTrigger;
    isConnected = true;
    isReading = false;
    isPerformingActionAlert = false;
    isVentilatorRunning = false;
    isBeeping = false;
    IsExternalBatteryFailed = false;
    isNetworkConnectionAvailable = true;
    NumberOfClientsConnected = 0;
    Gpi1LastPulseTime = QDateTime::currentDateTime(); // So that time difference of first pulse is correct.
    Gpi1PulseCount = 0;

    BeepDurationTimer.setSingleShot(true); // Timeout only once.
    connect(&BeepDurationTimer, SIGNAL(timeout()), this, SLOT(StopBeep())); // Connect timer timeout to action slot.

    ActionAlertDurationTimer.setSingleShot(true);       // Timeout only once.
    ActionAlertBeepTimer.setSingleShot(true);           // Timeout only once.
    ActionAlertPauseTimer.setSingleShot(true);          // Timeout only once.
    GPI2StopDelayTimer.setSingleShot(true);             // Timeout only once.
    GPI3SwitchStartDurationTimer.setSingleShot(true);   // Timeout only once.
    GPI3SwitchStopDurationTimer.setSingleShot(true);    // Timeout only once.
    BackupPowerReadingStopTimer.setSingleShot(true);    // Timeout only once.

    connect(&ActionAlertDurationTimer, SIGNAL(timeout()), this, SLOT(ClearActionAlert()));          // Connect timer timeout to action slot.
    connect(&ActionAlertBeepTimer, SIGNAL(timeout()), this, SLOT(StopActionAlertBeepFlash()));      // Connect timer timeout to action slot.
    connect(&ActionAlertPauseTimer, SIGNAL(timeout()), this, SLOT(StartActionAlertBeepFlash()));    // Connect timer timeout to action slot.

    connect(&GPI2StopDelayTimer, SIGNAL(timeout()), this, SLOT(GPI2DelayTimerFinished()));              // Connect timer timeout to action slot.
    connect(&GPI3SwitchStartDurationTimer, SIGNAL(timeout()), this, SLOT(GPI3StartTimerFinished()));    // Connect timer timeout to action slot.
    connect(&GPI3SwitchStopDurationTimer, SIGNAL(timeout()), this, SLOT(GPI3StopTimerFinished()));      // Connect timer timeout to action slot.

    connect(&BackupPowerReadingStopTimer, SIGNAL(timeout()), this, SLOT(BackupPowerTimeout()));
}

void GPIOHandler::run()
{
    // This timer will update GPO ports at regular intervals.
    QTimer GpoStatusTimer;
    connect(&GpoStatusTimer, SIGNAL(timeout()), this, SLOT(UpdateGpo2Status()));
    connect(&GpoStatusTimer, SIGNAL(timeout()), this, SLOT(UpdateGpo3Status()));
    GpoStatusTimer.start(500);

    // Generate GPIO ready beep once only.
    QTimer::singleShot(50, this, SLOT(GPIOReadyBeep()));

    // Generate repeated alerts for battery fail.
    QTimer BatteryFailAelrtTimer;
    connect(&BatteryFailAelrtTimer, SIGNAL(timeout()), this, SLOT(SendBatteryFailAlert()));
    BatteryFailAelrtTimer.start(10000);


    // Start eventloop of new thread.
    exec();
}




//PUBLIC SLOT
void GPIOHandler::GPIChanged(GpiChangedEventArgs args, QDateTime TimeStamp)
{
    //emit Log(QString("\n<<GPIO>> GPIO %1 triggered.\n\r").arg(args.PortNumber));    //Debug


    switch (args.PortNumber)
    {
        case 1:
            // Battery voltage pulse
            if (args.State == GpioState_High)
            {
                //emit Log("<<GPIO>> Input 1 = GpioState_High. \n\r");

                QDateTime Gpi1ThisPulseTime = TimeStamp;
                double PulseTimeDelta = Gpi1LastPulseTime.msecsTo(Gpi1ThisPulseTime);
                Gpi1LastPulseTime = Gpi1ThisPulseTime;

                //emit Log(QString("Interval = %1 msec. \n\r").arg(PulseTimeDelta));

                // Calculate present voltage value.
                double PresentVoltageValue = 15.0 / (PulseTimeDelta / 1000.0);

                //Filter spikes or troughs due to uneven thread timings.
                if (PresentVoltageValue > 8 && PresentVoltageValue < 18)
                {
                    BatteryVoltageValue[Gpi1PulseCount] = PresentVoltageValue;
                    Gpi1PulseCount++;
                }

                // Calculate average voltage value over 10 pulses.
                if (Gpi1PulseCount == 10)
                {
                    // Reset counter and clear last average value.
                    Gpi1PulseCount = 0;
                    BatteryVoltageLevel = 0;

                    // Add all 10 readings.
                    for (int i = 0; i < 10; i++)
                    {
                        BatteryVoltageLevel += BatteryVoltageValue[i];
                    }

                    // Average value and restrict to one decimal place.
                    //BatteryVoltageLevel /= 10.0;
                    //BatteryVoltageLevel *= 10.0;
                    BatteryVoltageLevel = floor(BatteryVoltageLevel) / 10;
                    //BatteryVoltageLevel /= 10.0;

                    // Backup filter for spikes over average value.
                    if (BatteryVoltageLevel > 8 && BatteryVoltageLevel < 18)
                        emit UpdateBatteryVoltage(BatteryVoltageLevel);

                    // Generate alert for low voltage.
                    if (BatteryVoltageLevel < 10.3)
                    {
                        emit Log("SYSTEM", "!!Alert!! Battery Voltage below 10.3V.\n\r");
                        emit Log("", "\n\r");

                        emit Broadcast("message 90 low.batt.voltage\r\n");
                    }
                }
            }
            break;
        case 2:
            // Light beam switch. Stays HIGH as long as light path is interrupted.
            // The reading should stop after some delay. The delay is defined in DataOne.ini file.
            // GPI2 comes from photocells, and pulses may be very small.
            // Therefore, a delay has been introduced to get the proper tag reading.
            if (args.State == GpioState_High)
            {
                if (!isReading)
                {
                    emit StartReading(); ReaderStartTrigger = TriggeredByGpi2;
                }
                else
                {
                    // Cancel the timer to keep the radio reading.
                    GPI2StopDelayTimer.stop();
                }
            }
            else if (args.State == GpioState_Low)
            {
                // Stop the reading after some delay. Start delay timer.
                GPI2StopDelayTimer.start(SystemSettings->DataOneDeviceSettings.GPI2StopDelay);
            }
            break;
        case 3:
            // Manual ON/OFF switch. Remains HIGH as long as it is pressed.
            if (args.State == GpioState_High)
            {
                if (!isReading)
                {
                    emit RefreshAntennas();
                    GPI3SwitchStartDurationTimer.start(1000);
                }
                else
                {
                    if (IsExternalBatteryFailed)
                    {
                        // If external battery has failed, switch must be pressed for 3 sec to stop reading.
                        GPI3SwitchStopDurationTimer.start(3000);
                    }
                    else
                    {
                        // Switch must be pressed for 1 sec to stop reading.
                        GPI3SwitchStopDurationTimer.start(1500);
                    }
                }
            }
            else if (args.State == GpioState_Low)
            {
                // If switch is pressed for a shorter interval than the timer, do not let the reading stop.
                GPI3SwitchStartDurationTimer.stop();
                GPI3SwitchStopDurationTimer.stop();
            }
            break;
        case 4:
            // External battery fail signal. Will go HIGH if battery fails.
            if (args.State == GpioState_High)
            {
                IsExternalBatteryFailed = true;

                if (isReading)
                    BackupPowerReadingStopTimer.start(SystemSettings->BackupPowerReadingCutOffTime * 60 * 1000 );
                else
                    setGPO(3, false); // This will put green lamp ON, so that HW does not disconnect power yet. This GPO is inverted.

                // Alert the clients.
                emit Log("GPIO", "!!ALERT!! External battery source failed.\n\r");
                emit Log("", "\n\r");

                emit Broadcast("message 90 ext.bat.disconnect\r\n");

                // Shutdown application if not reading.
                if (!isReading)
                {
                    emit CommandToReader("d1_shutdown");
                }
            }
            else if (args.State == GpioState_Low)
            {
                IsExternalBatteryFailed = false;
                BackupPowerReadingStopTimer.stop();

                // Alert the clients.
                emit Log("GPIO", "!!ALERT!! External battery connected.\n\r");
                emit Log("", "\n\r");

                emit Broadcast("message 10 ext.bat.connect\r\n");
            }

            break;
    }
}

//PUBLIC SLOT
void GPIOHandler::LLRPConnected(bool State)
{
    // Store LLRP connection state.
    isConnected = State;
}

//PUBLIC SLOT
void GPIOHandler::ReadingStarted(bool State)
{
    // Store tag reading state.
    isReading = State;
}

//PUBLIC SLOT
void GPIOHandler::StartTagReportBeep()
{
    // Gpo1 controls beeper.
    if (!isPerformingActionAlert)
    {
        if (isConnected)
        {
            if (isBeeping)
            {
                BeepDurationTimer.stop();
                emit setGPO(1, false);      // Break the old beep.
                msleep(10);                 // Insert a little pause before beep for next tag starts.
            }

            emit setGPO(1, true); isBeeping = true; // Start beeping.
            BeepDurationTimer.start(SystemSettings->DataOneDeviceSettings.Beep_Duration); // Set timer for stopping the beep.
        }
    }
}

//PUBLIC SLOT
void GPIOHandler::StopBeep()
{
    // Gpo1 controls beeper.
    emit setGPO(1, false); isBeeping = false;
}

//PUBLIC SLOT
void GPIOHandler::UpdateTemperature(int Temperature)
{
    // Gpo4 controls external ventilation fan.
    if (Temperature > 35)
    {
        if (isConnected)
        {
            // Start the ventilator fan.
            emit setGPO(4, true);
            isVentilatorRunning = true;
        }

    }
    else if (Temperature < 30 && isVentilatorRunning)
    {
        if (isConnected)
        {
            // Stop the ventilator fan.
            emit setGPO(4, false);
            isVentilatorRunning = false;
        }
    }

    //emit setGPO(4, true); //Testing
    //emit Log(QString("Temperature = %1\n\r").arg(Temperature));
}

//PUBLIC SLOT
void GPIOHandler::ClientConnected()
{
    NumberOfClientsConnected++;
    //emit Log(QString("<<GPIO>> Number of clients connected = %1 \n\r)").arg(NumberOfClientsConnected));
}

//PUBLIC SLOT
void GPIOHandler::ClientDisconnected()
{
    NumberOfClientsConnected--;
    //emit Log(QString("<<GPIO>> Number of clients connected = %1 \n\r)").arg(NumberOfClientsConnected));
}

//PUBLIC SLOT
void GPIOHandler::StartActionAlert(int Type)
{
    //if (!IsExternalBatteryFailed)
    //{

        isPerformingActionAlert = true;
        ActionAlertType = Type;

        // On different action alrt types, generate different timing patterns.
        switch (Type)
        {
            case 1:
                ActionAlertBeepTimer.setInterval(100);
                ActionAlertPauseTimer.setInterval(1000);
                ActionAlertPauseTimer.start();
                break;
            case 2:
                ActionAlertBeepTimer.start(100);
                ActionAlertPauseTimer.setInterval(30);
                ActionAlertPauseTimer.start();
                break;
            case 3:
                ActionAlertBeepTimer.start(30);
                ActionAlertPauseTimer.setInterval(30);
                ActionAlertPauseTimer.start();
                if (isConnected) emit setGPO(1, true);          //Beeper.
                break;
            case 4:                                             // This action alert is for missing USB at startup. This action alert will beep continuously.
                ActionAlertBeepTimer.setInterval(100);
                ActionAlertPauseTimer.setInterval(1000);
                ActionAlertPauseTimer.start();
                break;
            default:
                return;
                break;
        }

        ActionAlertCount = 0; ActionAlertSwitch = false;

        if (Type < 4)
        {
            ActionAlertDurationTimer.start(15000);
            emit Log("GPIO", QString("Performing Action Alert : %1\n\r").arg(Type));
            emit Log("", "\n\r");
        }
    //}
    //else
    //    emit Log("GPIO", QString("Action Alerts disabled.\n\r"));
}

//PUBLIC SLOT
void GPIOHandler::NetworkAvailable()
{
    // Network is available.
    isNetworkConnectionAvailable = true;
}

//PUBLIC SLOT
void GPIOHandler::NetworkNotAvailable()
{
    // Network is not available.
    isNetworkConnectionAvailable = false;
}



//PRIVATE SLOT
void GPIOHandler::UpdateGpo2Status()
{
    // Gpo2 controls client and timing server connection indicator lamp.
    if (!isNetworkConnectionAvailable)
    {
        emit setGPO(2, true); // Put the lamp OFF. This GPO is inverted.
        return;
    }


    if (!isPerformingActionAlert)
    {
        if (NumberOfClientsConnected > 0)
        {
            if (isConnected)
                emit setGPO(2, false); // Put the lamp ON. This GPO is inverted.
        }
        else
        {
            if (isConnected)
                emit setGPO(2, true);  // Put the lamp OFF. This GPO is inverted.
        }
    }
}

//PRIVATE SLOT
void GPIOHandler::UpdateGpo3Status()
{
    // Gpo3 controls Reading ON/OFF lamp.
    if (IsExternalBatteryFailed)
    {
        // Keep reading lamp ON
        if (isConnected)
            emit setGPO(3, false); // This will put green lamp ON, so that HW does not disconnect power yet. This GPO is inverted.

        return;
    }


    if (!isPerformingActionAlert)
    {
        if (isReading)
        {
            if (isConnected)
                emit setGPO(3, false); // Put the lamp ON. This GPO is inverted.
        }
        else
        {
            if (isConnected)
                emit setGPO(3, true); // Put the lamp OFF. This GPO is inverted.
        }
    }
}

//PRIVATE SLOT
void GPIOHandler::ClearActionAlert()
{
    // Stop all timres and set GPO states to default.

    ActionAlertBeepTimer.stop();
    ActionAlertPauseTimer.stop();

    isPerformingActionAlert = false;

    if (isConnected) emit setGPO(1, false);     // Beeper.
    if (isConnected) emit setGPO(2, true);      // Network indicator Lamp.

}

//PRIVATE SLOT
void GPIOHandler::StartActionAlertBeepFlash()
{
    // This is part of the Start/Stop logic for Action Alerts.
    // Beeping and flashing starts here.
    // See StopActionAlertBeepFlash() for the Stop logic.

    if (isPerformingActionAlert)
    {
        if (ActionAlertType == 1 || ActionAlertType == 4)
        {
            if (isConnected) emit setGPO(1, true);   //Beeper
            if (isConnected) emit setGPO(2, true);   //Lamp
            ActionAlertBeepTimer.start();
        }
        else if (ActionAlertType == 2)
        {
            if (isConnected) emit setGPO(1, true);   //Beeper
            if (isConnected) emit setGPO(2, false);  //Lamp
            ActionAlertBeepTimer.start();
        }
        else if (ActionAlertType == 3)
        {
            if (isConnected) emit setGPO(2, ActionAlertSwitch);    //Lamp
            ActionAlertBeepTimer.start();
        }
    }
}

//PRIVATE SLOT
void GPIOHandler::StopActionAlertBeepFlash()
{
    // This is part of the Start/Stop logic for Action Alerts.
    // Beeping and flashing stops here.
    // See StartActionAlertBeepFlash() for the Start logic.

    if (ActionAlertType == 1 || ActionAlertType == 4)
    {
        if (isConnected) emit setGPO(1, false);   //Beeper
        if (isConnected) emit setGPO(2, false);   //Lamp
        ActionAlertPauseTimer.start();
    }
    else if (ActionAlertType == 2)
    {
        if (isConnected) emit setGPO(1, false);   //Beeper
        if (isConnected) emit setGPO(2, true);    //Lamp
        ActionAlertPauseTimer.start();
    }
    else if (ActionAlertType == 3)
    {
        if (isConnected) emit setGPO(2, !ActionAlertSwitch);    //Lamp
        ActionAlertPauseTimer.start();
        ActionAlertCount++;
        if (ActionAlertCount == 3) {ActionAlertSwitch = !ActionAlertSwitch; ActionAlertCount = 0;}
    }
}

//PRIVATE SLOT
void GPIOHandler::GPIOReadyBeep()
{
    // Generate a 3 beep pattern on startup indicating GPIO is ready.

    if (isConnected) emit setGPO(1, true);  // Beep.
    msleep(300);                            // Beep Duration.
    if (isConnected) emit setGPO(1, false); // Silence.
    msleep(200);                            // Silence Duration.
    if (isConnected) emit setGPO(1, true);  // Beep.
    msleep(300);                            // Beep Duration.
    if (isConnected) emit setGPO(1, false); // Silence.
    msleep(200);                            // Silence Duration.
    if (isConnected) emit setGPO(1, true);  // Beep.
    msleep(300);                            // Beep Duration.
    if (isConnected) emit setGPO(1, false); // Silence.

}

//PRIVATE SLOT
void GPIOHandler::GPI2DelayTimerFinished()
{
    // On timeout, stop reading.

    emit StopReading(); ReaderStartTrigger = NoTrigger;
}

//PRIVATE SLOT
void GPIOHandler::GPI3StartTimerFinished()
{
    emit StartReading(); ReaderStartTrigger = TriggeredByGpi3;

    emit Log("GPIO", "Reading started manually.\n\r");
    emit Log("", "\n\r");

    emit Broadcast("message 10 rdng.start.manual\r\n");
}

//PRIVATE SLOT
void GPIOHandler::GPI3StopTimerFinished()
{
    // If timer finished, before reading ON/OFF switch release, then stop reading.

    emit StopReading(); ReaderStartTrigger = NoTrigger;

    emit Log("GPIO", "Reading stopped manually.\n\r");
    emit Log("", "\n\r");

    emit Broadcast("message 10 rdng.stop.manual\r\n");
}

//PRIVATE SLOT
void GPIOHandler::BackupPowerTimeout()
{
    emit StopReading();
    emit CommandToReader("d1_shutdown");
}

//PRIVATE SLOT
void GPIOHandler::SendBatteryFailAlert()
{
    if (IsExternalBatteryFailed)
        emit Broadcast("message 90 ext.bat.disconnect\r\n");
}
