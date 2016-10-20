#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "headWidget.h"

HeadWidget::HeadWidget(QWidget *parent, QRect headRect)
    :QWidget(parent,Qt::FramelessWindowHint){

//    this->setAutoFillBackground(true);
    this->setGeometry(headRect.x(),  headRect.y(), headRect.width(),headRect.height());

}

void HeadWidget::refreshData(){
//    Operate_mode = READY_MODE;
    update();
}

//白天、夜晚模式切换
void HeadWidget::changeDNMode()
{

}

void HeadWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    int width = this->geometry().width();
    int height = this->geometry().height();


    //移动坐标系,使得坐标原点在label的下方中间
    painter.translate(width / 2, height);

    /*上端刻度*/
    int r1 = 3*width/2;
    int interval1 = 10;

    /*下端偏差条*/
    int r2 = width;//外圆弧半径
    int interval2 = 30;//外圆弧 - 内圆弧 间隔

    QPen pen1;//线条Pen
    QPen pen2;//设定进度条
    QPen pen3;//反馈进度条
    QPen pen4;//黑字体
    QPen pen5;
    QPen pen6;//艏向 指示线


    if(daynight_mode == DAYMODE)
    {
        pen1 = PEN_1;
        pen2 = PEN_7;
        pen3 = PEN_8;
        pen4 = PEN_2;
        pen5 = PEN_9;
        pen6 = PEN_18;
    }
    else
    {
        pen1 = PEN_1_1;
        pen2 = PEN_7;
        pen3 = PEN_8;
        pen4 = PEN_1_1;
        pen5 = PEN_9;
        pen6 = PEN_18;
    }

    pen2.setWidth(interval2/2);
    pen3.setWidth(interval2/2);


    /*============上端==============*/
    painter.setPen(pen1);

    /*上端 弧*/
    QRectF rectangle(-r1,-height +30 ,2*r1,2*r1);
    int startAngle = 70 * 16;
    int spanAngle = 40 * 16;
    painter.drawArc(rectangle,startAngle, spanAngle);

    QRectF rectangle2(-r1,-height + 30 + interval1 ,2*r1,2*r1);
    painter.drawEllipse(rectangle2);

    //艏向位置、回转率
    float speedR = speed_r * 60.0;//原来是度每秒，转换为度每分钟
    if((speedR > -0.1 && speedR < 0) || (speedR > 0 && speedR < 0.1))
        speedR = 0;


    painter.setPen(pen1);
    painter.setFont(FONT_3);
    painter.drawText(-85 - 40, - height*2/3 + 85,str_huizhuanlv);//"回转率"
    painter.setFont(FONT_3);
    painter.drawText(50,- height*2/3 + 85,danwei_dufen );//"°/分"
    if(speedR>0)
        painter.drawText(50,- height*2/3 + 105, str_youxian);//"右舷"
    else if(speedR < 0 )
        painter.drawText(50,- height*2/3 + 105,str_zuoxian);//"左舷"

    painter.setPen(pen4);
    painter.setFont(FONT_11);

    painter.setBrush(Qt::NoBrush);

    painter.drawText(-60,- height*2/3 - 15 + 90 ,120,30,Qt::AlignCenter,QString::number(speedR,'f',1));

    painter.setFont(FONT_12);
    painter.drawText(-190,- height*2/3 - 60 + 50 ,400,80,Qt::AlignCenter, QString::number(heading,'f',1 )+"  °");


    //画船只的转弯方向
     painter.setPen(pen1);
     //painter.setFont(FONT_1);

     painter.drawLine(0,0,600,600);

    // 上方,左右方向三角形
    QPolygonF polygonL;
    polygonL << QPointF(-90, -height + 75) << QPointF(-30, -height + 60) << QPointF(-30,-height + 90) ;

    if(speedR < 0)
    {
        painter.setBrush(BRUSH_2);
    }
    else
    {
        painter.setBrush(Qt::NoBrush);
    }
    painter.drawPolygon(polygonL, Qt::WindingFill);

    QPolygonF polygonR;
    polygonR << QPointF(90, -height + 75) << QPointF(30, -height + 60) << QPointF(30,-height + 90) ;
    if(speedR > 0 )
    {
        painter.setBrush(BRUSH_1);
    }
    else
    {
        painter.setBrush(Qt::NoBrush);
    }
    painter.drawPolygon(polygonR, Qt::WindingFill);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(pen1);
    painter.drawLine(0,-height + 30 + interval1,0,-height);

    /*===========下端扇形回转力区域============*/

    /*联合操作杆模式下自动艏向控制*/
    if(Operate_mode == HEADING_MODE || Operate_mode == KEEPXD_MODE || Operate_mode == KEEPYD_MODE || Operate_mode == KEEPPOS_MODE)
    {
        int uh = height/4-40; // 矩形区域高度,宽度
        int uw = width - 40;
        QRectF rectangle8(-width/2+20,-height/4, uw, uh );
        painter.drawRect(rectangle8);

        painter.drawLine(0,-height/4 + 2*uh/5,0,-height/4 + uh - 2 );

        pen5.setColor(COLOR_17);
        painter.setPen(pen5);
        painter.drawLine(-uw/8,-height/4 + 2*uh/5,-uw/8,-height/4 + uh -2);
        painter.drawLine(uw/8,-height/4 + 2*uh/5,uw/8,-height/4 + uh -2);
        pen5.setColor(COLOR_18);
        painter.setPen(pen5);
        painter.drawLine(-3*uw/8,-height/4 + 2*uh/5,-3*uw/8,-height/4 + uh -2);
        painter.drawLine(3*uw/8,-height/4 + 2*uh/5,3*uw/8,-height/4 + uh -2);

        //painter.drawLine(0,0,0,-900);

        pen5.setWidth(uh/2);
        painter.setPen(pen5);
        painter.setFont(FONT_3);

//        heading = -heading;
        float max_head = Warning_head + Alarm_head;
        //数据
        float len = 0; //计算长度

        float offsetHeading = heading -set_heading;

        if(fabs(offsetHeading) > 180)
        {
            offsetHeading = 360 -fabs(offsetHeading);
            offsetHeading = - offsetHeading;
        }

        bool havealarm = false;//是否警告
        bool alarmincrease = false;//是否警告 且 持续增加


        pen5.setColor(Qt::white);
        if(fabs(offsetHeading) <Warning_head && Warning_head>0)
        {
            len = uw/8 * fabs(offsetHeading  ) / (Warning_head  );
            pen5.setColor(COLOR_10);

            isWarn_head = false;
            isAlarm_head = false;

        }
        else if(fabs(offsetHeading) < Alarm_head && Alarm_head > Warning_head)
        {
            len = uw/4 * (fabs(offsetHeading ) - Warning_head) / (Alarm_head - Warning_head) + uw/8;
            pen5.setColor(COLOR_17);
            havealarm = true;

            isWarn_head = true;
            isAlarm_head = false;
        }
        else if(fabs(offsetHeading) >= Alarm_head && Alarm_head > 0)
        {
            len = uw/8 * (fabs(offsetHeading ) - Alarm_head) / (max_head - Alarm_head)+ 3*uw/8;

            pen5.setColor(COLOR_18);
            havealarm = true;
            if(fabs(heading) > fabs(preHeading)) alarmincrease = true;

            isWarn_head = false;
            isAlarm_head = true;
        }
        if(len > uw/2) len = uw/2;

        painter.setPen(pen5);
        if(offsetHeading > 0)
        {
            painter.drawLine(0,-height/4 + 1*uh/2 + 1*uh/4, len,-height/4 + 1*uh/2 + 1*uh/4);
        }
        else if(offsetHeading < 0)
        {
            painter.drawLine(0,-height/4 + 1*uh/2 + 1*uh/4, -len,-height/4 + 1*uh/2 + 1*uh/4);
        }


        pen5.setColor(Qt::white);
        pen5.setWidth(1);
        painter.setPen(pen5);
        painter.setFont(FONT_11);
        if(alarmincrease)
        {
            if(offsetHeading > 0)
                painter.drawText(QRect( 0,-height/4 + 2*uh/5 + 3, len, 2*uh/5) ,Qt::AlignRight  | Qt::AlignVCenter ," + ");
            else if(offsetHeading < 0)
                painter.drawText(QRect(-len,-height/4 + 2*uh/5 + 3, len, 2*uh/5) ,Qt::AlignLeft | Qt::AlignVCenter ," + ");
        }
        painter.setFont(FONT_3);
        painter.setPen(pen4);

        if(offsetHeading > -0.1 && offsetHeading < 0)
            offsetHeading = 0;

        painter.setFont(FONT_9);
        //偏差值
        painter.drawText(QRect(-uw/8,-height/4,uw/4,2*uh/5),Qt::AlignCenter,QString::number((offsetHeading),'f',1));

        pen5.setColor(Qt::white);
        painter.setPen(pen5);

        painter.setBrush(BRUSH_2);
        painter.setPen(pen1);

        QPolygonF polygon8;

        float increase = heading -preHeading;

        if(fabs(increase) > 180)
        {
            increase = - increase;
        }

        if(offsetHeading > 0)
        {
            if(increase > 0)
            {
                 polygon8 << QPointF(3*uw/8 +10, -height/4 + uh/5)

                            <<QPointF(3*uw/8 -6, -height/4 + uh/5 + 9 )

                            <<QPointF(3*uw/8 -6, -height/4 + uh/5 + 5)

                            <<QPointF(3*uw/8 - 18, -height/4 + uh/5 + 5)

                            <<QPointF(3*uw/8 - 18, -height/4 + uh/5 - 5 )

                            <<QPointF(3*uw/8 - 6, -height/4 + uh/5 -5 )

                            <<QPointF(3*uw/8 -6, -height/4 + uh/5 - 9);
            }
            else if(increase < 0)
            {
                            polygon8 << QPointF(3*uw/8 - 18, -height/4 + uh/5)

                                <<QPointF(3*uw/8 -2, -height/4 + uh/5 + 9 )

                                <<QPointF(3*uw/8 -2, -height/4 + uh/5 + 5)

                                <<QPointF(3*uw/8 + 10, -height/4 + uh/5 + 5)

                                <<QPointF(3*uw/8 + 10, -height/4 + uh/5 - 5 )

                                <<QPointF(3*uw/8 -2, -height/4 + uh/5 -5 )

                                <<QPointF(3*uw/8 -2, -height/4 + uh/5 - 9);
            }
        }
        else if(offsetHeading < 0)
        {
            if(increase > 0)
            {
                         polygon8 << QPointF(-3*uw/8 + 18, -height/4 + uh/5)

                                    <<QPointF(-3*uw/8 + 2, -height/4 + uh/5 + 9 )

                                    <<QPointF(-3*uw/8 +2, -height/4 + uh/5 + 5)

                                    <<QPointF(-3*uw/8 - 10, -height/4 + uh/5 + 5)

                                    <<QPointF(-3*uw/8 - 10, -height/4 + uh/5 - 5 )

                                    <<QPointF(-3*uw/8 + 2, -height/4 + uh/5 -5 )

                                    <<QPointF(-3*uw/8 + 2, -height/4 + uh/5 - 9);
            }
            else if(increase < 0)
            {
                polygon8 << QPointF(-3*uw/8 -10, -height/4 + uh/5)

                           <<QPointF(-3*uw/8 +6, -height/4 + uh/5 + 9 )

                           <<QPointF(-3*uw/8 +6, -height/4 + uh/5 + 5)

                           <<QPointF(-3*uw/8 + 18, -height/4 + uh/5 + 5)

                           <<QPointF(-3*uw/8 + 18, -height/4 + uh/5 - 5 )

                           <<QPointF(-3*uw/8 +6, -height/4 + uh/5 -5 )

                           <<QPointF(-3*uw/8 +6, -height/4 + uh/5 - 9);
            }
        }

        preHeading = heading;

        if(havealarm)
        {
              painter.setBrush(BRUSH_2);
        }
        else
        {
            painter.setBrush(BRUSH_1);
        }

        painter.drawPolygon(polygon8, Qt::WindingFill);
    }
    //-------------------------------------自动舵---------------------------------------------
    else if(Operate_mode == AUTOPLT_MODE)
    {
        painter.translate(-width/4,0);
        painter.rotate(180);

        int bth = 40;//下端数字所占高度
        //左
        int r3 = (width/2) /2 ;
        QRectF rectangle3(-width/4 ,bth,2*r3,2*r3);

        int startAngle3 = 30;
        int spanAngle3 = 120;
        painter.drawArc(rectangle3, startAngle3 * 16, spanAngle3 * 16);

        int r4 = (width/2 - 2*interval1)/2;
        QRectF rectangle4(-width/4  +interval1,bth+interval1,2*r4,2*r4);
        int startAngle4 = 30;
        int spanAngle4= 120;
        painter.drawArc(rectangle4, startAngle4 * 16 , spanAngle4 * 16);

        int r5 = (width/2 - 4*interval1)/2;

        QRectF rectangle5(-width/4  + 2 *interval1, bth + 2 * interval1,2*r5,2*r5);
        int startAngle5 = 30;
        int spanAngle5= 120 ;
        painter.drawArc(rectangle5,startAngle5 * 16 , spanAngle5 * 16);

        /*下端弧 左右中 边界线 中心轴 在width/4 右偏10位置*/
        painter.drawLine(sin((90-startAngle3) *3.14159265/180)* r3 ,
                         bth + (1-cos((90-startAngle3)*3.14159265/180))* r3 ,
                               sin((90-startAngle5)*3.14159265/180)* r5
                               , bth + 2 * interval1  +(1-cos((90-startAngle5)*3.14159265/180))* r5);

        painter.drawLine(-sin((90-startAngle3) *3.14159265/180)* r3 ,
                         bth + (1-cos((90-startAngle3)*3.14159265/180))* r3 ,
                               -sin((90-startAngle5)*3.14159265/180)* r5, bth + 2 * interval1  +(1-cos((90-startAngle5)*3.14159265/180))* r5);

        painter.drawLine(0,bth,0, bth + 2 *interval1);

        painter.setPen(pen1);
        painter.translate(0,bth + r3);

        //画刻度
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        pen1.setWidth(2);
        painter.setPen(pen1);
        painter.drawLine(0,-r5 + 10,0,-r5);
        painter.rotate(-50);
        pen1.setWidth(1);
        painter.setPen(pen1);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(-10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(-10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(-10);
        pen1.setWidth(2);
        painter.setPen(pen1);
        painter.drawLine(0,-r5 + 10,0,-r5);
        painter.rotate(40);

        painter.translate(0,-bth - r3);

        /*双指示条*/
        pen2.setWidth(interval1);
        pen3.setWidth(interval1-1);




        painter.setPen(pen2);

        QRectF rectangle6(-width/4 + interval1/2,bth + interval1/2,2*(r3 - interval1/2 ),2*(r3 - interval1/2) );
        int startAngle6;
        int spanAngle6 =fabs(cmd_f4) * 40 / max_rudangle;/*最大跨度 50*/

         if(cmd_f4 > 0)
         {
             startAngle6 = 90;
             painter.drawArc(rectangle6,startAngle6*16,spanAngle6*16 );
         }
         else
         {
             startAngle6 = 90 - spanAngle6;
             painter.drawArc(rectangle6,startAngle6*16,spanAngle6*16 );
         }


         painter.setPen(pen3);
         QRectF rectangle7(-width/4 + 3*interval1/2, bth + 3 * interval1/2,2*(r5 + interval1/2),2*(r5 + interval1/2));

         int startAngle7;
         int spanAngle7 = fabs(fbk_f5) * 40 / max_rudangle;/*最大跨度 50*/

          if(fbk_f4 > 0)
          {
              startAngle7 = 90;
              painter.drawArc(rectangle7,startAngle7*16,spanAngle7*16 );
          }
          else
          {
              startAngle7 = 90 - spanAngle7;
              painter.drawArc(rectangle7,startAngle7*16,spanAngle7*16 );
          }


        //右
        pen1.setWidth(1);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(pen1);

        painter.translate(-width/2,0);

        QRectF rectangle3_2(-width/4,bth,2*r3,2*r3);

        int startAngle3_2 = 30;
        int spanAngle3_2 = 120;
//        painter.drawRect(rectangle3_2);
        painter.drawArc(rectangle3_2, startAngle3_2 * 16, spanAngle3_2 * 16);

        QRectF rectangle4_2(-width/4 +interval1,bth+interval1,2*r4,2*r4);
        int startAngle4_2 = 30;
        int spanAngle4_2 = 120;
        painter.drawArc(rectangle4_2, startAngle4_2 * 16 , spanAngle4_2 * 16);

        QRectF rectangle5_2(-width/4 + 2 *interval1, bth + 2 * interval1,2*r5,2*r5);
        int startAngle5_2 = 30;
        int spanAngle5_2= 120 ;
        painter.drawArc(rectangle5_2,startAngle5_2 * 16 , spanAngle5_2 * 16);


        /*下端弧 左右中 边界线*/
        painter.drawLine(sin((90-startAngle3_2) *3.14159265/180)* r3 ,
                         bth + (1-cos((90-startAngle3_2)*3.14159265/180))* r3 ,
                               sin((90-startAngle5_2)*3.14159265/180)* r5, bth + 2 * interval1  +(1-cos((90-startAngle5_2)*3.14159265/180))* r5);

        painter.drawLine(-sin((90-startAngle3_2) *3.14159265/180)* r3 ,
                         bth + (1-cos((90-startAngle3_2)*3.14159265/180))* r3 ,
                               -sin((90-startAngle5_2)*3.14159265/180)* r5, bth + 2 * interval1  +(1-cos((90-startAngle5_2)*3.14159265/180))* r5);


        painter.drawLine(0,bth,0, bth + 2 *interval1);

        pen1.setWidth(1);
        painter.setPen(pen1);
        painter.translate(0,bth + r3);

        //画刻度
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(10);
        pen1.setWidth(2);
        painter.setPen(pen1);
        painter.drawLine(0,-r5 + 10,0,-r5);
        painter.rotate(-50);
        pen1.setWidth(1);
        painter.setPen(pen1);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(-10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(-10);
        painter.drawLine(0,-r5 + 5,0,-r5);
        painter.rotate(-10);
        pen1.setWidth(2);
        painter.setPen(pen1);
        painter.drawLine(0,-r5 + 10,0,-r5);
        painter.rotate(40);

        painter.translate(0,-bth - r3);


        /*双指示条*/

        painter.setPen(pen2);

        QRectF rectangle6_2(-width/4 + interval1/2,bth + interval1/2,2*(r3 - interval1/2 ),2*(r3 - interval1/2) );
        int startAngle6_2;
        int spanAngle6_2 =fabs(cmd_f5) * 40 / max_rudangle;/*最大跨度 50*/

         if(cmd_f5 > 0)
         {
             startAngle6_2 = 90;
             painter.drawArc(rectangle6_2,startAngle6_2*16,spanAngle6_2*16 );
         }
         else
         {
             startAngle6_2 = 90 - spanAngle6_2;
             painter.drawArc(rectangle6_2,startAngle6_2*16,spanAngle6_2*16 );
         }

        painter.setPen(pen3);
        QRectF rectangle7_2(-width/4 + 3*interval1/2, bth + 3 * interval1/2,2*(r5 + interval1/2),2*(r5 + interval1/2));

        int startAngle7_2;
        int spanAngle7_2 = fabs(fbk_f5) * 40 / max_rudangle;/*最大跨度 50*/

         if(fbk_f5 > 0)
         {
             startAngle7_2 = 90;
             painter.drawArc(rectangle7_2,startAngle7_2*16,spanAngle7_2*16 );
         }
         else
         {
             startAngle7_2 = 90 - spanAngle7_2;
             painter.drawArc(rectangle7_2,startAngle7_2*16,spanAngle7_2*16 );
         }

         painter.translate(width/4,0);
         painter.rotate(-180);

         painter.setFont(FONT_3);
         painter.setPen(pen1);

        painter.drawText(-90,-height*1/4 + interval2 + 40,str_duojiao);//"舵角"
        painter.setPen(pen4);
        painter.setFont(FONT_9);
        painter.drawText(QRect(-40,-height*1/4 + interval2 + 14,80,40),Qt::AlignCenter,QString::number(fbk_f4,'f',0)+"°");

        painter.setFont(FONT_7);
        painter.setPen(pen1);
        painter.drawText(50,-height*1/4 + interval2 + 40,str_youxian);//"右舷"

    }
    else
    {
        /*下端 弧 外 中 内*/
        QRectF rectangle3(-r2,-height*1/4,2*r2,2*r2);
        int startAngle3 = 65;
        int spanAngle3 = 50;
        painter.drawArc(rectangle3, startAngle3 * 16, spanAngle3 * 16);

        QRectF rectangle4(-r2,-height*1/4 +interval2 ,2*r2,2*r2);
        int startAngle4 = 67;
        int spanAngle4= 46;
        painter.drawArc(rectangle4, startAngle4 * 16 , spanAngle4 * 16);

        QRectF rectangle7(-r2,-height*1/4 +interval2/2 ,2*r2,2*r2);
        int startAngle8 = 66;
        int spanAngle8= 48;
        painter.drawArc(rectangle7,startAngle8 * 16 , spanAngle8 * 16);

        /*下端弧 左右中 边界线*/
        painter.drawLine(-sin((90 -startAngle3)*3.14159265/180)* r2, -height*1/4 + (1-cos((90 -startAngle3)*3.14159265/180))* r2 ,
                               -sin((90 -startAngle4)*3.14159265/180)* r2, -height*1/4 + interval2 + (1-cos((90 -startAngle4)*3.14159265/180))* r2 );

        painter.drawLine(sin((90 -startAngle3)*3.14159265/180)* r2, -height*1/4 + (1-cos((90 -startAngle3)*3.14159265/180))* r2 ,
                               sin((90 -startAngle4)*3.14159265/180)* r2, -height*1/4 + interval2 + (1-cos((90 -startAngle4)*3.14159265/180))* r2 );

        painter.drawLine(0,-height*1/4,0,-height*1/4+interval2);

        /*双指示条*/
        painter.setPen(pen2);
        float startAngle6;
        float spanAngle6;//24.6*16;

        QRectF rectangle6(-r2 ,-height*1/4 + interval2/4 ,2*r2,2*r2);

        spanAngle6 = fabs(cmd_Nz) * 24.68 / MAX_NZ;/*最大跨度 25*/

         if(cmd_Nz < 0)
         {
             startAngle6 = 90;

             painter.drawArc(rectangle6,startAngle6*16,spanAngle6*16 );
         }
         else if(cmd_Nz > 0)
         {
             startAngle6 = 90 - spanAngle6;
             painter.drawArc(rectangle6,startAngle6*16,spanAngle6*16 );
         }

        float startAngle7 ;
        float spanAngle7 ;//

        painter.setPen(pen3);
        QRectF rectangle8(-r2 ,-height*1/4 + interval2 * 3/4 ,2*r2,2*r2);

        spanAngle7 = fabs(fbk_Nz) * 23.40 / MAX_NZ;/*最大跨度 23.40*/

         if(fbk_Nz < 0)
         {
             startAngle7 = 90;
             painter.drawArc(rectangle8,startAngle7*16,spanAngle7*16 );
         }
         else if(fbk_Nz > 0)
         {
             startAngle7 = 90 - spanAngle7;
             painter.drawArc(rectangle8,startAngle7*16,spanAngle7*16 );
         }


        painter.setFont(FONT_9);
        painter.setPen(pen4);

        painter.drawText(QRect(-40,-height*1/4 + interval2 ,80,40),Qt::AlignCenter,QString::number(fbk_Nz * 100.0 / MAX_NZ,'f',0)+"%");
        painter.setPen(pen1);
        painter.setFont(FONT_2);
        if(fbk_Nz > 0)
            painter.drawText(40,-height*1/4 + interval2 + 30, str_youxian);//"右舷"
        else if(fbk_Nz < 0)
            painter.drawText(40,-height*1/4 + interval2 + 30, str_zuoxian);//"左舷"


        //联合操作杆的旋转方向

        //将坐标系原点 转换到外圈圆心
        painter.translate( 0, r2 - height/4);
        //往右偏转(90 -startAngle) / 2 度
//        painter.rotate((90 -startAngle3) / 2);

        int rotateAng = 0;

        //小三角形转弯方向指示
        QPolygonF polygon;


        if(cmd_Nz > 5000 || cmd_Nz < -5000.0){
            if(cmd_Nz > 0)
            {
                rotateAng = 15;
            }
            else if( cmd_Nz < -0 )
            {
                rotateAng = -15;
            }

            painter.rotate(rotateAng);

            polygon << QPointF(0 ,-r2 - 12)
                    << QPointF(-8, -r2 + 10) << QPointF(8, -r2 + 10) ;

            painter.setBrush(BRUSH_8);
            painter.setPen(pen1);
            painter.drawPolygon(polygon, Qt::WindingFill);
        }

        //还原坐标系
        painter.rotate(-rotateAng);
        painter.translate(0,-r2 + height/4);
    }

    /*上端刻度*/

    //移动坐标系,使得坐标原点移动到顶圆的圆心
    painter.translate( 0, -height +r1 + 30);

    /*用画笔3,画表盘刻度*/
    painter.setPen(pen1);
    painter.setFont(FONT_1);

    /*刻度表 半弧度*/
    double angle = 180/ (3.14159265 / asin( (width/2)* 1.0/r1));

    double a = 2 * angle / 13.0; //逆时针方向旋转坐标系统a度

    painter.rotate(angle - 90 -a/2);

    int begin = heading*10 + (6 * 2.5 * 10);//半边 为15个刻度

    if(begin > 3600) begin -= 3600;

    int remainder = (begin % 25);//第一个刻度 开始的偏转角度  10 度 4 刻度

    painter.rotate(-remainder * a / 25.0);

    if(remainder > 0)
        begin -= remainder;

    for (int i = 0; i < 13; i++) {

        if(begin < 0)
            begin += 3600;

        if(begin % 100 == 0){
            painter.drawLine(r1, 0, r1+ 8, 0);

            painter.rotate(90);

            if(begin== 0)
                painter.drawText(-5,-r1-10, QString("%1").arg("N"));
            else if(begin == 900)
                painter.drawText(-5,-r1-10, QString("%1").arg("E"));
            else if(begin == 1800)
                painter.drawText(-5,-r1-10, QString("%1").arg("S"));
            else if(begin == 2700)
                painter.drawText(-5,-r1-10, QString("%1").arg("W"));
            else{
                painter.drawText(-5,-r1-10, QString("%1").arg(begin/10.0));
            }
            painter.rotate(-90);

        }else if(begin % 50 == 0)
             painter.drawLine(r1, 0, r1+ 5, 0);
        else
            painter.drawLine(r1, 0, r1+ 3, 0);


        if((begin - 25)/10.0 < set_heading)
        {
            painter.setPen(pen6);
            painter.rotate((-begin + set_heading*10) * a / 25.0);
            painter.drawLine(r1, 0, r1+ 10, 0);
            painter.rotate((begin - set_heading*10 - 25) * a/25.0);
            painter.setPen(pen1);
        }
        else
        {
            painter.rotate(-a);
        }

        begin -= 25;
     }
}
