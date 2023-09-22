/****************************************************************************
** Meta object code from reading C++ file 'reader.h'
**
** Created: Fri Jun 28 02:03:00 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Reader/reader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Reader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    8,    7,    7, 0x05,
      31,    7,    7,    7, 0x05,
      50,    8,    7,    7, 0x05,
      93,    8,    7,    7, 0x05,
     140,    7,    7,    7, 0x05,
     176,  161,    7,    7, 0x05,
     218,    7,    7,    7, 0x05,
     238,    7,    7,    7, 0x05,
     259,    7,    7,    7, 0x05,
     282,    7,    7,    7, 0x05,
     310,    7,    7,    7, 0x05,
     331,    7,    7,    7, 0x05,
     346,    7,    7,    7, 0x05,
     361,    7,    7,    7, 0x05,
     385,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     403,    7,    7,    7, 0x0a,
     417,    7,    7,    7, 0x0a,
     434,    7,    7,    7, 0x0a,
     449,    7,    7,    7, 0x0a,
     463,    7,    7,    7, 0x0a,
     511,  494,    7,    7, 0x0a,
     528,    7,    7,    7, 0x0a,
     546,    7,    7,    7, 0x08,
     564,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Reader[] = {
    "Reader\0\0,\0Log(QString,QString)\0"
    "Broadcast(QString)\0"
    "NewDataRecordAvailable(QByteArray,quint64)\0"
    "NewFilteredRecordAvailable(QByteArray,quint64)\0"
    "StartTagReportBeep()\0args,TimeStamp\0"
    "GPIChanged(GpiChangedEventArgs,QDateTime)\0"
    "LLRPConnected(bool)\0ReadingStarted(bool)\0"
    "UpdateTemperature(int)\0"
    "UpdateAntennaState(QString)\0"
    "SaveDeviceSettings()\0ClearBuffers()\0"
    "ClearAllLogs()\0PerformActionAlert(int)\0"
    "DataOneShutdown()\0ConnectLLRP()\0"
    "DisconnectLLRP()\0StartReading()\0"
    "StopReading()\0ParseClientCommand(QByteArray)\0"
    "PortNumber,State\0setGPO(int,bool)\0"
    "RefreshAntennas()\0getReaderStatus()\0"
    "ProcessStartModeTags()\0"
};

const QMetaObject Reader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Reader,
      qt_meta_data_Reader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Reader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Reader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Reader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Reader))
        return static_cast<void*>(const_cast< Reader*>(this));
    if (!strcmp(_clname, "SpeedwayReader"))
        return static_cast< SpeedwayReader*>(const_cast< Reader*>(this));
    return QObject::qt_metacast(_clname);
}

int Reader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: Broadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: NewDataRecordAvailable((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 3: NewFilteredRecordAvailable((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 4: StartTagReportBeep(); break;
        case 5: GPIChanged((*reinterpret_cast< GpiChangedEventArgs(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 6: LLRPConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: ReadingStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: UpdateTemperature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: UpdateAntennaState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: SaveDeviceSettings(); break;
        case 11: ClearBuffers(); break;
        case 12: ClearAllLogs(); break;
        case 13: PerformActionAlert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: DataOneShutdown(); break;
        case 15: ConnectLLRP(); break;
        case 16: DisconnectLLRP(); break;
        case 17: StartReading(); break;
        case 18: StopReading(); break;
        case 19: ParseClientCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 20: setGPO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 21: RefreshAntennas(); break;
        case 22: getReaderStatus(); break;
        case 23: ProcessStartModeTags(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void Reader::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Reader::Broadcast(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Reader::NewDataRecordAvailable(QByteArray _t1, quint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Reader::NewFilteredRecordAvailable(QByteArray _t1, quint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Reader::StartTagReportBeep()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Reader::GPIChanged(GpiChangedEventArgs _t1, QDateTime _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Reader::LLRPConnected(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Reader::ReadingStarted(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Reader::UpdateTemperature(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Reader::UpdateAntennaState(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Reader::SaveDeviceSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void Reader::ClearBuffers()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void Reader::ClearAllLogs()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void Reader::PerformActionAlert(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Reader::DataOneShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}
QT_END_MOC_NAMESPACE
