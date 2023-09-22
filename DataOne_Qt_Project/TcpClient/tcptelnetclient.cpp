#include "tcptelnetclient.h"

// CONSTRUCTOR
TcpTelnetClient::TcpTelnetClient(int SocketDescriptor, TelnetClientType ClientType, quint64 RecordCounter, QObject *parent) :
    QThread(parent)
{
    // Defaults
    Client = ClientType;
    FilePosition = 0;
    StartRecordIndex = 0;
    SXValid = false;
    SdtValid=false;
    SendCustomFile = false;
    AntennaState = "";

    LastCommandIndex = 0;

    isDisconnecting = false;

    // Set clinet type. Data or Filtered.
    //if (Client == TelnetDataClient)
    //    CurrentRecordIndex = TagRecord::DataRecordCounter;
    //if (Client == TelnetFilteredClient)
    //    CurrentRecordIndex = TagRecord::FilteredRecordCounter;
    CurrentRecordIndex = RecordCounter;

    FileChunkReadTimer.setInterval(1000);
    connect(&FileChunkReadTimer, SIGNAL(timeout()), this, SLOT(ReadChunkFromFile()));

    connect(&TcpDataSocket, SIGNAL(readyRead()), this, SLOT(onDataReceived()));
    connect(&TcpDataSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(&TcpDataSocket, SIGNAL(disconnected()), this, SLOT(quit()));

    LastCommandIndexResetTimer.setInterval(30000);
    LastCommandIndexResetTimer.setSingleShot(true);
    connect(&LastCommandIndexResetTimer, SIGNAL(timeout()), this, SLOT(ResetLastCommandIndex()));

    LastCommandDateTimeResetTimer.setInterval(30000);
    LastCommandDateTimeResetTimer.setSingleShot(true);
    connect(&LastCommandDateTimeResetTimer, SIGNAL(timeout()), this, SLOT(ResetLastCommandDateTime()));

    // Setup a new tcp socket for this thread
    isTcpDataSocketConnected = TcpDataSocket.setSocketDescriptor(SocketDescriptor);
    SendTcpData(QByteArray("\r")); // Send this to clear client side screen buffer, if client is connecting from DOS application.

    if (isTcpDataSocketConnected)
    {
        // Get socket properties.
        ClientIP = TcpDataSocket.peerAddress().toString();
        ClientName = TcpDataSocket.peerName();
        ClientPort = TcpDataSocket.peerPort();
        LocalTcpPort = TcpDataSocket.localPort();
    }
}




//PROTECTED OVERRIDE FUNCTION
void TcpTelnetClient::run()
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
void TcpTelnetClient::onConnected()
{
    TcpDataSocket.setSocketOption(QAbstractSocket::LowDelayOption, 1);   // Enable Tcp low delay option.
    TcpDataSocket.setSocketOption(QAbstractSocket::KeepAliveOption, 1);  // Enable Tcp keep alive option.

    // Show some nice output on console.
    QString ConnectedLog;
    ConnectedLog.append(QString("\n\r"));
    ConnectedLog.append(QString("********** CONNECTED **********\n\r"));
    ConnectedLog.append(QString("* Type:        Client\n\r"));
    ConnectedLog.append(QString("* Client Name: %1\n\r").arg(ClientName));
    ConnectedLog.append(QString("* Client IP:   %1\n\r").arg(ClientIP));
    ConnectedLog.append(QString("* Client Port: %1\n\r").arg(ClientPort));
    ConnectedLog.append(QString("* Local Port:  %1\n\r").arg(LocalTcpPort));
    ConnectedLog.append(QString("*******************************\n\r"));
    emit Log("NETWORK", ConnectedLog);
    emit Log("", "\n\r");
}



//PUBLIC SLOT
void TcpTelnetClient::SendTagData(QByteArray NewTagRecord, quint64 RecordNumber)
{
    // Send tag record to timing server if not already sending records from file.
    if (!SXValid && !SdtValid)
    {
        SendTcpData(NewTagRecord);
    }

    CurrentRecordIndex = RecordNumber;
}

//PUBLIC SLOT
void TcpTelnetClient::SendStatusPing(QByteArray Status)
{
    // Send status message.
    //Status += QString("(SXValid=%1) (SdtValid=%2) (FilePosition=%3)\r\n").arg(SXValid).arg(SdtValid).arg(FilePosition);
    SendTcpData(Status);
}

//PUBLIC SLOT
void TcpTelnetClient::SendBroadcastMessage(QByteArray BroadcastMessage)
{
    // Send broadcast message.
    SendTcpData(BroadcastMessage);
}

//PUBLIC SLOT
void TcpTelnetClient::ClearBuffers()
{
    // Reset variables if clear_buffers command is received in any thread in the application.
    SXValid = false;    //Stop sending records from previous file.
    SdtValid = false;   //Stop sending records from previous file.
    CurrentRecordIndex = 0;
}

//PUBLIC SLOT
void TcpTelnetClient::StoreAntennaState(QString State)
{
    // Store antenna state.
    AntennaState = State;
}



//PRIVATE SLOT
void TcpTelnetClient::SendTcpData(QByteArray TcpData)
{
    // Block data sendding if this thread is quiting.
    if (isDisconnecting)
        return;

    // Try to send data, or abort connection if fault detected.
    if (TcpDataSocket.isValid())
    {
        if (!TcpDataSocket.isOpen() || TcpDataSocket.write(TcpData) < 1)
        {
            TcpDataSocket.abort();
        }
    }
    else
    {
        TcpDataSocket.abort();
    }
}

//PRIVATE SLOT
void TcpTelnetClient::onDisconnected()
{
    // Block further sending of data on this thread's tcp port.
    isDisconnecting = true;

    // Show some nicce output on console.
    QString DisconnectedLog;
    DisconnectedLog.append(QString("\n\r"));
    DisconnectedLog.append(QString("********* DISCONNECTED *********\n\r"));
    DisconnectedLog.append(QString("* Type:        Client\n\r"));
    DisconnectedLog.append(QString("* Client Name: %1\n\r").arg(ClientName));
    DisconnectedLog.append(QString("* Client IP:   %1\n\r").arg(ClientIP));
    DisconnectedLog.append(QString("* Client Port: %1\n\r").arg(ClientPort));
    DisconnectedLog.append(QString("* Local Port:  %1\n\r").arg(LocalTcpPort));
    DisconnectedLog.append(QString("********************************\n\r"));
    emit Log("NETWORK", DisconnectedLog);
    emit Log("", "\n\r");

    // Disconnect signals and slots.
    disconnect(this, SIGNAL(Log(QString, QString)));
    disconnect(this, SIGNAL(ClientCommand(QByteArray)));

    disconnect(this, SLOT(SendTagData(QByteArray,quint64)));
    disconnect(this, SLOT(SendStatusPing(QByteArray)));
    disconnect(this, SLOT(SendBroadcastMessage(QByteArray)));
    disconnect(this, SLOT(StoreAntennaState(QString)));

    // Quit this thread.
    quit();
}



//PRIVATE SLOT
void TcpTelnetClient::onDataReceived()
{
    // Any data/commands sent by telnet client is received here.

    if (!isDisconnecting)
    {
        // Read the command into a byte array.
        QByteArray ClientData;
        ClientData.resize(TcpDataSocket.bytesAvailable());
        TcpDataSocket.read(ClientData.data(), ClientData.length());
        ClientData_buffer.append(ClientData);

        // Parse the commands here.
        if (ClientData_buffer.contains("\r") || ClientData_buffer.contains("\n"))
        {
            ClientData_buffer = ClientData_buffer.trimmed();

            //Following code takes care of a bug in scoring application.
            QList<QByteArray> CommandsList = ClientData_buffer.split('\n');

            for (int i = 0; i < CommandsList.size(); i++) // This for loop caters for a bug, where multiple commands are received at once.
            {
                QByteArray CurrentCommand = CommandsList.at(i).trimmed();  // Remove useless characters from start and end.

                // Show commands on console except 'ping'.
                if (!CurrentCommand.startsWith("ping"))
                    emit Log("COMMAND", QString("%1 (from %2)\n\r").arg(QString(CurrentCommand)).arg(ClientIP));


                if (CurrentCommand.startsWith("ping"))
                {
                    // ping command is entailed by clint time.
                    // This time will be used to determine the time difference between client and this reader.
                    if (CurrentCommand.length() > 4)
                    {
                        // Take current time and do time zone adjustment.
                        QDateTime ReaderTime = SystemSettings->AdjustTimeZoneAndDST(QDateTime::currentDateTime());

                        CurrentCommand.remove(0, 5);
                        QStringList DateTimeParts = QString(CurrentCommand).split(' ');

                        int Day = DateTimeParts.at(0).mid(0,2).toInt();
                        int Month = DateTimeParts.at(0).mid(3,2).toInt();
                        int Year = DateTimeParts.at(0).mid(6,4).toInt();

                        int Hour = DateTimeParts.at(1).mid(0,2).toInt();
                        int Minute = DateTimeParts.at(1).mid(3,2).toInt();
                        int Second = DateTimeParts.at(1).mid(6,2).toInt();
                        int MilliSecond = DateTimeParts.at(1).mid(9).toInt();

                        QDateTime ClientTime(QDate(Year, Month, Day), QTime(Hour, Minute, Second, MilliSecond));

                        //emit Log("ACTION", QString("client DateTime = %1.\n\r").arg(ServerTime.toString("dd.MM.yyyy hh:mm:ss.z")));

                        double TimeDifference = ReaderTime.msecsTo(ClientTime) / 1000.000;

                        // Time difference should be within 1 sec, otherwise trouble.
                        if (TimeDifference > 1 || TimeDifference < -1)
                        {
                            QByteArray WarningMessage;
                            WarningMessage.append("message 80 ");
                            WarningMessage.append(QString("%1").arg(TimeDifference));
                            WarningMessage.append(" sec\r\n");

                            emit Log("WARNING", QString("Time difference with %1 is %2 sec.\n\r").arg(ClientIP).arg(TimeDifference));

                            SendTcpData(WarningMessage);
                        }
                    }

                }


                else if (CurrentCommand == "clear_buffer")
                {
                    SXValid = false;                        //Stop sending records from previous file.
                    CurrentRecordIndex = 0;
                    emit ClientCommand(CurrentCommand);     //Tell the reader to clear buffers.
                }


                else if (CurrentCommand == "exit")
                {
                    TcpDataSocket.disconnectFromHost();
                    quit();
                }


                else if (CurrentCommand.startsWith("Sdt"))
                {
                    if (!SystemSettings->isUSBDevicePresent)
                    {
                        emit Log("ERROR", "Can not send records. USB Storage not present.\n\r");
                        emit Log("", "\n\r");

                        ClientData_buffer.clear();
                        CommandsList.clear();
                        return;
                    }

                    CurrentCommand.remove(0, 4);
                    StartRecordDateTime = QDateTime::fromString(QString(CurrentCommand), "dd.MM.yyyy hh:mm:ss.zzz");

                    if (StartRecordDateTime != LastCommandDateTime) // Filter the command if same date time is requested again within 30 sec.
                    {
                        LastCommandDateTime = StartRecordDateTime;
                        LastCommandDateTimeResetTimer.start();

                        if(StartRecordDateTime.isValid() && !StartRecordDateTime.isNull())
                        {
                            if (Client == TelnetDataClient && SystemSettings->DataOneApplicationSettings.EnableWriteDataLog)
                                FilePosition = SystemSettings->GetDataTimePosition(StartRecordDateTime);
                            else if (Client == TelnetFilteredClient && SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
                                FilePosition = SystemSettings->GetFilteredTimePosition(StartRecordDateTime);
                            else
                            {
                                emit Log("ERROR", "Can not send records. Log writing disabled.\n\r");
                                emit Log("", "\n\r");

                                ClientData_buffer.clear();
                                CommandsList.clear();
                                return;
                            }

                            if (FilePosition > -1)
                            {
                                SdtValid = true;
                                TcpDataSocket.flush();      // Flush all pending data in socket buffer.
                                FileChunkReadTimer.start(); // Start timer to read and send records to timing server.

                                emit Log("ACTION", QString("Sending records from time position %1 \n\r").arg(StartRecordDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
                                //emit Log("ACTION", QString("File position = %1 \n\r").arg(FilePosition));
                                emit Log("", "\n\r");
                            }
                            else
                            {
                                emit Log("ERROR", QString("Can not send records from time position %1 \n\r").arg(StartRecordDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
                                emit Log("", "\n\r");
                            }

                        }
                        else
                            emit Log("ERROR", QString("Invalid time position %1 requested.\n\r").arg(StartRecordDateTime.toString("dd.MM.yyyy hh:mm:ss.zzz")));
                        emit Log("", "\n\r");
                    }
                    else
                    {
                        emit Log("ERROR", QString("Last Sdt command repeated within 30 seconds... ignoring. \n\r"));
                        emit Log("", "\n\r");
                    }
                }


                else if (CurrentCommand.startsWith("S"))
                {
                    if (CurrentCommand == "S")
                    {
                        emit Log("ERROR", "Illegal command 'S'.\n\r");
                        emit Log("", "\n\r");

                        ClientData_buffer.clear();
                        CommandsList.clear();
                        return;
                    }

                    if (!SystemSettings->isUSBDevicePresent)
                    {
                        emit Log("ERROR", "Can not send records. USB Storage not present.\n\r");
                        emit Log("", "\n\r");

                        ClientData_buffer.clear();
                        CommandsList.clear();
                        return;
                    }

                    CurrentCommand.remove(0, 1);
                    StartRecordIndex = CurrentCommand.toInt();

                    if (StartRecordIndex != LastCommandIndex) // Filter the command if same record index is requested again within 30 sec.
                    {
                        LastCommandIndex = StartRecordIndex;
                        LastCommandIndexResetTimer.start();

                        if(StartRecordIndex > 0 && StartRecordIndex <= CurrentRecordIndex)
                        {
                            if (Client == TelnetDataClient && SystemSettings->DataOneApplicationSettings.EnableWriteDataLog)
                                FilePosition = SystemSettings->GetDataPosition(StartRecordIndex - (StartRecordIndex % 1000));
                            else if (Client == TelnetFilteredClient && SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
                                FilePosition = SystemSettings->GetFilteredPosition(StartRecordIndex - (StartRecordIndex % 1000));
                            else
                            {
                                emit Log("ERROR", "Can not send records. Log writing disabled.\n\r");
                                emit Log("", "\n\r");

                                ClientData_buffer.clear();
                                CommandsList.clear();
                                return;
                            }

                            if (FilePosition > -1)
                            {
                                SXValid = true;
                                TcpDataSocket.flush();      // Flush all pending data in socket buffer.
                                FileChunkReadTimer.start(); // Start timer to read and send records to timing server.

                                emit Log("ACTION", QString("Sending records from index position %1 (seek: %2) \n\r").arg((int) StartRecordIndex).arg(FilePosition));
                                emit Log("", "\n\r");
                            }
                            else
                            {
                                emit Log("ERROR", QString("Can not send records from index position %1 \n\r").arg((int) StartRecordIndex));
                                emit Log("", "\n\r");
                            }

                        }
                        else
                            emit Log("ERROR", QString("Invalid index position %1 requested.\n\r").arg((int) StartRecordIndex));
                            emit Log("", "\n\r");
                    }
                    else
                    {
                        if (StartRecordIndex == 0)
                        {
                            emit Log("ERROR", QString("No record found at index position 0. Try sending S1.\n\r"));
                            emit Log("", "\n\r");
                        }
                        else
                        {
                            emit Log("ERROR", QString("Last SX command repeated within 30 seconds... ignoring. \n\r"));
                            emit Log("", "\n\r");
                        }
                    }
                }

                else if (CurrentCommand == "get_d1_version")
                {
                    QByteArray D1Version;
                    D1Version.append("message 0 ");
                    D1Version.append(SystemSettings->DataOneApplicationSettings.AppVersion);
                    D1Version.append("\r\n");

                    emit Log("ACTION", QString("Sending DataOne Version: %1 \n\r").arg(SystemSettings->DataOneApplicationSettings.AppVersion));
                    emit Log("", "\n\r");

                    SendTcpData(D1Version);
                }

                else if (CurrentCommand == "get_log_files_dir")
                {
                    if (SystemSettings->isUSBDevicePresent)
                    {
                        QDir LogFilesDir;

                        if (Client == TelnetDataClient)
                            LogFilesDir.setPath(SystemSettings->DataFolderPath);
                        else if (Client == TelnetFilteredClient)
                            LogFilesDir.setPath(SystemSettings->FilteredFolderPath);

                        QFileInfoList DirectoryContents = LogFilesDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name);

                        if (DirectoryContents.size() > 1)
                        {
                            QByteArray LogFiles;

                            emit Log("ACTION", QString("Sending log files.\n\r"));
                            emit Log("", "\n\r");

                            for (int i = 0; i < DirectoryContents.size(); i++)
                            {
                                if (DirectoryContents.at(i).fileName() != "footprint") // Do not show footprint file.
                                {
                                    double FileSize = DirectoryContents.at(i).size() / 1024.0;
                                    FileSize *= 1000.0;
                                    FileSize = floor(FileSize);
                                    FileSize /= 1000.0;

                                    QString FileEntry = QString("message 1 %1 (%2 KB)\r\n").arg(DirectoryContents.at(i).fileName()).arg(FileSize, 0, 'f', 3);
                                    LogFiles.append(FileEntry);
                                }
                            }

                            if (!LogFiles.isEmpty()) SendTcpData(LogFiles); // Send directory list.
                            emit Log("", "\n\r");
                        }
                        else
                        {
                            emit Log("ACTION", QString("Log folder empty.\n\r"));
                            emit Log("", "\n\r");
                        }
                    }
                }

                else if (CurrentCommand.startsWith("get_log_file"))
                {
                    QList<QByteArray> CommandSplit = CurrentCommand.split(' ');
                    if (CommandSplit.size() == 2)
                    {
                        if (!CommandSplit.at(1).isEmpty())
                        {
                            if (Client == TelnetDataClient && SystemSettings->DataOneApplicationSettings.EnableWriteDataLog)
                                RecordFile.setFileName(SystemSettings->DataFolderPath + CommandSplit.at(1));
                            else if (Client == TelnetFilteredClient && SystemSettings->DataOneApplicationSettings.EnableWriteFilteredLog)
                                RecordFile.setFileName(SystemSettings->FilteredFolderPath + CommandSplit.at(1));
                            else
                            {
                                emit Log("ERROR", "Can not send records. Log writing disabled.\n\r");
                                emit Log("", "\n\r");

                                ClientData_buffer.clear();
                                CommandsList.clear();
                                return;
                            }

                            if (!RecordFile.exists())
                            {
                                emit Log("ERROR", "Can not send file. Requested file does not exist.\n\r");
                                emit Log("", "\n\r");

                                ClientData_buffer.clear();
                                CommandsList.clear();
                                return;
                            }
                        }
                        else
                        {
                            emit Log("ERROR", "Can not send file. Missing file name parameter.\n\r");
                            emit Log("", "\n\r");

                            ClientData_buffer.clear();
                            CommandsList.clear();
                            return;
                        }
                    }
                    else
                    {
                        emit Log("ERROR", "Can not send file. Missing file name parameter.\n\r");
                        emit Log("", "\n\r");

                        ClientData_buffer.clear();
                        CommandsList.clear();
                        return;
                    }


                    if (!SystemSettings->isUSBDevicePresent)
                    {
                        emit Log("ERROR", "Can not send records. USB Storage not present.\n\r");
                        emit Log("", "\n\r");

                        ClientData_buffer.clear();
                        CommandsList.clear();
                        return;
                    }

                    emit Log("ACTION", QString("Sending log file: %1\n\r").arg(RecordFile.fileName()));
                    emit Log("", "\n\r");

                    SXValid = false;
                    SendCustomFile = true;
                    FilePosition = 0;
                    TcpDataSocket.flush();      // Flush all pending data in socket buffer.
                    FileChunkReadTimer.start(); // Start timer to read and send records to timing server.

                }

                else if (CurrentCommand == "get_date_time")
                {
                    QByteArray CurrentDateTime;
                    CurrentDateTime.append("message 0 ");
                    CurrentDateTime.append(SystemSettings->GetCurrentDateTimeString());
                    CurrentDateTime.append("\r\n");

                    emit Log("ACTION", QString("Sending current Date and Time: %1 \n\r").arg(SystemSettings->GetCurrentDateTimeString()));
                    emit Log("", "\n\r");

                    SendTcpData(CurrentDateTime);
                }

                else if (CurrentCommand == "get_frequency")
                {
                    QByteArray FrequencyID;
                    FrequencyID.append("message 0 ");
                    FrequencyID.append(SystemSettings->DataOneDeviceSettings.Frequency);
                    FrequencyID.append("\r\n");

                    emit Log("ACTION", QString("Sending current frequency: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Frequency));
                    emit Log("", "\n\r");

                    SendTcpData(FrequencyID);
                }

                else if (CurrentCommand == "get_reader_mode")
                {
                    QByteArray ReaderMode;
                    ReaderMode.append("message 0 ");
                    ReaderMode.append(SystemSettings->DataOneDeviceSettings.Reader_Mode);
                    ReaderMode.append("\r\n");

                    emit Log("ACTION", QString("Sending Reader Mode: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Reader_Mode));
                    emit Log("", "\n\r");

                    SendTcpData(ReaderMode);
                }

                else if (CurrentCommand == "get_search_mode")
                {
                    QByteArray SearchMode;
                    SearchMode.append("message 0 ");
                    SearchMode.append(SystemSettings->DataOneDeviceSettings.Search_Mode);
                    SearchMode.append("\r\n");

                    emit Log("ACTION", QString("Sending Search Mode: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Search_Mode));
                    emit Log("", "\n\r");

                    SendTcpData(SearchMode);
                }

                else if (CurrentCommand == "get_session")
                {
                    QByteArray Session;
                    Session.append("message 0 ");
                    Session.append(QString("%1").arg(SystemSettings->DataOneDeviceSettings.Session));
                    Session.append("\r\n");

                    emit Log("ACTION", QString("Sending Session: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Session));
                    SendTcpData(Session);
                }

                else if (CurrentCommand == "get_tag_volume")
                {
                    QByteArray TagVolume;
                    TagVolume.append("message 0 ");
                    TagVolume.append(SystemSettings->DataOneDeviceSettings.Tag_Volume);
                    TagVolume.append("\r\n");

                    emit Log("ACTION", QString("Sending Tag Volume: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Tag_Volume));
                    emit Log("", "\n\r");

                    SendTcpData(TagVolume);
                }

                else if (CurrentCommand == "get_antennas")
                {
                    QByteArray Antennas;
                    Antennas.append("message 0 ");
                    Antennas.append(SystemSettings->DataOneDeviceSettings.Antennas);
                    Antennas.append("\r\n");

                    emit Log("ACTION", QString("Sending Antenna Settings: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Antennas));
                    emit Log("", "\n\r");

                    SendTcpData(Antennas);
                }

                else if (CurrentCommand == "get_beep_duration")
                {
                    QByteArray BeepDuration;
                    BeepDuration.append("message 0 ");
                    BeepDuration.append(QString("%1").arg(SystemSettings->DataOneDeviceSettings.Beep_Duration));
                    BeepDuration.append("\r\n");

                    emit Log("ACTION", QString("Sending Beep Interval : %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Beep_Duration));
                    emit Log("", "\n\r");

                    SendTcpData(BeepDuration);
                }

                else if (CurrentCommand == "get_beep")
                {
                    QByteArray BeepStatus;
                    BeepStatus.append("message 0 ");
                    BeepStatus.append(SystemSettings->DataOneDeviceSettings.Beep);
                    BeepStatus.append("\r\n");

                    emit Log("ACTION", QString("Sending Beep status: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Beep));
                    emit Log("", "\n\r");

                    SendTcpData(BeepStatus);
                }

                else if (CurrentCommand == "get_reader_no")
                {
                    QByteArray ReaderNumber;
                    ReaderNumber.append("message 0 ");
                    ReaderNumber.append(QString("%1").arg(SystemSettings->DataOneDeviceSettings.Reader_Number));
                    ReaderNumber.append("\r\n");

                    emit Log("ACTION", QString("Sending Reader Number: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.Reader_Number));
                    emit Log("", "\n\r");

                    SendTcpData(ReaderNumber);
                }

                else if (CurrentCommand == "get_timepoint_desc")
                {
                    QByteArray TimePointDesc;
                    TimePointDesc.append("message 0 ");
                    TimePointDesc.append(SystemSettings->DataOneDeviceSettings.TimePointDesc);
                    TimePointDesc.append("\r\n");

                    emit Log("ACTION", QString("Sending TimePointDesc: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.TimePointDesc));
                    emit Log("", "\n\r");

                    SendTcpData(TimePointDesc);
                }

                else if (CurrentCommand == "get_filter_length")
                {
                    QByteArray FilterLength;
                    FilterLength.append("message 0 ");
                    FilterLength.append(QString("%1").arg(SystemSettings->DataOneDeviceSettings.FilterLength));
                    FilterLength.append("\r\n");

                    emit Log("ACTION", QString("Sending Filter Length: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.FilterLength));
                    emit Log("", "\n\r");

                    SendTcpData(FilterLength);
                }

                else if (CurrentCommand == "get_filter_drift")
                {
                    QByteArray FilterDrift;
                    FilterDrift.append("message 0 ");
                    FilterDrift.append(QString("%1").arg(SystemSettings->DataOneDeviceSettings.FilterDrift));
                    FilterDrift.append("\r\n");

                    emit Log("ACTION", QString("Sending Filter Drift: %1 \n\r").arg(SystemSettings->DataOneDeviceSettings.FilterDrift));
                    emit Log("", "\n\r");

                    SendTcpData(FilterDrift);
                }

                else if (CurrentCommand == "get_antennas_connected")
                {
                    QByteArray AntennasStateByteArray;
                    AntennasStateByteArray.append("message 0 ");
                    AntennasStateByteArray.append(QString("%1").arg(AntennaState));
                    AntennasStateByteArray.append("\r\n");

                    emit Log("ACTION", QString("Sending antennas state: %1\n\r").arg(AntennaState));
                    emit Log("", "\n\r");

                    SendTcpData(AntennasStateByteArray);
                }

                else if (CurrentCommand == "get_readerinfos")
                {
                    //Answer:  |get_timepoint_desc|get_frequency|get_antennas_connected|get_filter_length|get_date_time|readin on/off|record counter|

                    QByteArray ReaderInfos;
                    ReaderInfos.append("message 0 readerinfos ");
                    ReaderInfos.append("|");
                    ReaderInfos.append(SystemSettings->DataOneDeviceSettings.TimePointDesc);
                    ReaderInfos.append("|");
                    ReaderInfos.append(SystemSettings->DataOneDeviceSettings.Frequency);
                    ReaderInfos.append("|");
                    ReaderInfos.append(AntennaState);
                    ReaderInfos.append("|");
                    ReaderInfos.append(QString("%1").arg(SystemSettings->DataOneDeviceSettings.FilterLength));
                    ReaderInfos.append("|");
                    ReaderInfos.append(SystemSettings->GetCurrentDateTimeString());
                    ReaderInfos.append("|");
                    ReaderInfos.append(SystemSettings->GetReadingStatusString());
                    ReaderInfos.append("|");
                    ReaderInfos.append(QString("%1").arg(CurrentRecordIndex));
                    ReaderInfos.append("|");
                    ReaderInfos.append("\r\n");

                    QString ReaderInfosString;
                    ReaderInfosString.append("|");
                    ReaderInfosString.append(SystemSettings->DataOneDeviceSettings.TimePointDesc);
                    ReaderInfosString.append("|");
                    ReaderInfosString.append(SystemSettings->DataOneDeviceSettings.Frequency);
                    ReaderInfosString.append("|");
                    ReaderInfosString.append(AntennaState);
                    ReaderInfosString.append("|");
                    ReaderInfosString.append(QString("%1").arg(SystemSettings->DataOneDeviceSettings.FilterLength));
                    ReaderInfosString.append("|");
                    ReaderInfosString.append(SystemSettings->GetCurrentDateTimeString());
                    ReaderInfosString.append("|");
                    ReaderInfosString.append(SystemSettings->GetReadingStatusString());
                    ReaderInfosString.append("|");
                    ReaderInfosString.append(QString("%1").arg(CurrentRecordIndex));
                    ReaderInfosString.append("|");

                    emit Log("ACTION", QString("Sending reader infos: %1\n\r").arg(ReaderInfosString));
                    emit Log("", "\n\r");

                    SendTcpData(ReaderInfos);
                }

                else if (CurrentCommand == "get_rospec")
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
                                XMLValid = false;
                                SendTcpData(RospecXMLLine); // Special case for one last line.
                            }

                            if (XMLValid)
                                SendTcpData(RospecXMLLine);                                            // Send line to client.
                        }

                        SendTcpData("\n\r\n");

                    }
                    else
                    {
                        emit Log("ERROR", "Failed to retrieve ROSPEC.\n\r");
                        emit Log("", "\n\r");
                    }
                }

                else
                {
                    emit ClientCommand(CurrentCommand);
                }
            }

            ClientData_buffer.clear();  // Clear buffer to make space for next command.
            CommandsList.clear();
        }
    }
}



//PRIVATE SLOT
void TcpTelnetClient::ReadChunkFromFile()
{
    if (SdtValid)
    {
        //emit Log("DEBUG", QString("Executing: Sdt\n\r"));

        // Set filename to current log file.
        if (Client == TelnetDataClient)
            RecordFile.setFileName(SystemSettings->CurrentDataLogFileName);
        else if (Client == TelnetFilteredClient)
            RecordFile.setFileName(SystemSettings->CurrentFilteredLogFileName);

        //emit Log("DEBUG", QString("Opening file: %1\n\r").arg(RecordFile.fileName()));

        if (!RecordFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            emit Log("ERROR", QString("Can not open record file for reading.\n\r"));
            emit Log("", "\n\r");

            SdtValid = false;
            FilePosition = 0;
            FileChunkReadTimer.stop();
            return;
        }

        // Take the read pointer to where reading was left last time.
        RecordFile.seek(FilePosition);
        int RecordCount = 0;
        QString ProcessedDateTime;

        while (RecordCount++ < 500) // At more than 500 records at a time, the reader RAM is stressed due to cacheing.
        {
            QByteArray TagDataFromFile = RecordFile.readLine(); // Read 1 record.
            FilePosition = RecordFile.pos(); // Save read pointer position.

            // Extract record number of this record.
            QDateTime TagRecordTimeFromFile;
            TagRecordTimeFromFile = QDateTime::fromString(QString(TagDataFromFile.split(',').at(2)), "dd.MM.yyyy hh:mm:ss.zzz");
            ProcessedDateTime = TagRecordTimeFromFile.toString("dd.MM.yyyy hh:mm:ss.zzz");

            //emit Log("DEBUG", QString("ProcessedDateTime = %1 \n\r").arg(ProcessedDateTime));

            if (TagRecordTimeFromFile >= StartRecordDateTime)
            {
                TagDataFromFile.chop(1);
                TagDataFromFile.append("\r\n");
                SendTcpData(TagDataFromFile);
            }

            // Finish reading.
            if (RecordFile.atEnd())
            {
                SdtValid = false;
                FilePosition = 0;
                FileChunkReadTimer.stop();
                break;
            }

        }
        //emit Log(QString("Processed records upto : %1\n\r").arg(ProcessedDateTime)); // Debug.
        RecordFile.close();
    }

    if (SXValid)
    {
        //emit Log("DEBUG", QString("Executing: SX\n\r"));

        // Set filename to current log file.
        if (Client == TelnetDataClient)
            RecordFile.setFileName(SystemSettings->CurrentDataLogFileName);
        else if (Client == TelnetFilteredClient)
            RecordFile.setFileName(SystemSettings->CurrentFilteredLogFileName);

        //emit Log("DEBUG", QString("Opening file: %1\n\r").arg(RecordFile.fileName()));

        if (!RecordFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            emit Log("ERROR", QString("Can not open record file for reading.\n\r"));
            emit Log("", "\n\r");

            SXValid = false;
            FilePosition = 0;
            FileChunkReadTimer.stop();
            return;
        }

        // Take the read pointer to where reading was left last time.
        RecordFile.seek(FilePosition);
        int RecordCount = 0;
        int ProcessedIndex = 0;

        while (RecordCount++ < 500) // At more than 500 records at a time, the reader RAM is stressed due to cacheing.
        {
            QByteArray TagDataFromFile = RecordFile.readLine(); // Read 1 record.
            FilePosition = RecordFile.pos(); // Save read pointer position.

            // Extract record number of this record.
            quint64 TagRecordNumberFromFile;
            TagRecordNumberFromFile = (quint64) TagDataFromFile.split(',').at(0).toInt();
            ProcessedIndex = (int) TagRecordNumberFromFile;

            if (TagRecordNumberFromFile >= StartRecordIndex && TagRecordNumberFromFile <= CurrentRecordIndex)
            {
                TagDataFromFile.chop(1);
                TagDataFromFile.append("\r\n");
                SendTcpData(TagDataFromFile);
            }

            // Finish reading.
            if ((TagRecordNumberFromFile == CurrentRecordIndex) || (StartRecordIndex > CurrentRecordIndex))
            {
                SXValid = false;
                FilePosition = 0;
                FileChunkReadTimer.stop();
                break;
            }

        }
        //emit Log(QString("Processed records upto : %1\n\r").arg(ProcessedIndex)); // Debug.
        RecordFile.close();
    }

    if (SendCustomFile)
    {
        //emit Log("DEBUG", QString("Executing: Custom file send.\n\r"));

        //emit Log("DEBUG", QString("Opening file: %1\n\r").arg(RecordFile.fileName()));

        if (RecordFile.size() == 0)
        {
            emit Log("ERROR", QString("Can not open record file for reading.  File size is 0.\n\r"));
            emit Log("", "\n\r");

            SendCustomFile = false;
            FilePosition = 0;
            FileChunkReadTimer.stop();
            return;
        }

        if (!RecordFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            emit Log("ERROR", QString("Can not open record file for reading. I/O error.\n\r"));
            emit Log("", "\n\r");

            SendCustomFile = false;
            FilePosition = 0;
            FileChunkReadTimer.stop();
            return;
        }

        // Take the read pointer to where reading was left last time.
        RecordFile.seek(FilePosition);
        int RecordCount = 0;
        int ProcessedIndex = 0;

        while (RecordCount++ < 500 && !RecordFile.atEnd()) // At more than 500 records at a time, the reader RAM is stressed due to cacheing.
        {
            QByteArray TagDataFromFile = RecordFile.readLine(); // Read 1 record.
            FilePosition = RecordFile.pos(); // Save read pointer position.

            if (!TagDataFromFile.isEmpty())
            {
                // Extract record number of this record.
                quint64 TagRecordNumberFromFile;
                TagRecordNumberFromFile = (quint64) TagDataFromFile.split(',').at(0).toInt();
                ProcessedIndex = (int) TagRecordNumberFromFile;

                TagDataFromFile.chop(1);
                TagDataFromFile.append("\r\n");
                SendTcpData("message 2 " + TagDataFromFile);
            }
        }

        // Finish reading.
        if (RecordFile.atEnd())
        {
            SendCustomFile = false;
            FilePosition = 0;
            FileChunkReadTimer.stop();
        }

        //emit Log(QString("Processed records upto : %1\n\r").arg(ProcessedIndex)); // Debug.
        RecordFile.close();
    }
}

//PRIVATE SLOT
void TcpTelnetClient::CheckPortStatus()
{
    // Tear down connection if some socket fault has happened.
    if (!TcpDataSocket.isValid() || !TcpDataSocket.isOpen())
    {
        TcpDataSocket.abort();
    }
}


//PRIVATE SLOT
void TcpTelnetClient::ResetLastCommandIndex()
{
    LastCommandIndex = 0;
}

//PRIVATE SLOT
void TcpTelnetClient::ResetLastCommandDateTime()
{
    LastCommandDateTime.setDate(QDate(1999, 01, 01));
    LastCommandDateTime.setTime(QTime(00, 00, 00, 000));
}
