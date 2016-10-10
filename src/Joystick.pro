#-------------------------------------------------
#
# Project created by QtCreator 2016-10
#
#-------------------------------------------------

QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += mainwindow.h \
    mainViewWidget.h \
    titleWidget.h \
    infoWidget.h \
    keyWidget.h \
    headWidget.h \
    positionWidget.h \
    limitsetwidget.h \
    promptwidget.h \
    lineedit.h \
    alarmlistwidget.h \
    positionreferencewidget.h \
    powerconsumptionwidget.h \
    propellerwidget.h \
    sensorwidget.h \
    headingsetpwidget.h \
    titleWidget.h \
    generalsettingwidget.h \
    autoruddersettingwidget.h \
    deviceviewwidget.h \
    softwareoperationwidget.h \
    sensorenablewidget.h \
    propellerenablewidget.h \
    systeminfowidget.h \
    systemstatuswidget.h \
    adjustingbrightnesswidget.h \
    dataCommit.h \
    serialcomm.h \
    systemsettingwidget.h \
    AlarmHandle.h \
    headingsetpwidget.h \
    headingsetpwidget.h \
    characterconversion.h \
    globalSettings.h \
    gpiojoystick.h \
    modbus/config.h \
    modbus/modbus.h \
    modbus/modbus-private.h \
    modbus/modbus-rtu.h \
    modbus/modbus-rtu-private.h \
    modbus/modbus-tcp.h \
    modbus/modbus-tcp-private.h \
    modbus/modbus-version.h \
    modbus/stdint.h \
    modbus/modbustcpcomm.h\
    modbusdataprocess.h \
    gpio/define.h \
    gpio/REL_DEBUG.H \
    gpio/REL_SUSI.H \
    gpio/REL_ERRLIB.H \
    gpio/REL_ERRDRV.H

SOURCES += mainwindow.cpp \
    main.cpp \
    mainViewWidget.cpp \
    titleWidget.cpp \
    infoWidget.cpp \
    keyWidget.cpp \
    headWidget.cpp \
    positionWidget.cpp \
    limitsetwidget.cpp \
    promptwidget.cpp \
    lineedit.cpp \
    alarmlistwidget.cpp \
    positionreferencewidget.cpp \
    powerconsumptionwidget.cpp \
    propellerwidget.cpp \
    sensorwidget.cpp \
    headingsetpwidget.cpp \
    generalsettingwidget.cpp \
    autoruddersettingwidget.cpp \
    deviceviewwidget.cpp \
    softwareoperationwidget.cpp \
    sensorenablewidget.cpp \
    propellerenablewidget.cpp \
    systeminfowidget.cpp \
    systemstatuswidget.cpp \
    adjustingbrightnesswidget.cpp \
    dataCommit.cpp \
    serialcomm.cpp \
    systemsettingwidget.cpp \
    AlarmHandle.cpp \
    characterconversion.cpp \
    gpiojoystick.cpp \
    modbus/modbustcpcomm.cpp \
    modbus/modbus.c \
    modbus/modbus-data.c \
    modbus/modbus-rtu.c \
    modbus/modbus-tcp.c \
    modbusdataprocess.cpp \

FORMS += mainwindow.ui \
    limitsetwidget.ui \
    alarmlistwidget.ui \
    positionreferencewidget.ui \
    powerconsumptionwidget.ui \
    propellerwidget.ui \
    sensorwidget.ui \
    generalsettingwidget.ui \
    autoruddersettingwidget.ui \
    deviceviewwidget.ui \
    softwareoperationwidget.ui \
    sensorenablewidget.ui \
    propellerenablewidget.ui \
    systeminfowidget.ui \
    systemstatuswidget.ui \
    adjustingbrightnesswidget.ui \
    systemsettingwidget.ui \
    headingsetpwidget.ui

RESOURCES += \
    img.qrc

LIBS += -LC:\Proj\Qt.711.2016.JoyStick\src\
        -LC:\Proj\Qt.711.2016.JoyStick\src\gpio\
        -lgdi32\
        -luser32\
        -ladvapi32\
        -lWs2_32\
        -lSusi
