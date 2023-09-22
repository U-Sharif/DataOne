/****************************************************************************
** Meta object code from reading C++ file 'mainthread.h'
**
** Created: Fri Jun 28 02:02:55 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,
      72,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,   11,   11,   11, 0x0a,
     162,  137,   11,   11, 0x08,
     212,  199,   11,   11, 0x08,
     235,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainThread[] = {
    "MainThread\0\0WriteLogToDisk(QByteArray)\0"
    "SendBroadcastMessage(QByteArray)\0"
    "SendLogToRemoteConsoles(QByteArray)\0"
    "SendApplicationRunningTime()\0"
    "MessageType,LogStatement\0"
    "WriteApplicationLog(QString,QString)\0"
    "LogStatement\0SendBroadcast(QString)\0"
    "UpdateApplicationRunningTime()\0"
};

const QMetaObject MainThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainThread,
      qt_meta_data_MainThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainThread))
        return static_cast<void*>(const_cast< MainThread*>(this));
    return QObject::qt_metacast(_clname);
}

int MainThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: WriteLogToDisk((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: SendBroadcastMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: SendLogToRemoteConsoles((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: SendApplicationRunningTime(); break;
        case 4: WriteApplicationLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: SendBroadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: UpdateApplicationRunningTime(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainThread::WriteLogToDisk(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainThread::SendBroadcastMessage(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainThread::SendLogToRemoteConsoles(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
