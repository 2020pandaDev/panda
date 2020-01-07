/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PandaClient/chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chat_t {
    QByteArrayData data[18];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chat_t qt_meta_stringdata_Chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Chat"
QT_MOC_LITERAL(1, 5, 22), // "processPendinDatagrams"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "getFileName"
QT_MOC_LITERAL(4, 41, 25), // "on_boldToolButton_clicked"
QT_MOC_LITERAL(5, 67, 7), // "checked"
QT_MOC_LITERAL(6, 75, 27), // "on_italicToolButton_clicked"
QT_MOC_LITERAL(7, 103, 26), // "on_underToolButton_clicked"
QT_MOC_LITERAL(8, 130, 26), // "on_colorToolButton_clicked"
QT_MOC_LITERAL(9, 157, 25), // "on_sendToolButton_clicked"
QT_MOC_LITERAL(10, 183, 25), // "on_saveToolButton_clicked"
QT_MOC_LITERAL(11, 209, 26), // "on_clearToolButton_clicked"
QT_MOC_LITERAL(12, 236, 26), // "on_closePushButton_clicked"
QT_MOC_LITERAL(13, 263, 25), // "on_sendPushButton_clicked"
QT_MOC_LITERAL(14, 289, 34), // "on_fontComboBox_currentFontCh..."
QT_MOC_LITERAL(15, 324, 1), // "f"
QT_MOC_LITERAL(16, 326, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(17, 358, 4) // "arg1"

    },
    "Chat\0processPendinDatagrams\0\0getFileName\0"
    "on_boldToolButton_clicked\0checked\0"
    "on_italicToolButton_clicked\0"
    "on_underToolButton_clicked\0"
    "on_colorToolButton_clicked\0"
    "on_sendToolButton_clicked\0"
    "on_saveToolButton_clicked\0"
    "on_clearToolButton_clicked\0"
    "on_closePushButton_clicked\0"
    "on_sendPushButton_clicked\0"
    "on_fontComboBox_currentFontChanged\0f\0"
    "on_comboBox_currentIndexChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    1,   80,    2, 0x08 /* Private */,
       4,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       7,    1,   89,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,   15,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void Chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chat *_t = static_cast<Chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processPendinDatagrams(); break;
        case 1: _t->getFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_boldToolButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_italicToolButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_underToolButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_colorToolButton_clicked(); break;
        case 6: _t->on_sendToolButton_clicked(); break;
        case 7: _t->on_saveToolButton_clicked(); break;
        case 8: _t->on_clearToolButton_clicked(); break;
        case 9: _t->on_closePushButton_clicked(); break;
        case 10: _t->on_sendPushButton_clicked(); break;
        case 11: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 12: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Chat::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Chat.data,
      qt_meta_data_Chat,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chat.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
