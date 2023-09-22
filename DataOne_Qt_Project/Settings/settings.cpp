#include "settings.h"

#include <QProcess>

// CONSTRUCTOR
DataOneSettings::DataOneSettings(QObject *parent) : QObject(parent)
{
    //Application version
    DataOneApplicationSettings.AppVersion = "2.0.3";
    //DataOneApplicationSettings.AppVersion = "Debug";

    // Defaults.
    isTimeZoneAdjustmentEnabled = true;
    isDateTimeManuallySet = false;
    isUSBDevicePresent = false;
    isInternetAvailable = false;
    isNewReader = false;
    BackupPowerReadingCutOffTime = 30; //Minutes.
    DataOneDeviceSettings.isReading = false;

    // Define fixed directories for file structure.
    DataFolderPath = "/mnt/usbfs/usbsda1/data/";
    FilteredFolderPath = "/mnt/usbfs/usbsda1/filtered/";
    ConsoleLogFolderPath = "/mnt/usbfs/usbsda1/log/";

    //Define default static URL for Internet Connection check.
    //DataOneNetworkSettings.InternetCheckURL = "http://services.datasport.com"; //Depricated on 23 June, 2018. Returned 403 Access denied response.
    //DataOneNetworkSettings.InternetCheckURL = "https://services.datasport.com/d1-test.htm"; //Added on 23 June, 2018.
    //DataOneNetworkSettings.InternetCheckIP = "8.8.8.8"; //Google DNS server for Ping test.

    // Define web address to which console log will be uploaded.
    //LogUploadServerAddress = "https://secure.datasport.com/sys/d1_log.cfm"; // Endpoint definition shifted to ini file as of 02 December, 2014.
    //LogUploadServerAddress = "http://www.datasport.com/sys/d1_log.cfm";   // Test URL.

    // Define settings files.
    AppSettings = new QSettings("/cust/app/DataOne.ini", QSettings::IniFormat);
    TimeSettings = new QSettings("/cust/app/TimeZone.ini", QSettings::IniFormat);
    ReaderSettings = new QSettings("/cust/app/ReaderStatus.ini", QSettings::IniFormat);

    // Load settings from DataOne.ini
    LoadApplicationSettings();
    LoadNetworkSettings();
    LoadDeviceSettings();

    // Load settings from TimeZone.ini
    LoadTimeZoneAndDSTSettings();

    // Set reader number based on reader IP address.
    SetReaderNumber();

    // Set footprint file paths.
    DataFootprintFile.setFileName(DataFolderPath + "footprint");
    FilteredFootprintFile.setFileName(FilteredFolderPath + "footprint");

    // Reset footprints once to clear any old data.
    ResetDataFootprint();
    ResetFilteredFootprint();
}


//PUBLIC FUNCTION
void DataOneSettings::SetReaderNumber()
{
    // Get a list of all IP addresses on the reader.
    // Choose the non-loopback address.
    // Set the last part of IP address as reader number.

    // Get all IP addresses.
    QList<QHostAddress> ReaderAddresses = QNetworkInterface::allAddresses();

    for (int i = 0; i < ReaderAddresses.size(); i++)
    {
        printf("Host IP: %s\n", ReaderAddresses.at(i).toString().toLocal8Bit().data());

        // Filter loopback addresses, 127.0.0.1.
        if (ReaderAddresses.at(i) != QHostAddress::LocalHost && ReaderAddresses.at(i).protocol() == QAbstractSocket::IPv4Protocol)
        {
            QString IPAddress = ReaderAddresses.at(i).toString();           // Convert IP address to string.
            QStringList IPOctets = IPAddress.split('.');                    // Split the IP address octets.

            DataOneDeviceSettings.Reader_Number = IPOctets.at(3).toUInt();  // Assign last octet as reader number.
        }
    }
}



//PUBLIC FUNCTION
void DataOneSettings::LogDataFootprint(qint64 FilePosition, QByteArray TagTime)
{
    // Save the given File Position in the data footprint file.

    if (DataFootprintFile.isWritable())
    {
        QByteArray FootprintEntry;
        FootprintEntry.setNum(FilePosition);
        FootprintEntry.append(',');
        FootprintEntry.append(TagTime);
        FootprintEntry.append("\n");
        DataFootprintFile.write(FootprintEntry);
        DataFootprintFile.flush();
    }
}

//PUBLIC FUNCTION
void DataOneSettings::LogFilteredFootprint(qint64 FilePosition, QByteArray TagTime)
{
    // Save the given File Position in the filtered footprint file.

    if (FilteredFootprintFile.isWritable())
    {
        QByteArray FootprintEntry;
        FootprintEntry.setNum(FilePosition);
        FootprintEntry.append(',');
        FootprintEntry.append(TagTime);
        FootprintEntry.append("\n");
        FilteredFootprintFile.write(FootprintEntry);
        FilteredFootprintFile.flush();
    }
}



//PUBLIC FUNCTION
qint64 DataOneSettings::GetDataPosition(qint64 RecordNumber)
{
    // Retrieve file position entry for the relevant RecordNumber.
    // The RecordNumber will be a multiple of 1000.

    // Create a new file handle.
    QFile newDataFootprintFileHandle;
    newDataFootprintFileHandle.setFileName(DataFolderPath + "footprint");
    newDataFootprintFileHandle.open(QIODevice::ReadOnly | QIODevice::Text);

    if (newDataFootprintFileHandle.isReadable())
    {
        // The readLine() function returns a QByteArray.
        QString Position = "0";

        int i = 1;
        while (i++ <= RecordNumber/1000)
        {
            if (newDataFootprintFileHandle.atEnd()) break;

            QByteArray LineRead = newDataFootprintFileHandle.readLine();
            LineRead.chop(1); // Remove the \n at the end.
            QList<QByteArray> DataSplit = LineRead.split(',');
            Position = QString(DataSplit.at(0));
        }

        //printf("Position read = %s\n", Position.toLatin1().data());
        return (qint64)Position.toDouble();
    }
    return 0; // This will make the calling thread start log file reading from start.
}

//PUBLIC FUNCTION
qint64 DataOneSettings::GetFilteredPosition(qint64 RecordNumber)
{
    // Retrieve file position entry for the relevant RecordNumber.
    // The RecordNumber will be a multiple of 1000.

    // Create a new file handle.
    QFile newFilteredFootprintFileHandle;
    newFilteredFootprintFileHandle.setFileName(FilteredFolderPath + "footprint");
    newFilteredFootprintFileHandle.open(QIODevice::ReadOnly | QIODevice::Text);

    if (newFilteredFootprintFileHandle.isReadable())
    {
        // The readLine() function returns a QByteArray.
        QString Position = "0";

        int i = 1;
        while (i++ <= RecordNumber/1000)
        {
            if (newFilteredFootprintFileHandle.atEnd()) break;

            QByteArray LineRead = newFilteredFootprintFileHandle.readLine();
            LineRead.chop(1); // Remove the \n at the end.
            QList<QByteArray> DataSplit = LineRead.split(',');
            Position = QString(DataSplit.at(0));
        }

        //printf("Position read = %d\n", Position.toInt());
        return (qint64)Position.toDouble();
    }
    return 0; // This will make the calling thread start log file reading from start.
}

//PUBLIC FUNCTION
qint64 DataOneSettings::GetDataTimePosition(QDateTime QueryTagTime)
{
    // Retrieve file position entry for the relevant RecordNumber.
    // The RecordNumber will be a multiple of 1000.

    // Create a new file handle.
    QFile newDataFootprintFileHandle;
    newDataFootprintFileHandle.setFileName(DataFootprintFile.fileName());
    newDataFootprintFileHandle.open(QIODevice::ReadOnly | QIODevice::Text);

    if (newDataFootprintFileHandle.isReadable() && newDataFootprintFileHandle.size() > 0)
    {
        // The readLine() function returns a QByteArray.
        QByteArray TimeByteArray = "0";
        QString Position = "0";
        QDateTime RecordDateTime;

        TimeByteArray = newDataFootprintFileHandle.readLine(); //Read first line to know what is the tag time of first record.

        if (TimeByteArray.isEmpty())
            return 0;
        else
        {
            TimeByteArray.chop(1); // Remove the \n at the end.
            QList<QByteArray> DataSplit = TimeByteArray.split(',');
            Position = QString(DataSplit.at(0));
            RecordDateTime = QDateTime::fromString(QString(DataSplit.at(1)), "dd.MM.yyyy hh:mm:ss.zzz"); //Convert time stored in QByteArray to QDateTime.
        }

        if(QueryTagTime < RecordDateTime)
            return 0; //Query date time is less than first record in file, so calling thread will return all records in the file.

        while (RecordDateTime < QueryTagTime)
        {
            if (newDataFootprintFileHandle.atEnd()) break;
            TimeByteArray = newDataFootprintFileHandle.readLine(); //Read first line to know what is the tag time of first record.
            TimeByteArray.chop(1); // Remove the \n at the end.
            QList<QByteArray> DataSplit = TimeByteArray.split(',');
            Position = QString(DataSplit.at(0));
            RecordDateTime = QDateTime::fromString(QString(DataSplit.at(1)), "dd.MM.yyyy hh:mm:ss.zzz"); //Convert time stored in QByteArray to QDateTime.
            //printf("Time read = %s\n", TimeByteArray.data());
        }

        return (qint64)Position.toDouble();
    }
    return 0; // This will make the calling thread start log file reading from start.
}

//PUBLIC FUNCTION
qint64 DataOneSettings::GetFilteredTimePosition(QDateTime QueryTagTime)
{
    // Retrieve file position entry for the relevant RecordNumber.
    // The RecordNumber will be a multiple of 1000.

    // Create a new file handle.
    QFile newFilteredFootprintFileHandle;
    newFilteredFootprintFileHandle.setFileName(FilteredFootprintFile.fileName());
    newFilteredFootprintFileHandle.open(QIODevice::ReadOnly | QIODevice::Text);

    if (newFilteredFootprintFileHandle.isReadable() && newFilteredFootprintFileHandle.size() > 0)
    {
        // The readLine() function returns a QByteArray.
        QByteArray TimeByteArray = "0";
        QString Position = "0";
        QDateTime RecordDateTime;

        TimeByteArray = newFilteredFootprintFileHandle.readLine(); //Read first line to know what is the tag time of first record.

        if (TimeByteArray.isEmpty())
            return 0;
        else
        {
            TimeByteArray.chop(1); // Remove the \n at the end.
            QList<QByteArray> DataSplit = TimeByteArray.split(',');
            Position = QString(DataSplit.at(0));
            RecordDateTime= QDateTime::fromString(QString(DataSplit.at(1)), "dd.MM.yyyy hh:mm:ss.zzz"); //Convert time stored in QByteArray to QDateTime.
        }

        if(QueryTagTime < RecordDateTime)
            return 0; //Query date time is less than first record in file, so calling thread will return all records in the file.

        while (RecordDateTime < QueryTagTime)
        {
            if (newFilteredFootprintFileHandle.atEnd()) break;
            TimeByteArray = newFilteredFootprintFileHandle.readLine(); //Read first line to know what is the tag time of first record.
            TimeByteArray.chop(1); // Remove the \n at the end.
            QList<QByteArray> DataSplit = TimeByteArray.split(',');
            Position = QString(DataSplit.at(0));
            RecordDateTime = QDateTime::fromString(QString(DataSplit.at(1)), "dd.MM.yyyy hh:mm:ss.zzz"); //Convert time stored in QByteArray to QDateTime.
            //printf("Time read = %s\n", TimeByteArray.data());
        }

        return (qint64)Position.toDouble();
    }
    return 0; // This will make the calling thread start log file reading from start.
}



//PUBLIC FUNCTION
void DataOneSettings::ResetDataFootprint()
{
    // Refresh the data log footprint file.

    if (DataFootprintFile.isOpen())
        DataFootprintFile.close();

    DataFootprintFile.remove();

    DataFootprintFile.open(QIODevice::ReadWrite | QIODevice::Text);
}

//PUBLIC FUNCTION
void DataOneSettings::ResetFilteredFootprint()
{
    // Reset the filtered log footprint file.

    if (FilteredFootprintFile.isOpen())
        FilteredFootprintFile.close();

    FilteredFootprintFile.remove();

    FilteredFootprintFile.open(QIODevice::ReadWrite | QIODevice::Text);
}



//PUBLIC FUNCTION
QDateTime DataOneSettings::GetCurrentDateTime()
{
    if (isTimeZoneAdjustmentEnabled)
        return QDateTime::currentDateTime().addSecs(DataOneTimeSettings.TimeZoneToSecs); //TimeZone adjustment
    else
        return QDateTime::currentDateTime();
}

//PUBLIC FUNCTION
QString DataOneSettings::GetCurrentDateTimeString()
{
    QDateTime CurrentDateTime;

    if (isTimeZoneAdjustmentEnabled)
        CurrentDateTime = QDateTime::currentDateTime().addSecs(DataOneTimeSettings.TimeZoneToSecs); //TimeZone adjustment
    else
        CurrentDateTime = QDateTime::currentDateTime();

    return CurrentDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz");
}

//PUBLIC FUNCTION
QString DataOneSettings::GetCurrentDateTimeFileNameString()
{
    QDateTime CurrentDateTime;

    if (isTimeZoneAdjustmentEnabled)
        CurrentDateTime = QDateTime::currentDateTime().addSecs(DataOneTimeSettings.TimeZoneToSecs); //TimeZone adjustment
    else
        CurrentDateTime = QDateTime::currentDateTime();

    return CurrentDateTime.toString("yyyy'-'MM'-'dd'_'hh'-'mm'-'ss");
}


//PUBLIC FUNCTION
QDateTime DataOneSettings::AdjustTimeZoneAndDST(QDateTime Input)
{
    if (isTimeZoneAdjustmentEnabled)
        return Input.addSecs(DataOneTimeSettings.TimeZoneToSecs); //TimeZone adjustment
    else
        return Input;
}


// PUBLIC FUNCTION
int DataOneSettings::UpdateDateTimeFromNTP()
{
    if (isNewReader) return 0; // Do not run ntpdate on new readers.

    system("killall -q ntpd");
    return QProcess::execute(QString("ntpdate -4 -t1 time.datasport.com")); //Prevoisly -t0.4
}


// PUBLIC FUNCTION
void DataOneSettings::SynchronizeHardwareClock()
{
    QProcess::execute(QString("/sbin/hwclock -w --localtime &"));
}



//PUBLIC FUNCTION
void DataOneSettings::LoadApplicationSettings()
{
    // Load values in [Application] group from ini file.
    // Do not forget to convert the read value to correct data type.

    AppSettings->beginGroup("Application");
        DataOneApplicationSettings.EnableWriteDataLog = AppSettings->value("EnableWriteDataLog").toBool();
        DataOneApplicationSettings.EnableWriteFilteredLog = AppSettings->value("EnableWriteFilteredLog").toBool();
        DataOneApplicationSettings.EnableWriteConsoleLog = AppSettings->value("EnableWriteConsoleLog").toBool();
        DataOneApplicationSettings.EnableDataPort = AppSettings->value("EnableDataPort").toBool();
        DataOneApplicationSettings.EnableFilteredPort = AppSettings->value("EnableFilteredPort").toBool();
        DataOneApplicationSettings.EnableConsolePort = AppSettings->value("EnableConsolePort").toBool();
        DataOneApplicationSettings.EnableTimingServer1 = AppSettings->value("EnableTimingServer1").toBool();
        DataOneApplicationSettings.EnableTimingServer2 = AppSettings->value("EnableTimingServer2").toBool();
    AppSettings->endGroup();
}

//PUBLIC SLOT
void DataOneSettings::SaveApplicationSettings()
{
    // Save values in [Application] group to ini file.

    AppSettings->beginGroup("Application");
        AppSettings->setValue("EnableWriteDataLog", DataOneApplicationSettings.EnableWriteDataLog);
        AppSettings->setValue("EnableWriteFilteredLog", DataOneApplicationSettings.EnableWriteFilteredLog);
        AppSettings->setValue("EnableWriteConsoleLog", DataOneApplicationSettings.EnableWriteConsoleLog);
        AppSettings->setValue("EnableDataPort", DataOneApplicationSettings.EnableDataPort);
        AppSettings->setValue("EnableFilteredPort", DataOneApplicationSettings.EnableFilteredPort);
        AppSettings->setValue("EnableConsolePort", DataOneApplicationSettings.EnableConsolePort);
        AppSettings->setValue("EnableTimingServer1", DataOneApplicationSettings.EnableTimingServer1);
        AppSettings->setValue("EnableTimingServer2", DataOneApplicationSettings.EnableTimingServer2);
    AppSettings->endGroup();
    AppSettings->sync();
}



//PUBLIC FUNCTION
void DataOneSettings::LoadNetworkSettings()
{
    // Load values in [Network] group from ini file.
    // Do not forget to convert the read value to correct data type.

    AppSettings->beginGroup("Network");
        DataOneNetworkSettings.DataPort = AppSettings->value("DataPort").toInt();
        DataOneNetworkSettings.FilteredPort = AppSettings->value("FilteredPort").toInt();
        DataOneNetworkSettings.ConsolePort = AppSettings->value("ConsolePort").toInt();
        DataOneNetworkSettings.PingInterval = AppSettings->value("PingInterval").toInt();
        DataOneNetworkSettings.MaxConnectedClients = AppSettings->value("MaxConnectedClients").toInt();
        DataOneNetworkSettings.TimingServer1Address = AppSettings->value("TimingServer1Address").toString();
        DataOneNetworkSettings.TimingServer2Address = AppSettings->value("TimingServer2Address").toString();
        DataOneNetworkSettings.TimingServerBasePort = AppSettings->value("TimingServerBasePort").toUInt();
        DataOneNetworkSettings.LogUploadServerAddress = AppSettings->value("LogUploadServerAddress").toString();
        DataOneNetworkSettings.LogUploadServerUseSSL = AppSettings->value("LogUploadServerUseSSL").toBool();
        DataOneNetworkSettings.PingIPAddress = AppSettings->value("PingIPAddress", "8.8.8.8").toString();
        DataOneNetworkSettings.InternetCheckURL = AppSettings->value("InternetCheckWebAddress", "http://services.datasport.com").toString();
    AppSettings->endGroup();

    if (DataOneNetworkSettings.LogUploadServerUseSSL)
        WebUploadServerURL.append(QString("https://%1").arg(DataOneNetworkSettings.LogUploadServerAddress));  // Set HTTPS URL.
    else
        WebUploadServerURL.append(QString("http://%1").arg(DataOneNetworkSettings.LogUploadServerAddress));   // Set HTTP URL.
}



//PUBLIC FUNCTION
void DataOneSettings::LoadDeviceSettings()
{
    // Load values in [Reader] group from ini file.
    // Do not forget to convert the read value to correct data type.

    AppSettings->beginGroup("Reader");
        DataOneDeviceSettings.Reader_Mode = AppSettings->value("ReaderMode").toString();
        DataOneDeviceSettings.Search_Mode = AppSettings->value("SearchMode").toString();
        DataOneDeviceSettings.Session = AppSettings->value("Session").toUInt();
        DataOneDeviceSettings.Frequency = AppSettings->value("Frequency").toString();
        DataOneDeviceSettings.Tag_Volume = AppSettings->value("TagVolume").toString();
        DataOneDeviceSettings.Antennas = AppSettings->value("Antennas").toString();
        DataOneDeviceSettings.Beep = AppSettings->value("Beep").toString();
        DataOneDeviceSettings.Beep_Duration = AppSettings->value("BeepDuration").toUInt();
        DataOneDeviceSettings.TimePointDesc = AppSettings->value("TimePointDesc").toString();
        DataOneDeviceSettings.FilterLength = AppSettings->value("FilterLength").toInt();
        DataOneDeviceSettings.FilterDrift = AppSettings->value("FilterDrift").toInt();
        DataOneDeviceSettings.Password = AppSettings->value("Password").toString(); // Never display this on console.
        DataOneDeviceSettings.GPI2StopDelay = AppSettings->value("GPI2_StopDelay").toUInt();

    AppSettings->endGroup();

    // Populate antenna definitions array.
    ParseAntennaSettings();

}

//PUBLIC SLOT
void DataOneSettings::SaveDeviceSettings()
{
    // Save values in [Reader] group to ini file.

    AppSettings->beginGroup("Reader");
        AppSettings->setValue("ReaderMode", DataOneDeviceSettings.Reader_Mode);
        AppSettings->setValue("SearchMode", DataOneDeviceSettings.Search_Mode);
        AppSettings->setValue("Session", DataOneDeviceSettings.Session);
        AppSettings->setValue("Frequency", DataOneDeviceSettings.Frequency);
        AppSettings->setValue("TagVolume", DataOneDeviceSettings.Tag_Volume);

        if (!isAntennasTemp) AppSettings->setValue("Antennas", DataOneDeviceSettings.Antennas);

        AppSettings->setValue("Beep", DataOneDeviceSettings.Beep);
        AppSettings->setValue("BeepDuration", DataOneDeviceSettings.Beep_Duration);
        AppSettings->setValue("TimePointDesc", DataOneDeviceSettings.TimePointDesc);

        if (!isFilterLengthTemp) AppSettings->setValue("FilterLength", DataOneDeviceSettings.FilterLength);

        AppSettings->setValue("FilterDrift", DataOneDeviceSettings.FilterDrift);
    AppSettings->endGroup();
    AppSettings->sync();
}



//PRIVATE FUNCTION
void DataOneSettings::ParseAntennaSettings()
{
    // Clear previous definitions;
    for (int i = 0; i < Constants::MaxAntennaPortNumber; i++)
    {
        ReaderAntennaDefinitions[i].isDefined = false;
        ReaderAntennaDefinitions[i].TxPower = 0;
    }

    // Extracting antenna definitions.
    if (!DataOneDeviceSettings.Antennas.isEmpty())
    {
        QStringList AntennaDefinitionParts = DataOneDeviceSettings.Antennas.split(" ");
        if (AntennaDefinitionParts.size() > 0)
        {
            for (int i = 0; i < AntennaDefinitionParts.size(); i++)
            {
                QStringList AntennaPort = AntennaDefinitionParts.at(i).split(",");
                if (AntennaPort.size() == 2 && AntennaPort.at(0).toInt() >= Constants::MinAntennaPortNumber && AntennaPort.at(0).toInt() <= Constants::MaxAntennaPortNumber)
                {
                    ReaderAntennaDefinitions[AntennaPort.at(0).toInt() - 1].isDefined = true;
                    ReaderAntennaDefinitions[AntennaPort.at(0).toInt() - 1].TxPower = AntennaPort.at(1).toDouble();
                }
            }
        }
    }
}



//PUBLIC FUNCTION
void DataOneSettings::SetReadingStatus(bool Status)
{
    ReaderSettings->beginGroup("Status");
        ReaderSettings->setValue("Reading", Status);
    ReaderSettings->endGroup();

    ReaderSettings->sync();

    DataOneDeviceSettings.isReading = Status;
}

//PUBLIC FUNCTION
bool DataOneSettings::GetReadingStatus()
{
    // For holding the reader status in a file.
    // The purpose is to tell this application at startup that previously, the application was exited
    // while it was reading (or not) tag records. Specially, if the application crashes for some reason.
    // This ensures auto-reading-start without user intervention on autonomus readers.

    ReaderSettings->beginGroup("Status");
    bool Status = ReaderSettings->value("Reading", false).toBool();
    ReaderSettings->endGroup();

    DataOneDeviceSettings.isReading = Status;

    return Status;
}


//PUBLIC FUNCTION
QString DataOneSettings::GetReadingStatusString()
{
    // Determine reader status.
    QString ReaderStatus;
    if(DataOneDeviceSettings.isReading) ReaderStatus = "on";
    else ReaderStatus = "off";

    return ReaderStatus;
}


//PUBLIC FUNCTION
void DataOneSettings::LoadTimeZoneAndDSTSettings()
{
    TimeSettings->beginGroup("TimeZone");
        DataOneTimeSettings.TimeZoneString = TimeSettings->value("TimeZone").toString();
    TimeSettings->endGroup();

    TimeSettings->beginGroup("DST");
        DataOneTimeSettings.DSTEnabled = TimeSettings->value("DSTEnabled").toBool();

        if (DataOneTimeSettings.DSTEnabled)
        {
            QString DSTYear = QString("%1").arg(QDateTime::currentDateTime().date().year()); // Determine current year.
            QString DSTSetting = TimeSettings->value(DSTYear).toString(); // Read DST dates according to current year.

            QStringList DSTSettingParts = DSTSetting.split('-');
            QStringList DSTStartParts = DSTSettingParts.at(0).split('.');
            QStringList DSTEndParts = DSTSettingParts.at(1).split('.');

            DataOneTimeSettings.DST_Start.setDate(QDate(DSTYear.toInt(), DSTStartParts.at(1).toInt(), DSTStartParts.at(0).toInt()));
            DataOneTimeSettings.DST_Start.setTime(QTime(1, 0, 0));

            DataOneTimeSettings.DST_End.setDate(QDate(DSTYear.toInt(), DSTEndParts.at(1).toInt(), DSTEndParts.at(0).toInt()));
            DataOneTimeSettings.DST_End.setTime(QTime(1, 0, 0));

            if ((QDateTime::currentDateTime() > DataOneTimeSettings.DST_Start) && (QDateTime::currentDateTime() < DataOneTimeSettings.DST_End))
                DataOneTimeSettings.DSTValid = true; // We are in DST time period.
            else
                DataOneTimeSettings.DSTValid = false; // We are outside DST time period.


        }
        else
            DataOneTimeSettings.DSTValid = false;
    TimeSettings->endGroup();

    // TimeZone will be defined in the ini file as "+XXXX" or "-XXXX", e.g, "+0100", "-0500" etc.
    // The Impinj Reader does not cater for time zone correction for NTP time update.
    // Therefore, with this setting, we will adjust time zone correction when updating system time.
    if (DataOneTimeSettings.TimeZoneString.length() == 5)
    {
        DataOneTimeSettings.TimeZoneToSecs = (DataOneTimeSettings.TimeZoneString.mid(1,2).toInt() * 3600) + (DataOneTimeSettings.TimeZoneString.mid(3,2).toInt() * 60);

        if (DataOneTimeSettings.DSTValid)
        {
            DataOneTimeSettings.TimeZoneToSecs += 3600; // Add 1 hr if DST is valid.

            int TzHour = DataOneTimeSettings.TimeZoneString.mid(2, 1).toInt() + 1;
            DataOneTimeSettings.TimeZoneString.replace(2, 1, QString("%1").arg(TzHour));
        }

        if (DataOneTimeSettings.TimeZoneString.at(0) == '-')
            DataOneTimeSettings.TimeZoneToSecs *= -1;
    }
    else
    {
        DataOneTimeSettings.TimeZoneToSecs = 0;
    }
}


//PUBLIC FUNCTION
QDateTime DataOneSettings::ConvertDateTimeToUTC(QDateTime Input)
{
    return Input.addSecs(-1 * DataOneTimeSettings.TimeZoneToSecs); //Subtract TZ and DST bias.
}


//PUBLIC FUNCTION
void DataOneSettings::ShutDown()
{
    AppSettings->sync();
}
