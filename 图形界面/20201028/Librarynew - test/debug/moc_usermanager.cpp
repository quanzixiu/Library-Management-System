/****************************************************************************
** Meta object code from reading C++ file 'usermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserManager_t {
    QByteArrayData data[9];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserManager_t qt_meta_stringdata_UserManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UserManager"
QT_MOC_LITERAL(1, 12, 23), // "on_gotomainpage_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "on_exitlogin1_clicked"
QT_MOC_LITERAL(4, 59, 22), // "on_confirmsure_clicked"
QT_MOC_LITERAL(5, 82, 18), // "on_addsure_clicked"
QT_MOC_LITERAL(6, 101, 19), // "on_addusers_clicked"
QT_MOC_LITERAL(7, 121, 22), // "on_updateusers_clicked"
QT_MOC_LITERAL(8, 144, 22) // "on_deleteusers_clicked"

    },
    "UserManager\0on_gotomainpage_clicked\0"
    "\0on_exitlogin1_clicked\0on_confirmsure_clicked\0"
    "on_addsure_clicked\0on_addusers_clicked\0"
    "on_updateusers_clicked\0on_deleteusers_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserManager *_t = static_cast<UserManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_gotomainpage_clicked(); break;
        case 1: _t->on_exitlogin1_clicked(); break;
        case 2: _t->on_confirmsure_clicked(); break;
        case 3: _t->on_addsure_clicked(); break;
        case 4: _t->on_addusers_clicked(); break;
        case 5: _t->on_updateusers_clicked(); break;
        case 6: _t->on_deleteusers_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UserManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserManager.data,
      qt_meta_data_UserManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserManager.stringdata0))
        return static_cast<void*>(const_cast< UserManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
