#include "tagrecord.h"

#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QString>
#include <QStringList>

// Initialize static variables.
quint64 TagRecord::DataRecordCounter = 1;
quint64 TagRecord::FilteredRecordCounter = 1;
QString TagRecord::RecordEndMark = "\r\n";

// CONSTRUCTOR
TagRecord::TagRecord(DataOneSettings *SysSettings, QObject *parent) :
    QObject(parent)
{
    // Defaults.

    EPCRecordNumber = 0;
    BIBRecordNumber = 0;
    SeenCount = 0;
    AntennaPortNumber = 0;

    ChannelInMhz = 0;
    PhaseAngleInRadians = 0;
    RssiInDbm = 0;

    FirstSeenDateTime = QDateTime();
    LastSeenDateTime = QDateTime();

    SystemSettings = SysSettings;
    DecryptKey = SystemSettings->DataOneDeviceSettings.Password.toLocal8Bit(); // Decrypt key comes from settings file.
}



//PUBLIC FUNCTION
void TagRecord::SetTagData(Tag newTag)
{
    // One by one, copy all values from Tag to local variables for processing.
    if (newTag.IsSeenCountPresent) SeenCount = newTag.SeenCount;
    if (newTag.IsAntennaPortNumberPresent) AntennaPortNumber = newTag.AntennaPortNumber;

    if (newTag.IsChannelInMhzPresent) ChannelInMhz = newTag.ChannelInMhz;
    if (newTag.IsPhaseAngleInRadiansPresent) PhaseAngleInRadians = newTag.PhaseAngleInRadians;
    if (newTag.IsPeakRssiInDbmPresent) RssiInDbm = newTag.PeakRssiInDbm;

    if (newTag.IsSerializedTidPresent) SerializedTid = newTag.SerializedTid;
    EPC = QString("%1").arg(newTag.Epc); // Push char data into QString.

    // FirstSeenTime = time when tag with this EPC value was detected the first time by the radio.
    // Remember, radio keeps a table of EPCs and seen times (plus counts also).
    if (newTag.IsFirstSeenTimePresent)
    {
        char timeStrBuf[32];
        newTag.FirstSeenTime.Formatter(timeStrBuf, sizeof timeStrBuf);      // Formatter is an OctaneSDK function.
        QString OctaneSDK_Format_DateTime(timeStrBuf);
        OctaneSDK_Format_DateTime.chop(4); //Remove extra text at the end of date string.
        FirstSeenDateTime =  QDateTime::fromString(OctaneSDK_Format_DateTime, "yyyy-MM-ddThh:mm:ss.zzz");

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
        //FirstSeenDateTime.setDate(newDate);
        //FirstSeenDateTime.setTime(newTime);

        // If clock adjustment is enabled, then adjust for time zone and DST.
        FirstSeenDateTime = SystemSettings->AdjustTimeZoneAndDST(FirstSeenDateTime);
    }

    // LastSeenTime = time when tag with this EPC value was most recently detected by the radio.
    // Remember, radio keeps a table of EPCs and seen times (plus counts also).
    if (newTag.IsLastSeenTimePresent)
    {
        char timeStrBuf[32];
        newTag.LastSeenTime.Formatter(timeStrBuf, sizeof timeStrBuf);      // Formatter is an OctaneSDK function.
        QString OctaneSDK_Format_DateTime(timeStrBuf);
        OctaneSDK_Format_DateTime.chop(4); //Remove extra text at the end of date string.
        LastSeenDateTime = QDateTime::fromString(OctaneSDK_Format_DateTime, "yyyy-MM-ddThh:mm:ss.zzz");

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
        //LastSeenDateTime.setDate(newDate);
        //LastSeenDateTime.setTime(newTime);

        // If clock adjustment is enabled, then adjust for time zone.
        LastSeenDateTime = SystemSettings->AdjustTimeZoneAndDST(LastSeenDateTime);
    }
}

//PUBLIC FUNCTION
QString TagRecord::TagDataToQString()
{
    QString Result;

    Result.append(QString("%1,").arg(SeenCount));
    Result.append(QString("%1,").arg(AntennaPortNumber));
    Result.append(QString("%1,").arg(ChannelInMhz));
    Result.append(QString("%1,").arg(PhaseAngleInRadians));
    Result.append(QString("%1,").arg(RssiInDbm));
    Result.append(QString("%1,").arg(SerializedTid));
    Result.append(QString("%1,").arg(EPC));
    //Result.append(QString("%1,").arg(FirstSeenDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
    Result.append(QString("%1").arg(LastSeenDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));

    return Result;
}

//PUBLIC FUNCTION
void TagRecord::SetTagDataFromQString(QString TagString)
{
    QStringList TagStringParts(TagString.split(','));

    if (!TagStringParts.isEmpty())
    {
        SeenCount = QString("%1").arg(TagStringParts.takeFirst()).toInt();
        AntennaPortNumber = QString("%1").arg(TagStringParts.takeFirst()).toInt();
        ChannelInMhz = QString("%1").arg(TagStringParts.takeFirst()).toDouble();
        PhaseAngleInRadians = QString("%1").arg(TagStringParts.takeFirst()).toDouble();
        RssiInDbm = QString("%1").arg(TagStringParts.takeFirst()).toDouble();
        SerializedTid = QString("%1").arg(TagStringParts.takeFirst());
        EPC = QString("%1").arg(TagStringParts.takeFirst());
        //FirstSeenDateTime = QDateTime::fromString(TagStringParts.takeFirst(), "dd.MM.yyyy hh:mm:ss.zzz");
        LastSeenDateTime = QDateTime::fromString(TagStringParts.takeFirst(), "dd.MM.yyyy hh:mm:ss.zzz");
    }
}


//PUBLIC FUNCTION
QString TagRecord::SeenCountToQString()
{
    // Convert integer to QString.
    return QString("%1").arg(SeenCount);
}

//PUBLIC FUNCTION
QString TagRecord::AntennaPortNumberToQString()
{
    // Convert integer to QString.
    return QString("%1").arg(AntennaPortNumber);
}


//PUBLIC FUNCTION
QString TagRecord::ChannelInMhzToQString()
{
    // Convert double to QString.
    return QString("%1").arg(ChannelInMhz);
}

//PUBLIC FUNCTION
QString TagRecord::PhaseAngleInRadiansToQString()
{
    // Convert double to QString.
    return QString("%1").arg(PhaseAngleInRadians);
}

//PUBLIC FUNCTION
QString TagRecord::RssiInDbmToQString()
{
    // Convert double to QString.
    return QString("%1").arg(RssiInDbm);
}



//PUBLIC FUNCTION
QString TagRecord::FirstSeenDateTimeToQString()
{
    // Convert QDateTime to our custom format as per spec.
    return FirstSeenDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz");
}

//PUBLIC FUNCTION
QString TagRecord::LastSeenDateTimeToQString()
{
    // Convert QDateTime to our custom format as per spec.
    return LastSeenDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz");
}



//PUBLIC FUNCTION
QString TagRecord::TagReportWithEPCToQString()
{
    // Prepare a coma separated tag record. As per spec.

    //QString newTagReport;

    EPCRecordNumber = DataRecordCounter++;
    //newTagReport.append(QString("%1").arg(EPCRecordNumber));
    //newTagReport.append(",");
    //newTagReport.append(EPC);
    //newTagReport.append(",");
    //newTagReport.append(LastSeenDateTimeToQString());
    //newTagReport.append(',');
    //newTagReport.append(AntennaPortNumberToQString());
    //newTagReport.append(',');
    //newTagReport.append(RssiInDbmToQString());
    //newTagReport.append(RecordEndMark);

    //return newTagReport;

    return QString("%1,%2,%3,%4,%5%6").arg(EPCRecordNumber).arg(EPC).arg(LastSeenDateTimeToQString()).arg(AntennaPortNumberToQString()).arg(RssiInDbmToQString()).arg(RecordEndMark);
}

//PUBLIC FUNCTION
QByteArray TagRecord::TagReportWithEPCToQByteArray()
{
    // Prepare a coma separated tag record. As per spec.
    // And then export it as a byte array.

    //QByteArray newTagReport;
    //newTagReport.append(TagReportWithEPCToQString());
    //return newTagReport;

    return TagReportWithEPCToQString().toLocal8Bit();
}


//PUBLIC FUNCTION
QString TagRecord::TagReportWithBIBToQString()
{
    // Prepare a coma separated filtered tag record. As per spec.

    //QString newTagReport;
    QString Bib = ParseEPC();   // Convert EPC into BIB.

    if (!Bib.isEmpty())
    {
        BIBRecordNumber = FilteredRecordCounter++;

        //newTagReport.append(QString("%1").arg(BIBRecordNumber));
        //newTagReport.append(",");
        //newTagReport.append(Bib);
        //newTagReport.append(",");
        //newTagReport.append(LastSeenDateTimeToQString());
        //newTagReport.append(',');
        //newTagReport.append(SystemSettings->DataOneDeviceSettings.TimePointDesc);
        //newTagReport.append(RecordEndMark);

        //return newTagReport;

        return QString("%1,%2,%3,%4%5").arg(BIBRecordNumber).arg(Bib).arg(LastSeenDateTimeToQString()).arg(SystemSettings->DataOneDeviceSettings.TimePointDesc).arg(RecordEndMark);
    }
    else
    {
        return QString("");
    }


}

//PUBLIC FUNCTION
QByteArray TagRecord::TagReportWithBIBToQByteArray()
{
    // Prepare a coma separated tag record. As per spec.
    // And then export it as a byte array.

    //QByteArray newTagReport;
    //newTagReport.append(TagReportWithBIBToQString());
    //return newTagReport;

    return TagReportWithBIBToQString().toLocal8Bit();
}


//PUBLIC FUNCTION
bool TagRecord::Filter()
{
    // Filtering is required to temporarily block the tags which appear frequently.
    // A filter can be any duration in number of seconds.
    // Filter drift is a sort of fine adjustment for keeping delayes in control and getting as much precise time duration as possible.

    // This function only tells the caller that the current EPC is to be filtered or not.

    // Implementation of Filter.
    if (EPC.isEmpty())
        return true;

    // Normal mode filtering.
    if (SystemSettings->DataOneDeviceSettings.FilterLength > 0)
    {
        //int RemainingFilterTime = (unsigned int) SystemSettings->FilterDatabase.value(EPC).time().msecsTo(LastSeenDateTime.time());
        int RemainingFilterTime = (unsigned int) SystemSettings->FilterDatabase.value(EPC).msecsTo(LastSeenDateTime); //Changed in

        // Filter magic.
        if (SystemSettings->FilterDatabase.contains(EPC) && RemainingFilterTime < ((SystemSettings->DataOneDeviceSettings.FilterLength * 1000) + SystemSettings->DataOneDeviceSettings.FilterDrift))
            return true;

        // Store last seen date time to the filter database.
        // Remember, filter database can be disk based or RAM based.
        SystemSettings->FilterDatabase.insert(EPC, LastSeenDateTime);
        return false;
    }
    else
        return false; // If filter length = 0.
}


//PUBLIC FUNCTION
QString TagRecord::ParseEPC()
{
    // Process EPCs which match the length and format requirements.

    //qDebug() << "EPC: " << EPC;

    // if (EPC.length() == 24 && EPC.startsWith("FF")) //Changed in 1.5.2 on Bruno's request.
    if (EPC.length() >= 24 && EPC.startsWith("FF"))
    {
        QString Bib =  DecodeEPC(EPC); // EPC to BIB conversion.

        QStringList BibParts = Bib.split('/');
        bool ConvertFlag = false;
        BibParts.at(1).toInt(&ConvertFlag);

        //qDebug() << "Bib: " << Bib << " ConvertFlag: " << ConvertFlag;

        if (ConvertFlag)
            return Bib;
        else
            return QString("");
    }
    else
        return QString("");
}

//PUBLIC FUNCTION
QString TagRecord::DecodeEPC(QString EPCString)
{
    // EPC encoding is done with a simple Hex encoding based on a predefined key.
    // We'll do the reverse process here.

    EPCString.remove(0, 2); // Remove "FF" from start, that is not part of the key.
    QByteArray Data = QByteArray::fromHex(EPCString.toLocal8Bit()); // Convert asci Hex data to byte array.

    Data = XORData(Data, DecryptKey, 22); // XOR the EPC and key.

    QString DataString(Data);
    DataString.insert(5, "/");  // Required as per spec.
    DataString.simplified();    // Discard any spaces and /n /r from start and end.
    DataString.remove(QChar(' '), Qt::CaseInsensitive); // Remove spaces if between the characters.

    return DataString;
}

//PUBLIC FUNCTION
QByteArray TagRecord::XORData(QByteArray data, QByteArray key, int Length)
{
    // Method for performing byte bye byte xor of two byte arrays.

    if(key.isEmpty())
        return data;

    QByteArray result;
    // for(int i = 0 , j = 0; i < data.length(); ++i , ++j) //Changed in 1.5.2 on Bruno's request.
    for(int i = 0 , j = 0; i < Length/2; ++i , ++j) // Process only n number of bytes, specified by Length.
    {
        if(j == key.length())
            j = 0;// repeat the key if key.length() < data.length()

        result.append(data.at(i) ^ key.at(j)); // XOR is done here.
    }
    return result;
}

//PUBLIC FUNCTION
bool TagRecord::isTestChip()
{
    // Check for a predefined string pattern in BIB.
    // If it matches, this tag is a test chip.
    return ParseEPC().startsWith("dstst");
}

