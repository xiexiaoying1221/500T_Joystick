#ifndef MODBUSTCPCOMM_H
#define MODBUSTCPCOMM_H

#define RDBFF_START_ADD 8192
#define RDBFF_LEN 110
#define WRBFF_START_ADD 24576
#define WRBFF_LEN 70


//#define DEBUG

#include <QObject>
#include <QList>
#include <QtNetwork>
#include <QUdpSocket>
#include <QTimer>
#include <QHostAddress>
#include "modbus/modbus.h"

class ModbusTCPComm: public QObject
{
Q_OBJECT
public:
    ModbusTCPComm();
    ~ModbusTCPComm();
    void startRoll();

    bool    connectOK;//连接正常
    bool    writeEnable;
    bool    readEnable;

    int   readBool_buff   (bool* value, qint16 add, qint16 offset);
    int   readUint32_buff (quint32* value, qint16 add);
    int   readFloat_buff  (float* value, qint16 add);

    int   writeBool_buff  (bool value, qint16 add, qint16 offset);
    int   writeUint32_buff(quint32 value, qint16 add);
    int   writeFloat_buff (float value, qint16 add);

private:
    QTimer *timer;
    QHostAddress ip;
    qint16 errCount;
    qint32 rollInterval;

    modbus_t* myConnection;
    uint16_t* readBuffer;
    uint16_t* writeBuffer;

    void customer(void);

private slots:
    void refreshData();




};




#endif // MODBUSTCPCOMM_H
