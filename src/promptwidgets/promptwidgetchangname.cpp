#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "promptwidgetchangname.h"

PromptWidgetChangeName::PromptWidgetChangeName(QWidget *parent,QRect viewRect)
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

void PromptWidgetChangeName::setTargetUsrName(const QString &usrName){
    _targetUsrName = usrName;
}

void PromptWidgetChangeName::initWidget(){

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

    int h_obj = 2* h_unit;

    _lblOldName = new QLabel(this);
    _lblOldName->setAlignment(Qt::AlignRight);
    _lblOldName->setFont(FONT_3);
    _lblOldName->setGeometry( col1 , line1 , 3 * w_unit , h_unit);

    _leOldName = new QLineEdit(this);
    _leOldName->setAlignment(Qt::AlignLeft);
    _leOldName->setFont(FONT_3);
    _leOldName->setGeometry( col5, line1 , 4 * w_unit , h_unit);
    _leOldName->setText(_targetUsrName);
    _leOldName->setEnabled(false);

    _lblNewName = new QLabel(this);
    _lblNewName->setAlignment(Qt::AlignRight);
    _lblNewName->setFont(FONT_3);
    _lblNewName->setGeometry( col1 , line2 , 3 * w_unit , h_unit);

    _leNewName = new QLineEdit(this);
    _leNewName->setAlignment(Qt::AlignLeft);
    _leNewName->setFont(FONT_3);
    _leNewName->setGeometry( col5, line2 , 4 * w_unit , h_unit);

    _lblPswd = new QLabel(this);
    _lblPswd->setAlignment(Qt::AlignRight);
    _lblPswd->setFont(FONT_3);
    _lblPswd->setGeometry( col1 , line3 , 3 * w_unit , h_unit);

    _lePswd = new QLineEdit(this);
    _lePswd->setAlignment(Qt::AlignLeft);
    _lePswd->setFont(FONT_3);
    _lePswd->setGeometry( col5 , line3 , 4 * w_unit , h_unit);
    _lePswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

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

void PromptWidgetChangeName::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_23)));
        this->setPalette(p);
        _lblNewName->setStyleSheet(StyleSheet_DayColor);
        _leNewName->setStyleSheet(StyleSheet_DayColor);
        _lblOldName->setStyleSheet(StyleSheet_DayColor);
        _leOldName->setStyleSheet(StyleSheet_DayColor);
        _lblPswd->setStyleSheet(StyleSheet_DayColor);
        _lePswd->setStyleSheet(StyleSheet_DayColor);

    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_23)));
        this->setPalette(p);
        _lblNewName->setStyleSheet(StyleSheet_NgtColor);
        _leNewName->setStyleSheet(StyleSheet_NgtColor);
        _lblOldName->setStyleSheet(StyleSheet_NgtColor);
        _leOldName->setStyleSheet(StyleSheet_NgtColor);
        _lblPswd->setStyleSheet(StyleSheet_NgtColor);
        _lePswd->setStyleSheet(StyleSheet_NgtColor);
    }
}

void PromptWidgetChangeName::Refresh_changless_words()
{
    _lblOldName->setText(str_jiuyonghuming);
    _lblNewName->setText(str_xinyonghuming);
    _lblPswd->setText(str_mima);
    _pbOK->setText(str_queding);
    _pbCancel->setText(str_quxiao);
}

void PromptWidgetChangeName::clickOk(){
    bool ok;
    UsrInfo* targetUsr;
    targetUsr = _manager->getUsr( _targetUsrName );
    if( targetUsr !=0 ){
        ok = targetUsr->setName(_leNewName->text(), _lePswd->text() );
        if(ok){
            _leNewName->clear();
            _lePswd->clear();
            emit promptFinished();
            this->setVisible(false);
        }
        else{
            //登录失败
            _lePswd->clear();
            QMessageBox msgBox;
            this->setVisible(false);
            msgBox.setText(str_denglushibai);
            msgBox.exec();
            this->setVisible(true);
        }
    }
}

void PromptWidgetChangeName::clickCancel(){
    _leNewName->clear();
    _leOldName->clear();
    _lePswd->clear();
    emit promptFinished();
    this->setVisible(false);
}

void PromptWidgetChangeName::paintEvent(QPaintEvent *){

}

void PromptWidgetChangeName::showEvent(QShowEvent *){
    if(_targetUsrName == "")
        this->setVisible(false);

    _leOldName->setText( _targetUsrName );
}
