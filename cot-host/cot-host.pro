QT += core network gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += ../common
DESTDIR = ../app

RESOURCES += ../resources.qrc

CONFIG(debug, debug|release) {
        LIBS += -L../common/debug
        TARGET = cot-hostd
        LIBS += -lcommond
		OBJECTS_DIR = debug
        } else {
        TARGET = cot-host
        LIBS += -L../common/release
        LIBS += -lcommon
		OBJECTS_DIR = release
}

# Win32 Settings
win32-g++ {
RC_FILE +=  cot-host.exe.rc
}

win32-msvc* {
CONFIG += embed_manifest_exe
QMAKE_LFLAGS_WINDOWS += $$quote( /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\" )
RC_ICONS = icon.ico
}

SOURCES += \
    IpSettingsWizardPage.cpp \
    MainWindow.cpp \
    TargetSettingsWizardPage.cpp \
    TestSettingsWizard.cpp \
    cot-host.cpp

HEADERS += \
    IpSettingsWizardPage.h \
    MainWindow.h \
    TargetSettingsWizardPage.h \
    TestSettingsWizard.h

FORMS += \
    IpSettingsWizardPage.ui \
    MainWindow.ui \
    TargetSettingsWizardPage.ui
