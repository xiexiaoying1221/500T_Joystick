#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "tokenwidget.h"
#include "ui_tokenwidget.h"

TokenWidget::TokenWidget(QWidget *parent, QRect rect) : QWidget(parent),
    ui(new Ui::TokenWidget)
{
//基础几何
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setGeometry(rect.x(),  rect.y() + 20, rect.width()-2,rect.height());

//处理弹出界面
    int dialogWidth = 317;
    int dialogHeight = 212;
    promptWidget = new PromptWidget(0,this,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));
    promptWidget->statePtr = &promptRes;
    promptWidget->raise();//上层显示
    promptWidget->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    promptWidget->setVisible(false);
    connect(promptWidget,SIGNAL(changemode(bool)),this,SLOT(prompFinished(bool)));

//处理model和view
    _model = new QStandardItemModel(this);
    _model->setHorizontalHeaderItem(0, new QStandardItem( QString("操作站名称")));
    _model->setHorizontalHeaderItem(1, new QStandardItem( QString("状态")));
    _model->setHorizontalHeaderItem(2, new QStandardItem( QString("最后错误")));
    _model->setVerticalHeaderItem(0, new QStandardItem(QString("本机")));

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0,90);
    ui->tableView->setColumnWidth(1,145);
    ui->tableView->setColumnWidth(2,140);

//处理tokenmanager
    manager = new tmTokenManager();
    //设备列表有更新
    connect(manager,SIGNAL(msgPeersListChanged(int)),this,SLOT(updateModel(int)));
    //主站同步数据有更新
    connect(manager,SIGNAL(msgMasterPeerMessageUpdated()),this,SLOT(updateMasterString()));
    //设置本机器的参数（名称、IP地址、优先级（数值越高级别越高））
    tmPeer* s = manager->getSelfPeer();
    s->setName( QString("固定式操作端") );
    foreach( QHostAddress t, QNetworkInterface::allAddresses()){
        if (t.protocol() == QAbstractSocket::IPv4Protocol && !t.isLoopback()){
            s->setPeerIp( t.toIPv4Address() );
            break;
        }
    }
    s->setPeerPriority( 2 );
    connect(s,SIGNAL(msgStateChanged(quint64)),this,SLOT(selfStateChanged(quint64)));
    //启动manager
    manager->start();
    _comm = new QThread(this);
    manager->moveToThread(_comm);
    _comm->start();

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

//        ui->pbAct->setStyleSheet("background-color: transparent;"
//                                 "border-image: url(:/images/按钮-日.png);");
//        ui->pbCancel->setStyleSheet("background-color: transparent;"
//                                 "border-image: url(:/images/按钮-日.png);");
//        ui->pbOk->setStyleSheet("background-color: transparent;"
//                                 "border-image: url(:/images/按钮-日.png);");
    }
    else{
//        p.setColor(QPalette::Normal,QPalette::ButtonText,COLOR_23);
//        ui->pbAct->setPalette(p);
//        ui->pbCancel->setPalette(p);
//        ui->pbOk->setPalette(p);

        p.setColor(QPalette::Text,COLOR_23);
        ui->tableView->setPalette(p);

//        ui->pbAct->setStyleSheet("background-color: transparent;"
//                                 "border-image: url(:/images/按钮-夜.png);");
//        ui->pbCancel->setStyleSheet("background-color: transparent;"
//                                 "border-image: url(:/images/按钮-夜.png);");
//        ui->pbOk->setStyleSheet("background-color: transparent;"
//                                 "border-image: url(:/images/按钮-夜.png);");
    }
}

void TokenWidget::refreshData(){

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
    it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    it = _model->horizontalHeaderItem(1);
    it->setText( str_zhanzhuangtai );
    it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    it = _model->horizontalHeaderItem(2);
    it->setText( str_zhancuowu );
    it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    it = _model->verticalHeaderItem(0);
    it->setText( str_benji );
    it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
//更新_model内容的文字
    int i = 0;
    while( manager->isIndexValid(i) ){
        updateModel(i);
        i++;
    }

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

    it = _model->item(index, 2);
    if(it)  it->setText( t->getErrorStringList( lang ).join(";") );
    else  _model->setItem(index,2,new QStandardItem( t->getErrorStringList( lang ).join(";") ) );
    ui->tableView->setCurrentIndex(temp);
}

//用于处理主站来的数据
void TokenWidget::updateMasterString(){

}

//更新本机的状态
void TokenWidget::selfStateChanged(quint64 state){
    if(state == tmPeer::stateOnlinewithToken){
        stat_master = true;
        //收起界面
        promptRes = 0;
        this->parentWidget()->setEnabled(true);
        promptWidget->setVisible(false);
        promptWidget->setEnabled(false);
    }
    else if(state == tmPeer::stateOnlinewithoutToken){
        stat_master = false;
        //收起界面
        promptRes = 0;
        this->parentWidget()->setEnabled(true);
        promptWidget->setVisible(false);
        promptWidget->setEnabled(false);
    }
    else if(state == tmPeer::stateTokenTakeOutPending){

    }
    else if(state == tmPeer::stateTokenTakeInPending){

    }
    else if(state == tmPeer::stateTokenOrderOutPending){
        //弹出界面
        promptWidget->targetState = 1;
        promptWidget->message = str_take_out.arg( manager->getPartner()->getName() );
        this->parentWidget()->setEnabled(false);
        promptWidget->setVisible(true);
        promptWidget->setEnabled(true);
    }
    else if(state == tmPeer::stateTokenOrderInPending){
        //弹出界面
        promptWidget->targetState = 2;
        promptWidget->message = str_give_in.arg( manager->getPartner()->getName() );
        this->parentWidget()->setEnabled(false);
        promptWidget->setVisible(true);
        promptWidget->setEnabled(true);
    }
    else{
        stat_master = false;
        //收起界面
        promptRes = 0;
        this->parentWidget()->setEnabled(true);
        promptWidget->setVisible(false);
        promptWidget->setEnabled(false);
    }

    Refresh_changlese_words();
}


//处理弹出界面完成
void TokenWidget::prompFinished(bool ok){
    this->parentWidget()->setEnabled(true);
    promptWidget->setEnabled(true);

    if(promptRes == 1){
        //TokenOrderOut
        if(ok){
            //确认
            manager->tokenOrderOutAck();
        }
        else{
            //取消
            manager->tokenOrderOutCancel();
        }
    }
    else if(promptRes == 2){
        //TokenOrderIn
        if(ok){
            //确认
            manager->tokenOrderInAck();
        }
        else{
            //取消
            manager->tokenOrderInCancel();
        }
    }
    promptRes = 0;
}

void TokenWidget::on_pbAct_clicked()
{
    quint64 state = manager->getSelfPeer()->getState();
    int index = ui->tableView->currentIndex().row();

    if(state == tmPeer::stateOnlinewithoutToken){
        manager->tokenTakeIn(-1,30000);//30sec超时
    }
    else if(state == tmPeer::stateTokenTakeInPending){
        manager->tokenForceTakeIn();
    }
    else if(state == tmPeer::stateOnlinewithToken){
        manager->tokenTakeOut(index,30000);
    }
    else {
    }
}

void TokenWidget::on_pbCancel_clicked()
{
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
