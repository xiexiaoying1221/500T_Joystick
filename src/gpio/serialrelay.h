#ifndef SERIALRELAY_H
#define SERIALRELAY_H

#include <QObject>
#include <QTimer>
#include <QSerialPort>

#include "igpio.h"

class SerialRelay : public QObject, public IGPIO
{
    Q_OBJECT

private:
    explicit SerialRelay(QObject *parent = 0);
    static SerialRelay* _singleton;//全局单例模式

public:

    //全局单例模式
    static SerialRelay* Instance( void );
    virtual ~SerialRelay();

    //////////////////////////////////////////start implement IGPIO
public slots:
    void init(void);
public:
    void setIODirection(int pinNum, int direction);
    void writeIO(int pinNum, bool status);
    bool readIO(int pinNum);
    bool isReady(void){return ready;}
    //////////////////////////////////////////IGPIO implement finished

private:

    bool ready;
    QSerialPort* port;
    quint8 state;
    QTimer* blankTimer;

private slots:
    void read(void);
};

#endif // SERIALRELAY_H
