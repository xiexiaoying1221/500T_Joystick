/*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   /*
    总体设置
*/

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "generalsettingwidget.h"
#include "ui_generalsettingwidget.h"

GeneralSettingWidget::GeneralSettingWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::GeneralSettingWidget)
{
    ui->setupUi(this);

    //手柄矫正窗口的初始化
    int dialogWidthWithSyn =  450;
    int dialogHeightWithSyn = 639;
    _prompt = new StickSettingWidget(0,
                                    QRect((WINDOWWIDTH - dialogWidthWithSyn) / 2 , (WINDOWHEIGHT - dialogHeightWithSyn)/2 , dialogWidthWithSyn , dialogHeightWithSyn));
    _prompt->raise();//上层显示
    _prompt->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    _prompt->setVisible(false);
    connect(_prompt,SIGNAL(promptFinished()),this,SLOT(promptFinished()));

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_5)));//"images/总体设置-日.png"
//    this->setPalette(p);

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());

    changeDNMode();

    connect(ui->leThrusterAlloc_,SIGNAL(clicked(bool)),this,SLOT(leThrusterAlloc_click()));
    connect(ui->leRateTurn_,SIGNAL(clicked(bool)),this,SLOT(leRateTurn_click()));
    connect(ui->leDraughtType_,SIGNAL(clicked(bool)),this,SLOT(leDraughtType_click()));
    connect(ui->leWindComp_,SIGNAL(clicked(bool)),this,SLOT(leWindComp_click()));
    connect(ui->leGainLevel_,SIGNAL(clicked(bool)),this,SLOT(leGainLevel_click()));
    connect(ui->leMaxRudderAngle_,SIGNAL(clicked(bool)),this,SLOT(leMaxRudderAngle_click()));

    ui->leThrusterAlloc_->setText(mode_thrAlloc == 1 ? "模式一" : "模式二");
    ui->leRateTurn_->setText(QString::number(set_rot * 60.0 ,'f',2));
    ui->leRateTurn_->setProperty("numinput", true);

    if(drughttype == 1)
         ui->leDraughtType_->setText(str_moshi1);//"模式一"
    else if(drughttype == 2 )
         ui->leDraughtType_->setText(str_moshi2);//"模式二"
    else
         ui->leDraughtType_->setText(str_moshi3);//"模式三"

    ui->leWindComp_->setText(flag_windcomp ? str_on : str_off);//"On" : "Off"

    if(gainlevel == 1)
        ui->leGainLevel_->setText(str_di);//"Low"
    else if(gainlevel == 2)
        ui->leGainLevel_->setText(str_zhong);//"Middle"
    else
        ui->leGainLevel_->setText(str_gao);//"High"

    ui->leMaxRudderAngle_->setText ( QString::number(set_maxRudderAngle,'f',2) );
    ui->leMaxRudderAngle_->setProperty("numinput", true);

    /*按键区 事件-槽*/
    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOK_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));


    ui->label_1->setFont(FONT_3);
    ui->label_2->setFont(FONT_3);
    ui->label_3->setFont(FONT_3);
    ui->label_4->setFont(FONT_3);
    ui->label_5->setFont(FONT_3);
    ui->label_6->setFont(FONT_3);
    ui->label_7->setFont(FONT_3);
    ui->label_8->setFont(FONT_3);
    ui->pbOk->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);
    ui->leDraughtType_->setFont(FONT_3);
    ui->pbStickSetting->setFont(FONT_3);
    ui->leThrusterAlloc_->setFont(FONT_3);
    ui->leGainLevel_->setFont(FONT_3);
    ui->leWindComp_->setFont(FONT_3);
    ui->leMaxRudderAngle_->setFont(FONT_3);
    ui->leRateTurn_->setFont(FONT_3);
}

GeneralSettingWidget::~GeneralSettingWidget()
{
    delete ui;
}

//白天、夜晚模式切换
void GeneralSettingWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_5)));//"images/总体设置-日.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_5->setStyleSheet(StyleSheet_DayColor);
        ui->label_6->setStyleSheet(StyleSheet_DayColor);
        ui->label_7->setStyleSheet(StyleSheet_DayColor);
        ui->label_8->setStyleSheet(StyleSheet_DayColor);

        p.setColor(QPalette::Text,QColor(COLOR_15));
        ui->leDraughtType_->setPalette(p);
        ui->leThrusterAlloc_->setPalette(p);
        ui->leRateTurn_->setPalette(p);
        ui->leWindComp_->setPalette(p);
        ui->leGainLevel_->setPalette(p);
        ui->leMaxRudderAngle_->setPalette (p);
        ui->pbStickSetting->setPalette(p);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_5)));//"images/总体设置-夜.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_5->setStyleSheet(StyleSheet_NgtColor);
        ui->label_6->setStyleSheet(StyleSheet_NgtColor);
        ui->label_7->setStyleSheet(StyleSheet_NgtColor);
        ui->label_8->setStyleSheet(StyleSheet_NgtColor);

        p.setColor(QPalette::Text,QColor(COLOR_23));
        ui->leDraughtType_->setPalette(p);
        ui->leThrusterAlloc_->setPalette(p);
        ui->leRateTurn_->setPalette(p);
        ui->leWindComp_->setPalette(p);
        ui->leGainLevel_->setPalette(p);
        ui->leMaxRudderAngle_->setPalette (p);
        ui->pbStickSetting->setPalette(p);
    }
}

void GeneralSettingWidget::leThrusterAlloc_click()
{
     if(ui->leThrusterAlloc_->text() == "模式一" || ui->leThrusterAlloc_->text() == "Mode 1")
         ui->leThrusterAlloc_->setText(str_moshi2);//"模式二"
     else
         ui->leThrusterAlloc_->setText(str_moshi1);//"模式一"
}

void GeneralSettingWidget::leRateTurn_click()
{

}

void GeneralSettingWidget::leDraughtType_click()
{
    if(ui->leDraughtType_->text() == "模式一"  || ui->leDraughtType_->text() == "Mode 1")
        ui->leDraughtType_->setText(str_moshi2);//"模式二"
    else if(ui->leDraughtType_->text() == "模式二"  || ui->leDraughtType_->text() == "Mode 2")
        ui->leDraughtType_->setText(str_moshi3);//"模式三"
    else
        ui->leDraughtType_->setText(str_moshi1);//"模式一"
}

void GeneralSettingWidget::leWindComp_click()
{
     if(ui->leWindComp_->text() == "Off" || ui->leWindComp_->text() == "关")
         ui->leWindComp_->setText(str_on);//"On"
     else
         ui->leWindComp_->setText(str_off);//"Off"
}

void GeneralSettingWidget::leGainLevel_click()
{
    if(ui->leGainLevel_->text() == "Low" || ui->leGainLevel_->text() == "低")
        ui->leGainLevel_->setText(str_zhong);//"Middle"
    else if(ui->leGainLevel_->text()=="Middle" || ui->leGainLevel_->text() == "中")
        ui->leGainLevel_->setText(str_gao);//"High"
    else
        ui->leGainLevel_->setText(str_di);//"Low"
}

void GeneralSettingWidget::leMaxRudderAngle_click(){

}


void GeneralSettingWidget::pbOK_clicked()
{
    bool isOk;
    mode_thrAlloc = ui->leThrusterAlloc_->text() == str_moshi1 ? 1 :2 ;//"模式一"
    set_rot = ui->leRateTurn_->text().toDouble(&isOk) / 60.0;
    if(!isOk)
        set_rot =0;

    set_maxRudderAngle = ui->leMaxRudderAngle_->text().toFloat(&isOk);
    if(!isOk)
        set_maxRudderAngle =0.0;

    if(ui->leDraughtType_->text() == "模式一"  || ui->leDraughtType_->text() == "Mode 1")
        drughttype = 1;
    else if(ui->leDraughtType_->text() == "模式二"  || ui->leDraughtType_->text() == "Mode 2")
        drughttype = 2;
    else
        drughttype = 3;

    flag_windcomp = ui->leWindComp_->text() == str_off ? 0 : 1;//"Off"

    if(ui->leGainLevel_->text() == "Low" || ui->leGainLevel_->text() == "低")
        gainlevel = 1;
    else if(ui->leGainLevel_->text() == "Middle" || ui->leGainLevel_->text() == "中")
        gainlevel = 2;
    else
        gainlevel = 3;

    emit ok_signal(this->objectName());
    //20161130增加，保存为文件
    saveParameters();
}
void GeneralSettingWidget::Refresh_changless_words()
{

    ui->label_1->setText(str_tuilifenpeimoshi_ZTSZ);

    ui->label_2->setText(str_shezhihuizhuanlv_ZTSZ);

    ui->label_3->setText(str_fenglibuchang_ZTSZ);

    ui->label_4->setText(str_zengyidengji_ZTSZ);

    ui->label_5->setText(str_chuanbochishuileixing_ZTSZ);

    ui->label_6->setText(str_zuidaduojiao_ZTSZ);

    ui->label_7->setText (danwei_du);

    ui->label_8->setText (danwei_dufen);

    ui->pbOk->setText(str_queding);

    ui->pbCancel->setText(str_quxiao);

    ui->pbStickSetting->setText(str_shezhishoubing);

    if(ui->leDraughtType_->text() == "Mode 1" || ui->leDraughtType_->text() == "模式一")
        ui->leDraughtType_->setText(str_moshi1);
    else if(ui->leDraughtType_->text() == "Mode 2" || ui->leDraughtType_->text() == "模式二")
        ui->leDraughtType_->setText(str_moshi2);
    else
        ui->leDraughtType_->setText(str_moshi3);


    if(ui->leThrusterAlloc_->text() == "Mode 1" || ui->leThrusterAlloc_->text() == "模式一")
            ui->leThrusterAlloc_->setText(str_moshi1);
        else
            ui->leThrusterAlloc_->setText(str_moshi2);


    if(ui->leGainLevel_->text() == "高" || ui->leGainLevel_->text() == "High")
        ui->leGainLevel_->setText(str_gao);
    else if(ui->leGainLevel_->text() == "中" || ui->leGainLevel_->text() == "Middle")
        ui->leGainLevel_->setText(str_zhong);
    else
        ui->leGainLevel_->setText(str_di);

    if(ui->leWindComp_->text() == "开" || ui->leWindComp_->text() == "On")
        ui->leWindComp_->setText(str_on);
    else
        ui->leWindComp_->setText(str_off);

}
void GeneralSettingWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

void GeneralSettingWidget::on_pbStickSetting_clicked()
{
    this->parentWidget()->setEnabled(false);
    _prompt->show();
}

void GeneralSettingWidget::promptFinished(){
   this->parentWidget()->setEnabled(true);
}

void GeneralSettingWidget::on_leRateTurn__editingFinished()
{
    QString res = ui->leRateTurn_->text();
    bool ok;
    float resReal = res.toFloat(&ok);
    if(ok){
        if(resReal > 60.0)      ui->leRateTurn_->setText(QString::number(60.0) );
        else if (resReal <0.0)  ui->leRateTurn_->setText(QString::number(0.0) );
    }
    else{
        ui->leRateTurn_->setText(QString::number(set_rot,'f',2 ) );
    }
}

void GeneralSettingWidget::on_leMaxRudderAngle__editingFinished()
{
    QString res = ui->leMaxRudderAngle_->text();
    bool ok;
    float resReal = res.toFloat(&ok);
    if(ok){
        if(resReal > 45.0)      ui->leMaxRudderAngle_->setText(QString::number(45.0) );
        else if (resReal <0.0)  ui->leMaxRudderAngle_->setText(QString::number(0.0) );
    }
    else{
        ui->leMaxRudderAngle_->setText(QString::number(set_maxRudderAngle,'f',2 ) );
    }
}
