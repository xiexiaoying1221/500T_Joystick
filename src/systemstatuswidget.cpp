/*
    系统状态
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "systemstatuswidget.h"
#include "ui_systemstatuswidget.h"

SystemStatusWidget::SystemStatusWidget(QWidget *parent,QRect rect) :
    QWidget(parent),
    ui(new Ui::SystemStatusWidget)
{
    ui->setupUi(this);


    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_19)));//"images/systemstatus.png"

//    ui->label_1->setStyleSheet("color: rgb(65, 65, 65);");
//    ui->label_2->setStyleSheet("color: rgb(65, 65, 65);");
//    ui->label_3->setStyleSheet("color: rgb(65, 65, 65);");
//    ui->label_4->setStyleSheet("color: rgb(65, 65, 65);");
//    ui->label_5->setStyleSheet("color: rgb(65, 65, 65);");
//    ui->label_6->setStyleSheet("color: rgb(65, 65, 65);");
//    ui->label_7->setStyleSheet("color: rgb(65, 65, 65);");


//    this->setPalette(p);
    changeDNMode();

    this->setGeometry(rect.x(),  rect.y(), rect.width(),rect.height());
}


//白天、夜晚模式切换
void SystemStatusWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
  //      p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/系统状态视图-日.png")));
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_19)));//"images/systemstatus.png"
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_5->setStyleSheet(StyleSheet_DayColor);
        ui->label_6->setStyleSheet(StyleSheet_DayColor);
        ui->label_7->setStyleSheet(StyleSheet_DayColor);
        ui->label_10->setStyleSheet(StyleSheet_DayColor);
        ui->label_11->setStyleSheet(StyleSheet_DayColor);
        ui->label_12->setStyleSheet(StyleSheet_DayColor);
        ui->label_13->setStyleSheet(StyleSheet_DayColor);
        ui->label_14->setStyleSheet(StyleSheet_DayColor);
        ui->label_15->setStyleSheet(StyleSheet_DayColor);


    }
    else
    {
//        p.setBrush(QPalette::Window,QBrush(QPixmap("images/系统状态视图-夜.png")));
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_19)));//"images/systemstatus.png"
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_5->setStyleSheet(StyleSheet_NgtColor);
        ui->label_6->setStyleSheet(StyleSheet_NgtColor);
        ui->label_7->setStyleSheet(StyleSheet_NgtColor);
        ui->label_10->setStyleSheet(StyleSheet_NgtColor);
        ui->label_11->setStyleSheet(StyleSheet_NgtColor);
        ui->label_12->setStyleSheet(StyleSheet_NgtColor);
        ui->label_13->setStyleSheet(StyleSheet_NgtColor);
        ui->label_14->setStyleSheet(StyleSheet_NgtColor);
        ui->label_15->setStyleSheet(StyleSheet_NgtColor);

    }
    this->setPalette(p);
}

void SystemStatusWidget::refreshData()
{

    //prop1
    if(Ready_prop1)
    {
        ui->lblprop1->setVisible(false);
    }
    else
    {
        ui->lblprop1->setVisible(true);
    }

    //prop2
    if(Ready_prop2)
    {
        ui->lblprop2->setVisible(false);
    }
    else
    {
        ui->lblprop2->setVisible(true);
    }

    //prop3
    if(Ready_prop3)
    {
        ui->lblprop3->setVisible(false);
    }
    else
    {
        ui->lblprop3->setVisible(true);
    }

    //rudder1
    if(Ready_rudder1)
    {
        ui->lblleftrudder->setVisible(false);
    }
    else
    {
        ui->lblleftrudder->setVisible(true);
    }

    //rudder2
    if(Ready_rudder2)
    {
        ui->lblrightrudder->setVisible(false);
    }
    else
    {
        ui->lblrightrudder->setVisible(true);
    }

    //net1
    if(State_cc_net1==0 || State_ot_net1 ==0 )
    {
        ui->lblnet1->setVisible(false);
    }
    else
    {
        ui->lblnet1->setVisible(true);
    }

    //gyro
    if(State_cc_com1 ==0 )
    {
        ui->lblrs422_gyro->setVisible(false);
    }
    else
    {
        ui->lblrs422_gyro->setVisible(true);
    }

    //wind
    if(State_cc_com4 ==0 )
    {
        ui->lblrs422_wind->setVisible(false);
    }
    else
    {
        ui->lblrs422_wind->setVisible(true);
    }
}


void SystemStatusWidget::Refresh_changless_words()
{


    ui->label_1->setFont(FONT_2);
    ui->label_1->setText(str_zuoduo);

    ui->label_2->setFont(FONT_2);
    ui->label_2->setText(str_youduo);

    ui->label_3->setFont(FONT_2);
    ui->label_3->setText(str_weizuozhutui);

    ui->label_4->setFont(FONT_2);
    ui->label_4->setText(str_weiyouzhutui);

    ui->label_5->setFont(FONT_2);
    ui->label_5->setText(str_shoucetui);

    ui->label_6->setFont(FONT_2);
    ui->label_6->setText(str_kongzhigui);

    ui->label_7->setFont(FONT_2);
    ui->label_7->setText(str_caozuoduan);

    ui->label_10->setFont(FONT_2);
    ui->label_10->setText(str_fengsu_ZTST);//风速

    ui->label_11->setFont(FONT_2);
    ui->label_11->setText(str_dianluojing_ZTST);//电罗经

    ui->label_12->setFont(FONT_2);
    ui->label_12->setText(str_chuankou_ZTST);//串口

    ui->label_13->setFont(FONT_2);
    ui->label_13->setText(str_IO_ZTST);//IO

    ui->label_14->setFont(FONT_2);
    ui->label_14->setText(str_yitaiwang_ZTST);//以太网

    ui->label_15->setFont(FONT_2);
    ui->label_15->setText(str_duanlu_ZTST);//断路
}

SystemStatusWidget::~SystemStatusWidget()
{
    delete ui;
}
