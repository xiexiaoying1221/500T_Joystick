/*
    自动舵设置
*/

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "autoruddersettingwidget.h"
#include "ui_autoruddersettingwidget.h"

AutoRudderSettingWidget::AutoRudderSettingWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::AutoRudderSettingWidget)
{
    ui->setupUi(this);

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());

    this->setAutoFillBackground(true);

    QPalette p;
    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_3)));//"images/设置艏向-日.png"
    this->setPalette(p);

    ui->groupBox->setVisible(false);

    leGainLevel = new LineEdit(this);
    leGainLevel->setGeometry(ui->leGainLevel_->geometry());
    leGainLevel->setReadOnly(true);
    leGainLevel->setText(ui->leGainLevel_->text());
    leGainLevel->setStyleSheet(ui->leGainLevel_->styleSheet());
    leGainLevel->setFont(ui->leGainLevel_->font());

    leCounterRudder = new LineEdit(this);
    leCounterRudder->setGeometry(ui->leCounterRudder_->geometry());
    leCounterRudder->setReadOnly(true);
    leCounterRudder->setText(ui->leCounterRudder_->text());
    leCounterRudder->setStyleSheet(ui->leCounterRudder_->styleSheet());
    leCounterRudder->setFont(ui->leCounterRudder_->font());

    leAutoTrim = new LineEdit(this);
    leAutoTrim->setGeometry(ui->leAutoTrim_->geometry());
    leAutoTrim->setReadOnly(true);
    leAutoTrim->setText(ui->leAutoTrim_->text());
    leAutoTrim->setStyleSheet(ui->leAutoTrim_->styleSheet());
    leAutoTrim->setFont(ui->leAutoTrim_->font());

    leWeather = new LineEdit(this);
    leWeather->setGeometry(ui->leWeather_->geometry());
    leWeather->setReadOnly(true);
    leWeather->setText(ui->leWeather_->text());
    leWeather->setStyleSheet(ui->leWeather_->styleSheet());
    leWeather->setFont(ui->leWeather_->font());

    leRateTurn = new LineEdit(this);
    leRateTurn->setGeometry(ui->leRateTurn_->geometry());
    leRateTurn->setReadOnly(true);
    leRateTurn->setText(ui->leRateTurn_->text());
    leRateTurn->setStyleSheet(ui->leRateTurn_->styleSheet());
    leRateTurn->setFont(ui->leRateTurn_->font());

    connect(leGainLevel,SIGNAL(clicked()),this,SLOT(leGainLevel_click()));
    connect(leCounterRudder,SIGNAL(clicked()),this,SLOT(leCounterRudder_click()));
    connect(leAutoTrim,SIGNAL(clicked()),this,SLOT(leAutoTrim_click()));
    connect(leWeather,SIGNAL(clicked()),this,SLOT(leWeather_click()));
    connect(leRateTurn,SIGNAL(clicked()),this,SLOT(leRateTurn_click()));


    /*按键区 事件-槽*/
    connect(ui->pb0,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb1,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb2,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb3,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb4,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb5,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb6,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb7,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb8,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pb9,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pbPoint,SIGNAL(clicked()),this,SLOT(gbpbNumber_click()));
    connect(ui->pbOK,SIGNAL(clicked()),this,SLOT(gbpbOK_click()));
}


//白天、夜晚模式切换
void AutoRudderSettingWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_4)));//"images/推进器启用设置-日.png"
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_4)));//"images/推进器启用设置-夜.png"
    }
    this->setPalette(p);
}

void AutoRudderSettingWidget::leGainLevel_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(le->text() == "Hi")
        le->setText("Low");
    else if(le->text()=="Low")
        le->setText("Med");
    else
        le->setText("Hi");
}

void AutoRudderSettingWidget::leCounterRudder_click()
{
    QLineEdit *lineEdit = (QLineEdit*)QObject::sender();
    float rudder = lineEdit->text().toFloat();

    rudder += 5;
    if(rudder > 150)
        rudder = 50;

    lineEdit->setText(QString("%1.0").arg(rudder));
}

void AutoRudderSettingWidget::leAutoTrim_click()
{
    QLineEdit *lineEdit = (QLineEdit*)QObject::sender();
    float rudder = lineEdit->text().toFloat();

    rudder += 5;
    if(rudder > 150)
        rudder = 50;

    lineEdit->setText(QString("%1.0").arg(rudder));
}

void AutoRudderSettingWidget::leWeather_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(le->text() == "Off")
        le->setText("On");
    else
        le->setText("Off");
}

void AutoRudderSettingWidget::leRateTurn_click()
{
    ui->groupBox->setVisible(true);
    leRateTurn->setText("");
}

/*小键盘*/
void AutoRudderSettingWidget::gbpbNumber_click()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString text = button->text();
    if(text == "．")
        text = ".";

    leRateTurn->setText(leRateTurn->text() + text);
}

void AutoRudderSettingWidget::gbpbOK_click()
{
    QString text = leRateTurn->text();

    bool ok;
//    double a = text.toDouble(&ok);
    float a = text.toFloat(&ok);
    if(!ok)
    {
        leRateTurn->setText("");
    }
    else
    {
       if(a  > 999) return;
       ui->groupBox->setVisible(false);
       leRateTurn->setFocus();
    }
}

AutoRudderSettingWidget::~AutoRudderSettingWidget()
{
    delete ui;
}
