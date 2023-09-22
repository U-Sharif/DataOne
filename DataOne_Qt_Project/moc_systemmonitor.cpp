/****************************************************************************
** Meta object code from reading C++ file 'systemmonitor.h'
**
** Created: Fri Jun 28 02:02:56 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Reader/systemmonitor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemmonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SystemMonitor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,
      38,   14,   14,   14, 0x05,
      69,   57,   14,   14, 0x05,
      93,   14,   14,   14, 0x05,
     112,   14,   14,   14, 0x05,
     134,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     153,   14,   14,   14, 0x08,
     176,   14,   14,   14, 0x08,
     202,   14,   14,   14, 0x08,
     220,   14,   14,   14, 0x08,
     240,   14,   14,   14, 0x08,
     274,   14,   14,   14, 0x08,
     288,   14,   14,   14, 0x08,
     331,  322,   14,   14, 0x08,
     379,  374,   14,   14, 0x08,
     416,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SystemMonitor[] = {
    "SystemMonitor\0\0,\0Log(QString,QString)\0"
    "Broadcast(QString)\0ActionAlert\0"
    "USBMemoryUnplugged(int)\0USBMemoryPlugged()\0"
    "NetworkNotAvailable()\0NetworkAvailable()\0"
    "CheckCurrentCPUUsage()\0CheckCurrentMemoryUsage()\0"
    "CheckUsbPresent()\0CheckUsbFreeSpace()\0"
    "CheckInternetConnectivityByPING()\0"
    "OnPingEnded()\0CheckInternetConnectivityByHTTP()\0"
    "WebReply\0InternetCheckReplyFinished(QNetworkReply*)\0"
    "Code\0onError(QNetworkReply::NetworkError)\0"
    "UpdateDateTimeFromNTP()\0"
};

const QMetaObject SystemMonitor::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SystemMonitor,
      qt_meta_data_SystemMonitor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SystemMonitor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SystemMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SystemMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SystemMonitor))
        return static_cast<void*>(const_cast< SystemMonitor*>(this));
    return QThread::qt_metacast(_clname);
}

int SystemMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: Broadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: USBMemoryUnplugged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: USBMemoryPlugged(); break;
        case 4: NetworkNotAvailable(); break;
        case 5: NetworkAvailable(); break;
        case 6: CheckCurrentCPUUsage(); break;
        case 7: CheckCurrentMemoryUsage(); break;
        case 8: CheckUsbPresent(); break;
        case 9: CheckUsbFreeSpace(); break;
        case 10: CheckInternetConnectivityByPING(); break;
        case 11: OnPingEnded(); break;
        case 12: CheckInternetConnectivityByHTTP(); break;
        case 13: InternetCheckReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 14: onError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 15: UpdateDateTimeFromNTP(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SystemMonitor::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SystemMonitor::Broadcast(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SystemMonitor::USBMemoryUnplugged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SystemMonitor::USBMemoryPlugged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void SystemMonitor::NetworkNotAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void SystemMonitor::NetworkAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
