/****************************************************************************
** Meta object code from reading C++ file 'consolefilewriter.h'
**
** Created: Fri Jun 28 02:03:00 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FileWriter/consolefilewriter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consolefilewriter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConsoleFileWriter[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      41,   18,   18,   18, 0x0a,
      60,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ConsoleFileWriter[] = {
    "ConsoleFileWriter\0\0RecordLog(QByteArray)\0"
    "USBMemoryPlugged()\0Shutdown()\0"
};

const QMetaObject ConsoleFileWriter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ConsoleFileWriter,
      qt_meta_data_ConsoleFileWriter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConsoleFileWriter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConsoleFileWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConsoleFileWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConsoleFileWriter))
        return static_cast<void*>(const_cast< ConsoleFileWriter*>(this));
    return QThread::qt_metacast(_clname);
}

int ConsoleFileWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: RecordLog((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: USBMemoryPlugged(); break;
        case 2: Shutdown(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
