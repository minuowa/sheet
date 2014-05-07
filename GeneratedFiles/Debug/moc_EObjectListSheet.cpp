/****************************************************************************
** Meta object code from reading C++ file 'EObjectListSheet.h'
**
** Created: Tue May 6 23:05:33 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EObjectListSheet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EObjectListSheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EObjectListSheet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      38,   18,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EObjectListSheet[] = {
    "EObjectListSheet\0\0selected,deselected\0"
    "onSelectionChanged(QItemSelection,QItemSelection)\0"
};

void EObjectListSheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EObjectListSheet *_t = static_cast<EObjectListSheet *>(_o);
        switch (_id) {
        case 0: _t->onSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EObjectListSheet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EObjectListSheet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EObjectListSheet,
      qt_meta_data_EObjectListSheet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EObjectListSheet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EObjectListSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EObjectListSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EObjectListSheet))
        return static_cast<void*>(const_cast< EObjectListSheet*>(this));
    if (!strcmp(_clname, "Actor"))
        return static_cast< Actor*>(const_cast< EObjectListSheet*>(this));
    return QObject::qt_metacast(_clname);
}

int EObjectListSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
