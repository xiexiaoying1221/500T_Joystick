#ifndef BUZZERGOVERNOR_H
#define BUZZERGOVERNOR_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <Windows.h>
#include "gpio/REL_DEBUG.H"
#include "gpio/REL_ERRDRV.H"
#include "gpio/REL_ERRLIB.H"
#include "gpio/REL_SUSI.H"

typedef struct _buzzerGov{
    //控制位，外部程序操作蜂鸣器的接口
    bool buzzer1Hz;//1Hz间断音，谁触发谁复位
    bool buzzer05Hz;//0.5Hz间断音，谁触发谁复位
    bool buzzer2Hz;//2Hz间断音，谁触发谁复位
    bool buzzerContinuous;//持续响，谁触发谁复位
} buzzerGov_t;


class buzzerGovernor : public QObject
{
    Q_OBJECT
public:
    explicit buzzerGovernor(QObject *parent = 0);
    buzzerGov_t controlBits;
    bool ready;
signals:

private:
    QTimer* _t05;
    bool _sq05Hz,_sq1Hz,_sq2Hz;//方波
    long _countdown1Hz,_countdown05Hz,_countdown2Hz;
    int _counterBuzzer1Hz,_counterBuzzer2Hz,_counterBuzzer05Hz,_counterBuzzerContinuous;
    bool _buzzer;

private slots:
    void process(void);

public slots:
    void silence(void);

    void set1Hz(long during =-1);
    void reset1Hz(void);

    void set05Hz(long during =-1);
    void reset05Hz(void);

    void set2Hz(long during =-1);
    void reset2Hz(void);

    void setContinurous(long during =-1);
    void resetContinurous(void);
};


#endif // BUZZERGOVERNOR_H
