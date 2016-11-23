#ifndef SUSIGPIO_H
#define SUSIGPIO_H

#include <QObject>
#include <QLibrary>
#include <Windows.h>
#include <tlhelp32.h>
#include <QDebug>
#include "gpio/REL_DEBUG.H"
#include "gpio/REL_ERRDRV.H"
#include "gpio/REL_ERRLIB.H"
#include "gpio/REL_SUSI.H"

#define OK 1
#define ERROR 0

typedef bool (*Fun1)( void );
typedef int  (*Fun )(int,int,int);
typedef bool (*Fun5)(BYTE,BYTE,DWORD *);

typedef void (*Fun2)();
typedef void (*Fun3)(int,int*);
typedef bool (*Fun4)(short,bool);

class SusiGpio : public QObject
{
    Q_OBJECT

private:
    explicit SusiGpio(QObject *parent = 0);
    static SusiGpio* _singleton;//全局单例模式

public:

    //全局单例模式
    static SusiGpio* getGpio( void );

    void init();
    bool setIODirection(int pinNum, int direction);
    bool writeIO(int pinNum, bool status);

    bool ready;
signals:

private:
    QLibrary* _lib;

    Fun1 _funInitial;
    Fun5 _funSetDirection;
    Fun4 _funSetStatus;
};

#endif // SUSIGPIO_H
