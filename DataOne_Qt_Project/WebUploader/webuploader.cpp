#include "webuploader.h"

//CONSTRUCTOR
WebUploader::WebUploader(QObject *parent) :
    QThread(parent)
{
    //Defaults.
    LastServerReplyFinished = true;
    MessageCounter = 1;

    // Initialize Network access manager for Log upload.
    NAM_LogUploader = new QNetworkAccessManager(this);
    connect(NAM_LogUploader, SIGNAL(finished(QNetworkReply*)), this, SLOT(LogServerReplyFinished(QNetworkReply*)));
    connect(NAM_LogUploader, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(onNAMSslErrors(QNetworkReply*,QList<QSslError>)));

}

//PROTECTED OVERRIDE FUNCTION
void WebUploader::run()
{
    // Setup a timer to upload buffered console messages.
    QTimer BufferUploadTimer;
    connect(&BufferUploadTimer, SIGNAL(timeout()), this, SLOT(PostBufferedMessage()));
    BufferUploadTimer.start(1000);

    // Start eventloop of new thread.
    exec();
}


//PUBLIC FUNCTION
void WebUploader::QueueMessage(int MessageNumber, QString MessageType, QString LogStatement)
{
    BufferedMessage newMessage;
    newMessage.MessageType = MessageType;
    newMessage.Message = LogStatement;
    newMessage.MessageNumber = MessageNumber;
    newMessage.MessageTime = SystemSettings->GetCurrentDateTime();

    MessageBuffer.append(newMessage);

    //qDebug() << "Message Queued.\n";
}



//PRIVATE FUNCTION
bool WebUploader::Post(BufferedMessage newMessage)
{
    if (SystemSettings->isInternetAvailable && LastServerReplyFinished)
    {
        QByteArray PostData;
        QUrl PostParameters;

        // Calculate message wait time in queue.
        int MessageWaitTime = abs(newMessage.MessageTime.secsTo(SystemSettings->GetCurrentDateTime()));

        PostParameters.addQueryItem("readerno", QString("%1").arg(SystemSettings->DataOneDeviceSettings.Reader_Number));
        PostParameters.addQueryItem("messagenum", QString("%1").arg(newMessage.MessageNumber));
        PostParameters.addQueryItem("messagetime", newMessage.MessageTime.toString("dd.MM.yyyy hh:mm:ss"));
        PostParameters.addQueryItem("messagewaittime", QString("%1").arg(MessageWaitTime));
        PostParameters.addQueryItem("messagetyp", newMessage.MessageType);
        PostParameters.addQueryItem("message", newMessage.Message);

        PostData = PostParameters.encodedQuery();

        QNetworkRequest LogPostRequest; // Http request object.
        LogPostRequest.setUrl(SystemSettings->WebUploadServerURL);
        LogPostRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QByteArray UserAgent("DataOne/");
        UserAgent.append(SystemSettings->DataOneApplicationSettings.AppVersion);
        LogPostRequest.setRawHeader("User-Agent", UserAgent);

        LogPostRequest.setHeader(QNetworkRequest::ContentLengthHeader, QVariant(PostData.size()).toString());


        LogServerReply = NAM_LogUploader->post(LogPostRequest, PostData);
        connect(LogServerReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
        connect(LogServerReply, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(onSlotSslErrors(QList<QSslError>)));

        LastServerReplyFinished = false;


        //qDebug() << "Post = " << LogPostRequest.url();
        //qDebug() << "readerno = " << QString("%1").arg(SystemSettings->DataOneDeviceSettings.Reader_Number);
        //qDebug() << "messagenum = " << QString("%1").arg(newMessage.MessageNumber);
        //qDebug() << "messagetime = " << newMessage.MessageTime.toString("dd.MM.yyyy hh:mm:ss");
        //qDebug() << "messagewaittime = " << QString("%1").arg(MessageWaitTime);
        //qDebug() << "messagetyp = " << newMessage.MessageType;
        //qDebug() << "message = " << newMessage.Message;
        //qDebug();

        return true;
    }
    else
        return false;
}


//PRIVATE SLOT
void WebUploader::PostBufferedMessage()
{
    if (SystemSettings->isInternetAvailable && LastServerReplyFinished)
    {
        if (!MessageBuffer.isEmpty())
        {
            BufferedMessage newMessage = MessageBuffer.takeFirst();

            if (!Post(newMessage))
                MessageBuffer.prepend(newMessage);

            //qDebug() << "Buffered message posted.\n";
        }
    }
}


//PRIVATE SLOT
void WebUploader::LogServerReplyFinished(QNetworkReply* WebReply)
{
    if (WebReply->isFinished())
    {
        //QFile HTTPDumpFile("/mnt/usbfs/usbsda1/HTTP_dump.html");

        //HTTPDumpFile.open(QIODevice::Append);
        //HTTPDumpFile.write(WebReply->readAll());
        //HTTPDumpFile.close();

        LastServerReplyFinished = true;
        WebReply->deleteLater();
    }
}

//PRIVATE SLOT
void WebUploader::onError(QNetworkReply::NetworkError Code)
{
    (void)(Code);

    LogServerReply->deleteLater();
}

//PRIVATE SLOT
void WebUploader::onNAMSslErrors(QNetworkReply *WebReply, const QList<QSslError> &SslErrors)
{
    for (int i = 0; i < SslErrors.size(); i++)
    {
        // Write entry on attached standard IO.
        printf("%s", SslErrors.at(i).errorString().toLocal8Bit().data());

        //emit Log("SSL ERROR", QString("%1\n\r").arg(SslErrors.at(i).errorString()));
    }

    WebReply->ignoreSslErrors();
}

//PRIVATE SLOT
void WebUploader::onSlotSslErrors(const QList<QSslError> &SslErrors)
{
    for (int i = 0; i < SslErrors.size(); i++)
    {
        // Write entry on attached standard IO.
        printf("%s", SslErrors.at(i).errorString().toLocal8Bit().data());

        //emit Log("SSL ERROR", QString("%1\n\r").arg(SslErrors.at(i).errorString()));
    }
}
