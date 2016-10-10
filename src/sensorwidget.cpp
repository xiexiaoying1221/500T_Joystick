/*
    传感器视图
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "sensorwidget.h"
#include "ui_sensorwidget.h"

SensorWidget::SensorWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::SensorWidget)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_17)));//"images/传感器视图-日.png"
//    this->setPalette(p);

    changeDNMode();

//    ui->leeast_gps1->setFont(FONT_11);
//    ui->lenorth_gps1->setFont(FONT_11);
//    ui->leeast_gps2->setFont(FONT_11);
//    ui->lenorth_gps2->setFont(FONT_11);
//    ui->ledirection_wind->setFont(FONT_11);
//    ui->lespeed_wind->setFont(FONT_11);
//    ui->lepitch_vrs->setFont(FONT_11);
//    ui->leroll_vrs->setFont(FONT_11);
//    ui->leheading_gyro->setFont(FONT_11);

    this->setGeometry(viewRect.x(),  viewRect.y() + 20, viewRect.width()-2,viewRect.height());
}

void SensorWidget::Refresh_changless_words()
{

    ui->label_1->setFont(FONT_15);
    ui->label_2->setFont(FONT_15);

    ui->label_1->setText(sensor_dianluojing);
    ui->label_2->setText(sensor_fengsufengxiangyi);

 //   painter.setFont(FONT_3);
    ui->label_shouxiang->setFont(FONT_2);

    ui->label_fengsu->setFont(FONT_2);
    ui->label_fengxiang->setFont(FONT_2);

    ui->label_jiuxu->setFont(FONT_2);
    ui->label_qiyong->setFont(FONT_2);


    ui->label_shouxiang->setText(str_shouxiang); 
    ui->label_fengsu->setText(str_fengsu);
    ui->label_fengxiang->setText(str_fengxiang);
    ui->label_jiuxu->setText(str_jiuxu);
    ui->label_qiyong->setText(str_qiyong);


    ui->label_shouxiang_dw->setFont(FONT_1);
    ui->label_fengsu_dw->setFont(FONT_1);
    ui->label_fengxiang_dw->setFont(FONT_1);


 //   painter.setFont(FONT_1);
    ui->label_shouxiang_dw->setText(danwei_du);
    ui->label_fengsu_dw->setText(danwei_mimiao);
    ui->label_fengxiang_dw->setText(danwei_du);    
    ui->label_jiuxu->setText(str_jiuxu);
    ui->label_qiyong->setText(str_qiyong);
}

/*刷新数据*/
void SensorWidget::refreshData()
{

    QPalette pe;
    //就绪

    //电罗经

    ui->leready_gyro->setAutoFillBackground(true);
    ui->leenable_gyro->setAutoFillBackground(true);

    if(State_Gyro == 0)
    {
         pe.setColor(QPalette::Base,COLOR_20);
    }
    else
    {
         pe.setColor(QPalette::Base,COLOR_18);
    }
    ui->leready_gyro->setPalette(pe);

    if(Enable_gyro_on)
    {
         pe.setColor(QPalette::Base,COLOR_20);
    }
    else
    {
         pe.setColor(QPalette::Base,COLOR_18);
    }
   ui->leenable_gyro->setPalette(pe);

   ui->leheading_gyro->setText(QString::number(mes_heading,'f',1));

    //风速风向仪

    ui->leready_wind->setAutoFillBackground(true);
    ui->leenable_wind->setAutoFillBackground(true);

    if(State_Wind == 0)
    {
        pe.setColor(QPalette::Base,COLOR_20);
    }
    else
    {
        pe.setColor(QPalette::Base,COLOR_18);
    }
    ui->leready_wind->setPalette(pe);

    if(Enable_wind_on)
    {
        pe.setColor(QPalette::Base,COLOR_20);
    }
    else
    {
        pe.setColor(QPalette::Base,COLOR_18);
    }
    ui->leenable_wind->setPalette(pe);

    ui->lespeed_wind->setText(QString::number(mes_windspd,'f',1));
    ui->ledirection_wind->setText(QString::number(mes_winddir,'f',1));
}

//白天、夜晚模式切换
void SensorWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_17)));//"images/传感器视图-日.png"
        this->setPalette(p);
        p.setColor(QPalette::WindowText,COLOR_15);
        ui->label_1->setPalette(p);
        ui->label_2->setPalette(p);
        ui->label_fengsu->setPalette(p);
        ui->label_fengsu->setPalette(p);
        ui->label_fengsu_dw->setPalette(p);
        ui->label_fengxiang->setPalette(p);
        ui->label_fengxiang_dw->setPalette(p);
        ui->label_jiuxu->setPalette(p);
        ui->label_qiyong->setPalette(p);
        ui->label_shouxiang->setPalette(p);
        ui->label_shouxiang_dw->setPalette(p);


        p.setColor(QPalette::Text,COLOR_15);
        ui->ledirection_wind->setPalette(p);        
        ui->leenable_gyro->setPalette(p);        
        ui->leenable_wind->setPalette(p);
        ui->leheading_gyro->setPalette(p);       
        ui->leready_gyro->setPalette(p);        
        ui->lespeed_wind->setPalette(p);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_17)));//"images/传感器视图-夜.png"
        this->setPalette(p);
        p.setColor(QPalette::WindowText,COLOR_23);
        ui->label_1->setPalette(p);
        ui->label_2->setPalette(p);
        ui->label_fengsu->setPalette(p);
        ui->label_fengsu->setPalette(p);
        ui->label_fengsu_dw->setPalette(p);
        ui->label_fengxiang->setPalette(p);
        ui->label_fengxiang_dw->setPalette(p);
        ui->label_jiuxu->setPalette(p);
        ui->label_qiyong->setPalette(p);
        ui->label_shouxiang->setPalette(p);
        ui->label_shouxiang_dw->setPalette(p);
        p.setColor(QPalette::Text,COLOR_23);
        ui->ledirection_wind->setPalette(p);
        ui->leenable_gyro->setPalette(p);
        ui->leenable_wind->setPalette(p);
        ui->leheading_gyro->setPalette(p);
        ui->leready_gyro->setPalette(p);

        ui->leready_wind->setPalette(p);
        ui->lespeed_wind->setPalette(p);
    }

}

SensorWidget::~SensorWidget()
{
    delete ui;
}
