/****************************************************************************
** Meta object code from reading C++ file 'EditorSheetEvent.h'
**
** Created: Fri May 2 17:51:37 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EditorSheetEvent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditorSheetEvent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EEditorEventAgent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      39,   19,   18,   18, 0x0a,
      89,   18,   18,   18, 0x0a,
     117,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EEditorEventAgent[] = {
    "EEditorEventAgent\0\0selected,deselected\0"
    "onSelectionChanged(QItemSelection,QItemSelection)\0"
    "onAddObjectAction(QAction*)\0"
    "onComponentAction(QAction*)\0"
};

void EEditorEventAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EEditorEventAgent *_t = static_cast<EEditorEventAgent *>(_o);
        switch (_id) {
        case 0: _t->onSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 1: _t->onAddObjectAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->onComponentAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EEditorEventAgent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EEditorEventAgent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EEditorEventAgent,
      qt_meta_data_EEditorEventAgent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EEditorEventAgent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EEditorEventAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EEditorEventAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EEditorEventAgent))
        return static_cast<void*>(const_cast< EEditorEventAgent*>(this));
    return QObject::qt_metacast(_clname);
}

int EEditorEventAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
