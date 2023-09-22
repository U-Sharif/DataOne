#ifndef CONSOLEFILEWRITER_H
#define CONSOLEFILEWRITER_H

#include <QThread>
#include <QDir>
#include <QFile>
#include <QDateTime>

#include "../Settings/settings.h"

// This class will write console log to disk.
// ConsoleFileWriter object will run in a separate thread, to offload disk i/o from main application thread.
// This class inherits QThread of Qt framework, which provides functionality for making multi-threaded applications.

class ConsoleFileWriter : public QThread
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit ConsoleFileWriter(DataOneSettings *SysSettings, QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application.
    DataOneSettings *SystemSettings;

protected:
    // Virtual protected function of QThread for launching the thread.
    // This thread will be launched from mainthread.cpp
    void run();

private:
    // File object for writing the log to.
    QFile ConsoleLogFile;

    // Function for opening the log file.
    // There will be only one log file, which resides on USB memory device.
    void OpenConsoleLogFile();

signals:
    // No signals are raised from this class.

public slots:
    // Function for writing log to the ConsoleLogFile object.
    void RecordLog(QByteArray);

    // Slot for launching OpenConsoleLogFile() function when USB memory is plugged into the reader after starting of this application.
    void USBMemoryPlugged();

    // Slot for initiating shutdown sequence.
    void Shutdown();

};

#endif // CONSOLEFILEWRITER_H
