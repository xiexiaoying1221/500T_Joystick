#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QStyleOption>
#include <QDebug>
#include "sticksettingwidget.h"

StickSettingWidget::StickSettingWidget(QWidget *parent,QRect viewRect)
    :QWidget(parent, Qt::FramelessWindowHint)//Popup
{
    _comm = SerialComm::getSerial();

    this->setAutoFillBackground(true);
    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());

    int w = this->geometry().width();
    int h = this->geometry().height();

    QFont font("微软雅黑",15);

    _lblDirection = new QLabel(this);
    _lblDirection->setAlignment(Qt::AlignCenter);
    _lblDirection->setFont(font);
    _lblDirection->setGeometry(10,60,w-20,60);

    _lblState = new QLabel(this);
    _lblState->setAlignment(Qt::AlignCenter);
    _lblState->setFont(font);
    _lblState->setGeometry(10,h-160,w-20,30);

    _pbSet = new QPushButton(this);
    _pbSet->setFocusPolicy(Qt::NoFocus);
    _pbSet->setGeometry(w/2-24, h-120 ,48,26);
    _pbSet->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    _pbSet->setText(str_shezhi);
    _pbSet->setFont(FONT_7);

    _pbNext = new QPushButton(this);
    _pbNext->setFocusPolicy(Qt::NoFocus);
    _pbNext->setGeometry(w/2+35, h-60 ,48,26);
    _pbNext->setStyleSheet("background-color: transparent;"
                        "border-image: url(:/images/按钮-日.png);");
    _pbNext->setText(str_xiayixiang);
    _pbNext->setFont(FONT_7);

    _pbPrevious = new QPushButton(this);
    _pbPrevious->setFocusPolicy(Qt::NoFocus);
    _pbPrevious->setGeometry(w/2-83, h-60 ,48,26);
    _pbPrevious->setStyleSheet("background-color: transparent;"
                               "border-image: url(:/images/按钮-日.png);");
    _pbPrevious->setText(str_shangyixiang);
    _pbPrevious->setFont(FONT_7);

    _pbCancel = new QPushButton(this);
    _pbCancel->setFocusPolicy(Qt::NoFocus);
    _pbCancel->setGeometry(w/2-24, h-60 ,48,26);
    _pbCancel->setStyleSheet("background-color: transparent;"
                             "border-image: url(:/images/按钮-日.png);");
    _pbCancel->setText(str_quxiao);
    _pbCancel->setFont(FONT_7);

    changeDNMode();
    connect(_pbSet,SIGNAL(clicked()),this,SLOT(clickSet()));
    connect(_pbNext,SIGNAL(clicked()),this,SLOT(clickNext()));
    connect(_pbPrevious,SIGNAL(clicked()),this,SLOT(clickPrevious()));
    connect(_pbCancel,SIGNAL(clicked()),this,SLOT(clickCancel()));
}

void StickSettingWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        _lblDirection->setStyleSheet(StyleSheet_DayColor);
        _lblState->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        _lblDirection->setStyleSheet(StyleSheet_NgtColor);
        _lblState->setStyleSheet(StyleSheet_NgtColor);
    }
}

void StickSettingWidget::paintEvent(QPaintEvent *){
    //
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void StickSettingWidget::showEvent(QShowEvent *)
{
    QPalette p;
    _state = 1;
    _lblDirection->setText(str_yidongdaoXzuida);
    _lblState->setText(QString::null);
    _pbNext->setText(str_xiayixiang);
    _pbNext->setEnabled(false);
    _pbPrevious->setText(str_shangyixiang);
    _pbPrevious->setEnabled(false);
    if(daynight_mode == DAYMODE){
        p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-前移到底-日.png")));
    }
    else{
        p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-前移到底-夜.png")));
    }
    this->setPalette(p);
}

void StickSettingWidget::Refresh_changless_words()
{
    _pbSet->setText(str_shezhi);
    _pbNext->setText(str_xiayixiang);
    _pbPrevious->setText(str_shangyixiang);
    _pbCancel->setText(str_quxiao);
}

void StickSettingWidget::clickSet(){
    //步骤，1-XMax，2-XMin，3-YMax，4—YMin，5-ZMax，6-ZMin，7-AllZero，8-finished！
    switch(_state){
    case 1:
        _stickXMax = _comm->rawX;
        _lblState->setText(str_yizancun);
        _pbNext->setEnabled(true);
        break;
    case 2:
        _stickXMin = _comm->rawX;
        _lblState->setText(str_yizancun);
        _pbNext->setEnabled(true);
        break;
    case 3:
        _stickYMax = _comm->rawY;
        _lblState->setText(str_yizancun);
        _pbNext->setEnabled(true);
        break;
    case 4:
        _stickYMin = _comm->rawY;
        _lblState->setText(str_yizancun);
        _pbNext->setEnabled(true);
        break;
    case 5:
        _stickZMax = _comm->rawZ;
        _lblState->setText(str_yizancun);
        _pbNext->setEnabled(true);
        break;
    case 6:
        _stickZMin = _comm->rawZ;
        _lblState->setText(str_yizancun);
        _pbNext->setEnabled(true);
        break;
    case 7:
        _stickXZero = _comm->rawX;
        _stickYZero = _comm->rawY;
        _stickZZero = _comm->rawZ;
        _lblState->setText(str_yizancun);
        _pbNext->setEnabled(true);
        break;
    default:
        break;
    }
}

void StickSettingWidget::clickNext(){
    //步骤，1-XMax，2-XMin，3-YMax，4—YMin，5-ZMax，6-ZMin，7-AllZero，8-finished！
    QPalette p;
    switch(_state){
    case 1:
        _state = 2;
        _lblDirection->setText(str_yidongdaoXzuixiao);
        _lblState->setText(QString::null);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(false);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-后移到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-后移到底-夜.png")));
        }
        break;
    case 2:
        _state = 3;
        _lblDirection->setText(str_yidongdaoYzuida);
        _lblState->setText(QString::null);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(false);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右移到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右移到底-夜.png")));
        }
        break;
    case 3:
        _state = 4;
        _lblDirection->setText(str_yidongdaoYzuixiao);
        _lblState->setText(QString::null);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(false);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左移到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左移到底-夜.png")));
        }
        break;
    case 4:
        _state = 5;
        _lblDirection->setText(str_yidongdaoZzuida);
        _lblState->setText(QString::null);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(false);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右旋到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右旋到底-夜.png")));
        }
        break;
    case 5:
        _state = 6;
        _lblDirection->setText(str_yidongdaoZzuixiao);
        _lblState->setText(QString::null);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(false);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左旋到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左旋到底-夜.png")));
        }
        break;
    case 6:
        _state = 7;
        _lblDirection->setText(str_yidongdaolingwei);
        _lblState->setText(QString::null);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(false);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-回中-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-回中-夜.png")));
        }
        break;
    case 7:
        _state = 8;
        _lblDirection->setText(QString::null);
        _lblState->setText(QString::null);
        _pbNext->setText(str_queding);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        _pbSet->setVisible(false);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-空-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-空-夜.png")));
        }
        break;
    case 8:
        setStickXMax = _stickXMax;
        setStickXZero = _stickXZero;
        setStickXMin = _stickXMin;
        setStickYMax = _stickYMax;
        setStickYZero = _stickYZero;
        setStickYMin = _stickYMin;
        setStickZMax = _stickZMax;
        setStickZZero = _stickZZero;
        setStickZMin = _stickZMin;
        emit settingFinished();
        this->setVisible(false);
    default:
        break;
    }
    this->setPalette(p);
}
void StickSettingWidget::clickPrevious(){
    //步骤，1-XMax，2-XMin，3-YMax，4—YMin，5-ZMax，6-ZMin，7-AllZero，8-finished！
    QPalette p;
    switch(_state){
    case 1:
        break;
    case 2:
        _state = 1;
        _lblDirection->setText(str_yidongdaoXzuida);
        _lblState->setText(str_yizancun);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(false);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-前移到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-前移到底-夜.png")));
        }
        break;
    case 3:
        _state = 2;
        _lblDirection->setText(str_yidongdaoXzuixiao);
        _lblState->setText(str_yizancun);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-后移到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-后移到底-夜.png")));
        }
        break;
    case 4:
        _state = 3;
        _lblDirection->setText(str_yidongdaoYzuida);
        _lblState->setText(str_yizancun);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右移到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右移到底-夜.png")));
        }
        break;
    case 5:
        _state = 4;
        _lblDirection->setText(str_yidongdaoYzuixiao);
        _lblState->setText(str_yizancun);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左移到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左移到底-夜.png")));
        }
        break;
    case 6:
        _state = 5;
        _lblDirection->setText(str_yidongdaoZzuida);
        _lblState->setText(str_yizancun);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右旋到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-右旋到底-夜.png")));
        }
        break;
    case 7:
        _state = 6;
        _lblDirection->setText(str_yidongdaoZzuixiao);
        _lblState->setText(str_yizancun);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左旋到底-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-左旋到底-夜.png")));
        }
        break;
    case 8:
        _state = 7;
        _lblDirection->setText(str_yidongdaolingwei);
        _lblState->setText(str_yizancun);
        _pbNext->setText(str_xiayixiang);
        _pbNext->setEnabled(true);
        _pbPrevious->setText(str_shangyixiang);
        _pbPrevious->setEnabled(true);
        _pbSet->setVisible(true);
        if(daynight_mode == DAYMODE){
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-回中-日.png")));
        }
        else{
            p.setBrush(QPalette::Window,QBrush(QPixmap(":/images/手柄对齐-回中-夜.png")));
        }
        break;
    default:
        break;
    }
    this->setPalette(p);
}

void StickSettingWidget::clickCancel(){
    emit settingFinished();
    this->setVisible(false);
}
