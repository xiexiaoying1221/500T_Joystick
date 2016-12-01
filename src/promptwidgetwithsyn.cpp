#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "promptwidgetwithsyn.h"

PromptWidgetWithSyn::PromptWidgetWithSyn(QWidget *parent,QWidget *singalReceiver,QRect viewRect):
    QWidget(parent, Qt::FramelessWindowHint)
{
    this->setAutoFillBackground(true);

    this->setGeometry(viewRect.x(),  viewRect.y(), viewRect.width(),viewRect.height());

    int w = this->geometry().width();
    int h = this->geometry().height();

    QFont font("微软雅黑",15);
    QFont font1("微软雅黑",10);

    statePtr= &Operate_mode;//默认的prompWidget是用于修改操作模式的

    lblPrompt = new QLabel(this);
    lblPrompt->setAlignment(Qt::AlignCenter);
    lblPrompt->setFont(font);
    lblPrompt->setGeometry(10,30,w-20,60);

    lblConst = new QLabel(this);
    lblConst->setAlignment(Qt::AlignCenter);
    lblConst->setFont(font1);
    lblConst->setGeometry(10,h-40,w-20,40);
    lblConst->setVisible( false );

    pbOK = new QPushButton(this);
    pbOK->setFocusPolicy(Qt::NoFocus);
    pbOK->setGeometry(w/2 - 59, h - 60,48,26);
    pbOK->setStyleSheet("background-color: transparent;"
                        "border-image: url(:/images/按钮-日.png);");
    pbOK->setText(str_queding);
    pbOK->setFont(FONT_7);
    pbOK->setEnabled( false);

    pbCancel = new QPushButton(this);
    pbCancel->setFocusPolicy(Qt::NoFocus);
    pbCancel->setGeometry(w/2 + 11 , h - 60,48,26);
    pbCancel->setStyleSheet("background-color: transparent;"
                        "border-image: url(:/images/按钮-日.png);");
    pbCancel->setText(str_quxiao);
    pbCancel->setFont(FONT_7);

    changeDNMode();
    connect(pbOK,SIGNAL(clicked()),this,SLOT(clickOk()));
    connect(pbCancel,SIGNAL(clicked()),this,SLOT(clickCancel()));
    connect(this, SIGNAL(changemode(bool)),singalReceiver,SLOT(changeMode(bool)));
}

void PromptWidgetWithSyn::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_22)));//":/images/对话框长-日.png"
        this->setPalette(p);
        lblPrompt->setStyleSheet(StyleSheet_DayColor);
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_22)));//":/images/对话框长-夜.png"
        this->setPalette(p);
        lblPrompt->setStyleSheet(StyleSheet_NgtColor);
    }
}

void PromptWidgetWithSyn::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->geometry().width();
    int height = this->geometry().height();

    QPen pen1;//线条Pen
    QPen pen2;//master值
    QPen pen3;//本地值
    QPen pen4;//黑字体
    QPen pen5;
    QPen pen6;//艏向 指示线

    pen2 = QPen(COLOR_10,10,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
    pen3 = QPen(COLOR_17,10,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);

    if(daynight_mode == DAYMODE)
    {
        pen1 = PEN_1;
        pen4 = PEN_2;
        pen5 = PEN_9;
        pen6 = PEN_18;
    }
    else
    {
        pen1 = PEN_1_1;
        pen4 = PEN_1_1;
        pen5 = PEN_9;
        pen6 = PEN_18;
    }

//    joystick_x = 50.0;masterJoystick_x  =80.0;
//    joystick_y = 100.0; masterJoystick_y = 95.0;
//    joystick_z = -40.0; masterJoystick_z = 55.0;

    //判断同步条件
    bool x_syn=false,y_syn=false,z_syn=false,all_syn=false;
    if( abs( joystick_x - masterJoystick_x) <10.0) x_syn =true;
    if( abs( joystick_y - masterJoystick_y) <10.0) y_syn =true;
    if( abs( joystick_z - masterJoystick_z) <10.0) z_syn =true;
    if( x_syn && y_syn && z_syn ) all_syn = true;
    //根据条件显示
    if( all_syn ){
        this->lblConst->setVisible( false );
        this->pbOK->setEnabled( true );
        clickOk();
    }
    else{
        this->lblConst->setVisible( true );
        this->pbOK->setEnabled( false );
    }


//以下开始画弧形
    //移动坐标系,使得坐标原点在label的下方中间
    painter.translate(width / 2, height);
    painter.setPen(pen1);
    //圆弧
    int r2 = width;//外圆弧半径
    int interval2 = 30;//外圆弧 - 内圆弧 间隔

    /*下端 弧 外 中 内*/
    QRectF rectangle3(-r2,-height*3/4,2*r2,2*r2);
    int startAngle3 = 65;
    int spanAngle3 = 50;
    painter.drawArc(rectangle3, startAngle3 * 16, spanAngle3 * 16);

    QRectF rectangle4(-r2,-height*3/4 +interval2 ,2*r2,2*r2);
    int startAngle4 = 67;
    int spanAngle4= 46;
    painter.drawArc(rectangle4, startAngle4 * 16 , spanAngle4 * 16);

    QRectF rectangle7(-r2,-height*3/4 +interval2/2 ,2*r2,2*r2);
    int startAngle8 = 66;
    int spanAngle8= 48;
    painter.drawArc(rectangle7,startAngle8 * 16 , spanAngle8 * 16);

    /*下端弧 左右中 边界线*/
    painter.drawLine(-sin((90 -startAngle3)*3.14159265/180)* r2, -height*3/4 + (1-cos((90 -startAngle3)*3.14159265/180))* r2 ,
                           -sin((90 -startAngle4)*3.14159265/180)* r2, -height*3/4 + interval2 + (1-cos((90 -startAngle4)*3.14159265/180))* r2 );

    painter.drawLine(sin((90 -startAngle3)*3.14159265/180)* r2, -height*3/4 + (1-cos((90 -startAngle3)*3.14159265/180))* r2 ,
                           sin((90 -startAngle4)*3.14159265/180)* r2, -height*3/4 + interval2 + (1-cos((90 -startAngle4)*3.14159265/180))* r2 );

    painter.drawLine(0,-height*3/4,0,-height*3/4+interval2);

    /*双指示条*/
    if(z_syn){
        //同步上了显示绿色，否则橙色
        pen3.setColor(COLOR_10);
    }
    else{
        pen3.setColor(COLOR_17);
    }
    pen3.setWidth(interval2/2 *0.9);
    painter.setPen(pen3);//本地值
    float startAngle6;
    float spanAngle6;//24.6*16;

    QRectF rectangle6(-r2 ,-height*3/4 + interval2/4 ,2*r2,2*r2);

    spanAngle6 = fabs(joystick_z) * 24.68 / 100.0;/*最大跨度 25*/

     if(joystick_z < 0)
     {
         startAngle6 = 90;

         painter.drawArc(rectangle6,startAngle6*16,spanAngle6*16 );
     }
     else if(joystick_z > 0)
     {
         startAngle6 = 90 - spanAngle6;
         painter.drawArc(rectangle6,startAngle6*16,spanAngle6*16 );
     }

    float startAngle7 ;
    float spanAngle7 ;//

    pen2.setWidth(interval2/2 *0.9);
    painter.setPen(pen2);//master值
    QRectF rectangle8(-r2 ,-height*3/4 + interval2 * 3/4 ,2*r2,2*r2);
    //masterJoystick_z是主站的手柄z值，是跟踪值
    spanAngle7 = fabs(masterJoystick_z) * 23.40 / 100.0;/*最大跨度 23.40*/
    //drawArc：3点钟方向为0度，顺时针span为负，逆时针span为正
     if(masterJoystick_z < 0)
     {
         startAngle7 = 90;
         painter.drawArc(rectangle8,startAngle7*16,spanAngle7*16 );
     }
     else if(masterJoystick_z > 0)
     {
         startAngle7 = 90 - spanAngle7;
         painter.drawArc(rectangle8,startAngle7*16,spanAngle7*16 );
     }


//以下开始画十字星
    int remain = 120;
    int interval = (width - remain)/20;

    int rectW = 4*  interval/3;
    int rectH = 8*  interval;

    painter.translate(0, - 20 * interval );
    painter.setPen(pen1);
    painter.drawRect(QRect(-rectW,-10*interval,2*rectW,rectH));//上
    painter.drawRect(QRect(-rectW,2*interval,2*rectW,rectH));//下
    painter.drawRect(QRect(-10*interval,-rectW,rectH,2*rectW));//左
    painter.drawRect(QRect(2*interval,-rectW,rectH,2*rectW));//右

    painter.setBrush(Qt::NoBrush);
    //画十字型
    painter.drawLine(0,-interval*10 ,0,interval*10);
    painter.drawLine(-10 * interval,0, 10*interval,0);

//    //画刻度
//    for(int i=1; i<= 10; i++){
//        painter.drawLine(i * interval,1,i * interval,-1);//x +
//        painter.drawLine(-i * interval,1,-i * interval,-1);// x-
//        painter.drawLine(-1,i*interval,1,i*interval);//y +
//        painter.drawLine(-1,-i*interval,1,-i*interval);// y-
//    }

    float cmdfx = rectH * joystick_x / 100.0;
    float fbkfx = rectH * masterJoystick_x / 100.0;
    float cmdfy = rectH * joystick_y / 100.0;
    float fbkfy = rectH * masterJoystick_y / 100.0;
    //qDebug()<<"PositionWidget::paintEvent.0"<<rectH<<cmd_Fx<<MAX_FX<<cmdfx;

    float beginX = cmdfx > 0 ? -2*interval : 2*interval;
    float beginY = cmdfy > 0 ? 2*interval : -2*interval;

    pen3.setWidth(rectW *0.8);
    if(x_syn){
        //同步上了显示绿色，否则橙色
        pen3.setColor(COLOR_10);
    }
    else{
        pen3.setColor(COLOR_17);
    }
    painter.setPen(pen3);
    painter.drawLine(-rectW/2,beginX, -rectW/2,beginX-cmdfx);//cmd-fx
    if(y_syn){
        //同步上了显示绿色，否则橙色
        pen3.setColor(COLOR_10);
    }
    else{
        pen3.setColor(COLOR_17);
    }
    painter.setPen(pen3);
    painter.drawLine(beginY ,-rectW/2, beginY + cmdfy,-rectW/2);//cmd-fy

    pen2.setWidth(rectW *0.8);
    painter.setPen(pen2);
    beginX = fbkfx > 0 ? -2*interval : 2*interval;
    beginY = fbkfy > 0 ? 2*interval : -2*interval;
    painter.drawLine(rectW/2,beginX, rectW/2,beginX-fbkfx);//fbk-fx,前后,前负后正
    painter.drawLine(beginY, rectW/2,beginY + fbkfy,rectW/2);//fbk-fy,左右,左负右正


//    QWidget::paintEvent(event);
}


void PromptWidgetWithSyn::showEvent(QShowEvent *)
{
    lblPrompt->setText(message);
}

void PromptWidgetWithSyn::Refresh_changless_words()
{
    pbOK->setText(str_queding);
    pbCancel->setText(str_quxiao);
    lblConst->setText(str_takegive_notice);
}

void PromptWidgetWithSyn::clickOk(){
    bool ok;
    if(targetState != -1)
    {
        *statePtr = targetState;
        ok = true;
    }
    else
       ok = false;

    emit changemode(ok);
    this->setVisible(false);
}

void PromptWidgetWithSyn::clickCancel(){
    emit changemode(false);
    this->setVisible(false);
}

void PromptWidgetWithSyn::refreshData(){
    update();
}
