/****************************************************************************
** Meta object code from reading C++ file 'mainwindowserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../webCamServer/mainwindowserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindowServer_t {
    QByteArrayData data[12];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowServer_t qt_meta_stringdata_MainWindowServer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MainWindowServer"
QT_MOC_LITERAL(1, 17, 11), // "startServer"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "stopServer"
QT_MOC_LITERAL(4, 41, 13), // "newConnection"
QT_MOC_LITERAL(5, 55, 12), // "DisplayError"
QT_MOC_LITERAL(6, 68, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(7, 97, 11), // "socketError"
QT_MOC_LITERAL(8, 109, 8), // "ReadData"
QT_MOC_LITERAL(9, 118, 9), // "ShowImage"
QT_MOC_LITERAL(10, 128, 2), // "ba"
QT_MOC_LITERAL(11, 131, 11) // "recordVideo"

    },
    "MainWindowServer\0startServer\0\0stopServer\0"
    "newConnection\0DisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "ReadData\0ShowImage\0ba\0recordVideo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowServer[] = {

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
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,
       9,    1,   56,    2, 0x0a /* Public */,
      11,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void,

       0        // eod
};

void MainWindowServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowServer *_t = static_cast<MainWindowServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startServer(); break;
        case 1: _t->stopServer(); break;
        case 2: _t->newConnection(); break;
        case 3: _t->DisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->ReadData(); break;
        case 5: _t->ShowImage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->recordVideo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindowServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowServer.data,
      qt_meta_data_MainWindowServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindowServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowServer.stringdata0))
        return static_cast<void*>(const_cast< MainWindowServer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
