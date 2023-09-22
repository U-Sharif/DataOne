#include "reader.h"

#include <QStringList>
#include <QProcess>

Reader::Reader(QObject *parent) : QObject(parent)
{
    //qRegisterMetaType<TagRecord>("TagRecord");

    // Defaults.
    isConnected = false;
    isReading = false;
    isSettingChanged = false;
    isAntennaChanged = false;
    isPerformingActionAlert = false;
    WriteLockStartModeDatabase = false;
    TotalTagCounter = 0;

    // This timer inserts a delay at startup before auto-start reading.
    PreviousReadingStatusTimer = new QTimer(this);
    PreviousReadingStatusTimer->setSingleShot(true);
    connect(PreviousReadingStatusTimer, SIGNAL(timeout()), this, SLOT(StartReading()));

    // Regular update of parameters.
    ReaderStatusUpdateTimer = new QTimer(this);
    connect(ReaderStatusUpdateTimer, SIGNAL(timeout()), this, SLOT(getReaderStatus()));

    // To process stored tags in start mode.
    StartModeTimer = new QTimer(this);
    StartModeTimer->setInterval(1000);
    connect(StartModeTimer, SIGNAL(timeout()), this, SLOT(ProcessStartModeTags()));

}

//PUBLIC FUNCTION
bool Reader::Run(const char * readerName)
{
    // This is where reader is setup.

    // Set Reader name.
    ReaderName = (char*) readerName;

    // Setup tag record object for handling tag reports.
    CurrentTag = new TagRecord(SystemSettings, this);

    // Setup Reader update timer.
    ReaderStatusUpdateTimer->start(SystemSettings->DataOneNetworkSettings.PingInterval * 1000);


    // Always use try/catch with LLRP.
    try
    {

        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Off;

        // Connect to the reader. The name is the host name or IP address.
        //SpeedwayReader::Connect(ReaderName); isConnected = true;
        DisconnectLLRP();
        ConnectLLRP();

        // Clear the reader of any RFID operation and configuration.
        SpeedwayReader::ClearSettings();

        emit Log("ACTION", QString("Querying Reader featureset....\n\r"));
        emit Log("", "\n\r");

        // Query the features of the reader. This includes model
        // name, version information, subregion, transmit powers,
        // frequencies, sensitivities, modes, etc.
        ReaderFeatureSet = SpeedwayReader::QueryFeatureSet();

        // Show the feature set on console.
        QString FeatureSetLog;
        FeatureSetLog.append(QString("\n\r"));
        FeatureSetLog.append(QString("- Serial Number     : %1\n\r").arg(ReaderFeatureSet.SerialNumber));
        FeatureSetLog.append(QString("- Model             : %1\n\r").arg(ReaderFeatureSet.ModelName));
        FeatureSetLog.append(QString("- Software Version  : %1\n\r").arg(ReaderFeatureSet.SoftwareVersion));
        FeatureSetLog.append(QString("- Firmware Version  : %1\n\r").arg(ReaderFeatureSet.FirmwareVersion));
        FeatureSetLog.append(QString("- PCBA Version      : %1\n\r").arg(ReaderFeatureSet.PcbaVersion));
        FeatureSetLog.append(QString("- FPGA Version      : %1\n\r").arg(ReaderFeatureSet.FpgaVersion));
        FeatureSetLog.append(QString("- Regulatory Region : %1\n\r").arg(ReaderFeatureSet.Subregion));
        FeatureSetLog.append(QString("- Programmed Frequencies : %1\n\r").arg(ReaderFeatureSet.TxFrequencies.nEntries));
        FeatureSetLog.append(QString("  - Frequency A = %1 MHz\n\r").arg(ReaderFeatureSet.TxFrequencies.Entries[0].Mhz));
        FeatureSetLog.append(QString("  - Frequency B = %1 MHz\n\r").arg(ReaderFeatureSet.TxFrequencies.Entries[1].Mhz));
        FeatureSetLog.append(QString("  - Frequency C = %1 MHz\n\r").arg(ReaderFeatureSet.TxFrequencies.Entries[2].Mhz));
        FeatureSetLog.append(QString("  - Frequency D = %1 MHz\n\r").arg(ReaderFeatureSet.TxFrequencies.Entries[3].Mhz));
        emit Log("SYSTEM RESPONSE", FeatureSetLog);
        emit Log("", "\n\r");

        // If reader has frequency > 900 MHz, this means this is one of  the new readers procured in 2019.
        // OS and hardware features are slightly different, this check is used at many places to filter some commands.
        if (ReaderFeatureSet.TxFrequencies.Entries[0].Mhz > 900)
            SystemSettings->isNewReader = true;

        emit Log("ACTION", QString("Querying Reader status...\n\r"));
        emit Log("", "\n\r");

        // Query the status of the reader. This includes the
        // connection state of each antenna, the state of each
        // general purpose input (GPI), the state of the RFID
        // operation, etc.

        ReaderStatus = SpeedwayReader::QueryStatus(StatusRefresh_Everything);

        QString QueryStatusLog;
        QueryStatusLog.append("\n\r");
        QueryStatusLog.append(QString("Antennas:\n\r"));

        for (
             int portNumber = Constants::MinAntennaPortNumber;
             portNumber <= Constants::MaxAntennaPortNumber;
             portNumber++)
        {
            AntennaStatus *     antStat = &ReaderStatus.Antennas[portNumber];
            const char *        stateStr = "";

            switch (antStat->State)
            {
            // The port present is on the reader and connected to an antenna.
            case AntennaConnectionState_Connected:
                stateStr = "Connected";
                break;

                // The port is present on the reader but is not connected to an antenna, or the connection is bad.
            case AntennaConnectionState_NotConnected:
                stateStr = "Disconnected";
                break;

                // No such port on the reader.
            case AntennaConnectionState_NotApplicable:
                stateStr = "N/A";
                break;

                // Unknown state. This usually means something went wrong while communicating with the reader.
            case AntennaConnectionState_Unknown:
                stateStr = "Unknown";
                break;

                // Should never happen.
            default:
                stateStr = "??";
                break;
            }

            // Show the antenna state on console.
            QueryStatusLog.append(QString("- %1 : %2\n\r").arg(antStat->PortNumber).arg(QString(stateStr)));
        }
        emit Log("SYSTEM RESPONSE", QueryStatusLog);
        emit Log("", "\n\r");


        emit Log("ACTION", QString("Querying factory default settings...\n\r"));
        emit Log("", "\n\r");

        // Query the default settings for the reader. Settings
        // include which antennas are enabled, when to report and
        // optional report fields. Typically you will prepare the
        // reader by getting the default settings and adjusting them.

        ReaderSettings = SpeedwayReader::QueryFactorySettings();

        // Show the factory default frequency settings on console.
        QString FactorySettingsLog;
        FactorySettingsLog.append(QString("Frequencies in factory settings : %1\n\r").arg(ReaderSettings.nTxFrequenciesInMhz));
        FactorySettingsLog.append(QString("- Default Frequency = %1 MHz\n\r").arg(ReaderSettings.TxFrequenciesInMhz[0]));
        emit Log("SYSTEM RESPONSE", FactorySettingsLog);
        emit Log("", "\n\r");

        // Set reader configuration from settings.
        setBeep(SystemSettings->DataOneDeviceSettings.Beep);
        setFrequency(SystemSettings->DataOneDeviceSettings.Frequency);
        setReaderMode(SystemSettings->DataOneDeviceSettings.Reader_Mode);
        setSearchMode(SystemSettings->DataOneDeviceSettings.Search_Mode);
        setSession(SystemSettings->DataOneDeviceSettings.Session);
        setTagVolume(SystemSettings->DataOneDeviceSettings.Tag_Volume);
        setAntennas();

        // Show the settings on console.
        QString AppliedSettingsLog;
        AppliedSettingsLog.append("\n\r");
        AppliedSettingsLog.append(QString("- Setting Beep duration to : %1 ms. \n\r").arg(SystemSettings->DataOneDeviceSettings.Beep_Duration));
        AppliedSettingsLog.append(QString("- Setting Filter Length to : %1 sec.\n\r").arg(SystemSettings->DataOneDeviceSettings.FilterLength));
        AppliedSettingsLog.append(QString("- Setting Filter Drift to : %1 ms.\n\r").arg(SystemSettings->DataOneDeviceSettings.FilterDrift));
        AppliedSettingsLog.append(QString("- Setting Reader number to : %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Reader_Number));
        AppliedSettingsLog.append(QString("- Setting Time Point Desc to : %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.TimePointDesc));
        emit Log("ACTION", AppliedSettingsLog);
        emit Log("", "\n\r");

        // Set some more reader settings.
        ReaderSettings.Report.Mode = ReportMode_Individual;
        ReaderSettings.Report.IncludePeakRssi = true;
        ReaderSettings.Report.IncludeLastSeenTime = true;
        ReaderSettings.Report.IncludeAntennaPortNumber = true;
        ReaderSettings.Report.IncludeChannel = false;

        // Setup GPIs.
        ReaderSettings.Gpis[1].IsEnabled = true;
        ReaderSettings.Gpis[1].DebounceInMs = 20;
        ReaderSettings.Gpis[2].IsEnabled = true;
        ReaderSettings.Gpis[2].DebounceInMs = 20;
        ReaderSettings.Gpis[3].IsEnabled = true;
        ReaderSettings.Gpis[3].DebounceInMs = 20;
        ReaderSettings.Gpis[4].IsEnabled = true;
        ReaderSettings.Gpis[4].DebounceInMs = 20;


        // Order the reader to change its settings to these.
        emit Log("ACTION", QString("Applying saved settings.\n\r"));
        emit Log("", "\n\r");
        SpeedwayReader::ApplySettings(ReaderSettings);
        isSettingChanged = false;


        // Set timer to start reading automatically, if application previously crashed while reading.
        if (SystemSettings->GetReadingStatus())
            PreviousReadingStatusTimer->start(8000);


        return true;
    }
    catch (OctaneSdkException ex)
    {
        // OctaneSdkExceptions are detected by the Octane SDK
        // library. These exceptions usually indicate either
        // something wrong with the reader or something wrong
        // with the application's request.
        emit Log("SYSTEM RESPONSE", QString("OctaneSdk detected: %1\n\r").arg(ex.what()));
        emit Log("", "\n\r");

        return false;
    }
    catch (exception ex)
    {
        // Any other kind of exception deteced by the system.
        emit Log("SYSTEM RESPONSE", QString("Exception: %1\n\r").arg(ex.what()));
        emit Log("", "\n\r");

        return false;
    }

}



//PRIVATE FUNCTION
void Reader::setFrequency(QString FrequencyID)
{
    if (FrequencyID == "A")
    {
        if (ReaderFeatureSet.TxFrequencies.Entries[0].Mhz == 0)
        {
            emit Log("WARNING", QString("No frequency programmed at setting %1. \n\r").arg(FrequencyID));
            emit Log("ACTION", QString("Setting Reader frequency to : Auto \n\r"));

            // Store frequency setting into reader settings.
            ReaderSettings.TxFrequenciesInMhz[0] = 0;
            ReaderSettings.nTxFrequenciesInMhz = 0;
        }
        else
        {
            // Store frequency setting into reader settings.
            //ReaderSettings.TxFrequenciesInMhz[0] = 865.7; //Old readers
            //ReaderSettings.TxFrequenciesInMhz[0] = 916.3; //New readers (2019)
            ReaderSettings.TxFrequenciesInMhz[0] = ReaderFeatureSet.TxFrequencies.Entries[0].Mhz;
            ReaderSettings.nTxFrequenciesInMhz = 1;

            emit Log("ACTION", QString("Setting Reader frequency to : %1 = %2 \n\r").arg(FrequencyID).arg(ReaderSettings.TxFrequenciesInMhz[0]));

            // Store the frequency in the application configuration.
            SystemSettings->DataOneDeviceSettings.Frequency = "A";
            emit SaveDeviceSettings();
        }
    }
    else if (FrequencyID == "B")
    {
        if (ReaderFeatureSet.TxFrequencies.Entries[1].Mhz == 0)
        {
            emit Log("WARNING", QString("No frequency programmed at setting %1. \n\r").arg(FrequencyID));
            emit Log("ACTION", QString("Setting Reader frequency to : Auto \n\r"));

            // Store frequency setting into reader settings.
            ReaderSettings.TxFrequenciesInMhz[0] = 0;
            ReaderSettings.nTxFrequenciesInMhz = 0;
        }
        else
        {
            // Store frequency setting into reader settings.
            //ReaderSettings.TxFrequenciesInMhz[0] = 866.3; //Old readers
            //ReaderSettings.TxFrequenciesInMhz[0] = 917.5; //New readers (2019)
            ReaderSettings.TxFrequenciesInMhz[0] = ReaderFeatureSet.TxFrequencies.Entries[1].Mhz;
            ReaderSettings.nTxFrequenciesInMhz = 1;

            emit Log("ACTION", QString("Setting Reader frequency to : %1 = %2 \n\r").arg(FrequencyID).arg(ReaderSettings.TxFrequenciesInMhz[0]));

            // Store the frequency in the application configuration.
            SystemSettings->DataOneDeviceSettings.Frequency = "B";
            emit SaveDeviceSettings();
        }
    }
    else if (FrequencyID == "C")
    {
        if (ReaderFeatureSet.TxFrequencies.Entries[2].Mhz == 0)
        {
            emit Log("WARNING", QString("No frequency programmed at setting %1. \n\r").arg(FrequencyID));
            emit Log("ACTION", QString("Setting Reader frequency to : Auto \n\r"));

            // Store frequency setting into reader settings.
            ReaderSettings.TxFrequenciesInMhz[0] = 0;
            ReaderSettings.nTxFrequenciesInMhz = 0;
        }
        else
        {
            // Store frequency setting into reader settings.
            //ReaderSettings.TxFrequenciesInMhz[0] = 866.9; //Old readers
            //ReaderSettings.TxFrequenciesInMhz[0] = 918.7; //New readers (2019)
            ReaderSettings.TxFrequenciesInMhz[0] = ReaderFeatureSet.TxFrequencies.Entries[2].Mhz;
            ReaderSettings.nTxFrequenciesInMhz = 1;

            emit Log("ACTION", QString("Setting Reader frequency to : %1 = %2 \n\r").arg(FrequencyID).arg(ReaderSettings.TxFrequenciesInMhz[0]));

            // Store the frequency in the application configuration.
            SystemSettings->DataOneDeviceSettings.Frequency = "C";
            emit SaveDeviceSettings();
        }
    }
    else if (FrequencyID == "D")
    {
        if (ReaderFeatureSet.TxFrequencies.Entries[3].Mhz == 0)
        {
            emit Log("WARNING", QString("No frequency programmed at setting %1. \n\r").arg(FrequencyID));
            emit Log("ACTION", QString("Setting Reader frequency to : Auto \n\r"));

            // Store frequency setting into reader settings.
            ReaderSettings.TxFrequenciesInMhz[0] = 0;
            ReaderSettings.nTxFrequenciesInMhz = 0;
        }
        else
        {
            // Store frequency setting into reader settings.
            //ReaderSettings.TxFrequenciesInMhz[0] = 867.5; //Old readers
            //ReaderSettings.TxFrequenciesInMhz[0] = 918.7; //New readers (2019)
            ReaderSettings.TxFrequenciesInMhz[0] = ReaderFeatureSet.TxFrequencies.Entries[3].Mhz;
            ReaderSettings.nTxFrequenciesInMhz = 1;

            emit Log("ACTION", QString("Setting Reader frequency to : %1 = %2 \n\r").arg(FrequencyID).arg(ReaderSettings.TxFrequenciesInMhz[0]));

            // Store the frequency in the application configuration.
            SystemSettings->DataOneDeviceSettings.Frequency = "D";
            emit SaveDeviceSettings();
        }
    }
    else if (FrequencyID == "Auto")
    {
        // Clear all programmed frequencies
        emit Log("ACTION", QString("Setting Reader frequency to : Auto \n\r"));

        // Store frequency setting into reader settings.
        ReaderSettings.TxFrequenciesInMhz[0] = 0;
        ReaderSettings.nTxFrequenciesInMhz = 0;

        // Store the frequency in the application configuration.
        SystemSettings->DataOneDeviceSettings.Frequency = "Auto";
        emit SaveDeviceSettings();
    }
    else
    {
        emit Log("ERROR", QString("Illegal command.\n\r"));
    }

    emit Log("", "\n\r");

    // Set flag.
    isSettingChanged = true;
}

//PRIVATE FUNCTION
void Reader::setReaderMode(QString ReaderMode)
{
    if (SystemSettings->isNewReader && ReaderMode == "AutoSet Dense Reader" )
        ReaderMode = "Hybrid Mode";


    if (ReaderMode == "AutoSet Dense Reader")
    {
        emit Log("ACTION", QString("Setting Reader Mode to : AutoSet Dense Reader \n\r"));

        // Store reader mode in reader settings.
        ReaderSettings.ReaderMode = ReaderMode_AutoSetDenseReader;

        // Store the reader mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Reader_Mode = "AutoSet Dense Reader";
        emit SaveDeviceSettings();
    }
    else if (ReaderMode == "Dense Reader (M=8)")
    {
        emit Log("ACTION", QString("Setting Reader Mode to : Dense Reader (M=8) \n\r"));

        // Store reader mode in reader settings.
        ReaderSettings.ReaderMode = ReaderMode_DenseReaderM8;

        // Store the reader mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Reader_Mode = "Dense Reader (M=8)";
        emit SaveDeviceSettings();
    }
    else if (ReaderMode == "Dense Reader (M=4)")
    {
        emit Log("ACTION", QString("Setting Reader Mode to : Dense Reader (M=4) \n\r"));

        // Store reader mode in reader settings.
        ReaderSettings.ReaderMode = ReaderMode_DenseReaderM4;

        // Store the reader mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Reader_Mode = "Dense Reader (M=4)";
        emit SaveDeviceSettings();
    }
    else if (ReaderMode == "Hybrid Mode")
    {
        emit Log("ACTION", QString("Setting Reader Mode to : Hybrid Mode \n\r"));

        // Store reader mode in reader settings.
        ReaderSettings.ReaderMode = ReaderMode_Hybrid;

        // Store the reader mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Reader_Mode = "Hybrid Mode";
        emit SaveDeviceSettings();
    }
    else if (ReaderMode == "Max Troughput")
    {
        emit Log("ACTION", QString("Setting Reader Mode to : Max Troughput \n\r"));

        // Store reader mode in reader settings.
        ReaderSettings.ReaderMode = ReaderMode_MaxThroughput;

        // Store the reader mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Reader_Mode = "Max Troughput";
        emit SaveDeviceSettings();
    }
    else
    {
        emit Log("ERROR", QString("Illegal command.\n\r"));
    }

    emit Log("", "\n\r");

    // Set flag.
    isSettingChanged = true;
}

//PRIVATE FUNCTION
void Reader::setSearchMode(QString SearchMode)
{
    if (SearchMode == "Dual Target")
    {
        emit Log("ACTION", QString("Setting Search Mode to : Dual Target \n\r"));

        // Store search mode in reader settings.
        ReaderSettings.SearchMode = SearchMode_DualTarget;

        // Store the search mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Search_Mode = "Dual Target";
        emit SaveDeviceSettings();
    }
    else if (SearchMode == "Reader Selected")
    {
        emit Log("ACTION", QString("Setting Search Mode to : Reader Selected \n\r"));

        // Store search mode in reader settings.
        ReaderSettings.SearchMode = SearchMode_ReaderSelected;

        // Store the search mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Search_Mode = "Reader Selected";
        SystemSettings->SaveDeviceSettings();
    }
    else if (SearchMode == "Single Target")
    {
        emit Log("ACTION", QString("Setting Search Mode to : Single Target \n\r"));

        // Store search mode in reader settings.
        ReaderSettings.SearchMode = SearchMode_SingleTarget;

        // Store the search mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Search_Mode = "Single Target";
        SystemSettings->SaveDeviceSettings();
    }
    else if (SearchMode == "Single Target with Suppression")
    {
        emit Log("ACTION", QString("Setting Search Mode to : Single Target with Suppression \n\r"));

        // Store search mode in reader settings.
        ReaderSettings.SearchMode = SearchMode_SingleTargetWithSuppression;

        // Store the search mode in application configuration.
        SystemSettings->DataOneDeviceSettings.Search_Mode = "Single Target with Suppression";
        SystemSettings->SaveDeviceSettings();
    }
    else
    {
        emit Log("ERROR", QString("Illegal command.\n\r"));
    }

    emit Log("", "\n\r");

    // Set flag.
    isSettingChanged = true;
}

//PRIVATE FUNCTION
void Reader::setSession(int Session)
{
    emit Log("ACTION", QString("Setting Session to : %1 \n\r").arg(Session));
    emit Log("", "\n\r");

    // Store sessoin value in reader settings.
    ReaderSettings.Session = Session;

    // Store the session value in application configuration.
    SystemSettings->DataOneDeviceSettings.Session = Session;
    emit SaveDeviceSettings();

    // Set flag.
    isSettingChanged = true;
}

//PRIVATE FUNCTION
void Reader::setTagVolume(QString TagVolume)
{
    // Split the input. We only need the second part of the string.
    QStringList TagVolumeParts = TagVolume.split("-");

    if (TagVolumeParts.size() == 2)
    {
        emit Log("ACTION", QString("Setting Tag Volume to : %1 \n\r").arg(TagVolume));

        // Store tag volume value in reader settings.
        // Only the end range value is required.
        ReaderSettings.TagPopulationEstimate = TagVolumeParts.at(1).toInt();

        // Store the tag volume value in application configuration.
        SystemSettings->DataOneDeviceSettings.Tag_Volume = TagVolume;
        emit SaveDeviceSettings();
    }
    else
    {
        emit Log("ERROR", QString("Illegal command.\n\r"));
    }

    emit Log("", "\n\r");

    // Set flag.
    isSettingChanged = true;
}

//PRIVATE FUNCTION
void Reader::setAntennas()
{
    QString AntennaLog;
    AntennaLog.append("Setting Antennas:\n\r");

    for (int i = 0; i < ReaderFeatureSet.AntennaCount; i++)
    {
        if (SystemSettings->ReaderAntennaDefinitions[i].isDefined && ReaderStatus.Antennas[i + 1].IsConnected())
        {
            // Store antenna enabled state in reader settings.
            if (!ReaderStatus.Antennas[i + 1].IsEnabled)
                ReaderSettings.Antennas.Elements[i].IsEnabled = true;

            // Store antenna power in reader settings.
            ReaderSettings.Antennas.Elements[i].TxPowerInDbm = SystemSettings->ReaderAntennaDefinitions[i].TxPower;

            AntennaLog.append(QString("-> Setting Antenna %1 Power to : %2 \n\r").arg(i + 1).arg(SystemSettings->ReaderAntennaDefinitions[i].TxPower));
        }
        else
        {
            // If antenna is not defined in settings or is not connected, disable it.
            ReaderSettings.Antennas.Elements[i].IsEnabled = false;

            AntennaLog.append(QString("-> Antenna %1 not defined, or not connected : disabling... \n\r").arg(i + 1));
        }

    }

    // Set flag.
    isSettingChanged = true;

    emit Log("ACTION", AntennaLog);
    emit Log("", "\n\r"); // Insert some space on console.

}

//PRIVATE FUNCTION
void Reader::setBeep(QString BeepStatus)
{
    if (BeepStatus == "unfiltered")
    {
        emit Log("ACTION", QString("Setting Beep status to : unfiltered \n\r"));

        // Store beep type in application configuration.
        SystemSettings->DataOneDeviceSettings.Beep = "unfiltered";

        // Save immediately.
        emit SaveDeviceSettings();
    }
    else if (BeepStatus == "filtered")
    {
        emit Log("ACTION", QString("Setting Beep status to : filtered \n\r"));

        // Store beep type in application configuration.
        SystemSettings->DataOneDeviceSettings.Beep = "filtered";

        // Save immediately.
        emit SaveDeviceSettings();
    }
    else
    {
        emit Log("ERROR", QString("Illegal command.\n\r"));
    }

    emit Log("", "\n\r");
}

//PRIVATE FUNCTION
void Reader::setBeepDuration(QString BeepDuration)
{
    int BeepDurationInt = BeepDuration.toInt();

    // Keep the beep duruation to a reasonable length.
    if (BeepDurationInt >= 100 and BeepDurationInt <= 1000)
    {
        emit Log("ACTION", QString("Setting Beep duration to : %1 ms.\n\r").arg(BeepDurationInt));

        // Save the beep duration value in application configuration.
        SystemSettings->DataOneDeviceSettings.Beep_Duration = BeepDurationInt;

        // Save immediately.
        emit SaveDeviceSettings();
    }
    else
    {
        emit Log("ERROR", QString("Illegal command.\n\r Beep duration value should be between 100 and 1000 milliseconds.\n\r"));
    }

    emit Log("", "\n\r");
}

//PRIVATE FUNCTION
void Reader::setTime(QString DateTimeString)
{
    // Split the string.
    QStringList DateTimeParts = DateTimeString.split(' ');

    // Separate year, month, day.
    QString Day = DateTimeParts.at(0).mid(0,2);
    QString Month = DateTimeParts.at(0).mid(3,2);
    QString Year = DateTimeParts.at(0).mid(6,4);

    // Separate hour, minute, second.
    QString Hour = DateTimeParts.at(1).mid(0,2);
    QString Minute = DateTimeParts.at(1).mid(3,2);
    QString Second = DateTimeParts.at(1).mid(6,2);

    // Convert time to UTC.
    QDateTime LocalTime;
    LocalTime.setDate(QDate(Year.toInt(), Month.toInt(), Day.toInt()));
    LocalTime.setTime(QTime(Hour.toInt(), Minute.toInt(), Second.toInt(), 0));

    QDateTime UTCTime = SystemSettings->ConvertDateTimeToUTC(LocalTime);
    Day = QString("%1").arg(UTCTime.date().day());
    Month = QString("%1").arg(UTCTime.date().month());
    Year = QString("%1").arg(UTCTime.date().year());

    Hour = QString("%1").arg(UTCTime.time().hour());
    Minute = QString("%1").arg(UTCTime.time().minute());
    Second = QString("%1").arg(UTCTime.time().second());

    // We are setting manual time, therefore, kill the NTP daemon.
    system("killall -q ntpd");
    //emit Log("ACTION", "NTP daemon killed.\n\r");

    // Setup date command for OS.
    QString TimeCommand;
    TimeCommand.append("date -s \""+Year+"-"+Month+"-"+Day+" "+Hour+":"+Minute+":"+Second+"\""); //Format: YYYY-MM-DD hh:mm[:ss]

    emit Log("ACTION", QString("Setting system time manually to : %1\n\r").arg(DateTimeString));

    // Set time in OS.
    //system(TimeCommand.toStdString().data()); // Old method
    QProcess::execute(TimeCommand);

    // Disable time zone adjustment in whole application.
    //SystemSettings->isTimeZoneAdjustmentEnabled = false; //Disabled in 1.4.5.

    // Enable indication that date and time has been manually set.
    SystemSettings->isDateTimeManuallySet = true;

    // Synchronize OS hardware clock with new OS clock time.
    emit Log("ACTION", QString("Synchronizing hardware clock.\n\r"));
    SystemSettings->SynchronizeHardwareClock();

    emit Log("", QString("\n\r"));

    // Combine into one date time object.
    QDate NewDate(Year.toInt(), Month.toInt(), Day.toInt());
    QTime NewTime(Hour.toInt(), Minute.toInt(), Second.toInt());
    QDateTime NewDateTime(NewDate, NewTime);

    // If new date time is earlier than current tag, then send command to open new record files.
    if (NewDateTime < CurrentTag->LastSeenDateTime)
        ParseClientCommand("clear_buffer");

    emit Log("", "\n\r");
}


QDateTime Reader::AdjustTimeZone(Time ReaderTime)
{
    QDateTime EventDateTime;

    char timeStrBuf[32];
    ReaderTime.Formatter(timeStrBuf, sizeof timeStrBuf);
    QString OctaneSDK_Format_DateTime(timeStrBuf);
    OctaneSDK_Format_DateTime.chop(4); //Remove extra text at the end of date string.
    EventDateTime =  QDateTime::fromString(OctaneSDK_Format_DateTime, "yyyy-MM-ddThh:mm:ss.zzz");

    // Separate year, month, day.
    //int Year = OctaneSDK_Format_DateTime.mid(0,4).toInt();
    //int Month = OctaneSDK_Format_DateTime.mid(5,2).toInt();
    //int Day = OctaneSDK_Format_DateTime.mid(8,2).toInt();
    //QDate newDate(Year, Month, Day);

    // Separate hour, minute, second, millisecond.
    //int Hour = OctaneSDK_Format_DateTime.mid(11,2).toInt();
    //int Minute = OctaneSDK_Format_DateTime.mid(14,2).toInt();
    //int Second = OctaneSDK_Format_DateTime.mid(17,2).toInt();
    //int MilliSecond = OctaneSDK_Format_DateTime.mid(20,3).toInt();
    //QTime newTime(Hour, Minute, Second, MilliSecond);

    // Combine into one date time object.
    //QDateTime EventDateTime;
    //EventDateTime.setDate(newDate);
    //EventDateTime.setTime(newTime);

    // If clock adjustment is enabled, add the tz difference to this time.
    if (SystemSettings->isTimeZoneAdjustmentEnabled)
        EventDateTime = EventDateTime.addSecs(SystemSettings->DataOneTimeSettings.TimeZoneToSecs); //TimeZone adjustment

    // Return new date and time.
    return EventDateTime;
}


//PROTECTED OVERRIDE FUNCTIONS
// The event handler methods below are invoked while running
// on a callback thread. There is one callback thread per a
// SpeedwayReader instance. Be sure to use thread safe techniques.

void Reader::OnConnected(ConnectionChangedEventArgs & args)
{
    // Tell other threads that LLRP is connected.
    emit LLRPConnected(true);

    QDateTime EventDateTime = AdjustTimeZone(args.Timestamp); //TimeZone adjustment

    emit Log("SYSTEM RESPONSE", QString("LLRP connected as of %1\n\r").arg(EventDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
    emit Log("", "\n\r");

    SpeedwayReader::OnConnected(args);
}

void Reader::OnDisconnected(ConnectionChangedEventArgs & args)
{
    // Tell other threads that LLRP is disconnected.
    emit LLRPConnected(false);

    QDateTime EventDateTime = AdjustTimeZone(args.Timestamp); //TimeZone adjustment

    emit Log("SYSTEM RESPONSE", QString("LLRP disconnected as of %1\n\r").arg(EventDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
    emit Log("", "\n\r");

    SpeedwayReader::OnDisconnected(args);
}

void Reader::OnStarted(StartedEventArgs & args)
{
    // Tell other thread sthat reader has started tag reading.
    emit ReadingStarted(true);

    QDateTime EventDateTime = AdjustTimeZone(args.Timestamp); //TimeZone adjustment

    emit Log("SYSTEM RESPONSE", QString("Reader started as of %1\n\r").arg(EventDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
    emit Log("", "\n\r");

    SpeedwayReader::OnStarted(args);
}

void Reader::OnStopped(StoppedEventArgs & args)
{
    // Tell other threads that reader has stopped reading.
    emit ReadingStarted(false);

    QDateTime EventDateTime = AdjustTimeZone(args.Timestamp); //TimeZone adjustment

    emit Log("SYSTEM RESPONSE", QString("Reader stopped as of %1\n\r").arg(EventDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
    emit Log("", "\n\r");

    SpeedwayReader::OnStopped(args);
}



void Reader::OnTagsReported(TagsReportedEventArgs & args)
{
    // This is where the new tags arrive from radio and LLRP.

    //if (TotalTagCounter == 500) return; //Debugging.
    //TotalTagCounter+= args.TagReport.nTags;

    // Debug.
    //emit Log("DEBUG", QString("Tags reported: %1  Total: %2\n\r").arg(args.TagReport.nTags).arg(TotalTagCounter+=args.TagReport.nTags));
    //emit Log("", "\n\r");

    for (int i = 0; i < args.TagReport.nTags; i++)
    {

        // Reuse the tag object and set new data into it.
        CurrentTag->SetTagData(args.TagReport.Tags[i]);

        // Log unique EPCs. Used for debugging.
        //if (!SystemSettings->UniqueTagsDatabase.contains(CurrentTag->EPC))// && CurrentTag->EPC.startsWith("FF"))
        //{
        //    SystemSettings->UniqueTagsDatabase.insert(CurrentTag->EPC, 1);
        //    emit Log("DEBUG", QString("New tag seen: %1 (Total %2)\n\r").arg(CurrentTag->EPC).arg(SystemSettings->UniqueTagsDatabase.size()));
        //}
        //int Count = SystemSettings->UniqueTagsDatabase.value(CurrentTag->EPC) + 1;
        //SystemSettings->UniqueTagsDatabase.insert(CurrentTag->EPC, Count);

        //emit Log("DEBUG", QString("EPC: %1\n\r").arg(args.TagReport.Tags[i].Epc));
        //emit Log("", "\n\r");


        // Always beep on test chips, irrespective of beep type.
        if (CurrentTag->isTestChip())
            emit StartTagReportBeep();


        // Tell other threads that a new data tag record is available.
        if(SystemSettings->DataOneApplicationSettings.EnableDataPort || SystemSettings->DataOneApplicationSettings.EnableWriteDataLog)
            emit NewDataRecordAvailable(CurrentTag->TagReportWithEPCToQByteArray(), CurrentTag->EPCRecordNumber);

        // Beep.
        if (SystemSettings->DataOneDeviceSettings.Beep == "unfiltered")
            emit StartTagReportBeep();


        if (SystemSettings->DataOneDeviceSettings.FilterLength < 0)
        {
            // Start mode filtering.

            // Store all new tags in start mode database.
            SystemSettings->StartModeTagDatabase.insert(CurrentTag->EPC, CurrentTag->TagDataToQString());

            // If tag seen for the first time, insert it into the filter database.
            if(!SystemSettings->FilterDatabase.contains(CurrentTag->EPC))
            {
                SystemSettings->FilterDatabase.insert(CurrentTag->EPC, CurrentTag->LastSeenDateTime);
                //emit Log("DEBUG", QString("New tag found: %1  (Total: %2)\n\r").arg(args.TagReport.Tags[i].Epc).arg(SystemSettings->FilterDatabase.size()));
            }
        }
        else if (SystemSettings->DataOneDeviceSettings.FilterLength > 0)
        {
            // Normal mode filtering.

            // If this record is to be filtered, do nothing.
            if (CurrentTag->Filter())
            {
               // Doing nothing.
            }
            else
            {
                // Convert from tag object to filtered record format.
                QByteArray newTagBIBByteArray = CurrentTag->TagReportWithBIBToQByteArray();

                // If it is a valid record, take actions.
                if (!newTagBIBByteArray.isEmpty())
                {
                    // Tell other threads that a new filtered tag record is available.
                    if(SystemSettings->DataOneApplicationSettings.EnableFilteredPort || SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
                        emit NewFilteredRecordAvailable(newTagBIBByteArray, CurrentTag->BIBRecordNumber);

                    // Beep.
                    if (SystemSettings->DataOneDeviceSettings.Beep == "filtered")
                        emit StartTagReportBeep();
                }
            }
        }
    }

    SpeedwayReader::OnTagsReported(args);
}



void Reader::OnLogging(LoggingEventArgs & args)
{
    // Reformat OctaneSDK log statements to our own.
    LogEntry entry = args.Entry;

    emit Log("", "\n\r");
    emit Log("SYSTEM RESPONSE", QString("%1:%2\n\r").arg(QString(LogLevelToString(entry.Level))).arg(QString(entry.Message)));
    emit Log("", "\n\r");

    SpeedwayReader::OnLogging(args);
}


void Reader::OnGpiChanged(GpiChangedEventArgs &args)
{
    // Send GPI state change info to GPIOHandle thread. Offload processing.
    emit GPIChanged(args, QDateTime::currentDateTime());

    SpeedwayReader::OnGpiChanged(args);
}

void Reader::OnAntennaChanged(AntennaChangedEventArgs &args)
{
    if (args.State == AntennaConnectionState_Connected)
    {
        emit Log("", "\n\r");
        emit Log("ANTENNA", QString("Antenna %1 changed state to : Connected.\n\r").arg(args.PortNumber));
        emit Log("", "\n\r");

        // Enable the antenna and set power.
        ReaderSettings.Antennas.Elements[args.PortNumber - 1].IsEnabled = true;
        ReaderSettings.Antennas.Elements[args.PortNumber - 1].TxPowerInDbm = SystemSettings->ReaderAntennaDefinitions[args.PortNumber].TxPower;

        // Inform all clients.
        emit Broadcast(QString("message 10 ant.%1.connect\r\n").arg(args.PortNumber));

        //if (!isReading) SpeedwayReader::ApplySettings(ReaderSettings);

    }
    else if (args.State == AntennaConnectionState_NotConnected)
    {
        emit Log("", "\n\r");
        emit Log("ANTENNA", QString("Antenna %1 changed state to : Disonnected.\n\r").arg(args.PortNumber));
        emit Log("", "\n\r");

        // Disable the antenna.
        ReaderSettings.Antennas.Elements[args.PortNumber - 1].IsEnabled = false;

        // Inform all clients.
        emit Broadcast(QString("message 90 ant.%1.disconnect\r\n").arg(args.PortNumber));

        //if (!isReading) SpeedwayReader::ApplySettings(ReaderSettings);
    }

    // Set flag.
    isAntennaChanged = true;

    SpeedwayReader::OnAntennaChanged(args);
}


void Reader::OnReportBufferOverflowed(ReportBufferOverflowedEventArgs & args)
{
    // There is a buffer on the radio side, where tag reports are temporarily stored.
    // If application does not offload the tag reports via LLRP, the radio side buffer will overflow.
    // This warning will arrive just before radio buffer is about to overflow.

    QDateTime EventDateTime = AdjustTimeZone(args.Timestamp); //TimeZone adjustment
    emit Log("", "\n\r");
    emit Log("WARNING", QString("The report buffer on the reader is nearly full. %1\n\r").arg(EventDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
    emit Log("", "\n\r");

    SpeedwayReader::OnReportBufferOverflowed(args);
}


//PUBLIC SLOT
void Reader::ConnectLLRP()
{
    // Attempt connection only if not already connected.
    if (!isConnected)
    {
        emit Log("ACTION", QString("Connecting to Reader.\n\r"));

        // Connect to the reader. The name is the host name or IP address.
        bool ConnectionAttemptSuccesful = false;

        do
        {
            try
            {
                Connect("localhost"); isConnected = true;
                ConnectionAttemptSuccesful = true;
            }
            catch (OctaneSdkException ex)
            {
                // OctaneSdkExceptions are detected by the Octane SDK
                // library. These exceptions usually indicate either
                // something wrong with the reader or something wrong
                // with the application's request.
                emit Log("SYSTEM RESPONSE:ConnectLLRP", QString("OctaneSdk detected: %1\n\r").arg(ex.what()));
                emit Log("", "\n\r");

                ConnectionAttemptSuccesful = false;
                qApp->quit();
            }

        }
        while(!ConnectionAttemptSuccesful);


        // Set GPO default states.
        SpeedwayReader::SetGpo(1, false);
        SpeedwayReader::SetGpo(2, true);    // Inverted.
        SpeedwayReader::SetGpo(3, true);    // Inverted.
        SpeedwayReader::SetGpo(4, false);
    }
    else
    {
        emit Log("STATUS", QString("Already connected to Reader.\n\r"));
        emit Log("", "\n\r");
    }
}

//PUBLIC SLOT
void Reader::DisconnectLLRP()
{
    // Attempt to disconnect only if already connected.
    if (isConnected)
    {
        emit Log("ACTION", QString("Disconnecting from Reader.\n\r"));

        // Restore GPO default states.
        SetGpo(1, false);
        SetGpo(2, true);    // Inverted.
        SetGpo(3, true);    // Inverted.
        SetGpo(4, false);

        // Disconnect LLRP and set flags.
        Disconnect(); isConnected = false; isReading = false;
    }
    else
    {
        emit Log("STATUS", QString("Not connected to Reader.\n\r"));
        emit Log("", "\n\r");
    }
}

//PUBLIC SLOT
void Reader::StartReading()
{
    try{
        // Only attempt to start reading if not already reading.
        if (!isReading)
        {
            // If LLRP is connected, only inform the user. Do not attempt connection automatically.
            if (!isConnected)
            {
                emit Log("ERROR", QString("LLRP not connected.... Connect LLRP first.\n\r"));
                return;
            }

            if (isSettingChanged)
            {
                // Apply antenna settings.
                setAntennas();
                isAntennaChanged = false;

                // Apply all other settings.
                emit Log("ACTION", QString("Applying settings.\n\r"));
                SpeedwayReader::ApplySettings(ReaderSettings);
                isSettingChanged = false;
            }

            // Start the reader, and set flags.
            emit Log("ACTION", QString("StartReading: Starting Reader now.\n\r"));
            Start(); isReading = true; SystemSettings->SetReadingStatus(true);

            // Start timer for start mode.
            if (SystemSettings->DataOneDeviceSettings.FilterLength < 0)
                StartModeTimer->start();

        }
        else
        {
            emit Log("STATUS", QString("StartReading: Already reading.\n\r"));
            emit Log("", "\n\r");
        }

    }
    catch (OctaneSdkException ex)
    {
        // OctaneSdkExceptions are detected by the Octane SDK
        // library. These exceptions usually indicate either
        // something wrong with the reader or something wrong
        // with the application's request.
        emit Log("SYSTEM RESPONSE:StartReading", QString("OctaneSdk detected: %1\n\r").arg(QString(ex.what())));
    }
    catch (exception ex)
    {
        // Any other kind of exception deteced by the system.
        emit Log("SYSTEM RESPONSE:StartReading", QString("Exception: %1\n\r").arg(QString(ex.what())));
    }
}

//PUBLIC SLOT
void Reader::StopReading()
{
    try
    {
        // Attempt to stop reading only if already reading.
        if (isReading)
        {
            emit Log("ACTION", QString("StopReading: Stopping Reader now.\n\r"));

            // Stop reading and set flags.
            Stop(); isReading = false; SystemSettings->SetReadingStatus(false);

            StartModeTimer->stop();
            FlushStartModeDatabase();
            SystemSettings->StartModeTagDatabase.clear(); // Clear any provious remnants of tags.
            SystemSettings->FilterDatabase.clear(); //Clear database to start fresh next time.
        }
        else
        {
            emit Log("STATUS", QString("StopReading: Not reading.\n\r"));
            emit Log("", "\n\r");
        }

    }
    catch (OctaneSdkException ex)
    {
        // OctaneSdkExceptions are detected by the Octane SDK
        // library. These exceptions usually indicate either
        // something wrong with the reader or something wrong
        // with the application's request.
        emit Log("SYSTEM RESPONSE:StopReading", QString("OctaneSdk detected: %1\n\r").arg(QString(ex.what())));
        emit Log("", "\n\r");
    }
    catch (exception ex)
    {
        // Any other kind of exception deteced by the system.
        emit Log("SYSTEM RESPONSE:StopReading", QString("Exception: %1\n\r").arg(QString(ex.what())));
        emit Log("", "\n\r");
    }

}



//PUBLIC SLOT
void Reader::ParseClientCommand(QByteArray Command)
{
    if (Command == "clear_buffer")
    {
        emit Log("ACTION", QString("Clearing local record buffers.\n\r"));

        // Tell all threads to take action accordingly.
        emit ClearBuffers();

        // Reset all record counters.
        TagRecord::ResetRecordCounters();
    }

    else if (Command == "connect_llrp")
    {
        ConnectLLRP();  // Connect to LLRP.
    }
    else if (Command == "disconnect_llrp")
    {
        DisconnectLLRP();   // Disconnect from LLRP.
    }

    else if (Command == "start_reading")
    {
        StartReading(); // Start reading.
    }
    else if (Command == "stop_reading")
    {
        StopReading();  // Stop reading.
    }

    else if (Command == "action_clear_all_logs")
    {
        emit Log("ACTION", QString("Clearing log files.\n\r"));

        // Tell the file writers.
        emit ClearAllLogs();

        // Reset all record counters.
        TagRecord::ResetRecordCounters();
    }

    else if (Command.startsWith("set_date_time="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 14);

        if (Command == "ntp")
        {
            SystemSettings->UpdateDateTimeFromNTP();
            SystemSettings->SynchronizeHardwareClock();
            SystemSettings->isDateTimeManuallySet = false;
            SystemSettings->isTimeZoneAdjustmentEnabled = true;
            emit Log("ACTION", QString("NTP time synchronization enabled.\n\r"));
        }
        else
        {
            if (Command.length() == 23)
                setTime(Command);
            else
                emit Log("ACTION", QString("Invalid Date time format. Valid format: dd.MM.yyy hh:mm:ss.zzz\n\r"));
        }
    }

    else if (Command.startsWith("set_frequency="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 14);
        setFrequency(Command);
    }

    else if (Command.startsWith("set_reader_mode="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 16);
        setReaderMode(Command);
    }

    else if (Command.startsWith("set_search_mode="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 16);
        setSearchMode(Command);
    }

    else if (Command.startsWith("set_session="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 12);
        setSession(Command.toInt());
    }

    else if (Command.startsWith("set_tag_volume="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 15);
        setTagVolume(Command);
    }

    else if (Command.startsWith("set_antennas="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 13);

        SystemSettings->DataOneDeviceSettings.Antennas = QString(Command);  // Save the new values to application configuration.
        SystemSettings->ParseAntennaSettings();                             // Fill the antenna definitions array.
        SystemSettings->isAntennasTemp = false;                             // Enable saving in DataOne.ini

        setAntennas();

        // Save settings immediately.
        emit SaveDeviceSettings();

        if (isReading)
        {
            StopReading();
            StartReading();
        }
    }

    else if (Command.startsWith("set_antennas_temp="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 18);

        SystemSettings->DataOneDeviceSettings.Antennas = QString(Command);  // Save the new values to application configuration.
        SystemSettings->ParseAntennaSettings();                             // Fill the antenna definitions array.
        SystemSettings->isAntennasTemp = true;                              // Disable saving in DataOne.ini

        setAntennas();

        if (isReading)
        {
            StopReading();
            StartReading();
        }
    }

    else if (Command.startsWith("set_beep_duration="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 18);
        setBeepDuration(Command);
    }

    else if (Command.startsWith("set_beep="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 9);
        setBeep(Command);
    }

    else if (Command.startsWith("set_reader_no="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 14);

        SystemSettings->DataOneDeviceSettings.Reader_Number = Command.toUInt(); // Save in application cofiguration.

        // Save settings immediately.
        emit SaveDeviceSettings();
        emit Log("ACTION", QString("Setting Reader Number to : %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Reader_Number));
    }

    else if (Command.startsWith("set_timepoint_desc="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 19);

        SystemSettings->DataOneDeviceSettings.TimePointDesc = QString(Command); // Save in application cofiguration.

        // Save settings immediately.
        emit SaveDeviceSettings();
        emit Log("ACTION", QString("Setting TimePointDesc to : %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.TimePointDesc));
    }

    else if (Command.startsWith("set_filter_length="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 18);
        int FilterLength = Command.toInt();

        if (FilterLength < 0)
        {
            if (FilterLength < -9999)
            {
                FilterLength = -9999;
                emit Log("ACTION", QString("Filter Length: Out of range... (0-9999). Limiter applied.\n\r"));
            }

            emit Log("ACTION", QString("Reader filtering is now in START mode. \n\r"));

            if (isReading)
                StartModeTimer->start();
        }
        else if (FilterLength > 0)
        {
            if (FilterLength > 9999)
            {
                FilterLength = 9999;
                emit Log("ACTION", QString("Filter Length: Out of range... (0-9999). Limiter applied.\n\r"));
            }

            emit Log("ACTION", QString("Reader filtering is in NORMAL mode. \n\r"));

            if (isReading)
            {
                StartModeTimer->stop();
                FlushStartModeDatabase();
                SystemSettings->StartModeTagDatabase.clear(); // Clear
            }
        }

        SystemSettings->DataOneDeviceSettings.FilterLength = FilterLength; // Save in application cofiguration.
        SystemSettings->isFilterLengthTemp = false;                        // Enable saving in DataOne.ini

        // Save settings immediately.
        emit SaveDeviceSettings();
        emit Log("ACTION", QString("Setting Filter Length to : %1 sec. \n\r").arg(SystemSettings->DataOneDeviceSettings.FilterLength));
    }

    else if (Command.startsWith("set_filter_length_temp="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 23);
        int FilterLength = Command.toInt();

        if (FilterLength < 0)
        {
            if (FilterLength < -9999)
            {
                FilterLength = -9999;
                emit Log("ACTION", QString("Filter Length: Out of range... (0-9999). Limiter applied.\n\r"));
            }

            emit Log("ACTION", QString("Reader filtering is now in START mode. \n\r"));

            if (isReading)
                StartModeTimer->start();
        }
        else if (FilterLength > 0)
        {
            if (FilterLength > 9999)
            {
                FilterLength = 9999;
                emit Log("ACTION", QString("Filter Length: Out of range... (0-9999). Limiter applied.\n\r"));
            }

            emit Log("ACTION", QString("Reader filtering is in NORMAL mode. \n\r"));

            if (isReading)
            {
                StartModeTimer->stop();
                FlushStartModeDatabase();
                SystemSettings->StartModeTagDatabase.clear(); // Clear
            }
        }

        SystemSettings->DataOneDeviceSettings.FilterLength = FilterLength; // Save in application cofiguration.
        SystemSettings->isFilterLengthTemp = true;                         // Disable saving in DataOne.ini

        emit Log("ACTION", QString("Setting Filter Length to : %1 sec. \n\r").arg(SystemSettings->DataOneDeviceSettings.FilterLength));
    }

    else if (Command.startsWith("set_filter_drift="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 17);

        SystemSettings->DataOneDeviceSettings.FilterDrift = Command.toInt(); // Save in application cofiguration.

        // Save settings immediately.
        emit SaveDeviceSettings();
        emit Log("ACTION", QString("Setting Filter Drift to : %1 msec. \n\r").arg(SystemSettings->DataOneDeviceSettings.FilterDrift));
    }

    else if (Command.startsWith("action_alert="))
    {
        // Remove the command string, keep the value.
        Command.remove(0, 13);

        // Flter illegal alert values.
        if (Command.length() > 1) emit Log("ERROR", QString("Illegal command.\n\r"));
        if (Command.toInt() < 1 && Command.toInt() > 3) emit Log("ERROR", QString("Incorrect alert type.\n\r"));

        emit Log("", "\n\r");

        // Send signal to GPIOHandler to start action alert.
        emit PerformActionAlert(Command.toInt());
    }

    else if (Command == "d1_shutdown")
    {
        system("killall start");

        if (isReading)
            StopReading();

        SystemSettings->ShutDown(); // Commit unsaved changes to disk.
        emit DataOneShutdown();     // Shutdown all threads.

        sleep(3);

        if (isConnected)
        {
            // Turn OFF GPOs.
            SpeedwayReader::SetGpo(1, false);
            SpeedwayReader::SetGpo(2, true);    // Inverted.
            SpeedwayReader::SetGpo(4, false);
            SpeedwayReader::SetGpo(3, true);    // Inverted.

            DisconnectLLRP();
        }
        else
        {
            ConnectLLRP();

            // Turn OFF GPOs.
            SpeedwayReader::SetGpo(1, false);
            SpeedwayReader::SetGpo(2, true);    // Inverted.
            SpeedwayReader::SetGpo(4, false);
            SpeedwayReader::SetGpo(3, true);    // Inverted.

            DisconnectLLRP();
        }


        QCoreApplication::instance()->quit();
    }

    else if (Command == "reader_reboot")
    {
        if (isReading)
            StopReading();

        emit DataOneShutdown();
        sleep(3);

        if (isConnected)
        {
            // Turn OFF GPOs.
            SpeedwayReader::SetGpo(1, false);
            SpeedwayReader::SetGpo(2, true);    // Inverted.
            SpeedwayReader::SetGpo(4, false);
            SpeedwayReader::SetGpo(3, true);    // Inverted.

            DisconnectLLRP();
        }
        else
        {
            ConnectLLRP();

            // Turn OFF GPOs.
            SpeedwayReader::SetGpo(1, false);
            SpeedwayReader::SetGpo(2, true);    // Inverted.
            SpeedwayReader::SetGpo(4, false);
            SpeedwayReader::SetGpo(3, true);    // Inverted.

            DisconnectLLRP();
        }


        system("reboot");
        QCoreApplication::instance()->quit();
    }

    else
    {
        emit Log("ERROR", QString("Illegal command.\n\r"));
        emit Log("", "\n\r");
    }


}



//PUBLIC SLOT
void Reader::setGPO(int PortNumber, bool State)
{
    if (isConnected)
    {
        // Set the new GPO state received from GPIOHandler.
        SpeedwayReader::SetGpo(PortNumber, State);
    }
}

//PUBLIC SLOT
void Reader::RefreshAntennas()
{
    if (isConnected)
    {
        // Refresh the reader antennas status.
        ReaderStatus = SpeedwayReader::QueryStatus(StatusRefresh_JustAntennas);

        // Get antennas state.
        QString AntennaState;

        for (
             int portNumber = Constants::MinAntennaPortNumber;
             portNumber <= Constants::MaxAntennaPortNumber;
             portNumber++)
        {
            AntennaStatus *antStat = &ReaderStatus.Antennas[portNumber];
            const char *stateStr = "";

            switch (antStat->State)
            {
            // The port present is on the reader and connected to an antenna.
            case AntennaConnectionState_Connected:
                stateStr = "Connected";
                // Enable the antenna and set power.
                ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = true;
                ReaderSettings.Antennas.Elements[portNumber - 1].TxPowerInDbm = SystemSettings->ReaderAntennaDefinitions[portNumber - 1].TxPower;
                break;

                // The port is present on the reader but is not connected to an antenna, or the connection is bad.
            case AntennaConnectionState_NotConnected:
                stateStr = "Disconnected";
                // Disable the antenna.
                ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                break;

                // No such port on the reader.
            case AntennaConnectionState_NotApplicable:
                stateStr = "N/A";
                // Disable the antenna.
                ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                break;

                // Unknown state. This usually means something went wrong while communicating with the reader.
            case AntennaConnectionState_Unknown:
                stateStr = "Unknown";
                // Disable the antenna.
                ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                break;

                // Should never happen.
            default:
                stateStr = "??";
                // Disable the antenna.
                ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                break;
            }
            AntennaState += QString("%1:%2 ").arg(antStat->PortNumber).arg(QString(stateStr));
        }

        SpeedwayReader::ResumeEventsAndReports();
    }
}



//PRIVATE SLOT
void Reader::getReaderStatus()
{
    // Get new reader parameters. This function is on timer.
    try
    {
        if (isConnected)
        {
            // Refresh the reader status, otherwise parameters will not be updated.
            ReaderStatus = SpeedwayReader::QueryStatus(StatusRefresh_Everything);

            // Report reader temperature to other threads.
            emit UpdateTemperature(ReaderStatus.TemperatureInCelsius);

            // Get antennas state.
            QString AntennaState;

            for (
                 int portNumber = Constants::MinAntennaPortNumber;
                 portNumber <= Constants::MaxAntennaPortNumber;
                 portNumber++)
            {
                AntennaStatus *antStat = &ReaderStatus.Antennas[portNumber];
                const char *stateStr = "";

                QString AntennaPower;


                switch (antStat->State)
                {
                // The port present is on the reader and connected to an antenna.
                case AntennaConnectionState_Connected:
                    stateStr = "Connected";
                    // Enable the antenna and set power.
                    ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = true;
                    ReaderSettings.Antennas.Elements[portNumber - 1].TxPowerInDbm = SystemSettings->ReaderAntennaDefinitions[portNumber - 1].TxPower;
                    AntennaPower.append(QString("%1").arg(SystemSettings->ReaderAntennaDefinitions[portNumber - 1].TxPower));
                    break;

                    // The port is present on the reader but is not connected to an antenna, or the connection is bad.
                case AntennaConnectionState_NotConnected:
                    stateStr = "Disonnected";
                    // Disable the antenna.
                    ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                    break;

                    // No such port on the reader.
                case AntennaConnectionState_NotApplicable:
                    stateStr = "N/A";
                    // Disable the antenna.
                    ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                    break;

                    // Unknown state. This usually means something went wrong while communicating with the reader.
                case AntennaConnectionState_Unknown:
                    stateStr = "Unknown";
                    // Disable the antenna.
                    ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                    break;

                    // Should never happen.
                default:
                    stateStr = "??";
                    // Disable the antenna.
                    ReaderSettings.Antennas.Elements[portNumber - 1].IsEnabled = false;
                    break;
                }

                if (QString(stateStr) == "Connected")
                    AntennaState += QString("%1:%2,%3 ").arg(antStat->PortNumber).arg(QString(stateStr)).arg(AntennaPower);
                else
                    AntennaState += QString("%1:%2 ").arg(antStat->PortNumber).arg(QString(stateStr));
            }

            // Report antennas state to other threads.
            emit UpdateAntennaState(AntennaState);

            SpeedwayReader::ResumeEventsAndReports();
        }
        else
        {
            emit UpdateTemperature(0);

        }

    }
    catch (OctaneSdkException ex)
    {
        emit UpdateTemperature(0);
    }
    catch (exception ex)
    {
        emit UpdateTemperature(0);
    }


}


// PRIVATE SLOT
void Reader::ProcessStartModeTags()
{
    if (SystemSettings->FilterDatabase.isEmpty() || SystemSettings->StartModeTagDatabase.isEmpty())
    {
        //WriteLockStartModeDatabase = false;
        return;
    }

    //emit Log("", QString("\n\r"));
    //emit Log("DEBUG", QString("Starting ProcessStartModeTags()... \n\r"));
    //emit Log("DEBUG", QString("UniqueTagsDatabase size:   %1\n\r").arg(SystemSettings->UniqueTagsDatabase.size()));
    //emit Log("DEBUG", QString("FilterDatabase size:       %1\n\r").arg(SystemSettings->FilterDatabase.size()));
    //emit Log("DEBUG", QString("StartModeTagDatabase size: %1\n\r").arg(SystemSettings->StartModeTagDatabase.size()));

    //qDebug() << SystemSettings->StartModeTagDatabase;

    // Setup tag record object for handling tag reports.
    TagRecord *StartModeTag = new TagRecord(SystemSettings, this);
    QList<QString> StartModeTagsList = SystemSettings->FilterDatabase.uniqueKeys();


    while (!StartModeTagsList.isEmpty())
    {
        QDateTime NowTime = SystemSettings->AdjustTimeZoneAndDST(QDateTime::currentDateTime());

        QString TagEPC = StartModeTagsList.takeFirst();                     // Get and remove first EPC from list.
        QDateTime TagLastSendTime = SystemSettings->FilterDatabase.value(TagEPC);   // Get last transmit time of tag from FilterDatabase.
        int TagAge = TagLastSendTime.msecsTo(NowTime)/1000;

        //emit Log("", QString("Tag(%1) age = %2 sec.\n\r").arg(TagEPC).arg(TagAge));

        if (TagAge > abs(SystemSettings->DataOneDeviceSettings.FilterLength))
        {
            if (!SystemSettings->StartModeTagDatabase.contains(TagEPC))
            {
                // Cleanup. Tag was not seen during prevoius period, delete the record.
                SystemSettings->FilterDatabase.remove(TagEPC);
                //emit Log("", QString("Tag(%1) Absent1... deleting record.\n\r").arg(TagEPC));
            }
            else
            {
                //emit Log("", QString("Tag(%1) Processing.....\n\r").arg(TagEPC));

                QString TagDataInString = SystemSettings->StartModeTagDatabase.value(TagEPC);
                StartModeTag->SetTagDataFromQString(TagDataInString);
                //emit Log("", QString("Tag = %1\n\r").arg(TagDataInString));

                if (StartModeTag->LastSeenDateTime >= TagLastSendTime)
                {
                    // Convert from tag object to filtered record format.
                    QByteArray newTagBIBByteArray = StartModeTag->TagReportWithBIBToQByteArray();

                    // If it is a valid record, take actions.
                    // Remember, tags only with EPC starting with "FF" will be sent. All others will be filtered.
                    if (!newTagBIBByteArray.isEmpty())
                    {
                        // Tell other threads that a new filtered tag record is available.
                        if(SystemSettings->DataOneApplicationSettings.EnableFilteredPort || SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
                        {
                            emit NewFilteredRecordAvailable(newTagBIBByteArray, StartModeTag->BIBRecordNumber);
                            SystemSettings->FilterDatabase.insert(StartModeTag->EPC, StartModeTag->LastSeenDateTime);

                            //emit Log("DEBUG", QString(">>> Sending tag %1 \n\r").arg(StartModeTag->EPC));
                        }

                        // Beep.
                        //if (SystemSettings->DataOneDeviceSettings.Beep == "filtered")
                        //    emit StartTagReportBeep();
                    }
                }

                if (StartModeTag->LastSeenDateTime < TagLastSendTime || TagAge >= 2*SystemSettings->DataOneDeviceSettings.FilterLength)
                {
                    // Cleanup. Tag was not seen during prevoius period, delete the record.
                    SystemSettings->FilterDatabase.remove(TagEPC);
                    SystemSettings->StartModeTagDatabase.remove(TagEPC);
                    //emit Log("", QString("Tag(%1) Absent2... deleting record.\n\r").arg(TagEPC));
                }
            }
        }
        else
        {
            //emit Log("", QString("Tag(%1) Ignoring.....\n\r").arg(TagEPC));
        }
    }

    delete StartModeTag;

}


// PRIVATE FUNCTION
void Reader:: FlushStartModeDatabase()
{
    if (SystemSettings->StartModeTagDatabase.isEmpty())
    {
        //WriteLockStartModeDatabase = false;
        return;
    }

    // Setup tag record object for handling tag reports.
    TagRecord *StartModeTag = new TagRecord(SystemSettings, this);
    QList<QString> StartModeTagsList = SystemSettings->StartModeTagDatabase.uniqueKeys();

    if (!SystemSettings->StartModeTagDatabase.isEmpty())
    {
        while (!StartModeTagsList.isEmpty())
        {
            QString TagEPC = StartModeTagsList.takeFirst(); // Get and remove first EPC from list.
            QDateTime TagTime = SystemSettings->FilterDatabase.value(TagEPC); // Get last transmit time of tag from FilterDatabase.

            QString TagDataInString = SystemSettings->StartModeTagDatabase.take(TagEPC);
            StartModeTag->SetTagDataFromQString(TagDataInString);

            if (StartModeTag->LastSeenDateTime > TagTime)
            {

                // Always beep on test chips, irrespective of beep type.
                if (StartModeTag->isTestChip())
                    emit StartTagReportBeep();

                // Convert from tag object to filtered record format.
                QByteArray newTagBIBByteArray = StartModeTag->TagReportWithBIBToQByteArray();

                // If it is a valid record, take actions.
                if (!newTagBIBByteArray.isEmpty())
                {
                    // Tell other threads that a new filtered tag record is available.
                    if(SystemSettings->DataOneApplicationSettings.EnableFilteredPort || SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
                    {
                        emit NewFilteredRecordAvailable(newTagBIBByteArray, StartModeTag->BIBRecordNumber);

                    }

                    // Beep.
                    //if (SystemSettings->DataOneDeviceSettings.Beep == "filtered")
                    //    emit StartTagReportBeep();

                }
            }
        }
    }

    delete StartModeTag;
}


