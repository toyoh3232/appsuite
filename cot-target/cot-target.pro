QT += core network gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += ../common
DESTDIR = ../app

RESOURCES += ../languages/translations.qrc

CONFIG(debug, debug|release) {
        LIBS += -L../common/debug
        TARGET = cot-targetd
        LIBS += -lcommond
        } else {
        TARGET = cot-target
        LIBS += -L../common/release
        LIBS += -lcommon
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
    HostSettingsWizardPage.ui \
    MainWindow.ui

HEADERS += \
    HostSettingsWizardPage.h \
    MainWindow.h \
    TestSettingsWizard.h

SOURCES += \
    HostSettingsWizardPage.cpp \
    MainWindow.cpp \
    TestSettingsWizard.cpp \
    cot-target.cpp
