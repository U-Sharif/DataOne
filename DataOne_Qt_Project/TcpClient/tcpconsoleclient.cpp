#include "tcpconsoleclient.h"

// CONSTRUCTOR
TcpConsoleClient::TcpConsoleClient(int SocketDescriptor, QObject *parent) :
    QThread(parent)
{
    // Defaults.
    AntennaState = "";
    isDisconnecting = false;    //Controls loopback of Log signals.

    connect(&TcpConsoleSocket, SIGNAL(readyRead()), this, SLOT(onDataReceived()));
    connect(&TcpConsoleSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(&TcpConsoleSocket, SIGNAL(disconnected()), this, SLOT(quit()));

    // Setup tcp port.
    isTcpDataSocketConnected = TcpConsoleSocket.setSocketDescriptor(SocketDescriptor);

    if (isTcpDataSocketConnected)
    {
        ClientIP = TcpConsoleSocket.peerAddress().toString();
        ClientName = TcpConsoleSocket.peerName();
        ClientPort = TcpConsoleSocket.peerPort();
        LocalTcpPort = TcpConsoleSocket.localPort();
    }

}

//PROTECTED OVERRIDE FUNCTION
void TcpConsoleClient::run()
{
    if (isTcpDataSocketConnected)
    {
        // Perform some initialization actions.
        onConnected();

        // Setup a timer to check tcp port status at regular intervals.
        QTimer PortStatusTimer;
        connect(&PortStatusTimer, SIGNAL(timeout()), this, SLOT(CheckPortStatus()));
        connect(this, SIGNAL(finished()), &PortStatusTimer, SLOT(stop()));
        connect(this, SIGNAL(finished()), &PortStatusTimer, SLOT(deleteLater()));
        PortStatusTimer.start(10000);

        // Start eventloop of new thread.
        exec();
    }
    else
    {
        onDisconnected();
    }
}


//PRIVATE FUNCTION
void TcpConsoleClient::onConnected()
{
    TcpConsoleSocket.setSocketOption(QAbstractSocket::LowDelayOption, 1);   // Enable Tcp low delay option.
    TcpConsoleSocket.setSocketOption(QAbstractSocket::KeepAliveOption, 1);  // Enable Tcp keep alive option.

    // Show some nice output on console.
    QString ConnectedLog;
    ConnectedLog.append(QString("\n\r"));
    ConnectedLog.append(QString("********** CONNECTED **********\n\r"));
    ConnectedLog.append(QString("* Type:        Console\n\r"));
    ConnectedLog.append(QString("* Client Name: %1\n\r").arg(ClientName));
    ConnectedLog.append(QString("* Client IP:   %1\n\r").arg(ClientIP));
    ConnectedLog.append(QString("* Client Port: %1\n\r").arg(ClientPort));
    ConnectedLog.append(QString("* Local Port:  %1\n\r").arg(LocalTcpPort));
    ConnectedLog.append(QString("*******************************\n\r"));
    emit Log("NETWORK", ConnectedLog);
    emit Log("", "\n\r");
}



//PRIVATE SLOT
void TcpConsoleClient::onDisconnected()
{
    // Block further sending of data on this thread's tcp port.
    isDisconnecting = true;

    // Disconnect this thread's signals and slots.
    disconnect(this, SIGNAL(Log(QString, QString)));
    disconnect(this, SLOT(SendLog(QByteArray)));
    disconnect(this, SLOT(StoreAntennaState(QString)));

    // Show some nicce output on console.
    QString DisconnectedLog;
    DisconnectedLog.append(QString("\n\r"));
    DisconnectedLog.append(QString("********* DISCONNECTED *********\n\r"));
    DisconnectedLog.append(QString("* Type:        Console\n\r"));
    DisconnectedLog.append(QString("* Client Name: %1\n\r").arg(ClientName));
    DisconnectedLog.append(QString("* Client IP:   %1\n\r").arg(ClientIP));
    DisconnectedLog.append(QString("* Client Port: %1\n\r").arg(ClientPort));
    DisconnectedLog.append(QString("* Local Port:  %1\n\r").arg(LocalTcpPort));
    DisconnectedLog.append(QString("********************************\n\r"));
    emit Log("NETWORK", DisconnectedLog);
    emit Log("", "\n\r");

    // Quit this thread.
    quit();
}

//PRIVATE SLOT
void TcpConsoleClient::onDataReceived()
{
    // Any data/commands sent by console clients is received here.

    // Read the command into a byte array.
    QByteArray ClientData;
    ClientData.resize(TcpConsoleSocket.bytesAvailable());
    TcpConsoleSocket.read(ClientData.data(), ClientData.length());
    ClientData_buffer.append(ClientData);

    // Parse the commands here.
    if (ClientData_buffer.contains("\r") || ClientData_buffer.contains("\n"))
    {
        ClientData_buffer = ClientData_buffer.trimmed(); // Remove useless characters from start and end.
        emit Log("COMMAND", QString("%1  (from %2)\n\r").arg(QString(ClientData_buffer)).arg(ClientIP)); // Show command on console.

        if (ClientData_buffer == "exit")
        {
            TcpConsoleSocket.disconnectFromHost();
            quit();
        }

        else if (ClientData_buffer == "get_rospec")
        {
            QFile::remove("/cust/app/rospec.xml");      // Remove old rospec dump.
            system("/cust/app/getROSPEC &");            // Execute rospec fetching script in a system command.
            sleep(5);                                   // Wait for script to finish.
            QFile RospecFile("/cust/app/rospec.xml");   // Start hadling the new rospec dump file.

            if (RospecFile.exists())
            {
                emit Log("ACTION", QString("Sending ROSPEC 0.\n\r"));
                emit Log("", "\n\r");

                RospecFile.open(QIODevice::ReadOnly);
                QByteArray RospecXMLLine;
                bool XMLValid = false;

                while (!RospecFile.atEnd())             // Read everything in the dump file.
                {
                    RospecXMLLine = RospecFile.readLine();


                    if (RospecXMLLine.contains("<GET_ROSPECS_RESPONSE")) XMLValid = true;       // Validate start of XML.
                    if (RospecXMLLine.contains("</GET_ROSPECS_RESPONSE>"))
                    {
                        XMLValid = false;                                                       // This is end of XML data. Anything beyond this is junk.
                        SendLog(RospecXMLLine);                                                 // Special case for one last line.
                    }

                    if (XMLValid)
                        SendLog(RospecXMLLine);                                                 // Send line to client.
                }

                SendLog("\n\r"); // Insert some space.

            }
            else
            {
                emit Log("ERROR", "Failed to retrieve ROSPEC.\n\r");
                emit Log("", "\n\r");
            }
        }

        else if (ClientData_buffer == "get_running_time")
        {
            emit Command_GetRunningTime();                                                      // Running time is maintained by main thread, send a signal to main thread.
        }

        else if (ClientData_buffer == "get_antennas_connected")
        {
            emit Log("ACTION", QString("%1\n\r").arg(AntennaState));
            emit Log("", "\n\r");
        }

        else if (ClientData_buffer == "d1_shutdown")
        {
            emit ConsoleCommand(ClientData_buffer);
            TcpConsoleSocket.disconnectFromHost();
            quit();
        }

        else if (ClientData_buffer == "reader_reboot")
        {
            emit ConsoleCommand(ClientData_buffer);
            TcpConsoleSocket.disconnectFromHost();
            quit();
        }

        else
        {
            emit Log("ERROR", QString("Illegal command.\n\r"));
            emit Log("", "\n\r");
        }


        ClientData_buffer.clear();  // Clear buffer to make space for next command.
    }

}

//PRIVATE SLOT
void TcpConsoleClient::CheckPortStatus()
{
    // Tear down connection if some socket fault has happened.
    if (!TcpConsoleSocket.isValid() || !TcpConsoleSocket.isOpen())
    {
        TcpConsoleSocket.abort();
    }
}


//PUBLIC SLOT
void TcpConsoleClient::SendLog(QByteArray LogEntry)
{
    // Block data sendding if this thread is quiting.
    if (isDisconnecting)
        return;

    // Try to send data, or abort connection if fault detected.
    if (TcpConsoleSocket.isValid())
    {
        if (!TcpConsoleSocket.isOpen() || TcpConsoleSocket.write(LogEntry) < 1)
        {
            TcpConsoleSocket.abort();
        }
    }
    else
    {
        TcpConsoleSocket.abort();
    }
}


//PUBLIC SLOT
void TcpConsoleClient::StoreAntennaState(QString State)
{
    // Store current antennas state.
    AntennaState = State;
}
