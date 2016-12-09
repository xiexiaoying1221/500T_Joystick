/*
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
//基础几何
    this->setAutoFillBackground(true);
    QPalette p;
    p.setBrush(QPalette::Window,QBrush(QPixmap(PicBlank)));//空背景
    this->setPalette(p);

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());
    ui->setupUi(this);

    m_window = nullptr;
    m_widget = nullptr;

    m_dimProg = new QProcess(this);
    m_dimProg->start("PPCBacklightAdjustmentTool");

    ui->pbOk->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    ui->pbOk->setFont(FONT_7);

    ui->pbCancel->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    ui->pbCancel->setFont(FONT_7);

    connect(this,SIGNAL(ok_signal(QString)),    parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));
}

//白天、夜晚模式切换
void AdjustingBrightnessWidget::changeDNMode()
{

}

void AdjustingBrightnessWidget::Refresh_changless_words()
{
    ui->pbOk->setFont(FONT_3);
    ui->pbOk->setText(str_queding);

    ui->pbCancel->setFont(FONT_3);
    ui->pbCancel->setText(str_quxiao);
}

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

void AdjustingBrightnessWidget::on_pbOk_clicked()
{
    emit ok_signal(this->objectName());
}

void AdjustingBrightnessWidget::on_pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}
