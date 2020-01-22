QT       += core gui serialbus widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = modbusmaster

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    m320t.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    m320t.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
