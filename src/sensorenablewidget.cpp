/*
    传感器启用
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

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

    ui->wReadyGypo->setFont(FONT_3);
    ui->pbEnableGyro->setFont(FONT_3);

    ui->wReadyWind->setFont(FONT_3);
    ui->pbEnableWind->setFont(FONT_3);

    ui->label_1->setFont(FONT_3);
    ui->label_2->setFont(FONT_3);
    ui->label_6->setFont(FONT_2);
    ui->label_7->setFont(FONT_2);
    ui->pbOk->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);

    changeDNMode();
    refreshData();
    Refresh_changless_words();

    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOK_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));
}

SensorEnableWidget::~SensorEnableWidget()
{
    delete ui;
}

void SensorEnableWidget::Refresh_changless_words()
{
    ui->label_1->setText(str_dianluojing_CQSZ);
    ui->label_2->setText(str_fengsufengxiangyi_CQSZ);
    ui->label_6->setText(str_jiuxu);
    ui->label_7->setText(str_qiyong);
    ui->pbOk->setText(str_queding);
    ui->pbCancel->setText(str_quxiao);

    if(ui->pbEnableGyro->text() == "是" || ui->pbEnableGyro->text() == "Yes")
        ui->pbEnableGyro->setText(str_yes);
    else
        ui->pbEnableGyro->setText(str_no);

    if(ui->pbEnableWind->text() == "是" || ui->pbEnableWind->text() == "Yes")
        ui->pbEnableWind->setText(str_yes);
    else
        ui->pbEnableWind->setText(str_no);
}


void SensorEnableWidget::refreshData()
{

    if(State_Gyro == 0)
    {
        ui->wReadyGypo->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        ui->wReadyGypo->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
        Enable_gyro_on = false;
    }


    if(State_Wind == 0)
    {
        ui->wReadyWind->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        ui->wReadyWind->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
        Enable_wind_on =false;
    }
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
        ui->wReadyGypo->setPalette(p);
        ui->pbEnableGyro->setPalette(p);

        ui->wReadyWind->setPalette(p);
        ui->pbEnableWind->setPalette(p);


    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_16)));//"images/传感器启用设置-夜.png"
        this->setPalette(p);
        p.setColor(QPalette::WindowText,COLOR_23);
        ui->label_1->setPalette(p);
        ui->label_2->setPalette(p);

        p.setColor(QPalette::Text,COLOR_23);
        ui->wReadyGypo->setPalette(p);
        ui->pbEnableGyro->setPalette(p);

        ui->wReadyWind->setPalette(p);
        ui->pbEnableWind->setPalette(p);

    }
}


void SensorEnableWidget::on_pbEnableGyro_clicked()
{
    if(ui->pbEnableGyro->text() == "否" || ui->pbEnableGyro->text() == "No")
    {
        if( State_Gyro ==0 ){
            ui->pbEnableGyro->setText(str_yes);//"是"
            ui->pbEnableGyro->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
            return;
        }
    }
    ui->pbEnableGyro->setText(str_no);//"否"
    ui->pbEnableGyro->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
}

void SensorEnableWidget::on_pbEnableWind_clicked()
{
    if(ui->pbEnableWind->text() == "否" || ui->pbEnableWind->text() == "No")
    {
        if( State_Wind ==0 ){
            ui->pbEnableWind->setText(str_yes);//"是"
            ui->pbEnableWind->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
            return;
        }
    }
    ui->pbEnableWind->setText(str_no);//"否"
    ui->pbEnableWind->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
}


//void SensorEnableWidget::leGps1Enable_click()
//{
//    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
//    if(State_GPS1 != 0) return;

//    if(le->text() == "否" || le->text() == "No")
//    {
//        le->setText(str_yes);//"是"
//        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
//    }
//    else
//    {
//        le->setText(str_no);//"否"
//        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
//    }
//}

//void SensorEnableWidget::leGps2Enable_click()
//{
//    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
//    if(State_GPS2 != 0) return;

//    if(le->text() == "否" || le->text() == "No")
//    {
//        le->setText(str_yes);//"是"
//        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
//    }
//    else
//    {
//        le->setText(str_no);//"否"
//        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
//    }
//}


//void SensorEnableWidget::leVrsEnable_click()
//{
//    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
//    if(State_VRS !=0 ) return;
//    if(le->text() == "否" || le->text() == "No")
//    {
//        le->setText(str_yes);//"是"
//        le->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
//    }
//    else
//    {
//        le->setText(str_no);//"否"
//        le->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
//    }
//}


void SensorEnableWidget::pbOK_clicked()
{
    //leGryoEnable
    Enable_gyro_on = ui->pbEnableGyro->text() == str_yes ? 1 : 0;//"是"
    Enable_wind_on = ui->pbEnableWind->text() == str_yes ? 1 : 0;//"是"
    emit ok_signal(this->objectName());
}

void SensorEnableWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}
