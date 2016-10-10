/*
    系统信息视图
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "systeminfowidget.h"
#include "ui_systeminfowidget.h"

SystemInfoWidget::SystemInfoWidget(QWidget *parent,QRect rect) :
    QWidget(parent),
    ui(new Ui::SystemInfoWidget)
{
    ui->setupUi(this);
    this->setGeometry(rect.x(),  rect.y()+30, rect.width()-5,rect.height());

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/systeminfo_day.png")));
//    this->setPalette(p);
    changeDNMode();

    ui->label_1->setStyleSheet(StyleSheet_DayColor);
    ui->label_2->setStyleSheet(StyleSheet_DayColor);
    ui->label_3->setStyleSheet(StyleSheet_DayColor);
    ui->label_4->setStyleSheet(StyleSheet_DayColor);
    ui->label_5->setStyleSheet(StyleSheet_DayColor);
    ui->label_6->setStyleSheet(StyleSheet_DayColor);
    ui->label_7->setStyleSheet(StyleSheet_DayColor);

}

//白天、夜晚模式切换
void SystemInfoWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicBlank)));
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_5->setStyleSheet(StyleSheet_DayColor);
        ui->label_6->setStyleSheet(StyleSheet_DayColor);
        ui->label_7->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicBlank)));//根本就没有这幅图
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_5->setStyleSheet(StyleSheet_NgtColor);
        ui->label_6->setStyleSheet(StyleSheet_NgtColor);
        ui->label_7->setStyleSheet(StyleSheet_NgtColor);

    }
    this->setPalette(p);
}

void SystemInfoWidget::Refresh_changless_words()
{

    ui->label_1->setFont(FONT_3);
    ui->label_1->setText(str_ip);


    ui->label_2->setFont(FONT_3);
    ui->label_2->setText(str_otsw);

    ui->label_3->setFont(FONT_3);
    ui->label_3->setText(str_ctlsw);

    ui->label_4->setFont(FONT_3);
    ui->label_4->setText(str_config);

    ui->label_5->setFont(FONT_3);
    ui->label_5->setText(str_sdk);

    ui->label_6->setFont(FONT_3);
    ui->label_6->setText(str_ide);

    ui->label_7->setFont(FONT_3);
    ui->label_7->setText(str_windows);


}

SystemInfoWidget::~SystemInfoWidget()
{
    delete ui;
}
