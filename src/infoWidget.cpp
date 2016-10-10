#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "infoWidget.h"

InfoWidget::InfoWidget(QWidget *parent, QRect infoRect)
    :QWidget(parent,Qt::FramelessWindowHint){


//    QPalette *p = new QPalette(Qt::yellow);
//    this->setPalette(*p);
//    this->setAutoFillBackground(true);
    this->setGeometry(infoRect.x()+270,  infoRect.y()-2, infoRect.width(),infoRect.height()-1);

//    this->setAttribute(Qt::WA_PaintOutsidePaintEvent);
}

void InfoWidget::refreshData(){
//    Operate_mode = READY_MODE;
    update();
}

void InfoWidget::paintEvent(QPaintEvent *){
    int width = this->geometry().width();
    int height = this->geometry().height();

    int part = width / 16;
    QTextOption to(Qt::AlignCenter);

    if(atlen == 0){
        this->setAutoFillBackground(false);
        return;
    }
    //分成10份
    QPainter painter(this);
    painter.setFont(FONT_2);

    QPalette *p;
//    QBrush brush1(COLOR_16);//警告
//    QBrush brush2(COLOR_18);//报警
//    QBrush brush3(COLOR_19);//紧急
//    QBrush brush4(COLOR_20);//启用

    if(AlarmOrderList[0][3] == "警告" || AlarmOrderList[0][3] == "W"){
        p = new QPalette(COLOR_16);
        painter.setPen(PEN_WARN);
    }
    else if(AlarmOrderList[0][3] == "报警" || AlarmOrderList[0][3] == "A"){
        p = new QPalette(COLOR_18);
        painter.setPen(PEN_ALARM);
    }
    else if(AlarmOrderList[0][3] == "紧急" || AlarmOrderList[0][3] == "E"){
        p = new QPalette(COLOR_19);
        painter.setPen(PEN_ALARM);
    }
    else{
        p = new QPalette(COLOR_11);
        painter.setPen(PEN_INFO);
    }

    this->setPalette(*p);
    delete p;
    this->setAutoFillBackground(true);

    painter.drawLine(part*0.5,0,part*0.5,height);
    QRect rect1(0,0,part*0.5,height);
    painter.drawText(rect1,AlarmOrderList[0][0],to);

    painter.drawLine(part*1.5,0,part *1.5,height);
    QRect rect2(part*0.5,0,part,height);
    painter.drawText(rect2,AlarmOrderList[0][1],to);

    painter.drawLine(part* 4,0,part * 4,height);
    QRect rect3(part *1.5,0,part*2.5,height);
    painter.drawText(rect3,AlarmOrderList[0][2],to);

    painter.drawLine(part* 5,0,part * 5,height);
    QRect rect4(part * 4,0,part,height);
    painter.drawText(rect4,AlarmOrderList[0][3],to);

    painter.drawLine(part* 6,0,part * 6,height);
    QRect rect5(part * 5,0,part,height);
    painter.drawText(rect5,AlarmOrderList[0][4],to);

    painter.drawLine(part* 9,0,part * 9,height);
    QRect rect6(part * 6,0,3*part,height);
    painter.drawText(rect6,AlarmOrderList[0][5],to);

    QRect rect7(part * 9,0,3*part,height);
    painter.drawText(rect7,AlarmOrderList[0][6],to);
}
