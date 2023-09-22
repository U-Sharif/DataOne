#ifndef TCPSERVERCONNECTION_H
#define TCPSERVERCONNECTION_H

#include <cmath>

#include <QThread>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QHostInfo>
#include <QDateTime>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QFileInfoList>
#include <QTimer>
#include <QList>
#include <QMap>

#include "../Settings/settings.h"
#include "../Enums/enums.h"
#include "../Tag/tagrecord.h"

// This class provides functionality for handling a tcp connection to timing servers.
// TcpServerConnection object will run in a separate thread, to offload prcessing from reader thread.
// This class inherits QThread of Qt framework, which provides functionality for making multi-threaded applications.

class TcpServerConnection : public QThread
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit TcpServerConnection(QString Name, quint16 Port, quint64 RecordCounter, QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

    // A static flag to indicate if timing server is connected.
    // Since there will be 2 persistant timing server threads running in the application,
    // and we only need one connection at a time, the static variable will be used  to
    // a successful connection to the other thread.
    static bool isTimingServerConnected;

private:
    // Tcp socket for providing server connection.
    QTcpSocket *TcpDataSocket;

    // Tcp socket connected flag.
    bool isTcpDataSocketConnected;

    // Keeping track of server connection attempts
    int ServerConnectionRetriesCount;

    // Timer to check server connection state at regular intervals.
    QTimer ServerStatusCheckTimer;

    // Timer to detect inactivity of server connection. Possible disconnection.
    QTimer ServerInactivityTimer;

    // Tcp socket properties.
    QString ServerName;
    quint16 ServerPort;
    QString ServerIP;
    quint16 LocalTcpPort;

    // Variable to store filtered log file readback pointer.
    qint64 FilePosition;

    // Record index requested by server.
    quint64 StartRecordIndex;

    // Record date time requested by client.
    QDateTime StartRecordDateTime;

    // Record index of current live tag.
    quint64 CurrentRecordIndex;

    // Flag to indicate if the SX command is being handled.
    bool SXValid;

    // Flag to indicate if the Sdt command is being handled.
    bool SdtValid;

    // Flag to indicate if get_log_file command is being executed.
    bool SendCustomFile;

    // Timer to read and send records from log file in chunks.
    // Continuous readback will block the thread, and possibly whole application.
    QTimer FileChunkReadTimer;

    // Log file handle.
    QFile RecordFile;

    // Byte array to hold client commands.
    QByteArray CommandData_buffer;

    // Current reader antennas state.
    QString AntennaState;

    // Flag to indicate disconnection.
    bool isDisconnecting;

    // Byte array to hold last index requested by client command SX.
    quint64 LastCommandIndex;

    // Byte array to hold last date time requested by client command Sdt.
    QDateTime LastCommandDateTime;

    // Timer to clear he last index requested by client command SX.
    QTimer LastCommandIndexResetTimer;

    // Timer to clear he last date time requested by client command Sdt.
    QTimer LastCommandDateTimeResetTimer;


protected:
    // Virtual protected function of QThread for launching the thread.
    // This thread will be launched from tcpfilteredserver.cpp
    void run();

signals:
    void Log(QString, QString);         // Signal to send log to TcpFilteredServer.
    void ServerCommand(QByteArray);     // Signal to send timing server command to TcpFilteredServer.
    void TimingServerConnected();       // Signal to indicate that timing server connection has been established.
    void TimingServerDisconnected();    // Signal to indicate that timing server connection has been disconnected.

public slots:
    void SendTagData(QByteArray, quint64);  // Slot to receive new tag record from TcpFilteredServer and send to timing server.
    void SendStatusPing(QByteArray);        // Slot to receive status message from TcpFilteredServer and send to timing server.
    void SendBroadcastMessage(QByteArray);  // Slot to receive broadcast message from TcpFilteredServer and send to timing server.
    void StoreAntennaState(QString);        // Slot to receive and store current antenna connection state.
    void ClearBuffers();                    // Slot to handle clear_buffers command.


private slots:
    void SendTcpData(QByteArray);           // Slot to actually send data to timing server.
    void onConnected();                     // Slot to perform actions at socket connection.
    void onDisconnected();                  // Slot to perform actions at socket disconnection.
    void onDataReceived();                  // Slot to handle commands received from timing server.
    void onSocketError(QAbstractSocket::SocketError);                   // Slot to handle TcpSocket errors.
    void ReadChunkFromFile();               // Slot to read certain number of records from log file and send to timing server.

    void DisconnectSocket();                // Slot to disconnect the siming server connection.
    void CheckPortStatus();                 // Slot to check the port connection status at regular intervals.

    void ResetLastCommandIndex();           // Slot to to clear he last index requested by timing server command SX.
    void ResetLastCommandDateTime();        // Slot to to clear he last date time requested by client command Sdt.

};

#endif // TCPSERVERCONNECTION_H
