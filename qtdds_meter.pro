#-------------------------------------------------
#
# Project created by QtCreator 2019-03-04T17:01:56
#
#-------------------------------------------------

QT       += core gui
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtdds
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ./encrypt/include/

CONFIG += c++11
#CONFIG += libmodbus
SOURCES += \
        main.cpp \
        mainwindow_dds.cpp \
        meter_relay.cxx \
        meter_relayImplPlugin.cxx \
        ooodds.cpp \
        meter_relayImpl.cxx \
        get_modbus.cpp \
        encrypt/aes_tools.cpp \
        encrypt/rsa_tools.cpp \
        encrypt/hybrid_tools.cpp

HEADERS += \
        mainwindow_dds.h \
        ooodds.h \
        meter_relay.hpp \
        meter_relayImplPlugin.h \
        meter_relayImpl.h \
        src/include/asyncdeltask.h \
        src/include/qexecthread.h \
        get_modbus.h  \
        encrypt/include/aes_tools.h \
        encrypt/include/rsa_tools.h \
        encrypt/include/hybrid_tools.h \
        encrypt/include/henon_tools.h\
        encrypt/include/aes_tools.h \
        encrypt/include/rsa_tools.h \
        encrypt/include/hybrid_tools.h \
        encrypt/include/henon_tools.h

FORMS += \
        mainwindow_dds.ui
#LIBS  += -lmodbus
LIBS += -lQt5SerialPort -lQt5SerialBus
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

NDDSHOME = /home/liu/Public/rti_connext_dds-5.3.1
TARGET_ARCH = x64Linux3gcc5.4.0
SYSLIBS = -ldl -lnsl -lm -lpthread -lrt

DEFINES += RTI_UNIX RTI_LINUX RTI_64BIT RTI_STATIC
LIBS += -L$$NDDSHOME/lib/$$TARGET_ARCH \
        -lnddscpp2z -lnddscz -lnddscorez $$SYSLIBS

INCLUDEPATH += $$NDDSHOME/lib/x64Linux3gcc5.4.0
DEPENDPATH += $$NDDSHOME/lib/x64Linux3gcc5.4.0
INCLUDEPATH += \
    $$NDDSHOME/include \
    $$NDDSHOME/include/ndds \
    $$NDDSHOME/include/ndds/hpp

#INCLUDEPATH += 3rdparty/libmodbus \
#               3rdparty/libmodbus/src \
#               3rdparty/qextserialport \
#               src/include/modbus \
#               src/include

#MODBUS = `pkg-config --libs --cflags libmodbus`
#CONFIG += PKGCONFIG
#PKGCONFIG += libmodbus

DISTFILES += \
    ../rti_workspace/5.3.1/examples/connext_dds/qos/reliable.xml \
    logo.png

RESOURCES +=
resource.qrc
