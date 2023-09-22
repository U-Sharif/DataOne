#ifndef TCPTELNETCLIENT_H
#define TCPTELNETCLIENT_H

#include <cmath>

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
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

// This class provides functionality for handling a tcp connection to telnet clients.
// This class is polymorphous, and can be used for data as well as filtered clint connections.
// TcpTelnetClient object will run in a separate thread, to offload prcessing from reader thread.
// This class inherits QThread of Qt framework, which provides functionality for making multi-threaded applications.


class TcpTelnetClient : public QThread
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit TcpTelnetClient(int SocketDescriptor, TelnetClientType ClientType, quint64 RecordCounter, QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

private:
    // Tcp socket for providing client connection.
    QTcpSocket TcpDataSocket;

    // Tcp socket connected flag.
    bool isTcpDataSocketConnected;

    // Flag to indicate disconnection.
    bool isDisconnecting;

    // This variable makes this class polymorphous.
    // TelnetClientType indicates whether this thread is handling data or filtered records.
    // See structures.h
    TelnetClientType Client;

    // Tcp socket properties.
    QString ClientIP;
    QString ClientName;
    quint16 ClientPort;
    quint16 LocalTcpPort;

    // Variable to store data/filtered log file readback pointer.
    qint64 FilePosition;

    // Record index requested by client.
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
    QByteArray ClientData_buffer;

    // Current reader antennas state.
    QString AntennaState;

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
    // This thread will be launched from tcpfilteredserver.cpp and tcp dataserver.cpp
    void run();

signals:
    void Log(QString, QString);         // Signal to send log to Tcp Server.
    void ClientCommand(QByteArray);     // Signal to send client command to Tcp Server.

public slots:
    void SendTagData(QByteArray, quint64);  // Slot to receive new tag record from Tcp Server and send to client.
    void SendStatusPing(QByteArray);        // Slot to receive status message from Tcp Server and send to client.
    void SendBroadcastMessage(QByteArray);  // Slot to receive broadcast message from Tcp Server and send to client.
    void StoreAntennaState(QString);        // Slot to receive and store current antenna connection state.
    void ClearBuffers();                    // Slot to handle clear_buffers command.


private slots:
    void SendTcpData(QByteArray);           // Slot to actually send data to client.
    void onConnected();                     // Slot to perform actions at socket connection.
    void onDisconnected();                  // Slot to perform actions at socket disconnection.
    void onDataReceived();                  // Slot to handle commands received from client.
    void ReadChunkFromFile();               // Slot to read certain number of records from log file and send to client.

    void CheckPortStatus();                 // Slot to check the port connection status at regular intervals.

    void ResetLastCommandIndex();           // Slot to to clear he last index requested by client command SX.
    void ResetLastCommandDateTime();        // Slot to to clear he last date time requested by client command Sdt.

};

#endif // TCPTELNETCLIENT_H
