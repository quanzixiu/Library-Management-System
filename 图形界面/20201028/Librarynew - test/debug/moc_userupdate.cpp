/****************************************************************************
** Meta object code from reading C++ file 'userupdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userupdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserUpdate_t {
    QByteArrayData data[12];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserUpdate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserUpdate_t qt_meta_stringdata_UserUpdate = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UserUpdate"
QT_MOC_LITERAL(1, 11, 19), // "on_updateid_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "on_updatename_clicked"
QT_MOC_LITERAL(4, 54, 23), // "on_updateschool_clicked"
QT_MOC_LITERAL(5, 78, 22), // "on_updatemajor_clicked"
QT_MOC_LITERAL(6, 101, 22), // "on_updateemail_clicked"
QT_MOC_LITERAL(7, 124, 23), // "on_gotomainpage_clicked"
QT_MOC_LITERAL(8, 148, 28), // "on_returnusermanager_clicked"
QT_MOC_LITERAL(9, 177, 19), // "on_confirm1_clicked"
QT_MOC_LITERAL(10, 197, 19), // "on_confirm2_clicked"
QT_MOC_LITERAL(11, 217, 21) // "on_updatesure_clicked"

    },
    "UserUpdate\0on_updateid_clicked\0\0"
    "on_updatename_clicked\0on_updateschool_clicked\0"
    "on_updatemajor_clicked\0on_updateemail_clicked\0"
    "on_gotomainpage_clicked\0"
    "on_returnusermanager_clicked\0"
    "on_confirm1_clicked\0on_confirm2_clicked\0"
    "on_updatesure_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserUpdate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserUpdate *_t = static_cast<UserUpdate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_updateid_clicked(); break;
        case 1: _t->on_updatename_clicked(); break;
        case 2: _t->on_updateschool_clicked(); break;
        case 3: _t->on_updatemajor_clicked(); break;
        case 4: _t->on_updateemail_clicked(); break;
        case 5: _t->on_gotomainpage_clicked(); break;
        case 6: _t->on_returnusermanager_clicked(); break;
        case 7: _t->on_confirm1_clicked(); break;
        case 8: _t->on_confirm2_clicked(); break;
        case 9: _t->on_updatesure_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UserUpdate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserUpdate.data,
      qt_meta_data_UserUpdate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserUpdate.stringdata0))
        return static_cast<void*>(const_cast< UserUpdate*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
