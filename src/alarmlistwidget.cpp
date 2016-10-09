/*
    报警列表视图
*/

#include "alarmlistwidget.h"
#include "ui_alarmlistwidget.h"

AlarmListWidget::AlarmListWidget(QWidget *parent,QRect rect) :
    QWidget(parent),
    ui(new Ui::AlarmListWidget)
{
    ui->setupUi(this);

    int marginTop = WINDOWHEIGHT * (TITLE_HEIGHT_PERCENTAGE + INFO_HEIGHT_PERCENTAGE);//距离顶部

    this->setGeometry(rect.x()+1,  rect.y()+marginTop-3, rect.width()-1,rect.height() -2);

    this->setAutoFillBackground(true);
    QPalette p;
    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_2)));//"images/报警页背景-日.png"
    this->setPalette(p);

    //添加表头
    //QStandardItemModel *alarm_model = new QStandardItemModel();
    alarm_model = new QStandardItemModel();
    //alarm_model->item(0,0)->setFont(FONT_3);
    alarm_model->setHorizontalHeaderItem(0,new QStandardItem(almtitle_yingda));//QObject::tr("应答")
    alarm_model->setHorizontalHeaderItem(1,new QStandardItem(almtitle_laiyuan));//QObject::tr("来源")
    alarm_model->setHorizontalHeaderItem(2,new QStandardItem(almtitle_shijian));//QObject::tr("时间")
    alarm_model->setHorizontalHeaderItem(3,new QStandardItem(almtitle_jibie));//级别-QObject::tr("类型")
    alarm_model->setHorizontalHeaderItem(4,new QStandardItem(almtitle_leixing));//QObject::tr("状态")
    alarm_model->setHorizontalHeaderItem(5,new QStandardItem(almtitle_miaoshu));//QObject::tr("描述")
    alarm_model->setHorizontalHeaderItem(6,new QStandardItem(almtitle_xinxi));//QObject::tr("信息")

    ui->alarm_tableView->horizontalHeader()->setFont(FONT_2);

    ui->alarm_tableView->setModel(alarm_model);
    ui->alarm_tableView->setFont(FONT_2);
    //ui->alarm_tableView->horizontalHeader()->



    //设置表格属性
    //设置列宽不可变动
    ui->alarm_tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
    ui->alarm_tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
    ui->alarm_tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
    ui->alarm_tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
    ui->alarm_tableView->horizontalHeader()->setResizeMode(4, QHeaderView::Fixed);
    ui->alarm_tableView->horizontalHeader()->setResizeMode(5, QHeaderView::Fixed);
    ui->alarm_tableView->horizontalHeader()->setResizeMode(6, QHeaderView::Fixed);


    //设置列宽
    ui->alarm_tableView->setColumnWidth(0,60);
    ui->alarm_tableView->setColumnWidth(1,100);
    ui->alarm_tableView->setColumnWidth(2,180);
    ui->alarm_tableView->setColumnWidth(3,80);
    ui->alarm_tableView->setColumnWidth(4,80);
    ui->alarm_tableView->setColumnWidth(5,280);
    ui->alarm_tableView->setColumnWidth(6,200);

    //设置表格单元格只读
//    ui->alarm_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    ui->alarm_tableView->setStyleSheet("QTableView::Item{background-color:#FF3EFF}");

    //setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->alarm_tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->alarm_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选择

}

void AlarmListWidget::refreshData(){
    alarm_model = (QStandardItemModel *)ui->alarm_tableView->model();

    alarm_model->removeRows(0,alarm_model->rowCount());

    QBrush brush1(COLOR_16);//警告
    QBrush brush2(COLOR_18);//报警
    QBrush brush3(COLOR_19);//紧急
    QBrush brush4(COLOR_11);//提示

    QBrush brush;

    //添加行
    int i;
    for( i=0; i<atlen;i++)
    {
        alarm_model->setItem(i,0,new QStandardItem(AlarmOrderList[i][0]));
        alarm_model->setItem(i,1,new QStandardItem(AlarmOrderList[i][1]));
        alarm_model->setItem(i,2,new QStandardItem(AlarmOrderList[i][2]));
        alarm_model->setItem(i,3,new QStandardItem(AlarmOrderList[i][3]));
        alarm_model->setItem(i,4,new QStandardItem(AlarmOrderList[i][4]));
        alarm_model->setItem(i,5,new QStandardItem(AlarmOrderList[i][5]));
        alarm_model->setItem(i,6,new QStandardItem(AlarmOrderList[i][6]));

        if(AlarmOrderList[i][3] == "警告" || AlarmOrderList[i][3] == "W")
        {
            brush = brush1;
        }
        else if(AlarmOrderList[i][3] == "报警" || AlarmOrderList[i][3] == "A")
        {
            brush = brush2;
        }
        else if(AlarmOrderList[i][3] == "紧急" || AlarmOrderList[i][3] == "E")
        {
            brush = brush3;
        }
        else// if(AlarmOrderList[i][3] == "提示" || AlarmOrderList[i][3] == "I")
        {
            brush = brush4;
        }

        alarm_model->item(i,0)->setFont(FONT_15);
        alarm_model->item(i,0)->setBackground(brush);
        alarm_model->item(i,1)->setBackground(brush);
        alarm_model->item(i,2)->setBackground(brush);
        alarm_model->item(i,3)->setBackground(brush);
        alarm_model->item(i,4)->setBackground(brush);
        alarm_model->item(i,5)->setBackground(brush);
        alarm_model->item(i,6)->setBackground(brush);

        alarm_model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        alarm_model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        alarm_model->item(i,2)->setTextAlignment(Qt::AlignCenter);
        alarm_model->item(i,3)->setTextAlignment(Qt::AlignCenter);
        alarm_model->item(i,4)->setTextAlignment(Qt::AlignCenter);
        alarm_model->item(i,5)->setTextAlignment(Qt::AlignCenter);
        alarm_model->item(i,6)->setTextAlignment(Qt::AlignCenter);
    }

    for( i = atlen ; i <21 ; i++ )
    {
        alarm_model->setItem(i,0,new QStandardItem(""));
        alarm_model->setItem(i,1,new QStandardItem(""));
        alarm_model->setItem(i,2,new QStandardItem(""));
        alarm_model->setItem(i,3,new QStandardItem(""));
        alarm_model->setItem(i,4,new QStandardItem(""));
        alarm_model->setItem(i,5,new QStandardItem(""));
        alarm_model->setItem(i,6,new QStandardItem(""));
    }
}



//白天、夜晚模式切换
void AlarmListWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_2)));//"images/报警页背景-日.png"
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_2)));//"images/报警页背景-夜.png"
    }
    this->setPalette(p);
}

//中英文切换--报警表格页标题行文字
void AlarmListWidget::Refresh_changless_words()
{
    QStandardItem *item = 0;
    item = alarm_model->horizontalHeaderItem(0);
    if(item !=0 ) item->setText(almtitle_yingda);
    item = alarm_model->horizontalHeaderItem(1);
    if(item !=0 ) item->setText(almtitle_laiyuan);
    item = alarm_model->horizontalHeaderItem(2);
    if(item !=0 ) item->setText(almtitle_shijian);
    item = alarm_model->horizontalHeaderItem(3);
    if(item !=0 ) item->setText(almtitle_jibie);
    item = alarm_model->horizontalHeaderItem(4);
    if(item !=0 ) item->setText(almtitle_leixing);
    item = alarm_model->horizontalHeaderItem(5);
    if(item !=0 ) item->setText(almtitle_miaoshu);
    item = alarm_model->horizontalHeaderItem(6);
    if(item !=0 ) item->setText(almtitle_xinxi);

}

AlarmListWidget::~AlarmListWidget()
{
    delete ui;
}
