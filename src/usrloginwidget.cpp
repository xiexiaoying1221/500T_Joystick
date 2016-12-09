#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "usrloginwidget.h"
#include "ui_usrloginwidget.h"

UsrLogInWidget::UsrLogInWidget(QWidget *parent, QRect rect) : QWidget(parent),
    ui(new Ui::UsrLogInWidget){
//基础几何
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setGeometry(rect.x(),  rect.y() + 20, rect.width()-2,rect.height());

//登录弹出界面
    int dialogWidth =  450;
    int dialogHeight = 639;
    _promptWidgetLogIn = new PromptWidgetLogIn(0,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));
    _promptWidgetLogIn->raise();//上层显示
    _promptWidgetLogIn->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    _promptWidgetLogIn->setVisible(false);
    connect(_promptWidgetLogIn,SIGNAL(promptFinished()),this,SLOT(promptFinished()));

//设置弹出界面
    _promptWidgetUsrSetting = new PromptWidgetUsrSetting(0,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));
    _promptWidgetUsrSetting->raise();//上层显示
    _promptWidgetUsrSetting->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    _promptWidgetUsrSetting->setVisible(false);
    connect(_promptWidgetUsrSetting,SIGNAL(promptFinished()),this,SLOT(promptFinished()));

//处理UsrManager
    _manager = UsrManager::Instance();
    connect(_manager,SIGNAL(msgCurrentUsrChanged()),this,SLOT(usrLogInChanged()) );

//确定、取消信号-槽（用于退出界面）
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));

//刷新界面
    changeDNMode();
    Refresh_changlese_words();

//禁用按钮
    ui->pbLogOut->setEnabled(false);//用户等级大于0的用户，登录后启用
    ui->pbAutoLogOut->setEnabled(false);//用户等级大于0的用户，登录后启用
}

UsrLogInWidget::~UsrLogInWidget(){
    delete ui;
    delete _manager;
    delete _promptWidgetLogIn;
    delete _promptWidgetUsrSetting;
}

void UsrLogInWidget::changeDNMode(){
    QPalette p;
    if(daynight_mode == DAYMODE){
        p.setColor(QPalette::Normal,QPalette::ButtonText,COLOR_15);
        ui->pbAutoLogOut->setPalette(p);
        ui->pbLogIn->setPalette(p);
        ui->pbLogOut->setPalette(p);
        ui->pbCancel->setPalette(p);
    }
    else{
//        p.setColor(QPalette::Normal,QPalette::ButtonText,COLOR_23);
//        ui->pbAutoLogOut->setPalette(p);
//        ui->pbLogIn->setPalette(p);
//        ui->pbLogOut->setPalette(p);
//        ui->pbCancel->setPalette(p);
    }
    _promptWidgetLogIn->changeDNMode();
    _promptWidgetUsrSetting->changeDNMode();
}

void UsrLogInWidget::Refresh_changlese_words(){

    //更新按钮的文字
    ui->pbAutoLogOut->setFont(FONT_3);
    ui->pbAutoLogOut->setText( str_zidongdengchu );

    ui->pbLogIn->setFont(FONT_3);
    ui->pbLogIn->setText(str_denglu);

    ui->pbLogOut->setFont(FONT_3);
    ui->pbLogOut->setText(str_dengchu);

    ui->pbCancel->setFont(FONT_3);
    ui->pbCancel->setText(str_quxiao);

    //更新子窗口
    _promptWidgetUsrSetting->Refresh_changless_words();
    _promptWidgetLogIn->Refresh_changless_words();
}

//处理弹出界面完成
void UsrLogInWidget::promptFinished(){
    this->parentWidget()->setEnabled(true);
}

void UsrLogInWidget::on_pbCancel_clicked(){
    emit cancel_signal(this->objectName());
}

void UsrLogInWidget::on_pbAutoLogOut_clicked(){
    this->parentWidget()->setEnabled(false);
    _promptWidgetUsrSetting->setVisible(true);
}

void UsrLogInWidget::on_pbLogOut_clicked(){
    _manager->logOut();
}

void UsrLogInWidget::on_pbLogIn_clicked(){
    this->parentWidget()->setEnabled(false);
    _promptWidgetLogIn->setVisible(true);
}

void UsrLogInWidget::usrLogInChanged(){
    QString name;
    quint8 level;
    _manager->getNameAndLevel(&name,&level);
    ui->lblCurrentName->setText(QString("User:\n %1").arg(name));
    ui->lblCurrentLevel->setText(QString("Level: %1").arg(level));
    if(level>0){
        ui->pbLogOut->setEnabled(true);//用户等级大于0的用户，登录后启用
        ui->pbAutoLogOut->setEnabled(true);//用户等级大于0的用户，登录后启用
    }
    else{
        ui->pbLogOut->setEnabled(false);//用户等级大于0的用户，登录后启用
        ui->pbAutoLogOut->setEnabled(false);//用户等级大于0的用户，登录后启用
    }
}

void UsrLogInWidget::showEvent(QShowEvent *){
    QString name;
    quint8 level;
    _manager->getNameAndLevel(&name,&level);
    ui->lblCurrentName->setText(QString(str_yonghuming + " :%1").arg(name));
    ui->lblCurrentLevel->setText(QString(str_yonghudengji + " :%1").arg(level));
}
