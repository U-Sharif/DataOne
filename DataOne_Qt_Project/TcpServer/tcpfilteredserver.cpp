#include "tcpfilteredserver.h"

TcpFilteredServer::TcpFilteredServer(QObject *parent) :
    QTcpServer(parent)
{
    // Defaults.
    setMaxPendingConnections(2);    // This is a QTcpServer public function.
    ConnectedClients = 0;
    CurrentRecordIndex = 0;
    ReaderTemperature = 0;
    ExternalBatteryVoltage = 13.0; //Start from correct voltage value, otherwise first message will have 0.
    isReading = false;
}


//PUBLIC FUNCTION
void TcpFilteredServer::StartServer()
{
    // Set clinet connection limit.
    MaximumConnectedClients = SystemSettings->DataOneNetworkSettings.MaxConnectedClients;

    // Set port.
    TcpServerPort = SystemSettings->DataOneNetworkSettings.FilteredPort;

    // Listen for connections on the given port and all IP addresses.
    if (listen(QHostAddress(QHostAddress::Any), TcpServerPort))
    {
        emit Log("STATUS", QString("Filtered server Ready.\n\r"));
        emit Log("STATUS", QString("Waiting for connections on port %2 \n\r").arg((int) TcpServerPort));
        emit Log("", "\n\r");

        // Setup status message timer.
        ServerPingTimer.setInterval(SystemSettings->DataOneNetworkSettings.PingInterval * 1000);
        connect(&ServerPingTimer, SIGNAL(timeout()), this, SLOT(SendStatus()));
        ServerPingTimer.start();

        // Setup timing server 1 connecction.
        if (SystemSettings->DataOneApplicationSettings.EnableTimingServer1 && !SystemSettings->DataOneNetworkSettings.TimingServer1Address.isEmpty())
            SetupTimingServer1();

        // Setup timing server 2 connecction.
        if (SystemSettings->DataOneApplicationSettings.EnableTimingServer2 && !SystemSettings->DataOneNetworkSettings.TimingServer2Address.isEmpty())
            SetupTimingServer2();
    }
    else
    {
        emit Log("ERROR", QString("Could not initialize Filtered server.\n\r"));
        emit Log("", "\n\r");
    }

    // Check server status regularly.
    ServerStatusCheckTimer.setInterval(10000);
    connect(&ServerStatusCheckTimer, SIGNAL(timeout()), this, SLOT(CheckServerStatus()));
    ServerStatusCheckTimer.start();
}


//PROTECTED OVERRIDE
void TcpFilteredServer::incomingConnection(int socketDescriptor)
{
    // This function is called when ever a new clinet is trying to connect to this server.
    if (ConnectedClients < MaximumConnectedClients)
    {
        // Create a new filtered client thread.
        newFilteredClient = new TcpTelnetClient(socketDescriptor, TelnetFilteredClient, CurrentRecordIndex, this);

        // Pass on the pointer of system settings to client thread.
        newFilteredClient->SystemSettings = SystemSettings;

        // Connect the new client's signals.
        connect(newFilteredClient, SIGNAL(ClientCommand(QByteArray)), this, SLOT(CommandFromChildThread(QByteArray)));
        connect(newFilteredClient, SIGNAL(Log(QString, QString)), this, SLOT(LogFromChildThread(QString, QString)));
        connect(newFilteredClient, SIGNAL(finished()), newFilteredClient, SLOT(deleteLater()));
        connect(newFilteredClient, SIGNAL(finished()), this, SLOT(DecrementConnectedClientsCount()));

        // Connect the new client's slots.
        connect(this, SIGNAL(NewTagAvailable(QByteArray,quint64)), newFilteredClient, SLOT(SendTagData(QByteArray,quint64)));
        connect(this, SIGNAL(SendStatusPing(QByteArray)), newFilteredClient, SLOT(SendStatusPing(QByteArray)));
        connect(this, SIGNAL(SendBroadcastMessage(QByteArray)), newFilteredClient, SLOT(SendBroadcastMessage(QByteArray)));
        connect(this, SIGNAL(ClearBuffer()), newFilteredClient, SLOT(ClearBuffers()));
        connect(this, SIGNAL(UpdateAntennaState(QString)), newFilteredClient, SLOT(StoreAntennaState(QString)));
        connect(this, SIGNAL(DataOneShutdown()), newFilteredClient, SLOT(quit()));

        // Start the new client thread.
        newFilteredClient->start();

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
        rejectedClient.waitForBytesWritten(3000);
        rejectedClient.disconnectFromHost();
    }
}



//PRIVATE FUNCTION
void TcpFilteredServer::SetupTimingServer1()
{
    emit Log("STATUS", QString("Initializing Timing Server 1 connection.\n\r"));
    //emit Log("", "\n\r");

    // Set server name.
    QString ServerName = SystemSettings->DataOneNetworkSettings.TimingServer1Address;

    // Set server port.
    quint16 ServerPort = SystemSettings->DataOneNetworkSettings.TimingServerBasePort + SystemSettings->DataOneDeviceSettings.Reader_Number;

    // Initialize timing server connection thread.
    Timing1ServerConnection = new TcpServerConnection(ServerName, ServerPort, CurrentRecordIndex);

    // Pass on the pointer of system settings to connection thread.
    Timing1ServerConnection->SystemSettings = SystemSettings;

    // Connect the new server connection signals.
    connect(Timing1ServerConnection, SIGNAL(ServerCommand(QByteArray)), this, SLOT(CommandFromChildThread(QByteArray)));
    connect(Timing1ServerConnection, SIGNAL(Log(QString, QString)), this, SLOT(LogFromChildThread(QString, QString)));
    connect(Timing1ServerConnection, SIGNAL(TimingServerConnected()), this, SLOT(IncrementConnectedClientsCount()));
    connect(Timing1ServerConnection, SIGNAL(TimingServerDisconnected()), this, SLOT(DecrementConnectedClientsCount()));

    // Connect the new server connection slots.
    connect(this, SIGNAL(NewTagAvailable(QByteArray,quint64)), Timing1ServerConnection, SLOT(SendTagData(QByteArray,quint64)));
    connect(this, SIGNAL(SendStatusPing(QByteArray)), Timing1ServerConnection, SLOT(SendStatusPing(QByteArray)));
    connect(this, SIGNAL(SendBroadcastMessage(QByteArray)), Timing1ServerConnection, SLOT(SendBroadcastMessage(QByteArray)));
    connect(this, SIGNAL(ClearBuffer()), Timing1ServerConnection, SLOT(ClearBuffers()));
    connect(this, SIGNAL(UpdateAntennaState(QString)), Timing1ServerConnection, SLOT(StoreAntennaState(QString)));

    // Start the new connection thread. This is a persistant thread.
    Timing1ServerConnection->start();

}

//PRIVATE FUNCTION
void TcpFilteredServer::SetupTimingServer2()
{
    emit Log("STATUS", QString("Initializing Timing Server 2 connection.\n\r"));
    //emit Log("", "\n\r");

    // Set server name.
    QString ServerName = SystemSettings->DataOneNetworkSettings.TimingServer2Address;

    // Set server port.
    quint16 ServerPort = SystemSettings->DataOneNetworkSettings.TimingServerBasePort + SystemSettings->DataOneDeviceSettings.Reader_Number;

    // Initialize timing server connection thread.
    Timing2ServerConnection = new TcpServerConnection(ServerName, ServerPort, CurrentRecordIndex);

    // Pass on the pointer of system settings to connection thread.
    Timing2ServerConnection->SystemSettings = SystemSettings;

    // Connect the new server connection signals.
    connect(Timing2ServerConnection, SIGNAL(ServerCommand(QByteArray)), this, SLOT(CommandFromChildThread(QByteArray)));
    connect(Timing2ServerConnection, SIGNAL(Log(QString, QString)), this, SLOT(LogFromChildThread(QString, QString)));
    connect(Timing2ServerConnection, SIGNAL(TimingServerConnected()), this, SLOT(IncrementConnectedClientsCount()));
    connect(Timing2ServerConnection, SIGNAL(TimingServerDisconnected()), this, SLOT(DecrementConnectedClientsCount()));

    // Connect the new server connection slots.
    connect(this, SIGNAL(NewTagAvailable(QByteArray,quint64)),Timing2ServerConnection, SLOT(SendTagData(QByteArray,quint64)));
    connect(this, SIGNAL(SendStatusPing(QByteArray)), Timing2ServerConnection, SLOT(SendStatusPing(QByteArray)));
    connect(this, SIGNAL(SendBroadcastMessage(QByteArray)), Timing2ServerConnection, SLOT(SendBroadcastMessage(QByteArray)));
    connect(this, SIGNAL(ClearBuffer()), Timing2ServerConnection, SLOT(ClearBuffers()));
    connect(this, SIGNAL(UpdateAntennaState(QString)), Timing2ServerConnection, SLOT(StoreAntennaState(QString)));

    // Start the new connection thread. This is a persistant thread.
    Timing2ServerConnection->start();
}



//PUBLIC SLOT
void TcpFilteredServer::SendTagData(QByteArray NewTagRecord, quint64 RecordNumber)
{
    // Save the record number and raise signal to inform client threads.
    emit NewTagAvailable(NewTagRecord, RecordNumber);
    CurrentRecordIndex = RecordNumber;
}

//PUBLIC SLOT
void TcpFilteredServer::UpdateTemperature(int Temp)
{
    // Store the current reader temperature.
    ReaderTemperature = Temp;
}

//PUBLIC SLOT
void TcpFilteredServer::UpdateBatteryVoltage(double Voltage)
{
    // Store the current battery voltage.
    ExternalBatteryVoltage = Voltage;
}

//PUBLIC SLOT
void TcpFilteredServer::SendBroadcast(QByteArray BroadcastMessage)
{
    // Raise signal to pass on the broadcast message to client threads.
    emit SendBroadcastMessage(BroadcastMessage);
}

//PUBLIC SLOT
void TcpFilteredServer::ReadingStarted(bool State)
{
    // Store reading state.
    isReading = State;

}

//PUBLIC SLOT
void TcpFilteredServer::ClearBuffers()
{
    // Reset record index and inform client threads.
    emit ClearBuffer();
    CurrentRecordIndex = 0;
}

//PUBLIC SLOT
void TcpFilteredServer::StoreAntennaState(QString State)
{
    // Store antennas state and inform client threads.
    AntennaState = State;
    emit UpdateAntennaState(AntennaState);
}

//PUBLIC SLOT
void TcpFilteredServer::Shutdown()
{
    emit Log("ACTION", QString("Shutting down TCP Filtered Server thread.\n\r"));
    emit DataOneShutdown();

    Timing1ServerConnection->quit();
    Timing2ServerConnection->quit();
}



//PRIVATE SLOT
void TcpFilteredServer::IncrementConnectedClientsCount()
{
    // Increase the clients counter and inform the GpioHandler.
    ConnectedClients++;
    emit ClientConnected();
}

//PRIVATE SLOT
void TcpFilteredServer::DecrementConnectedClientsCount()
{
    // Decrease the clients counter and inform the GpioHandler.
    ConnectedClients--;
    emit ClientDisconnected();
}

//PRIVATE SLOT
void TcpFilteredServer::LogFromChildThread(QString MessageType, QString LogEntry)
{
    // Raise signal to pass on log entries from client threads to the main thread.
    emit Log(MessageType, LogEntry);
}

//PRIVATE SLOT
void TcpFilteredServer::CommandFromChildThread(QByteArray Command)
{
    // Raise signal to pass on client commands to main thread.
    emit ClientCommand(Command);
}

//PRIVATE SLOT
void TcpFilteredServer::SendStatus()
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
void TcpFilteredServer::CheckServerStatus()
{
    // If server is not running, then start the server again.
    if (!this->isListening())
    {
        if (listen(QHostAddress(QHostAddress::Any), TcpServerPort))
        {
            emit Log("STATUS", QString("Filtered server Ready.\n\r"));
            emit Log("STATUS", QString("Waiting for connections on port %2 \n\r").arg((int) TcpServerPort));
            emit Log("", "\n\r");

            // Setup status message timer.
            ServerPingTimer.setInterval(SystemSettings->DataOneNetworkSettings.PingInterval * 1000);
            connect(&ServerPingTimer, SIGNAL(timeout()), this, SLOT(SendStatus()));
            ServerPingTimer.start();

            // Setup timing server 1 connecction.
            if (SystemSettings->DataOneApplicationSettings.EnableTimingServer1 && !SystemSettings->DataOneNetworkSettings.TimingServer1Address.isEmpty())
                SetupTimingServer1();

            // Setup timing server 2 connecction.
            if (SystemSettings->DataOneApplicationSettings.EnableTimingServer2 && !SystemSettings->DataOneNetworkSettings.TimingServer2Address.isEmpty())
                SetupTimingServer2();
        }
    }
}

