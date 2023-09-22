#include "systemmonitor.h"

#include <QProcess>

// CONSTRUCTOR
SystemMonitor::SystemMonitor(DataOneSettings *SysSettings, QObject *parent) :
    QThread(parent)
{
    SystemSettings = SysSettings;

    // Defaults.
    USBDeviceError = false;
    USBAlertIssued = false;
    USBErrorIssued = false;
    isFirstRead = true;
    isFirstUSBCheck = true;
    isSda1Mounted = false;
    isSda1Writable = false;
    InternetAvailablePreviousStatus = false;
    LastNetworkReplyFinished = true;


    // OS file to read CPU statistics from.
    // It is safe to open the file here is constructor, because as long as the OS is running, this file is always present.
    CPUStatFile.setFileName("/proc/stat");
    CPUStatFile.open(QIODevice::ReadOnly);

    // OS file to read RAM statistics from.
    // It is safe to open the file here is constructor, because as long as the OS is running, this file is always present.
    MemoryInfoFile.setFileName("/proc/meminfo");
    MemoryInfoFile.open(QIODevice::ReadOnly);

    // OS file to read statistics about all mounted devices.
    MountPointsFile.setFileName("/proc/mounts");
    CheckSda1();
    if (isSda1Mounted && isSda1Writable) SystemSettings->isUSBDevicePresent = true; // Check here so that ConsoleFileWriter initializes correctly.

    // Initialize Network access manager which is our HTTP engine.
    NAM_InternetConnection = new QNetworkAccessManager(this);
    connect(NAM_InternetConnection, SIGNAL(finished(QNetworkReply*)), this, SLOT(InternetCheckReplyFinished(QNetworkReply*)));

    // Connect PingProcess with slot to parse the ping output.
    connect(&PingProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(OnPingEnded()));
}


//PROTECTED FUNCTION
void SystemMonitor::run()
{
    // This is the main statistics refresh timer.
    QTimer StatsRefreshTimer;
    connect(&StatsRefreshTimer, SIGNAL(timeout()), this, SLOT(CheckCurrentCPUUsage()));
    connect(&StatsRefreshTimer, SIGNAL(timeout()), this, SLOT(CheckCurrentMemoryUsage()));
    connect(&StatsRefreshTimer, SIGNAL(timeout()), this, SLOT(CheckUsbFreeSpace()));
    StatsRefreshTimer.start(10000); // 10 sec.

    // This is the USB presence check timer.
    // This works a little faster than the main timer.
    QTimer USBCheckTimer;
    connect(&USBCheckTimer, SIGNAL(timeout()), this, SLOT(CheckUsbPresent()));
    USBCheckTimer.start(6000); //6 sec.

    // This the internet connectivity check timer.
    // Sends an HTTP request to InternetCheckURL.
    QTimer InternetCheckTimer;
    connect(&InternetCheckTimer, SIGNAL(timeout()), this, SLOT(CheckInternetConnectivityByPING()));
    InternetCheckTimer.start(7000); //7 sec.

    // This is the system time sync timer.
    // Calls ntpdate system command.
    QTimer TimeRefreshTimer;
    connect(&TimeRefreshTimer, SIGNAL(timeout()), this, SLOT(UpdateDateTimeFromNTP()));
    //TimeRefreshTimer.start(10000); //Testing time: 10 Seconds
    TimeRefreshTimer.start(300000); //5 minutes

    // Start eventloop of new thread.
    exec();
}



//PRIVATE FUNCTION
void SystemMonitor::CheckSda1()
{
    isSda1Mounted = false;
    isSda1Writable = false;

    MountPointsFile.open(QIODevice::ReadOnly);
    MountPointsFile.reset();

    QString MountPointFileContents;
    MountPointFileContents.append(MountPointsFile.readAll());

    QStringList MountLines = MountPointFileContents.split("\n");

    for (int i = 0; i < MountLines.size(); i++)
    {
        //qDebug() << "Read: " << MountLines.at(i);

        QStringList MountLineParts = MountLines.at(i).split(" ");

        if (MountLineParts.at(0) == "/dev/sda1")
        {
            if (MountLineParts.at(1) == "/mnt/usbfs/usbsda1")
            {
                isSda1Mounted = true;

                if (MountLineParts.at(3).startsWith("rw"))
                {
                    //printf("USB is writeable.\n");
                    isSda1Writable = true;
                }
             }
        }
    }


    MountPointsFile.close();
}

//PRIVATE SLOT
void SystemMonitor::CheckUsbPresent()
{
    CheckSda1();

    // If sda1 is not mounted then no need checking further.
    if (!isSda1Mounted)
    {
        SystemSettings->isUSBDevicePresent = false; // Retain state in system settings.

        USBDeviceError = true;

        emit Log("SYSTEM", "!!ERROR!! : USB Memory device unplugged.\n\r");
        emit Log("", "\n\r");

        emit Broadcast("message 90 usb.dev.unplugged\r\n"); // Alert the clients.

        if (isFirstUSBCheck)
        {
            emit USBMemoryUnplugged(4); // If USB memory is not present right on the startup, send signal to GPIOHandler to alert user with beeps and lamp flashes.
        }
    }
    else
    {
        SystemSettings->isUSBDevicePresent = true; // Retain state in system settings.

        if (USBDeviceError)
        {
            USBDeviceError = false;

            emit Log("SYSTEM", "USB Memory device plugged.\n\r");
            emit Log("", "\n\r");

            emit Broadcast("message 10 usb.dev.plugged\r\n"); // Alert the clients.

            emit USBMemoryPlugged(); // Inform the file writer threads that USB memory is available, and file writing can start/resume.
        }

        if (!isSda1Writable)
        {
            SystemSettings->isUSBDevicePresent = false; // Retain state in system settings.

            emit Log("SYSTEM", "!!ALERT!! : USB memory device is read-only.\n\r");
            emit Log("ACTION", "Rectifying problem.\n\r");
            emit Log("", "\n\r");

            system("mount -o remount,rw /dev/sda1");
            system("rm /mnt/usbfs/usbsda1/log/log.txt");

            if (isFirstUSBCheck)
                system("reboot");

            //emit Broadcast("message 90 usb.dev.read-only\r\n"); // Alert the clients.
        }
    }

    isFirstUSBCheck = false;

}

//PRIVATE SLOT
void SystemMonitor::CheckCurrentCPUUsage()
{
    CPUStatFile.reset();                        // Reset to set read pointer to the beginning.
    QString CpuStat = CPUStatFile.readLine();   // Important stats are in the first line.
    CpuStat.remove(0,5);                        // Remove initial text.

    QStringList CpuTimes = CpuStat.split(' ');  // Values are space separated.

    //double WorkJiffiesCurrent = CpuTimes.at(0).toInt()+ CpuTimes.at(1).toInt() + CpuTimes.at(2).toInt(); // Add values 1, 2 and 3 to get actually utilized cpu time slots.

    double WorkJiffiesCurrent = CpuTimes.at(0).toInt() + CpuTimes.at(2).toInt(); // Add values 1, and 3 to get actually utilized cpu time slots.

    //double TotalJiffiesCurrent = 0;
    //for (int i = 0; i < CpuTimes.size(); i++)
    //{
    //    TotalJiffiesCurrent += CpuTimes.at(i).toInt();  // Add all values togather to get total cpu time slots during the last interval.
    //}

    double TotalJiffiesCurrent = CpuTimes.at(0).toInt() + CpuTimes.at(2).toInt() + CpuTimes.at(3).toInt(); // Add values 1, and 3 to get actually utilized cpu time slots.

    double WorkDifference = WorkJiffiesCurrent - WorkJiffiesLast;       // Relative difference.
    double TotalDifference = TotalJiffiesCurrent - TotalJiffiesLast;    // Relative difference.

    CpuUsage = (WorkDifference / TotalDifference) * 100.0;              // CPU usage percentage.
    CpuUsage = (CpuUsage + CpuUsageLast)/2;                             // Average to damp out momentary spikes.

    WorkJiffiesLast = WorkJiffiesCurrent;                               // Store current values.
    TotalJiffiesLast = TotalJiffiesCurrent;                             // Store current values.
    CpuUsageLast = CpuUsage;                                            // Store current values.

    if (CpuUsage > 90) HighCpuUsageCount+=10;
    else HighCpuUsageCount = 0;

    if (HighCpuUsageCount > 60 && !isFirstRead) // Do not generate alerts on first iteration.
    {
        emit Log("SYSTEM", "!!ALERT!! : CPU usage above 90%.\n\r");
        emit Log("", "\n\r");

        emit Broadcast("message 80 cpu > 90%\r\n");
    }

    isFirstRead = false;    // Reset first read flag.
}

//PRIVATE SLOT
void SystemMonitor::CheckCurrentMemoryUsage()
{
    MemoryInfoFile.reset();                                 // Reset to set read pointer to the beginning.
    QString MemoryStatTotal = MemoryInfoFile.readLine();    // Read first line. Total RAM available.
    MemoryStatTotal.remove(0, 17);                          // Remove initial text.
    MemoryStatTotal.chop(4);

    QString MemoryStatFree = MemoryInfoFile.readLine();     // Read second line. Total free RAM at this moment.
    MemoryStatFree.remove(0, 17);                           // REmove initial text.
    MemoryStatFree.chop(4);

    double MemStatTotal = MemoryStatTotal.toDouble();
    double MemStatFree = MemoryStatFree.toDouble();

    double MemoryFree = (MemStatFree / MemStatTotal) * 100.0;

    if (MemoryFree < 15)
    {
        system("echo 1 > /proc/sys/vm/drop_caches"); // Set flag, so that OS clears as much chached memory as possible.
    }
    if (MemoryFree < 5)
    {
        emit Log("SYSTEM", "!!ALERT!! : Free memory below 10%.\n\r");
        emit Log("SYSTEM", "Freeing cached memory.\n\r");
        emit Log("", "\n\r");

        emit Broadcast("message 80 free.mem < 5%\r\n");

        system("echo 1 > /proc/sys/vm/drop_caches"); // Set flag, so that OS clears as much chached memory as possible.
    }
}

//PRIVATE SLOT
void SystemMonitor::CheckUsbFreeSpace()
{
    if (SystemSettings->isUSBDevicePresent)
    {

        system("df /dev/sda1 > /tmp/usb_usage.info"); // Run system command to dump sda1 usage statistics to a temporary file.

        QFile usbMemoryInfo;            // Handle to open the temp file.
        QStringList usbMemoryLines;
        QStringList usbMemoryColumns;

        usbMemoryInfo.setFileName("/tmp/usb_usage.info");

        usbMemoryInfo.open(QIODevice::ReadOnly);
        QTextStream readData(&usbMemoryInfo);       // Read dumped data from temp file.

        while (!readData.atEnd())
        {
            usbMemoryLines << readData.readLine();  // Read all data.
        }

        usbMemoryInfo.close();
        usbMemoryInfo.remove();                     // Remove file.

        if (usbMemoryLines.size() > 1)
        {
            usbMemoryColumns = usbMemoryLines.at(1).split(QRegExp("\\s+")); // Split all data.

            //QString MountPath = usbMemoryColumns.at(0);               // Mount path.
            double TotalKBytes = usbMemoryColumns.at(1).toDouble();     // Total storage available.
            //double UsedKBytes = usbMemoryColumns.at(2).toDouble();    // Used.
            double FreeKBytes = usbMemoryColumns.at(3).toDouble();      // Free.

            double PercentageFree = (FreeKBytes / TotalKBytes) * 100.0; // Free space percentage.

            if (PercentageFree > 10 && (USBAlertIssued || USBErrorIssued))
            {
                SystemSettings->DataOneApplicationSettings.EnableWriteDataLog = true;       // Enable file writing.
                SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog = true;   // Enable file writing.
                SystemSettings->DataOneApplicationSettings.EnableWriteConsoleLog = true;    // Enable file writing.

                //TagSaver->ClearBuffer = true;
                //Reader->ResetTagCounters();

                USBAlertIssued = false;     // Clear alert.
                USBErrorIssued = false;     // Clear error.
            }

            if (PercentageFree < 10 && !USBAlertIssued)
            {
                emit Log("SYSTEM", "!!ALERT!! : USB Memory free space is less than 10%.\n\r");
                emit Log("", "\n\r");

                emit Broadcast("message 80 usb.space < 10%\r\n");

                USBAlertIssued = true;  // Alert message has been issued.
            }

            if (PercentageFree < 1 && USBAlertIssued && !USBErrorIssued)
            {
                emit Log("SYSTEM", "!!ERROR!! : USB Memory device full. Log writing disabled.\n\r");
                emit Log("", "\n\r");

                emit Broadcast("message 90 usb.dev.full\r\n");

                SystemSettings->DataOneApplicationSettings.EnableWriteDataLog = false;      // Disable file writing.
                SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog = false;  // Disable file writing.
                SystemSettings->DataOneApplicationSettings.EnableWriteConsoleLog = false;   // Disable file writing.

                USBErrorIssued = true;  // Error message has been issued.
            }

        }
        else
        {
            USBAlertIssued = true;      // If temp file turns up empty, then treat as if alert message has been issued.
            USBErrorIssued = true;      // If temp file turns up empty, then treat as if error message has been issued.
        }
    }
}



//PRIVATE SLOT
void SystemMonitor::CheckInternetConnectivityByHTTP()
{
    // Following is a second method of checking internet connectivity.
    // An HTTP request is sent to InternetCheckURL.
    // If reply contains something, then internet is available.
    // If reply comes empty in case of timeout and other errors, this means internet is not available.
    // If last reply has not finished, we treat it as internet not available.

    if (LastNetworkReplyFinished == false)
        SystemSettings->isInternetAvailable = false;    // Set/Unset internet availability. Will be used by server connection threads.

    if (!TcpServerConnection::isTimingServerConnected && LastNetworkReplyFinished)
    {
        QNetworkRequest GetRequest; // Http request object.
        GetRequest.setUrl(QUrl(SystemSettings->DataOneNetworkSettings.InternetCheckURL));   // Set URL.
        GetRequest.setRawHeader("User-Agent", "DataOne");

        QSslConfiguration SSL_Config = QSslConfiguration::defaultConfiguration();
        SSL_Config.setProtocol(QSsl::AnyProtocol);
        GetRequest.setSslConfiguration(SSL_Config);

        WebReply = NAM_InternetConnection->get(GetRequest);    // Use http-get method to send the request. Just like entering url in a web browser.
        WebReply->ignoreSslErrors();
        connect(WebReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));

        //qDebug() << "HTTP request for Internet connection check launched.";

        LastNetworkReplyFinished = false;           // Unset finished flag.
    }
}

//PRIVATE SLOT
void SystemMonitor::CheckInternetConnectivityByPING()
{
    // Ping based method implmeneted since version 1.6.1 dated 24 June, 2018.
    // Send single ping through system command to InternetCheckIP defined in settings.
    // Read the output of ping command, and parse it.
    // If output has ttl value, then ping was success, else internet is down.

    if (!TcpServerConnection::isTimingServerConnected)
        PingProcess.start("ping", QStringList() << "-c" << "1" << "-w" << "1" << SystemSettings->DataOneNetworkSettings.PingIPAddress);
}

//PRIVATE SLOT
void SystemMonitor::InternetCheckReplyFinished(QNetworkReply *Reply)
{
    LastNetworkReplyFinished = true;        // Set flag.

    QByteArray ReplyContents = Reply->readAll();    // Read everything from the reply.

    //int ReplyError = Reply->error();
    //qDebug() << "HTTP Reply received:" << ReplyContents << Reply->url();

    if (!ReplyContents.isEmpty())                   // If reply is not empty, this means server sent us something.
    {
        SystemSettings->isInternetAvailable = true;     // Internet is available.

        if (InternetAvailablePreviousStatus != SystemSettings->isInternetAvailable)
        {
            emit Log("NETWORK", QString("***** Internet connection is UP *****\n\r\n\r"));
            InternetAvailablePreviousStatus = SystemSettings->isInternetAvailable;
            UpdateDateTimeFromNTP(); // Try to sync time whenever internet is available, when prevoiusly it was unavailable.

        }
    }
    else
    {
        SystemSettings->isInternetAvailable = false;    // If reply is empty, internet is not available.        

        if (InternetAvailablePreviousStatus != SystemSettings->isInternetAvailable)
        {
            emit Log("NETWORK", QString("***** Internet connection is DOWN *****\n\r\n\r"));
            InternetAvailablePreviousStatus = SystemSettings->isInternetAvailable;
        }
    }

    Reply->deleteLater();    // This is essential, otherwise memory leakage will happen.
}


void SystemMonitor::OnPingEnded()
{
    QString ConsoleOutput = QString(PingProcess.readAllStandardOutput());

    if (!ConsoleOutput.isEmpty())
    {
        if (ConsoleOutput.contains("ttl", Qt::CaseInsensitive))
        {
           int ttlIndex = ConsoleOutput.indexOf("time", 0, Qt::CaseInsensitive);
           SystemSettings->InternetPingTime = QString(ConsoleOutput.mid(ttlIndex+5, 5)).toDouble();
           //qDebug("PING(%s) OK : Time = %0.2f ms", SystemSettings->DataOneNetworkSettings.InternetCheckIP.toStdString().c_str(), SystemSettings->InternetPingTime);

           SystemSettings->isInternetAvailable = true;     // Internet is available.

           if (InternetAvailablePreviousStatus != SystemSettings->isInternetAvailable)
           {
               emit Log("NETWORK", QString("***** Internet connection is UP *****\n\r\n\r"));
               InternetAvailablePreviousStatus = SystemSettings->isInternetAvailable;
               UpdateDateTimeFromNTP(); // Try to sync time whenever internet is available, when prevoiusly it was unavailable.
           }
        }
        else
        {
           //qDebug("PING(%s) FAILED", SystemSettings->DataOneNetworkSettings.InternetCheckIP.toStdString().c_str());

           SystemSettings->isInternetAvailable = false;    // If reply is empty, internet is not available.
           CheckInternetConnectivityByHTTP();
        }
    }
}

//PRIVATE SLOT
void SystemMonitor::onError(QNetworkReply::NetworkError Code)
{
    (void)(Code);
    //qDebug() << "HTTP Reply Error:" << Code;

    disconnect(WebReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
    WebReply->deleteLater();
}


//PRIVATE SLOT
void SystemMonitor::UpdateDateTimeFromNTP()
{
    // This function is called from 2 places.
    // 1. TimeRefreshTimer (every 5 minutes).
    // 2. InternetCheckReplyFinished, whenever internet is available, when prevoiusly it was unavailable.

    if (SystemSettings->isNewReader) return; // Do not update time manually from NTP, as new readers do not have ntpdate command.

    if (!SystemSettings->isDateTimeManuallySet) // If date time has been set manually via "set_date_time" command, NTP time sync will be bypassed.
    {

        emit Log("SYSTEM", "Starting system time synchronization.\n\r");

        int Result = SystemSettings->UpdateDateTimeFromNTP();

        switch (Result)
        {
        case 0:
            emit Log("SYSTEM", QString("Time synchronization successful. Current time: %1\n\r"). arg(SystemSettings->GetCurrentDateTimeString()));
            break;
        case 1:
            emit Log("SYSTEM", QString("!!ERROR!! : Time synchronization failed. Could not find NTP server. (code%1)\n\r").arg(Result));
            break;
        case -1:
            emit Log("SYSTEM", QString("!!ERROR!! : Attempt to start ntpdate command crashed. (code %1)\n\r").arg(Result));
            break;
        case -2:
            emit Log("SYSTEM", QString("!!ERROR!! : Could not start ntpdate command. (code%1)\n\r").arg(Result));
            break;
        default:
            emit Log("SYSTEM", QString("!!ERROR!! : Time synchronization failed. (code %1)\n\r").arg(Result));
        }

        if (Result == 0)
        {
            emit Log("ACTION", QString("Synchronizing hardware clock.\n\r"));
            SystemSettings->SynchronizeHardwareClock();
        }

        emit Log("", "\n\r");
    }
}
