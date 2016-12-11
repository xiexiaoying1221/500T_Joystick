/*
    推进器启用
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "propellerenablewidget.h"
#include "ui_propellerenablewidget.h"

PropellerEnableWidget::PropellerEnableWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::PropellerEnableWidget)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_14)));//"images/推进器启用设置-日.png"
//    this->setPalette(p);


    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());


    ui->pbEnableProp1->setFont(FONT_3);
    ui->pbEnableProp2->setFont(FONT_3);
    ui->pbEnableProp3->setFont(FONT_3);
    ui->pbEnableRudder1->setFont(FONT_3);
    ui->pbEnableRudder2->setFont(FONT_3);
    ui->label_1->setFont(FONT_3);
    ui->label_2->setFont(FONT_3);
    ui->label_3->setFont(FONT_3);
    ui->label_4->setFont(FONT_3);
    ui->label_5->setFont(FONT_3);
    ui->label_6->setFont(FONT_2);
    ui->label_7->setFont(FONT_2);
    ui->label_8->setFont(FONT_2);
    ui->pbOK->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);


    connect(ui->pbOK,SIGNAL(clicked()),this,SLOT(pbOK_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));

    refreshData();
    changeDNMode();
    Refresh_changless_words();
}

//白天、夜晚模式切换
void PropellerEnableWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_14)));//"images/推进器启用设置-日.png"
        this->setPalette(p);
        p.setColor(QPalette::WindowText,COLOR_15);
        ui->label_1->setPalette(p);
        ui->label_2->setPalette(p);
        ui->label_3->setPalette(p);
        ui->label_4->setPalette(p);
        ui->label_5->setPalette(p);
        ui->label_6->setPalette(p);
        ui->label_7->setPalette(p);
        ui->label_8->setPalette(p);
        p.setColor(QPalette::Text,COLOR_15);
        ui->pbEnableProp1->setPalette(p);
        ui->pbEnableProp2->setPalette(p);
        ui->pbEnableProp3->setPalette(p);
        ui->pbEnableRudder1->setPalette(p);
        ui->pbEnableRudder2->setPalette(p);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_14)));//"images/推进器启用设置-夜.png"
        this->setPalette(p);
        p.setColor(QPalette::WindowText,COLOR_23);
        ui->label_1->setPalette(p);
        ui->label_2->setPalette(p);
        ui->label_3->setPalette(p);
        ui->label_4->setPalette(p);
        ui->label_5->setPalette(p);
        ui->label_6->setPalette(p);
        ui->label_7->setPalette(p);
        ui->label_8->setPalette(p);
        p.setColor(QPalette::Text,COLOR_23);
        ui->pbEnableProp1->setPalette(p);
        ui->pbEnableProp2->setPalette(p);
        ui->pbEnableProp3->setPalette(p);
        ui->pbEnableRudder1->setPalette(p);
        ui->pbEnableRudder2->setPalette(p);
    }
}


void PropellerEnableWidget::refreshData()
{
 //prop1
    if(Ready_prop1)
    {
        ui->wReadyProp1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wReadyProp1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop1_on = false;
    }
    if(Run_prop1)
    {
        ui->wRunProp1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wRunProp1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //prop2
    if(Ready_prop2)
    {
        ui->wReadyProp2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wReadyProp2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop2_on = false;
    }
    if(Run_prop2)
    {
        ui->wRunProp2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wRunProp2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //prop3
    if(Ready_prop3)
    {
        ui->wReadyProp3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wReadyProp3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop3_on =false;
    }
    if(Run_prop3)
    {
        ui->wRunProp3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wRunProp3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //rudder1
    //qDebug()<<"rudder1"<<Ready_rudder1<<Enable_rudder1_on;
    if(Ready_rudder1)
    {
        ui->wReadyRudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wReadyRudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_rudder1_on =false;
    }
    if(Run_rudder1)
    {
        ui->wRunRudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wRunRudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //rudder2
    if(Ready_rudder2)
    {
        ui->wReadyRudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wReadyRudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_rudder2_on = false;
    }
    if(Run_rudder2)
    {
        ui->wRunRudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->wRunRudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }
}

void PropellerEnableWidget::on_pbEnableProp1_clicked()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Prop1_click()"<<Ready_prop1;
    if(ui->pbEnableProp1->text() == "是" || ui->pbEnableProp1->text()=="Yes" || Ready_prop1 == false ){
        ui->pbEnableProp1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        ui->pbEnableProp1->setText(str_no);//"否"
        return;
    }
    if(Ready_prop1 == false) return;
    ui->pbEnableProp1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
    ui->pbEnableProp1->setText(str_yes);//"是"
}

void PropellerEnableWidget::on_pbEnableProp2_clicked()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Prop2_click()"<<Ready_prop2;
    if(ui->pbEnableProp2->text() == "是" || ui->pbEnableProp2->text()=="Yes" || Ready_prop2 == false){
        ui->pbEnableProp2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        ui->pbEnableProp2->setText(str_no);//"否"
        return;
    }
    ui->pbEnableProp2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
    ui->pbEnableProp2->setText(str_yes);//"是"
}

void PropellerEnableWidget::on_pbEnableProp3_clicked()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Prop3_click()"<<Ready_prop3;
    if(ui->pbEnableProp3->text() == "是" || ui->pbEnableProp3->text()=="Yes" || Ready_prop3 == false ){
        ui->pbEnableProp3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        ui->pbEnableProp3->setText(str_no);//"否"
        return;
    }
    ui->pbEnableProp3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
    ui->pbEnableProp3->setText(str_yes);//"是"
}


void PropellerEnableWidget::on_pbEnableRudder1_clicked()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Rudder1_click()"<<Ready_rudder1;
    if(ui->pbEnableRudder1->text() == "是" || ui->pbEnableRudder1->text()=="Yes" || Ready_rudder1 == false ){
        ui->pbEnableRudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        ui->pbEnableRudder1->setText(str_no);//"否"
        return;
    }
    ui->pbEnableRudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
    ui->pbEnableRudder1->setText(str_yes);//"是"
}

void PropellerEnableWidget::on_pbEnableRudder2_clicked()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Rudder2_click()"<<Ready_rudder2;
    if(ui->pbEnableRudder2->text() == "是" || ui->pbEnableRudder2->text() == "Yes" || Ready_rudder2 == false ){
        ui->pbEnableRudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        ui->pbEnableRudder2->setText(str_no);//"否"
        return;
    }
    ui->pbEnableRudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
    ui->pbEnableRudder2->setText(str_yes);//"是"
}

void PropellerEnableWidget::pbOK_clicked()
{
    Enable_prop1_on = ui->pbEnableProp1->text() == str_yes? true : false;//"是"
    Enable_prop2_on = ui->pbEnableProp2->text() == str_yes ? true : false;//"是"
    Enable_prop3_on = ui->pbEnableProp3->text() == str_yes ? true : false;//"是"
    Enable_rudder1_on = ui->pbEnableRudder1->text() == str_yes ? true : false;//"是"
    Enable_rudder2_on = ui->pbEnableRudder2->text() == str_yes ? true : false;//"是"
    emit ok_signal(this->objectName());
}

void PropellerEnableWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

void PropellerEnableWidget::Refresh_changless_words()
{
    ui->label_1->setText(str_shoucetui);
    ui->label_2->setText(str_weizuozhutui);
    ui->label_3->setText(str_weiyouzhutui);
    ui->label_4->setText(str_zuoduoji);
    ui->label_5->setText(str_youduoji);
    ui->label_6->setText(str_jiuxu);
    ui->label_7->setText(str_yunxing);
    ui->label_8->setText(str_qiyong);
    ui->pbOK->setText(str_queding);
    ui->pbCancel->setText(str_quxiao);

    if(ui->pbEnableProp1->text() == "是" || ui->pbEnableProp1->text() == "Yes")
        ui->pbEnableProp1->setText(str_yes);
    else
        ui->pbEnableProp1->setText(str_no);

    if(ui->pbEnableProp2->text() == "是" || ui->pbEnableProp2->text() == "Yes")
        ui->pbEnableProp2->setText(str_yes);
    else
        ui->pbEnableProp2->setText(str_no);

    if(ui->pbEnableProp3->text() == "是" || ui->pbEnableProp3->text() == "Yes")
        ui->pbEnableProp3->setText(str_yes);
    else
        ui->pbEnableProp3->setText(str_no);

    if(ui->pbEnableRudder1->text() == "是" || ui->pbEnableRudder1->text() == "Yes")
        ui->pbEnableRudder1->setText(str_yes);
    else
        ui->pbEnableRudder1->setText(str_no);

    if(ui->pbEnableRudder2->text() == "是" || ui->pbEnableRudder2->text() == "Yes")
        ui->pbEnableRudder2->setText(str_yes);
    else
        ui->pbEnableRudder2->setText(str_no);


}

PropellerEnableWidget::~PropellerEnableWidget()
{
    delete ui;
}
