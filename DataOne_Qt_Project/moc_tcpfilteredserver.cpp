/****************************************************************************
** Meta object code from reading C++ file 'tcpfilteredserver.h'
**
** Created: Fri Jun 28 02:02:58 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TcpServer/tcpfilteredserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpfilteredserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpFilteredServer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   19,   18,   18, 0x05,
      42,   19,   18,   18, 0x05,
      78,   18,   18,   18, 0x05,
     104,   18,   18,   18, 0x05,
     131,   18,   18,   18, 0x05,
     164,   18,   18,   18, 0x05,
     182,   18,   18,   18, 0x05,
     203,   18,   18,   18, 0x05,
     217,   18,   18,   18, 0x05,
     245,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     263,   19,   18,   18, 0x0a,
     295,   18,   18,   18, 0x0a,
     318,   18,   18,   18, 0x0a,
     347,   18,   18,   18, 0x0a,
     373,   18,   18,   18, 0x0a,
     394,   18,   18,   18, 0x0a,
     409,   18,   18,   18, 0x0a,
     436,   18,   18,   18, 0x0a,
     447,   18,   18,   18, 0x08,
     480,   18,   18,   18, 0x08,
     513,   19,   18,   18, 0x08,
     549,   18,   18,   18, 0x08,
     584,   18,   18,   18, 0x08,
     597,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpFilteredServer[] = {
    "TcpFilteredServer\0\0,\0Log(QString,QString)\0"
    "NewTagAvailable(QByteArray,quint64)\0"
    "ClientCommand(QByteArray)\0"
    "SendStatusPing(QByteArray)\0"
    "SendBroadcastMessage(QByteArray)\0"
    "ClientConnected()\0ClientDisconnected()\0"
    "ClearBuffer()\0UpdateAntennaState(QString)\0"
    "DataOneShutdown()\0SendTagData(QByteArray,quint64)\0"
    "UpdateTemperature(int)\0"
    "UpdateBatteryVoltage(double)\0"
    "SendBroadcast(QByteArray)\0"
    "ReadingStarted(bool)\0ClearBuffers()\0"
    "StoreAntennaState(QString)\0Shutdown()\0"
    "IncrementConnectedClientsCount()\0"
    "DecrementConnectedClientsCount()\0"
    "LogFromChildThread(QString,QString)\0"
    "CommandFromChildThread(QByteArray)\0"
    "SendStatus()\0CheckServerStatus()\0"
};

const QMetaObject TcpFilteredServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TcpFilteredServer,
      qt_meta_data_TcpFilteredServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpFilteredServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpFilteredServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpFilteredServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpFilteredServer))
        return static_cast<void*>(const_cast< TcpFilteredServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int TcpFilteredServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: NewTagAvailable((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 2: ClientCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: SendStatusPing((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: SendBroadcastMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: ClientConnected(); break;
        case 6: ClientDisconnected(); break;
        case 7: ClearBuffer(); break;
        case 8: UpdateAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: DataOneShutdown(); break;
        case 10: SendTagData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 11: UpdateTemperature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: UpdateBatteryVoltage((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: SendBroadcast((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 14: ReadingStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: ClearBuffers(); break;
        case 16: StoreAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: Shutdown(); break;
        case 18: IncrementConnectedClientsCount(); break;
        case 19: DecrementConnectedClientsCount(); break;
        case 20: LogFromChildThread((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: CommandFromChildThread((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 22: SendStatus(); break;
        case 23: CheckServerStatus(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void TcpFilteredServer::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpFilteredServer::NewTagAvailable(QByteArray _t1, quint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpFilteredServer::ClientCommand(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpFilteredServer::SendStatusPing(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpFilteredServer::SendBroadcastMessage(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpFilteredServer::ClientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void TcpFilteredServer::ClientDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void TcpFilteredServer::ClearBuffer()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void TcpFilteredServer::UpdateAntennaState(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TcpFilteredServer::DataOneShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
