#ifndef GPIOJOYSTICK_H
#define GPIOJOYSTICK_H

#include <QObject>
#include <QLibrary>
#include <QMessageBox>
#include <Windows.h>
#include <tlhelp32.h>
#include <QDebug>
#include <QTimer>
#include "gpio/REL_DEBUG.H"
#include "gpio/REL_ERRDRV.H"
#include "gpio/REL_ERRLIB.H"
#include "gpio/REL_SUSI.H"

#include "AlarmHandle.h"

#define OK 1
#define ERROR 0

typedef bool (*Fun1)( void );
typedef int (*Fun)(int,int,int);
typedef bool (*Fun5)(BYTE,BYTE,DWORD *);

typedef void (*Fun2)();
typedef void (*Fun3)(int,int*);
typedef bool (*Fun4)(short,bool);

class GpioJoystick : public QObject
{
    Q_OBJECT
public:
    explicit GpioJoystick(QObject *parent = 0);
    void Gpio2Buzzer();
    void GpioInit();

signals:

private:
    QLibrary* m_lib;
    int setbuzzer;
    int setbuzzer_old;
    bool first;
    bool ready;

};

#endif // GPIOJOYSTICK_H
