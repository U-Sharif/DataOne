#ifndef TAGRECORD_H
#define TAGRECORD_H

#include <QObject>
#include <QDateTime>

#include "../Settings/settings.h"

#include <OctaneSdk.h>
using namespace Impinj_OctaneSdk;


// This is a conveience class for handlig all RFID tag related operations.
// A Tag is handed over from radio to OctaneSDK via LLRP protocol.
// From OctaneSDK, the tag is handedover to our code for processing, filtering, storing and sending.

class TagRecord : public QObject
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Constructor.
    explicit TagRecord(DataOneSettings *SysSettings, QObject *parent = 0);

    // Convenience function to set new tag data into an existing TagRecord instance.
    void SetTagData(Tag newTag);

    // Function to flatten the OctaneSDK Tag data structure to QString.
    QString TagDataToQString();

    // Function to deflate QString based Tag data to this class.
    void SetTagDataFromQString(QString);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

    // Global Record Counters.
    // Will be incremented after every tag report.
    // Will be reset to 1 on command "clear_buffer" from Tcp Clinet.
    // Initialized in TagRecord.cpp
    static quint64 DataRecordCounter;
    static quint64 FilteredRecordCounter;

    // Tag Properties.
    quint64 EPCRecordNumber;
    quint64 BIBRecordNumber;
    int SeenCount;
    int AntennaPortNumber;
    double ChannelInMhz;
    double PhaseAngleInRadians;
    double RssiInDbm;
    QString SerializedTid;
    QString EPC;
    QDateTime FirstSeenDateTime;
    QDateTime LastSeenDateTime;


    // End of Record marker.
    // Will be essentially "\r\n", as per specification.
    // Initialized in TagRecord.cpp
    static QString RecordEndMark;

    // Bytearray to hold the decrypt key. Used in filtering.
    QByteArray DecryptKey;


    // Functions
    static void ResetRecordCounters()                       // To reset the record counters.
    { DataRecordCounter = 1; FilteredRecordCounter = 1;}

    // Functions to convert values into asci strings.
    QString SeenCountToQString();
    QString AntennaPortNumberToQString();
    QString ChannelInMhzToQString();
    QString PhaseAngleInRadiansToQString();
    QString RssiInDbmToQString();
    QString FirstSeenDateTimeToQString();
    QString LastSeenDateTimeToQString();

    // Functions to give the tag report a final shape for storage and sending.
    QString TagReportWithEPCToQString();
    QByteArray TagReportWithEPCToQByteArray();

    QString TagReportWithBIBToQString();                    // A parsed EPC is called a BIB.
    QByteArray TagReportWithBIBToQByteArray();

    // Function to check if the tag is a test chip.
    bool isTestChip();

    // Functions to process the tag EPC and filter the tags.
    bool Filter();
    QString ParseEPC();
    QString DecodeEPC(QString EPCString);
    QByteArray XORData(QByteArray Data, QByteArray Key, int Length);

};

#endif // TAGRECORD_H
