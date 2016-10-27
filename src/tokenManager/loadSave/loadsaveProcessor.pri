QT       += core xml xmlpatterns

SOURCES +=  $$PWD\loadsaveprocessorxml.cpp \
#	    $$PWD\common\basedevice.cpp \
            $$PWD\QAes\qaeswrap.cpp \
            $$PWD\QAes\aes.c


HEADERS  += $$PWD\iloadsaveprocessor.h \
            $$PWD\loadsaveprocessorxml.h \
#	    $$PWD\common\basedevice.h  \
#           $$PWD\common\ierrmsg.h    \
#           $$PWD\common\iloadsave.h  \
#           $$PWD\common\istatemsg.h  \
            $$PWD\QAes\qaeswrap.h \
            $$PWD\QAes\aes.h

INCLUDEPATH += $$PWD\
               $$PWD\common\
