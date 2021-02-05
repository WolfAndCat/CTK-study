TEMPLATE = lib

TARGET = Client1

DESTDIR = $$PWD/../bin/plugins/

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/../includes \
            += $$PWD/../includes/core \
            += $$PWD/../includes/pluginFramework

INCLUDEPATH += $$PWD/../libs

DEPENDPATH += $$PWD/../libs

LIBS += -L$$PWD/../libs/ -lCTKCore
LIBS += -L$$PWD/../libs/ -lCTKPluginFramework

file.path = $$DESTDIR
file.files = MANIFEST.MF
INSTALLS += file

DISTFILES += \
    MANIFEST.MF

RESOURCES += \
    Client1.qrc

HEADERS += \
    client1activator.h \
    client1plugin.h \
    clientplugin.h \
    datawidget.h

SOURCES += \
    client1activator.cpp \
    client1plugin.cpp \
    clientplugin.cpp \
    datawidget.cpp

FORMS += \
    datawidget.ui

