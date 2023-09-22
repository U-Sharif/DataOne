/****************************************************************************
** Meta object code from reading C++ file 'tcpconsoleclient.h'
**
** Created: Fri Jun 28 02:02:58 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TcpClient/tcpconsoleclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpconsoleclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpConsoleClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   18,   17,   17, 0x05,
      41,   17,   17,   17, 0x05,
      68,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   17,   17,   17, 0x0a,
     113,   17,   17,   17, 0x0a,
     140,   17,   17,   17, 0x08,
     157,   17,   17,   17, 0x08,
     174,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpConsoleClient[] = {
    "TcpConsoleClient\0\0,\0Log(QString,QString)\0"
    "ConsoleCommand(QByteArray)\0"
    "Command_GetRunningTime()\0SendLog(QByteArray)\0"
    "StoreAntennaState(QString)\0onDisconnected()\0"
    "onDataReceived()\0CheckPortStatus()\0"
};

const QMetaObject TcpConsoleClient::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TcpConsoleClient,
      qt_meta_data_TcpConsoleClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpConsoleClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpConsoleClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpConsoleClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpConsoleClient))
        return static_cast<void*>(const_cast< TcpConsoleClient*>(this));
    return QThread::qt_metacast(_clname);
}

int TcpConsoleClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: ConsoleCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: Command_GetRunningTime(); break;
        case 3: SendLog((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: StoreAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: onDisconnected(); break;
        case 6: onDataReceived(); break;
        case 7: CheckPortStatus(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TcpConsoleClient::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpConsoleClient::ConsoleCommand(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpConsoleClient::Command_GetRunningTime()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
