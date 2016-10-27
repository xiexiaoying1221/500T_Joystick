QT       += core network
include(common\common.pri)
include(loadSave\loadsaveProcessor.pri)

SOURCES +=\
    $$PWD/tmpeer.cpp \
    $$PWD/tmtokenmanager.cpp

HEADERS  +=\
    $$PWD/tmpeer.h \
    $$PWD/tmtokenmanager.h

INCLUDEPATH += $$PWD\

DISTFILES += \
    $$PWD\../../HISTORY.txt \
    $$PWD\../../README.txt
