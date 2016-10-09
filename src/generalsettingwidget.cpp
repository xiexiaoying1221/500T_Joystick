/*
    总体设置
*/
#include "generalsettingwidget.h"
#include "ui_generalsettingwidget.h"

GeneralSettingWidget::GeneralSettingWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::GeneralSettingWidget)
{
    ui->setupUi(this);


    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_5)));//"images/总体设置-日.png"
//    this->setPalette(p);

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());

    ui->groupBox->setVisible(false);
    ui->groupBox->setStyleSheet("background-image: url(:/images/设置区.png);");

    leThrusterAlloc = new LineEdit(this);
    leRateTurn = new LineEdit(this);
    leDraughtType = new LineEdit(this);
    leWindComp = new LineEdit(this);
    leGainLevel = new LineEdit(this);

    changeDNMode();

    leThrusterAlloc->setGeometry(ui->leThrusterAlloc_->geometry());
    leThrusterAlloc->setReadOnly(true);
    leThrusterAlloc->setText(ui->leThrusterAlloc_->text());
    leThrusterAlloc->setStyleSheet(ui->leThrusterAlloc_->styleSheet());
    leThrusterAlloc->setFont(ui->leThrusterAlloc_->font());


    leRateTurn->setGeometry(ui->leRateTurn_->geometry());
    leRateTurn->setReadOnly(true);
    leRateTurn->setText(ui->leRateTurn_->text());
    leRateTurn->setStyleSheet(ui->leRateTurn_->styleSheet());
    leRateTurn->setFont(ui->leRateTurn_->font());


    leDraughtType->setGeometry(ui->leDraughtType_->geometry());
    leDraughtType->setReadOnly(true);
    leDraughtType->setText(ui->leDraughtType_->text());
    leDraughtType->setStyleSheet(ui->leDraughtType_->styleSheet());
    leDraughtType->setFont(ui->leDraughtType_->font());


    leWindComp->setGeometry(ui->leWindComp_->geometry());
    leWindComp->setReadOnly(true);
    leWindComp->setText(ui->leWindComp_->text());
    leWindComp->setStyleSheet(ui->leWindComp_->styleSheet());
    leWindComp->setFont(ui->leWindComp_->font());


    leGainLevel->setGeometry(ui->leGainLevel_->geometry());
    leGainLevel->setReadOnly(true);
    leGainLevel->setText(ui->leGainLevel_->text());
    leGainLevel->setStyleSheet(ui->leGainLevel_->styleSheet());
    leGainLevel->setFont(ui->leGainLevel_->font());

    connect(leThrusterAlloc,SIGNAL(clicked()),this,SLOT(leThrusterAlloc_click()));
    connect(leRateTurn,SIGNAL(clicked()),this,SLOT(leRateTurn_click()));
    connect(leDraughtType,SIGNAL(clicked()),this,SLOT(leDraughtType_click()));
    connect(leWindComp,SIGNAL(clicked()),this,SLOT(leWindComp_click()));
    connect(leGainLevel,SIGNAL(clicked()),this,SLOT(leGainLevel_click()));

    leThrusterAlloc->setText(mode_thrAlloc == 1 ? "模式一" : "模式二");

    leRateTurn->setText(QString::number(set_rot,'f',1));
    if(drughttype == 1)
        leDraughtType->setText(str_moshi1);//"模式一"
    else if(drughttype == 2 )
         leDraughtType->setText(str_moshi2);//"模式二"
    else
         leDraughtType->setText(str_moshi3);//"模式三"

    leWindComp->setText(flag_windcomp ? str_on : str_off);//"On" : "Off"

    if(gainlevel == 1)
        leGainLevel->setText(str_di);//"Low"
    else if(gainlevel == 2)
        leGainLevel->setText(str_zhong);//"Middle"
    else
        leGainLevel->setText(str_gao);//"High"


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
    connect(ui->gbpbOK,SIGNAL(clicked()),this,SLOT(gbpbOK_click()));

    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOK_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

     ui->groupBox->raise();//上层显示

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));
}


//白天、夜晚模式切换
void GeneralSettingWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_5)));//"images/总体设置-日.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_5->setStyleSheet(StyleSheet_DayColor);

        p.setColor(QPalette::Text,QColor(COLOR_15));
        leDraughtType->setPalette(p);
        leThrusterAlloc->setPalette(p);
        leRateTurn->setPalette(p);
        leWindComp->setPalette(p);
        leGainLevel->setPalette(p);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_5)));//"images/总体设置-夜.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_5->setStyleSheet(StyleSheet_NgtColor);

        p.setColor(QPalette::Text,QColor(COLOR_23));
        leDraughtType->setPalette(p);
        leThrusterAlloc->setPalette(p);
        leRateTurn->setPalette(p);
        leWindComp->setPalette(p);
        leGainLevel->setPalette(p);
    }
}

void GeneralSettingWidget::leThrusterAlloc_click()
{
     QLineEdit *le = qobject_cast<QLineEdit *>(sender());
     if(le->text() == "模式一" || le->text() == "Mode 1")
         le->setText(str_moshi2);//"模式二"
     else
         le->setText(str_moshi1);//"模式一"
}

void GeneralSettingWidget::leRateTurn_click()
{
    ui->groupBox->setVisible(true);
    leRateTurn->setText("");
}

void GeneralSettingWidget::leDraughtType_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(le->text() == "模式一"  || le->text() == "Mode 1")
        le->setText(str_moshi2);//"模式二"
    else if(le->text() == "模式二"  || le->text() == "Mode 2")
        le->setText(str_moshi3);//"模式三"
    else
        le->setText(str_moshi1);//"模式一"
}

void GeneralSettingWidget::leWindComp_click()
{
     QLineEdit *le = qobject_cast<QLineEdit *>(sender());
     if(le->text() == "Off" || le->text() == "关")
         le->setText(str_on);//"On"
     else
         le->setText(str_off);//"Off"
}

void GeneralSettingWidget::leGainLevel_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if(le->text() == "Low" || le->text() == "低")
        le->setText(str_zhong);//"Middle"
    else if(le->text()=="Middle" || le->text() == "中")
        le->setText(str_gao);//"High"
    else
        le->setText(str_di);//"Low"
}

void GeneralSettingWidget::gbpbNumber_click()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString text = button->text();
    if(text == "．")
        text = ".";

    leRateTurn->setText(leRateTurn->text() + text);
}

void GeneralSettingWidget::gbpbOK_click()
{
    QString text = leRateTurn->text();

    bool ok;
    double a = text.toDouble(&ok);
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

void GeneralSettingWidget::pbOK_clicked()
{
    bool isOk;
    mode_thrAlloc = leThrusterAlloc->text() == str_moshi1 ? 1 :2 ;//"模式一"
    set_rot = leRateTurn->text().toDouble(&isOk);
    if(!isOk)
        set_rot =0;

    if(leDraughtType->text() == "模式一"  || leDraughtType->text() == "Mode 1")
        drughttype = 1;
    else if(leDraughtType->text() == "模式二"  || leDraughtType->text() == "Mode 2")
        drughttype = 2;
    else
        drughttype = 3;

    flag_windcomp = leWindComp->text() == str_off ? 0 : 1;//"Off"

    if(leGainLevel->text() == "Low" || leGainLevel->text() == "低")
        gainlevel = 1;
    else if(leGainLevel->text() == "Middle" || leGainLevel->text() == "中")
        gainlevel = 2;
    else
        gainlevel = 3;

    emit ok_signal(this->objectName());
}
void GeneralSettingWidget::Refresh_changless_words()
{
    ui->label_1->setFont(FONT_3);
    ui->label_1->setText(str_tuilifenpeimoshi_ZTSZ);

    ui->label_2->setFont(FONT_3);
    ui->label_2->setText(str_shezhihuizhuanlv_ZTSZ);

    ui->label_3->setFont(FONT_3);
    ui->label_3->setText(str_fenglibuchang_ZTSZ);

    ui->label_4->setFont(FONT_3);
    ui->label_4->setText(str_zengyidengji_ZTSZ);

    ui->label_5->setFont(FONT_3);
    ui->label_5->setText(str_chuanbochishuileixing_ZTSZ);

    ui->pbOk->setFont(FONT_3);
    ui->pbOk->setText(str_queding);

    ui->pbCancel->setFont(FONT_3);
    ui->pbCancel->setText(str_quxiao);

    leDraughtType->setFont(FONT_3);

    if(leDraughtType->text() == "Mode 1" || leDraughtType->text() == "模式一")
        leDraughtType->setText(str_moshi1);
    else if(leDraughtType->text() == "Mode 2" || leDraughtType->text() == "模式二")
        leDraughtType->setText(str_moshi2);
    else
        leDraughtType->setText(str_moshi3);

    leThrusterAlloc->setFont(FONT_3);

    if(leThrusterAlloc->text() == "Mode 1" || leThrusterAlloc->text() == "模式一")
            leThrusterAlloc->setText(str_moshi1);
        else
            leThrusterAlloc->setText(str_moshi2);

    leGainLevel->setFont(FONT_3);

    if(leGainLevel->text() == "高" || leGainLevel->text() == "High")
        leGainLevel->setText(str_gao);
    else if(leGainLevel->text() == "中" || leGainLevel->text() == "Middle")
        leGainLevel->setText(str_zhong);
    else
        leGainLevel->setText(str_di);

    leWindComp->setFont(FONT_3);

    if(leWindComp->text() == "开" || leWindComp->text() == "On")
        leWindComp->setText(str_on);
    else
        leWindComp->setText(str_off);

    ui->gbpbOK->setFont(FONT_1);
    ui->gbpbOK->setText(str_queding);
}
void GeneralSettingWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

GeneralSettingWidget::~GeneralSettingWidget()
{
    delete ui;
}


