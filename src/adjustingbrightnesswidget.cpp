﻿/*
    屏幕亮度调节
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "adjustingbrightnesswidget.h"
#include "ui_adjustingbrightnesswidget.h"

AdjustingBrightnessWidget::AdjustingBrightnessWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::AdjustingBrightnessWidget)
{

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());
    ui->setupUi(this);

    m_window = nullptr;
    m_widget = nullptr;

    m_dimProg = new QProcess(this);
    m_dimProg->start("PPCBacklightAdjustmentTool");

    this->setAutoFillBackground(true);
    QPalette p;
    p.setBrush(QPalette::Window,QBrush(QPixmap(PicBlank)));//空背景
    this->setPalette(p);
}

//白天、夜晚模式切换
void AdjustingBrightnessWidget::changeDNMode()
{
//    QPalette p;
//    if(daynight_mode == DAYMODE)
//    {
//        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_1)));//"images/调光-日.png"
//        ui->label->setStyleSheet(StyleSheet_DayColor);
//    }
//    else
//    {
//        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_1)));//"images/调光-夜.png"
//        ui->label->setStyleSheet(StyleSheet_NgtColor);
//    }
//    this->setPalette(p);
}

void AdjustingBrightnessWidget::Refresh_changless_words()
{
//    ui->label->setFont(FONT_3);
//    ui->label->setText(str_liangdushezhi);

//    ui->pbOk->setFont(FONT_3);
//    ui->pbOk->setText(str_queding);

//    ui->pbCancel->setFont(FONT_3);
//    ui->pbCancel->setText(str_quxiao);
}

//void AdjustingBrightnessWidget::pbAdd_clicked()
//{
//    tempRight += maxBright / 50;

//    if(tempRight > maxBright) tempRight = maxBright;

//    int nowLen = (lblw * tempRight) / maxBright;

//    ui->lblBright->setGeometry(lblx ,lbly,nowLen,lblh);

//    SetGamma(maxBright - tempRight);
//}

//void AdjustingBrightnessWidget::pbReduce_clicked()
//{
//    tempRight -= maxBright / 50;

//    if(tempRight <0 ) tempRight =0;

//    int nowLen = (lblw * tempRight) / maxBright;

//    ui->lblBright->setGeometry(lblx ,lbly,nowLen,lblh);

//    SetGamma(maxBright - tempRight);
//}
//void AdjustingBrightnessWidget::pbAdd_clicked()
//{
//    tempRight -= maxBright / 50;
//    if(tempRight <0 ) tempRight =0;

//    int nowLen = (lblw * tempRight) / maxBright;

//    ui->lblBright->setGeometry(lblx-nowLen ,lbly,nowLen,lblh);

//    SetGamma(maxBright - tempRight);
//}

//void AdjustingBrightnessWidget::pbReduce_clicked()
//{
//    tempRight += maxBright / 50;
//    if(tempRight > maxBright) tempRight = maxBright;

//    int nowLen = (lblw * tempRight) / maxBright;

//    ui->lblBright->setGeometry(lblx-nowLen ,lbly,nowLen,lblh);

//    SetGamma(maxBright - tempRight);
//}

//void AdjustingBrightnessWidget::pbOk_clicked()
//{
//    nowBright = maxBright-tempRight;
//    lastBright = nowBright;
//    emit ok_signal(this->objectName());
//}

//void AdjustingBrightnessWidget::pbCancel_clicked()
//{
//    int tempwidth = 0;
//    tempRight = nowBright;
//    tempwidth = nowBright * lblw/ maxBright;
//    //ui->lblBright->setGeometry(lblx ,lbly, nowBright * lblw/ maxBright ,lblh);
//    ui->lblBright->setGeometry(lblx-tempwidth ,lbly, tempwidth ,lblh);
//    SetGamma(lastBright);

//    emit cancel_signal(this->objectName());
//}

//int AdjustingBrightnessWidget::GetGamma()
//{
////    void * lpGamma = NULL;

//    HDC hdc = ::GetDC(NULL);

//    if (NULL == hdc)
//        return maxBright/2;

//    WORD gMap[3][256] = {0};

//    GetDeviceGammaRamp(hdc,gMap);

////    if(gMap ==) return maxBright/2;

////    WORD *gMap = (WORD*)lpGamma;

////    if(gMap==NULL || gMap[256] ==NULL) return maxBright/2;

//    int gamma = (int)gMap[0][1];

//    int bright = gamma - 128;

//    if(bright <  0)
//    {
//        return 0;
//    }
//    if(bright > maxBright)
//        return maxBright;


//    return bright;
//}

//int AdjustingBrightnessWidget::SetGamma(int bright)
//{

//    void * lpGamma = NULL;

//    int iArrayValue;

//    WORD gMap[3][256] = {0};

//    lpGamma = &gMap;

//    HDC hdc = ::GetDC(NULL);

//    if (NULL == hdc)
//        return -1;

//    for (int i = 0; i < 256; i++)

//    {

//    iArrayValue = i * (bright + 128);

//    if (iArrayValue > 65535)
//        iArrayValue = 65535;
//        gMap[0][i] =
//        gMap[1][i] =
//        gMap[2][i] = (WORD)iArrayValue;
//    }
////    if (FALSE == SetDeviceGammaRamp(hdc, lpGamma))
////    return -2;
//    SetDeviceGammaRamp(hdc,lpGamma);
//    return 0;
//}



AdjustingBrightnessWidget::~AdjustingBrightnessWidget()
{
    delete ui;
    m_dimProg->deleteLater();
    if(m_window != nullptr){
        m_window->deleteLater();
    }
    if(m_widget != nullptr){
        m_widget->deleteLater();
    }
}


void AdjustingBrightnessWidget::attachWindow(void){

    if(m_widget == nullptr){
        QString className=("WindowsForms10.Window.8.app.0.378734a");
        LPCWSTR className_w = reinterpret_cast<LPCWSTR>(className.data());
        QString appName("Advantech Panel PC backlight auto adjustment tool v1.1");
        LPCWSTR appName_w = reinterpret_cast<LPCWSTR>(appName.data());
        HWND dimWind = FindWindowW(className_w,0);

        if(dimWind){
            m_window = QWindow::fromWinId( (WId)dimWind );
            m_widget = QWidget::createWindowContainer( m_window, this );
            m_widget->stackUnder (this);
            m_widget->setGeometry( 60, 60, m_window->width(), m_window->height()-160 );
        }
        else{
            qDebug()<<dimWind<<"not Found!";
        }
    }
    else{
    }
    m_widget->setVisible ( true );
}


//因为调光窗口太宽，且位于所有窗口之上，因此当keyWidget展开后，会阻挡部分keyWidget
//当keyWidget展开，调用此函数，用于隐藏调光窗口，
//当keyWidget收起，调用此函数，用于显示调光窗口

void AdjustingBrightnessWidget::hideWindow( bool visible ){
    if(m_widget != nullptr){
        m_widget->setVisible( visible );
    }
}
