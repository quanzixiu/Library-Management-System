/****************************************************************************
** Meta object code from reading C++ file 'bookmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bookmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bookmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BookManager_t {
    QByteArrayData data[8];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BookManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BookManager_t qt_meta_stringdata_BookManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BookManager"
QT_MOC_LITERAL(1, 12, 23), // "on_gotomainpage_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "on_exitlogin_clicked"
QT_MOC_LITERAL(4, 58, 22), // "on_confirmsure_clicked"
QT_MOC_LITERAL(5, 81, 19), // "on_addbooks_clicked"
QT_MOC_LITERAL(6, 101, 22), // "on_updatebooks_clicked"
QT_MOC_LITERAL(7, 124, 22) // "on_deletebooks_clicked"

    },
    "BookManager\0on_gotomainpage_clicked\0"
    "\0on_exitlogin_clicked\0on_confirmsure_clicked\0"
    "on_addbooks_clicked\0on_updatebooks_clicked\0"
    "on_deletebooks_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BookManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BookManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BookManager *_t = static_cast<BookManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_gotomainpage_clicked(); break;
        case 1: _t->on_exitlogin_clicked(); break;
        case 2: _t->on_confirmsure_clicked(); break;
        case 3: _t->on_addbooks_clicked(); break;
        case 4: _t->on_updatebooks_clicked(); break;
        case 5: _t->on_deletebooks_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BookManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BookManager.data,
      qt_meta_data_BookManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BookManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BookManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BookManager.stringdata0))
        return static_cast<void*>(const_cast< BookManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int BookManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
