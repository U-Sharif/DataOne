#ifndef MAINTHREAD_H
#define MAINTHREAD_H


#include <QObject>
#include <QBuffer>
#include <QTimer>
#include <QTime>

#include "Settings/settings.h"
#include "Reader/reader.h"
#include "Reader/gpiohandler.h"
#include "Reader/systemmonitor.h"
#include "FileWriter/consolefilewriter.h"
#include "FileWriter/datafilewriter.h"
#include "FileWriter/filteredfilewriter.h"
#include "TcpServer/tcpconsoleserver.h"
#include "TcpServer/tcpdataserver.h"
#include "TcpServer/tcpfilteredserver.h"
#include "WebUploader/webuploader.h"

// This class is the main application object.
// This class initializes all other classes.
// After initialization this class controls logging, broadcasting and application running time.

class MainThread : public QObject
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Constructor.
    explicit MainThread(QObject *parent = 0);

private:
    DataOneSettings *SystemSettings;            // Application settings and configuration.

    Reader *RFIDReader;                         // The main RFID reader object.
    GPIOHandler *GpioHandler;                   // GPI and GPO handler thread.
    SystemMonitor *SystemManager;               // System monitor thread.

    TcpConsoleServer *TcpServer_Console;        // Tcp server for console connections.
    TcpDataServer *TcpServer_Data;              // Tcp server for data connections.
    TcpFilteredServer *TcpServer_Filtered;      // Tcp server for filtered connections.

    ConsoleFileWriter *FileWriter_Console;      // File writer thread for console log.
    DataFileWriter *FileWriter_Data;            // File writer thread for data log.
    FilteredFileWriter *FileWriter_Filtered;    // File writer thread for filtered log.

    WebUploader *LogUploader;

    QTimer ApplicationRunningTimer;             // Timer to increment application running time.
    quint64 ApplicationRunningTime;             // Applicatino running time value.

    QBuffer *LogBuffer;                         // Console log buffer.

    void ShowAllSettings();                     // Functino to show all application settings on startup.

    int MessageCounter;                         // Used for sequencing of log upload to web.

signals:
    void WriteLogToDisk(QByteArray);                    // Signal to console file writer with new log entry.
    void SendBroadcastMessage(QByteArray);              // Signal to all Tcp servers for sending broadcast entry.
    void SendLogToRemoteConsoles(QByteArray);           // Send signal to Tcp Console Server.

public slots:
    void SendApplicationRunningTime();                  // Slot to write application running time on console.

private slots:
    void WriteApplicationLog(QString MessageType, QString LogStatement);     // Slot to write new application log on console.
    void SendBroadcast(QString LogStatement);           // Slot to receive a new broadcast entry from originating thread.

    void UpdateApplicationRunningTime();                // Slot to update application running running time on timer.

};

#endif // MAINTHREAD_H
