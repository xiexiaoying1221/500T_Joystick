#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "promptwidgetusrsetting.h"

PromptWidgetUsrSetting::PromptWidgetUsrSetting(QWidget *parent,QRect viewRect)
    :QWidget(parent, Qt::FramelessWindowHint)//Popup
{

    this->setAutoFillBackground(true);
    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());
    _manager = UsrManager::Instance();

    initWidget();
    changeDNMode();
    Refresh_changless_words();

}

void PromptWidgetUsrSetting::initWidget(){

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

    _cbAutoLogOut = new QCheckBox(this);
    _cbAutoLogOut->setFont(FONT_3);
    _cbAutoLogOut->setGeometry( col2 , line1 , 7 * w_unit , h_unit);

    _lblDelayMin = new QLabel(this);
    _lblDelayMin->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    _lblDelayMin->setFont(FONT_3);
    _lblDelayMin->setGeometry( col1 , line2 , 4 * w_unit , h_unit);

    _leDelayMin = new QLineEdit(this);
    _leDelayMin->setAlignment(Qt::AlignLeft);
    _leDelayMin->setFont(FONT_3);
    _leDelayMin->setGeometry( col5 , line2 , 3 * w_unit , h_unit);
    _leDelayMin->setValidator(new QIntValidator(0,120,this));

    _pbOK = new QPushButton(this);
    _pbOK->setFocusPolicy(Qt::NoFocus);
    _pbOK->setGeometry( col3 , line5 , 3* w_unit /2 , h_unit);
    _pbOK->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    _pbOK->setFont(FONT_3);
    connect(_pbOK,SIGNAL(clicked()),this,SLOT(clickOk()));

    _pbCancel = new QPushButton(this);
    _pbCancel->setFocusPolicy(Qt::NoFocus);
    _pbCancel->setGeometry( col5 , line5 , 3* w_unit /2 , h_unit);
    _pbCancel->setStyleSheet("background-color: transparent;"
                          "border-image: url(:/images/按钮-日.png);");
    _pbCancel->setFont(FONT_3);
    connect(_pbCancel,SIGNAL(clicked()),this,SLOT(clickCancel()));
}

void PromptWidgetUsrSetting::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_23)));
        this->setPalette(p);
        _cbAutoLogOut->setStyleSheet(StyleSheet_DayColor);
        _lblDelayMin->setStyleSheet(StyleSheet_DayColor);
        _leDelayMin->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_23)));
        this->setPalette(p);
        _cbAutoLogOut->setStyleSheet(StyleSheet_NgtColor);
        _lblDelayMin->setStyleSheet(StyleSheet_NgtColor);
        _leDelayMin->setStyleSheet(StyleSheet_NgtColor);
    }
}

void PromptWidgetUsrSetting::Refresh_changless_words()
{
    _cbAutoLogOut->setText(str_zidongdengchu);
    _lblDelayMin->setText(str_yanshifenzhong);
    _pbOK->setText(str_queding);
    _pbCancel->setText(str_quxiao);
}

void PromptWidgetUsrSetting::clickOk(){
    _manager->setAutoLogOut( _cbAutoLogOut->isChecked() , _leDelayMin->text().toInt() );
    emit promptFinished();
    this->setVisible(false);
}

void PromptWidgetUsrSetting::clickCancel(){
    emit promptFinished();
    this->setVisible(false);
}

void PromptWidgetUsrSetting::paintEvent(QPaintEvent *){

}

void PromptWidgetUsrSetting::showEvent(QShowEvent *){
    bool en;
    int delay;
    _manager->getAutoLogOut(&en, &delay);

    _cbAutoLogOut->setChecked(en);
    _leDelayMin->setText(QString::number(delay));

}
