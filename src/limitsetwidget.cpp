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

    QFont font("Microsoft Sans Serif",16);

    leHeadWarnActive = new LineEdit(this);
    leHeadAlarmActive = new LineEdit(this);
    leHeadWarnLimit = new LineEdit(this);
    leHeadAlarmLimit = new LineEdit(this);

    changeDNMode();

    /*艏向限定*/
    leHeadWarnActive->setGeometry(ui->leHeadWarnActive_->geometry());
    leHeadWarnActive->setReadOnly(true);
    if(flag_alarmh)
    {
        leHeadWarnActive->setText(str_yes);//"是"
        leHeadWarnActive->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
    }
    else
    {
        leHeadWarnActive->setText(str_no);//"否"
        leHeadWarnActive->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
    }

    leHeadWarnActive->setFont(FONT_3);

    leHeadAlarmActive->setGeometry(ui->leHeadAlarmActive_->geometry());
    leHeadAlarmActive->setReadOnly(true);

    if(flag_alarmh)
    {
        leHeadAlarmActive->setText(str_yes);//"是"
        leHeadAlarmActive->setStyleSheet("background-color: rgb(0, 255, 0); border-width:0; border-style:outset;");
    }
    else
    {
        leHeadAlarmActive->setText(str_no);//"否"
        leHeadAlarmActive->setStyleSheet("background-color: rgb(255, 0, 0); border-width:0; border-style:outset;");
    }

    leHeadAlarmActive->setFont(FONT_3);

    leHeadWarnLimit->setGeometry(ui->leHeadWarnLimit_->geometry());
    leHeadWarnLimit->setReadOnly(true);
    leHeadWarnLimit->setText(QString::number(Warning_head,'f',1));
    leHeadWarnLimit->setFont(FONT_9);
    leHeadWarnLimit->setStyleSheet(ui->leHeadWarnLimit_->styleSheet());
    leHeadWarnLimit->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    leHeadAlarmLimit->setGeometry(this->ui->leHeadAlarmLimit_->geometry());
    leHeadAlarmLimit->setReadOnly(true);
    leHeadAlarmLimit->setText(QString::number(Alarm_head,'f',1));
    leHeadAlarmLimit->setFont(FONT_9);
    leHeadAlarmLimit->setStyleSheet(ui->leHeadAlarmLimit_->styleSheet());
    leHeadAlarmLimit->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);


    connect(leHeadWarnActive,SIGNAL(clicked()),this,SLOT(setActive()));
    connect(leHeadAlarmActive,SIGNAL(clicked()),this,SLOT(setActive()));


    connect(leHeadWarnLimit,SIGNAL(clicked()),this,SLOT(setWarningLimit()));
    connect(leHeadAlarmLimit,SIGNAL(clicked()),this,SLOT(setAlarmLimit()));

    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOk_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));
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

    leHeadWarnActive->setPalette(p);
    leHeadAlarmActive->setPalette(p);
    leHeadWarnLimit->setPalette(p);
    leHeadAlarmLimit->setPalette(p);
}

void LimitSetWidget::Refresh_changless_words()
{
    ui->label_1->setFont(FONT_3);
    ui->label_1->setText(str_shouxiangxianzhi);

    ui->label_3->setFont(FONT_3);
    ui->label_4->setFont(FONT_3);
    ui->label_3->setText(str_jinggao);
    ui->label_4->setText(str_baojing);

    ui->label_9->setFont(FONT_2);
    ui->label_10->setFont(FONT_2);

    ui->label_9->setText(str_qiyong);
    ui->label_10->setText(str_xianzhi);

    ui->pbOk->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);

    ui->pbOk->setText(str_queding);
    ui->pbCancel->setText(str_quxiao);

    leHeadWarnActive->setFont(FONT_3);
    if(leHeadWarnActive->text() == "是" || leHeadWarnActive->text() == "Yes")
       leHeadWarnActive->setText(str_yes);
    else
        leHeadWarnActive->setText(str_no);

    leHeadAlarmActive->setFont(FONT_3);
    if(leHeadAlarmActive->text() == "是" || leHeadAlarmActive->text() == "Yes")
        leHeadAlarmActive->setText(str_yes);
    else
        leHeadAlarmActive->setText(str_no);
}


LimitSetWidget::~LimitSetWidget()
{
    delete ui;
}

void LimitSetWidget::setActive(){
    QLineEdit *lineEdit = (QLineEdit*)QObject::sender();
    if(lineEdit->text() == "是" || lineEdit->text() == "Yes")
    {
        lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);border-width:0; border-style:outset;");
        lineEdit->setText(str_no);//"否"
    }
    else
    {
        lineEdit->setStyleSheet("background-color: rgb(0, 255, 0);border-width:0; border-style:outset;");
        lineEdit->setText(str_yes);
    }

    QPalette p;
    if(daynight_mode == DAYMODE)
    {
         p.setColor(QPalette::Text,QColor(COLOR_15));
    }
    else
    {
         p.setColor(QPalette::Text,QColor(COLOR_23));
    }
    lineEdit->setPalette(p);
}

void LimitSetWidget::setWarningLimit(){
    QLineEdit *lineEdit = (QLineEdit*)QObject::sender();
    float active = lineEdit->text().toFloat();

    active += 0.5;
    if(active > 5)
        active = 1;

    lineEdit->setText(QString("%1").arg(active,0,'f',1));
}

void LimitSetWidget::setAlarmLimit(){
    QLineEdit *lineEdit = (QLineEdit*)QObject::sender();
    float limit = lineEdit->text().toFloat();

    limit += 0.5;
    if(limit > 10)
        limit = 3;

    lineEdit->setText(QString("%1").arg(limit,0,'f',1));
}

void LimitSetWidget::pbOk_clicked(){
    flag_warningh = leHeadWarnActive->text() == str_yes ? 1 : 0;//"是" ? 1 : 0;
    flag_alarmh = leHeadAlarmActive->text() == str_yes ? 1 : 0;//"是" ? 1 : 0;
    Warning_head = leHeadWarnLimit->text().toFloat();
    Alarm_head = leHeadAlarmLimit->text().toFloat();

    emit ok_signal(this->objectName());
}

void LimitSetWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}
