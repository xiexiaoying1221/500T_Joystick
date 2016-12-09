#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "promptwidget.h"

PromptWidget::PromptWidget(QWidget *parent,QWidget *singalReceiver,QRect viewRect)
    :QWidget(parent, Qt::FramelessWindowHint)//Popup
{

//    QPalette p;
//    p.setBrush(this->backgroundRole(),QBrush(QPixmap(PicNameD_13)));//"images/dialog.png"
//    this->setPalette(p);
    this->setAutoFillBackground(true);

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());

    int w = this->geometry().width();
    int h = this->geometry().height();

    QFont font("微软雅黑",15);

    statePtr= &Operate_mode;//默认的prompWidget是用于修改操作模式的

    lblPrompt = new QLabel(this);
    lblPrompt->setAlignment(Qt::AlignCenter);
    lblPrompt->setFont(font);
    lblPrompt->setGeometry(10,h/3,w-20,60);

    //QPushButton *pbOK = new QPushButton(this);
    pbOK = new QPushButton(this);
    pbOK->setFocusPolicy(Qt::NoFocus);
    pbOK->setGeometry(w/2 - 70, h - 60,70,40);
    pbOK->setStyleSheet("background-color: transparent;");
    pbOK->setText(str_queding);
    pbOK->setFont(FONT_7);

    pbCancel = new QPushButton(this);
    pbCancel->setFocusPolicy(Qt::NoFocus);
    pbCancel->setGeometry(w/2 , h - 60,70,40);
    pbCancel->setStyleSheet("background-color: transparent;");
    pbCancel->setText(str_quxiao);
    pbCancel->setFont(FONT_7);

    changeDNMode();
    connect(pbOK,SIGNAL(clicked()),this,SLOT(clickOk()));
    connect(pbCancel,SIGNAL(clicked()),this,SLOT(clickCancel()));
    connect(this, SIGNAL(changemode(bool)),singalReceiver,SLOT(changeMode(bool)));
}

void PromptWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_13)));//":/images/对话框-日.png"
        this->setPalette(p);
        lblPrompt->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_13)));//":/images/对话框-夜.png"
        this->setPalette(p);
        lblPrompt->setStyleSheet(StyleSheet_NgtColor);
    }
}

void PromptWidget::paintEvent(QPaintEvent *){

}

void PromptWidget::showEvent(QShowEvent *)
{
    lblPrompt->setText(message);
}

void PromptWidget::Refresh_changless_words()
{
    pbOK->setText(str_queding);
    pbCancel->setText(str_quxiao);
}

void PromptWidget::clickOk(){
    bool ok;
    if(targetState != -1)
    {
        *statePtr = targetState;
        ok = true;
    }
    else
       ok = false;

    emit changemode(ok);
    this->setVisible(false);
}

void PromptWidget::clickCancel(){
    emit changemode(false);
    this->setVisible(false);
}
