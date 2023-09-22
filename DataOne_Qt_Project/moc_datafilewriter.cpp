/****************************************************************************
** Meta object code from reading C++ file 'datafilewriter.h'
**
** Created: Fri Jun 28 02:02:56 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FileWriter/datafilewriter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datafilewriter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataFileWriter[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   15,   15,   15, 0x0a,
      54,   15,   15,   15, 0x0a,
      69,   15,   15,   15, 0x0a,
     105,   88,   15,   15, 0x0a,
     136,   15,   15,   15, 0x0a,
     147,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DataFileWriter[] = {
    "DataFileWriter\0\0,\0Log(QString,QString)\0"
    "ClearBuffers()\0ClearAllLogs()\0"
    "USBMemoryPlugged()\0newTag,RecordNum\0"
    "EnqueueTag(QByteArray,quint64)\0"
    "Shutdown()\0SetNewDataFileName()\0"
};

const QMetaObject DataFileWriter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DataFileWriter,
      qt_meta_data_DataFileWriter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataFileWriter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataFileWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataFileWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataFileWriter))
        return static_cast<void*>(const_cast< DataFileWriter*>(this));
    return QThread::qt_metacast(_clname);
}

int DataFileWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: ClearBuffers(); break;
        case 2: ClearAllLogs(); break;
        case 3: USBMemoryPlugged(); break;
        case 4: EnqueueTag((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 5: Shutdown(); break;
        case 6: SetNewDataFileName(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DataFileWriter::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
