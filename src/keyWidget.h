#ifndef KEYWIDGET_H
#define KEYWIDGET_H

#include "qwidget.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "qrect.h"
#include "qpainter.h"
#include "globalSettings.h"
#include "promptwidget.h"
#include "qtimer.h"
#include "characterconversion.h"
#include "QDebug"


class KeyWidget : public QWidget{
    Q_OBJECT
public:
    KeyWidget(QWidget *parent=0, QRect keyRect = QRect(0,0,0,0));

    void keyAreaInit();
    void modeConfirm(QString msg, int set_mode);
    void modeCondition(int set_mode);

    void changeDNMode();
    void Refresh_keys_title();
    void refreshData();//按键区

private :
    QWidget *parent;

    PromptWidget *promptWidget;
    QPushButton *btn1;//视图
    QPushButton *btn2;//系统
    QPushButton *btn3;//日夜
    QPushButton *btn4;//报警
    QPushButton *btn5;//总体设置
    QPushButton *btn6;//启用设置
    QPushButton *btn7;//限值设置
    QPushButton *btn8;//系统设置

    QPushButton *btn9;//全推力
    QPushButton *btn10;//待机
    QPushButton *btn11;//当前艏向
    QPushButton *btn12;//手操
    QPushButton *btn13;//位置保持
    QPushButton *btn14;//自动舵
    QPushButton *btn15;//艏向设置
    QPushButton *btn16;//自动艏向
    QPushButton *btn17;//自动纵向
    QPushButton *btn18;//自动横向
    QPushButton *btn19;//船艏
    QPushButton *btn20;//船舯
    QPushButton *btn21;//船艉
    QPushButton *btn22;//令牌
//    QPushButton *btn23;//转出

    QPushButton *btn24;//调光
    QPushButton *btn25;//中英文转换-（原测试按钮）

    QPushButton *btn26;//隐藏按键区
    QPushButton *btn27;//仿真（20160918新增）

    int btn10FlashCount;//btn10闪烁计数器
    int btn12FlashCount;//btn12闪烁计数器
    int btn16FlashCount;//btn16闪烁计数器
    int btn19FlashCount;//btn19闪烁计数器
    int btn20FlashCount;//btn20闪烁计数器
    int btn21FlashCount;//btn21闪烁计数器
    int btn22FlashCount;//btn22闪烁计数器
    int btn27FlashCount;//btn27闪烁计数器

private slots:
    void btnFullForce_clicked();//全推力
    void btnStandby_clicked();//待机
    void btnManualOperation_clicked();//手操
    void btnPositionKepping_clicked();//位置保持
    void btnAutoRudder_clicked();//自动舵
    void btnAutoHeading_clicked();//自动艏向
    void btnAutoVertical_clicked();//自动纵向
    void btnAutoHorizontal_clicked();//自动横向
    void btnForePivot_clicked();//船艏
    void btnCentrePivot_click();//船舯
    void btnAftPivot_click();//船艉
//    void btnTurnIn_clicked();//转入
//    void btnTurnOut_clicked();//转出
    void btnSimulate_clicked();//仿真
    void btnCurrentHeading_clicked();//当前艏向


//    void btnTest_clicked();

public slots:
    void changeMode(bool);

public slots:
//    void changeCurrentHead();//改变当前艏向按钮颜色

    void fixKeyArea();//固定、释放 按键区域
    void unFixKeyArea();


};

#endif // KEYWIDGET_H
