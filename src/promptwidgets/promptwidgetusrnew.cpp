#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "promptwidgetusrnew.h"

PromptWidgetUsrNew::PromptWidgetUsrNew(QWidget *parent,QRect viewRect)
    :QWidget(parent, Qt::FramelessWindowHint)//Popup
{

    this->setAutoFillBackground(true);
    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());
    _manager = UsrManager::Instance();
    initWidget();
    changeDNMode();
    Refresh_changless_words();
}

void PromptWidgetUsrNew::initWidget(){

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

    _lblName = new QLabel(this);
    _lblName->setAlignment(Qt::AlignRight);
    _lblName->setFont(FONT_3);
    _lblName->setGeometry( col1 , line1 , 3 * w_unit , h_unit);

    _leName = new QLineEdit(this);
    _leName->setAlignment(Qt::AlignLeft);
    _leName->setFont(FONT_3);
    _leName->setGeometry( col5, line1 , 4 * w_unit , h_unit);

    _lblPswd = new QLabel(this);
    _lblPswd->setAlignment(Qt::AlignRight);
    _lblPswd->setFont(FONT_3);
    _lblPswd->setGeometry( col1 , line2 , 3 * w_unit , h_unit);

    _lePswd = new QLineEdit(this);
    _lePswd->setAlignment(Qt::AlignLeft);
    _lePswd->setFont(FONT_3);
    _lePswd->setGeometry( col5 , line2 , 4 * w_unit , h_unit);
    _lePswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    _lblRepeatPswd = new QLabel(this);
    _lblRepeatPswd->setAlignment(Qt::AlignRight);
    _lblRepeatPswd->setFont(FONT_3);
    _lblRepeatPswd->setGeometry( col1 , line3 , 3 * w_unit , h_unit);

    _leRepeatPswd = new QLineEdit(this);
    _leRepeatPswd->setAlignment(Qt::AlignLeft);
    _leRepeatPswd->setFont(FONT_3);
    _leRepeatPswd->setGeometry( col5 , line3 , 4 * w_unit , h_unit);
    _leRepeatPswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    _lblLevel = new QLabel(this);
    _lblLevel->setAlignment(Qt::AlignRight);
    _lblLevel->setFont(FONT_3);
    _lblLevel->setGeometry( col1 , line4 , 3 * w_unit , h_unit);

    _cbxLevel = new QComboBox(this);
    _cbxLevel->setFont(FONT_3);
    _cbxLevel->setGeometry( col5 , line4 , 4 * w_unit , h_unit);

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

void PromptWidgetUsrNew::changeDNMode()
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
        _lblRepeatPswd->setStyleSheet(StyleSheet_DayColor);
        _leRepeatPswd->setStyleSheet(StyleSheet_DayColor);
        _lblLevel->setStyleSheet(StyleSheet_DayColor);
        _cbxLevel->setStyleSheet(StyleSheet_DayColor);

    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_23)));
        this->setPalette(p);
        _lblName->setStyleSheet(StyleSheet_NgtColor);
        _leName->setStyleSheet(StyleSheet_NgtColor);
        _lblPswd->setStyleSheet(StyleSheet_NgtColor);
        _lePswd->setStyleSheet(StyleSheet_NgtColor);
        _lblRepeatPswd->setStyleSheet(StyleSheet_NgtColor);
        _leRepeatPswd->setStyleSheet(StyleSheet_NgtColor);
        _lblLevel->setStyleSheet(StyleSheet_NgtColor);
        _cbxLevel->setStyleSheet(StyleSheet_NgtColor);
    }
}

void PromptWidgetUsrNew::Refresh_changless_words()
{
    _lblName->setText(str_yonghuming);
    _lblPswd->setText(str_mima);
    _lblRepeatPswd->setText(str_mimachongfu);
    _lblLevel->setText(str_yonghudengji);
    _pbOK->setText(str_queding);
    _pbCancel->setText(str_quxiao);
}

void PromptWidgetUsrNew::clickOk(){
    QMessageBox msgBox;
    if(_lePswd->text() != _leRepeatPswd->text() ){
        _lePswd->clear();
        _leRepeatPswd->clear();
        this->setVisible(false);
        msgBox.setText(str_mimacuowu);
        msgBox.exec();
        this->setVisible(false);
    }

    quint8 level = _cbxLevel->currentText().remove(0,6).toUShort();
    _manager->addUsr( _leName->text(),  _lePswd->text(), level);
    _leName->clear();
    _lePswd->clear();
    _leRepeatPswd->clear();
    _cbxLevel->clear();
    emit promptFinished();
    this->setVisible(false);
}

void PromptWidgetUsrNew::clickCancel(){
    _leName->clear();
    _lePswd->clear();
    _leRepeatPswd->clear();
    _cbxLevel->clear();
    emit promptFinished();
    this->setVisible(false);
}

void PromptWidgetUsrNew::paintEvent(QPaintEvent *){

}

void PromptWidgetUsrNew::showEvent(QShowEvent *){
    _leName->clear();
    _lePswd->clear();
    _leRepeatPswd->clear();
    _cbxLevel->clear();

    quint8 level;
    _manager->getNameAndLevel(0,&level);
    QStringList list;
    for(int i=0; i<=level; i++){
        list<<QString("level %1").arg(i);
    }
    _cbxLevel->addItems(list);

}
