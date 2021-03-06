TEMPLATE = lib
CONFIG += staticlib
QT += core network concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG(debug, debug|release) {
	TARGET = commond
	DESTDIR = debug
	OBJECTS_DIR = debug
	} else {
	TARGET = common
	DESTDIR = release
	OBJECTS_DIR = release
}

HEADERS +=  \
    ErrorHandler.h \
    Logger.h \
    NetworkInterface.h \
    RunGuard.h \
    Settings.h \
    TcpServer.h \
    TcpSocket.h \
    TextEditIODevice.h \
    Utility.h \
    Wizard.h \
    Wizardpage.h
    ErrorHandler.h

SOURCES +=  \
    ErrorHandler.cpp \
    Logger.cpp \
    NetworkInterface.cpp \
    RunGuard.cpp \
    Settings.cpp \
    TcpServer.cpp \
    TcpSocket.cpp \
    TextEditIODevice.cpp \
    Utility.cpp \
    Wizard.cpp \
    Wizardpage.cpp
    ErrorHandler.cpp
