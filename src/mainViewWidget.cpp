#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "MainViewWidget.h"

MainViewWidget::MainViewWidget(QWidget *parent,QRect viewAreaRect)
    : QWidget(parent, Qt::FramelessWindowHint){

    this->setAutoFillBackground(true);
    QPalette p;
    p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_9)));//"images/主视图区-日.png"
    this->setPalette(p);

    this->setGeometry(viewAreaRect.x()+1,  viewAreaRect.y()+1, viewAreaRect.width()-1,viewAreaRect.height() -2);
}

/*刷新数据*/
void MainViewWidget::refreshData()
{
    update();
}

//白天、夜晚模式切换
void MainViewWidget::changeDNMode(){
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_9)));//"images/主视图区-日.png"
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_9)));//"images/主视图区-夜.png"

    }
    this->setPalette(p);
}

void MainViewWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;//灰色
    QPen pen2;//淡黑色
    QPen pen3;//风向区 红色边线
    QPen pen4;// 风向区 灰色边线
    QPen pen5;

    if(daynight_mode == DAYMODE)
    {
       pen  = PEN_1;
       pen2 = PEN_2;
       pen3 = PEN_4;
       pen4 = PEN_5;
       pen5 = PEN_6;

    }
    else
    {
        pen  = PEN_1_1;
        pen2 = PEN_1_1;
        pen3 = PEN_4;
        pen4 = PEN_1_1;
        pen5 = PEN_1_1;
    }

    int x;
    int y;

    int x1,y1;

/*-----------------左上角:旋回转中心位---------------*/

    QPoint pGyrationCentre(135,70);
    x = pGyrationCentre.x();
    y = pGyrationCentre.y();
    painter.setPen(pen);
    painter.setFont(FONT_3);
    painter.drawText(pGyrationCentre,view1_xuanzhuanzhongxin);
    painter.setPen(pen2);
    painter.setFont(FONT_2);

    x1 = x;
    y1 = y+35;
    painter.drawText(QRect(x1,y1,60,20),view1_juchuanshou,Qt::AlignLeft|Qt::AlignVCenter);//距船首:
    //painter.drawRect(x1,y1,80,20);
    x1 = x;
    y1 = y+55;
    painter.drawText(QRect(x1,y1,60,20),view1_juyouxian,Qt::AlignLeft|Qt::AlignVCenter);//距右舷:


//老程序
//    if(btn_centrepivot == 1)//旋转中心:船舯
    if(fbk_rotateCenter == 0)
    {
//        point_rot = 0;

        x1 = x;
        y1 = y+25;
        painter.drawText(x1,y1,str_chuanzhong);//船中

        painter.setFont(FONT_9);
        //距船艏的值
        x1 = x+75;
        y1 = y+35;
        painter.drawText(QRect(x1,y1,80,20),QString("%1  m").arg(QString::number(SHIP_LEN/2.0,'f',1)),Qt::AlignLeft|Qt::AlignBottom);


        //距右舷的值
        x1 = x+75;
        y1 = y+55;
        painter.drawText(QRect(x1,y1,80,20),QString("%1  m").arg(QString::number(SHIP_WIDTH/2.0,'f',1)),Qt::AlignLeft|Qt::AlignBottom);
    }
    else if(fbk_rotateCenter == 2)//旋转中心:船艉
    {
//        point_rot = 2;
        x1 = x;
        y1 = y+25;
        painter.drawText(x1,y1,str_chuanwei);//船尾


        painter.setFont(FONT_9);
        //距船艏的值
        x1 = x+75;
        y1 = y+35;
        painter.drawText(QRect(x1,y1,80,20),QString("%1  m").arg(QString::number(SHIP_LEN,'f',1)),Qt::AlignLeft|Qt::AlignBottom);

        //距右舷的值
        x1 = x+75;
        y1 = y+55;
        painter.drawText(QRect(x1,y1,80,20),QString("%1  m").arg(QString::number(SHIP_WIDTH/2.0,'f',1)),Qt::AlignLeft|Qt::AlignBottom);
    }
    else if(fbk_rotateCenter == 1)//旋转中心:船艏
    {
//        point_rot = 1;

        x1 = x;
        y1 = y+25;
        painter.drawText(x1,y1,str_chuanshou);//船首


        painter.setFont(FONT_9);
        //距船艏的值
        x1 = x+75;
        y1 = y+35;
        painter.drawText(QRect(x1,y1,80,20),"0.0  m",Qt::AlignLeft|Qt::AlignBottom);

        //距右舷的值
        x1 = x+75;
        y1 = y+55;
        painter.drawText(QRect(x1,y1,80,20),QString("%1  m").arg(QString::number(SHIP_WIDTH/2.0,'f',1)),Qt::AlignLeft|Qt::AlignBottom);
    }

//    y += 20;
//    painter.setPen(pen);
//    QRect rect(x , y,90,25);
//    painter.drawRect(rect);


//    painter.setPen(pen2);
//    painter.setFont(FONT_9);

//    painter.drawText(rect.x() + 20,rect.y(),rect.width()-10,rect.height(),Qt::AlignCenter | Qt::AlignVCenter,"1.1");

//    painter.setPen(pen);
//    painter.setBrush(BRUSH_1);

//    QPolygonF polygon;
//    polygon << QPointF(x+5, rect.y()+5)
//               <<QPointF(x+20,rect.y() + rect.height()/2 )
//               <<QPointF(x + 5,rect.y()+ rect.height() - 5);
//    painter.drawPolygon(polygon, Qt::WindingFill);

    /*-----------------上部中间，状态区---------------*/

    QPoint qStatusArea(380,27);
    int statusAreaW = 170;
    int statusAreaH = 246;
    x = qStatusArea.x();
    y = qStatusArea.y();

    painter.setPen(pen2);
    painter.setFont(FONT_3);

    int ySpace = statusAreaH / 7;

    QRect gyroRect(x, y ,2*statusAreaW/3,ySpace);
    painter.drawText(gyroRect,Qt::AlignRight | Qt::AlignVCenter,sensor_dianluojing);//"电罗径"
    if(State_Gyro == 1)
        painter.setBrush(BRUSH_3);//橙色
    else
        painter.setBrush(BRUSH_11);//绿色

    painter.drawRect(x + 2*statusAreaW/3 + statusAreaW/6 - ySpace/6 , y + (ySpace/2 - ySpace/6 ) ,ySpace/3,ySpace/3);
    y += ySpace;

    QRect gps1Rect(x, y ,2*statusAreaW/3,ySpace);
    painter.drawText(gps1Rect,Qt::AlignRight | Qt::AlignVCenter,sensor_fengsufengxiangyi);//"风速风向仪"
    if(State_Wind == 1)
        painter.setBrush(BRUSH_3);//橙色
    else
        painter.setBrush(BRUSH_11);//绿色
    painter.drawRect(x + 2*statusAreaW/3 + statusAreaW/6 - ySpace/6 , y + (ySpace/2 - ySpace/6 ) ,ySpace/3,ySpace/3);
    y += ySpace;


    /*------------右上角，风力区----------------*/


    //圆点位置
//    QPoint qWindArea(653,111);
    QPoint qWindArea(668,112);
    int r1 = 67;//大圆半径
    int r2 = 52;//小圆半径
    x = qWindArea.x();
    y = qWindArea.y();

    painter.setBrush(Qt::NoBrush);

    //将坐标系原点 转换到圆心
    painter.translate( x , y);


    int angle1 = heading;
    int angle2 = (360 - angle1) + 90;
    painter.setPen(pen3);
    painter.drawLine(0,0,-sin(angle1 * 3.14159265/180) * r1,-cos(angle1 * 3.14159265/180) *r1);
    painter.setPen(pen4);
    painter.drawLine(0,0,sin(angle1 * 3.14159265/180) * r1,cos(angle1 * 3.14159265/180) * r1);
    painter.drawLine(0,0,sin(angle2 * 3.14159265/180) * r1,-cos(angle2 * 3.14159265/180) * r1);
    painter.drawLine(0,0,-sin(angle2 * 3.14159265/180) * r1,cos(angle2 * 3.14159265/180) * r1);


    painter.rotate(Rwind_dir);

    //qDebug(QString("heading=%1 Rwind_dir=%2").arg(heading).arg(Rwind_dir).toLatin1());
    //箭头，多边形
    QPolygonF polygon2;

    polygon2 << QPointF(0,r2)
          <<QPointF(6,r1)
          <<QPointF(0,r2 + (r1 - r2)/2.0 + 1)
          <<QPointF(-6,r1);

    painter.setBrush(BRUSH_4);
    painter.drawPolygon(polygon2, Qt::WindingFill);

    painter.rotate(-Rwind_dir);
    painter.translate( -x , -y);

    y += r1 + 52;

    painter.setPen(pen2);
    painter.setFont(FONT_11);
    painter.drawText(x - 30,y,QString::number(Rwind_spd * KSPEED, 'f', 1));
    painter.setFont(FONT_5);
    painter.drawText(x + 35,y,danwei_jie);//节

    y += 60;

    painter.setPen(pen);
    painter.setFont(FONT_3);
    painter.drawText(x - 40,y,view1_chuansu);//"船速 "
    painter.setPen(pen2);
    painter.setFont(FONT_1);
    painter.drawText(x+30, y, danwei_jie);//"节"

    y += 5;
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    QRect rect2(x - 40,y,90,25);

    painter.drawRect(rect2);

    painter.setBrush(BRUSH_1);
    QPolygonF polygon3;

    if(speed_v >= 0)//右
    {
        polygon3 << QPointF(rect2.x() + 5, rect2.y()+5)
                   <<QPointF(rect2.x() + 20, y + rect2.height()/2 )
                   <<QPointF(rect2.x() + 5,rect2.y()+ rect2.height()-5);
    }
    else//左
    {
        polygon3 << QPointF(rect2.x() + 5, rect2.y()+5)
                   <<QPointF(rect2.x() + 20,  y + rect2.height()/2 )
                   <<QPointF(rect2.x() + 5, rect2.y()+ rect2.height()-5);
    }
    painter.drawPolygon(polygon3, Qt::WindingFill);
    painter.setPen(pen2);
    painter.setFont(FONT_9);

    float speedV = speed_v * 7.07 * KSPEED;
    if((speedV > -0.1 && speedV < 0))
        speedV = 0;

    painter.drawText(rect2.x() + 20,rect2.y(),rect2.width()-5,rect2.height(),
                     Qt::AlignCenter | Qt::AlignVCenter,QString::number(speedV, 'f', 1));

    y += rect2.height() + 5;

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    QRect rect3(x - 40,y,90,25);
    painter.drawRect(rect3);

    painter.setBrush(BRUSH_2);
    QPolygonF polygon4;
    if(speed_u>=0)//上
    {
        polygon4 << QPointF(rect3.x() + 10, rect3.y()+5)
                   <<QPointF(rect3.x() + 2, rect3.y()+ rect3.height()-5)
                   <<QPointF(rect3.x() + 18,rect3.y()+ rect3.height()-5);
    }
    else//下
    {
        polygon4 << QPointF(rect3.x() + 2, rect3.y()+5)
                   <<QPointF(rect3.x() + 18, rect3.y() +5)
                   <<QPointF(rect3.x() + 10,rect3.y()+ rect3.height()-5);
    }
    painter.drawPolygon(polygon4, Qt::WindingFill);

    painter.setPen(pen2);
    painter.setFont(FONT_9);

    float speedU = speed_u * 7.07 * KSPEED;
    if(speedU > -0.1 && speedU < 0)
        speedU = 0;


    painter.drawText(rect3.x()+20,rect3.y(),rect3.width()-5,rect3.height(),
                     Qt::AlignCenter | Qt::AlignVCenter,QString::number(speedU, 'f', 1));

    /*------------右中部，前推进器值----------------*/
    QPoint qProperllerTop(674,382);//前推进器

    x = qProperllerTop.x();
    y = qProperllerTop.y();
    int properllerW = 29;//推进器 宽
    int properllerH = 16;//推进器 高

    //平衡线
    painter.drawLine(x,y,x,y+properllerH);

    painter.setBrush(BRUSH_5);
    //qDebug()<<fbk_prop1_spd<<MAX_PROP1_SPD;
        //20160921增加
        if( fbk_prop1_spd > MAX_PROP1_SPD ){//野值剔除
                fbk_prop1_spd = MAX_PROP1_SPD;
        }
        if( fbk_prop1_spd <= ( -1 * MAX_PROP1_SPD ) ){	//野值剔除
                fbk_prop1_spd = -1 * MAX_PROP1_SPD;
        }
        //qDebug()<<fbk_f1;
        painter.setPen(Qt::NoPen);//绘制柱状图
        if(fbk_prop1_spd > 0 ){
                painter.drawRect(x, y, properllerW * fabs(fbk_prop1_spd) / MAX_PROP1_SPD, properllerH);
        }
        else if(fbk_prop1_spd < 0){
                painter.drawRect(x, y, (-1) * properllerW * fabs(fbk_prop1_spd/ MAX_PROP1_SPD ) ,properllerH);
        }
        //老程序
        //    if(fabs(fbk_f1) > MAX_F1)//野值剔除
        //    {
        //        fbk_f1 = fbk_f1 > 0 ? MAX_F1 : - MAX_F1;
        //    }

        //if(fabs(fbk_f2) > MAX_F23){
                //fbk_f2 = fbk_f2 > 0 ? MAX_F23 : - MAX_F23;
        //}

        //if(fabs(fbk_f3) > MAX_F23){
                //fbk_f3 = fbk_f3 > 0 ? MAX_F23 : - MAX_F23;
        //}

        //painter.setPen(Qt::NoPen);
        //if(fbk_f1 > 0)
        //	painter.drawRect(x+1, y,properllerW * fabs(fbk_f1) / MAX_F1,properllerH);
        //else if(fbk_f1 < 0)
        //	painter.drawRect(x - properllerW + properllerW *(1-fabs(fbk_f1)/MAX_F1) ,y,properllerW * fabs(fbk_f1) / MAX_F1,properllerH);


    /*------------右下部，设定艏向----------------*/
    //设定艏向位置
    //    QPoint qSettingHead(this->width() - 100,this->height() - 120);
    QPoint qSettingHead(this->width() - 130,this->height() - 120);//xxy

    x = qSettingHead.x();
    y = qSettingHead.y();

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
//    QRect rect4(x ,y,90,25);

//    painter.drawRect(rect4);

//    painter.setBrush(BRUSH_1);
//    QPolygonF polygon5;
//    polygon5 << QPointF(rect4.x() + 5, rect4.y()+5)
//               <<QPointF(rect4.x() + 20, y + rect4.height()/2 )
//               <<QPointF(rect4.x() + 5,rect4.y()+ rect4.height()-5);
//    painter.drawPolygon(polygon5, Qt::WindingFill);
//    painter.setPen(pen2);
//    painter.setFont(FONT_9);
//    painter.drawText(rect4.x() + 20,rect4.y(),rect4.width()-5,rect4.height(),Qt::AlignCenter | Qt::AlignVCenter,"0.5");

    y += 41;//rect4.height() + 16;---xxy

    painter.setPen(pen);
    painter.setFont(FONT_3);
    painter.drawText(x,y,view1_shedingshouxiang);//"设定艏向 "
    painter.setFont(FONT_1);
    painter.drawText(x+90,y,danwei_du);//" °"

    y += 5;
    painter.setBrush(Qt::NoBrush);
    QRect rect5(x ,y,90,25);
    painter.drawRect(rect5);

    painter.setPen(pen2);
    painter.setFont(FONT_9);
    painter.drawText(rect5.x(),rect5.y(),rect5.width()-5,rect5.height(),
                     Qt::AlignCenter | Qt::AlignVCenter,QString::number(set_heading, 'f', 1));


    /*------------左中部，主推进器----------------*/
    //艉推进器
    QPoint qProperllerLeft(209,221);
    QPoint qProperllerRight(245,221);

    x = qProperllerLeft.x();
    y = qProperllerLeft.y();

    painter.setBrush(BRUSH_5);

    //左
    //平衡线
    painter.setPen(pen2);
    painter.drawLine(x,y,x+properllerH,y);
    painter.setPen(Qt::NoPen);

        //20160921增加
        if( fbk_prop2_pitch > 1.0 ){//野值剔除
                fbk_prop2_pitch = 1.0;
        }
        if( fbk_prop2_pitch < -1.0 ){//野值剔除
                fbk_prop2_pitch = -1.0;
        }
        if( fbk_prop2_pitch > 0){
                painter.drawRect(x ,y, properllerH,  (-1) * properllerW * fabs(fbk_prop2_pitch / 1.0 ));
        }
        else if( fbk_prop2_pitch < 0){
                painter.drawRect(x ,y, properllerH ,properllerW * fabs(fbk_prop2_pitch / 1.0 ));
        }
//老程序
//    if(fbk_f2 > 0)
//        painter.drawRect(x ,y - properllerW + properllerW *(1- fabs(fbk_f2)/MAX_F23),properllerH ,properllerW * fabs(fbk_f2) / MAX_F23);
//    else if(fbk_f2 < 0)
//        painter.drawRect(x,y,properllerH ,properllerW * fabs(fbk_f2) / MAX_F23);

    x = qProperllerRight.x();
    y = qProperllerRight.y();

    //右
    //平衡线
    painter.setPen(pen2);
    painter.drawLine(x,y,x+properllerH,y);
    painter.setPen(Qt::NoPen);


        //20160921增加
        if( fbk_prop3_pitch > 1.0 ){//野值剔除
                fbk_prop3_pitch = 1.0;
        }
        if( fbk_prop3_pitch < -1.0 ){//野值剔除
                fbk_prop3_pitch = -1.0;
        }
        if( fbk_prop3_pitch > 0){
                painter.drawRect(x ,y , properllerH, (-1) * properllerW * fabs(fbk_prop3_pitch / 1.0 ));
        }
        else if( fbk_prop3_pitch < 0){
                painter.drawRect(x ,y , properllerH ,properllerW * fabs(fbk_prop3_pitch / 1.0 ));
        }
//老程序
//    if(fbk_f3 > 0)
//        painter.drawRect(x ,y - properllerW + properllerW *(1-fabs(fbk_f3)/MAX_F23),properllerH ,properllerW * fabs(fbk_f3) / MAX_F23);
//    else if(fbk_f3 < 0)
//        painter.drawRect(x,y,properllerH ,properllerW * fabs(fbk_f3) / MAX_F23);

    /*------------左下部，舵状态----------------*/
    //船尾
    QPoint qSternL(82,254);
    QPoint qSternR(138,254);

    x = qSternL.x();
    y = qSternL.y();
    r1 = 35;

    painter.setBrush(Qt::NoBrush);
    painter.setPen(pen);
    angle1 = fbk_rudder1_ang;
    angle2 = fbk_rudder2_ang;

    painter.drawLine(x,y,x +sin(angle1 * 3.14159265/180) * r1,y + cos(angle1 * 3.14159265/180) * r1);
    painter.setPen(pen2);
    painter.setFont(FONT_9);

//    painter.drawRect(x - r1 ,y- 26,2*r1, 20);
    painter.drawText(x - r1 ,y- 26,2*r1, 20, Qt::AlignTop | Qt::AlignHCenter, QString("%1").arg(angle1));
    x = qSternR.x();
    y = qSternR.y();
    r1 = 35;
    //painter.drawEllipse(x - r1,y - r1,2*r1,2*r1);

    painter.setPen(pen2);
    painter.setFont(FONT_9);
    painter.drawText(x - r1 ,y- 26,2*r1, 20, Qt::AlignTop | Qt::AlignHCenter, QString("%1").arg(angle2));

    painter.setPen(pen);
    painter.drawLine(x,y,x +sin(angle2 * 3.14159265/180) * r1,y + cos(angle2 * 3.14159265/180) * r1);



    /*------------中部，旋转中心----------------*/
    //旋转中心
//    QPoint qRotation(230,476);
    QPoint qRotation(230,476);
    x = qRotation.x();
    y = qRotation.y();

    r1 = 32;
       //20160922新增

//#define MAX_ROTATETORQUE 820 * 1000 //最大回转力矩820kNm
//#define MAX_SWAYINGFORCE 20 * 1000  //横荡最大力	20kN
//#define MAX_SURGINGFORCE 390 * 1000 //纵荡最大力	390kN

        //合力线
        float overflowFx = abs(fbk_Fx) - (MAX_SURGINGFORCE);//纵向发力的超出部分
        float overflowFy = abs(fbk_Fy) - (MAX_SWAYINGFORCE);//横向发力的超出部分

        double fbkFxRate, fbkFyRate;//计算实际发力的百分比
        if(overflowFx >0){
                if(fbk_Fx > 0) fbkFxRate = 1.0;
                else fbkFxRate = -1.0;
        }
        else{
                fbkFxRate = fbk_Fx / (MAX_SURGINGFORCE);
        }
        if(overflowFy >0){
                if(fbk_Fy > 0) fbkFyRate = 1.0;
                else fbkFyRate = -1.0;
        }
        else{
                fbkFyRate = fbk_Fy / (MAX_SWAYINGFORCE);
        }

        double fbkForceRate = hypotenuse(fbkFxRate, fbkFyRate);//合力的大小,百分比
        double forceAngle = atan2( fbkFxRate, fbkFyRate ); //合力百分比的夹角，rad

        painter.setPen(pen3);
        painter.drawLine(x,y, x + fbkForceRate * r1 * cos(forceAngle), y - fbkForceRate * r1 * sin(forceAngle) );

//        qDebug()<<fbkForceRate<<forceAngle / 3.1415926535 * 180<<fbkFyRate<<fbkFxRate<<overflowFx<<overflowFy;

        //画扭矩
        float overflowNz = abs(fbk_Nz) - (MAX_ROTATETORQUE);

        double fbkNzRate;
        if(overflowNz >0){
                if(fbk_Nz > 0) fbkNzRate = 1.0;
                else fbkNzRate = -1.0;
        }
        else{
                fbkNzRate = fbk_Nz / (MAX_ROTATETORQUE);
        }

        painter.setPen(pen3);
        painter.drawArc(x-r1,y-r1, 2*r1, 2*r1, 90 * 16, (-180* fbkNzRate ) * 16);

        //qDebug()<<fbkNzRate;
//    老程序
//    painter.drawLine(x,y,x,y-r1);



//    int MAX_Flen = r1 + 12;//最大的力长度

////    MAX_Fsum = -100;
////    F_sum = -rand() % 100;

//    double Flen = MAX_Flen * F_sum / MAX_Fsum;//计算实际力长度
//    int MAX_Nang = 90; //最大的力角度

////    MAX_Nsum = -100;
////    N_sum = -rand() % 100;

////    F_ang = rand()%30;

//    double Nang = MAX_Nang * N_sum / MAX_Nsum;//计算实际力矩角度

//    painter.drawLine(x,y,x +sin(F_ang * 3.14159265/180) * (Flen),y + cos(F_ang * 3.14159265/180) * (Flen));

//    painter.setPen(pen3);

//    if(Nang < 0)
//        painter.drawArc(x-r1,y-r1,2*r1,2*r1,90*16,fabs(Nang)*16);
//    else if(Nang > 0)
//        painter.drawArc(x-r1,y-r1,2*r1,2*r1,(90-fabs(Nang))*16,fabs(Nang)*16);


    /*------------左下部，小船体----------------*/
    //左下部 船
    //艏侧推
    painter.setPen(pen2);
    painter.setFont(FONT_9);
    QPoint qProperllerTop2(83,548);//前推进器

    x =qProperllerTop2.x();
    y = qProperllerTop2.y();
    int properllerW2 = 14;//推进器 宽
    int properllerH2 = 8;//推进器 高

    //平衡线
    painter.drawLine(x,y,x,y+properllerH2);

    painter.setBrush(BRUSH_5);

        //20160921增加
        painter.setPen(Qt::NoPen);//绘制柱状图
        if(fbk_prop1_spd > 0 ){
                painter.drawRect(x, y, properllerW2 * fabs(fbk_prop1_spd) / MAX_PROP1_SPD, properllerH2);
        }
        else if(fbk_prop1_spd < 0){
                painter.drawRect(x, y, (-1) * properllerW2 * fabs(fbk_prop1_spd/ MAX_PROP1_SPD ) ,properllerH2);
        }

//    老程序
//    if(fabs(fbk_f1) > MAX_F1)
//    {
//        fbk_f1 = fbk_f1 > 0 ? MAX_F1 : - MAX_F1;
//    }

//    if(fabs(fbk_f2) > MAX_F23)
//    {
//        fbk_f2 = fbk_f2 > 0 ? MAX_F23 : - MAX_F23;
//    }

//    if(fabs(fbk_f3) > MAX_F23)
//    {
//        fbk_f3 = fbk_f3 > 0 ? MAX_F23 : - MAX_F23;
//    }

//    painter.setPen(Qt::NoPen);
//    if(fbk_f1 > 0)
//        painter.drawRect(x, y,properllerW2 * fabs(fbk_f1) / MAX_F1,properllerH2);
//    else if(fbk_f1 < 0)
//        painter.drawRect(x - properllerW2 + properllerW2 *(1-fabs(fbk_f1)/MAX_F1) ,y,properllerW2 * fabs(fbk_f1) / MAX_F1,properllerH2);


    //艉推进器
    QPoint qProperllerLeft2(64,640);
    QPoint qProperllerRight2(94,640);

    x = qProperllerLeft2.x();
    y = qProperllerLeft2.y();

    painter.setBrush(BRUSH_5);

    //平衡线
    painter.setPen(pen2);
    painter.drawLine(x,y,x+properllerH2,y);
    painter.setPen(Qt::NoPen);

    //左
        //20160921增加
        if( fbk_prop2_pitch > 0){
                painter.drawRect(x ,y, properllerH2 ,  (-1) * properllerW2 * fabs(fbk_prop2_pitch / 1.0 ));
        }
        else if( fbk_prop2_pitch < 0){
                painter.drawRect(x ,y, properllerH2 ,properllerW2 * fabs(fbk_prop2_pitch / 1.0 ));
        }

//    老程序
//    if(fbk_f2 > 0)
//        painter.drawRect(x ,y - properllerW2 + properllerW2 *(1- fabs(fbk_f2)/MAX_F23),properllerH2 ,properllerW2 * fabs(fbk_f2) / MAX_F23);
//    else if(fbk_f2 < 0)
//        painter.drawRect(x,y,properllerH2 ,properllerW2 * fabs(fbk_f2) / MAX_F23);

//    if(fbk_f2 > 0)
//        painter.drawRect(x ,y - properllerW2 ,properllerH2 ,properllerW2 );
//    else if(fbk_f2 < 0)
//        painter.drawRect(x,y,properllerH2 ,properllerW2 );


    x = qProperllerRight2.x();
    y = qProperllerRight2.y();

    //平衡线
    painter.setPen(pen2);
    painter.drawLine(x,y,x+properllerH2,y);
    painter.setPen(Qt::NoPen);
    //右
         //20160921增加
        if( fbk_prop3_pitch > 0){
                painter.drawRect(x ,y , properllerH2 , (-1) * properllerW2 * fabs(fbk_prop3_pitch / 1.0 ));
        }
        else if( fbk_prop3_pitch < 0){
                painter.drawRect(x ,y , properllerH2 ,properllerW2 * fabs(fbk_prop3_pitch / 1.0 ));
        }

//    老程序
//    if(fbk_f3 > 0)
//        painter.drawRect(x ,y - properllerW2 + properllerW2 *(1-fabs(fbk_f3)/MAX_F23),properllerH2 ,properllerW2 * fabs(fbk_f3) / MAX_F23);
//    else if(fbk_f3 < 0)
//        painter.drawRect(x,y,properllerH2 ,properllerW2* fabs(fbk_f3) / MAX_F23);

//    if(fbk_f3 > 0)
//        painter.drawRect(x ,y - properllerW2 ,properllerH2 ,properllerW2);
//    else if(fbk_f3 < 0)
//        painter.drawRect(x,y,properllerH2 ,properllerW2);


    //船尾
    QPoint qSternL2(68,655);
    QPoint qSternR2(98,655);

    x = qSternL2.x();
    y = qSternL2.y();
    r1 = 20;

    painter.setBrush(Qt::NoBrush);
    painter.setPen(pen);
    angle1 = fbk_rudder1_ang;
    angle2 = fbk_rudder2_ang;

    painter.drawLine(x,y,x +sin(angle1 * 3.14159265/180) * r1,y + cos(angle1 * 3.14159265/180) * r1);
    painter.setPen(pen2);
    painter.setFont(FONT_9);

//    painter.drawRect(x - r1 ,y- 26,2*r1, 20);
//    painter.drawText(x - r1 ,y- 26,2*r1, 20, Qt::AlignTop | Qt::AlignHCenter, QString("%1").arg(angle1));
    x = qSternR2.x();
    y = qSternR2.y();
    r1 = 20;
    //painter.drawEllipse(x - r1,y - r1,2*r1,2*r1);

    painter.setPen(pen2);
    painter.setFont(FONT_9);
//    painter.drawText(x - r1 ,y- 26,2*r1, 20, Qt::AlignTop | Qt::AlignHCenter, QString("%1").arg(angle2));

    painter.setPen(pen);
    painter.drawLine(x,y,x +sin(angle2 * 3.14159265/180) * r1,y + cos(angle2 * 3.14159265/180) * r1);
}

//计算斜边
double MainViewWidget::hypotenuse( double x, double y){
        return sqrt(x*x + y*y);
}
