#include "tcpdataserver.h"

//CONSTRUCTOR
TcpDataServer::TcpDataServer(QObject *parent) :
    QTcpServer(parent)
{
    // Defaults.
    setMaxPendingConnections(2);    // This is a QTcpServer public function.
    ConnectedClients = 0;
    CurrentRecordIndex = 0;
    ReaderTemperature = 0;
    ExternalBatteryVoltage = 13.0; //Start from an average voltage value, otherwise first message will have 0.
    isReading = false;
}


//PUBLIC FUNCTION
void TcpDataServer::StartServer()
{
    // Set clinet connection limit.
    MaximumConnectedClients = SystemSettings->DataOneNetworkSettings.MaxConnectedClients;

    // Set port.
    TcpServerPort = SystemSettings->DataOneNetworkSettings.DataPort;

    // Listen for connections on the given port and all IP addresses.
    if (listen(QHostAddress(QHostAddress::Any), TcpServerPort))
    {
        emit Log("STATUS", QString("Data server Ready.\n\r"));
        emit Log("STATUS", QString("Waiting for connections on port %2 \n\r").arg((int) TcpServerPort));
        emit Log("", "\n\r");

        // Setup status message timer.
        ServerPingTimer.setInterval(SystemSettings->DataOneNetworkSettings.PingInterval * 1000);
        connect(&ServerPingTimer, SIGNAL(timeout()), this, SLOT(SendStatus()));
        ServerPingTimer.start();
    }
    else
    {
        emit Log("ERROR", QString("Could not initialize Data server.\n\r"));
        emit Log("", "\n\r");
    }

    // Check server status regularly.
    ServerStatusCheckTimer.setInterval(10000);
    connect(&ServerStatusCheckTimer, SIGNAL(timeout()), this, SLOT(CheckServerStatus()));
    ServerStatusCheckTimer.start();
}


//PROTECTED OVERRIDE
void TcpDataServer::incomingConnection(int socketDescriptor)
{
    // This function is called when ever a new clinet is trying to connect to this server.
    if (ConnectedClients < MaximumConnectedClients)
    {
        // Create a new data client thread.
        newDataClient = new TcpTelnetClient(socketDescriptor, TelnetDataClient, CurrentRecordIndex, this);

        // Pass on the pointer of system settings to client thread.
        newDataClient->SystemSettings = SystemSettings;

        // Connect the new client's signals.
        connect(newDataClient, SIGNAL(ClientCommand(QByteArray)), this, SLOT(CommandFromChildThread(QByteArray)));
        connect(newDataClient, SIGNAL(Log(QString, QString)), this, SLOT(LogFromChildThread(QString, QString)));
        connect(newDataClient, SIGNAL(finished()), newDataClient, SLOT(deleteLater()));
        connect(newDataClient, SIGNAL(finished()), this, SLOT(DecrementConnectedClientsCount()));

        // Connect the new client's slots.
        connect(this, SIGNAL(NewTagAvailable(QByteArray,quint64)), newDataClient, SLOT(SendTagData(QByteArray,quint64)));
        connect(this, SIGNAL(SendStatusPing(QByteArray)), newDataClient, SLOT(SendStatusPing(QByteArray)));
        connect(this, SIGNAL(SendBroadcastMessage(QByteArray)), newDataClient, SLOT(SendBroadcastMessage(QByteArray)));
        connect(this, SIGNAL(ClearBuffer()), newDataClient, SLOT(ClearBuffers()));
        connect(this, SIGNAL(UpdateAntennaState(QString)), newDataClient, SLOT(StoreAntennaState(QString)));
        connect(this, SIGNAL(DataOneShutdown()), newDataClient, SLOT(quit()));

        // Start the new client thread.
        newDataClient->start();

        // Increment connected clients count.
        ConnectedClients++;

        // Raise signal to inform GpioHandler that a new client has been connected.
        emit ClientConnected();
    }
    else
    {
        // Reject the client with a message.
        QTcpSocket rejectedClient(this);
        rejectedClient.setSocketDescriptor(socketDescriptor);
        rejectedClient.write(QByteArray("DataOne server full. Can not accept connection now.\r\n"));
        rejectedClient.write(QByteArray("Please try later.\r\n"));
        rejectedClient.disconnectFromHost();
    }
}



//PUBLIC SLOT
void TcpDataServer::SendTagData(QByteArray NewTagRecord, quint64 RecordNumber)
{
    // Save the record number and raise signal to inform client threads.
    emit NewTagAvailable(NewTagRecord, RecordNumber);
    CurrentRecordIndex = RecordNumber;
}

//PUBLIC SLOT
void TcpDataServer::UpdateTemperature(int Temp)
{
    // Store the current reader temperature.
    ReaderTemperature = Temp;
}

//PUBLIC SLOT
void TcpDataServer::UpdateBatteryVoltage(double Voltage)
{
    // Store the current battery voltage.
    ExternalBatteryVoltage = Voltage;
}

//PUBLIC SLOT
void TcpDataServer::SendBroadcast(QByteArray BroadcastMessage)
{
    // Raise signal to pass on the broadcast message to client threads.
    emit SendBroadcastMessage(BroadcastMessage);
}

//PUBLIC SLOT
void TcpDataServer::ReadingStarted(bool State)
{
    // Store reading state.
    isReading = State;

}

//PUBLIC SLOT
void TcpDataServer::ClearBuffers()
{
    // Reset record index and inform client threads.
    emit ClearBuffer();
    CurrentRecordIndex = 0;
}

//PUBLIC SLOT
void TcpDataServer::StoreAntennaState(QString State)
{
    // Store antennas state and inform client threads.
    AntennaState = State;
    emit UpdateAntennaState(AntennaState);
}

//PUBLIC SLOT
void TcpDataServer::Shutdown()
{
    emit Log("ACTION", QString("Shutting down TCP Data Server thread.\n\r"));
    emit DataOneShutdown();
}



//PRIVATE SLOT
void TcpDataServer::DecrementConnectedClientsCount()
{
    // Decrease the clients counter and inform the GpioHandler.
    ConnectedClients--;
    emit ClientDisconnected();
}

//PRIVATE SLOT
void TcpDataServer::LogFromChildThread(QString MessageType, QString LogEntry)
{
    // Raise signal to pass on log entries from client threads to the main thread.
    emit Log(MessageType, LogEntry);
}

//PRIVATE SLOT
void TcpDataServer::CommandFromChildThread(QByteArray Command)
{
    // Raise signal to pass on client commands to main thread.
    emit ClientCommand(Command);
}

//PRIVATE SLOT
void TcpDataServer::SendStatus()
{
    // Convert values to QString.
    QString Record = QString("%1").arg(CurrentRecordIndex);
    QString Temperature = QString("%1").arg(ReaderTemperature);
    QString Voltage = QString("%1").arg(ExternalBatteryVoltage);

    // Determine reader status.
    QString ReaderStatus;
    if(isReading) ReaderStatus = "on";
    else ReaderStatus = "off";

    // Format voltage value.
    if (Voltage.length() == 2)
        Voltage.append(".0");

    // Make the status message.
    QByteArray Status;
    Status.append("status " + Record + " " + ReaderStatus + " " + Temperature + " " + Voltage + "\r\n");

    // Raise signal to sent status message to all connected client threads.
    emit SendStatusPing(Status);
}

//PRIVATE SLOT
void TcpDataServer::CheckServerStatus()
{
    // If server is not running, then start the server again.
    if (!this->isListening())
    {
        if (listen(QHostAddress(QHostAddress::Any), TcpServerPort))
        {
            emit Log("STATUS", QString("Data server Ready.\n\r"));
            emit Log("STATUS", QString("Waiting for connections on port %2 \n\r").arg((int) TcpServerPort));
            emit Log("", "\n\r");

            // Setup status message timer.
            ServerPingTimer.setInterval(SystemSettings->DataOneNetworkSettings.PingInterval * 1000);
            connect(&ServerPingTimer, SIGNAL(timeout()), this, SLOT(SendStatus()));
            ServerPingTimer.start();
        }
        else
        {
            emit Log("ERROR", QString("Could not initialize Data server.\n\r"));
            emit Log("", "\n\r");
        }
    }
}





