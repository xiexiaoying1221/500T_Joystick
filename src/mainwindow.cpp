#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui/QtGui>
#include <QString>
#include "serialcomm.h"

QColor cbColor = COLOR_1;
QColor cfColor = COLOR_2;


//pSensor_data psensor_data = (struct _Sensor_Data *)malloc(sizeof(struct _Sensor_Data));
//pOT_SettingData pot_SettingData = (struct _OT_SettingData*)malloc(sizeof(struct _OT_SettingData));

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);
    //qApp->setOverrideCursor(QCursor(Qt::BlankCursor));//隐藏光标

    QPalette p;
    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_10)));//"images/backgournd.png"
    this->setPalette(p);

    //标题栏的长宽
    titleLWidth = WINDOWWIDTH;
    titleLHeight = WINDOWHEIGHT * TITLE_HEIGHT_PERCENTAGE;
    //信息栏的长宽
    infoLWidth = WINDOWWIDTH;
    infoLHeight = WINDOWHEIGHT * INFO_HEIGHT_PERCENTAGE;
    //按键区的长宽
    keyAreaWidth = WINDOWWIDTH * KEY_WIDTH_PERCENTAGE;
    keyAreaHeight = (WINDOWHEIGHT * VIEW_HEIGHT_PERCENTAGE);
    //艏向区的长宽
    headAreaWidth = WINDOWWIDTH* HEAD_WIDTH_PERCENTAGE;
    headAreaHeight = WINDOWHEIGHT * HEAD_HEIGHT_PERCENTAGE ;
    //位置区的长宽
    positionAreaWidth = WINDOWWIDTH * POSITION_WIDTH_PERCENTAGE;
    positionAreaHeight =WINDOWHEIGHT * POSITION_HEIGHT_PERCENTAGE;
    //视图区的长宽
    viewAreaWidth =(WINDOWWIDTH * VIEW_WIDTH_PERCENTAGE);
    viewAreaHeight =(WINDOWHEIGHT * VIEW_HEIGHT_PERCENTAGE);
    //设置区的长宽
    setAreaWidth = viewAreaWidth - keyAreaWidth;
    setAreaHeight = viewAreaHeight;

    /*主界面边线也占有宽度*/
    //标题栏区域
    titleLRect.setRect(2,0,titleLWidth-2,titleLHeight);
    //信息栏区域
     infoLRect.setRect(2,titleLHeight,infoLWidth-4,infoLHeight);
    //按键区域
    keyAreaRect.setRect(1,titleLHeight + infoLHeight+2 ,keyAreaWidth-2,keyAreaHeight);
    //艏向区域
    headAreaRect.setRect(viewAreaWidth+2,titleLHeight+infoLHeight+2,headAreaWidth-2,headAreaHeight-2);

    //位置区域
    positionAreaRect.setRect(viewAreaWidth,titleLHeight + infoLHeight + headAreaHeight+3,
                             positionAreaWidth,positionAreaHeight);
    //视图区域
    viewAreaRect.setRect(2,titleLHeight+infoLHeight,viewAreaWidth,viewAreaHeight);

    //设置区域
    setAreaRect.setRect(keyAreaWidth,titleLHeight + infoLHeight+2,setAreaWidth,setAreaHeight);

    //调光页面区域
    adjustingbrightnessRect.setRect(keyAreaWidth,titleLHeight + infoLHeight+2,keyAreaWidth-2+ setAreaWidth,setAreaHeight );


    setWindowFlags(Qt::FramelessWindowHint);
    character->Refresh_character(State_language);

    daynight_mode = DAYMODE;//选择白天模式

    titleWidget = new TitleWidget(this, titleLRect);
    titleWidget->setObjectName("titleWidget");

    infoWidget = new InfoWidget(this, infoLRect);
    infoWidget->setObjectName("infoWidget");

    headWidget = new HeadWidget(this, headAreaRect);
    headWidget->setObjectName("headWidget");

    positionWidget = new PositionWidget(this,positionAreaRect);
    positionWidget->setObjectName("positionWidget");

    viewWidget = new MainViewWidget(this, viewAreaRect);
    viewWidget->setObjectName("v1");


    limitsetWidget = new LimitSetWidget(this, setAreaRect);
    limitsetWidget->setObjectName("ls");
    limitsetWidget->setVisible(false);

    alarmListWidget = new AlarmListWidget(this,QRect(0,0,WINDOWWIDTH,WINDOWHEIGHT));
    alarmListWidget->setObjectName("alarmListWidget");
    alarmListWidget->setVisible(false);

    positionReferenceWidget = new PositionReferenceWidget(this, viewAreaRect);
    positionReferenceWidget->setObjectName("v4");
    positionReferenceWidget->setVisible(false);

    propellerwidget = new PropellerWidget(this,viewAreaRect);
    propellerwidget->setObjectName("v2");
    propellerwidget->setVisible(false);

    sensorwidget = new SensorWidget(this, viewAreaRect);
    sensorwidget->setObjectName("v3");
    sensorwidget->setVisible(false);

    powerconsumptionwidget = new PowerConsumptionWidget(this, viewAreaRect);
    powerconsumptionwidget->setObjectName("v5");
    powerconsumptionwidget->setVisible(false);

    deviceviewwidget = new DeviceViewWidget(this,viewAreaRect);
    deviceviewwidget->setObjectName("s1");
    deviceviewwidget->setVisible(false);

    systemstatuswidget = new SystemStatusWidget(this, viewAreaRect);
    systemstatuswidget->setObjectName("s2");
    systemstatuswidget->setVisible(false);

    systemInfoWidget = new SystemInfoWidget(this,viewAreaRect);
    systemInfoWidget->setObjectName("s3");
    systemInfoWidget->setVisible(false);

    adjustingbrightnesswidget = new AdjustingBrightnessWidget(this,setAreaRect);
    adjustingbrightnesswidget->setVisible(false);
    adjustingbrightnesswidget->setObjectName("adjustingbrightnesswidget");

    autoruddersettingwidget = new AutoRudderSettingWidget(this,setAreaRect);
    autoruddersettingwidget->setVisible(false);
    autoruddersettingwidget->setObjectName("as");

    headingsetpwidget = new HeadingSetpWidget(this,setAreaRect);
    headingsetpwidget->setVisible(false);
    headingsetpwidget->setObjectName("headingsetpwidget");


    generalsettingwidget = new GeneralSettingWidget(this,setAreaRect);
    generalsettingwidget->setVisible(false);
    generalsettingwidget->setObjectName("gs1");

    systemsettingwidget = new SystemSettingWidget(this,setAreaRect);
    systemsettingwidget->setObjectName("systemsettingwidget");
    systemsettingwidget->setVisible(false);

    sensorenablewidget = new SensorEnableWidget(this,setAreaRect);//传感器启用
    sensorenablewidget->setObjectName("es1");
    sensorenablewidget->setVisible(false);

    propellerenablewidget = new PropellerEnableWidget(this,setAreaRect);//推进器启用
    propellerenablewidget->setObjectName("es2");
    propellerenablewidget->setVisible(false);

    tokenWidget = new TokenWidget(this,setAreaRect);//令牌切换
    tokenWidget->setObjectName("tokenwidget");
    tokenWidget->setVisible(false);

    keyWidget = new KeyWidget(this,keyAreaRect);
    keyWidget->setObjectName("keyWidget");
    keyWidget->setVisible(false);
    keyWidget->raise();//上层显示
//    headingsetpwidget->raise();

    /*应答、消声*/
    pbNoiseElimination = new QPushButton(this);
    pbNoiseElimination->setFocusPolicy(Qt::NoFocus);
    pbNoiseElimination->setGeometry(10,38,229,43);
    pbNoiseElimination->setVisible(true);
    pbNoiseElimination->setStyleSheet("border-image:url(:/images/ack-up.png);");//ack-up1.png
    pbNoiseElimination->setFont(FONT_3);//xxy
    pbNoiseElimination->setText(btnstr_yingda+"      ");//xxy
    pbNoiseElimination->setWindowFlags(Qt::WindowStaysOnTopHint);
    pbNoiseElimination->setFocusPolicy(Qt::NoFocus);
    /*消声事件-槽*/
//    connect(pbNoiseElimination,SIGNAL(pressed()),SLOT(noiseElimination_Pressed()));
//    connect(pbNoiseElimination,SIGNAL(released()),SLOT(noiseElimination_Released()));
    connect(pbNoiseElimination,SIGNAL(clicked()),SLOT(noiseElimination_Clicked()));



    //显示按键区
    pbShowKeyArea = new QPushButton(this);
    pbShowKeyArea->setFocusPolicy(Qt::NoFocus);
    pbShowKeyArea->setGeometry(2,324,40,130);
    pbShowKeyArea->setVisible(true);
    pbShowKeyArea->setStyleSheet("background-image:url(:/images/keydisap.png); border-style:flat; background-repeat: no-repeat;");
    pbShowKeyArea->setWindowFlags(Qt::WindowStaysOnTopHint);

    currentWidget = viewWidget;

    connect(pbShowKeyArea,SIGNAL(clicked()),SLOT(showKeyArea()));


//-----------将所有需要中英文切换的字符串赋值-add by xxy---初始化所有不变的文字部分------------------------------------
//    character->Refresh_character("Chinese");
//    sensorwidget->Refresh_changless_words();
//    propellerwidget->Refresh_changless_words();
//    limitsetWidget->Refresh_changless_words();
//    Refresh_Alarm_words();
//    systemInfoWidget->Refresh_changless_words();
//    systemstatuswidget->Refresh_changless_words();
//    powerconsumptionwidget->Refresh_changless_words();
     Refresh_all_words();

    //按键区 信号-槽
    connect(this,SIGNAL(fixKeyArea_signal()),keyWidget,SLOT(fixKeyArea()));
    connect(this,SIGNAL(unFixKeyArea_signal()),keyWidget,SLOT(unFixKeyArea()));
    //按键区 当前艏向灯灭
//    connect(this,SIGNAL(changecurrenthead()),keyWidget,SLOT(changeCurrentHead()));

    serialcom = new SerialComm;
    serialcom->OpenMyCom();

    //定时给数据赋值
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),SLOT(timer1Done()));
    timer1->start(500);

    gpiohandle = new GpioJoystick(this);
    gpiohandle->GpioInit();

    //定时刷新各窗体数据
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),SLOT(timer2Done()));
    timer2->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void MainWindow::timer1Done(){
    serialcom->sendMyCom();
    serialcom->readMyCom();
//    HandleWind();
//    ControlMain();
//    RunShipModel();
//    AlarmHandle();
    EnableBuzzer();

    AlarmListMain();

    gpiohandle->Gpio2Buzzer();


}

void MainWindow::timer2Done(){

    if(titleWidget->isVisible()) titleWidget->refreshData();//标题行 时间
    if(infoWidget->isVisible()) infoWidget->refreshData();
    if(viewWidget->isVisible()) viewWidget->refreshData();//刷新主视图区
    if(headWidget->isVisible()) headWidget->refreshData();//刷新艏向区
    if(positionWidget->isVisible()) positionWidget->refreshData();//刷新位置区

    if(alarmListWidget->isVisible()) alarmListWidget->refreshData();//警告列表
    if(positionReferenceWidget->isVisible()) positionReferenceWidget->refreshData();//位置参考视图
    if(propellerwidget->isVisible()) propellerwidget->refreshData();//推进器
    if(sensorwidget->isVisible()) sensorwidget->refreshData();//传感器
    if(powerconsumptionwidget->isVisible()) powerconsumptionwidget->refreshData();//功率视图
    if(keyWidget->isVisible() ) keyWidget->refreshData();//按键区

    //qDebug(QString("propellerenablewidget->isVisible()=%1").arg(propellerenablewidget->isVisible()).toLatin1());

    if(propellerenablewidget->isVisible()) propellerenablewidget->refreshData();//推进器设置


    if(sensorenablewidget->isVisible()) sensorenablewidget->refreshData();//传感器设置
    if(systemstatuswidget->isVisible()) systemstatuswidget->refreshData();//系统状态视图


    tokenWidget->refreshData();//令牌功能刷新
}

/*改变白天、夜晚模式*/
void MainWindow::changeDayNightMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_10)));//"images/backgournd.png"
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_10)));//"images/backgournd_night.png"

    }

    this->setPalette(p);

    viewWidget->changeDNMode();
    headWidget->changeDNMode();
    positionWidget->changeDNMode();
    alarmListWidget->changeDNMode();
    limitsetWidget->changeDNMode();
    powerconsumptionwidget->changeDNMode();
    headingsetpwidget->changeDNMode();
    generalsettingwidget->changeDNMode();
    propellerwidget->changeDNMode();
    systemsettingwidget->changeDNMode();
    propellerenablewidget->changeDNMode();
    keyWidget->changeDNMode();
    systemstatuswidget->changeDNMode();
    systemInfoWidget->changeDNMode();
    sensorwidget->changeDNMode();
    sensorenablewidget->changeDNMode();
    adjustingbrightnesswidget->changeDNMode();
    deviceviewwidget->changeDNMode();
    positionReferenceWidget->changeDNMode();
    tokenWidget->changeDNMode();
}


void MainWindow::showKeyArea(){
    keyWidget->setVisible(true);
    pbShowKeyArea->setVisible(false);
}

void MainWindow::hideKeyArea(bool force){
    QString objName =currentWidget->objectName();

    if(objName.startsWith("gs") || objName.startsWith("es")
               || objName.startsWith("ls") || objName.startsWith("as")
               || objName.startsWith("systemsettingwidget") || objName.startsWith("headingsetpwidget")
               || objName.startsWith("tokenwidget" ) || objName.startsWith("adj")){
        if(!force){
            return;
        }
    }
    keyWidget->setVisible(false);
    pbShowKeyArea->setVisible(true);
}



/*按键区 按键处理槽*/

//void MainWindow::btnTest_clicked()//测试
//{
//    QPushButton *pb = (QPushButton*)QObject::sender();


//    bool normal = pb->styleSheet().contains("border-image:url(:/images/white");

//    if( normal )
//    {
//        pb->setStyleSheet("border-image:url(:/images/greenbtn_a6.png);");
//    }
//    else
//    {
//        pb->setStyleSheet("border-image:url(:/images/whitebtn_a6.png);");
//    }
//}
void MainWindow::Refresh_all_words()
{
    character->Refresh_character(State_language);

    Refresh_Alarm_words();//

    sensorwidget->Refresh_changless_words();
    keyWidget->Refresh_keys_title();
    propellerwidget->Refresh_changless_words();
    limitsetWidget->Refresh_changless_words();

    alarmListWidget->Refresh_changless_words();
    systemInfoWidget->Refresh_changless_words();
    systemstatuswidget->Refresh_changless_words();
    generalsettingwidget->Refresh_changless_words();
    sensorenablewidget->Refresh_changless_words();
    systemsettingwidget->Refresh_changless_words();
    powerconsumptionwidget->Refresh_changless_words();

    //----------------------
    pbNoiseElimination->setFont(FONT_3);//xxy
    pbNoiseElimination->setText(btnstr_yingda+"      ");//xxy
    //------------------------

    propellerenablewidget->Refresh_changless_words();
    positionReferenceWidget->Refresh_changless_words();

    adjustingbrightnesswidget->Refresh_changless_words();
    deviceviewwidget->Refresh_changless_words();

    headingsetpwidget->Refresh_changless_words();
    titleWidget->Refresh_changlese_words();
    tokenWidget->Refresh_changlese_words();

}

void MainWindow::btnTest_clicked()//中英文切换
{
//    QPushButton *pb = (QPushButton*)QObject::sender();


    if(State_language == "Chinese")
    {
         State_language = "English";
    }
    else
    {
        State_language = "Chinese";
    }

    Refresh_all_words();


}

void MainWindow::btnLightDim_clicked()//调光
{
        if(currentWidget != NULL)
        {
            if(currentWidget->objectName() != adjustingbrightnesswidget->objectName())
                 currentWidget->setVisible(false);
            else
                return;
        }
        adjustingbrightnesswidget->setVisible(true);

        previousWidget = currentWidget;
        currentWidget = adjustingbrightnesswidget;

}
//令牌切换
void MainWindow::btnTokenManager_clicked(){

    if(currentWidget != NULL)
    {
        if(currentWidget->objectName() != tokenWidget->objectName())
             currentWidget->setVisible(false);
        else
            return;
    }
    tokenWidget->setVisible(true);

    previousWidget = currentWidget;
    currentWidget = tokenWidget;

}

void MainWindow::btnView_clicked()//视图
{


    QString objectName = currentWidget->objectName();
    int index = 0;
    bool ok;


    if(!objectName.startsWith('v'))
    {
        currentWidget->setVisible(false);
    }
    else
    {
        index = objectName.mid(1).toInt(&ok);
//        qDebug("index is %d,",index);
//        qDebug()<<"objectname:"<<objectName;
        if(ok)
        {
            if(index == 3) index = 1;
            else index += 1;
        }
        else
            index = 1;
        viewIndex = QString("v%1").arg(index);

    }

    previousWidget = currentWidget;



    if(viewIndex == "v4")//显示位置参考系统视图
    {
        viewWidget->setVisible(false);
        positionReferenceWidget->setVisible(true);
//        objectName = viewWidget->objectName();
        currentWidget = positionReferenceWidget;
    }
    else if(viewIndex == "v2")//显示推进器视图
    {
//        positionReferenceWidget->setVisible(false);
        viewWidget->setVisible(false);
        propellerwidget->setVisible(true);
        currentWidget = propellerwidget;
    }
    else if(viewIndex == "v3")//显示传感器视图
    {
        propellerwidget->setVisible(false);
        sensorwidget->setVisible(true);
//        objectName = propellerwidget->objectName();
        currentWidget = sensorwidget;
    }
    else if(viewIndex == "v5")//显示功耗
    {
        sensorwidget->setVisible(false);
        powerconsumptionwidget->setVisible(true);
//        objectName = sensorwidget->objectName();
        currentWidget = powerconsumptionwidget;
    }
    else//v1
    {
 //       powerconsumptionwidget->setVisible(false);
        sensorwidget->setVisible(false);
        viewWidget->setVisible(true);
        currentWidget = viewWidget;
    }
}

void MainWindow::btnSystem_clicked()//系统
{

    QString objectName = currentWidget->objectName();

    if(!objectName.startsWith('s'))//从之前位置开始显示
    {
        currentWidget->setVisible(false);
    }
    else
    {
        bool ok;

        int index = objectName.mid(1).toInt(&ok);
        if(ok)
        {
            if(index == 4) index = 1;
            else index += 1;
        }
        else
            index = 1;
        systemIndex= QString("s%1").arg(index);
    }

    previousWidget = currentWidget;


    if(systemIndex == "s2")//显示系统状态
    {
        deviceviewwidget->setVisible(false);
        systemstatuswidget->setVisible(true);
        currentWidget = systemstatuswidget;
    }
    else if(systemIndex == "s3")//显示信息视图
    {
        systemstatuswidget->setVisible(false);
        systemInfoWidget->setVisible(true);
        currentWidget = systemInfoWidget;
    }
    else
    {
        systemInfoWidget->setVisible(false);
        deviceviewwidget->setVisible(true);
        currentWidget = deviceviewwidget;
    }
}

void MainWindow::btnDayNight_clicked()//白天、晚上
{
    QPushButton *pb = qobject_cast<QPushButton *>(sender());
    if(daynight_mode == DAYMODE)
    {
        pb->setText(str_baitian);
        daynight_mode = NIGHTMODE;
    }
    else
    {
        pb->setText(str_wanshang);
        daynight_mode = DAYMODE;
    }

    changeDayNightMode();
}

void MainWindow::btnAlarm_clicked()//警报
{
    if(currentWidget != NULL)
    {
        if(currentWidget->objectName() != alarmListWidget->objectName())
             currentWidget->setVisible(false);
        else
            return;
    }
    alarmListWidget->setVisible(true);

    previousWidget = currentWidget;
    currentWidget = alarmListWidget;

    hideKeyArea();
}

void MainWindow::btnGeneralSetting_clicked()//总体设置
{


    if(currentWidget != NULL)
    {
        if(currentWidget->objectName() != generalsettingwidget->objectName())
             currentWidget->setVisible(false);
        else
            return;
    }
    generalsettingwidget->setVisible(true);

    previousWidget = currentWidget;
    currentWidget = generalsettingwidget;
}

void MainWindow::btnEnableSetting_clicked()//启用设置
{
    QString objectName = currentWidget->objectName();

    if(!objectName.startsWith("es")){
        currentWidget->setVisible(false);
    }
    else{
        bool ok;
        int index = objectName.mid(2).toInt(&ok);
        if(ok){
            if(index == 6) index = 1;
            else index += 1;
        }
        else
            index = 1;
        viewIndex = QString("es%1").arg(index);
    }

    previousWidget = currentWidget;
    if(viewIndex == "es2")//显示位置参考系统
    {
        propellerenablewidget->setVisible(true);
        sensorenablewidget->setVisible(false);
        currentWidget = propellerenablewidget;
    }
    else
    {
        propellerenablewidget->setVisible(false);
        sensorenablewidget->setVisible(true);
        currentWidget = sensorenablewidget;
    }
//    emit fixKeyArea_signal();
}

void MainWindow::btnLimitSetting_clicked()//限值设定
{
    if(currentWidget != NULL)
    {
        if(currentWidget->objectName() != limitsetWidget->objectName())
             currentWidget->setVisible(false);
        else
            return;
    }
    limitsetWidget->setVisible(true);

    previousWidget = currentWidget;
    currentWidget = limitsetWidget;
//    emit fixKeyArea_signal();
}

void MainWindow::btnHeadingSetting_clicked()//艏向设定
{
    if(currentWidget != NULL)
    {
        if(currentWidget->objectName() != headingsetpwidget->objectName())
             currentWidget->setVisible(false);
        else
            return;
    }

    headingsetpwidget->setVisible(true);
    headingsetpwidget->refreshData ();
    previousWidget = currentWidget;
    currentWidget = headingsetpwidget;
}

void MainWindow::btnAutoRudderSetting_clicked()//自动舵设置 -- 改为系统设置
{
    if(currentWidget != NULL)
    {
        if(currentWidget->objectName() != systemsettingwidget->objectName())
             currentWidget->setVisible(false);
        else
            return;
    }
    systemsettingwidget->setVisible(true);
    previousWidget = currentWidget;
    currentWidget = systemsettingwidget;
}

/*-----------------------------消声应答---------------------------*/
void MainWindow::noiseElimination_Pressed()
{
    Sleep(1000);
//    bool normal = pbNoiseElimination->styleSheet().contains("border-image:url(:/images/ack-up");

//    if( normal )
//    {
        pbNoiseElimination->setStyleSheet("border-image:url(:/images/ack-down.png);");//ack-down1.png
        btn_answer = 1;
//    }
//    else
//    {
//        pbNoiseElimination->setStyleSheet("border-image:url(:/images/ack-up1.png);");
//        btn_answer = 0;
//    }

}

void MainWindow::noiseElimination_Released()
{
        pbNoiseElimination->setStyleSheet("border-image:url(:/images/ack-up.png);");//ack-up1
        btn_answer = 0;
 }

void MainWindow::noiseElimination_Clicked()
{
    pbNoiseElimination->setStyleSheet("border-image:url(:/images/ack-down.png);");//ack-down1.png
    btn_answer = 1;

    /*500ms后 弹起*/
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),SLOT(noiseElimination_Released()));
    timer->setSingleShot(true);//只执行一次
    timer->start(300);
}



void MainWindow::childWidgetOkSlot(QString objectName)//子控件确定信号处理槽
{

//    if(objectName == "headingsetpwidget")
//    {
//        emit changecurrenthead();
//    }
//    currentWidget->setVisible(false);
//    previousWidget->setVisible(true);

//    QWidget *tempWidget= currentWidget;

//    currentWidget = previousWidget;
//    previousWidget = tempWidget;

//    qDebug("ddddddddddddddddddddddddddddddfffffffffffffffffffffffffffffffffffffffffffffffff");

//    if(!currentWidget->objectName().startsWith("es")
//            && !currentWidget->objectName().startsWith("gs"))
//    emit unFixKeyArea_signal();

    btnView_clicked();
}

void MainWindow::childWidgetCancleSlot(QString objectName)//子控件取消信号处理槽
{
//    currentWidget->setVisible(false);
//    previousWidget->setVisible(true);

//    QWidget *tempWidget= currentWidget;

//    currentWidget = previousWidget;
//    previousWidget = tempWidget;

//    if(!currentWidget->objectName().startsWith("es")
//            && !currentWidget->objectName().startsWith("gs"))
//    emit unFixKeyArea_signal();

    btnView_clicked();
}

void MainWindow::paintEvent(QPaintEvent *)
{

}
