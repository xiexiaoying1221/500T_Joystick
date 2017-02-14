#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QObject>
#include <QStringList>
#include <QRegExp>
#include <QSerialPort>
#include <QTimer>
#include "globalSettings.h"
#include "dataCommit.h"

//仿真开关
//#define SIMULATION

class SerialComm : public QObject
{
    Q_OBJECT
public:

    float rawX,rawY,rawZ;
    static SerialComm* Instance(void);//全局单例模式
    bool stateError;

signals:

private:
    explicit SerialComm(QObject *parent = 0);
    static SerialComm* _singleton;//全局单例模式
//    static float joystick_x_old[5];
//    static float joystick_y_old[5];
//    static float joystick_z_old[5];
	QString myCom_data;
    QSerialPort * myCom;
    QTimer* _sendTimer;
    QTimer* _overTime;
public slots:
    void readMyCom();
    void sendMyCom();
    void OpenMyCom();
    void HandleMyComData();
    void closeMyCom();
    void overTimeError();
private slots:
};

#endif // SERIALCOMM_H
