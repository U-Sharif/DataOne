/****************************************************************************
** Meta object code from reading C++ file 'tcptelnetclient.h'
**
** Created: Fri Jun 28 02:03:01 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TcpClient/tcptelnetclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcptelnetclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpTelnetClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   17,   16,   16, 0x05,
      40,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   17,   16,   16, 0x0a,
      98,   16,   16,   16, 0x0a,
     125,   16,   16,   16, 0x0a,
     158,   16,   16,   16, 0x0a,
     185,   16,   16,   16, 0x0a,
     200,   16,   16,   16, 0x08,
     224,   16,   16,   16, 0x08,
     238,   16,   16,   16, 0x08,
     255,   16,   16,   16, 0x08,
     272,   16,   16,   16, 0x08,
     292,   16,   16,   16, 0x08,
     310,   16,   16,   16, 0x08,
     334,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpTelnetClient[] = {
    "TcpTelnetClient\0\0,\0Log(QString,QString)\0"
    "ClientCommand(QByteArray)\0"
    "SendTagData(QByteArray,quint64)\0"
    "SendStatusPing(QByteArray)\0"
    "SendBroadcastMessage(QByteArray)\0"
    "StoreAntennaState(QString)\0ClearBuffers()\0"
    "SendTcpData(QByteArray)\0onConnected()\0"
    "onDisconnected()\0onDataReceived()\0"
    "ReadChunkFromFile()\0CheckPortStatus()\0"
    "ResetLastCommandIndex()\0"
    "ResetLastCommandDateTime()\0"
};

const QMetaObject TcpTelnetClient::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TcpTelnetClient,
      qt_meta_data_TcpTelnetClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpTelnetClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpTelnetClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpTelnetClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpTelnetClient))
        return static_cast<void*>(const_cast< TcpTelnetClient*>(this));
    return QThread::qt_metacast(_clname);
}

int TcpTelnetClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: ClientCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: SendTagData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 3: SendStatusPing((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: SendBroadcastMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: StoreAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: ClearBuffers(); break;
        case 7: SendTcpData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: onConnected(); break;
        case 9: onDisconnected(); break;
        case 10: onDataReceived(); break;
        case 11: ReadChunkFromFile(); break;
        case 12: CheckPortStatus(); break;
        case 13: ResetLastCommandIndex(); break;
        case 14: ResetLastCommandDateTime(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TcpTelnetClient::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpTelnetClient::ClientCommand(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
