#ifndef USBRELAY_H
#define USBRELAY_H

#include <QObject>
#include <QTimer>
#include "igpio.h"
#include "usb_relay_device.h"


class UsbRelay : public QObject, public IGPIO
{
    Q_OBJECT

private:
    explicit UsbRelay(QObject *parent = 0);
    static UsbRelay* _singleton;//全局单例模式

public:

    //全局单例模式
    static UsbRelay* Instance( void );
    virtual ~UsbRelay();

    //////////////////////////////////////////start implement IGPIO
    void init(void);
    void setIODirection(int pinNum, int direction);
    void writeIO(int pinNum, bool status);
    bool readIO(int pinNum);
    bool isReady(void){return ready;}
    //////////////////////////////////////////IGPIO implement finished


private:
    int handle;
    bool ready;
    QTimer* checkTimer;

private slots:
    void stateCheck();

};

#endif // USBRELAY_H
