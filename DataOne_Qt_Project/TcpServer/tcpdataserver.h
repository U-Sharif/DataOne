#ifndef TCPDATASERVER_H
#define TCPDATASERVER_H

#include <QTcpServer>
#include <QHostAddress>
#include <QTimer>

#include "../Settings/settings.h"
#include "../Enums/enums.h"
#include "../TcpClient/tcptelnetclient.h"


// This class provides a TCP server for connecting clients to this application over network.
// TcpDataServer runs in the main thread.
// This server handles raw tag records.
// This class inherits QTcpServer of Qt framework, which provides functionality for making TcpServers.

class TcpDataServer : public QTcpServer
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Constructor.
    explicit TcpDataServer(QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

    // Funtion to launch the Tcp server.
    void StartServer();

private:
    // Tcp Port for listening.
    quint16 TcpServerPort;

    // Keep clients count.
    int MaximumConnectedClients;
    int ConnectedClients;

    // Flag for keeping record of reading status of reader.
    bool isReading;

    // Pointer for creating new console client threads.
    TcpTelnetClient *newDataClient;

    // Timer for sending status messages to clients.
    QTimer ServerPingTimer;

    // Keep record of tag record indexes.
    int CurrentRecordIndex;

    // Keep record of reader temperature.
    int ReaderTemperature;

    // Keep record of external battery voltage.
    double ExternalBatteryVoltage;

    // Keep record of current reader antennas state.
    QString AntennaState;

    // Timer to check server running status regularly.
    QTimer ServerStatusCheckTimer;


protected:
    // QTcpServer override. Handles incoming tcp connections.
    void incomingConnection(int socketDescriptor);

signals:
    void Log(QString, QString);                              // Send log to main thread.
    void NewTagAvailable(QByteArray, quint64);      // Signal to send new tag record to all client threads.
    void ClientCommand(QByteArray);                 // Signal to send clinet commands to reader thread.
    void SendStatusPing(QByteArray);                // Signal to send status message to all client threads.
    void SendBroadcastMessage(QByteArray);          // Signal to send broadcast message to all client threads.
    void ClientConnected();                         // Signal to send client connect indication to GpioHandler.
    void ClientDisconnected();                      // Signal to send client disconnect indication to GpioHandler.
    void ClearBuffer();                             // Signal to inform all client threads about clear_buffer command.
    void UpdateAntennaState(QString);               // Signal for updating current antenna state to client threads.

    void DataOneShutdown();                         // Signal for other threads, clean exit.

public slots:
    void SendTagData(QByteArray, quint64);          // Slot to receive new tag record from reader.
    void UpdateTemperature(int);                    // Slot to receive current reader temperature from reader.
    void UpdateBatteryVoltage(double);              // Slot to receive current battery voltage from GpioHandler.
    void SendBroadcast(QByteArray);                 // Slot to receive broadcast messages from mian thread.
    void ReadingStarted(bool);                      // Slot to receive reading status from reader.
    void ClearBuffers();                            // Slot to receive clear_buffer command.
    void StoreAntennaState(QString);                // Slot to receive current antennas state from reader.

    // Slot for initiating shutdown sequence.
    void Shutdown();


private slots:
    void DecrementConnectedClientsCount();          // Slot to decrease the connected clinets count on a client thread exit.
    void LogFromChildThread(QString, QString);      // Slot to receive log messages from client threads.
    void CommandFromChildThread(QByteArray);        // Slot to receive commands from client threads.
    void SendStatus();                              // Slot to generate status messages.
    void CheckServerStatus();                       // Slot to check server status regularly.

};

#endif // TCPDATASERVER_H
