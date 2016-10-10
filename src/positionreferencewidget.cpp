/*
    位置参考系统视图
*/

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "positionreferencewidget.h"
#include "ui_positionreferencewidget.h"

PositionReferenceWidget::PositionReferenceWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::PositionReferenceWidget)
{
    ui->setupUi(this);
    this->setGeometry(viewRect.x(),  viewRect.y() + 20, viewRect.width()-2,viewRect.height());

    this->setAutoFillBackground(true);
//    QPalette p;
//    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_11)));//"images/位置参考视图-日.png"
//    //changeDNMode();

//    this->setPalette(p);

//    ui->leWeight1->setFont(FONT_11);
//    ui->leWeight2->setFont(FONT_11);

//    ui->leECurrentPosition->setFont(FONT_11);
//    ui->leNCurrentPosition->setFont(FONT_11);
//    ui->leEPositionSetpoint->setFont(FONT_11);
//    ui->leNPositionSetpoint->setFont(FONT_11);

    changeDNMode();
}


/*刷新数据*/
void PositionReferenceWidget::refreshData()
{
    ui->leNCurrentPosition->setText(QString::number(pos_north,'f',4));
    ui->leNPositionSetpoint->setText(QString::number(set_north,'f',4));
    ui->leECurrentPosition->setText(QString::number(pos_east,'f',4));
    ui->leEPositionSetpoint->setText(QString::number(set_east,'f',4));

    QPalette pe = ui->leStatus1->palette();
    ui->leStatus1->setFont(FONT_3);
    ui->leStatus2->setFont(FONT_3);

    ui->leRef1->setText("GPS1");

    if(State_GPS1 == 0)
    {
        ui->leStatus1->setText(str_zaixian);//"在线"
        ui->leWeight1->setText("1");
        pe.setColor(QPalette::Text,COLOR_22);
    }
    else if(State_GPS1 ==1)
    {
        ui->leStatus1->setText(str_zaixian);//"在线"
        ui->leWeight1->setText("0");
        pe.setColor(QPalette::Text,COLOR_17);
    }
    else
    {
        ui->leStatus1->setText(str_lixian);//"离线"
        ui->leWeight1->setText("0");
        pe.setColor(QPalette::Text,COLOR_18);
    }
    ui->leStatus1->setPalette(pe);


    ui->leRef2->setText("GPS2");

    if(State_GPS2 == 0)
    {
        ui->leStatus2->setText(str_zaixian);//"在线"
        ui->leWeight2->setText("1");
        pe.setColor(QPalette::WindowText,COLOR_22);
    }
    else if(State_GPS2 ==1)
    {
        ui->leStatus2->setText(str_zaixian);//"在线"
        ui->leWeight2->setText("0");
        pe.setColor(QPalette::WindowText,COLOR_17);
    }
    else
    {
        ui->leStatus2->setText(str_lixian);//"离线"
        ui->leWeight2->setText("0");
        pe.setColor(QPalette::WindowText,COLOR_18);
    }
    ui->leStatus2->setPalette(pe);


}

//白天、夜晚模式切换
void PositionReferenceWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_11)));//"images/位置参考视图-日.png"
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_5->setStyleSheet(StyleSheet_DayColor);
        ui->label_6->setStyleSheet(StyleSheet_DayColor);
        ui->label_7->setStyleSheet(StyleSheet_DayColor);
        ui->label_8->setStyleSheet(StyleSheet_DayColor);
        this->setPalette(p);

        p.setColor(QPalette::Text,QColor(COLOR_15));

    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_11)));//"images/位置参考视图-夜.png"

        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_5->setStyleSheet(StyleSheet_NgtColor);
        ui->label_6->setStyleSheet(StyleSheet_NgtColor);
        ui->label_7->setStyleSheet(StyleSheet_NgtColor);
        ui->label_8->setStyleSheet(StyleSheet_NgtColor);
        this->setPalette(p);

        p.setColor(QPalette::Text,QColor(COLOR_23));
    }

    ui->leECurrentPosition->setPalette(p);
    ui->leEPositionSetpoint->setPalette(p);
    ui->leNCurrentPosition->setPalette(p);
    ui->leNPositionSetpoint->setPalette(p);
    ui->leRef1->setPalette(p);
    ui->leStatus1->setPalette(p);
    ui->leWeight1->setPalette(p);
    ui->leRef2->setPalette(p);
    ui->leStatus2->setPalette(p);
    ui->leWeight2->setPalette(p);
    ui->leRef3->setPalette(p);
    ui->leStatus3->setPalette(p);
    ui->leWeight3->setPalette(p);

}

void PositionReferenceWidget::Refresh_changless_words()
{
    ui->label_1->setFont(FONT_3);
    ui->label_1->setText(str_shedingweizhi);

    ui->label_2->setFont(FONT_3);
    ui->label_2->setText(str_dangqianweizhi);

    ui->label_3->setFont(FONT_3);
    ui->label_3->setText(str_bei);

    ui->label_4->setFont(FONT_3);
    ui->label_4->setText(str_dong);

    ui->label_5->setFont(FONT_3);
    ui->label_5->setText(str_cankaoyuandian);

    ui->label_6->setFont(FONT_3);
    ui->label_6->setText(str_gpsmingcheng);

    ui->label_7->setFont(FONT_3);
    ui->label_7->setText(str_zhuangtai);

    ui->label_8->setFont(FONT_3);
    ui->label_8->setText(str_jiaquan);
}

void PositionReferenceWidget::test(){
    //ui->gridLayout_3->setGeometry(QRect(0,500,1024,384));
}

void PositionReferenceWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QBrush brush(QColor(170, 0, 127));
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

//    qDebug(QString("%1 %2").arg(ui->lblStdDev->x()).arg(ui->lblStdDev->y()).toLatin1());
//    painter.drawRect(ui->lblStdDev->x(),ui->lblStdDev->y(),ui->lblStdDev->width()/2,ui->lblStdDev->height()-1);
}

PositionReferenceWidget::~PositionReferenceWidget()
{
    delete ui;
}
