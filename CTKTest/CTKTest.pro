CONFIG += c++11 console gui core
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
        mainwindow.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/includes \
            += $$PWD/includes/core \
            += $$PWD/includes/pluginFramework

INCLUDEPATH += $$PWD/libs

DEPENDPATH += $$PWD/libs

DESTDIR = $$PWD/../bin

LIBS += -L$$PWD/libs/ -lCTKCore
LIBS += -L$$PWD/libs/ -lCTKPluginFramework

INSTALLS += inst

HEADERS += \
    ../includes/IWidgetManage.h \
    mainwindow.h \
    imainwindow.h

FORMS += \
    mainwindow.ui
