/****************************************************************************
** Meta object code from reading C++ file 'webuploader.h'
**
** Created: Fri Jun 28 02:03:03 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "WebUploader/webuploader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webuploader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebUploader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   12,   12,   12, 0x0a,
      67,   58,   12,   12, 0x0a,
     111,  106,   12,   12, 0x0a,
     167,  148,   12,   12, 0x0a,
     225,  215,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WebUploader[] = {
    "WebUploader\0\0,\0Log(QString,QString)\0"
    "PostBufferedMessage()\0WebReply\0"
    "LogServerReplyFinished(QNetworkReply*)\0"
    "Code\0onError(QNetworkReply::NetworkError)\0"
    "WebReply,SslErrors\0"
    "onNAMSslErrors(QNetworkReply*,QList<QSslError>)\0"
    "SslErrors\0onSlotSslErrors(QList<QSslError>)\0"
};

const QMetaObject WebUploader::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_WebUploader,
      qt_meta_data_WebUploader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebUploader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebUploader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebUploader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebUploader))
        return static_cast<void*>(const_cast< WebUploader*>(this));
    return QThread::qt_metacast(_clname);
}

int WebUploader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: PostBufferedMessage(); break;
        case 2: LogServerReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: onError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 4: onNAMSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        case 5: onSlotSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WebUploader::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
