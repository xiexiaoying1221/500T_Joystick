#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "headingsetpwidget.h"
#include "ui_headingsetpwidget.h"

HeadingSetpWidget::HeadingSetpWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::HeadingSetpWidget)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());


    QPalette p;
    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_6)));//"images/设置艏向-日.png"
    this->setPalette(p);


    connect(ui->dial,SIGNAL(valueChanged(int)),SLOT(dialValueChanged(int)));
    connect(ui->pbAdd,SIGNAL(clicked()),SLOT(pbAdd_clicked()));
    connect(ui->pbReduce,SIGNAL(clicked()),SLOT(pbReduce_clicked()));
    connect(ui->pbOK,SIGNAL(clicked()),SLOT(pbOK_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),SLOT(pbCancel_clicked()));

//    connect(this,SIGNAL(changecurrenthead()),keyWidget,SLOT(changeCurrentHead()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));

    ui->dial->setValue( convert2dial( set_heading ) );

}

//白天、夜晚模式切换
void HeadingSetpWidget::changeDNMode()
{
//    ui->dial->setStyleSheet("background-color: rgb(221, 221, 221);");
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_6)));//"images/设置艏向-日.png"
        this->setPalette(p);
        ui->dial->setStyleSheet("background-color: rgb(230, 230, 230);");
        p.setColor(QPalette::Text,QColor(COLOR_15));
        ui->leHead->setPalette(p);

        ui->pbOK->setStyleSheet(StyleSheet_DayColor);
        ui->pbCancel->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_6)));//"images/设置艏向-夜.png"
        this->setPalette(p);
        ui->dial->setStyleSheet("background-color: rgb(10, 10, 10);");
        p.setColor(QPalette::Text,QColor(COLOR_23));
        ui->leHead->setPalette(p);

//        ui->pbOK->setStyleSheet(StyleSheet_NgtColor);
//        ui->pbCancel->setStyleSheet(StyleSheet_NgtColor);
    }

}

void HeadingSetpWidget::Refresh_changless_words()
{
    ui->pbOK->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);

    ui->pbOK->setText(str_queding);
    ui->pbCancel->setText(str_quxiao);
}

void HeadingSetpWidget::dialValueChanged(int v)
{
    ui->leHead->setText(QString::number( convert2Text( v ), 'f', 1));
}


void HeadingSetpWidget::pbAdd_clicked()
{
    int dialValue = ui->dial->value();

    dialValue +=1;
    ui->dial->setValue(dialValue);//QString("%1").arg(dialValue/10.0)

    ui->leHead->setText(QString::number( convert2Text( dialValue ), 'f', 1));
}

void HeadingSetpWidget::pbReduce_clicked()
{
    int dialValue = ui->dial->value();

    dialValue -= 1;
    ui->dial->setValue(dialValue);//QString("%1").arg(dialValue/10.0)

    ui->leHead->setText(QString::number( convert2Text( dialValue ), 'f', 1));
}

void HeadingSetpWidget::pbOK_clicked()
{
    set_heading = convert2Text( ui->dial->value() );
//    emit changecurrenthead();//发送信号到按键区 改变当前艏向背景
    emit ok_signal(this->objectName());
}


void HeadingSetpWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

HeadingSetpWidget::~HeadingSetpWidget()
{
    delete ui;
}

int HeadingSetpWidget::convert2dial (float value){
    //value:0.0-360.0，零度在正北方向，逆时针增加
    //dial:0-3600，零度在正南方向，逆时针增加
    while(value < 0.0){
        value += 360.0;
    }
    while(value >=360.0){
        value -= 360.0;
    }
    if(value < 180.0){
        return (1800 + (int)(value *10.0) );
    }
    else{
        return ((int)(value *10.0) - 1800 );
    }
}

float HeadingSetpWidget::convert2Text (int dial){
    //value:0.0-360.0，零度在正北方向，逆时针增加
    //dial:0-3600，零度在正南方向，逆时针增加
    while(dial < 0){
        dial += 3600;
    }
    while(dial >=3600){
        dial -= 3600;
    }
    if(dial < 1800){
        return (180.0 + (float)(dial /10.0) );
    }
    else{
        return ((float)(dial /10.0) - 180.0 );
    }
}
