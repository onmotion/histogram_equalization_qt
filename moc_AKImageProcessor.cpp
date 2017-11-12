/****************************************************************************
** Meta object code from reading C++ file 'AKImageProcessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "AKImageProcessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AKImageProcessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AKImageProcessor_t {
    QByteArrayData data[11];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AKImageProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AKImageProcessor_t qt_meta_stringdata_AKImageProcessor = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AKImageProcessor"
QT_MOC_LITERAL(1, 17, 22), // "sendEqualizedHistogram"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 15), // "sendResultImage"
QT_MOC_LITERAL(4, 57, 21), // "sendOriginalHistogram"
QT_MOC_LITERAL(5, 79, 14), // "sendCumulative"
QT_MOC_LITERAL(6, 94, 21), // "getEqualizedHistogram"
QT_MOC_LITERAL(7, 116, 17), // "getEqualizedImage"
QT_MOC_LITERAL(8, 134, 11), // "lightFactor"
QT_MOC_LITERAL(9, 146, 20), // "getOriginalHistogram"
QT_MOC_LITERAL(10, 167, 13) // "getCumulative"

    },
    "AKImageProcessor\0sendEqualizedHistogram\0"
    "\0sendResultImage\0sendOriginalHistogram\0"
    "sendCumulative\0getEqualizedHistogram\0"
    "getEqualizedImage\0lightFactor\0"
    "getOriginalHistogram\0getCumulative"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AKImageProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   66,    2, 0x0a /* Public */,
       7,    1,   67,    2, 0x0a /* Public */,
       9,    0,   70,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void AKImageProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AKImageProcessor *_t = static_cast<AKImageProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendEqualizedHistogram((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sendResultImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->sendOriginalHistogram((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->sendCumulative((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->getEqualizedHistogram(); break;
        case 5: _t->getEqualizedImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->getOriginalHistogram(); break;
        case 7: _t->getCumulative((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AKImageProcessor::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AKImageProcessor::sendEqualizedHistogram)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AKImageProcessor::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AKImageProcessor::sendResultImage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AKImageProcessor::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AKImageProcessor::sendOriginalHistogram)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AKImageProcessor::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AKImageProcessor::sendCumulative)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AKImageProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AKImageProcessor.data,
      qt_meta_data_AKImageProcessor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AKImageProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AKImageProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AKImageProcessor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AKImageProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void AKImageProcessor::sendEqualizedHistogram(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AKImageProcessor::sendResultImage(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AKImageProcessor::sendOriginalHistogram(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AKImageProcessor::sendCumulative(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
