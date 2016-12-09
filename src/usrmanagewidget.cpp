#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "usrmanagewidget.h"
#include "ui_usrmanagewidget.h"

UsrManageWidget::UsrManageWidget(QWidget *parent, QRect rect) : QWidget(parent),
    ui(new Ui::UsrManageWidget)
{
//基础几何
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setGeometry(rect.x(),  rect.y() + 20, rect.width()-2,rect.height());

//修改名称弹出界面
    int dialogWidth =  450;
    int dialogHeight = 639;
    _promptWidgetChangeName = new PromptWidgetChangeName(0,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));
    _promptWidgetChangeName->raise();//上层显示
    _promptWidgetChangeName->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    _promptWidgetChangeName->setVisible(false);
    connect(_promptWidgetChangeName,SIGNAL(promptFinished()),this,SLOT(promptFinished()));

//修改密码弹出界面
    _promptWidgetChangePswd = new PromptWidgetChangePswd(0,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));
    _promptWidgetChangePswd->raise();//上层显示
    _promptWidgetChangePswd->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    _promptWidgetChangePswd->setVisible(false);
    connect(_promptWidgetChangePswd,SIGNAL(promptFinished()),this,SLOT(promptFinished()));

//新建用户密码弹出界面
    _promptWidgetUsrNew = new PromptWidgetUsrNew(0,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));
    _promptWidgetUsrNew->raise();//上层显示
    _promptWidgetUsrNew->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    _promptWidgetUsrNew->setVisible(false);
    connect(_promptWidgetUsrNew,SIGNAL(promptFinished()),this,SLOT(promptFinished()));

//处理model和view
    _model = new QStandardItemModel(this);
    _model->setHorizontalHeaderItem(0, new QStandardItem( QString("用户名称")));
    _model->setHorizontalHeaderItem(1, new QStandardItem( QString("用户等级")));

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0,180);
    ui->tableView->setColumnWidth(1,180);
    ui->tableView->setFont(FONT_3);
    _model->setHorizontalHeaderItem(0, new QStandardItem( str_yonghuming));
    _model->setHorizontalHeaderItem(1, new QStandardItem( str_yonghudengji));

//处理manager
    _manager = UsrManager::Instance();
    //登录有更新
    connect(_manager,SIGNAL(msgCurrentUsrChanged()),this,SLOT(usrLogInChanged()));
    //用户列表有更新
    connect(_manager,SIGNAL(msgUsrListChanged()),this,SLOT(updateModel()) );

//确定、取消信号-槽（用于退出界面）
    connect(this,SIGNAL(ok_signal(QString)),parent,SLOT(childWidgetOkSlot(QString)));
    connect(this,SIGNAL(cancel_signal(QString)),parent,SLOT(childWidgetCancleSlot(QString)));

//刷新界面
    changeDNMode();
    Refresh_changlese_words();

//禁用按钮
    ui->pbChangeName->setEnabled(false);//表格选中用户后启用
    ui->pbChangePswd->setEnabled(false);//表格选中用户后启用
    ui->pbDeleteUsr->setEnabled(false);//表格选中用户后启用
    ui->pbNewUsr->setEnabled(false);//用户等级大于0的用户，登录后启用

}

UsrManageWidget::~UsrManageWidget(){
    delete ui;
    delete _manager;
    delete _model;
    delete _promptWidgetUsrNew;
    delete _promptWidgetChangePswd;
    delete _promptWidgetChangeName;
}

void UsrManageWidget::changeDNMode(){
    QPalette p;
    if(daynight_mode == DAYMODE){
        p.setColor(QPalette::Normal,QPalette::ButtonText,COLOR_15);
        ui->pbChangeName->setPalette(p);
        ui->pbChangePswd->setPalette(p);
        ui->pbDeleteUsr->setPalette(p);
        ui->pbNewUsr->setPalette(p);
        ui->pbCancel->setPalette(p);

        p.setColor(QPalette::Text,COLOR_15);
        ui->tableView->setPalette(p);

    }
    else{
//        p.setColor(QPalette::Normal,QPalette::ButtonText,COLOR_23);
//        ui->pbChangeName->setPalette(p);
//        ui->pbChangePswd->setPalette(p);
//        ui->pbDeleteUsr->setPalette(p);
//        ui->pbNewUsr->setPalette(p);
//        ui->pbCancel->setPalette(p);

        p.setColor(QPalette::Text,COLOR_23);
        ui->tableView->setPalette(p);

    }
    _promptWidgetUsrNew->changeDNMode();
    _promptWidgetChangePswd->changeDNMode();
    _promptWidgetChangeName->changeDNMode();
}

void UsrManageWidget::Refresh_changlese_words(){

//更新三个按钮的文字
    ui->pbChangeName->setFont(FONT_3);
    ui->pbChangeName->setText( str_xiugaiyonghuming );

    ui->pbChangePswd->setFont(FONT_3);
    ui->pbChangePswd->setText( str_xiugaimima );

    ui->pbDeleteUsr->setFont(FONT_3);
    ui->pbDeleteUsr->setText( str_shanchuyonghu );

    ui->pbNewUsr->setFont(FONT_3);
    ui->pbNewUsr->setText( str_xinyonghu );

    ui->pbCancel->setFont(FONT_3);
    ui->pbCancel->setText(str_quxiao );

//更新_model内容的文字
    QStandardItem* it = nullptr;
    it = _model->horizontalHeaderItem(0);
    it->setFont(FONT_3);
    it->setText( str_yonghuming );
    it = _model->horizontalHeaderItem(1);
    it->setFont(FONT_3);
    it->setText( str_yonghudengji );
    updateModel();

//更新_promptWidget
    _promptWidgetUsrNew->Refresh_changless_words();
    _promptWidgetChangePswd->Refresh_changless_words();
    _promptWidgetChangeName->Refresh_changless_words();
}

//更新_model
void UsrManageWidget::updateModel(){
    QList<UsrInfo*> temp = _manager->getUsrList();
    _model->setRowCount( temp.size() );
    _model->setColumnCount(2);
    for(int i = 0; i < temp.size(); i++){
        QStandardItem* it;
        it =  _model->item(i, 0);
        if(it!=0){
            it->setText( temp.at(i)->getName() );
        }
        else{
            _model->setItem(i,0, new QStandardItem( temp.at(i)->getName() ));
        }
        it = _model->item(i, 1);
        if(it!=0){
            it->setText( QString::number( temp.at(i)->getLevel() ));
        }
        else{
            _model->setItem(i,1, new QStandardItem( temp.at(i)->getLevel() ));
        }
    }
}
//处理用户登录改变
void UsrManageWidget::usrLogInChanged(){
    quint8 level;
    _manager->getNameAndLevel(0,&level);
    if(level>0){
        ui->pbNewUsr->setEnabled(true);//用户等级大于0的用户，登录后启用
    }
    else{
        ui->pbNewUsr->setEnabled(false);//用户等级大于0的用户，登录后启用
    }
}

//处理弹出界面完成
void UsrManageWidget::promptFinished(){
    this->parentWidget()->setEnabled(true);
}

void UsrManageWidget::on_pbChangeName_clicked()
{
    int index = ui->tableView->currentIndex().row();
    if(index <0 ) return;
    QString targetName = _model->item(index, 0)->text();

    this->parentWidget()->setEnabled(false);
    _promptWidgetChangeName->setTargetUsrName( targetName );
    _promptWidgetChangeName->show();
}

void UsrManageWidget::on_pbChangePswd_clicked()
{
    int index = ui->tableView->currentIndex().row();
    if(index <0 ) return;
    QString targetName = _model->item(index, 0)->text();

    this->parentWidget()->setEnabled(false);
    _promptWidgetChangePswd->setTargetUsrName( targetName );
    _promptWidgetChangePswd->show();
}

void UsrManageWidget::on_pbNewUsr_clicked()
{
    this->parentWidget()->setEnabled(false);
    _promptWidgetUsrNew->show();
}

void UsrManageWidget::on_pbDeleteUsr_clicked()
{
    int index = ui->tableView->currentIndex().row();
    if(index <0 ) return;
    QString targetName = _model->item(index, 0)->text();
    _manager->deleteUsr(targetName);
}

void UsrManageWidget::on_pbCancel_clicked()
{
    emit cancel_signal(this->objectName());
}

void UsrManageWidget::on_tableView_clicked(const QModelIndex &index)
{
    if(index.row() <0 ){
        ui->pbChangeName->setEnabled(false);//表格选中用户后启用
        ui->pbChangePswd->setEnabled(false);//表格选中用户后启用
        ui->pbDeleteUsr->setEnabled(false);//表格选中用户后启用
    }
    else{
        ui->pbChangeName->setEnabled(true);//表格选中用户后启用
        ui->pbChangePswd->setEnabled(true);//表格选中用户后启用
        ui->pbDeleteUsr->setEnabled(true);//表格选中用户后启用
    }
}

void UsrManageWidget::showEvent(QShowEvent *){
    updateModel();
}
