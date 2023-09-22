/****************************************************************************
** Meta object code from reading C++ file 'tcpconsoleserver.h'
**
** Created: Fri Jun 28 02:02:59 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TcpServer/tcpconsoleserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpconsoleserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpConsoleServer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   18,   17,   17, 0x05,
      41,   17,   17,   17, 0x05,
      69,   17,   17,   17, 0x05,
      94,   17,   17,   17, 0x05,
     122,   17,   17,   17, 0x05,
     148,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     173,  166,   17,   17, 0x0a,
     196,   17,   17,   17, 0x0a,
     225,   17,   17,   17, 0x0a,
     252,   17,   17,   17, 0x0a,
     263,   17,   17,   17, 0x08,
     296,   18,   17,   17, 0x08,
     332,   17,   17,   17, 0x08,
     352,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpConsoleServer[] = {
    "TcpConsoleServer\0\0,\0Log(QString,QString)\0"
    "NewLogAvailable(QByteArray)\0"
    "Command_GetRunningTime()\0"
    "UpdateAntennaState(QString)\0"
    "ClientCommand(QByteArray)\0DataOneShutdown()\0"
    "newLog\0SendNewLog(QByteArray)\0"
    "SendApplicationRunningTime()\0"
    "StoreAntennaState(QString)\0Shutdown()\0"
    "DecrementConnectedClientsCount()\0"
    "LogFromChildThread(QString,QString)\0"
    "CheckServerStatus()\0"
    "CommandFromChildThread(QByteArray)\0"
};

const QMetaObject TcpConsoleServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TcpConsoleServer,
      qt_meta_data_TcpConsoleServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpConsoleServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpConsoleServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpConsoleServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpConsoleServer))
        return static_cast<void*>(const_cast< TcpConsoleServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int TcpConsoleServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: NewLogAvailable((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: Command_GetRunningTime(); break;
        case 3: UpdateAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: ClientCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: DataOneShutdown(); break;
        case 6: SendNewLog((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: SendApplicationRunningTime(); break;
        case 8: StoreAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: Shutdown(); break;
        case 10: DecrementConnectedClientsCount(); break;
        case 11: LogFromChildThread((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: CheckServerStatus(); break;
        case 13: CommandFromChildThread((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void TcpConsoleServer::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpConsoleServer::NewLogAvailable(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpConsoleServer::Command_GetRunningTime()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TcpConsoleServer::UpdateAntennaState(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpConsoleServer::ClientCommand(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpConsoleServer::DataOneShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
