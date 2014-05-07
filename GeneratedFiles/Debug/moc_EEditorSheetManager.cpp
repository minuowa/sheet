/****************************************************************************
** Meta object code from reading C++ file 'EEditorSheetManager.h'
**
** Created: Tue May 6 23:05:33 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EEditorSheetManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EEditorSheetManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EEditorManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      44,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EEditorManager[] = {
    "EEditorManager\0\0onAddObjectAction(QAction*)\0"
    "onComponentAction(QAction*)\0"
};

void EEditorManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EEditorManager *_t = static_cast<EEditorManager *>(_o);
        switch (_id) {
        case 0: _t->onAddObjectAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->onComponentAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EEditorManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EEditorManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EEditorManager,
      qt_meta_data_EEditorManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EEditorManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EEditorManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EEditorManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EEditorManager))
        return static_cast<void*>(const_cast< EEditorManager*>(this));
    if (!strcmp(_clname, "Actor"))
        return static_cast< Actor*>(const_cast< EEditorManager*>(this));
    return QObject::qt_metacast(_clname);
}

int EEditorManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
