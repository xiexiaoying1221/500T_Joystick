/*
    系统设置对话框视图
*/
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

    leYear = new LineEdit(this);
    leMonth = new LineEdit(this);
    leDay = new LineEdit(this);
    leHour = new LineEdit(this);
    leMinute = new LineEdit(this);
    leSecond = new LineEdit(this);
    leClose = new LineEdit(this);
    leRestart = new LineEdit(this);
    changeDNMode();


    leYear->setGeometry(ui->leYear_->geometry());
    leYear->setReadOnly(true);
    leYear->setText(QString("%1").arg(cDate.year()));
    leYear->setFont(FONT_9);
    leYear->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    leMonth->setGeometry(ui->leMonth_->geometry());
    leMonth->setReadOnly(true);
    leMonth->setText(QString("%1").arg(cDate.month()));
    leMonth->setFont(FONT_9);
    leMonth->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    leDay->setGeometry(ui->leDay_->geometry());
    leDay->setReadOnly(true);
    leDay->setText(QString("%1").arg(cDate.day()));
    leDay->setFont(FONT_9);
    leDay->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    leHour->setGeometry(ui->leHour_->geometry());
    leHour->setReadOnly(true);
    leHour->setText(QString("%1").arg(cTime.hour()));
    leHour->setFont(FONT_9);
    leHour->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    leMinute->setGeometry(ui->leMinute_->geometry());
    leMinute->setReadOnly(true);
    leMinute->setText(QString("%1").arg(cTime.minute()));
    leMinute->setFont(FONT_9);
    leMinute->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    leSecond->setGeometry(ui->leSecond_->geometry());
    leSecond->setReadOnly(true);
    leSecond->setText(QString("%1").arg(cTime.second()));
    leSecond->setFont(FONT_9);
    leSecond->setStyleSheet("background-color: transparent;border-width:0;border-style:outset;");

    leClose->setGeometry(ui->leClose_->geometry());
    leClose->setReadOnly(true);
    leClose->setText(str_no);//"否"
    leClose->setFont(FONT_3);
    leClose->setStyleSheet("border-width:0; border-style:outset;  background-color: rgb(255, 0, 0);");

    leRestart->setGeometry(ui->leRestart_->geometry());
    leRestart->setReadOnly(true);
    leRestart->setText(str_no);//"否"
    leRestart->setFont(FONT_3);
    leRestart->setStyleSheet("border-width:0; border-style:outset;  background-color: rgb( 255,0, 0);");

    this->ui->groupBox->setVisible(false);

    /*时间文本框事件-槽*/
    connect(leYear,SIGNAL(clicked()),this,SLOT(leTime_click()));
    connect(leMonth,SIGNAL(clicked()),this,SLOT(leTime_click()));
    connect(leDay,SIGNAL(clicked()),this,SLOT(leTime_click()));
    connect(leHour,SIGNAL(clicked()),this,SLOT(leTime_click()));
    connect(leMinute,SIGNAL(clicked()),this,SLOT(leTime_click()));
    connect(leSecond,SIGNAL(clicked()),this,SLOT(leTime_click()));

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
    connect(ui->gbpbCancel,SIGNAL(clicked()),this,SLOT(gbplCancel_click()));
    connect(ui->gbpbOK,SIGNAL(clicked()),this,SLOT(gbpbOK_click()));


    connect(leClose,SIGNAL(clicked()),this,SLOT(leCloseOrRestart_click()));
    connect(leRestart,SIGNAL(clicked()),this,SLOT(leCloseOrRestart_click()));

    connect(ui->pbOk,SIGNAL(clicked()),this,SLOT(pbOk_clicked()));
    connect(ui->pbCancel,SIGNAL(clicked()),this,SLOT(pbCancel_clicked()));

    //确定、取消信号-槽
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));
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

    leDay->setPalette(p);
    leMonth->setPalette(p);
    leYear->setPalette(p);
    leHour->setPalette(p);
    leMinute->setPalette(p);
    leSecond->setPalette(p);
    leClose->setPalette(p);
    leRestart->setPalette(p);
}


void SystemSettingWidget::leTime_click()
{

    leYear->setEnabled(false);
    leMonth->setEnabled(false);
    leDay->setEnabled(false);
    leHour->setEnabled(false);
    leMinute->setEnabled(false);
    leSecond->setEnabled(false);

    leCurrent = qobject_cast<QLineEdit *>(sender());

    leCurrent->setEnabled(true);
    leCurrent->setFocus();

    valCurrent = leCurrent->text().toInt();
    leCurrent->setText("");
    ui->groupBox->setVisible(true);
}

void SystemSettingWidget::gbpbNumber_click()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString text = button->text();

    leCurrent->setText(leCurrent->text() + text);
}

void SystemSettingWidget::gbplCancel_click()
{
    leYear->setEnabled(true);
    leMonth->setEnabled(true);
    leDay->setEnabled(true);
    leHour->setEnabled(true);
    leMinute->setEnabled(true);
    leSecond->setEnabled(true);

    leCurrent->setText(QString("%1").arg(valCurrent));
    ui->groupBox->setVisible(false);
    leCurrent->setFocus();
}

void SystemSettingWidget::gbpbOK_click()
{

    int year = leYear->text().toInt();
    int month = leMonth->text().toInt();
    int day = leDay->text().toInt();



    if(leCurrent->text()=="" || year ==0 ||
               month ==0 || day ==0)
        leCurrent->setText(QString("%1").arg(valCurrent));
    else
    {

        if(month > 12)
            return;

        if(month == 12)
        {
            year += 1;
            month = 1;
        }
        else
            month += 1;
        QDate cDate(year,month,1);

        int maxDay = cDate.addDays(-1).day();

        if(day > maxDay)
            return;


        if(leHour->text().toInt() > 23)
            return;
        if(leMinute->text().toInt() > 59)
            return;
        if(leSecond->text().toInt() > 59)
            return;
    }

    leYear->setEnabled(true);
    leMonth->setEnabled(true);
    leDay->setEnabled(true);
    leHour->setEnabled(true);
    leMinute->setEnabled(true);
    leSecond->setEnabled(true);

    ui->groupBox->setVisible(false);
    leCurrent->setFocus();

    leCurrent->setText(QString("%1").arg(leCurrent->text().toInt()));
}


void SystemSettingWidget::leCloseOrRestart_click()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    QString text = le->text();


    leClose->setStyleSheet("border-width:0; border-style:outset; background-color: rgb( 255, 0, 0);");
    leRestart->setStyleSheet("border-width:0; border-style:outset;background-color: rgb( 255,0, 0);");
    leClose->setText(str_no);//"否"
    leRestart->setText(str_no);//"否"

    if(text == "否" || text == "No")
    {
        le->setText(str_yes);
        le->setStyleSheet("border-width:0; border-style:outset; background-color: rgb( 0, 255, 0);");
    }
    else
    {
        le->setText(str_no);
    }
}

void SystemSettingWidget::pbOk_clicked()
{
    /*设置系统时间*/
    int year = leYear->text().toInt();
    int month = leMonth->text().toInt();
    int day = leDay->text().toInt();
    int hour = leHour->text().toInt();
    int minute = leMinute->text().toInt();
    int second = leSecond->text().toInt();

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
    if(leClose->text()==str_yes || leRestart->text() == str_yes)
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


        if(leClose->text()==str_yes)
        {
           // ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0);

            QCoreApplication::exit(1);
        }
        else if(leRestart->text() == str_yes)
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

    ui->label_1->setFont(FONT_3);
    ui->label_1->setText(str_year_XTSZ);//年

    ui->label_2->setFont(FONT_3);
    ui->label_2->setText(str_month_XTSZ);//月

    ui->label_3->setFont(FONT_3);
    ui->label_3->setText(str_day_XTSZ);//日

    ui->label_4->setFont(FONT_3);
    ui->label_4->setText(str_hour_XTSZ);//时

    ui->label_5->setFont(FONT_3);
    ui->label_5->setText(str_minute_XTSZ);//分

    ui->label_6->setFont(FONT_3);
    ui->label_6->setText(str_second_XTSZ);//秒

    ui->label_7->setFont(FONT_3);
    ui->label_7->setText(str_guanbixitong_XTSZ);//关闭系统

    ui->label_8->setFont(FONT_3);
    ui->label_8->setText(str_guanbizhongduan_XTSZ);//关闭此操作终端

    ui->label_9->setFont(FONT_3);
    ui->label_9->setText(str_chongqizhongduan_XTSZ);//重启此操作终端

    ui->pbOK->setFont(FONT_3);
    ui->pbOK->setText(str_queding);//确定

    ui->pbCancel->setFont(FONT_3);
    ui->pbCancel->setText(str_quxiao);//取消

    leClose->setFont(FONT_3);
    leRestart->setFont(FONT_3);
    if(leClose->text() == "Yes" || leClose->text() == "是")
        leClose->setText(str_yes);
    else
        leClose->setText(str_no);

    if(leRestart->text() == "Yes" || leRestart->text() == "是")
        leRestart->setText(str_yes);
    else
        leRestart->setText(str_no);


    ui->gbpbCancel->setFont(FONT_1);
    ui->gbpbCancel->setText(str_quxiao);

    ui->gbpbOK->setFont(FONT_1);
    ui->gbpbOK->setText(str_queding);

    ui->pbOk->setFont(FONT_3);
    ui->pbCancel->setFont(FONT_3);
    ui->pbOk->setText(str_queding);
    ui->pbCancel->setText(str_quxiao);

}
void SystemSettingWidget::pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}


SystemSettingWidget::~SystemSettingWidget()
{
    delete ui;
}
