/*
    设备视图
*/
#include "deviceviewwidget.h"
#include "ui_deviceviewwidget.h"

DeviceViewWidget::DeviceViewWidget(QWidget *parent,QRect rect) :
    QWidget(parent),
    ui(new Ui::DeviceViewWidget)
{
    ui->setupUi(this);

    this->setGeometry(rect.x(),  rect.y()+ 30, rect.width()-5,rect.height());

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_20)));
//    this->setPalette(p);
    changeDNMode();

    QDateTime time = QDateTime::currentDateTime();

    start_time = time.currentDateTime().toString("MM.dd hh:mm:ss");

    ui->lbrow1_3->setFont(FONT_3);
    ui->lbrow1_4->setFont(FONT_3);
    ui->lbrow1_5->setFont(FONT_3);
    ui->lbrow2_3->setFont(FONT_3);
    ui->lbrow2_4->setFont(FONT_3);
    ui->lbrow2_5->setFont(FONT_3);

    ui->lbrow2_3->setText("0");
    ui->lbrow2_4->setText(start_time);
    ui->lbrow2_5->setText("");

    ui->lbrow1_3->setText("0");
    ui->lbrow1_4->setText(start_time);
    ui->lbrow1_5->setText("");
/*
    //添加表头
    QStandardItemModel *device_model = new QStandardItemModel();
    device_model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Station")));
    device_model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Status")));
    device_model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Error")));
    device_model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Reported")));
    device_model->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("Master")));

    ui->device_tableView->setModel(device_model);

    //设置表格属性
    //设置列宽不可变动
    ui->device_tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
    ui->device_tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
    ui->device_tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
    ui->device_tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
    ui->device_tableView->horizontalHeader()->setResizeMode(4, QHeaderView::Fixed);

    //设置列宽
    ui->device_tableView->setColumnWidth(0,120);
    ui->device_tableView->setColumnWidth(1,100);
    ui->device_tableView->setColumnWidth(2,120);
    ui->device_tableView->setColumnWidth(3,100);
    ui->device_tableView->setColumnWidth(4,350);

    //设置表格单元格只读
    ui->device_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //添加行
    device_model->setItem(0,0,new QStandardItem(str_caozuoduan));//"Cjoy-JS1"
    device_model->setItem(0,1,new QStandardItem(str_yunxing));//"Operation"
    device_model->setItem(0,2,new QStandardItem(QString::number(atlen)));//"0"
    device_model->setItem(0,3,new QStandardItem("18:03:01"));
    device_model->setItem(0,4,new QStandardItem(""));

    device_model->setItem(1,0,new QStandardItem("WT1"));
    device_model->setItem(1,1,new QStandardItem("Operational"));
    device_model->setItem(1,2,new QStandardItem("0"));
    device_model->setItem(1,3,new QStandardItem("18:08:08"));
    device_model->setItem(1,4,new QStandardItem(""));


    QBrush brush(QColor(220,229,229));
    QFont font("Microsoft Sans Serif",20,QFont::Bold);

//        device_model->item(0,0)->setFont(font);
    device_model->item(0,0)->setBackground(brush);
    device_model->item(0,1)->setBackground(brush);
    device_model->item(0,2)->setBackground(brush);
    device_model->item(0,3)->setBackground(brush);
    device_model->item(0,4)->setBackground(brush);

    device_model->item(0,0)->setTextAlignment(Qt::AlignCenter);
    device_model->item(0,1)->setTextAlignment(Qt::AlignCenter);
    device_model->item(0,2)->setTextAlignment(Qt::AlignCenter);
    device_model->item(0,3)->setTextAlignment(Qt::AlignCenter);
    device_model->item(0,4)->setTextAlignment(Qt::AlignCenter);


    device_model->item(1,0)->setBackground(brush);
    device_model->item(1,1)->setBackground(brush);
    device_model->item(1,2)->setBackground(brush);
    device_model->item(1,3)->setBackground(brush);
    device_model->item(1,4)->setBackground(brush);

    device_model->item(1,0)->setTextAlignment(Qt::AlignCenter);
    device_model->item(1,1)->setTextAlignment(Qt::AlignCenter);
    device_model->item(1,2)->setTextAlignment(Qt::AlignCenter);
    device_model->item(1,3)->setTextAlignment(Qt::AlignCenter);
    device_model->item(1,4)->setTextAlignment(Qt::AlignCenter);


    ui->device_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选择
    */

}

//白天、夜晚模式切换
void DeviceViewWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_20)));//":/images/设备视图-日.png"
        ui->lbtitle_1->setStyleSheet(StyleSheet_DayColor);
        ui->lbtitle_2->setStyleSheet(StyleSheet_DayColor);
        ui->lbtitle_3->setStyleSheet(StyleSheet_DayColor);
        ui->lbtitle_4->setStyleSheet(StyleSheet_DayColor);
        ui->lbtitle_5->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow1_1->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow1_2->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow1_3->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow1_4->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow1_5->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow2_1->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow2_2->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow2_3->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow2_4->setStyleSheet(StyleSheet_DayColor);
        ui->lbrow2_5->setStyleSheet(StyleSheet_DayColor);

    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_20)));
        ui->lbtitle_1->setStyleSheet(StyleSheet_NgtColor);
        ui->lbtitle_2->setStyleSheet(StyleSheet_NgtColor);
        ui->lbtitle_3->setStyleSheet(StyleSheet_NgtColor);
        ui->lbtitle_4->setStyleSheet(StyleSheet_NgtColor);
        ui->lbtitle_5->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow1_1->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow1_2->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow1_3->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow1_4->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow1_5->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow2_1->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow2_2->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow2_3->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow2_4->setStyleSheet(StyleSheet_NgtColor);
        ui->lbrow2_5->setStyleSheet(StyleSheet_NgtColor);

    }
    this->setPalette(p);
}

void DeviceViewWidget::Refresh_changless_words()
{
    ui->lbtitle_1->setFont(FONT_2);
    ui->lbtitle_2->setFont(FONT_2);
    ui->lbtitle_3->setFont(FONT_2);
    ui->lbtitle_4->setFont(FONT_2);
    ui->lbtitle_5->setFont(FONT_2);

    ui->lbtitle_1->setText(str_shebeimingcheng);
    ui->lbtitle_2->setText(str_zhuangtai);
    ui->lbtitle_3->setText(str_cuowu);
    ui->lbtitle_4->setText(str_kaijishijian);
    ui->lbtitle_5->setText(str_beizhu);

    ui->lbrow1_1->setFont(FONT_3);
    ui->lbrow1_2->setFont(FONT_3);

    ui->lbrow2_1->setFont(FONT_3);
    ui->lbrow2_2->setFont(FONT_3);


    ui->lbrow1_1->setText(str_caozuoduan);
    ui->lbrow1_2->setText(str_kecaozuo);

    ui->lbrow2_1->setText(str_kongzhigui);
    ui->lbrow2_2->setText(str_yunxing);


}

DeviceViewWidget::~DeviceViewWidget()
{
    delete ui;
}
