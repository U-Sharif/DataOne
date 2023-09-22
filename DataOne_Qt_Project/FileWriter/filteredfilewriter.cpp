#include "filteredfilewriter.h"

// CONSTRUCTOR
FilteredFileWriter::FilteredFileWriter(QObject *parent) :
    QThread(parent)
{
    // Set the flag now to trigger creation of new file when first tag is received by EnqueueTag() function.
    ClearBuffer = true;
}


//PROTECTED
void FilteredFileWriter::run()
{
    // Start eventloop of new thread.
    exec();
}


//PUBLIC SLOT
void FilteredFileWriter::ClearBuffers()
{
    // Set the flag to trigger creation of new file when next tag is received by EnqueueTag() function.
    ClearBuffer = true;
}

//PUBLIC SLOT
void FilteredFileWriter::ClearAllLogs()
{
    // Delete all old filtered log files on USB memory device.
    // Do this only when USB memory device is actually present.
    if (SystemSettings->isUSBDevicePresent)
    {
        QDir FileWritePath;
        FileWritePath.setPath(SystemSettings->FilteredFolderPath);
        QStringList DataFiles = FileWritePath.entryList();

        for (int i = 0; i < DataFiles.size(); i++)
        {
            QFile::remove(SystemSettings->FilteredFolderPath + DataFiles.at(i));
        }

        emit Log("ACTION", QString("Removed filtered logs. \n\r"));
        emit Log("", "\n\r");
    }
    else
    {
        emit Log("ERROR", QString("Clearing filtered logs failed. \n\r"));
        emit Log("", "\n\r");
    }

    // Since current filtered log file is also deleted, therefore, set flag to create new file on receiving next tag.
    ClearBuffer = true;
}

//PUBLIC SLOT
void FilteredFileWriter::USBMemoryPlugged()
{
    //if (!FilteredRecordFile.isWritable())
    //    SetNewFilteredFileName();
}

//PUBLIC SLOT
void FilteredFileWriter::EnqueueTag(QByteArray newTag, quint64 RecordNum)
{
    // Previously, this function used a QQueue buffer to hold the records.
    // However, due to memory management issues, QQueue was removed.
    // Now this function sends the tag records directly to WriteFilteredRecordFile() for writing to USB file.

    // Create new filtered file.
    if (RecordNum == 1 && ClearBuffer)
    {
        SetNewFilteredFileName();
        ClearBuffer = false;
    }

    // Send record for writing to USB filtered log file.
    if (SystemSettings->isUSBDevicePresent && SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
        WriteFilteredRecordFile(newTag, RecordNum);
}

//PUBLIC SLOT
void FilteredFileWriter::Shutdown()
{
    emit Log("ACTION", QString("Shutting down Filtered File Writer thread.\n\r"));

    if (FilteredRecordFile.isOpen()) FilteredRecordFile.close();

    this->quit();
}



//PRIVATE SLOT
void FilteredFileWriter::SetNewFilteredFileName()
{
    // Create new data file only if USB device is present.
    if (SystemSettings->isUSBDevicePresent)
    {
        // Always try to create the Filtered log folder.
        // Current device may be a blank USB device.
        QDir FileWritePath;
        FileWritePath.mkpath(SystemSettings->FilteredFolderPath);

        // If open, close old file.
        if (FilteredRecordFile.isOpen())
            FilteredRecordFile.close();

        // Create new filename.
        QString FileName;
        FileName = SystemSettings->FilteredFolderPath;
        FileName.append(SystemSettings->GetCurrentDateTimeFileNameString());
        FileName.append(".txt");

        // Set filename and send message to console.
        FilteredRecordFile.setFileName(FileName);
        emit Log("ACTION", QString("Setting filtered log filename to : \n\r"));
        emit Log("ACTION", QString("%1\n\r").arg(FileName));
        emit Log("", "\n\r");

        // Clear the record numbers footprint file.
        SystemSettings->ResetFilteredFootprint();               //USB based footprint.
        //SystemSettings->FilteredLogFootprintMap.clear();      //RAM based footprint.

        // Try to open the file in WriteOnly mode.
        if (!FilteredRecordFile.open(QIODevice::WriteOnly))
        {
            emit Log("ERROR", QString("Can not create Data record file for writing.\n\r"));
            emit Log("", "\n\r");
        }

        // Update system settings so that other threads can know the new filename.
        SystemSettings->CurrentFilteredLogFileName = FileName;
    }
}

//PRIVATE SLOT
void FilteredFileWriter::WriteFilteredRecordFile(QByteArray newTag, quint64 RecordNum)
{
    // Always check if the file is still writable.
    if (!FilteredRecordFile.isWritable())
    {
        emit Log("ERROR", QString("Can not open Filtered record file for writing.\n\r"));
        emit Log("", "\n\r");
        return;
    }

    // After every 999 records, write the file position of the 1000th record into the footprint file.
    if (RecordNum == 0 || (RecordNum % 1000) == 999)
    {
        QByteArray TagDateTime = newTag.split(',').at(2);
        SystemSettings->LogFilteredFootprint(FilteredRecordFile.pos(), TagDateTime);                    //USB based footprint.
        //SystemSettings->FilteredLogFootprintMap.insert(RecordNum + 1 , FilteredRecordFile.pos());     //RAM based footprint.
    }

    // Write the tag record to write buffer.
    FilteredRecordFile.write(newTag);

    // Flush the QFile object, so that data is immediately written to USB.
    FilteredRecordFile.flush();

}

