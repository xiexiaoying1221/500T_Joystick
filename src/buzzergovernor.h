#ifndef BUZZERGOVERNOR_H
#define BUZZERGOVERNOR_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <Windows.h>
#include "gpio/susigpio.h"

typedef struct _buzzerGov{
    //控制位
    bool buzzer1Hz;//1Hz间断音，谁触发谁复位
    bool buzzer05Hz;//0.5Hz间断音，谁触发谁复位
    bool buzzer2Hz;//2Hz间断音，谁触发谁复位
    bool buzzerContinuous;//持续响，谁触发谁复位
} buzzerGov_t;


class buzzerGovernor : public QObject
{
    Q_OBJECT
private:
    static buzzerGovernor* _singleton;//全局单例模式
    explicit buzzerGovernor(QObject *parent = 0);

public:
    bool ready;

    //全局单例模式
    static buzzerGovernor* getBuzzerGovernor( void );

signals:

private:
    buzzerGov_t controlBits;
    SusiGpio* _gpio;
    QTimer* _t05;
    bool _sq05Hz,_sq1Hz,_sq2Hz;//方波
    long _countdown1Hz,_countdown05Hz,_countdown2Hz;
    int _counterBuzzer1Hz,_counterBuzzer2Hz,_counterBuzzer05Hz,_counterBuzzerContinuous;
    bool _buzzer;

private slots:
    void process(void);

public slots:

    void silence(void);//外部接口，全部消音

    void set1Hz(long during =-1);//外部接口，1Hz间断响，持续ms（-1表示永远）
    void reset1Hz(void);//外部接口，1Hz间断响关闭

    void set05Hz(long during =-1);//外部接口，0.5Hz间断响，持续ms（-1表示永远）
    void reset05Hz(void);//外部接口，0.5Hz间断响关闭

    void set2Hz(long during =-1);//外部接口，2Hz间断响，持续ms（-1表示永远）
    void reset2Hz(void);//外部接口，2Hz间断响关闭

    void setContinurous(long during =-1);//外部接口，连续响，持续ms（-1表示永远）
    void resetContinurous(void);//外部接口，连续响关闭
};


#endif // BUZZERGOVERNOR_H
