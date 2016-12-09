#ifndef STICKSETTINGWIDGET_H
#define STICKSETTINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QTimer>
#include "globalSettings.h"
#include "serialcomm.h"

class StickSettingWidget : public QWidget
{
    Q_OBJECT
public:
    StickSettingWidget(QWidget *parent=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickNext();
    void clickPrevious();
    void clickCancel();
    void clickSet();

private:
    QLabel *_lblDirection;//指导性说明
    QLabel *_lblState;//状态说明

    QPushButton *_pbCancel;//退出放弃
    QPushButton *_pbPrevious;//上一个
    QPushButton *_pbNext;//下一个&完成
    QPushButton *_pbSet;//设置

    SerialComm* _comm;

    int _state;//步骤，1-XMax，2-XMin，3-YMax，4—YMin，5-ZMax，6-ZMin，7-AllZero，8-finished！
    //定义：X轴向前为Max，Y轴向右为Max，Z轴向右转为Max
    float _stickXMax, _stickXZero, _stickXMin;
    float _stickYMax, _stickYZero, _stickYMin;
    float _stickZMax, _stickZZero, _stickZMin;

protected:
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);
signals:
    void promptFinished(void);

public:
    void changeDNMode();
    void Refresh_changless_words();
};

#endif // STICKSETTINGWIDGET_H
