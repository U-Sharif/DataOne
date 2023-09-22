#ifndef DATAFILEWRITER_H
#define DATAFILEWRITER_H

#include <QThread>
#include <QTimer>
#include <QDir>
#include <QFile>
#include <QQueue>
#include <QBuffer>
#include <QDateTime>

#include "../Settings/settings.h"

// This class will write all Tag records to disk.
// DataFileWriter object will run in a separate thread, to offload disk i/o from main application thread.
// This class inherits QThread of Qt framework, which provides functionality for making multi-threaded applications.

class DataFileWriter : public QThread
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit DataFileWriter(QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application.
    DataOneSettings *SystemSettings;

protected:
    // Virtual protected function of QThread for launching the thread.
    // This thread will be launched from mainthread.cpp
    void run();

private:
    // Flag for triggering of buffer clearing.
    // Buffer is the tag record file.
    bool ClearBuffer;

    // File object for writing the Tag records to.
    QFile DataRecordFile;

    // Function for writing new tag record to current data log file.
    void WriteDataRecordFile(QByteArray newTag, quint64 RecordNum);


signals:
    // Signal to main thread for reporting console log entries.
    void Log(QString, QString);

public slots:
    // Slot for receiving clear buffer signal from reader thread.
    void ClearBuffers();

    // Slot for receiving clear all logs signal from reader thread.
    void ClearAllLogs();

    // Slot for launching SetNewDataFileName() function when USB memory is plugged into the reader after starting of this application.
    void USBMemoryPlugged();

    // Receive and process new Tag from reader thread.
    void EnqueueTag(QByteArray newTag, quint64 RecordNum);

    // Slot for initiating shutdown sequence.
    void Shutdown();


private slots:
    // Function for opening a new data log file on USB memory device.
    void SetNewDataFileName();

};

#endif // DATAFILEWRITER_H
