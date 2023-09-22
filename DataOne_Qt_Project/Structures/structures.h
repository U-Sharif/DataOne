#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <QString>
#include <QDateTime>

#include <OctaneSdk.h>
using namespace Impinj_OctaneSdk;

// Structure for Antenna Definitions.
struct AntennaDefinition
{
    bool isDefined;
    double TxPower;
};

// Structure for Application Settings.
// Corresponds to all the values under [Application] tag in DataOne.ini.
struct ApplicationSettings
{
    QString AppVersion;
    bool EnableWriteDataLog;
    bool EnableWriteFilteredLog;
    bool EnableWriteConsoleLog;
    bool EnableDataPort;
    bool EnableFilteredPort;
    bool EnableConsolePort;
    bool EnableTimingServer1;
    bool EnableTimingServer2;
};

// Structure for Network Settings.
// Corresponds to all the values under [Network] tag in DataOne.ini.
struct NetworkSettings
{
    quint16 DataPort;
    quint16 FilteredPort;
    quint16 ConsolePort;
    int PingInterval;
    int MaxConnectedClients;
    QString TimingServer1Address;
    QString TimingServer2Address;
    quint16 TimingServerBasePort;
    QString LogUploadServerAddress; //Web address of HTTP(S) server for uploading console log.
    bool LogUploadServerUseSSL;
    QString PingIPAddress;
    QString InternetCheckURL;
};

// Structure for Reader Device Settings.
// Corresponds to all the values under [Reader] tag in DataOne.ini.
struct DeviceSettings
{
    QString Reader_Mode;
    QString Search_Mode;
    unsigned int Session;
    QString Frequency;
    QString Tag_Volume;
    QString Antennas;
    QString Beep;
    unsigned int Reader_Number;
    unsigned int Beep_Duration;
    QString TimePointDesc;
    int FilterLength;
    int FilterDrift;

    QString Password;

    unsigned int GPI2StopDelay;

    bool isReading;
};

// Structure for Reader Time Zone and DST settings.
// This structure will be filled from TimeZone.ini file.
struct TimeZone
{
    QString TimeZoneString;

    int TimeZoneToSecs;

    bool DSTEnabled;
    bool DSTValid;

    QDateTime DST_Start;
    QDateTime DST_End;
};



#endif // STRUCTURES_H
