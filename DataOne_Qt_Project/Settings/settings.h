#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QFile>
#include <QMap>
#include <QHash>
#include <QList>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QTextStream>
#include <QStringList>
#include <QHostAddress>
#include <QNetworkInterface>

#include "../Structures/structures.h"

#include <OctaneSdk.h>
using namespace Impinj_OctaneSdk;


// This class handles all the settings of DataOne application.
// There is only one instance of this class in the whole application.
// This single instance is accessed by all the threads in this application via pointers.
// This class inherits QObject of Qt framework.

class DataOneSettings : public QObject
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit DataOneSettings(QObject *parent = 0);

    // This is a run-once function for setting the reader number from network IP address.
    void SetReaderNumber();

    //File system structure
    QString DataFolderPath;         // Path for storing raw tag record log files on USB memory device.
    QString FilteredFolderPath;     // Path for storing filtered tag record log files on USB memory device.
    QString ConsoleLogFolderPath;   // Path for storing console log file (only one file) on USB memory device.

    QString CurrentDataLogFileName;         // Filename of current open raw tag record log file.
    QString CurrentFilteredLogFileName;     // Filename of current open filtered tag record log file.

    // RECORD FOOTPRINT //
    // During development, it was seen that when records are read back from log files, considerable time was wasted
    // in just waiting for the read pointer to reach the correct record from start of file. Specially, when a single
    // log file contains over a million tag records. A need for some simple and low delay mechanism was felt, which
    // could take the read pointer to correct record start position as early as possible. Something like a primitive
    // database system. Therefore, a footprint of the currently open log file is saved in a file named "footprint" in
    // each log directory. The file position pointer for the 1st record and thereon after every 999 records is written
    // to the footprint file. While reading back (SX command from TCP clients), first this footprint file is read
    // for finding the closest(lower) file position value to the requested record. Then, the file position pointer
    // directly jumps to this file position (via 'seek' command), and searches for the correct record after this position.
    // This way, the maximum wasted time is equal to searching for the nearest lower file position, and that of reading
    // and discarding 1000 records, no matter how large the log file is.

    // Max time delay for SX command result = (Time to search nearest lower file position in footprint file) + (Time to search for the correct record number after the seeked file position)

    // This log file footprint can be kept in RAM as well as on USB disk.
    // From RAM, the read back is very fast, but QMap conatiner object will get big after a lot of records and hog the RAM.
    // Therefore, to avoid any memory issues, footprint was shifted to USB memory device.

    // RAM based File Record Position footprint.
    //QMap<qint64, qint64> DataLogFootprintMap;
    //QMap<qint64, qint64> FilteredLogFootprintMap;

    // USB based File Record Position footprint.
    QFile DataFootprintFile;
    QFile FilteredFootprintFile;

    // Functions for writing the footprints to USB memory device
    void LogDataFootprint(qint64, QByteArray);
    void LogFilteredFootprint(qint64, QByteArray);

    // Functions for retrieving file position (based on the requested record number) from footprint files.
    qint64 GetDataPosition(qint64);
    qint64 GetFilteredPosition(qint64);

    qint64 GetDataTimePosition(QDateTime);
    qint64 GetFilteredTimePosition(QDateTime);

    // Functions for resetting the footprints when new log files are opened.
    void ResetDataFootprint();
    void ResetFilteredFootprint();

    // Filtered tags database. This is kept in RAM for fast matching and performance.
    // In a real scenario, with time, this will get bigger and bigger, and probably hold a lot of RAM, but performance superceedes here.
    QHash<QString,QDateTime> FilterDatabase;

    // Start mode database for storing tags in negative filter duration.
    QHash<QString, QString> StartModeTagDatabase;

    // Database to log unique tags seen. Used for debugging only.
    //QHash<QString, int> UniqueTagsDatabase;

    // Instances of settings structures, in structures.h
    ApplicationSettings DataOneApplicationSettings;
    NetworkSettings DataOneNetworkSettings;
    DeviceSettings DataOneDeviceSettings;
    TimeZone DataOneTimeSettings;

    // Enabling and disabling reader clock time zone adjustment.
    // If user sends manual time via set_date_time command, time zone adjustment is disabled.
    bool isTimeZoneAdjustmentEnabled;

    // To indicate weather reader time is manually set or not.
    // If true, reader time is maually set, and NTP time sync is disabled.
    // If false, then reader will sync with NTP server.
    bool isDateTimeManuallySet;

    // Functions to get current system time.
    QDateTime GetCurrentDateTime();
    QString GetCurrentDateTimeString();
    QString GetCurrentDateTimeFileNameString();

    // Function to adjust TimeZone and DST for a given date and time.
    QDateTime AdjustTimeZoneAndDST(QDateTime);

    // Function to run NTP update.
    int UpdateDateTimeFromNTP();

    // Function to synchronize hardware clock with OS time.
    void SynchronizeHardwareClock();

    // Function to convert manual date time to UTC time.
    QDateTime ConvertDateTimeToUTC(QDateTime);

    // Array for holding antenna definitions.
    // Constants::MaxAntennaPortNumber is defined in OctaneSdk/constants.h.
    AntennaDefinition ReaderAntennaDefinitions[Constants::MaxAntennaPortNumber];

    // Functions for loading the settings from DataOne.ini at application startup.
    void LoadApplicationSettings();
    void LoadNetworkSettings();
    void LoadDeviceSettings();

    // Functions for loading Time Zone and DST settings from TimeZone.ini file at application startup.
    void LoadTimeZoneAndDSTSettings();

    // This function converts the antenna definitions from QString format to the ReaderAntennaDefinitions array above.
    void ParseAntennaSettings();

    // Functions to set and get the reading status from temporary file.
    void SetReadingStatus(bool);
    bool GetReadingStatus();

    //Function to get reading status (on/off)
    QString GetReadingStatusString();

    // Function to force sync unsaved changes to disk upon D1 Shutdown.
    void ShutDown();


    bool isUSBDevicePresent;    //Set by SystemMonitor Class.
    bool isInternetAvailable;   //Set by SystemMonitor Class.
    double InternetPingTime;    //Set by SystemMonitor Class.

    int BackupPowerReadingCutOffTime;   // When operating on battery, stop reading after this interval.

    QString WebUploadServerURL;

    bool isFilterLengthTemp;
    bool isAntennasTemp;

    bool isNewReader; //Added in D1 version 2.0+ to check for new or old readers.

private:
    // For reading and writing settings in DataOne.ini
    QSettings* AppSettings;

    // For reading and writing Time Zone and DST related settings.
    // We have to handle these settings ourselves because the current OS does not support timezones and DST.
    QSettings* TimeSettings;

    // For reading and writing settings in ReaderStatus.ini
    QSettings* ReaderSettings;


public slots:

    // Functions to save the changed values under [Application] and [Reader] tags in DataOne.ini.
    // Values under the [Network] tag in DataOne.ini are never changed by the application.
    void SaveApplicationSettings();
    void SaveDeviceSettings();


};

#endif // SETTINGS_H
