TEMPLATE = lib
CONFIG += staticlib
QT += core network concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release) {
	TARGET = commond
	} else {
	TARGET = common
}

HEADERS +=  \
    ErrorHandler.h \
    Logger.h \
    NetworkInterface.h \
    SettingsEntity.h \
    TcpServer.h \
    TcpSocket.h \
    TextEditIODevice.h \
    Utility.h \
    Wizard.h
    ErrorHandler.h

SOURCES +=  \
    ErrorHandler.cpp \
    Logger.cpp \
    NetworkInterface.cpp \
    SettingsEntity.cpp \
    TcpServer.cpp \
    TcpSocket.cpp \
    TextEditIODevice.cpp \
    Utility.cpp \
    Wizard.cpp
    ErrorHandler.cpp
