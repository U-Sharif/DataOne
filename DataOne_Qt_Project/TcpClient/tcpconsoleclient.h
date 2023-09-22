#ifndef TCPCONSOLECLIENT_H
#define TCPCONSOLECLIENT_H

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QFile>


// This class provides functionality for handling a client tcp connection for console output.
// TcpConsoleClient object will run in a separate thread, to offload prcessing from reader thread.
// This class inherits QThread of Qt framework, which provides functionality for making multi-threaded applications.

class TcpConsoleClient : public QThread
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit TcpConsoleClient(int SocketDescriptor, QObject *parent = 0);

private:
    // Tcp socket for providing client connection.
    QTcpSocket TcpConsoleSocket;

    // Tcp socket connected flag.
    bool isTcpDataSocketConnected;

    // Tcp socket properties.
    QString ClientIP;
    QString ClientName;
    quint16 ClientPort;
    quint16 LocalTcpPort;

    // Byte array to hold client commands.
    QByteArray ClientData_buffer;

    // Flag to indicate disconnection.
    bool isDisconnecting;

    // Current reader antennas state.
    QString AntennaState;

    // Function to perform actions at socket connection.
    void onConnected();

protected:
    // Virtual protected function of QThread for launching the thread.
    // This thread will be launched from tcpconsoleserver.cpp
    void run();

signals:
    void Log(QString, QString);         // Signal to send log to TcpConsoleServer.
    void ConsoleCommand(QByteArray);    // Signal to send cconsole command to Tcp Server.
    void Command_GetRunningTime();      // Signal to inform TcpConsoleServer that get_running_time command has been received.

public slots:
    void SendLog(QByteArray);           // Slot to receive log entry from TcpConsoleServer and send to client.
    void StoreAntennaState(QString);    // Slot to receive & store the current antennas state.


private slots:
    void onDisconnected();              // Slot to perform actions at socket disconnection.
    void onDataReceived();              // Slot to handle commands received from clinet.

    void CheckPortStatus();             // Slot to check the port connection status at regular intervals.

};

#endif // TCPCONSOLECLIENT_H
