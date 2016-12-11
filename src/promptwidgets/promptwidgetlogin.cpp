#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "promptwidgetlogin.h"

PromptWidgetLogIn::PromptWidgetLogIn(QWidget *parent,QRect viewRect)
    :QWidget(parent, Qt::FramelessWindowHint)//Popup
{

    this->setAutoFillBackground(true);
    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());
    _manager = UsrManager::Instance();
    initWidget();
    changeDNMode();
    Refresh_changless_words();
}

void PromptWidgetLogIn::initWidget(){

    QFont font("微软雅黑",20);

    int w = this->geometry().width();
    int h = this->geometry().height();

    int w_unit = (w-30)/8;
    int h_unit = (h-70)/16;

    int line1 = 50+ h_unit;
    int line2 = line1 + 3*h_unit;
    int line3 = line2 + 3*h_unit;
    int line4 = line3 + 3*h_unit;
    int line5 = line4 + 3*h_unit;

    int col1 = 15;
    int col2 = col1 + w_unit;
    int col3 = col2 + w_unit;
    int col4 = col3 + w_unit;
    int col5 = col4 + w_unit;
    int col6 = col5 + w_unit;
    int col7 = col6 + w_unit;
    int col8 = col7 + w_unit;

    _lblName = new QLabel(this);
    _lblName->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    _lblName->setFont(FONT_3);
    _lblName->setGeometry( col1 , line1 , 2 * w_unit , h_unit);

    _leName = new QLineEdit(this);
    _leName->setAlignment(Qt::AlignLeft);
    _leName->setFont(FONT_3);
    _leName->setGeometry( col4, line1 , 4 * w_unit , h_unit);

    _lblPswd = new QLabel(this);
    _lblPswd->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    _lblPswd->setFont(FONT_3);
    _lblPswd->setGeometry( col1 , line2 , 2 * w_unit , h_unit);

    _lePswd = new QLineEdit(this);
    _lePswd->setAlignment(Qt::AlignLeft);
    _lePswd->setFont(FONT_3);
    _lePswd->setGeometry( col4 , line2 , 4 * w_unit , h_unit);
    _lePswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    _pbOK = new QPushButton(this);
    _pbOK->setFocusPolicy(Qt::NoFocus);
    _pbOK->setGeometry( col3 , line5 , 3* w_unit /2, h_unit);
    _pbOK->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    _pbOK->setFont(FONT_3);
    connect(_pbOK,SIGNAL(clicked()),this,SLOT(clickOk()));

    _pbCancel = new QPushButton(this);
    _pbCancel->setFocusPolicy(Qt::NoFocus);
    _pbCancel->setGeometry( col5 , line5 , 3* w_unit /2, h_unit);
    _pbCancel->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    _pbCancel->setFont(FONT_3);
    connect(_pbCancel,SIGNAL(clicked()),this,SLOT(clickCancel()));
}

void PromptWidgetLogIn::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_23)));
        this->setPalette(p);
        _lblName->setStyleSheet(StyleSheet_DayColor);
        _leName->setStyleSheet(StyleSheet_DayColor);
        _lblPswd->setStyleSheet(StyleSheet_DayColor);
        _lePswd->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_23)));
        this->setPalette(p);
        _lblName->setStyleSheet(StyleSheet_NgtColor);
        _leName->setStyleSheet(StyleSheet_NgtColor);
        _lblPswd->setStyleSheet(StyleSheet_NgtColor);
        _lePswd->setStyleSheet(StyleSheet_NgtColor);
    }
}

void PromptWidgetLogIn::Refresh_changless_words()
{
    _lblName->setText(str_yonghuming);
    _lblPswd->setText(str_mima);
    _pbOK->setText(str_queding);
    _pbCancel->setText(str_quxiao);
}

void PromptWidgetLogIn::clickOk(){
    bool ok;
    ok = _manager->logIn( _leName->text(), _lePswd->text() );
    if(ok){
        _leName->clear();
        _lePswd->clear();
        emit promptFinished();
        this->setVisible(false);
    }
    else{
        _lePswd->clear();
        QMessageBox msgBox;
        msgBox.setText(str_denglushibai);
        this->setVisible(false);
        msgBox.exec();
        this->setVisible(true);
    }
}

void PromptWidgetLogIn::clickCancel(){
    _leName->clear();
    _lePswd->clear();
    emit promptFinished();
    this->setVisible(false);
}

void PromptWidgetLogIn::paintEvent(QPaintEvent *){

}

void PromptWidgetLogIn::showEvent(QShowEvent *){
    _leName->clear();
    _lePswd->clear();
}
