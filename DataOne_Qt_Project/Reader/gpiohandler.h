#ifndef GPIOHANDLER_H
#define GPIOHANDLER_H

#include <cmath>

#include <QThread>
#include <QTimer>
#include <QDateTime>

#include "../Settings/settings.h"
#include "../Enums/enums.h"

#include <OctaneSdk.h>

using namespace Impinj_OctaneSdk;


// This class handles all aspects related to General Purpose IO (GPIO).
// GPIOHandler object will run in a separate thread, to offload prcessing from reader thread.
// This class inherits QThread of Qt framework, which provides functionality for making multi-threaded applications.

class GPIOHandler : public QThread
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit GPIOHandler(QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

private:

    // Array to hold 10 battery voltage values.
    double BatteryVoltageValue[10];

    // Object to hold time when last GPI1 pulse was received.
    QDateTime Gpi1LastPulseTime;
    int Gpi1PulseCount;

    // Computed average of ten voltage values.
    double BatteryVoltageLevel;

    bool isConnected;                   // LLRP connected ?
    bool isReading;                     // Is reader reading ?
    bool isPerformingActionAlert;       // Is application performing Action alert ?
    bool isVentilatorRunning;           // Is ventilation fan running ?
    bool isBeeping;                     // Is beeper on ?
    bool IsExternalBatteryFailed;       // Is external battery connect signal present or not?

    bool isNetworkConnectionAvailable;  // Is network connected ?

    int ActionAlertType;                // Action alert.
    bool ActionAlertSwitch;             // A switch to create alternating pattern in action alrts.
    int ActionAlertCount;               // A counter for counting the number of beeps and flashes so far.

    int ReaderStartTrigger;             // Enum to keep track of reader starting trigger.
    int NumberOfClientsConnected;       // Keep count of the number of TCP connections present.

    QTimer BeepDurationTimer;           // Timer for controlling tag report beep.

    QTimer ActionAlertDurationTimer;    // Duration is 15 sec.
    QTimer ActionAlertBeepTimer;        // Variable timer.
    QTimer ActionAlertPauseTimer;       // Variable timer.

    QTimer GPI2StopDelayTimer;          // Timer to give some delay in stop reading.
    QTimer GPI3SwitchStartDurationTimer;
    QTimer GPI3SwitchStopDurationTimer;   // Timer to ensure that ON/OFF switch is pressed for some time to stop reading.

    QTimer BackupPowerReadingStopTimer;     // When opering on battery, stop reading after this timer has timedout, to save the battery from total discharge.

protected:

    // Virtual protected function of QThread for launching the thread.
    // This thread will be launched from mainthread.cpp
    void run();

signals:
    void Log(QString, QString);                         // Send log entry to main thread.
    void Broadcast(QString);                            // Send message to all connected TCP clients.

    void setGPO(int PortNumber, bool State);            // Set / Unset GPO states.

    void StartReading();                                // Send manual start reading signal to reader thread.
    void StopReading();                                 // Send manual stop reading signal to redaer thread.
    void RefreshAntennas();                             // Tell the reader thread to refresh antennas.

    void UpdateBatteryVoltage(double);                  // Update current battery voltage value to TCP servers.

    void CommandToReader(QByteArray Command);           // Send internal commands to reader thread.

public slots:
    void GPIChanged(GpiChangedEventArgs args, QDateTime TimeStamp);  // All GPIs states are parsed here.
    void LLRPConnected(bool);                           // Slot connected to reader object for tracking LLRP state.
    void ReadingStarted(bool);                          // Slot connected to reader object for tracking reading state.
    void StartTagReportBeep();                          // Receive signal from reader thread to start Tag report beep. GPO1 controlled here.
    void StopBeep();                                    // Receive signal from reader thread to stop Tag report beep. GPO1 controlled here.
    void UpdateTemperature(int);                        // Receive current temperature value from reader thread.
    void ClientConnected();                             // Receive signal from TCP servers that a new TCP client has been connected.
    void ClientDisconnected();                          // Receive signal from TCP servers that a TCP client has been disconnected.
    void StartActionAlert(int);                         // Receive signal from reader thread to start relevant action alert.
    void NetworkNotAvailable();                         // Receive signal from system monitor thread that network is disconnected.
    void NetworkAvailable();                            // Receive signal from system monitor thread that network is disconnected.


private slots:
    void UpdateGpo2Status();            // Network connections Lamp.
    void UpdateGpo3Status();            // Reading ON/OFF Lamp.

    void StartActionAlertBeepFlash();   // Action alert.
    void StopActionAlertBeepFlash();    // Action alert.
    void ClearActionAlert();            // Action alert.

    void GPIOReadyBeep();               // Beep at application startup.

    void GPI2DelayTimerFinished();      // Fuction to manually insert delay in reading OFF.
    void GPI3StartTimerFinished();      // Function to start reading with delay.
    void GPI3StopTimerFinished();       // Function to stop reading with delay.

    void BackupPowerTimeout();

    void SendBatteryFailAlert();
};

#endif // GPIOHANDLER_H
