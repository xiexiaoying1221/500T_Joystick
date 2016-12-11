/*
    限值设置
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "limitsetwidget.h"
#include "ui_limitsetwidget.h"

LimitSetWidget::LimitSetWidget(QWidget *parent,QRect viewAreaRect) :
    QWidget(parent),
    ui(new Ui::limitSetWidget)
{
    ui->setupUi(this);
    this->setGeometry(viewAreaRect.x()+1,  viewAreaRect.y()+1, viewAreaRect.width()-1,viewAreaRect.height()-1);
    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_8)));//"images/限值设置-日.png"
//    this->setPalette(p);


    ui->label_1->setFont(FONT_3);
    ui->label_3->setFont(FONT_3);
    ui->label_4->setFont(FONT_3);
    ui->label_9->setFont(FONT_2);
    ui->label_10->setFont(FONT_2);
    ui->pbOk->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);
    ui->pbHeadWarnActive_->setFont(FONT_3);
    ui->pbHeadAlarmActive_->setFont(FONT_3);
    ui->leHeadWarnLimit_->setFont(FONT_9);
    ui->leHeadAlarmLimit_->setFont(FONT_9);

    if(flag_alarmh)
    {
        ui->pbHeadWarnActive_->setText(str_yes);//"是"
        ui->pbHeadWarnActive_->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        ui->pbHeadWarnActive_->setText(str_no);//"否"
        ui->pbHeadWarnActive_->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    if(flag_alarmh)
    {
        ui->pbHeadAlarmActive_->setText(str_yes);//"是"
        ui->pbHeadAlarmActive_->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        ui->pbHeadAlarmActive_->setText(str_no);//"否"
        ui->pbHeadAlarmActive_->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }

    ui->leHeadWarnLimit_->setText(QString::number(Warning_head,'f',1));
    ui->leHeadWarnLimit_->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    ui->leHeadAlarmLimit_->setText(QString::number(Alarm_head,'f',1));
    ui->leHeadAlarmLimit_->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOk_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));

    Refresh_changless_words();
    changeDNMode();
}

void LimitSetWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_8)));//"images/限值设置-日.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_9->setStyleSheet(StyleSheet_DayColor);
        ui->label_10->setStyleSheet(StyleSheet_DayColor);
        p.setColor(QPalette::Text,QColor(COLOR_15));
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_8)));//"images/限值设置-夜.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_9->setStyleSheet(StyleSheet_NgtColor);
        ui->label_10->setStyleSheet(StyleSheet_NgtColor);
        p.setColor(QPalette::Text,QColor(COLOR_23));
    }

    ui->pbHeadWarnActive_->setPalette(p);
    ui->pbHeadAlarmActive_->setPalette(p);
    ui->leHeadWarnLimit_->setPalette(p);
    ui->leHeadAlarmLimit_->setPalette(p);
}

void LimitSetWidget::Refresh_changless_words()
{

    ui->label_1->setText(str_shouxiangxianzhi);
    ui->label_3->setText(str_jinggao);
    ui->label_4->setText(str_baojing);
    ui->label_9->setText(str_qiyong);
    ui->label_10->setText(str_xianzhi);
    ui->pbOk->setText(str_queding);
    ui->pbCancel->setText(str_quxiao);

    if(ui->pbHeadWarnActive_->text() == "是" || ui->pbHeadWarnActive_->text() == "Yes")
       ui->pbHeadWarnActive_->setText(str_yes);
    else
        ui->pbHeadWarnActive_->setText(str_no);

    if(ui->pbHeadAlarmActive_->text() == "是" || ui->pbHeadAlarmActive_->text() == "Yes")
        ui->pbHeadAlarmActive_->setText(str_yes);
    else
        ui->pbHeadAlarmActive_->setText(str_no);
}


LimitSetWidget::~LimitSetWidget()
{
    delete ui;
}

void LimitSetWidget::pbOk_clicked(){
    flag_warningh = ui->pbHeadWarnActive_->text() == str_yes ? 1 : 0;//"是" ? 1 : 0;
    flag_alarmh = ui->pbHeadAlarmActive_->text() == str_yes ? 1 : 0;//"是" ? 1 : 0;
    Warning_head = ui->leHeadWarnLimit_->text().toFloat();
    Alarm_head = ui->leHeadAlarmLimit_->text().toFloat();
    emit ok_signal(this->objectName());

    //20161130增加，保存为文件
    saveParameters();
}

void LimitSetWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

void LimitSetWidget::on_leHeadWarnLimit__editingFinished()
{
    QString res = ui->leHeadWarnLimit_->text();
    bool ok;
    float resReal = res.toFloat(&ok);
    if(ok){
        if(resReal > 5.0)      ui->leHeadWarnLimit_->setText(QString::number(5.0) );
        else if (resReal <1.0)  ui->leHeadWarnLimit_->setText(QString::number(1.0) );
    }
    else{
        ui->leHeadWarnLimit_->setText(QString::number(Warning_head,'f',1) );
    }
}

void LimitSetWidget::on_leHeadAlarmLimit__editingFinished()
{
    QString res = ui->leHeadAlarmLimit_->text();
    bool ok;
    float resReal = res.toFloat(&ok);
    if(ok){
        if(resReal > 10.0)      ui->leHeadAlarmLimit_->setText(QString::number(10.0) );
        else if (resReal <3.0)  ui->leHeadAlarmLimit_->setText(QString::number(3.0) );
    }
    else{
        ui->leHeadAlarmLimit_->setText(QString::number(Alarm_head,'f',1) );
    }
}

void LimitSetWidget::on_pbHeadWarnActive__clicked()
{
    QString oriental = ui->pbHeadWarnActive_->text();
    if( oriental == "是" || oriental == "Yes")
    {
        ui->pbHeadWarnActive_->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        ui->pbHeadWarnActive_->setText(str_no);//"否"
    }
    else
    {
        ui->pbHeadWarnActive_->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
        ui->pbHeadWarnActive_->setText(str_yes);
    }

    changeDNMode();
}

void LimitSetWidget::on_pbHeadAlarmActive__clicked()
{
    QString oriental = ui->pbHeadAlarmActive_->text();
    if( oriental == "是" || oriental == "Yes")
    {
        ui->pbHeadAlarmActive_->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        ui->pbHeadAlarmActive_->setText(str_no);//"否"
    }
    else
    {
        ui->pbHeadAlarmActive_->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
        ui->pbHeadAlarmActive_->setText(str_yes);
    }

    changeDNMode();
}
