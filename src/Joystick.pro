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
    tokenwidget.h \
    buzzergovernor.h \
    sticksettingwidget.h \
    usrmanagewidget.h \
    usrloginwidget.h \
    promptwidgets/promptwidget.h \
    promptwidgets/promptwidgetwithsyn.h \
    promptwidgets/promptwidgetchangname.h \
    promptwidgets/promptwidgetchangpswd.h \
    promptwidgets/promptwidgetlogin.h \
    promptwidgets/promptwidgetusrnew.h \
    promptwidgets/promptwidgetusrsetting.h \
    GPIO/usbrelay.h \
    GPIO/serialrelay.h \
    GPIO/igpio.h

SOURCES += mainwindow.cpp \
    main.cpp \
    mainViewWidget.cpp \
    titleWidget.cpp \
    infoWidget.cpp \
    keyWidget.cpp \
    headWidget.cpp \
    positionWidget.cpp \
    limitsetwidget.cpp \
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
    modbus/modbustcpcomm.cpp \
    modbus/modbus.c \
    modbus/modbus-data.c \
    modbus/modbus-rtu.c \
    modbus/modbus-tcp.c \
    modbusdataprocess.cpp \
    tokenwidget.cpp \
    buzzergovernor.cpp \
    sticksettingwidget.cpp \
    usrmanagewidget.cpp \
    usrloginwidget.cpp \
    promptwidgets/promptwidget.cpp \
    promptwidgets/promptwidgetwithsyn.cpp \
    promptwidgets/promptwidgetchangname.cpp \
    promptwidgets/promptwidgetchangpswd.cpp \
    promptwidgets/promptwidgetlogin.cpp \
    promptwidgets/promptwidgetusrnew.cpp \
    promptwidgets/promptwidgetusrsetting.cpp \
    GPIO/usbrelay.cpp \
    GPIO/serialrelay.cpp

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
    headingsetpwidget.ui \
    tokenwidget.ui \
    usrmanagewidget.ui \
    usrloginwidget.ui

RESOURCES += \
    img.qrc

LIBS += \
        -LC:/Proj/Qt.711.2016.Joystick/lib/usbrelay -lusb_relay_device\
        -luser32\
        -lGdi32\
        -ladvapi32\
        -lWs2_32\

INCLUDEPATH += ../lib/usbrelay

include($PWD/../../lib/tokenManager/src/tokenManager.pri)
include($PWD/../../lib/usrManager/src/usrmanager.pri)
include($PWD/../../lib/inputMethod/src/inputnew/inputnew.pri)
include($PWD/../../lib/inputMethod/src/inputnum/inputnum.pri)


#如果是便携式操作站则启用，固定式则注释掉，编译前必须1.清除 2.执行qmake 3.编译
#DEFINES += PORTABLE_STATION
