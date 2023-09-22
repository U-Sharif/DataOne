/****************************************************************************
** Meta object code from reading C++ file 'filteredfilewriter.h'
**
** Created: Fri Jun 28 02:02:55 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FileWriter/filteredfilewriter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filteredfilewriter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FilteredFileWriter[] = {

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
      22,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   19,   19,   19, 0x0a,
      58,   19,   19,   19, 0x0a,
      73,   19,   19,   19, 0x0a,
     109,   92,   19,   19, 0x0a,
     140,   19,   19,   19, 0x0a,
     151,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FilteredFileWriter[] = {
    "FilteredFileWriter\0\0,\0Log(QString,QString)\0"
    "ClearBuffers()\0ClearAllLogs()\0"
    "USBMemoryPlugged()\0newTag,RecordNum\0"
    "EnqueueTag(QByteArray,quint64)\0"
    "Shutdown()\0SetNewFilteredFileName()\0"
};

const QMetaObject FilteredFileWriter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FilteredFileWriter,
      qt_meta_data_FilteredFileWriter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FilteredFileWriter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FilteredFileWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FilteredFileWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FilteredFileWriter))
        return static_cast<void*>(const_cast< FilteredFileWriter*>(this));
    return QThread::qt_metacast(_clname);
}

int FilteredFileWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 6: SetNewFilteredFileName(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FilteredFileWriter::Log(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
