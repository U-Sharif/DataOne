/****************************************************************************
** Meta object code from reading C++ file 'tcpserverconnection.h'
**
** Created: Fri Jun 28 02:03:02 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TcpClient/tcpserverconnection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserverconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpServerConnection[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   21,   20,   20, 0x05,
      44,   20,   20,   20, 0x05,
      70,   20,   20,   20, 0x05,
      94,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,   21,   20,   20, 0x0a,
     153,   20,   20,   20, 0x0a,
     180,   20,   20,   20, 0x0a,
     213,   20,   20,   20, 0x0a,
     240,   20,   20,   20, 0x0a,
     255,   20,   20,   20, 0x08,
     279,   20,   20,   20, 0x08,
     293,   20,   20,   20, 0x08,
     310,   20,   20,   20, 0x08,
     327,   20,   20,   20, 0x08,
     371,   20,   20,   20, 0x08,
     391,   20,   20,   20, 0x08,
     410,   20,   20,   20, 0x08,
     428,   20,   20,   20, 0x08,
     452,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpServerConnection[] = {
    "TcpServerConnection\0\0,\0Log(QString,QString)\0"
    "ServerCommand(QByteArray)\0"
    "TimingServerConnected()\0"
    "TimingServerDisconnected()\0"
    "SendTagData(QByteArray,quint64)\0"
    "SendStatusPing(QByteArray)\0"
    "SendBroadcastMessage(QByteArray)\0"
    "StoreAntennaState(QString)\0ClearBuffers()\0"
    "SendTcpData(QByteArray)\0onConnected()\0"
    "onDisconnected()\0onDataReceived()\0"
    "onSocketError(QAbstractSocket::SocketError)\0"
    "ReadChunkFromFile()\0DisconnectSocket()\0"
    "CheckPortStatus()\0ResetLastCommandIndex()\0"
    "ResetLastCommandDateTime()\0"
};

const QMetaObject TcpServerConnection::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TcpServerConnection,
      qt_meta_data_TcpServerConnection, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpServerConnection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpServerConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpServerConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServerConnection))
        return static_cast<void*>(const_cast< TcpServerConnection*>(this));
    return QThread::qt_metacast(_clname);
}

int TcpServerConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: ServerCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: TimingServerConnected(); break;
        case 3: TimingServerDisconnected(); break;
        case 4: SendTagData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 5: SendStatusPing((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: SendBroadcastMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: StoreAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: ClearBuffers(); break;
        case 9: SendTcpData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: onConnected(); break;
        case 11: onDisconnected(); break;
        case 12: onDataReceived(); break;
        case 13: onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 14: ReadChunkFromFile(); break;
        case 15: DisconnectSocket(); break;
        case 16: CheckPortStatus(); break;
        case 17: ResetLastCommandIndex(); break;
        case 18: ResetLastCommandDateTime(); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void TcpServerConnection::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServerConnection::ServerCommand(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServerConnection::TimingServerConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TcpServerConnection::TimingServerDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
