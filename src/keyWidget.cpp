#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "keyWidget.h"

KeyWidget::KeyWidget(QWidget *parent, QRect keyRect)
    :QWidget(parent,Qt::FramelessWindowHint){

    /*位置 大小*/
    this->setGeometry(keyRect.x(),  keyRect.y()-3, keyRect.width()-5,keyRect.height());
    this->parent = parent;

    QPalette p;
    p.setBrush(this->backgroundRole(),QBrush(QPixmap(PicNameD_7)));//"images/按键区-日.png"
    this->setPalette(p);
    this->setAutoFillBackground(true);

    _manager = UsrManager::Instance();
    connect(_manager,SIGNAL(msgCurrentUsrChanged()),this,SLOT(currentUsrChanged()));

    //按键区初始化
    keyAreaInit();

    //2016.10.28新增，遮盖区域。没有控制权时就不能操作该区域按钮
    disableCover = new QWidget(this);
    disableCover->setStyleSheet("background-color: rgba(196, 196, 196, 0.5);");
    disableCover->setGeometry(this->x(), this->y() + 160, this->width() - 20, 340);
    disableCover->raise();
    disableCover->show();
    disableCover->setVisible(true);

    //2016.12.09新增，遮盖区域。用户未登录时就不能设置
    disableCover2 = new QWidget(this);
    disableCover2->setStyleSheet("background-color: rgba(196, 196, 196, 0.5);");
    disableCover2->setGeometry(this->x(), this->y() + 80, this->width() - 20, 80);
    disableCover2->raise();
    disableCover2->show();
    disableCover2->setVisible(true);
}

//白天、夜晚模式切换
void KeyWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        disableCover->setStyleSheet("background-color: rgba(196, 196, 196, 0.5);");
        disableCover2->setStyleSheet("background-color: rgba(196, 196, 196, 0.5);");
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_7)));//"images/按键区-日.png"
    }
    else
    {
        disableCover->setStyleSheet("background-color: rgba(35, 35, 35, 0.5);");
        disableCover2->setStyleSheet("background-color: rgba(35, 35, 35, 0.5);");
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_7)));//"images/按键区-夜.png"
    }
    this->setPalette(p);
    if(promptWidget != NULL)//是否有弹出的确认对话框
        promptWidget->changeDNMode();
}


void KeyWidget::keyAreaInit(){
    //近视划分成 8行 5列
    int cols = 4;
    int rows = 8;

    int width = this->geometry().width();
    int height = this->geometry().height();
    int x = 10;
    int y= 60;



    ////按6列计算按钮宽度 横向所有空隙宽 视为1列
    int btnWidth = width / (cols + 1.5);
    int btnHeight = btnWidth;
    float hSpace = (width - 2*x - cols * btnWidth)/(cols * 2)-2;
    float vSpace = (height - rows * btnHeight)/(rows * 2);

    int x1 = x  + hSpace;              //第1列按钮位置的x坐标
    int x2 = x + btnWidth + 3*hSpace;  //第2列按钮位置的x坐标
    int x3 = x + 2*btnWidth + 5*hSpace;//第3列按钮位置的x坐标
    int x4 = x + 3*btnWidth + 7*hSpace;//第4列按钮位置的x坐标


    int y1 = y + vSpace;                   //第1行按钮位置的y坐标
    int y2 = y1 + btnHeight + vSpace;      //第2行按钮位置的y坐标
    int y3 = y2 + btnHeight + 3 * vSpace;  //第3行按钮位置的y坐标
    int y4 = y3 + btnHeight + vSpace;      //第4行按钮位置的y坐标
    int y5 = y4 + btnHeight + vSpace;      //第5行按钮位置的y坐标
    int y6 = y5 + btnHeight + 3 * vSpace;  //第6行按钮位置的y坐标
    int y7 = y6 + btnHeight + vSpace;      //第7行按钮位置的y坐标


    /*--------------海事会------------------------
      --btn1:视图
      --btn2:系统
      --btn3:日/夜
      --btn4:报警
      --btn5:总体设置
      --btn6:启用设置
      --btn7:限值设置
      --btn8:系统设置（原：自动舵设置）
      --btn9:全推力
      --btn10:待机
      --btn11:当前艏向
      --btn12:手操
      --btn13:位置保持
      --btn14:自动舵
      --btn15:艏向设置
      --btn16:自动艏向
      --btn17:自动纵向
      --btn18:自动横向
      --btn19:船艏
      --btn20:船舯
      --btn21:船艉
      --btn22:令牌
      --btn23:转出
      --btn24:调光
      --btn25:中英文（原：测试）
      --btn26:隐藏按键区
      --btn27:仿真（20160918新增）
      --btn28:用户管理（20161202新增）
      --btn29:
      --btn30:
      --btn31:
      --btn32:
      -------------------------------------*/

    //QPushButton *btn1 =new QPushButton(this);//视图
    btn1 =new QPushButton(this);//视图
    btn1->setFocusPolicy(Qt::NoFocus);
    btn1->setGeometry(x1, y1, btnWidth,btnHeight);
    btn1->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn1->setText(btnstr_shitu);

    connect(btn1,SIGNAL(clicked()),parent,SLOT(btnView_clicked()));


    //QPushButton *btn2 = new QPushButton(this);//系统
    btn2 = new QPushButton(this);//系统
    btn2->setFocusPolicy(Qt::NoFocus);
    btn2->setGeometry(x2, y1, btnWidth,btnWidth);
    btn2->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn2->setText(btnstr_xitong);
    connect(btn2,SIGNAL(clicked()),parent,SLOT(btnSystem_clicked()));

    //QPushButton *btn3 = new QPushButton(this);//日/夜
    btn3 = new QPushButton(this);//日/夜
    btn3->setFocusPolicy(Qt::NoFocus);
    btn3->setGeometry(x3, y1 , btnWidth,btnHeight);
    btn3->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn3->setText(str_wanshang);
    connect(btn3,SIGNAL(clicked()),parent,SLOT(btnDayNight_clicked()));

    //QPushButton *btn4 = new QPushButton(this);//报警"
    btn4 = new QPushButton(this);//报警"
    btn4->setFocusPolicy(Qt::NoFocus);
    btn4->setGeometry(x4 , y1 , btnWidth,btnHeight);
    btn4->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn4->setText(btnstr_baojing);
    connect(btn4,SIGNAL(clicked()),parent,SLOT(btnAlarm_clicked()));

//    y = y + btnHeight + vSpace;//第二行

    //QPushButton *btn8 = new QPushButton(this);//系统设置(原自动舵设置)
    btn8 = new QPushButton(this);//系统设置(原自动舵设置)
    btn8->setFocusPolicy(Qt::NoFocus);
    btn8->setGeometry(x4, y2 , btnWidth,btnWidth);
    btn8->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn8->setText(btnstr_xitongshezhi);
    connect(btn8,SIGNAL(clicked()),parent,SLOT(btnAutoRudderSetting_clicked()));


//    y = y + btnHeight + 3 * vSpace;//第三行

    btn9 =new QPushButton(this);//全推力
    btn9->setFocusPolicy(Qt::NoFocus);
    btn9->setGeometry(x1 , y3 , btnWidth,btnHeight);
    btn9->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn9->setText(btnstr_quantuili);
    connect(btn9,SIGNAL(clicked()),this,SLOT(btnFullForce_clicked()));


    btn10 = new QPushButton(this);//待机
    btn10->setFocusPolicy(Qt::NoFocus);
    btn10->setGeometry(x2, y3 , btnWidth,btnWidth);
    btn10->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn10->setText(btnstr_daiji);
    connect(btn10,SIGNAL(clicked()),this,SLOT(btnStandby_clicked()));

    btn11 = new QPushButton(this);//当前艏向
    btn11->setFocusPolicy(Qt::NoFocus);
    btn11->setGeometry(x4 , y3 , btnWidth,btnWidth);
    btn11->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn11->setText(btnstr_dangqianshangxiang);
    connect(btn11,SIGNAL(clicked()),this,SLOT(btnCurrentHeading_clicked() ) );
//    y += btnHeight + vSpace;//第四行

    btn12 = new QPushButton(this);//手操
    btn12->setFocusPolicy(Qt::NoFocus);
    btn12->setGeometry(x2, y4 , btnWidth,btnWidth);
    btn12->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn12->setText(btnstr_shoucao);
    connect(btn12,SIGNAL(clicked()),this,SLOT(btnManualOperation_clicked()));
/*
    btn13 =new QPushButton(this);//位置保持
    btn13->setFocusPolicy(Qt::NoFocus);
    btn13->setGeometry(x3, y4, btnWidth,btnHeight);
    if(Operate_mode == KEEPPOS_MODE)
        btn13->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
    else
        btn13->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");

    btn13->setText(btnstr_weizhibaochi);
    connect(btn13,SIGNAL(clicked()),this,SLOT(btnPositionKepping_clicked()));


    btn14 = new QPushButton(this);//自动舵
    btn14->setFocusPolicy(Qt::NoFocus);
    btn14->setGeometry(x4, y4 , btnWidth,btnWidth);
    if(Operate_mode == AUTOPLT_MODE)
        btn14->setStyleSheet("border-image:url(:/images/greenbtn.png);color: rgb(52, 52, 52);");
    else
        btn14->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");

    btn14->setText(btnstr_zidongduo);
    connect(btn14,SIGNAL(clicked()),this,SLOT(btnAutoRudder_clicked()));
*/
//    y += btnHeight + vSpace;//第五行

    btn15 =new QPushButton(this);//艏向设置
    btn15->setFocusPolicy(Qt::NoFocus);
    btn15->setGeometry(x1 , y5 , btnWidth,btnHeight);
    btn15->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn15->setText(btnstr_shouxiangshezhi);
    connect(btn15,SIGNAL(clicked()),parent,SLOT(btnHeadingSetting_clicked()));

    btn16 = new QPushButton(this);//自动艏向
    btn16->setFocusPolicy(Qt::NoFocus);
    btn16->setGeometry(x2 , y5 , btnWidth,btnWidth);
    btn16->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn16->setText(btnstr_zidongshouxiang);
    connect(btn16,SIGNAL(clicked()),this,SLOT(btnAutoHeading_clicked()));

/*
    btn17 =new QPushButton(this);//自动纵向
    btn17->setFocusPolicy(Qt::NoFocus);
    btn17->setGeometry(x3 , y5 , btnWidth,btnHeight);
    if(Operate_mode == KEEPX_MODE || Operate_mode == KEEPXD_MODE || Operate_mode == KEEPXY_MODE)
        btn17->setStyleSheet("border-image:url(:/images/greenbtn.png);color: rgb(52, 52, 52);");
    else
        btn17->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn17->setText(btnstr_zidongzongxiang);
    connect(btn17,SIGNAL(clicked()),this,SLOT(btnAutoVertical_clicked()));

    btn18 =new QPushButton(this);//自动横向
    btn18->setFocusPolicy(Qt::NoFocus);
    btn18->setGeometry(x4 , y5 , btnWidth,btnHeight);
    if(Operate_mode == KEEPY_MODE || Operate_mode == KEEPYD_MODE || Operate_mode == KEEPXY_MODE)
        btn18->setStyleSheet("border-image:url(:/images/greenbtn.png);color: rgb(52, 52, 52);");
    else
        btn18->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn18->setText(btnstr_zidonghengxiang);
    connect(btn18,SIGNAL(clicked()),this,SLOT(btnAutoHorizontal_clicked()));
*/

//    y += btnHeight + 3 * vSpace;//第六行

    btn19 = new QPushButton(this);//船艏
    btn19->setFocusPolicy(Qt::NoFocus);
    btn19->setGeometry(x2 , y6 , btnWidth,btnHeight);
    btn19->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//船shou
    btn19->setText(btnstr_chuanshou);
    connect(btn19,SIGNAL(clicked()),this,SLOT(btnForePivot_clicked()));

    btn20 =new QPushButton(this);//船舯
    btn20->setFocusPolicy(Qt::NoFocus);
    btn20->setGeometry(x3, y6 , btnWidth,btnHeight);
    btn20->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//船zhong
    btn20->setText(btnstr_chuanzhong);
    connect(btn20,SIGNAL(clicked()),this,SLOT(btnCentrePivot_click()));

    btn21 =new QPushButton(this);//船艉
    btn21->setFocusPolicy(Qt::NoFocus);
    btn21->setGeometry(x4 , y6 , btnWidth,btnHeight);
    btn21->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//船wei
    btn21->setText(btnstr_chuanwei);
    connect(btn21,SIGNAL(clicked()),this,SLOT(btnAftPivot_click()));

//    y += btnHeight + vSpace;

    btn22 = new QPushButton(this);//令牌
    btn22->setFocusPolicy(Qt::NoFocus);
    btn22->setGeometry(x1 , y7 , btnWidth,btnWidth);
    btn22->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn22->setText(btnstr_lingpai);
    connect(btn22,SIGNAL(clicked()),parent,SLOT(btnTokenManager_clicked() ) );

//    btn23 = new QPushButton(this);//转出
//    btn23->setFocusPolicy(Qt::NoFocus);
//    btn23->setGeometry(x2, y7 , btnWidth,btnWidth);
//    btn23->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
//    btn23->setText(btnstr_zhuanchu);
//    connect(btn23,SIGNAL(clicked()),this,SLOT(btnTurnOut_clicked()));

    //QPushButton *btn24 =new QPushButton(this);//调光，移动端取消
#ifdef PORTABLE_STATION
#else
    btn24 =new QPushButton(this);//调光
    btn24->setFocusPolicy(Qt::NoFocus);
    btn24->setGeometry(x3 , y7 , btnWidth,btnHeight);
    btn24->setStyleSheet("border-image:url(:/images/whitebtn.png); color: rgb(52, 52, 52);");
    btn24->setText(btnstr_tiaoguang);
    connect(btn24,SIGNAL(clicked()),parent,SLOT(btnLightDim_clicked()));


    //QPushButton *btn5 = new QPushButton(this);//总体设置
    btn5 = new QPushButton(this);//总体设置
    btn5->setFocusPolicy(Qt::NoFocus);
    btn5->setGeometry(x1 , y2 , btnWidth,btnHeight);
    btn5->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn5->setText(btnstr_zongtishezhi);
    connect(btn5,SIGNAL(clicked()),parent,SLOT(btnGeneralSetting_clicked()));

    //QPushButton *btn6 = new QPushButton(this);//启用设置
    btn6 = new QPushButton(this);//启用设置
    btn6->setFocusPolicy(Qt::NoFocus);
    btn6->setGeometry(x2 , y2 , btnWidth,btnHeight);
    btn6->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn6->setText(btnstr_qiyongshezhi);
    connect(btn6,SIGNAL(clicked()),parent,SLOT(btnEnableSetting_clicked()));

    //QPushButton *btn7 =new QPushButton(this);//限值设置
    btn7 =new QPushButton(this);//限值设置
    btn7->setFocusPolicy(Qt::NoFocus);
    btn7->setGeometry(x3, y2 , btnWidth,btnHeight);
    btn7->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    btn7->setText(btnstr_xianzhishezhi);
    connect(btn7,SIGNAL(clicked()),parent,SLOT(btnLimitSetting_clicked()));

#endif

    //QPushButton *btn25 = new QPushButton(this);//中英文
    btn25 = new QPushButton(this);//中英文
    btn25->setFocusPolicy(Qt::NoFocus);
    btn25->setGeometry(x4 , y7 , btnWidth,btnWidth);
    btn25->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    if(State_language == "Chinese")
        btn25->setText("English");
    else
        btn25->setText("中文");
    connect(btn25,SIGNAL(clicked()),parent,SLOT(btnTest_clicked()));

    btn27 = new QPushButton(this);//仿真（20160918新增）
    btn27->setFocusPolicy(Qt::NoFocus);
    btn27->setGeometry(x3, y3 , btnWidth,btnWidth);
    btn27->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn27->setText(btnstr_simulation);
    connect(btn27,SIGNAL(clicked()),this,SLOT(btnSimulate_clicked()));

    btn28 = new QPushButton(this);//用户管理（20161202新增）
    btn28->setFocusPolicy(Qt::NoFocus);
    btn28->setGeometry(x2, y7 , btnWidth,btnWidth);
    btn28->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");
    btn28->setText(btnstr_usrmanager);
    connect(btn28,SIGNAL(clicked()),parent,SLOT(btnUsrManage_clicked()));

    btn1->setFont(FONT_16);
    btn2->setFont(FONT_16);
    btn3->setFont(FONT_16);
    btn4->setFont(FONT_16);

    btn8->setFont(FONT_16);
    btn9->setFont(FONT_16);
    btn10->setFont(FONT_16);
    btn11->setFont(FONT_16);
    btn12->setFont(FONT_16);
//    btn13->setFont(FONT_16);
//    btn14->setFont(FONT_16);
    btn15->setFont(FONT_16);
    btn16->setFont(FONT_16);
//    btn17->setFont(FONT_16);
//    btn18->setFont(FONT_16);
    btn19->setFont(FONT_16);
    btn20->setFont(FONT_16);
    btn21->setFont(FONT_16);
    btn22->setFont(FONT_16);
//    btn23->setFont(FONT_16);
#ifdef PORTABLE_STATION
#else
    btn24->setFont(FONT_16);

    btn5->setFont(FONT_16);
    btn6->setFont(FONT_16);
    btn7->setFont(FONT_16);
#endif
    btn27->setFont(FONT_16);
    btn28->setFont(FONT_16);

    if(State_language == "Chinese")
    {
        //FONT_1 = QFont();
        btn25->setFont(QFont("Arial",10,QFont::Bold));

    }
    else
    {
        btn25->setFont(QFont("微软雅黑",10,QFont::Bold));
    }




    /*透明的隐藏按键区的按键，需调整按键的位置 到 背景右侧的隐藏标示位置*/
    int btnHideWidth = 30;
    int btnHideHeight = 120;
    int btnHidePX = width - btnHideWidth;
    int btnHidePY = height/2 - btnHideHeight/2;

    btn26 = new QPushButton(this);//隐藏按键区
    btn26->setFocusPolicy(Qt::NoFocus);
    btn26->setGeometry(btnHidePX, btnHidePY, btnHideWidth,btnHideHeight);
    btn26->setStyleSheet("background-color: transparent;");
    connect(btn26,SIGNAL(clicked()),parent,SLOT(hideKeyArea()));


    /*提示对话框*/
    int dialogWidth = 317;
    int dialogHeight = 212;

    promptWidget = new PromptWidget(this->parentWidget(),this,
                                    QRect((WINDOWWIDTH - dialogWidth) / 2 , (WINDOWHEIGHT - dialogHeight)/2 , dialogWidth , dialogHeight));

    promptWidget->raise();//上层显示
    promptWidget->setVisible(false);
}

void KeyWidget:: Refresh_keys_title()
{
    /*--------------海事会------------------------
      --btn1:视图
      --btn2:系统
      --btn3:日/夜
      --btn4:报警
      --btn5:总体设置
      --btn6:启用设置
      --btn7:限值设置
      --btn8:系统设置（原：自动舵设置）
      --btn9:全推力
      --btn10:待机
      --btn11:当前艏向
      --btn12:手操
      --btn13:位置保持
      --btn14:自动舵
      --btn15:艏向设置
      --btn16:自动艏向
      --btn17:自动纵向
      --btn18:自动横向
      --btn19:船艏
      --btn20:船舯
      --btn21:船艉
      --btn22:令牌
      --btn23:转出
      --btn24:调光
      --btn25:中英文（原：测试）
      --btn26:隐藏按键区
      --btn27:仿真（20160918新增）
      --btn28:用户管理（20161202新增）
      -------------------------------------*/
    btn1->setText(btnstr_shitu);
    btn2->setText(btnstr_xitong);
    if(daynight_mode == DAYMODE)
    {
        btn3->setText(str_wanshang);
    }
    else
    {
        btn3->setText(str_baitian);
    }

    btn4->setText(btnstr_baojing);

    btn8->setText(btnstr_xitongshezhi);
    btn9->setText(btnstr_quantuili);
    btn10->setText(btnstr_daiji);
    btn11->setText(btnstr_dangqianshangxiang);
    btn12->setText(btnstr_shoucao);
//    btn13->setText(btnstr_weizhibaochi);
//    btn14->setText(btnstr_zidongduo);
    btn15->setText(btnstr_shouxiangshezhi);
    btn16->setText(btnstr_zidongshouxiang);
//    btn17->setText(btnstr_zidongzongxiang);
//    btn18->setText(btnstr_zidonghengxiang);
    btn19->setText(btnstr_chuanshou);
    btn20->setText(btnstr_chuanzhong);
    btn21->setText(btnstr_chuanwei);
    btn22->setText(btnstr_lingpai);
//    btn23->setText(btnstr_zhuanchu);
#ifdef PORTABLE_STATION
#else
    btn24->setText(btnstr_tiaoguang);

    btn5->setText(btnstr_zongtishezhi);
    btn6->setText(btnstr_qiyongshezhi);
    btn7->setText(btnstr_xianzhishezhi);
#endif
    btn25->setText(btnstr_zhongyingwen);
    btn27->setText(btnstr_simulation);
    btn28->setText(btnstr_usrmanager);

    btn1->setFont(FONT_16);
    btn2->setFont(FONT_16);
    btn3->setFont(FONT_16);
    btn4->setFont(FONT_16);

    btn8->setFont(FONT_16);
    btn9->setFont(FONT_16);
    btn10->setFont(FONT_16);
    btn11->setFont(FONT_16);
    btn12->setFont(FONT_16);
//    btn13->setFont(FONT_16);
//    btn14->setFont(FONT_16);
    btn15->setFont(FONT_16);
    btn16->setFont(FONT_16);
//    btn17->setFont(FONT_16);
//    btn18->setFont(FONT_16);
    btn19->setFont(FONT_16);
    btn20->setFont(FONT_16);
    btn21->setFont(FONT_16);
    btn22->setFont(FONT_16);
//    btn23->setFont(FONT_16);
#ifdef PORTABLE_STATION
#else
    btn24->setFont(FONT_16);

    btn5->setFont(FONT_16);
    btn6->setFont(FONT_16);
    btn7->setFont(FONT_16);
#endif
//    btn25->setFont(FONT_16);
    btn27->setFont(FONT_16);
    btn28->setFont(FONT_16);
    if(State_language == "Chinese")
    {
        //FONT_1 = QFont();
        btn25->setFont(QFont("Arial",10,QFont::Bold));

    }
    else
    {
        btn25->setFont(QFont("微软雅黑",10,QFont::Bold));
    }

    promptWidget->Refresh_changless_words();
}

void KeyWidget::btnStandby_clicked()//待机
{
    if(!isReady_first)//如果当前模式是待机
    {
        modeConfirm(str_Standby, READY_MODE);//"确认进入待机模式?"
    }
}

void KeyWidget::btnManualOperation_clicked()//手操
{
    if(Operate_mode != MANUAL_MODE)//如果当前模式是手操
    {
        modeConfirm(str_JoyStick, MANUAL_MODE);//"确认进入手操模式?"
    }
    else
    {
        modeConfirm(str_Standby, READY_MODE);//"确认进入待机模式?"
    }
}

void KeyWidget::btnPositionKepping_clicked()//位置保持
{
    if(Operate_mode != KEEPPOS_MODE)
    {
         modeConfirm(str_PositionKeep, KEEPPOS_MODE);//"确认进入位置保持模式?"
    }
    else
    {
        modeConfirm(str_Standby, READY_MODE);//"确认进入待机模式?"
    }
}

void KeyWidget::btnAutoRudder_clicked()//自动舵
{
    if(Operate_mode != AUTOPLT_MODE)
    {
         modeConfirm(str_AutoPilot, AUTOPLT_MODE);//"确认进入自动舵模式?"
    }
    else
    {
        modeConfirm(str_Standby, READY_MODE);//"确认进入待机模式?"
    }
}

void KeyWidget::btnCurrentHeading_clicked()//当前艏向
{
    //set_heading:写入PLC,艏向设定值;heading:读自PLC,实际艏向
    if(Operate_mode == KEEPPOS_MODE || Operate_mode == AUTOPLT_MODE || Operate_mode == HEADING_MODE) set_heading = heading;
}

void KeyWidget::btnAutoHeading_clicked()//自动艏向
{
    //qDebug()<<Operate_mode;
    if( Operate_mode == MANUAL_MODE)//未选择
    {
        //set_heading:写入PLC,艏向设定值;heading:读自PLC,实际艏向
        //set_heading = heading;
        modeConfirm(str_AutoHead, HEADING_MODE);//"确认进入自动艏向模式?"
        //qDebug()<<"into 自动首相";
    }
    else
    {
        modeConfirm(str_JoyStick, MANUAL_MODE);//"确认进入手操模式?"
        //qDebug()<<"outo 自动首相";
    }
}

void KeyWidget::btnAutoVertical_clicked()//自动纵向
{
    if(btn17->styleSheet().contains("border-image:url(images/white"))//未选择
    {
        if(btn16->styleSheet().contains("border-image:url(images/green")//已选择自动纵向
                && btn18->styleSheet().contains("border-image:url(images/green"))//已选择自动横向
        {
            modeConfirm(str_PositionKeep, KEEPPOS_MODE);//"确认进入位置保持模式?"
        }
        else if(btn16->styleSheet().contains("border-image:url(images/green"))//已选择自动纵向
        {
            modeConfirm(str_AutoHSu, KEEPXD_MODE);//"确认进入自动艏向+自动纵向模式?"
        }
        else if(btn18->styleSheet().contains("border-image:url(images/green"))//已选择自动横向
        {
            modeConfirm(str_AutoSuSw, KEEPXY_MODE);//"确认进入自动纵向+横向模式?"
        }
        else
        {
            modeConfirm(str_AutoSurge, KEEPX_MODE);//"确认进入自动纵向模式?"
        }
    }
    else//已选择
    {
        if(btn16->styleSheet().contains("border-image:url(images/green")//已选择自动纵向
                && btn18->styleSheet().contains("border-image:url(images/green"))//已选择自动横向
        {
            modeConfirm(str_AutoHSw, KEEPYD_MODE);//"确认进入自动艏向+自动横向模式?"
        }
        else if(btn16->styleSheet().contains("border-image:url(images/green"))//已选择自动纵向
        {
            modeConfirm(str_AutoHead, HEADING_MODE);//"确认进入自动艏向模式?"
        }
        else if(btn18->styleSheet().contains("border-image:url(images/green"))//已选择自动横向
        {
            modeConfirm(str_AutoSway, KEEPY_MODE);//"确认进入自动横向模式?"
        }
        else
        {
            modeConfirm(str_JoyStick, MANUAL_MODE);//"确认进入手操模式?"

        }
    }
}

void KeyWidget::btnAutoHorizontal_clicked()//自动横向
{
    if(btn18->styleSheet().contains("border-image:url(images/white"))//未选择
    {
        if(btn16->styleSheet().contains("border-image:url(images/green")//已选择自动艏向
                && btn17->styleSheet().contains("border-image:url(images/green"))//已选择自动纵向
        {
            modeConfirm(str_PositionKeep, KEEPPOS_MODE);//"确认进入位置保持模式?"
        }
        else if(btn16->styleSheet().contains("border-image:url(images/green"))//已选择自动艏向
        {
            modeConfirm(str_AutoHSw, KEEPYD_MODE);//"确认进入自动艏向+横向模式?"
        }
        else if(btn17->styleSheet().contains("border-image:url(images/green"))//已选择自动横向
        {
            modeConfirm(str_AutoSuSw, KEEPXY_MODE);//"确认进入自动纵向+横向模式?"

        }
        else
        {
            modeConfirm(str_AutoSway, KEEPY_MODE);//"确认进入自动横向模式?"
        }
    }
    else//已选择
    {
        if(btn16->styleSheet().contains("border-image:url(images/green")//已选择自动纵向
                && btn17->styleSheet().contains("border-image:url(images/green"))//已选择自动横向
        {
            modeConfirm(str_AutoHSu, KEEPYD_MODE);//"确认进入自动艏向+自动纵向模式?"
        }
        else if(btn16->styleSheet().contains("border-image:url(images/green"))//已选择自动艏向
        {
            modeConfirm(str_AutoHead, HEADING_MODE);//"确认进入自动艏向模式?"
        }
        else if(btn17->styleSheet().contains("border-image:url(images/green"))//已选择自动纵向
        {
            modeConfirm(str_AutoSurge, KEEPX_MODE);//"确认进入自动纵向模式?"
        }
        else
        {
            modeConfirm(str_JoyStick, MANUAL_MODE);//"确认进入手操模式?"

        }
    }
}

void KeyWidget::modeConfirm(QString msg, int set_mode)
{
    promptWidget->message =msg;
    promptWidget->targetState = set_mode;
    modeCondition(set_mode);
    promptWidget->show();
    this->setEnabled(false);
}


void KeyWidget::modeCondition(int set_mode)
{

    switch(set_mode)
    {
    case MANUAL_MODE:
        break;
    case HEADING_MODE:
        if(State_Gyro == 1)//&& Ready_prop1 == 1 && Ready_prop2 == 1 && Ready_prop3 == 1))
        {
            promptWidget->message = str_nomatch_autohead;//"不符合进入自动艏向模式的条件!"
            promptWidget->targetState = -1;
        }
        break;
    default:
        break;
    }

//    if(set_mode == MANUAL_MODE)
//    {
//        if(!(joystick_x == 0 && joystick_y ==0 && joystick_z ==0))
//        {
//            promptWidget->message = str_nomatch_joystick;//"不符合进入手操模式的条件!"
//            promptWidget->set_mode = -1;
//        }
//    }
//    else if(set_mode == HEADING_MODE)
//    {
//        if(!(State_Gyro == 1 && Ready_prop1 == 1 && Ready_prop2 == 1 && Ready_prop3 == 1))
//        {
//            promptWidget->message = str_nomatch_autohead;//"不符合进入自动艏向模式的条件!"
//            promptWidget->set_mode = -1;
//        }
//    }
//    else if(set_mode == KEEPXY_MODE)
//    {
//        //if(!(State_GPS1 == 0 && State_GPS2 == 0 && Ready_prop1 == 1 && Ready_prop2 == 1 && Ready_prop3 == 1))
//        if(1)
//        {
//            promptWidget->message = str_nomatch_surgesway;//"不符合进入自动纵向+横向模式的条件!"
//            promptWidget->set_mode = -1;
//        }
//    }
//    else if(set_mode == KEEPPOS_MODE)
//    {
//        if(!(State_Gyro == 0 && State_GPS1 == 0 && State_GPS2 == 0 &&Ready_prop1 == 1 && Ready_prop2 == 1 && Ready_prop3 == 1))
//        {
//            promptWidget->message = str_nomatch_poskeep;//"不符合进入位置保持模式的条件!"
//            promptWidget->set_mode = -1;
//        }
//    }
//    else if(set_mode == AUTOPLT_MODE)
//    {

//        if( speed_u < 5)
//        {
//            promptWidget->message = str_nomatch_autopilot;//"不符合进入自动舵模式的条件!"
//            promptWidget->set_mode = -1;
//        }
//    }
}

//void KeyWidget::btnTurnIn_clicked()//转入
//{

//}

//void KeyWidget::btnTurnOut_clicked()//转出
//{
//}

void KeyWidget::btnFullForce_clicked()//全推力
{
    if(flag_fullprop == true){
        flag_fullprop = false;
    }
    else{
        flag_fullprop = true;
    }
}

void KeyWidget::btnForePivot_clicked()//船艏
{
        point_rot = 1;
}

void KeyWidget::btnCentrePivot_click()//船舯
{
        point_rot = 0;
}

void KeyWidget::btnAftPivot_click()//船艉
{
        point_rot = 2;
}

void KeyWidget::changeMode(bool ok)//改变模式  参数  是否改变
{
    //2016.10.01 btn11(当前首向)移动至refreshData()函数中处理
    this->setEnabled(true);
    if(!ok) return;

//    btn9->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//待机
//    btn10->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//待机
//    btn11->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//当前艏向
//    btn12->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//手操
//    btn13->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//位置保持
//    btn14->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//自动舵
//    btn16->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//自动艏向
//    btn17->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//自动纵向
//    btn18->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");//自动横向

//    if(Operate_mode == READY_MODE)//待机
//    {
//        btn10->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//待机
//    }
//    else if(Operate_mode == MANUAL_MODE)//手操
//    {
//        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//手操
//    }
//    else if(Operate_mode == KEEPPOS_MODE)//位置保持
//    {
//        btn13->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//位置保持
//        btn16->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动艏向
//        btn17->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动纵向
//        btn18->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动横向
//        btn11->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//当前艏向
//        set_heading = heading;
//        set_east = pos_east;
//        set_north = pos_north;
//    }
//    else if(Operate_mode == AUTOPLT_MODE)//自动舵
//    {
//        btn11->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//当前艏向
//        btn14->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动舵

//        set_heading = heading;
//    }
//    else if(Operate_mode == HEADING_MODE)//自动艏向
//    {
//        btn11->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//当前艏向
//        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//手操
//        btn16->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动艏向
//        set_heading = heading;
//    }
//    else if(Operate_mode == KEEPX_MODE)//自动纵向
//    {
//        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//手操
//        btn17->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动纵向
//        set_pos_x = pos_x;
//    }
//    else if(Operate_mode == KEEPY_MODE)//自动横向
//    {
//        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//手操
//        btn18->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动横向
//        set_pos_y = pos_y;
//    }
//    else if(Operate_mode == KEEPXD_MODE)//
//    {
//        btn11->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//当前艏向
//        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//手操
//        btn16->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动艏向
//        btn17->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动纵向
//        set_heading = heading;
//        set_pos_x = pos_x;

//    }
//    else if(Operate_mode == KEEPYD_MODE)
//    {
//        btn11->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//当前艏向
//        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//手操
//        btn16->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动艏向
//        btn18->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动横向
//        set_heading = heading;
//        set_pos_y = pos_y;
//    }
//    else if(Operate_mode == KEEPXY_MODE)
//    {
//        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//手操
//        btn17->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动纵向
//        btn18->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");//自动横向

//        set_pos_x = pos_x;
//        set_pos_y = pos_y;
//    }

}

//void KeyWidget::changeCurrentHead()
//{
//    btn11->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
//}

//固定、释放 按键区域
void KeyWidget::fixKeyArea()
{
    btn26->setEnabled(false);
}

void KeyWidget::unFixKeyArea()
{
    btn26->setEnabled(true);
}


void KeyWidget::btnSimulate_clicked(){
    //只能在待机模式下，才能进入或退出仿真
    //fbk_controlMode 0待机，1手操
    //qDebug()<<"KeyWidget::btnSimulate_clicked()"<<fbk_controlMode;
    if( fbk_controlMode == 0 ){
        //Run_mode 1仿真；2实船；3测试
        if(Run_mode != 1){
            Run_mode = 1;
        }
        else{
            Run_mode = 2;
        }
        //qDebug()<<"KeyWidget::btnSimulate_clicked()"<<"inside"<<Run_mode<<fbk_StateSimulation;
    }
}

void KeyWidget::refreshData()//按键区刷新
{
    if(fbk_rotateCenter == 1)//船艏，亮
    {
        btn19->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn19FlashCount =0;
    }
    else if(btn19FlashCount%4 >=2 && point_rot ==1 )//闪烁亮
    {
        btn19->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn19FlashCount ++;
    }
    else//闪烁灭或彻底灭
    {
        btn19->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
        btn19FlashCount ++;
    }
    if(fbk_rotateCenter == 0)//船舯，亮
    {
        btn20->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn20FlashCount =0;
    }
    else if(btn20FlashCount%4 >=2 && point_rot ==0)//闪烁亮
    {
        btn20->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn20FlashCount ++;
    }
    else//闪烁灭或彻底灭
    {
        btn20->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
        btn20FlashCount ++;
    }

    if(fbk_rotateCenter == 2)//船艉，亮
    {
        btn21->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn21FlashCount =0;
    }
    else if(btn21FlashCount%4 >=2 && point_rot ==2)//闪烁亮
    {
        btn21->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn21FlashCount ++;
    }
    else//闪烁灭或彻底灭
    {
        btn21->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
        btn21FlashCount ++;
    }

//当前艏向按钮
    if( (Operate_mode == KEEPPOS_MODE || Operate_mode == AUTOPLT_MODE || Operate_mode == HEADING_MODE)//位置保持、自动舵，自动艏向
            &&( headTunningFinished ) )//调节完成
        btn11->setStyleSheet("border-image:url(:/images/greenbtn.png);color: rgb(52, 52, 52);");
    else
        btn11->setStyleSheet("border-image:url(:/images/whitebtn.png);color: rgb(52, 52, 52);");

//仿真按钮
    if(fbk_StateSimulation == true)//仿真，亮
    {
        btn27->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
    }
    else if(btn27FlashCount%4 >=2 && Run_mode == 1)//闪烁亮
    {
        btn27->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn27FlashCount ++;
    }
    else//闪烁灭或彻底灭
    {
        btn27->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
        btn27FlashCount ++;
    }

//待机按钮
    if(fbk_controlMode == 0)//待机，亮
    {
        btn10->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
    }
    else if(btn10FlashCount%4 >=2 && Operate_mode == READY_MODE)//闪烁亮
    {
        btn10->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn10FlashCount ++;
    }
    else//闪烁灭或彻底灭
    {
        btn10->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
        btn10FlashCount ++;
    }

//手操按钮
    if(fbk_controlMode == MANUAL_MODE && !fbk_StateAutoHeading)//手操，亮
    {
        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
    }
    else if(btn12FlashCount%4 >=2 && Operate_mode == MANUAL_MODE)//闪烁亮
    {
        btn12->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn12FlashCount ++;
    }
    else//闪烁灭或彻底灭
    {
        btn12->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
        btn12FlashCount ++;
    }

//自动首向
    if( fbk_StateAutoHeading )//自动首向，亮
    {
        btn16->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
    }
    else if(btn16FlashCount%4 >=2 && Operate_mode == HEADING_MODE)//闪烁亮
    {
        btn16->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
        btn16FlashCount ++;
    }
    else//闪烁灭或彻底灭
    {
        btn16->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
        btn16FlashCount ++;
    }

//令牌
    if( stat_master )//令牌，亮
    {
        btn22->setStyleSheet("border-image:url(:/images/greenbtn.png);color:rgb(52, 52, 52);");
    }
    else//彻底灭
    {
        btn22->setStyleSheet("border-image:url(:/images/whitebtn.png);color:rgb(52, 52, 52);");
    }

//2016.10.28新增，遮盖区域。没有控制权时就不能操作该区域按钮
    if( stat_master ){
        disableCover->setVisible( false );
    }
    else{
        disableCover->setVisible( true );
    }

//全推力按钮
    if(flag_fullprop == false)
    {
        btn9->setStyleSheet("border-image:url(:/images/whitebtn.png);");
    }
    else
    {
        btn9->setStyleSheet("border-image:url(:/images/greenbtn.png);");
    }
}

void KeyWidget::currentUsrChanged(){
    quint8 level;
    _manager->getNameAndLevel(0,&level);
    if(level>0){
        disableCover2->setVisible(false);
    }
    else{
        disableCover2->setVisible(true);
    }
}
