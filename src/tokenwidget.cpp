#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QStringList>
#include "tokenwidget.h"
#include "ui_tokenwidget.h"

TokenWidget::TokenWidget(QWidget *parent, QRect rect) : QWidget(parent),
    ui(new Ui::TokenWidget)
{
//基础几何
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setGeometry(rect.x(),  rect.y() + 20, rect.width()-2,rect.height());

    _buzzer = buzzerGovernor::Instance();
//处理弹出界面(需要同步手柄)
    int dialogWidthWithSyn =  317;
    int dialogHeightWithSyn = 450;
    promptWidgetWithSyn = new PromptWidgetWithSyn(0,this,
                                    QRect((WINDOWWIDTH - dialogWidthWithSyn) / 2 , (WINDOWHEIGHT - dialogHeightWithSyn)/2 , dialogWidthWithSyn , dialogHeightWithSyn));
    promptWidgetWithSyn->statePtr = &_promptRes;//输出结果是修改_promptRes变量
    promptWidgetWithSyn->raise();//上层显示
    promptWidgetWithSyn->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    promptWidgetWithSyn->setVisible(false);
    connect(promptWidgetWithSyn,SIGNAL(changemode(bool)),this,SLOT(prompFinished(bool)));

//处理弹出界面(不需要同步手柄)
    int dialogWidth = 317;
    int dialogHeight = 212;
    promptWidget = new PromptWidget(0,this,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));
    promptWidget->statePtr = &_promptRes;//输出结果是修改_promptRes变量
    promptWidget->raise();//上层显示
    promptWidget->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    promptWidget->setVisible(false);
    connect(promptWidget,SIGNAL(changemode(bool)),this,SLOT(prompFinished(bool)));

//处理model和view
    _model = new QStandardItemModel(this);
    _model->setHorizontalHeaderItem(0, new QStandardItem( QString("操作站名称")));
    _model->setHorizontalHeaderItem(1, new QStandardItem( QString("状态")));
    _model->setVerticalHeaderItem  (0, new QStandardItem( QString("本机")));

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0,180);
    ui->tableView->setColumnWidth(1,180);
    ui->tableView->setFont(FONT_3);
//处理tokenmanager
    manager = new tmTokenManager();
    //设备列表有更新
    connect(manager,SIGNAL(msgPeersListChanged(int)),this,SLOT(updateModel(int)));
    //主站同步数据有更新
    connect(manager,SIGNAL(msgMasterPeerMessageUpdated()),this,SLOT(updateMasterString()));
    //设置本机器的参数（名称、IP地址、优先级（数值越高级别越高））
    tmPeer* s = manager->getSelfPeer();
#ifdef PORTABLE_STATION
    s->setName( QString("移动式操作端") );
    foreach( QHostAddress t, QNetworkInterface::allAddresses()){
        if (t.protocol() == QAbstractSocket::IPv4Protocol && !t.isLoopback()){
            s->setPeerIp( t.toIPv4Address() );
            break;
        }
    }
    s->setPeerPriority( 0 );
#else
    s->setName( QString("固定式操作端") );
    foreach( QHostAddress t, QNetworkInterface::allAddresses()){
        if (t.protocol() == QAbstractSocket::IPv4Protocol && !t.isLoopback()){
            s->setPeerIp( t.toIPv4Address() );
            break;
        }
    }
    s->setPeerPriority( 2 );
#endif
    connect(s,SIGNAL(msgStateChanged(quint64)),this,SLOT(selfStateChanged(quint64)));
    //启动manager
    manager->start();
    _comm = new QThread(this);
    manager->moveToThread(_comm);
    _comm->start();
    connect(manager,SIGNAL(msgTokenLostShallForceIn()),this,SLOT(lostToken()));
    connect(manager,SIGNAL(msgTokenDuplicatedShallForceOut()),this,SLOT(multiToken()));

//确定、取消信号-槽（用于退出界面）
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));

//刷新界面
    changeDNMode();
    Refresh_changlese_words();

}

TokenWidget::~TokenWidget(){
    _comm->deleteLater();
    delete ui;
    delete manager;
    delete _model;
    delete promptWidgetWithSyn;
    delete promptWidget;
}

void TokenWidget::changeDNMode(){
    QPalette p;
    if(daynight_mode == DAYMODE){
        p.setColor(QPalette::Normal,QPalette::ButtonText,COLOR_15);
        ui->pbAct->setPalette(p);
        ui->pbCancel->setPalette(p);
        ui->pbOk->setPalette(p);

        p.setColor(QPalette::Text,COLOR_15);
        ui->tableView->setPalette(p);

    }
    else{
//        p.setColor(QPalette::Normal,QPalette::ButtonText,COLOR_23);
//        ui->pbAct->setPalette(p);
//        ui->pbCancel->setPalette(p);
//        ui->pbOk->setPalette(p);

        p.setColor(QPalette::Text,COLOR_23);
        ui->tableView->setPalette(p);

    }
    promptWidget->changeDNMode();
    promptWidgetWithSyn->changeDNMode();
}

void TokenWidget::refreshData(){
    if(stat_master){
        QStringList list;
        list<<QString::number(Run_mode);
        list<<QString::number(Operate_mode);
        list<<QString::number(point_rot);
        list<<QString::number(set_heading);
        list<<QString::number(set_rot);
        list<<QString::number(joystick_x);
        list<<QString::number(joystick_y);
        list<<QString::number(joystick_z);
        list<<QString::number(flag_fullprop);
        QString listString = list.join(";");
        manager->setMasterPeerMessage( listString );
    }
    promptWidgetWithSyn->refreshData();//弹出界面(需要同步手柄)，需要数据刷新功能
}

void TokenWidget::Refresh_changlese_words(){

//更新三个按钮的文字
    ui->pbOk->setFont(FONT_3);
    ui->pbOk->setText( btnstr_fanhui );

    ui->pbCancel->setFont(FONT_3);
    ui->pbCancel->setText(str_quxiao);

    ui->pbAct->setFont(FONT_3);
    quint64 state = manager->getSelfPeer()->getState();
    int index = ui->tableView->currentIndex().row();
    if(state == tmPeer::stateOnlinewithToken){
        ui->pbAct->setText(btnstr_zhuanchu);
        if(manager->isIndexValid(index) && index !=0 ){
            ui->pbAct->setEnabled(true);
        }
        else{
            ui->pbAct->setEnabled(false);
        }
        ui->pbCancel->setEnabled(false);
    }
    else if(state == tmPeer::stateOnlinewithoutToken){
        ui->pbAct->setText(btnstr_zhuanru);
        ui->pbAct->setEnabled(true);
        ui->pbCancel->setEnabled(false);
    }
    else if(state == tmPeer::stateTokenTakeOutPending){
        ui->pbAct->setEnabled(false);
        ui->pbCancel->setEnabled(true);
    }
    else if(state == tmPeer::stateTokenTakeInPending){
        ui->pbAct->setText(btnstr_qiangqie);
        //本机优先级比较高，才能强切
        if(manager->getSelfPeer()->getPeerPriority() > manager->getPartner()->getPeerPriority() ){
            ui->pbAct->setEnabled(true);
        }
        else{
            ui->pbAct->setEnabled(false);
        }
        ui->pbCancel->setEnabled(true);
    }
    else if(state == tmPeer::stateTokenOrderOutPending){
        ui->pbAct->setEnabled(false);
        ui->pbCancel->setEnabled(true);
    }
    else if(state == tmPeer::stateTokenOrderInPending){
        ui->pbAct->setEnabled(false);
        ui->pbCancel->setEnabled(true);
    }
    else{
        ui->pbAct->setEnabled(false);
        ui->pbCancel->setEnabled(true);
    }
//更新_model栏目的文字
    QStandardItem* it = nullptr;

    it = _model->horizontalHeaderItem(0);
    it->setText( str_zhanminchen );
    it->setFont(FONT_3);
    it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    it = _model->horizontalHeaderItem(1);
    it->setText( str_zhanzhuangtai );
    it->setFont(FONT_3);
    it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    it = _model->verticalHeaderItem(0);
    it->setText( str_benji );
    it->setFont(FONT_3);
    it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
//更新_model内容的文字
    int i = 0;
    while( manager->isIndexValid(i) ){
        updateModel(i);
        i++;
    }
    promptWidgetWithSyn->Refresh_changless_words();
    promptWidget->Refresh_changless_words();
}

//更新_model
void TokenWidget::updateModel(int index){
    if( !manager->isIndexValid(index) )
        return;

    QModelIndex temp =ui->tableView->currentIndex();

    tmPeer* t = manager->getPeer(index);
    if(t <=0 ) return;

    int lang;
    if(State_language == "English"){
        lang = baseDevice::langEN;
    }
    else{
        lang = baseDevice::langCHN;
    }

    QStandardItem* it = nullptr;
    it = _model->item(index, 0);
    if(it)  it->setText( t->getName() );
    else  _model->setItem(index,0,new QStandardItem( t->getName() ) );

    it = _model->item(index, 1);
    if(it)  it->setText( t->getStateString( lang ) );
    else  _model->setItem(index,1,new QStandardItem( t->getStateString( lang ) ) );

}

//用于处理主站来的数据
void TokenWidget::updateMasterString(){
    QStringList list = manager->getMasterPeerMessage().split(";");
    qDebug()<<"TokenWidget::updateMasterString"<<list;
    if(list.size() != 9) return;
    bool ok;
    if(!stat_master){
        Run_mode        =  list.at(0).toInt(&ok);
        Operate_mode    =  list.at(1).toInt(&ok);
        point_rot       =  list.at(2).toInt(&ok);
        set_heading     =  list.at(3).toFloat(&ok);
        set_rot         =  list.at(4).toFloat(&ok);
        masterJoystick_x=  list.at(5).toFloat(&ok);
        masterJoystick_y=  list.at(6).toFloat(&ok);
        masterJoystick_z=  list.at(7).toFloat(&ok);
        flag_fullprop   =  list.at(8).toInt(&ok);
    }
}

//更新本机的状态
void TokenWidget::selfStateChanged(quint64 state){

    qDebug()<<"TokenWidget::selfStateChanged"<<state;
    if(state == tmPeer::stateOnlinewithToken){
        stat_master = true;
        //收起界面
        _promptRes = 0;
        this->parentWidget()->setEnabled(true);
        promptWidgetWithSyn->setVisible(false);
        promptWidgetWithSyn->setEnabled(false);
        promptWidget->setVisible(false);
        promptWidget->setEnabled(false);
        _buzzer->reset2Hz();
    }
    else if(state == tmPeer::stateOnlinewithoutToken){
        stat_master = false;
        //收起界面
        _promptRes = 0;
        this->parentWidget()->setEnabled(true);
        promptWidgetWithSyn->setVisible(false);
        promptWidgetWithSyn->setEnabled(false);
        promptWidget->setVisible(false);
        promptWidget->setEnabled(false);
        _buzzer->reset2Hz();
    }
    else if(state == tmPeer::stateTokenTakeOutPending){

    }
    else if(state == tmPeer::stateTokenTakeInPending){

    }
    else if(state == tmPeer::stateTokenOrderOutPending){
        //弹出界面，不需要手柄同步
        promptWidget->targetState = 1;
        promptWidget->message = str_order_out.arg( manager->getPartner()->getName() );
        this->parentWidget()->setEnabled(false);
        promptWidget->setVisible(true);
        promptWidget->setEnabled(true);
        _buzzer->set2Hz();
    }
    else if(state == tmPeer::stateTokenOrderInPending){
        //弹出界面，需要手柄同步
        promptWidgetWithSyn->targetState = 2;
        promptWidgetWithSyn->message = str_order_in.arg( manager->getPartner()->getName() );
        this->parentWidget()->setEnabled(false);
        promptWidgetWithSyn->setVisible(true);
        promptWidgetWithSyn->setEnabled(true);
        _buzzer->set2Hz();
    }
    else{
        stat_master = false;
        //所有弹出界面消失
        _promptRes = 0;
        this->parentWidget()->setEnabled(true);
        promptWidgetWithSyn->setVisible(false);
        promptWidgetWithSyn->setEnabled(false);
        promptWidget->setVisible(false);
        promptWidget->setEnabled(false);
        _buzzer->reset2Hz();
    }

    Refresh_changlese_words();
}


//处理弹出界面完成
void TokenWidget::prompFinished(bool ok){
    this->parentWidget()->setEnabled(true);
    _buzzer->reset2Hz();
    if(ok && _promptRes == 1){
        //TokenOrderOut
        manager->tokenOrderOutAck();
    }
    else if(ok && _promptRes == 2){
        //TokenOrderIn
        manager->tokenOrderInAck();
    }
    else if(ok && _promptRes ==3){
        //TokenTakeIn
        manager->tokenTakeIn(-1,-1);//无超时
    }
    else if(ok && _promptRes ==4){
        //Token lost
        manager->tokenForceTakeIn();
    }
    else if(ok && _promptRes ==5){
        //Token duplicated
        manager->tokenForceTakeOut();
    }
    else if(!ok){
        manager->tokenOrderInCancel();
        manager->tokenOrderOutCancel();
        manager->tokenTakeInCancel();
    }
    _promptRes = 0;
}

void TokenWidget::on_pbAct_clicked()
{
    quint64 state = manager->getSelfPeer()->getState();
    int index = ui->tableView->currentIndex().row();

    if(state == tmPeer::stateOnlinewithoutToken){
        //take in 需要同步
        promptWidgetWithSyn->targetState = 3;
        promptWidgetWithSyn->message = str_take_in;
        this->parentWidget()->setEnabled(false);
        promptWidgetWithSyn->setVisible(true);
        promptWidgetWithSyn->setEnabled(true);
        _buzzer->set2Hz();
    }
    else if(state == tmPeer::stateTokenTakeInPending){
        //force take in 不需要同步，不需要弹出界面
        manager->tokenForceTakeIn();
    }
    else if(state == tmPeer::stateOnlinewithToken){
        //take out 不需要同步，不需要弹出界面
        manager->tokenTakeOut(index,-1);
    }
    else {
    }
}

//处理网络令牌丢失，本机需要获得令牌的故障
void TokenWidget::lostToken(){
    //需要同步
//    if(CCdata_alarm[15]){//控制器通信故障
//        return;
//    }
    promptWidgetWithSyn->targetState = 4;
    promptWidgetWithSyn->message = str_token_lost;
    this->parentWidget()->setEnabled(false);
    promptWidgetWithSyn->setVisible(true);
    promptWidgetWithSyn->setEnabled(true);
    _buzzer->set2Hz();
}

//处理网络令牌重复，本机需要让出令牌的故障
void TokenWidget::multiToken(){
    //弹出界面，不需要手柄同步
    promptWidget->targetState = 5;
    promptWidget->message = str_token_duplicated;
    this->parentWidget()->setEnabled(false);
    promptWidget->setVisible(true);
    promptWidget->setEnabled(true);
    _buzzer->set2Hz();
}

void TokenWidget::on_pbCancel_clicked()
{
    _buzzer->reset2Hz();
    quint64 state = manager->getSelfPeer()->getState();
    if(state == tmPeer::stateTokenTakeOutPending){
        manager->tokenTakeOutCancel();
    }
    else if(state == tmPeer::stateTokenTakeInPending){
        manager->tokenTakeInCancel();
    }
    else if(state == tmPeer::stateTokenOrderOutPending){
        manager->tokenOrderOutCancel();
    }
    else if(state == tmPeer::stateTokenOrderInPending){
        manager->tokenOrderInCancel();
    }
    else {
    }
}

void TokenWidget::on_pbOk_clicked()
{
    emit ok_signal(this->objectName());
}

void TokenWidget::on_tableView_clicked(const QModelIndex &index)
{
    Refresh_changlese_words();
}
