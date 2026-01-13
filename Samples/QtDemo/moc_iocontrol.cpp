/****************************************************************************
** Meta object code from reading C++ file 'iocontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "iocontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iocontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IOControl_t {
    QByteArrayData data[11];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IOControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IOControl_t qt_meta_stringdata_IOControl = {
    {
QT_MOC_LITERAL(0, 0, 9), // "IOControl"
QT_MOC_LITERAL(1, 10, 21), // "on_btnRefresh_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "on_btnTrigger_clicked"
QT_MOC_LITERAL(4, 55, 16), // "on_cbOut_clicked"
QT_MOC_LITERAL(5, 72, 7), // "checked"
QT_MOC_LITERAL(6, 80, 24), // "on_cbTriggerMode_clicked"
QT_MOC_LITERAL(7, 105, 27), // "on_cbStrobePolarity_clicked"
QT_MOC_LITERAL(8, 133, 28), // "on_cbTriggerPolarity_clicked"
QT_MOC_LITERAL(9, 162, 25), // "on_cbEnableStrobe_clicked"
QT_MOC_LITERAL(10, 188, 25) // "on_btnTriggerShot_clicked"

    },
    "IOControl\0on_btnRefresh_clicked\0\0"
    "on_btnTrigger_clicked\0on_cbOut_clicked\0"
    "checked\0on_cbTriggerMode_clicked\0"
    "on_cbStrobePolarity_clicked\0"
    "on_cbTriggerPolarity_clicked\0"
    "on_cbEnableStrobe_clicked\0"
    "on_btnTriggerShot_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    1,   56,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       7,    1,   62,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

       0        // eod
};

void IOControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IOControl *_t = static_cast<IOControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnRefresh_clicked(); break;
        case 1: _t->on_btnTrigger_clicked(); break;
        case 2: _t->on_cbOut_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_cbTriggerMode_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_cbStrobePolarity_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_cbTriggerPolarity_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_cbEnableStrobe_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_btnTriggerShot_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IOControl::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IOControl.data,
      qt_meta_data_IOControl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *IOControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IOControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IOControl.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int IOControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
