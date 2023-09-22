#include "datafilewriter.h"

// CONSTRUCTOR
DataFileWriter::DataFileWriter(QObject *parent) :
    QThread(parent)
{
    // Set the flag now to trigger creation of new file when first tag is received by EnqueueTag() function.
    ClearBuffer = true;
}


//PROTECTED
void DataFileWriter::run()
{
    // Start eventloop of new thread.
    exec();
}


//PUBLIC SLOT
void DataFileWriter::ClearBuffers()
{
    // Set the flag to trigger creation of new file when next tag is received by EnqueueTag() function.
    ClearBuffer = true;
}

//PUBLIC SLOT
void DataFileWriter::ClearAllLogs()
{
    // Delete all old data log files on USB memory device.
    // Do this only when USB memory device is actually present.
    if (SystemSettings->isUSBDevicePresent)
    {
        QDir FileWritePath;
        FileWritePath.setPath(SystemSettings->DataFolderPath);
        QStringList DataFiles = FileWritePath.entryList();

        for (int i = 0; i < DataFiles.size(); i++)
        {
            QFile::remove(SystemSettings->DataFolderPath + DataFiles.at(i));
        }

        emit Log("ACTION", QString("Removed data logs. \n\r"));
        emit Log("", "\n\r");
    }
    else
    {
        emit Log("ERROR", QString("Clearing data logs failed. \n\r"));
        emit Log("", "\n\r");
    }

    // Since current data log file is also deleted, therefore, set flag to create new file on receiving next tag.
    ClearBuffer = true;
}

//PUBLIC SLOT
void DataFileWriter::USBMemoryPlugged()
{
    //if (!DataRecordFile.isWritable())
    //    SetNewDataFileName();
}

//PUBLIC SLOT
void DataFileWriter::EnqueueTag(QByteArray newTag, quint64 RecordNum)
{
    // Previously, this function used a QQueue buffer to hold the records.
    // However, due to memory management issues, QQueue was removed.
    // Now this function sends the tag records directly to WriteDataRecordFile() for writing to USB file.

    // Create new data file.
    if (RecordNum == 1 && ClearBuffer)
    {
        SetNewDataFileName();
        ClearBuffer = false;
    }

    // Send record for writing to USB data log file.
    if (SystemSettings->isUSBDevicePresent && SystemSettings->DataOneApplicationSettings.EnableWriteDataLog)
        WriteDataRecordFile(newTag, RecordNum);
}

//PUBLIC SLOT
void DataFileWriter::Shutdown()
{
    emit Log("ACTION", QString("Shutting down Data File Writer thread.\n\r"));

    if (DataRecordFile.isOpen()) DataRecordFile.close();

    this->quit();
}



//PRIVATE SLOT
void DataFileWriter::SetNewDataFileName()
{
    // Create new data file only if USB device is present.
    if (SystemSettings->isUSBDevicePresent)
    {
        // Always try to create the Data log folder.
        // Current device may be a blank USB device.
        QDir FileWritePath;
        FileWritePath.mkpath(SystemSettings->DataFolderPath);

        // If open, close old file.
        if (DataRecordFile.isOpen())
            DataRecordFile.close();

        // Create new filename.
        QString FileName;
        FileName = SystemSettings->DataFolderPath;
        FileName.append(SystemSettings->GetCurrentDateTimeFileNameString());
        FileName.append(".txt");

        // Set filename and send message to console.
        DataRecordFile.setFileName(FileName);
        emit Log("ACTION", QString("Setting data log filename to : \n\r"));
        emit Log("ACTION", QString("%1\n\r").arg(FileName));
        emit Log("", "\n\r");

        // Clear the record numbers footprint file.
        SystemSettings->ResetDataFootprint();               //USB based footprint.
        //SystemSettings->DataLogFootprintMap.clear();      //RAM based footprint.

        // Try to open the file in WriteOnly mode.
        if (!DataRecordFile.open(QIODevice::WriteOnly))
        {
            emit Log("ERROR", QString("Can not create Data record file for writing.\n\r"));
            emit Log("", "\n\r");
        }

        // Update system settings so that other threads can know the new filename.
        SystemSettings->CurrentDataLogFileName = FileName;
    }
}

//PRIVATE SLOT
void DataFileWriter::WriteDataRecordFile(QByteArray newTag, quint64 RecordNum)
{
    // Always check if the file is still writable.
    if (!DataRecordFile.isWritable())
    {
        emit Log("ERROR", QString("Can not open Data record file for writing.\n\r"));
        emit Log("", "\n\r");
        return;
    }

    // After every 999 records, write the file position of the 1000th record into the footprint file.
    if (RecordNum == 0 || (RecordNum % 1000) == 999)
    {
        QByteArray TagDateTime = newTag.split(',').at(2);
        SystemSettings->LogDataFootprint(DataRecordFile.pos(), TagDateTime);                    //USB based footprint.
        //SystemSettings->DataLogFootprintMap.insert(RecordNum + 1, DataRecordFile.pos());      //RAM based footprint.
    }

    // Write the tag record to write buffer.
    DataRecordFile.write(newTag);

    // Flush the QFile object, so that data is immediately written to USB.
    DataRecordFile.flush();
}

