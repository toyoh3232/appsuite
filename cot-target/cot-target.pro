QT += core network gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += ../common
DESTDIR = ../app

RESOURCES += ../resources.qrc

CONFIG(debug, debug|release) {
        LIBS += -L../common/debug
        TARGET = cot-targetd
        LIBS += -lcommond
		OBJECTS_DIR = debug
        } else {
        TARGET = cot-target
        LIBS += -L../common/release
        LIBS += -lcommon
		OBJECTS_DIR = release
}

# Win32 Settings
win32-g++ {
RC_FILE +=  cot-target.exe.rc
}

win32-msvc* {
CONFIG += embed_manifest_exe
QMAKE_LFLAGS_WINDOWS += $$quote( /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\" )
RC_ICONS = icon.ico
}

FORMS += \
    IpSettingsWizardPage.ui \
    MainWindow.ui \
    VariousSettingsWizardPage.ui

HEADERS += \
    IpSettingsWizardPage.h \
    MainWindow.h \
    TestSettingsWizard.h \
    VariousSettingsWizardPage.h

SOURCES += \
    IpSettingsWizardPage.cpp \
    MainWindow.cpp \
    TestSettingsWizard.cpp \
    VariousSettingsWizardPage.cpp \
    cot-target.cpp

