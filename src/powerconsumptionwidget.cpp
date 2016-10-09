/*
    功耗视图
*/
#include "powerconsumptionwidget.h"
#include "ui_powerconsumptionwidget.h"

PowerConsumptionWidget::PowerConsumptionWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::PowerConsumptionWidget)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_12)));//"images/功耗视图-日.png"
//    this->setPalette(p);
    changeDNMode();

    this->setGeometry(viewRect.x(),  viewRect.y() + 20, viewRect.width()-2,viewRect.height());
}

/*刷新数据*/
void PowerConsumptionWidget::refreshData()
{
//    Power_now = rand() % 9600;
    ui->lepower_now->setText(QString::number(Power_now,'f',0));
    ui->lepower_sum->setText(QString::number(Power_sum,'f',0));

    update();
}

//白天、夜晚模式切换
void PowerConsumptionWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_12)));//"images/功耗视图-日.png"
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        this->setPalette(p);
        p.setColor(QPalette::Text,COLOR_15);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_12)));//"images/功耗视图-夜.png"
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        this->setPalette(p);
        p.setColor(QPalette::Text,COLOR_23);
    }

    ui->lepower_now->setPalette(p);
    ui->lepower_sum->setPalette(p);

}

void PowerConsumptionWidget::Refresh_changless_words()
{

    ui->label_1->setFont(FONT_15);
    ui->label_2->setFont(FONT_15);

    ui->label_1->setText(str_gonglvxiaohao);
    ui->label_2->setText(str_keyonggonglv);


}


void PowerConsumptionWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QBrush brush(COLOR_20);
//    QPen pen(QColor(0, 170, 0));
    QPen pen1(COLOR_18,1.5, Qt::DashLine, Qt::FlatCap, Qt::RoundJoin);//红色
    QPen pen2(COLOR_17,1.5, Qt::DashLine, Qt::FlatCap, Qt::RoundJoin);//橙色
    int x = 356;
    int y = 132;
    int w = 68;
    int h = 220;

    float percent = Power_now / Power_sum;

    int relativeH = Power_now * h / Power_sum;


    painter.setPen(Qt::NoPen);
    if(percent >= 0.9)
        brush.setColor(COLOR_18);
    else if(percent >= 0.8)
        brush.setColor(COLOR_17);
    else
        brush.setColor(COLOR_20);
    painter.setBrush(brush);

    painter.drawRect(x,y + h -relativeH,w,relativeH);
    painter.setPen(pen1);
    painter.drawLine(x,y+0.1*h,x+w,y+0.1*h);
    painter.setPen(pen2);
    painter.drawLine(x,y+0.2*h,x+w,y+0.2*h);




//    qDebug(QString("%1 %2").arg(ui->lblStdDev->x()).arg(ui->lblStdDev->y()).toLatin1());

//    int width = ui->lblPowerConsumption->width();
//    int height = ui->lblPowerConsumption->height()/3;
//    int x = ui->lblPowerConsumption->x();
//    int y = ui->lblPowerConsumption->y() + ui->lblPowerConsumption->height() - height;

//    painter.drawRect(x,y, width,height);

//    painter.drawLine();
}
PowerConsumptionWidget::~PowerConsumptionWidget()
{
    delete ui;
}
