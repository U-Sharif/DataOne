#include "tcpconsoleserver.h"

// CONSTRUCTOR
TcpConsoleServer::TcpConsoleServer(QObject *parent) :
    QTcpServer(parent)
{
    // Defaults.
    setMaxPendingConnections(2);    // This is a QTcpServer public function.
    ConnectedClients = 0;

}


//PUBLIC FUNCTION
void TcpConsoleServer::StartServer()
{
    // Set clinet connection limit.
    MaximumConnectedClients = SystemSettings->DataOneNetworkSettings.MaxConnectedClients;

    // Set port.
    TcpServerPort = SystemSettings->DataOneNetworkSettings.ConsolePort;

    // Listen for connections on the given port and all IP addresses.
    if (listen(QHostAddress(QHostAddress::Any), TcpServerPort))
    {
        emit Log("STATUS", QString("Console server Ready.\n\r"));
        emit Log("STATUS", QString("Waiting for connections on port %2 \n\r").arg((int) TcpServerPort));
        emit Log("", "\n\r");
    }
    else
    {
        emit Log("ERROR", QString("Could not initialize Console server.\n\r"));
        emit Log("", "\n\r");
    }

    // Check server status regularly.
    ServerStatusCheckTimer.setInterval(10000);
    connect(&ServerStatusCheckTimer, SIGNAL(timeout()), this, SLOT(CheckServerStatus()));
    ServerStatusCheckTimer.start();
}

//PUBLIC FUNCTION
void TcpConsoleServer::SendNewLog(QByteArray newLog)
{
    // Raise a signal about new log.
    // This is done to make the log sending a non-blocking process for the caller.
    emit NewLogAvailable(newLog);
}



//PROTECTED OVERRIDE
void TcpConsoleServer::incomingConnection(int socketDescriptor)
{
    // This function is called when ever a new clinet is trying to connect to this server.
    if (ConnectedClients < MaximumConnectedClients) // Follow limits.
    {
        // Create a new console client thread.
        newConsoleClient = new TcpConsoleClient(socketDescriptor, this);

        // Connect the new client's signals.
        connect(newConsoleClient, SIGNAL(Log(QString, QString)), this, SLOT(LogFromChildThread(QString, QString)));
        connect(newConsoleClient, SIGNAL(finished()), newConsoleClient, SLOT(deleteLater()));
        connect(newConsoleClient, SIGNAL(finished()), this, SLOT(DecrementConnectedClientsCount()));
        connect(newConsoleClient, SIGNAL(Command_GetRunningTime()), this, SLOT(SendApplicationRunningTime()));
        connect(newConsoleClient, SIGNAL(ConsoleCommand(QByteArray)), this, SLOT(CommandFromChildThread(QByteArray)));

        // Connect the new client's slots.
        connect(this, SIGNAL(NewLogAvailable(QByteArray)), newConsoleClient, SLOT(SendLog(QByteArray)));
        connect(this, SIGNAL(UpdateAntennaState(QString)), newConsoleClient, SLOT(StoreAntennaState(QString)));
        connect(this, SIGNAL(DataOneShutdown()), newConsoleClient, SLOT(quit()));

        // Start the new client thread.
        newConsoleClient->start();

        // Increment connected clients count.
        ConnectedClients++;

        //This will send all the previous log entries to the new client.
        newConsoleClient->SendLog(LogBuffer->buffer());
    }
    else
    {
        // Reject the client with a message.
        QTcpSocket rejectedClient(this);
        rejectedClient.setSocketDescriptor(socketDescriptor);
        rejectedClient.write(QByteArray("DataOne server full. Can not accept console connections now.\r\n"));
        rejectedClient.write(QByteArray("Please try later...\r\n"));
        rejectedClient.disconnectFromHost();

    }
}



//PUBLIC SLOT
void TcpConsoleServer::SendApplicationRunningTime()
{
    // Send signal to mian thread for sending application running time.
    emit Command_GetRunningTime();
}

//PUBLIC SLOT
void TcpConsoleServer::StoreAntennaState(QString State)
{
    // Store antenna state received from reader and send to all clinet threads.
    AntennaState = State;
    emit UpdateAntennaState(AntennaState);
}

//PUBLIC SLOT
void TcpConsoleServer::Shutdown()
{
    emit Log("ACTION", QString("Shutting down TCP Console Server thread.\n\r"));
    emit DataOneShutdown();
}




//PRIVATE SLOT
void TcpConsoleServer::DecrementConnectedClientsCount()
{
    // Decrement connected client count.
    ConnectedClients--;
}

//PRIVATE SLOT
void TcpConsoleServer::LogFromChildThread(QString MessageType, QString LogEntry)
{
    // Send log from client thread to the main thread.
    emit Log(MessageType, LogEntry);
}

//PRIVATE SLOT
void TcpConsoleServer::CheckServerStatus()
{
    // If server is not running, then start the server again.
    if (!this->isListening())
    {
        if (listen(QHostAddress(QHostAddress::Any), TcpServerPort))
        {
            emit Log("STATUS", QString("Console server Ready.\n\r"));
            emit Log("STATUS", QString("Waiting for connections on port %2 \n\r").arg((int) TcpServerPort));
            emit Log("", "\n\r");
        }
        else
        {
            emit Log("ERROR", QString("Could not initialize Console server.\n\r"));
            emit Log("", "\n\r");
        }
    }
}

//PRIVATE SLOT
void TcpConsoleServer::CommandFromChildThread(QByteArray Command)
{
    // Raise signal to pass on client commands to main thread.
    emit ClientCommand(Command);
}

