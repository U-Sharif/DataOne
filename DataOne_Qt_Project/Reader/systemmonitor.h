#ifndef SYSTEMMONITOR_H
#define SYSTEMMONITOR_H

#include <QThread>
#include <QTimer>
#include <QDir>
#include <QFile>
#include <QList>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QSslConfiguration>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QProcess>

#include "../Settings/settings.h"
#include "../TcpClient/tcpserverconnection.h"


// This class handles monitoring of the RFID reader. At present it mostly monitors the OS state.
// SystemMonitor object will run in a separate thread, to offload prcessing from reader thread.
// This class inherits QThread of Qt framework, which provides functionality for making multi-threaded applications.

class SystemMonitor : public QThread
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit SystemMonitor(DataOneSettings *SysSettings, QObject *parent);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

private:
    //Ping process
    QProcess PingProcess;

    // CPU usage.
    double CpuUsage;
    double TotalJiffiesLast; // Jiffies = A unit of time.
    double WorkJiffiesLast;
    double CpuUsageLast;
    int HighCpuUsageCount;

    // USB device monitoring.
    bool USBDeviceError;
    bool USBAlertIssued;
    bool USBErrorIssued;
    bool isFirstRead;
    bool isFirstUSBCheck;
    bool isSda1Mounted;
    bool isSda1Writable;

    // OS files to read the stats from.
    QFile CPUStatFile;
    QFile MemoryInfoFile;
    QFile MountPointsFile;

    // Internet Status
    bool InternetAvailablePreviousStatus;

    // Network access manager for sending and receiving HTTP requests and responses.
    QNetworkAccessManager *NAM_InternetConnection;
    QNetworkReply *WebReply;
    bool LastNetworkReplyFinished; // Flag.

    // Function to check if SDA1 file system is mounted and writeable.
    void CheckSda1();


signals:


    void Log(QString, QString);                 // Send log entry to main thread.
    void Broadcast(QString);                    // Send message to all connected TCP clients.

    void USBMemoryUnplugged(int ActionAlert);   // If USB memory device is unplugged, send an action alert to warn the users.
    void USBMemoryPlugged();                    // If USB memory device is plugged back in, inform other threads.

    void NetworkNotAvailable();                 // Send signal to GPIO handler that network is not available.
    void NetworkAvailable();                    // Send signal to GPIO handler that network is available.


protected:

    // Virtual protected function of QThread for launching the thread.
    // This thread will be launched from mainthread.cpp
    void run();


public slots:

private slots:
    void CheckCurrentCPUUsage();        // Check CPU usage during the last timer period.
    void CheckCurrentMemoryUsage();     // Check memory usage during the last timer period.
    void CheckUsbPresent();             // Check if USB memory device is present.
    void CheckUsbFreeSpace();           // Check if USB memory device has free space.

    void CheckInternetConnectivityByPING();   // Send a PING request to check internet connection present.
    void OnPingEnded();

    void CheckInternetConnectivityByHTTP();   // Send an HTTP request to check internet connection present.
    void InternetCheckReplyFinished(QNetworkReply* WebReply);   // Slot to capture the HTTP reply.
    void onError(QNetworkReply::NetworkError Code);

    void UpdateDateTimeFromNTP();


};

#endif // SYSTEMMONITOR_H
