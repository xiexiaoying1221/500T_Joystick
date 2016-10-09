#ifndef GPIORESPONSE_H
#define GPIORESPONSE_H


#include <QObject>

//#include "define.h"
//#include "REL_DEBUG.H"
//#include "REL_EC_API.h"
//#include "AlarmHandle.h"

#define ULONG unsigned long


class GpioResponse : public QObject
{
    Q_OBJECT
public:
    explicit GpioResponse(QObject *parent = 0);

    void GpioInit();
    void GpioOutput();
    void GpioInput();

signals:

public slots:


};

#endif // GPIORESPONSE_H
