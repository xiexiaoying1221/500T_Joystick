#include "positionWidget.h"

PositionWidget::PositionWidget(QWidget *parent, QRect positionRect)
    :QWidget(parent, Qt::FramelessWindowHint){

    this->setGeometry(positionRect.x(),  positionRect.y(), positionRect.width(),positionRect.height());

    QPalette *p = new QPalette(Qt::transparent);//Qt::transparent
    this->setPalette(*p);
    this->setAutoFillBackground(true);

    pre_posNorth = set_north;
    pre_posEast = set_east;
    pre_pos = 0;
}

void PositionWidget::refreshData()
{
    update();
}

//白天、夜晚模式切换
void PositionWidget::changeDNMode()
{

}

void PositionWidget::paintEvent(QPaintEvent *){
    int width = this->geometry().width();
    int height = this->geometry().height();

//    经纬度位置
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
//    10个刻度 remainder：矩形离边界间距 interval：刻度间距
    int llHeight = 40;//经纬度高度
    int len = width > height - llHeight ? (height - llHeight) : width;

    int remainder = len % 20;
    if(remainder ==0 )
        remainder = len / 20;
    int interval = (len - remainder)/20;

    QPen pen;
    QPen pen2;//灰字体
    QPen pen3;//艏向区设定进度条
    QPen pen4;//艏向区反馈进度条
    QPen pen5;//虚线
    QPen pen6;//点
    QPen pen7;//亮蓝色 设定进度条
    QPen pen8;
    QPen pen9;//灰 虚线
    QPen pen10;//报警
    QPen pen11;//警告
    QPen pen12;
    QPen pen13;
    QPen pen14;
    QPen pen15;

    if(daynight_mode == DAYMODE)
    {
        pen = PEN_2;
        pen2 = PEN_1;
        pen3 = PEN_7;
        pen4 = PEN_8;
        pen5 = PEN_11;
        pen6 = PEN_12;
        pen7 = PEN_13;
        pen8 = PEN_9;
        pen9 = PEN_10;
        pen10 = PEN_4;
        pen11 = PEN_14;
        pen12 = PEN_15;
        pen13 = PEN_16;
        pen14 = PEN_17;
        pen15 = PEN_19;
    }
    else
    {
        pen = PEN_1_1;
        pen2 = PEN_1;
        pen3 = PEN_7;
        pen4 = PEN_8;
        pen5 = PEN_10;
        pen6 = PEN_12;
        pen7 = PEN_13;
        pen8 = PEN_9;
        pen9 = PEN_10;
        pen10 = PEN_4;
        pen11 = PEN_14;
        pen12 = PEN_15;
        pen13 = PEN_16;
        pen14 = PEN_17;
        pen15 = PEN_19;
    }


    int rectW = 4*interval/3;
    int rectH = 8 * interval;
    QString wuxiao = "------";


    pen3.setWidth(rectW);
    pen4.setWidth(rectW);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(pen2);
    painter.drawLine(0,llHeight, width,llHeight);
    painter.drawLine(width/2,1,width/2,llHeight);

    painter.setFont(FONT_5);
    painter.drawText(QRect(5,0,width/2,llHeight),Qt::AlignLeft,str_bei);//" 北"
    painter.drawText(QRect((width/2 +5),0,width/2,llHeight),Qt::AlignLeft,str_dong);//" 东"

    painter.setFont(FONT_5);//(FONT_9);
    painter.drawText(QRect(20,0,width/2-20,llHeight),Qt::AlignVCenter | Qt::AlignHCenter,wuxiao);//QString::number(pos_north,'f',4));
    painter.drawText(QRect(width/2+20,0,width/2-20,llHeight),Qt::AlignVCenter | Qt::AlignHCenter,wuxiao);//QString::number(pos_east,'f',4));

//    移动坐标系,使得坐标原点在正方形中心
    painter.translate( width / 2, (height - llHeight) / 2 + llHeight);

//    画矩形

//    Operate_mode = AUTOPLT_MODE;
//----------------------------------------------自动纵轴------------------------------------------
    if(Operate_mode == KEEPX_MODE || Operate_mode == KEEPXD_MODE)
    {
        painter.setBrush(BRUSH_7);
        painter.drawRect(QRect(-10*interval,-rectW,8*interval,2*rectW));//左
        painter.drawRect(QRect(2*interval,-rectW,8*interval,2*rectW));//右

        painter.setPen(pen7);
        painter.drawRect(-rectW,-10*interval,2*rectW, 20 *interval);

//        画十字型
        painter.setPen(pen2);
        painter.drawLine(-10 * interval,0, 10*interval,0);

//        画刻度
        for(int i=1; i<= 10; i++){
            painter.drawLine(i * interval,1,i * interval,-1);//x +
            painter.drawLine(-i * interval,1,-i * interval,-1);// x-
        }

        painter.setPen(pen10);
        painter.drawLine(-rectW,-8*interval,interval-5,-8*interval);
        painter.drawLine(-rectW,8*interval,interval-5,8*interval);
        painter.setPen(pen11);
        painter.drawLine(-rectW,-5*interval,interval-5,-5*interval);
        painter.drawLine(-rectW,5*interval,interval-5,5*interval );

        int cmdfy = 8 * interval * cmd_Fy / MAX_FY;
        int fbkfy = 8 * interval * fbk_Fy / MAX_FY;


        int beginY = cmdfy > 0 ? 2*interval : -2*interval;
        painter.setPen(pen3);
        painter.drawLine(beginY ,-rectW/2, beginY + cmdfy,-rectW/2);//cmd-fy

        painter.setPen(pen4);
        beginY = fbkfy > 0 ? 2*interval : -2*interval;
        painter.drawLine(beginY, rectW/2,beginY + fbkfy,rectW/2);//fbk-fy



        //虚线
        cmdfy = 10 * interval * cmd_Fy / MAX_FY;

        painter.setPen(pen5);

//        //点 位置
//        int pointX = cmdfy;

//        if(fabs(pointX) > 10 * interval)
//        {
//           pointX = pointX >0 ? 10 * interval : -10*interval;
//        }

//        painter.setPen(pen6);
//        painter.drawPoint(0,pointX);

        //点位置
        int pointX = cmdfy;

        if(fabs(pointX) > 10 * interval)
        {
           pointX = pointX >0 ? -10 * interval : 10*interval;
        }

        painter.setPen(pen6);
        painter.drawPoint(pointX,0);


        /*数值显示 区域*/
        int rectWidth = 60;
        int rectHeight = 26;
        int rectX = interval;
        int rectY = interval;

        if(pos_north - set_north > 0)
        {
            rectY =  -10 * interval;
        }
        else
        {
            rectY = 10 * interval - 20;
        }

        QRect rectver(rectX + 8 ,rectY, rectWidth ,rectHeight);

        if(cmd_Fy > 0)
        {
            rectX = 10 * interval - rectWidth;
        }
        else
        {
            rectX =  -10 * interval;
        }

        QRect recthor(rectX,rectW + 2,rectWidth,rectHeight+10);

        painter.setPen(pen);

        float offsetNorth = pos_x - set_pos_x ;
        painter.setFont(FONT_9);


        painter.drawText(rectver,Qt::AlignLeft,QString::number((offsetNorth) ,'f',1));// "米"
        painter.drawText(recthor,Qt::AlignTop,QString::number(fbk_Fy * 100.0 /MAX_FY,'f',0) +'%');//xxy
        painter.setPen(pen2);
        painter.setFont(FONT_1);
        painter.drawText(QRect(rectver.x() + rectver.width(),rectver.y(),10,rectver.height()),Qt::AlignCenter,danwei_mi);
        painter.drawText(recthor,Qt::AlignBottom | Qt::AlignRight,str_youxian);//"右舷"

        float offsetLen = 0;//偏差对应的长度
        float maxOffsetNorth = Warning_pos + Alarm_pos;//最大的偏差

        bool alarm_increase = false;//处于警告且增加

        if(fabs(offsetNorth) < Warning_pos)//正常值
        {
            offsetLen = fabs(offsetNorth*100) * 5 * interval / (Warning_pos * 100);
            pen4.setWidth(rectW);
            painter.setPen(pen4);
            painter.setBrush(BRUSH_1);

            isWarn_posx = false;
            isAlarm_posx = false;
        }
        else if(flag_warningp && fabs(offsetNorth) < Alarm_pos)//超出警告值
        {
            offsetLen = 5 * interval +  (fabs(offsetNorth)-Warning_pos)  * 3 * interval / (Alarm_pos - Warning_pos) ;
            pen12.setWidth(rectW);
            painter.setPen(pen12);
            painter.setBrush(BRUSH_2);

            isWarn_posx = true;
            isAlarm_posx = false;
        }
        else if(flag_alarmp && fabs(offsetNorth) > Alarm_pos)//超出报警值
        {
            pen13.setWidth(rectW);
            painter.setPen(pen13);
            painter.setBrush(BRUSH_2);
            offsetLen = 8 * interval +  (fabs(offsetNorth)-Alarm_pos) * 2 * interval / (maxOffsetNorth -Alarm_pos) ;
            alarm_increase = true;

            isWarn_posx = false;
            isAlarm_posx = true;
        }

        if(offsetLen > 10 * interval) offsetLen = 10 * interval;

        painter.drawLine(-rectW/3,0,-rectW/3,offsetNorth > 0 ? -offsetLen : offsetLen);

        painter.setPen(pen14);
        painter.setFont(FONT_10);

        QPolygonF polygon;

        painter.setPen(pen8);


        if( fabs(pos_north) > fabs(pre_posNorth) )
        {
            if(offsetNorth > 0)//增大 纵 上
            {
                polygon << QPointF(0+ interval/3,  -9 * interval-3)

                           <<QPointF(-interval + 2 + interval/3, -8*interval + 1 )

                           <<QPointF(-interval/3 -1 + interval/3,-8*interval + 1)

                           <<QPointF(-interval/3 - 1 + interval/3, -7*interval + 1)

                           <<QPointF(interval/3 + 1 + interval/3, -7*interval + 1)

                           <<QPointF(interval/3 + 1 + interval/3,-8*interval + 1)

                           <<QPointF(interval - 2 + interval/3, -8*interval + 1);
            }
            else if(offsetNorth <= 0) //增大 纵 下
            {
                polygon << QPointF(0 + interval/3,  9 * interval + 3)
                           <<QPointF(-interval + 2 + interval/3, 8*interval - 1 )

                           <<QPointF(-interval/3 -1 + interval/3,8*interval - 1 )

                           <<QPointF(-interval/3 -1 + interval/3, 7*interval -1 )

                           <<QPointF(interval/3 +1 + interval/3, 7*interval -1 )

                           <<QPointF(interval/3 +1 + interval/3,8*interval - 1)

                           <<QPointF(interval - 2 + interval/3, 8*interval -1);

            }

            if(alarm_increase) alarm_increase = true;
        }
        else if(fabs(pos_north) < fabs(pre_posNorth))
        {
            if(offsetNorth > 0)//减小 纵 下
            {
                polygon << QPointF(0 + interval/3,  -7*interval + 2)
                           <<QPointF(-interval + 2 + interval/3, -8*interval - 2 )

                           <<QPointF(-interval/3 -1 + interval/3,-8*interval - 2 )

                           <<QPointF(-interval/3 -1 + interval/3, -9*interval - 2 )

                           <<QPointF(interval/3 +1 + interval/3, -9*interval - 2 )

                           <<QPointF(interval/3 +1 + interval/3,-8*interval - 2)

                           <<QPointF(interval - 2 + interval/3, -8*interval - 2);
                 }
            else
            {

                polygon << QPointF(0 + interval/3,  7*interval - 2)
                           <<QPointF(-interval + 2 + interval/3, 8*interval + 2 )

                           <<QPointF(-interval/3 -1 + interval/3, 8*interval + 2 )

                           <<QPointF(-interval/3 -1 + interval/3, 9*interval + 2 )

                           <<QPointF(interval/3 +1 + interval/3, 9*interval + 2 )

                           <<QPointF(interval/3 +1 + interval/3,8*interval + 2)

                           <<QPointF(interval - 2 + interval/3, 8*interval + 2);

            }
            alarm_increase =false;
        }

        pre_posNorth = pos_north;


        painter.drawPolygon(polygon, Qt::WindingFill);
        if(alarm_increase)
        {
            painter.setPen(pen14);
            painter.setFont(FONT_10);
            if(offsetNorth > 0)
                painter.drawText(QRect(-interval,-9*interval,4*interval/3,9*interval), Qt::AlignTop | Qt::AlignHCenter," + ");
            else
            {
                painter.drawText(QRect(-interval,0,4*interval/3,9*interval),Qt::AlignBottom | Qt::AlignCenter," + ");
            }
        }
        painter.setPen(pen);
    }
//-------------------------------------------------自动横轴--------------------------------------------
    else if(Operate_mode == KEEPY_MODE || Operate_mode == KEEPYD_MODE)
    {
        painter.setBrush(BRUSH_7);
        painter.drawRect(QRect(-rectW,-10*interval,2*rectW,8*interval));//上
        painter.drawRect(QRect(-rectW,2*interval,2*rectW,8*interval));//下

        painter.setPen(pen7);
        painter.drawRect(-10*interval,-rectW,20*interval, 2*rectW);

//        画十字型
        painter.setPen(pen2);
        painter.drawLine(0,-interval*10 ,0,interval*10);

//        画刻度
        for(int i=1; i<= 10; i++){
            painter.drawLine(-1,i*interval,1,i*interval);//y +
            painter.drawLine(-1,-i*interval,1,-i*interval);// y-
        }

        painter.setPen(pen10);
        painter.drawLine(-8*interval,-rectW,-8*interval,rectW -5);
        painter.drawLine(8*interval,-rectW,8*interval,rectW -5);
        painter.setPen(pen11);
        painter.drawLine(-5*interval,-rectW,-5*interval,rectW -5);
        painter.drawLine(5*interval,-rectW,5*interval,rectW -5);


        int cmdfx = rectH * cmd_Fx / MAX_FX;
        int fbkfx = rectH * fbk_Fx / MAX_FX;

        if(cmdfx > rectH) cmdfx = rectH;
        if(fbkfx > rectH) fbkfx = rectH;

        int beginX = cmdfx > 0 ? -2*interval : 2*interval;
        painter.setPen(pen3);
        painter.drawLine(-rectW/2,beginX, -rectW/2,beginX-cmdfx);//cmd-fx


        painter.setPen(pen4);
        beginX = fbkfx > 0 ? -2*interval : 2*interval;
        painter.drawLine(rectW/2,beginX,rectW/2,beginX-fbkfx);//fbk-fx

        //虚线
        cmdfx = 10 * interval * cmd_Fx / MAX_FX;

        painter.setPen(pen5);

        //点 位置
        int pointX = -cmdfx;

        if(fabs(pointX) > 10 * interval)
        {
           pointX = pointX >0 ? -10 * interval : 10*interval;
        }

        painter.setPen(pen6);
        painter.drawPoint(0,pointX);

//        //点位置
//        int pointX = cmdfx;

//        if(fabs(pointX) > 10 * interval)
//        {
//           pointX = pointX >0 ? 10 * interval : -10*interval;
//        }

//        painter.setPen(pen6);
//        painter.drawPoint(pointX,0);



         /*数值显示 区域*/
         int rectWidth = 100;
         int rectHeight = 26;
         int rectX = rectW;
         int rectY = rectW;

         float offsetEast = pos_y - set_pos_y;

         if(offsetEast >= 0)
         {
             rectX =  10 * interval - rectWidth;
         }
         else
         {
             rectX = -10 * interval;
         }

         QRect rectver(rectX ,rectY,rectWidth-10,rectHeight);

         if(cmd_Fx > 0)
         {
             rectY = -10 * interval;
         }
         else
         {
             rectY  =  10 * interval - rectHeight - 10;
         }

         QRect recthor(rectW+2,rectY,70,rectHeight+10);



         painter.setPen(pen);
         painter.setFont(FONT_9);

//         painter.drawRect(recthor);

//         painter.drawRect(rectver);
//         painter.drawRect(QRect(rectver.x()+rectver.width(),rectver.y(),10,rectHeight));



         painter.drawText(rectver,Qt::AlignTop | Qt::AlignRight,QString::number((offsetEast) ,'f',1) );
         painter.drawText(recthor,Qt::AlignTop,QString::number(fbk_Fx * 100.0 /MAX_FX,'f',0) +'%');//xxy
         painter.setPen(pen2);
         painter.setFont(FONT_1);
         painter.drawText(QRect(rectver.x()+rectver.width(),rectver.y(),10,rectHeight),Qt::AlignLeft | Qt::AlignVCenter ,danwei_mi);
         painter.drawText(recthor,Qt::AlignBottom | Qt::AlignRight,str_shouxiang);//"艏向"


        float offsetLen = 0;//偏差对应的长度
        float maxOffsetEast = Warning_pos + Alarm_pos;//最大的偏差

        bool alarm_increase = false;//处于警告且增加

        pen4.setColor(COLOR_10);
        if(fabs(offsetEast) < Warning_pos)//正常值
        {
            offsetLen = fabs(offsetEast) * 5 * interval / Warning_pos;
            painter.setBrush(BRUSH_1);

            isWarn_posy = false;
            isAlarm_posy = false;
        }
        else if(flag_warningp && fabs(offsetEast) < Alarm_pos)//超出警告值
        {
            offsetLen = 5 * interval +  (fabs(offsetEast)-Warning_pos) * 3 * interval / (Alarm_pos-Warning_pos) ;
            pen4.setColor(COLOR_17);
            painter.setBrush(BRUSH_2);

            isWarn_posy = true;//位置偏差报警为true
            isAlarm_posy = false;
        }
        else if(flag_alarmp && fabs(offsetEast) > Alarm_pos)//超出报警值
        {
            pen4.setColor(COLOR_18);
            painter.setBrush(BRUSH_2);
            offsetLen = 8 * interval +  (fabs(offsetEast)-Alarm_pos) * 2 * interval / (maxOffsetEast-Alarm_pos);
            alarm_increase = true;

            isWarn_posy = false;
            isAlarm_posy = true;
        }

        if(offsetLen > 10 * interval) offsetLen = 10 * interval;

        pen4.setWidth(4*rectW/3);
        painter.setPen(pen4);
        painter.drawLine(0,-rectW/3,offsetEast > 0 ? offsetLen : -offsetLen,-rectW/3);
        pen4.setWidth(rectW);

        pen2.setColor(Qt::white);

        painter.setPen(pen2);
        painter.setFont(FONT_10);

        QPolygonF polygon;

        if( fabs(pos_east) > fabs(pre_posEast) )
        {
            if(offsetEast > 0)//增大 横 右
            {

                polygon << QPointF(9 * interval+3, 0 + interval/3)

                           <<QPointF( 8*interval - 1 ,interval - 3 + interval/3)

                           <<QPointF(8*interval - 1, interval/3 + 1 + interval/3)

                           <<QPointF( 7*interval - 2, interval/3 + 1 + interval/3)

                           <<QPointF( 7*interval - 2, -interval/3 - 1 + interval/3)

                           <<QPointF(8*interval - 1, -interval/3 - 1 + interval/3)

                           <<QPointF(8*interval - 1, -interval + 3 + interval/3);

            }
            else if(offsetEast < 0)//增大 横 左
            {
                        polygon << QPointF(-9 * interval-3, 0 + interval/3)

                                   <<QPointF(-8*interval + 1 ,interval - 3 + interval/3)

                                   <<QPointF(-8*interval + 1, interval/3 + 1 + interval/3)

                                   <<QPointF(-7*interval + 2, interval/3 + 1 + interval/3)

                                   <<QPointF(-7*interval + 2, -interval/3 - 1 + interval/3)

                                   <<QPointF(-8*interval + 1, -interval/3 - 1 + interval/3)

                                   <<QPointF(-8*interval + 1, -interval + 3 + interval/3);
            }

            if(alarm_increase) alarm_increase = true;
        }
        else if(fabs(pos_north) < fabs(pre_posEast))
        {
            if(offsetEast > 0)//减小 横 右
            {

        polygon << QPointF(-7*interval + 2 , 0 + interval/3)
                   <<QPointF( -8*interval - 2, -interval + 2.5 + interval/3)

                   <<QPointF(-8*interval - 2 , -interval/3 -1 + interval/3)

                   <<QPointF(-9*interval - 2 , -interval/3 -1 + interval/3)

                   <<QPointF(-9*interval - 2  , interval/3 +1 + interval/3)

                   <<QPointF(-8*interval - 2 , interval/3 +1 + interval/3)

                   <<QPointF( -8*interval - 2, interval - 2.5 + interval/3);


            }
            else if(offsetEast < 0)//减小 横 左
            {
            polygon << QPointF(7*interval - 2 , 0 + interval/3)
                       <<QPointF( 8*interval + 2, -interval + 2.5 + interval/3)

                       <<QPointF(8*interval + 1 , -interval/3 -1 + interval/3)

                       <<QPointF(9*interval + 2 , -interval/3 -1 + interval/3)

                       <<QPointF(9*interval + 2  , interval/3 +1 + interval/3)

                       <<QPointF(8*interval + 2 , interval/3 +1 + interval/3)

                       <<QPointF(8*interval + 1, interval - 2.5 + interval/3);
            }
            alarm_increase =false;
        }

        pre_posEast = pos_east;
        painter.setPen(pen8);

        painter.drawPolygon(polygon, Qt::WindingFill);
        if(alarm_increase)
        {
            pen2.setColor(Qt::white);

            painter.setPen(pen2);
            painter.setFont(FONT_10);
            if(offsetEast > 0)
            {
                painter.drawText(QRect(0,-interval,offsetLen,4*interval/3), Qt::AlignRight | Qt::AlignVCenter," + ");
            }
            else
            {
                painter.drawText(QRect(-offsetLen,-interval,offsetLen,4*interval/3),Qt::AlignVCenter | Qt::AlignLeft," + ");
            }
        }
    }

/*-----------------------------------------位置保持模式----------------------------------------------*/
    else if(Operate_mode == KEEPPOS_MODE || Operate_mode == KEEPXY_MODE)
    {
        pen2.setColor(COLOR_17);
        pen9.setColor(COLOR_17);
        if(flag_warningp)
            painter.setPen(pen2);
        else
            painter.setPen(pen9);

        painter.drawArc(-3*interval,-3*interval,6*interval,6*interval,0,16*360);
        pen2.setColor(COLOR_18);
        pen9.setColor(COLOR_18);
        if(flag_alarmp)
            painter.setPen(pen2);
        else
            painter.setPen(pen9);//虚线

        painter.drawArc(-6*interval,-6*interval,12*interval,12*interval,0,16*360);
        pen2.setColor(COLOR_15);
        painter.setPen(pen2);
        painter.drawArc(-9*interval,-9*interval,18*interval,18*interval,0,16*360);

        float pos_ = sqrt(pow(pos_east - set_east ,2) + pow(pos_north - set_north,2));//位置
        float maxPosition =  Warning_pos + Alarm_pos;
        float pradius = 0; //圆 半径

        bool alarm_increase =false;//报警且持续增加
        bool overAlarm =false;//超出报警

        painter.setFont(FONT_9);
        QString positionStr = QString::number(pos_,'f',1);
        if(fabs(pos_) < Warning_pos)
        {
            painter.setBrush(BRUSH_5);
            pradius = 3 * interval * pos_ / Warning_pos;

            isWarn_pos = false;
            isAlarm_pos = false;
        }
        else if(fabs(pos_) < Alarm_pos)
        {
            painter.setBrush(BRUSH_3);
            pradius = 3 * interval * (pos_ - Warning_pos) / (Alarm_pos - Warning_pos) + 3 * interval;

            isWarn_pos = true;
            isAlarm_pos = false;
        }
        else
        {
            painter.setBrush(BRUSH_9);
            if(fabs(pos_) >999.9)
                positionStr = "??";
            pradius = 3 * interval * (pos_ - Alarm_pos) /(maxPosition - Alarm_pos) + 6 * interval;

            isWarn_pos = false;
            isAlarm_pos = true;
        }

        if(pradius > 9*interval)
        {
            overAlarm = true;
            pradius = 9*interval;
        }

        if(!flag_warningp || !flag_alarmp )
           painter.setBrush(BRUSH_10);

        painter.drawEllipse(-pradius,-pradius,2*pradius,2*pradius);

        //箭头
        painter.rotate(Rwind_dir);

        QPolygonF polygon3;

        if(fabs(pos_) < fabs(pre_pos))
        {
            polygon3 << QPointF(0,6*interval)
                  <<QPointF(28,7.5*interval)
                  <<QPointF(16,7.5*interval)
                  <<QPointF(16,9*interval)
                  <<QPointF(-16,9*interval)
                  <<QPointF(-16,7.5*interval)
                  <<QPointF(-28,7.5*interval);
        }
        else if(fabs(pos_) > fabs(pre_pos))
        {
            polygon3 << QPointF(0,9*interval)
                  <<QPointF(28,7.5*interval)
                  <<QPointF(16,7.5*interval)
                  <<QPointF(16,6*interval)
                  <<QPointF(-16,6*interval)
                  <<QPointF(-16,7.5*interval)
                  <<QPointF(-28,7.5*interval);
        }

        if(fabs(pos_) < Warning_pos)
        {
            painter.setBrush(BRUSH_5);
        }
        else
        {
            painter.setBrush(BRUSH_2);
            if(pos_ > pre_pos) alarm_increase = true;
        }
        painter.setPen(Qt::NoPen);
        painter.drawPolygon(polygon3, Qt::WindingFill);

        pre_pos = pos_;
        painter.rotate(-Rwind_dir);

        painter.setPen(pen);
        painter.setFont(FONT_9);
        painter.drawText(-width/2 + 30,- height/2 + llHeight + 20,positionStr);
        painter.setPen(pen2);
        painter.setFont(FONT_2);
        painter.drawText(-width/2 + 100,- height/2 + llHeight + 20,danwei_mi);//"米"



//        painter.drawLine(0,0,width/2 - 20, - height/2 + llHeight);
//        painter.setPen(pen);
        painter.setFont(FONT_13);
        painter.setPen(pen);

        if(alarm_increase)
            painter.drawText(QRect(-40,-40,80,80),Qt::AlignCenter,"+");

        painter.setFont(FONT_10);

        painter.setBrush(Qt::NoBrush);
        float a = heading;
        QPoint point;
        QRect rect;
        point = getPoint(a, interval);

        painter.setPen(pen);

        rect = QRect(point.x() - interval,point.y() - interval,2*interval,2*interval);
    //    painter.drawRect(rect);

        painter.drawText(rect,Qt::AlignTop | Qt::AlignHCenter,"S");
        //painter.drawRect(QRect(point.x(),point.y(),2*interval,2*interval));
        //painter.drawLine(0,0,point.x(),point.y());
        a += 90;
        point = getPoint(a, interval);
        rect = QRect(point.x()-interval,point.y()-interval ,2*interval,2*interval);
        painter.drawText(rect,Qt::AlignTop | Qt::AlignHCenter,"E");
    //    painter.drawLine(0,0,point.x(),point.y());
    //    painter.drawRect(rect);


//        painter.setPen(pen6);
//        painter.drawPoint(0 ,0);

//        painter.setPen(pen);

        //painter.drawLine(0,0,point.x(),point.y());
        a += 90;
        point = getPoint(a, interval);
        rect = QRect(point.x() - interval,point.y() - interval,2*interval,2*interval);
//        painter.drawRect(rect);
        painter.drawText(rect,Qt::AlignTop | Qt::AlignHCenter,"N");
        if(!overAlarm)
            painter.setPen(pen15);
        painter.drawLine(0,0,sin(a *3.14159265/180)*9*interval,cos(a *3.14159265/180) * 9 * interval);
        a += 90;
        painter.setPen(pen);
        point = getPoint(a, interval);

        rect = QRect(point.x() - interval,point.y() - interval,2*interval,2*interval);
        painter.drawText(rect,Qt::AlignTop | Qt::AlignHCenter,"W");
    }
//--------------------------------------------自动舵模式下的位置区--------------------------------------
    else if(Operate_mode == AUTOPLT_MODE)
    {        
        painter.drawRect(QRect(-rectW,-10*interval,2*rectW,8*interval));//上
        painter.drawRect(QRect(-rectW,2*interval,2*rectW,8*interval));//下


//        画十字型
        painter.setPen(pen2);
        painter.drawLine(0,-interval*10 ,0,interval*10);

//        画刻度
        for(int i=1; i<= 10; i++){
            painter.drawLine(-1,i*interval,1,i*interval);//y +
            painter.drawLine(-1,-i*interval,1,-i*interval);// y-
        }

//        cmd_Fy = -cmd_Fy;
//        fbk_Fy = - fbk_Fy;

        int cmdfx = rectH * cmd_Fx / MAX_FX;
        int fbkfx = rectH * speed_u / MAX_SPEED;

        if(cmdfx > rectH) cmdfx = rectH;
        if(fbkfx > rectH) fbkfx = rectH;

        int beginX = cmdfx > 0 ? -2*interval : 2*interval;
        painter.setPen(pen3);
        painter.drawLine(-rectW/2,beginX, -rectW/2,beginX-cmdfx);//cmd-fx


        painter.setPen(pen4);
        beginX = speed_u > 0 ? -2*interval : 2*interval;
        painter.drawLine(rectW/2,beginX,rectW/2,beginX-fbkfx);//fbk-fx

        //虚线
        cmdfx = 10 * interval * cmd_Fx / MAX_FX;

        painter.setPen(pen5);

        //点 位置
        int pointX = -cmdfx;

        if(fabs(pointX) > 10 * interval)
        {
           pointX = pointX >0 ? -10 * interval : 10*interval;
        }

        painter.setPen(pen6);
        painter.drawPoint(0,pointX);
         /*数值显示 区域*/
         int rectWidth = 60;
         int rectHeight = 26;
//         int rectX = rectW;
         int rectY = rectW;


         if(cmd_Fx > 0)
         {
             rectY = -10 * interval;
         }
         else
         {
           rectY  =  10 * interval - rectHeight;
         }

         QRect recthor(rectW+2,rectY,rectWidth,rectHeight);

         painter.setPen(pen);
         painter.setFont(FONT_9);

         painter.drawText(recthor,Qt::AlignCenter,QString::number(cmd_Fx*13.0/MAX_FX,'f',1));
         painter.setPen(pen2);
         painter.setFont(FONT_1);
         painter.drawText(QRect(recthor.x()+recthor.width(),recthor.y(),10,recthor.height()) , Qt::AlignVCenter | Qt::AlignLeft ,danwei_jie);//"速度"

    }
    /*----------------------------------手操模式--------------------------------------*/
    else
    {
        painter.drawRect(QRect(-rectW,-10*interval,2*rectW,rectH));//上
        painter.drawRect(QRect(-rectW,2*interval,2*rectW,rectH));//下
        painter.drawRect(QRect(-10*interval,-rectW,rectH,2*rectW));//左
        painter.drawRect(QRect(2*interval,-rectW,rectH,2*rectW));//右

        painter.setBrush(Qt::NoBrush);
        //画十字型
        painter.drawLine(0,-interval*10 ,0,interval*10);
        painter.drawLine(-10 * interval,0, 10*interval,0);

        //画刻度
        for(int i=1; i<= 10; i++){
            painter.drawLine(i * interval,1,i * interval,-1);//x +
            painter.drawLine(-i * interval,1,-i * interval,-1);// x-
            painter.drawLine(-1,i*interval,1,i*interval);//y +
            painter.drawLine(-1,-i*interval,1,-i*interval);// y-
        }


        int cmdfx = rectH * cmd_Fx / MAX_FX;
        int fbkfx = rectH * fbk_Fx / MAX_FX;
        int cmdfy = rectH * cmd_Fy / MAX_FY;
        int fbkfy = rectH * fbk_Fy / MAX_FY;
        //qDebug()<<"PositionWidget::paintEvent.0"<<rectH<<cmd_Fx<<MAX_FX;
        //qDebug()<<"PositionWidget::paintEvent.1"<<rectH<<cmd_Fy<<MAX_FY;
        //qDebug()<<"PositionWidget::paintEvent.2"<<cmdfx<<fbkfx<<cmdfy<<fbkfy;

        int beginX = cmdfx > 0 ? -2*interval : 2*interval;
        int beginY = cmdfy > 0 ? 2*interval : -2*interval;
        painter.setPen(pen3);
        painter.drawLine(-rectW/2,beginX, -rectW/2,beginX-cmdfx);//cmd-fx
        painter.drawLine(beginY ,-rectW/2, beginY + cmdfy,-rectW/2);//cmd-fy

        painter.setPen(pen4);
        beginX = fbkfx > 0 ? -2*interval : 2*interval;
        beginY = fbkfy > 0 ? 2*interval : -2*interval;
        painter.drawLine(rectW/2,beginX,rectW/2,beginX-fbkfx);//fbk-fx
        painter.drawLine(beginY, rectW/2,beginY + fbkfy,rectW/2);//fbk-fy

        //虚线

        cmdfx = 10 * interval * cmd_Fx / MAX_FX;
        cmdfy = 10 * interval * cmd_Fy / MAX_FY;

        painter.setPen(pen5);
        if(!(cmd_Fx == 0 && cmd_Fy ==0))
        {
            painter.drawLine(-rectW,-cmdfx,cmdfy,-cmdfx);
            painter.drawLine(cmdfy,0,cmdfy,-cmdfx);
        }
        //点 位置
        int pointX = cmdfy;
        int pointY = -cmdfx;

        if(fabs(pointX) > 10 * interval)
        {
           pointX = pointX >0 ? 10 * interval : -10*interval;
        }

        if(fabs(pointY) > 10 * interval)
        {
           pointY =  pointY >0 ? 10 * interval : -10*interval;
        }

        painter.setPen(pen6);
        painter.drawPoint(pointX ,pointY);

        /*数值显示 区域*/
//        int rectX = rectW;
//        int rectY = rectW;
        int rectWidth = 65;
        int rectHeight = 35;

        QRect rectver;//纵轴
        QRect recthor;//横轴


        if(cmd_Fx > 0)
        {
            rectver =QRect(rectW,-10*interval,rectWidth,rectHeight);
        }
        else if(cmd_Fx <0)
        {
            rectver =QRect(rectW,10*interval-rectHeight,rectWidth,rectHeight);
        }

        if(cmd_Fy > 0)
        {
            recthor = QRect(10*interval - rectWidth,rectW,rectWidth,rectHeight);
        }
        else if(cmd_Fy <0)
        {
            recthor = QRect(-10*interval,rectW,rectWidth,rectHeight);
        }

        painter.setPen(pen);
        painter.setFont(FONT_9);


//        painter.drawRect(rectver);
//        painter.drawRect(recthor);

        painter.drawText(rectver,Qt::AlignTop,QString::number(fbk_Fx*100/MAX_FX,'f',0) +'%');
        painter.drawText(recthor,Qt::AlignTop,QString::number(fbk_Fy*100/MAX_FY,'f',0) +'%');

        painter.setPen(pen2);
        painter.setFont(FONT_1);
        if(cmd_Fx > 0)
            painter.drawText(rectver,Qt::AlignBottom | Qt::AlignRight,str_chuanshou);//"船艏"
        else if(cmd_Fx < 0)
            painter.drawText(rectver,Qt::AlignBottom | Qt::AlignRight,str_chuanwei);//"船艉"

        if(cmd_Fy > 0)
            painter.drawText(recthor,Qt::AlignBottom | Qt::AlignRight,str_youxian);//"右舷"
        else if(cmd_Fy < 0)
            painter.drawText(recthor,Qt::AlignBottom | Qt::AlignRight,str_zuoxian);//"左舷"
    }
}

QPoint PositionWidget::getPoint(float a, int interval)
{
    int x = 0;
    int y = 0;

//    float x1 = sin(a *3.14159265/180) * 1000;
//    float y1 = cos(a *3.14159265/180) * 1000;

//    QString sss = QString::number(x1,'f',0);

//    int x2 = QString::number(x1,'f',1).toInt();
//    int y2 = y1;


    x =  sin(a *3.14159265/180)* 10 * interval;
    y =  cos(a *3.14159265/180) * 10 *interval;


    return QPoint(x,y);
}
