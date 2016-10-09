#ifndef GPIOHANDLE_H
#define GPIOHANDLE_H

#include "qlibrary.h"
#include "qmessagebox.h"
#include <windows.h>
#include <tlhelp32.h>
#include <QDebug>

#include "define.h"
#include "REL_DEBUG.H"
#include "REL_EC_API.h"

#include "AlarmHandle.h"

#define STATUS int
#define OK 1
#define ERROR 0

typedef int (*Fun1)();
typedef int (*Fun)(int,int,int);

class GpioHandle : public QObject
{
    Q_OBJECT
public:
    GpioHandle(QObject *parent);
    void Gpio2Buzzer();
    int GpioInit();
private:


    QLibrary mylib;

    Fun1 open;
    Fun set;

    void GpioSet(int channel,int data);
};

#endif // GPIOHANDLE_H
