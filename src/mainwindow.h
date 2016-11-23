#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlayout.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qtabwidget.h>
#include <qpushbutton.h>
#include <qrect.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <QDebug>
#include <MainViewWidget.h>
#include <titleWidget.h>
#include <infoWidget.h>
#include <keyWidget.h>
#include <headWidget.h>
#include <positionWidget.h>
#include <limitsetwidget.h>
#include <alarmlistwidget.h>
#include <softwareoperationwidget.h>
#include <positionreferencewidget.h>
#include <propellerwidget.h>
#include <sensorwidget.h>
#include <powerconsumptionwidget.h>
#include <deviceviewwidget.h>
#include <systemsettingwidget.h>
#include <systeminfowidget.h>
#include <generalsettingwidget.h>
#include <sensorenablewidget.h>
#include <propellerenablewidget.h>
#include <autoruddersettingwidget.h>
#include <headingsetpwidget.h>
#include <adjustingbrightnesswidget.h>
#include <promptwidget.h>
#include <systemstatuswidget.h>
#include "tokenwidget.h"
#include <globalSettings.h>
#include <dataCommit.h>
#include "serialcomm.h"
#include "AlarmHandle.h"
#include "characterconversion.h"
#include "buzzergovernor.h"



namespace Ui {
    class MainWindow;
}

//QColor cbColor;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void timer1Done();
    void timer2Done();

    void showKeyArea();//显示按键区
    void hideKeyArea(bool force =false );//隐藏按键区
    void childWidgetOkSlot(QString);//子控件确定信号处理槽
    void childWidgetCancleSlot(QString);//子控件取消信号处理槽

    /*按键区 按键对应槽  需切换视图*/
    void btnView_clicked();//视图
    void btnSystem_clicked();//系统
    void btnDayNight_clicked();//白天、晚上
    void btnAlarm_clicked();//警报
    void btnGeneralSetting_clicked();//总体设置
    void btnEnableSetting_clicked();//启用设置
    void btnLimitSetting_clicked();//限值设定
    void btnAutoRudderSetting_clicked();//自动舵设置
    void btnHeadingSetting_clicked();//艏向设置
    void btnTest_clicked();//测试
    void btnLightDim_clicked();//调光
    void btnTokenManager_clicked();//令牌切换

    //消声
    void noiseElimination_Pressed();
    void noiseElimination_Released();
    void noiseElimination_Clicked();



signals:
    void fixKeyArea_signal();//固定、释放 按键区域
    void unFixKeyArea_signal();
//    void changecurrenthead();//艏向设定后 当前艏向灯灭

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);

    void changeDayNightMode();


private:
    Ui::MainWindow *ui;

    QTimer *timer1;//定时给数据赋值
    QTimer *timer2;//定时刷新各窗体数据

    QPushButton *pbShowKeyArea;//显示按键区按钮
    QPushButton *pbNoiseElimination;//应答、消声

    //标题栏的长宽
    int titleLWidth ;
    int titleLHeight ;
    //按键区的长宽
    int keyAreaWidth;
    int keyAreaHeight ;
    //信息栏的长宽
    int infoLWidth ;
    int infoLHeight ;
    //艏向区的长宽
    int headAreaWidth;
    int headAreaHeight;
    //位置区的长宽
    int positionAreaWidth;
    int positionAreaHeight ;
    //视图区的长宽
    int viewAreaWidth;
    int viewAreaHeight ;
    //设置区的长宽
    int setAreaWidth;
    int setAreaHeight;

    //标题栏区域
    QRect titleLRect;
    //信息栏区域
    QRect infoLRect;
    //按键区域
    QRect keyAreaRect;
    //艏向区域
    QRect headAreaRect;//当前区域
    //位置区域
    QRect positionAreaRect;
    //视图区域
    QRect viewAreaRect;
    //设置区域(视图区-按键区)
    QRect setAreaRect;
    //调光窗口区域
    QRect adjustingbrightnessRect;

    MainViewWidget *viewWidget;
    TitleWidget *titleWidget;
    InfoWidget *infoWidget;
    KeyWidget *keyWidget;
    HeadWidget *headWidget;
    PositionWidget *positionWidget;
    LimitSetWidget *limitsetWidget;//限定值
    AlarmListWidget *alarmListWidget;//警报
    SoftwareOperationWidget *softwareOpeWidget;//软件升级和系统重启
    PositionReferenceWidget *positionReferenceWidget;//位置参考系统视图
    PropellerWidget *propellerwidget;//推进器
    SensorWidget *sensorwidget;//传感器
    PowerConsumptionWidget *powerconsumptionwidget;//功耗
    DeviceViewWidget *deviceviewwidget;//设备
    SystemSettingWidget *systemsettingwidget;//系统设置对话框
    SystemInfoWidget *systemInfoWidget;//系统信息
    GeneralSettingWidget *generalsettingwidget;//总体设置
    SensorEnableWidget *sensorenablewidget;//传感器启用
    PropellerEnableWidget *propellerenablewidget;//推进器启用
    AutoRudderSettingWidget *autoruddersettingwidget;//自动舵设置
    HeadingSetpWidget *headingsetpwidget;//艏向设置
    AdjustingBrightnessWidget *adjustingbrightnesswidget;//测试，调光按钮
    SystemStatusWidget *systemstatuswidget;//系统状态
    PromptWidget *promptwidget;
    TokenWidget *tokenWidget;
    SerialComm *serialcom;//串口
    CharacterConversion  *character;//字体

    QWidget *currentWidget;//当前部件
    QWidget *previousWidget;//上一个部件

    QString viewIndex;//视图当前显示索引
    QString systemIndex;//系统当前显示索引
    QString generalsetIndex;//总体设置显示索引
    QString enablesetIndex;//总体设置显示索引

    void Refresh_all_words();


};

#endif // MAINWINDOW_H
