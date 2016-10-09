#ifndef GPIOJOYSTICK_H
#define GPIOJOYSTICK_H

#include <QObject>
#include <QLibrary>
#include <QMessageBox>
#include <windows.h>
#include <tlhelp32.h>
#include <QDebug>

#include "gpio/define.h"
#include "gpio/REL_DEBUG.H"
#include "gpio/REL_ERRDRV.H"
#include "gpio/REL_ERRLIB.H"
#include "gpio/REL_SUSI.H"

#include "AlarmHandle.h"

#define OK 1
#define ERROR 0

typedef int (*Fun1)();
typedef int (*Fun)(int,int,int);

typedef void (*Fun2)();
typedef void (*Fun3)(int,int*);
typedef void (*Fun4)(short,bool);

class GpioJoystick : public QObject
{
    Q_OBJECT
public:
    explicit GpioJoystick(QObject *parent = 0);
    void Gpio2Buzzer();
    int GpioInit();

signals:

public slots:

};

#endif // GPIOJOYSTICK_H
