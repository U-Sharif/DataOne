#ifndef WEBUPLOADER_H
#define WEBUPLOADER_H

#include <QThread>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QSslError>

#include <QFile>
#include <QStringList>
#include <QVariant>
#include <QTimer>

#include <QDebug>

#include "../Settings/settings.h"


struct BufferedMessage
{
    int MessageNumber;
    QDateTime MessageTime;
    QString MessageType;
    QString Message;
};


// This class uploads console log to a web server.
class WebUploader : public QThread
{
    Q_OBJECT
public:
    explicit WebUploader(QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

    void QueueMessage(int MessageNumber, QString MessageType, QString LogStatement); // Adds new log messages to buffer.

private:
    QList<BufferedMessage> MessageBuffer;   // List for buffering log messages, while internet is not available.

    // Network access manager for sending and receiving HTTP requests and responses.
    QNetworkAccessManager *NAM_LogUploader;
    QNetworkReply *LogServerReply;
    bool LastServerReplyFinished;

    int MessageCounter;                         // Used for sequencing of log upload to web.

    bool Post(BufferedMessage newMessage); // HTTP posts are done here.

protected:
    // Virtual protected function of QThread for launching the thread.
    // This thread will be launched from mainthread.cpp
    void run();
    
signals:
    void Log(QString, QString);                     // Send log to main thread.
    
public slots:
    void PostBufferedMessage(); // Post unsent messages.

    void LogServerReplyFinished(QNetworkReply* WebReply);   // Slot to capture the HTTP reply.
    void onError(QNetworkReply::NetworkError Code);         // Handle network and HTTP errors.
    void onNAMSslErrors(QNetworkReply* WebReply, const QList<QSslError> & SslErrors); //Handle HTTPS SSL errors.
    void onSlotSslErrors(const QList<QSslError> & SslErrors); //Handle HTTPS SSL errors.
    
};

#endif // WEBUPLOADER_H
