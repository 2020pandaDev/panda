/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PandaClient/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[22];
    char stringdata0[423];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 23), // "processPendingDatagrams"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "getFileName"
QT_MOC_LITERAL(4, 44, 25), // "on_sendPushButton_clicked"
QT_MOC_LITERAL(5, 70, 25), // "on_exitPushButton_clicked"
QT_MOC_LITERAL(6, 96, 22), // "on_sendToolBtn_clicked"
QT_MOC_LITERAL(7, 119, 32), // "on_fontComBox_currentFontChanged"
QT_MOC_LITERAL(8, 152, 1), // "f"
QT_MOC_LITERAL(9, 154, 35), // "on_sizeComboBox_currentIndexC..."
QT_MOC_LITERAL(10, 190, 4), // "arg1"
QT_MOC_LITERAL(11, 195, 22), // "on_boldToolBtn_clicked"
QT_MOC_LITERAL(12, 218, 7), // "checked"
QT_MOC_LITERAL(13, 226, 24), // "on_italicToolBtn_clicked"
QT_MOC_LITERAL(14, 251, 27), // "on_underlineToolBtn_clicked"
QT_MOC_LITERAL(15, 279, 23), // "on_colorToolBtn_clicked"
QT_MOC_LITERAL(16, 303, 22), // "on_saveToolBtn_clicked"
QT_MOC_LITERAL(17, 326, 23), // "on_clearToolBtn_clicked"
QT_MOC_LITERAL(18, 350, 32), // "on_userTableWidget_doubleClicked"
QT_MOC_LITERAL(19, 383, 11), // "QModelIndex"
QT_MOC_LITERAL(20, 395, 5), // "index"
QT_MOC_LITERAL(21, 401, 21) // "on_toolButton_clicked"

    },
    "Widget\0processPendingDatagrams\0\0"
    "getFileName\0on_sendPushButton_clicked\0"
    "on_exitPushButton_clicked\0"
    "on_sendToolBtn_clicked\0"
    "on_fontComBox_currentFontChanged\0f\0"
    "on_sizeComboBox_currentIndexChanged\0"
    "arg1\0on_boldToolBtn_clicked\0checked\0"
    "on_italicToolBtn_clicked\0"
    "on_underlineToolBtn_clicked\0"
    "on_colorToolBtn_clicked\0on_saveToolBtn_clicked\0"
    "on_clearToolBtn_clicked\0"
    "on_userTableWidget_doubleClicked\0"
    "QModelIndex\0index\0on_toolButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    1,   90,    2, 0x08 /* Private */,
       4,    0,   93,    2, 0x08 /* Private */,
       5,    0,   94,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    1,   96,    2, 0x08 /* Private */,
       9,    1,   99,    2, 0x08 /* Private */,
      11,    1,  102,    2, 0x08 /* Private */,
      13,    1,  105,    2, 0x08 /* Private */,
      14,    1,  108,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    1,  114,    2, 0x08 /* Private */,
      21,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processPendingDatagrams(); break;
        case 1: _t->getFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_sendPushButton_clicked(); break;
        case 3: _t->on_exitPushButton_clicked(); break;
        case 4: _t->on_sendToolBtn_clicked(); break;
        case 5: _t->on_fontComBox_currentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 6: _t->on_sizeComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_boldToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_italicToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_underlineToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_colorToolBtn_clicked(); break;
        case 11: _t->on_saveToolBtn_clicked(); break;
        case 12: _t->on_clearToolBtn_clicked(); break;
        case 13: _t->on_userTableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->on_toolButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
