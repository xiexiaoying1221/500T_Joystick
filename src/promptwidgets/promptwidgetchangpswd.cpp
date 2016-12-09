#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "promptwidgetchangpswd.h"

PromptWidgetChangePswd::PromptWidgetChangePswd(QWidget *parent,QRect viewRect)
    :QWidget(parent, Qt::FramelessWindowHint)//Popup
{

    this->setAutoFillBackground(true);
    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());
    _manager = UsrManager::Instance();
    _targetUsrName = "";
    initWidget();
    changeDNMode();
    Refresh_changless_words();
}

void PromptWidgetChangePswd::setTargetUsrName(const QString &usrName){
    _targetUsrName = usrName;
}

void PromptWidgetChangePswd::initWidget(){

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
    _lblName->setAlignment(Qt::AlignRight);
    _lblName->setFont(FONT_3);
    _lblName->setGeometry( col1 , line1 , 3 * w_unit , h_unit);

    _leName = new QLineEdit(this);
    _leName->setAlignment(Qt::AlignLeft);
    _leName->setFont(FONT_3);
    _leName->setGeometry( col5, line1 , 4 * w_unit , h_unit);
    _leName->setText(_targetUsrName);
    _leName->setEnabled(false);

    _lblOldPswd = new QLabel(this);
    _lblOldPswd->setAlignment(Qt::AlignRight);
    _lblOldPswd->setFont(FONT_3);
    _lblOldPswd->setGeometry( col1 , line2 , 3 * w_unit , h_unit);

    _leOldPswd = new QLineEdit(this);
    _leOldPswd->setAlignment(Qt::AlignLeft);
    _leOldPswd->setFont(FONT_3);
    _leOldPswd->setGeometry( col5 , line2 , 4 * w_unit , h_unit);
    _leOldPswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    _lblNewPswd = new QLabel(this);
    _lblNewPswd->setAlignment(Qt::AlignRight);
    _lblNewPswd->setFont(FONT_3);
    _lblNewPswd->setGeometry( col1 , line3 , 3 * w_unit , h_unit);

    _leNewPswd = new QLineEdit(this);
    _leNewPswd->setAlignment(Qt::AlignLeft);
    _leNewPswd->setFont(FONT_3);
    _leNewPswd->setGeometry( col5 , line3 , 4 * w_unit , h_unit);
    _leNewPswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    _lblNewRepeatPswd = new QLabel(this);
    _lblNewRepeatPswd->setAlignment(Qt::AlignRight);
    _lblNewRepeatPswd->setFont(FONT_3);
    _lblNewRepeatPswd->setGeometry( col1 , line4 , 3 * w_unit , h_unit);

    _leNewRepeatPswd = new QLineEdit(this);
    _leNewRepeatPswd->setAlignment(Qt::AlignLeft);
    _leNewRepeatPswd->setFont(FONT_3);
    _leNewRepeatPswd->setGeometry( col5 , line4 , 4 * w_unit , h_unit);
    _leNewRepeatPswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    _pbOK = new QPushButton(this);
    _pbOK->setFocusPolicy(Qt::NoFocus);
    _pbOK->setGeometry( col2 , line5 , 2 * w_unit , h_unit);
    _pbOK->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    _pbOK->setFont(FONT_3);
    connect(_pbOK,SIGNAL(clicked()),this,SLOT(clickOk()));

    _pbCancel = new QPushButton(this);
    _pbCancel->setFocusPolicy(Qt::NoFocus);
    _pbCancel->setGeometry( col6 , line5 , 2 * w_unit , h_unit);
    _pbCancel->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    _pbCancel->setFont(FONT_3);
    connect(_pbCancel,SIGNAL(clicked()),this,SLOT(clickCancel()));
}

void PromptWidgetChangePswd::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_23)));
        this->setPalette(p);
        _lblName->setStyleSheet(StyleSheet_DayColor);
        _leName->setStyleSheet(StyleSheet_DayColor);
        _lblOldPswd->setStyleSheet(StyleSheet_DayColor);
        _leOldPswd->setStyleSheet(StyleSheet_DayColor);
        _lblNewRepeatPswd->setStyleSheet(StyleSheet_DayColor);
        _leNewRepeatPswd->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_23)));
        this->setPalette(p);
        _lblName->setStyleSheet(StyleSheet_NgtColor);
        _leName->setStyleSheet(StyleSheet_NgtColor);
        _lblOldPswd->setStyleSheet(StyleSheet_NgtColor);
        _leOldPswd->setStyleSheet(StyleSheet_NgtColor);
        _lblNewRepeatPswd->setStyleSheet(StyleSheet_NgtColor);
        _leNewRepeatPswd->setStyleSheet(StyleSheet_NgtColor);
    }
}

void PromptWidgetChangePswd::Refresh_changless_words()
{
    _lblName->setText(str_yonghuming);
    _lblNewPswd->setText(str_xinmima);
    _lblOldPswd->setText(str_jiumima);
    _lblNewRepeatPswd->setText(str_mimachongfu);
    _pbOK->setText(str_queding);
    _pbCancel->setText(str_quxiao);
}

void PromptWidgetChangePswd::clickOk(){
    bool ok;
    UsrInfo* targetUsr;
    QMessageBox msgBox;
    if(_lblNewPswd->text() != _lblNewRepeatPswd->text() ){
        _lblNewPswd->clear();
        _lblNewRepeatPswd->clear();
        msgBox.setText(str_mimacuowu);
        msgBox.exec();
        return;
    }
    targetUsr = _manager->getUsr( _targetUsrName );
    if( targetUsr !=0 ){
        ok = targetUsr->setPassWord(_lblOldPswd->text(), _lblNewPswd->text());
        if(ok){
            _lblOldPswd->clear();
            _lblNewPswd->clear();
            _lblNewRepeatPswd->clear();
            _targetUsrName = "";
            emit promptFinished();
            this->setVisible(false);
        }
        else{
            //登录失败
            _lblOldPswd->clear();
            _lblNewPswd->clear();
            _lblNewRepeatPswd->clear();
            QMessageBox msgBox;
            msgBox.setText(str_denglushibai);
            msgBox.exec();
        }
    }
}

void PromptWidgetChangePswd::clickCancel(){
    _lblOldPswd->clear();
    _lblNewPswd->clear();
    _lblNewRepeatPswd->clear();
    _targetUsrName = "";
    emit promptFinished();
    this->setVisible(false);
}

void PromptWidgetChangePswd::paintEvent(QPaintEvent *){

}

void PromptWidgetChangePswd::showEvent(QShowEvent *){
    if(_targetUsrName == "")
        this->setVisible(false);

    _leName->setText( _targetUsrName );
}
