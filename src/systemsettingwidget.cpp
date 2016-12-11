/*
    系统设置对话框视图
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "systemsettingwidget.h"
#include "ui_systemsettingwidget.h"

SystemSettingWidget::SystemSettingWidget(QWidget *parent,QRect rect) :
    QWidget(parent),
    ui(new Ui::SystemSettingWidget)
{
    ui->setupUi(this);


    this->setGeometry(rect.x(), rect.y(), rect.width(),rect.height());

    QTime cTime = QTime::currentTime();
    QDate cDate = QDate::currentDate();

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_18)));//"images/systemset_day.png"
//    this->setPalette(p);

    //QFont font("Microsoft Sans Serif",16);

    ui->leYear_->setFont(FONT_9);
    ui->leMonth_->setFont(FONT_9);
    ui->leDay_->setFont(FONT_9);
    ui->leHour_->setFont(FONT_9);
    ui->leMinute_->setFont(FONT_9);
    ui->leSecond_->setFont(FONT_9);
    ui->label_1->setFont(FONT_3);
    ui->label_2->setFont(FONT_3);
    ui->label_3->setFont(FONT_3);
    ui->label_4->setFont(FONT_3);
    ui->label_5->setFont(FONT_3);
    ui->label_6->setFont(FONT_3);
    ui->label_7->setFont(FONT_3);
    ui->label_8->setFont(FONT_3);
    ui->label_9->setFont(FONT_3);
    ui->pbOK->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);
    ui->pbClose_->setFont(FONT_3);
    ui->pbRestart_->setFont(FONT_3);


    ui->leYear_->setText(QString("%1").arg(cDate.year()));
    ui->leYear_->setProperty("numinput", true);
    ui->leYear_->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    ui->leMonth_->setText(QString("%1").arg(cDate.month()));
    ui->leMonth_->setProperty("numinput", true);
    ui->leMonth_->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    ui->leDay_->setText(QString("%1").arg(cDate.day()));
    ui->leDay_->setProperty("numinput", true);
    ui->leDay_->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    ui->leHour_->setText(QString("%1").arg(cTime.hour()));
    ui->leHour_->setProperty("numinput", true);
    ui->leHour_->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    ui->leMinute_->setText(QString("%1").arg(cTime.minute()));
    ui->leMinute_->setProperty("numinput", true);
    ui->leMinute_->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    ui->leSecond_->setText(QString("%1").arg(cTime.second()));
    ui->leSecond_->setProperty("numinput", true);
    ui->leSecond_->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    ui->pbClose_->setText(str_no);//"否"
    ui->pbClose_->setStyleSheet("border-width:0; border-style:outset;  background-color: rgb(255, 0, 0);");

    ui->pbRestart_->setText(str_no);//"否"
    ui->pbRestart_->setStyleSheet("border-width:0; border-style:outset;  background-color: rgb( 255,0, 0);");

    /*按键区 事件-槽*/
    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOk_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));

    changeDNMode();
    Refresh_changless_words();
}

//白天、夜晚模式切换
void SystemSettingWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_18)));//"images/systemset_day.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_5->setStyleSheet(StyleSheet_DayColor);
        ui->label_6->setStyleSheet(StyleSheet_DayColor);
        ui->label_7->setStyleSheet(StyleSheet_DayColor);
        ui->label_8->setStyleSheet(StyleSheet_DayColor);
        ui->label_9->setStyleSheet(StyleSheet_DayColor);

        p.setColor(QPalette::Text,COLOR_15);

    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_18)));//"images/systemset_night.png"
        this->setPalette(p);
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_5->setStyleSheet(StyleSheet_NgtColor);
        ui->label_6->setStyleSheet(StyleSheet_NgtColor);
        ui->label_7->setStyleSheet(StyleSheet_NgtColor);
        ui->label_8->setStyleSheet(StyleSheet_NgtColor);
        ui->label_9->setStyleSheet(StyleSheet_NgtColor);

        p.setColor(QPalette::Text,COLOR_23);
    }

    ui->leDay_->setPalette(p);
    ui->leMonth_->setPalette(p);
    ui->leYear_->setPalette(p);
    ui->leHour_->setPalette(p);
    ui->leMinute_->setPalette(p);
    ui->leSecond_->setPalette(p);
    ui->pbClose_->setPalette(p);
    ui->pbRestart_->setPalette(p);
}

void SystemSettingWidget::pbOk_clicked()
{
    /*设置系统时间*/
    int year = ui->leYear_->text().toInt();
    int month = ui->leMonth_->text().toInt();
    int day = ui->leDay_->text().toInt();
    int hour = ui->leHour_->text().toInt();
    int minute = ui->leMinute_->text().toInt();
    int second = ui->leSecond_->text().toInt();

    SYSTEMTIME st;

    st.wYear=year;
    st.wMonth=month;
    st.wDay=day;
    st.wHour = hour;//时区问题
    st.wMinute = minute;
    st.wSecond = second;
    st.wDayOfWeek= 0;
    st.wMilliseconds= 0;

    SetLocalTime(&st) ;   //Win32 API 设置系统时间


    /*关机、重启*/
    if(ui->pbClose_->text()==str_yes || ui->pbRestart_->text() == str_yes)
    {
        HANDLE hToken;
        TOKEN_PRIVILEGES tkp;

        //获取进程标志
        if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
             return;

        //获取关机特权的LUID
        LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,    &tkp.Privileges[0].Luid);
        tkp.PrivilegeCount = 1;
        tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

        //获取这个进程的关机特权
        AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
        if (GetLastError() != ERROR_SUCCESS) return;


        if(ui->pbClose_->text()==str_yes)
        {
           // ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0);

            QCoreApplication::exit(1);
        }
        else if(ui->pbRestart_->text() == str_yes)
        {
           // ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0);
            qApp->quit();
            QProcess::startDetached(qApp->applicationFilePath(), QStringList());
        }
    }



//    time_t t;
//    struct tm nowtime;
//    nowtime.tm_sec=8;/* Seconds.[0-60] (1leapsecond)*/
//    nowtime.tm_min=7;/* Minutes.[0-59]  */
//    nowtime.tm_hour=6;/* Hours. [0-23]*/
//    nowtime.tm_mday=5;/* Day.[1-31] */
//    nowtime.tm_mon=4-1;/* Month. [0-11]*/
//    nowtime.tm_year=2013-1900 ;/* Year-1900.*/
//    nowtime.tm_isdst=-1 ;/* DST.[-1/0/1]*/
//    t=mktime(&nowtime);
//    stime(&t);


    emit ok_signal(this->objectName());
}
void SystemSettingWidget::Refresh_changless_words()
{

    ui->label_1->setText(str_year_XTSZ);//年
    ui->label_2->setText(str_month_XTSZ);//月
    ui->label_3->setText(str_day_XTSZ);//日
    ui->label_4->setText(str_hour_XTSZ);//时
    ui->label_5->setText(str_minute_XTSZ);//分
    ui->label_6->setText(str_second_XTSZ);//秒
    ui->label_7->setText(str_guanbixitong_XTSZ);//关闭系统
    ui->label_8->setText(str_guanbizhongduan_XTSZ);//关闭此操作终端
    ui->label_9->setText(str_chongqizhongduan_XTSZ);//重启此操作终端
    ui->pbOK->setText(str_queding);//确定
    ui->pbCancel->setText(str_quxiao);//取消

    if(ui->pbClose_->text() == "Yes" || ui->pbClose_->text() == "是")
        ui->pbClose_->setText(str_yes);
    else
        ui->pbClose_->setText(str_no);

    if(ui->pbRestart_->text() == "Yes" || ui->pbRestart_->text() == "是")
        ui->pbRestart_->setText(str_yes);
    else
        ui->pbRestart_->setText(str_no);

}
void SystemSettingWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}


SystemSettingWidget::~SystemSettingWidget()
{
    delete ui;
}

void SystemSettingWidget::on_leYear__editingFinished()
{
    QDate cDate = QDate::currentDate();
    QString res = ui->leYear_->text();
    bool ok;
    int resInt = res.toInt(&ok);
    if(ok){
        if(resInt > 2100)        ui->leYear_->setText(QString::number(2100) );
        else if (resInt <2000)   ui->leYear_->setText(QString::number(2000) );
    }
    else{
        ui->leYear_->setText(QString("%1").arg(cDate.year()));
    }
}

void SystemSettingWidget::on_leMonth__editingFinished()
{
    QDate cDate = QDate::currentDate();
    QString res = ui->leMonth_->text();
    bool ok;
    int resInt = res.toInt(&ok);
    if(ok){
        if(resInt > 12)        ui->leMonth_->setText(QString::number(12) );
        else if (resInt <1)    ui->leMonth_->setText(QString::number(1) );
    }
    else{
        ui->leMonth_->setText(QString("%1").arg(cDate.month()));
    }
}

void SystemSettingWidget::on_leDay__editingFinished()
{
    QDate cDate = QDate::currentDate();
    QString res = ui->leDay_->text();
    bool ok;
    int resInt = res.toInt(&ok);
    if(ok){
        if(resInt > 31)        ui->leDay_->setText(QString::number(31) );
        else if (resInt <1)    ui->leDay_->setText(QString::number(1) );
    }
    else{
        ui->leDay_->setText(QString("%1").arg(cDate.day()));
    }
}

void SystemSettingWidget::on_leHour__editingFinished()
{
    QTime cTime = QTime::currentTime();
    QString res = ui->leHour_->text();
    bool ok;
    int resInt = res.toInt(&ok);
    if(ok){
        if(resInt > 24)        ui->leHour_->setText(QString::number(24) );
        else if (resInt <0)    ui->leHour_->setText(QString::number(0 ) );
    }
    else{
        ui->leHour_->setText(QString("%1").arg(cTime.hour()));
    }
}

void SystemSettingWidget::on_leMinute__editingFinished()
{
    QTime cTime = QTime::currentTime();
    QString res = ui->leMinute_->text();
    bool ok;
    int resInt = res.toInt(&ok);
    if(ok){
        if(resInt > 60)        ui->leMinute_->setText(QString::number(60) );
        else if (resInt <0)    ui->leMinute_->setText(QString::number(0 ) );
    }
    else{
        ui->leMinute_->setText(QString("%1").arg(cTime.minute()));
    }
}

void SystemSettingWidget::on_leSecond__editingFinished()
{
    QTime cTime = QTime::currentTime();
    QString res = ui->leSecond_->text();
    bool ok;
    int resInt = res.toInt(&ok);
    if(ok){
        if(resInt > 60)        ui->leSecond_->setText(QString::number(60) );
        else if (resInt <0)    ui->leSecond_->setText(QString::number(0 ) );
    }
    else{
        ui->leSecond_->setText(QString("%1").arg(cTime.second()));
    }
}

void SystemSettingWidget::on_pbClose__clicked()
{
    QString text = ui->pbClose_->text();

    if(text == "否" || text == "No")
    {
        ui->pbClose_->setText(str_yes);
        ui->pbClose_->setStyleSheet("border-width:0; border-style:outset; background-color: rgb( 0, 255, 0);");
    }
    else
    {
        ui->pbClose_->setText(str_no);
        ui->pbClose_->setStyleSheet("border-width:0; border-style:outset; background-color: rgb( 255, 0, 0);");
    }
}

void SystemSettingWidget::on_pbRestart__clicked()
{
    QString text = ui->pbRestart_->text();
    if(text == "否" || text == "No")
    {
        ui->pbRestart_->setText(str_yes);
        ui->pbRestart_->setStyleSheet("border-width:0; border-style:outset; background-color: rgb( 0, 255, 0);");
    }
    else
    {
        ui->pbRestart_->setText(str_no);
        ui->pbRestart_->setStyleSheet("border-width:0; border-style:outset; background-color: rgb( 255, 0, 0);");
    }
}
