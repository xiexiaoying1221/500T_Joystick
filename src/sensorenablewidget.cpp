/*
    传感器启用
*/
#include "sensorenablewidget.h"
#include "ui_sensorenablewidget.h"

SensorEnableWidget::SensorEnableWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::SensorEnableWidget)
{

    ui->setupUi(this);

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_16)));//"images/传感器启用设置-日.png"
//    this->setPalette(p);

    //changeDNMode();

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());

    leGyroReady = new LineEdit(this);
    leGyroEnable = new LineEdit(this);
    leWindReady = new LineEdit(this);
    leWindEnable = new LineEdit(this);


    changeDNMode();

    leGyroReady->setGeometry(ui->leready_gypo ->geometry());
    leGyroReady->setReadOnly(true);
    leGyroReady->setFont(ui->leready_gypo->font());

    leGyroEnable->setGeometry(ui->leenable_gyro->geometry());
    leGyroEnable->setReadOnly(true);
    leGyroEnable->setFont(FONT_3);

    leWindReady->setGeometry(ui->leready_wind->geometry());
    leWindReady->setReadOnly(true);
    leWindReady->setFont(ui->leready_wind->font());


    leWindEnable->setGeometry(ui->leenable_wind->geometry());
    leWindEnable->setReadOnly(true);
    leWindEnable->setFont(FONT_3);




    if(State_Gyro == 0)
    {
        leGyroReady->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        leGyroReady->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
        Enable_gyro_on = false;
    }

    if(Enable_gyro_on)
    {
        leGyroEnable->setText(str_yes);//"是"
        leGyroEnable->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        leGyroEnable->setText(str_no);//"否"
        leGyroEnable->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }


    if(State_Wind == 0)
    {
        leWindReady->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        leWindReady->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
        Enable_wind_on =false;
    }

    if(Enable_wind_on)
    {
        leWindEnable->setText(str_yes);//"是"
        leWindEnable->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        leWindEnable->setText(str_no);//"否"
        leWindEnable->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }

    connect(leGyroEnable,SIGNAL(clicked()),this,SLOT(leGyroEnable_click()));
    connect(leWindEnable,SIGNAL(clicked()),this,SLOT(leWindEnable_click()));

    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOK_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));
}

//白天、夜晚模式切换
void SensorEnableWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_16)));//"images/传感器启用设置-日.png"
        this->setPalette(p);
        p.setColor(QPalette::WindowText,COLOR_15);
        ui->label_1->setPalette(p);
        ui->label_2->setPalette(p);

        p.setColor(QPalette::Text,COLOR_15);
        leGyroReady->setPalette(p);
        leGyroEnable->setPalette(p);

        leWindReady->setPalette(p);
        leWindEnable->setPalette(p);


    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_16)));//"images/传感器启用设置-夜.png"
        this->setPalette(p);
        p.setColor(QPalette::WindowText,COLOR_23);
        ui->label_1->setPalette(p);
        ui->label_2->setPalette(p);

        p.setColor(QPalette::Text,COLOR_23);
        leGyroReady->setPalette(p);
        leGyroEnable->setPalette(p);
        leWindReady->setPalette(p);
        leWindEnable->setPalette(p);

    }
}

void SensorEnableWidget::refreshData()
{

    if(State_Gyro == 0)
    {
        leGyroReady->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        leGyroReady->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
        Enable_gyro_on = false;
    }


    if(State_Wind == 0)
    {
        leWindReady->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        leWindReady->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
        Enable_wind_on =false;
    }
}

void SensorEnableWidget::leGyroEnable_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(State_Gyro != 0) return;

    if(le->text() == "否" || le->text() == "No")
    {
        le->setText(str_yes);//"是"
        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        le->setText(str_no);//"否"
        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }
}

void SensorEnableWidget::leGps1Enable_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(State_GPS1 != 0) return;

    if(le->text() == "否" || le->text() == "No")
    {
        le->setText(str_yes);//"是"
        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        le->setText(str_no);//"否"
        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }
}

void SensorEnableWidget::leGps2Enable_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(State_GPS2 != 0) return;

    if(le->text() == "否" || le->text() == "No")
    {
        le->setText(str_yes);//"是"
        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        le->setText(str_no);//"否"
        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }
}

void SensorEnableWidget::leWindEnable_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(State_Wind !=0 ) return;
    if(le->text() == "否" || le->text() == "No")
    {
        le->setText(str_yes);//"是"
        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        le->setText(str_no);//"否"
        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }
}

void SensorEnableWidget::leVrsEnable_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(State_VRS !=0 ) return;
    if(le->text() == "否" || le->text() == "No")
    {
        le->setText(str_yes);//"是"
        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        le->setText(str_no);//"否"
        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }
}


void SensorEnableWidget::pbOK_clicked()
{
    //leGryoEnable
    Enable_gyro_on = leGyroEnable->text() == str_yes ? 1 : 0;//"是"
    Enable_wind_on = leWindEnable->text() == str_yes ? 1 : 0;//"是"
    emit ok_signal(this->objectName());
}

void SensorEnableWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

void SensorEnableWidget::Refresh_changless_words()
{
    ui->label_1->setFont(FONT_3);
    ui->label_1->setText(str_dianluojing_CQSZ);

    ui->label_2->setFont(FONT_3);
    ui->label_2->setText(str_fengsufengxiangyi_CQSZ);

    ui->label_6->setFont(FONT_2);
    ui->label_6->setText(str_jiuxu);

    ui->label_7->setFont(FONT_2);
    ui->label_7->setText(str_qiyong);

    ui->pbOk->setFont(FONT_3);
    ui->pbOk->setText(str_queding);

    ui->pbCancel->setFont(FONT_3);
    ui->pbCancel->setText(str_quxiao);




    if(leGyroEnable->text() == "是" || leGyroEnable->text() == "Yes")
        leGyroEnable->setText(str_yes);
    else
        leGyroEnable->setText(str_no);

    if(leWindEnable->text() == "是" || leWindEnable->text() == "Yes")
        leWindEnable->setText(str_yes);
    else
        leWindEnable->setText(str_no);
}


SensorEnableWidget::~SensorEnableWidget()
{
    delete ui;
}

