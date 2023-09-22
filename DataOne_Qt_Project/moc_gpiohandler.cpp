/****************************************************************************
** Meta object code from reading C++ file 'gpiohandler.h'
**
** Created: Fri Jun 28 02:02:57 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Reader/gpiohandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpiohandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GPIOHandler[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x05,
      36,   12,   12,   12, 0x05,
      72,   55,   12,   12, 0x05,
      89,   12,   12,   12, 0x05,
     104,   12,   12,   12, 0x05,
     118,   12,   12,   12, 0x05,
     136,   12,   12,   12, 0x05,
     173,  165,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     216,  201,   12,   12, 0x0a,
     258,   12,   12,   12, 0x0a,
     278,   12,   12,   12, 0x0a,
     299,   12,   12,   12, 0x0a,
     320,   12,   12,   12, 0x0a,
     331,   12,   12,   12, 0x0a,
     354,   12,   12,   12, 0x0a,
     372,   12,   12,   12, 0x0a,
     393,   12,   12,   12, 0x0a,
     415,   12,   12,   12, 0x0a,
     437,   12,   12,   12, 0x0a,
     456,   12,   12,   12, 0x08,
     475,   12,   12,   12, 0x08,
     494,   12,   12,   12, 0x08,
     522,   12,   12,   12, 0x08,
     549,   12,   12,   12, 0x08,
     568,   12,   12,   12, 0x08,
     584,   12,   12,   12, 0x08,
     609,   12,   12,   12, 0x08,
     634,   12,   12,   12, 0x08,
     658,   12,   12,   12, 0x08,
     679,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GPIOHandler[] = {
    "GPIOHandler\0\0,\0Log(QString,QString)\0"
    "Broadcast(QString)\0PortNumber,State\0"
    "setGPO(int,bool)\0StartReading()\0"
    "StopReading()\0RefreshAntennas()\0"
    "UpdateBatteryVoltage(double)\0Command\0"
    "CommandToReader(QByteArray)\0args,TimeStamp\0"
    "GPIChanged(GpiChangedEventArgs,QDateTime)\0"
    "LLRPConnected(bool)\0ReadingStarted(bool)\0"
    "StartTagReportBeep()\0StopBeep()\0"
    "UpdateTemperature(int)\0ClientConnected()\0"
    "ClientDisconnected()\0StartActionAlert(int)\0"
    "NetworkNotAvailable()\0NetworkAvailable()\0"
    "UpdateGpo2Status()\0UpdateGpo3Status()\0"
    "StartActionAlertBeepFlash()\0"
    "StopActionAlertBeepFlash()\0"
    "ClearActionAlert()\0GPIOReadyBeep()\0"
    "GPI2DelayTimerFinished()\0"
    "GPI3StartTimerFinished()\0"
    "GPI3StopTimerFinished()\0BackupPowerTimeout()\0"
    "SendBatteryFailAlert()\0"
};

const QMetaObject GPIOHandler::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GPIOHandler,
      qt_meta_data_GPIOHandler, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPIOHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPIOHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPIOHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPIOHandler))
        return static_cast<void*>(const_cast< GPIOHandler*>(this));
    return QThread::qt_metacast(_clname);
}

int GPIOHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: Broadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: setGPO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: StartReading(); break;
        case 4: StopReading(); break;
        case 5: RefreshAntennas(); break;
        case 6: UpdateBatteryVoltage((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: CommandToReader((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: GPIChanged((*reinterpret_cast< GpiChangedEventArgs(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 9: LLRPConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: ReadingStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: StartTagReportBeep(); break;
        case 12: StopBeep(); break;
        case 13: UpdateTemperature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: ClientConnected(); break;
        case 15: ClientDisconnected(); break;
        case 16: StartActionAlert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: NetworkNotAvailable(); break;
        case 18: NetworkAvailable(); break;
        case 19: UpdateGpo2Status(); break;
        case 20: UpdateGpo3Status(); break;
        case 21: StartActionAlertBeepFlash(); break;
        case 22: StopActionAlertBeepFlash(); break;
        case 23: ClearActionAlert(); break;
        case 24: GPIOReadyBeep(); break;
        case 25: GPI2DelayTimerFinished(); break;
        case 26: GPI3StartTimerFinished(); break;
        case 27: GPI3StopTimerFinished(); break;
        case 28: BackupPowerTimeout(); break;
        case 29: SendBatteryFailAlert(); break;
        default: ;
        }
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void GPIOHandler::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GPIOHandler::Broadcast(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GPIOHandler::setGPO(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GPIOHandler::StartReading()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GPIOHandler::StopReading()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void GPIOHandler::RefreshAntennas()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void GPIOHandler::UpdateBatteryVoltage(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GPIOHandler::CommandToReader(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
