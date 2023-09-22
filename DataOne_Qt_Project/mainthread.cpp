#include "mainthread.h"

MainThread::MainThread(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType<GpiChangedEventArgs>("GpiChangedEventArgs");

    // Console log buffer.
    LogBuffer = new QBuffer(this);
    LogBuffer->open(QBuffer::ReadWrite);

    // Setup application running timer.
    ApplicationRunningTime = 0;
    ApplicationRunningTimer.start(60000);
    connect(&ApplicationRunningTimer, SIGNAL(timeout()), this, SLOT(UpdateApplicationRunningTime()));

    // Application Settings
    SystemSettings = new DataOneSettings(this);

    // Console log web uploader
    MessageCounter = 1;
    LogUploader = new WebUploader(this);
    LogUploader->SystemSettings = SystemSettings;
    LogUploader->start();
    connect(LogUploader, SIGNAL(Log(QString,QString)), this, SLOT(WriteApplicationLog(QString,QString)));

    // System Monitor.
    SystemManager = new SystemMonitor(SystemSettings, this);
    SystemManager->SystemSettings = SystemSettings;

    connect(SystemManager, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));
    connect(SystemManager, SIGNAL(Broadcast(QString)), this, SLOT(SendBroadcast(QString)));

    SystemManager->start();


    //Console log file writer. Initialized only if EnableWriteConsoleLog is true in settings.
    if (SystemSettings->DataOneApplicationSettings.EnableWriteConsoleLog)
    {
        FileWriter_Console = new ConsoleFileWriter(SystemSettings, this);

        connect(this, SIGNAL(WriteLogToDisk(QByteArray)), FileWriter_Console, SLOT(RecordLog(QByteArray)));

        connect(SystemManager, SIGNAL(USBMemoryPlugged()), FileWriter_Console, SLOT(USBMemoryPlugged()));

        FileWriter_Console->start();
    }

    // Tcp console server. Initialized only if EnableConsolePort is true in settings.
    if (SystemSettings->DataOneApplicationSettings.EnableConsolePort)
    {
        WriteApplicationLog("STATUS", QString("Initializing Console server.\n\r"));
        TcpServer_Console = new TcpConsoleServer(this);
        TcpServer_Console->SystemSettings = SystemSettings;
        TcpServer_Console->LogBuffer = LogBuffer;

        connect(this, SIGNAL(SendLogToRemoteConsoles(QByteArray)), TcpServer_Console, SLOT(SendNewLog(QByteArray)));

        connect(TcpServer_Console, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));
        connect(TcpServer_Console, SIGNAL(Command_GetRunningTime()), this, SLOT(SendApplicationRunningTime()));


        TcpServer_Console->StartServer();
    }




    // Show all settings on console.
    ShowAllSettings();




    // Reader.
    WriteApplicationLog("STATUS", QString("Initializing Reader.\n\r"));
    RFIDReader = new Reader(this);
    RFIDReader->SystemSettings = SystemSettings;

    connect(RFIDReader, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));
    connect(RFIDReader, SIGNAL(SaveDeviceSettings()), SystemSettings, SLOT(SaveDeviceSettings()));
    connect(RFIDReader, SIGNAL(Broadcast(QString)), this, SLOT(SendBroadcast(QString)));
    connect(RFIDReader, SIGNAL(UpdateAntennaState(QString)), TcpServer_Console, SLOT(StoreAntennaState(QString)));

    connect(RFIDReader, SIGNAL(DataOneShutdown()), LogUploader, SLOT(quit()));
    connect(RFIDReader, SIGNAL(DataOneShutdown()), SystemManager, SLOT(quit()));
    connect(RFIDReader, SIGNAL(DataOneShutdown()), TcpServer_Console, SLOT(Shutdown()));

    connect(TcpServer_Console, SIGNAL(ClientCommand(QByteArray)), RFIDReader, SLOT(ParseClientCommand(QByteArray)));


    RFIDReader->Run("localhost");

    if (true)
    {
        // GPIO.
        WriteApplicationLog("STATUS", QString("Initializing GPIO Handler.\n\r"));
        WriteApplicationLog("", "\n\r");

        GpioHandler = new GPIOHandler(this);
        GpioHandler->SystemSettings = SystemSettings;
        connect(RFIDReader, SIGNAL(GPIChanged(GpiChangedEventArgs, QDateTime)), GpioHandler, SLOT(GPIChanged(GpiChangedEventArgs, QDateTime)));
        connect(RFIDReader, SIGNAL(StartTagReportBeep()), GpioHandler, SLOT(StartTagReportBeep()));
        connect(RFIDReader, SIGNAL(LLRPConnected(bool)), GpioHandler, SLOT(LLRPConnected(bool)));
        connect(RFIDReader, SIGNAL(ReadingStarted(bool)), GpioHandler, SLOT(ReadingStarted(bool)));
        connect(RFIDReader, SIGNAL(UpdateTemperature(int)), GpioHandler, SLOT(UpdateTemperature(int)));
        connect(RFIDReader, SIGNAL(PerformActionAlert(int)), GpioHandler, SLOT(StartActionAlert(int)));
        connect(RFIDReader, SIGNAL(DataOneShutdown()), GpioHandler, SLOT(quit()));

        connect(GpioHandler, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));
        connect(GpioHandler, SIGNAL(Broadcast(QString)), this, SLOT(SendBroadcast(QString)));
        connect(GpioHandler, SIGNAL(setGPO(int,bool)), RFIDReader, SLOT(setGPO(int,bool)));
        connect(GpioHandler, SIGNAL(StartReading()), RFIDReader, SLOT(StartReading()));
        connect(GpioHandler, SIGNAL(StopReading()), RFIDReader, SLOT(StopReading()));
        connect(GpioHandler, SIGNAL(RefreshAntennas()), RFIDReader, SLOT(RefreshAntennas()));
        connect(GpioHandler, SIGNAL(CommandToReader(QByteArray)), RFIDReader, SLOT(ParseClientCommand(QByteArray)));

        connect(SystemManager, SIGNAL(USBMemoryUnplugged(int)), GpioHandler, SLOT(StartActionAlert(int)));
        connect(SystemManager, SIGNAL(NetworkAvailable()), GpioHandler, SLOT(NetworkAvailable()));
        connect(SystemManager, SIGNAL(NetworkNotAvailable()), GpioHandler, SLOT(NetworkNotAvailable()));

        GpioHandler->start();



        //Tcp data server. Initialized only if EnableDataPort is true in settings.
        if (SystemSettings->DataOneApplicationSettings.EnableDataPort)
        {
            WriteApplicationLog("STATUS", QString("Initializing Data server.\n\r"));
            TcpServer_Data = new TcpDataServer(this);
            TcpServer_Data->SystemSettings = SystemSettings;

            connect(TcpServer_Data, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));
            connect(TcpServer_Data, SIGNAL(ClientCommand(QByteArray)), RFIDReader, SLOT(ParseClientCommand(QByteArray)));
            connect(TcpServer_Data, SIGNAL(ClientConnected()), GpioHandler, SLOT(ClientConnected()));
            connect(TcpServer_Data, SIGNAL(ClientDisconnected()), GpioHandler, SLOT(ClientDisconnected()));

            connect(RFIDReader, SIGNAL(NewDataRecordAvailable(QByteArray,quint64)), TcpServer_Data, SLOT(SendTagData(QByteArray,quint64)));
            connect(RFIDReader, SIGNAL(UpdateTemperature(int)), TcpServer_Data, SLOT(UpdateTemperature(int)));
            connect(RFIDReader, SIGNAL(UpdateAntennaState(QString)), TcpServer_Data, SLOT(StoreAntennaState(QString)));
            connect(RFIDReader, SIGNAL(ReadingStarted(bool)), TcpServer_Data, SLOT(ReadingStarted(bool)));
            connect(RFIDReader, SIGNAL(ClearBuffers()), TcpServer_Data, SLOT(ClearBuffers()));
            connect(RFIDReader, SIGNAL(ClearAllLogs()), TcpServer_Data, SLOT(ClearBuffers()));
            connect(RFIDReader, SIGNAL(DataOneShutdown()), TcpServer_Data, SLOT(Shutdown()));

            connect(GpioHandler, SIGNAL(UpdateBatteryVoltage(double)), TcpServer_Data, SLOT(UpdateBatteryVoltage(double)));

            connect(this, SIGNAL(SendBroadcastMessage(QByteArray)), TcpServer_Data, SLOT(SendBroadcast(QByteArray)));

            TcpServer_Data->StartServer();
        }

        //Tcp filtered server. Initialized only if EnableFilteredPort is true in settings.
        if (SystemSettings->DataOneApplicationSettings.EnableFilteredPort)
        {
            WriteApplicationLog("STATUS", QString("Initializing Filtered server.\n\r"));
            TcpServer_Filtered = new TcpFilteredServer(this);
            TcpServer_Filtered->SystemSettings = SystemSettings;

            connect(TcpServer_Filtered, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));
            connect(TcpServer_Filtered, SIGNAL(ClientCommand(QByteArray)), RFIDReader, SLOT(ParseClientCommand(QByteArray)));
            connect(TcpServer_Filtered, SIGNAL(ClientConnected()), GpioHandler, SLOT(ClientConnected()));
            connect(TcpServer_Filtered, SIGNAL(ClientDisconnected()), GpioHandler, SLOT(ClientDisconnected()));

            connect(RFIDReader, SIGNAL(NewFilteredRecordAvailable(QByteArray,quint64)), TcpServer_Filtered, SLOT(SendTagData(QByteArray,quint64)));
            connect(RFIDReader, SIGNAL(UpdateTemperature(int)), TcpServer_Filtered, SLOT(UpdateTemperature(int)));
            connect(RFIDReader, SIGNAL(UpdateAntennaState(QString)), TcpServer_Filtered, SLOT(StoreAntennaState(QString)));
            connect(RFIDReader, SIGNAL(ReadingStarted(bool)), TcpServer_Filtered, SLOT(ReadingStarted(bool)));
            connect(RFIDReader, SIGNAL(ClearBuffers()), TcpServer_Filtered, SLOT(ClearBuffers()));
            connect(RFIDReader, SIGNAL(ClearAllLogs()), TcpServer_Filtered, SLOT(ClearBuffers()));
            connect(RFIDReader, SIGNAL(DataOneShutdown()), TcpServer_Filtered, SLOT(Shutdown()));

            connect(GpioHandler, SIGNAL(UpdateBatteryVoltage(double)), TcpServer_Filtered, SLOT(UpdateBatteryVoltage(double)));

            connect(this, SIGNAL(SendBroadcastMessage(QByteArray)), TcpServer_Filtered, SLOT(SendBroadcast(QByteArray)));

            TcpServer_Filtered->StartServer();
        }


        //Data file writer. Initialized only if EnableWriteDataLog is true in settings.
        if (SystemSettings->DataOneApplicationSettings.EnableWriteDataLog)
        {
            WriteApplicationLog("STATUS", QString("Initializing Data file writer.\n\r"));
            WriteApplicationLog("", "\n\r");

            FileWriter_Data = new DataFileWriter(this);
            FileWriter_Data->SystemSettings = SystemSettings;

            connect(FileWriter_Data, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));

            connect(SystemManager, SIGNAL(USBMemoryPlugged()), FileWriter_Data, SLOT(USBMemoryPlugged()));

            connect(RFIDReader, SIGNAL(ClearBuffers()), FileWriter_Data, SLOT(ClearBuffers()));
            connect(RFIDReader, SIGNAL(ClearAllLogs()), FileWriter_Data, SLOT(ClearAllLogs()));
            connect(RFIDReader, SIGNAL(NewDataRecordAvailable(QByteArray,quint64)), FileWriter_Data, SLOT(EnqueueTag(QByteArray,quint64)));
            connect(RFIDReader, SIGNAL(DataOneShutdown()), FileWriter_Data, SLOT(Shutdown()));

            FileWriter_Data->start();
        }

        //Filtered file writer. Initialized only if EnableWriteFilteredLog is true in settings.
        if (SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
        {
            WriteApplicationLog("STATUS", QString("Initializing Filtered file writer.\n\r"));
            WriteApplicationLog("", "\n\r");

            FileWriter_Filtered = new FilteredFileWriter(this);
            FileWriter_Filtered->SystemSettings = SystemSettings;

            connect(FileWriter_Filtered, SIGNAL(Log(QString, QString)), this, SLOT(WriteApplicationLog(QString, QString)));

            connect(SystemManager, SIGNAL(USBMemoryPlugged()), FileWriter_Filtered, SLOT(USBMemoryPlugged()));

            connect(RFIDReader, SIGNAL(ClearBuffers()), FileWriter_Filtered, SLOT(ClearBuffers()));
            connect(RFIDReader, SIGNAL(ClearAllLogs()), FileWriter_Filtered, SLOT(ClearAllLogs()));
            connect(RFIDReader, SIGNAL(NewFilteredRecordAvailable(QByteArray,quint64)), FileWriter_Filtered, SLOT(EnqueueTag(QByteArray,quint64)));
            connect(RFIDReader, SIGNAL(DataOneShutdown()), FileWriter_Filtered, SLOT(Shutdown()));

            FileWriter_Filtered->start();
        }
    }
    else
    {
        WriteApplicationLog("ERROR", QString("Initializing RFID reader failed. Please reboot.\n\n\r"));
    }

    // Initialization finished.
}

//PRIVATE
void MainThread::ShowAllSettings()
{
    // Show the application settings on console on startup.
    // This function is only called once on startup during this class's constructor.

    WriteApplicationLog("GENERAL", QString("DataOne launched. (version %1)\n\r").arg(SystemSettings->DataOneApplicationSettings.AppVersion));
    WriteApplicationLog("", "\n\r");

    QString ConfigurationLog;
    ConfigurationLog.append(QString("\n\r"));
    ConfigurationLog.append(QString("------------------------------------------------\n\r"));
    ConfigurationLog.append(QString("- Enable Write Data Log = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableWriteDataLog))));
    ConfigurationLog.append(QString("- Enable Write Filtered Log = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog))));
    ConfigurationLog.append(QString("- Enable Write Console Log = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableWriteConsoleLog))));
    ConfigurationLog.append(QString("- Enable Data Port = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableDataPort))));
    ConfigurationLog.append(QString("- Enable Filtered Port = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableFilteredPort))));
    ConfigurationLog.append(QString("- Enable Console Port = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableConsolePort))));
    ConfigurationLog.append(QString("- Enable TimingServer 1 = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableTimingServer1))));
    ConfigurationLog.append(QString("- Enable TimingServer 2 = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneApplicationSettings.EnableTimingServer2))));
    ConfigurationLog.append(QString("------------------------------------------------\n\r"));
    ConfigurationLog.append(QString("- Data Port = %1 \n\r").arg(QString::number(SystemSettings->DataOneNetworkSettings.DataPort)));
    ConfigurationLog.append(QString("- Filtered Port = %1 \n\r").arg(QString::number(SystemSettings->DataOneNetworkSettings.FilteredPort)));
    ConfigurationLog.append(QString("- Console Port = %1 \n\r").arg(QString::number(SystemSettings->DataOneNetworkSettings.ConsolePort)));
    ConfigurationLog.append(QString("- Ping Interval = %1 sec. \n\r").arg(QString::number(SystemSettings->DataOneNetworkSettings.PingInterval)));
    ConfigurationLog.append(QString("- Max Connected Clients = %1 \n\r").arg(QString::number(SystemSettings->DataOneNetworkSettings.MaxConnectedClients)));
    ConfigurationLog.append(QString("- TimingServer 1 Address = %1 \n\r").arg(SystemSettings->DataOneNetworkSettings.TimingServer1Address));
    ConfigurationLog.append(QString("- TimingServer 2 Address = %1 \n\r").arg(SystemSettings->DataOneNetworkSettings.TimingServer2Address));
    ConfigurationLog.append(QString("- Timing Servers Base Port = %1 \n\r").arg(QString::number((int) SystemSettings->DataOneNetworkSettings.TimingServerBasePort)));
    ConfigurationLog.append(QString("- Log Upload Server Address = %1 \n\r").arg(SystemSettings->DataOneNetworkSettings.LogUploadServerAddress));
    ConfigurationLog.append(QString("- Log Upload Server Using SSL = %1 \n\r").arg(QString(BoolToString(SystemSettings->DataOneNetworkSettings.LogUploadServerUseSSL))));
    ConfigurationLog.append(QString("------------------------------------------------\n\r"));
    ConfigurationLog.append(QString("- Reader Mode = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Reader_Mode));
    ConfigurationLog.append(QString("- Search Mode = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Search_Mode));
    ConfigurationLog.append(QString("- Session = %1 \n\r").arg(QString::number(SystemSettings->DataOneDeviceSettings.Session)));
    ConfigurationLog.append(QString("- Frequency = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Frequency));
    ConfigurationLog.append(QString("- Tag Volume = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Tag_Volume));
    ConfigurationLog.append(QString("- Antennas = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Antennas));
    ConfigurationLog.append(QString("- Beep = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Beep));
    ConfigurationLog.append(QString("- Beep Duration = %1 \n\r").arg(QString::number(SystemSettings->DataOneDeviceSettings.Beep_Duration)));
    ConfigurationLog.append(QString("- Filter Length = %1 \n\r").arg(QString::number(SystemSettings->DataOneDeviceSettings.FilterLength)));
    ConfigurationLog.append(QString("- Filter Drift = %1 \n\r").arg(QString::number(SystemSettings->DataOneDeviceSettings.FilterDrift)));
    ConfigurationLog.append(QString("- Time Point Desc = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.TimePointDesc));
    ConfigurationLog.append(QString("- GPI3 Stop Delay = %1 msec.\n\r").arg(SystemSettings->DataOneDeviceSettings.GPI2StopDelay));
    ConfigurationLog.append(QString("------------------------------------------------\n\r"));
    ConfigurationLog.append(QString("- Reader # = %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Reader_Number));
    ConfigurationLog.append(QString("- Previous Reading Status = %1 \n\r").arg(QString(BoolToString(SystemSettings->GetReadingStatus()))));
    ConfigurationLog.append(QString("------------------------------------------------\n\r"));
    ConfigurationLog.append(QString("- Time Zone = %1 \n\r").arg(SystemSettings->DataOneTimeSettings.TimeZoneString));
    ConfigurationLog.append(QString("------------------------------------------------\n\r"));

    WriteApplicationLog("CONFIGURATION", ConfigurationLog);
    WriteApplicationLog("", "\n\r");

}


//PUBLIC SLOT
void MainThread::SendApplicationRunningTime()
{
    // Just write the application running time on console.
    WriteApplicationLog("STATUS", QString("%1 Hrs : %2 Min\n\r").arg(ApplicationRunningTime / 60).arg(ApplicationRunningTime % 60));
}



//PRIVATE SLOT
void MainThread::WriteApplicationLog(QString MessageType, QString LogStatement)
{
    // Upload log to web server
    if (!MessageType.isEmpty() && !LogStatement.isEmpty())     // Empty messages are only for inserting space on console.
    {
        LogUploader->QueueMessage(MessageCounter, MessageType, LogStatement);
        MessageCounter++;
    }

    QByteArray Entry;
    if (!MessageType.isEmpty()) Entry.append(QString("<<%1>> ").arg(MessageType));
    Entry.append(LogStatement);

    // Write entry to log buffer.
    LogBuffer->write(Entry);

    // Write entry on attached standard IO.
    printf("%s", Entry.data());

    // Send log entry to Tcp console server for sending to all connected console clients.
    if (SystemSettings->DataOneApplicationSettings.EnableConsolePort)
    {
        emit SendLogToRemoteConsoles(Entry);
    }

    // Send entry to console log writer thread.
    emit WriteLogToDisk(Entry);

}

//PRIVATE SLOT
void MainThread::SendBroadcast(QString LogStatement)
{
    // Send the broadcast entry to all Tcp servers, and onward delivery to all conencted clients of every type.
    emit SendBroadcastMessage(LogStatement.toLocal8Bit());
}

//PRIVATE SLOT
void MainThread::UpdateApplicationRunningTime()
{
    // Add a minute to application running time. This function is on timer.
    ApplicationRunningTime += 1; //minutes
}

