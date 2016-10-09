/*
    推进器启用
*/

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


    leEnable_Prop1 = new LineEdit(this);
    leEnable_Prop2 = new LineEdit(this);
    leEnable_Prop3 = new LineEdit(this);
    leEnable_Rudder1 = new LineEdit(this);
    leEnable_Rudder2 = new LineEdit(this);

    changeDNMode();

    leEnable_Prop1->setGeometry(ui->leenable_prop1->geometry());
    leEnable_Prop1->setReadOnly(true);
    leEnable_Prop1->setStyleSheet(ui->leenable_prop1->styleSheet());
    leEnable_Prop1->setFont(FONT_3);


    leEnable_Prop2->setGeometry(ui->leenable_prop2->geometry());
    leEnable_Prop2->setReadOnly(true);
    leEnable_Prop2->setStyleSheet(ui->leenable_prop2->styleSheet());
    leEnable_Prop2->setFont(FONT_3);


    leEnable_Prop3->setGeometry(ui->leenable_prop3->geometry());
    leEnable_Prop3->setReadOnly(true);
    leEnable_Prop3->setStyleSheet(ui->leenable_prop3->styleSheet());
    leEnable_Prop3->setFont(FONT_3);


    leEnable_Rudder1->setGeometry(ui->leenable_rudder1->geometry());
    leEnable_Rudder1->setReadOnly(true);
    leEnable_Rudder1->setStyleSheet(ui->leenable_rudder1->styleSheet());
    leEnable_Rudder1->setFont(FONT_3);

    leEnable_Rudder2->setGeometry(ui->leenable_rudder2->geometry());
    leEnable_Rudder2->setReadOnly(true);
    leEnable_Rudder2->setStyleSheet(ui->leenable_rudder2->styleSheet());
    leEnable_Rudder2->setFont(FONT_3);



    //prop1
    if(Ready_prop1)
    {
        ui->leready_prop1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_prop1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop1_on = false;
    }
    if(Run_prop1)
    {
        ui->lerun_prop1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_prop1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    if(Enable_prop1_on)
    {
        leEnable_Prop1->setText(str_yes);//"是"
        leEnable_Prop1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        leEnable_Prop1->setText(str_no);//"否"
        leEnable_Prop1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //prop2
    if(Ready_prop2)
    {
        ui->leready_prop2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_prop2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop2_on = false;
    }
    if(Run_prop2)
    {
        ui->lerun_prop2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_prop2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    if(Enable_prop2_on)
    {
        leEnable_Prop2->setText(str_yes);//"是"
        leEnable_Prop2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        leEnable_Prop2->setText(str_no);//"否"
        leEnable_Prop2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //prop3
    if(Ready_prop3)
    {
        ui->leready_prop3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_prop3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop3_on =false;
    }
    if(Run_prop3)
    {
        ui->lerun_prop3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_prop3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    if(Enable_prop3_on)
    {
        leEnable_Prop3->setText(str_yes);//"是"
        leEnable_Prop3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        leEnable_Prop3->setText(str_no);//"否"
        leEnable_Prop3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //rudder1
    //qDebug()<<"rudder1"<<Ready_rudder1<<Enable_rudder1_on;
    if(Ready_rudder1)
    {
        ui->leready_rudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_rudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_rudder1_on =false;
    }
    if(Run_rudder1)
    {
        ui->lerun_rudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_rudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    if(Enable_rudder1_on)
    {
        leEnable_Rudder1->setText(str_yes);//"是"
        leEnable_Rudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        leEnable_Rudder1->setText(str_no);//"否"
        leEnable_Rudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //rudder2
    if(Ready_rudder2)
    {
        ui->leready_rudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_rudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_rudder2_on = false;
    }
    if(Run_rudder2)
    {
        ui->lerun_rudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_rudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    if(Enable_rudder2_on)
    {
        leEnable_Rudder2->setText(str_yes);//"是"
        leEnable_Rudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        leEnable_Rudder2->setText(str_no);//"否"
        leEnable_Rudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }



    connect(leEnable_Prop1,SIGNAL(clicked()),this,SLOT(leEnable_Prop1_click()));
    connect(leEnable_Prop2,SIGNAL(clicked()),this,SLOT(leEnable_Prop2_click()));
    connect(leEnable_Prop3,SIGNAL(clicked()),this,SLOT(leEnable_Prop3_click()));
    connect(leEnable_Rudder1,SIGNAL(clicked()),this,SLOT(leEnable_Rudder1_click()));
    connect(leEnable_Rudder2,SIGNAL(clicked()),this,SLOT(leEnable_Rudder2_click()));

    connect(ui->pbOK,SIGNAL(clicked()),this,SLOT(pbOK_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));
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
        leEnable_Prop1->setPalette(p);
        leEnable_Prop2->setPalette(p);
        leEnable_Prop3->setPalette(p);
        leEnable_Rudder1->setPalette(p);
        leEnable_Rudder2->setPalette(p);
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
        leEnable_Prop1->setPalette(p);
        leEnable_Prop2->setPalette(p);
        leEnable_Prop3->setPalette(p);
        leEnable_Rudder1->setPalette(p);
        leEnable_Rudder2->setPalette(p);
    }
}


void PropellerEnableWidget::refreshData()
{
 //prop1
    if(Ready_prop1)
    {
        ui->leready_prop1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_prop1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop1_on = false;
    }
    if(Run_prop1)
    {
        ui->lerun_prop1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_prop1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //prop2
    if(Ready_prop2)
    {
        ui->leready_prop2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_prop2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop2_on = false;
    }
    if(Run_prop2)
    {
        ui->lerun_prop2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_prop2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //prop3
    if(Ready_prop3)
    {
        ui->leready_prop3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_prop3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_prop3_on =false;
    }
    if(Run_prop3)
    {
        ui->lerun_prop3->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_prop3->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //rudder1
    //qDebug()<<"rudder1"<<Ready_rudder1<<Enable_rudder1_on;
    if(Ready_rudder1)
    {
        ui->leready_rudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_rudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_rudder1_on =false;
    }
    if(Run_rudder1)
    {
        ui->lerun_rudder1->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_rudder1->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    //rudder2
    if(Ready_rudder2)
    {
        ui->leready_rudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->leready_rudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        Enable_rudder2_on = false;
    }
    if(Run_rudder2)
    {
        ui->lerun_rudder2->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->lerun_rudder2->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }
}

void PropellerEnableWidget::leEnable_Prop1_click()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Prop1_click()"<<Ready_prop1;
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(sender());
    if(Ready_prop1 == false) return;
    if(lineEdit->text() == "是" || lineEdit->text()=="Yes"){
        lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        lineEdit->setText(str_no);//"否"

    }else{
        lineEdit->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
        lineEdit->setText(str_yes);//"是"
    }
}

void PropellerEnableWidget::leEnable_Prop2_click()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Prop2_click()"<<Ready_prop2;
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(sender());
    if(Ready_prop2 == false) return;
    if(lineEdit->text() == "是" || lineEdit->text()=="Yes"){
        lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        lineEdit->setText(str_no);//"否"

    }else{
        lineEdit->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
        lineEdit->setText(str_yes);//"是"
    }
}

void PropellerEnableWidget::leEnable_Prop3_click()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Prop3_click()"<<Ready_prop3;
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(sender());
    if(Ready_prop3 == false) return;
    if(lineEdit->text() == "是" || lineEdit->text()=="Yes"){
        lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        lineEdit->setText(str_no);//"否"

    }else{
        lineEdit->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
        lineEdit->setText(str_yes);//"是"
    }
}


void PropellerEnableWidget::leEnable_Rudder1_click()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Rudder1_click()"<<Ready_rudder1;
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(sender());
    if(Ready_rudder1 == false) return;
    if(lineEdit->text() == "是" || lineEdit->text()=="Yes"){
        lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        lineEdit->setText(str_no);//"否"

    }else{
        lineEdit->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
        lineEdit->setText(str_yes);//"是"
    }
}

void PropellerEnableWidget::leEnable_Rudder2_click()
{
    //qDebug()<<"PropellerEnableWidget::leEnable_Rudder2_click()"<<Ready_rudder2;
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(sender());
    if(Ready_rudder2 == false) return;
    if(lineEdit->text() == "是" || lineEdit->text() == "Yes"){
        lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        lineEdit->setText(str_no);//"否"

    }else{
        lineEdit->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0;border-style:outset;");
        lineEdit->setText(str_yes);//"是"
    }
}

void PropellerEnableWidget::pbOK_clicked()
{
    Enable_prop1_on = leEnable_Prop1->text() == str_yes? true : false;//"是"
    Enable_prop2_on = leEnable_Prop2->text() == str_yes ? true : false;//"是"
    Enable_prop3_on = leEnable_Prop3->text() == str_yes ? true : false;//"是"
    Enable_rudder1_on = leEnable_Rudder1->text() == str_yes ? true : false;//"是"
    Enable_rudder2_on = leEnable_Rudder2->text() == str_yes ? true : false;//"是"
    emit ok_signal(this->objectName());
}

void PropellerEnableWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

void PropellerEnableWidget::Refresh_changless_words()
{

    ui->label_1->setFont(FONT_3);
    ui->label_2->setFont(FONT_3);
    ui->label_3->setFont(FONT_3);
    ui->label_4->setFont(FONT_3);
    ui->label_5->setFont(FONT_3);
    ui->label_6->setFont(FONT_2);
    ui->label_7->setFont(FONT_2);
    ui->label_8->setFont(FONT_2);

    ui->label_1->setText(str_shoucetui);
    ui->label_2->setText(str_weizuozhutui);
    ui->label_3->setText(str_weiyouzhutui);
    ui->label_4->setText(str_zuoduoji);
    ui->label_5->setText(str_youduoji);
    ui->label_6->setText(str_jiuxu);
    ui->label_7->setText(str_yunxing);
    ui->label_8->setText(str_qiyong);

    ui->pbOK->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);

    ui->pbOK->setText(str_queding);
    ui->pbCancel->setText(str_quxiao);

    if(leEnable_Prop1->text() == "是" || leEnable_Prop1->text() == "Yes")
        leEnable_Prop1->setText(str_yes);
    else
        leEnable_Prop1->setText(str_no);

    if(leEnable_Prop2->text() == "是" || leEnable_Prop2->text() == "Yes")
        leEnable_Prop2->setText(str_yes);
    else
        leEnable_Prop2->setText(str_no);

    if(leEnable_Prop3->text() == "是" || leEnable_Prop3->text() == "Yes")
        leEnable_Prop3->setText(str_yes);
    else
        leEnable_Prop3->setText(str_no);

    if(leEnable_Rudder1->text() == "是" || leEnable_Rudder1->text() == "Yes")
        leEnable_Rudder1->setText(str_yes);
    else
        leEnable_Rudder1->setText(str_no);

    if(leEnable_Rudder2->text() == "是" || leEnable_Rudder2->text() == "Yes")
        leEnable_Rudder2->setText(str_yes);
    else
        leEnable_Rudder2->setText(str_no);


}

PropellerEnableWidget::~PropellerEnableWidget()
{
    delete ui;
}
