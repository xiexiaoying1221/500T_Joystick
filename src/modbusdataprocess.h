#ifndef MODBUSDATAPROCESS_H
#define MODBUSDATAPROCESS_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include "modbus/modbustcpcomm.h"

class ModbusDataProcess : public QObject
{
    Q_OBJECT
public:
    explicit ModbusDataProcess(QObject *parent = 0);
    ~ModbusDataProcess();

private:
    QTimer *recv_timer;
    QTimer *send_timer;
    QTimer *watchDog;
    QTimer *masterStartDelay;
    ModbusTCPComm modbusdata;
    QThread* dataThread;

    quint32 lastHeartBeats;
    bool watchDogOK;
private slots:
    void RefreshRecvData();
    void RefreshSendData();
    void RefreshWatchDog();
    void writeSwitch();
};

#endif // MODBUSDATAPROCESS_H
