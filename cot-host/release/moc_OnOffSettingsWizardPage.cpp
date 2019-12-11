/****************************************************************************
** Meta object code from reading C++ file 'OnOffSettingsWizardPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../OnOffSettingsWizardPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OnOffSettingsWizardPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OnOffSettingsWizardPage_t {
    QByteArrayData data[7];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OnOffSettingsWizardPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OnOffSettingsWizardPage_t qt_meta_stringdata_OnOffSettingsWizardPage = {
    {
QT_MOC_LITERAL(0, 0, 23), // "OnOffSettingsWizardPage"
QT_MOC_LITERAL(1, 24, 16), // "lockButton_click"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 18), // "unlockButton_click"
QT_MOC_LITERAL(4, 61, 20), // "lineEdit_textChanged"
QT_MOC_LITERAL(5, 82, 15), // "setButton_click"
QT_MOC_LITERAL(6, 98, 16) // "fillButton_click"

    },
    "OnOffSettingsWizardPage\0lockButton_click\0"
    "\0unlockButton_click\0lineEdit_textChanged\0"
    "setButton_click\0fillButton_click"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OnOffSettingsWizardPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OnOffSettingsWizardPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OnOffSettingsWizardPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lockButton_click(); break;
        case 1: _t->unlockButton_click(); break;
        case 2: _t->lineEdit_textChanged(); break;
        case 3: _t->setButton_click(); break;
        case 4: _t->fillButton_click(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OnOffSettingsWizardPage::staticMetaObject = { {
    &QWizardPage::staticMetaObject,
    qt_meta_stringdata_OnOffSettingsWizardPage.data,
    qt_meta_data_OnOffSettingsWizardPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OnOffSettingsWizardPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OnOffSettingsWizardPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OnOffSettingsWizardPage.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int OnOffSettingsWizardPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
