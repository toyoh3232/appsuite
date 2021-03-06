QT += core network gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG -= app_bundle

CONFIG(debug, debug|release) {
        LIBS += -L../common/debug
        TARGET = testd
        LIBS += -lcommond
		OBJECTS_DIR = debug
        } else {
        TARGET = test
        LIBS += -L../common/release
        LIBS += -lcommon
		OBJECTS_DIR = release
}

# win32-g++ {
# RC_FILE +=  test.exe.rc
# }

# win32-msvc* {
# CONFIG += embed_manifest_exe
# QMAKE_LFLAGS_WINDOWS += $$quote( /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\" )
# }

INCLUDEPATH += ../common
DESTDIR = ../app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        FileCCDThread.cpp \
        FileCCDWidget.cpp \
        MainWindow.cpp \
        MainWindow2.cpp \
        MultiTargetSettingsWidget.cpp \
        main.cpp

FORMS += \
    FileCCDWidget.ui \
    MainWindow.ui \
    MainWindow2.ui \
    MultiTargetSettingsWidget.ui

HEADERS += \
    FileCCDThread.h \
    FileCCDWidget.h \
    MainWindow.h \
    MainWindow2.h \
    MultiTargetSettingsWidget.h
