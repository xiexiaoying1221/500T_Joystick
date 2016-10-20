#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "modbusdataprocess.h"
#include"dataCommit.h"
#include"qglobal.h"


ModbusDataProcess::ModbusDataProcess(QObject *parent) :
    QObject(parent)
{
      dataThread = new QThread(this);
      modbusdata.moveToThread(dataThread);
      dataThread->start();
      modbusdata.startRoll();

      recv_timer = new QTimer();
      send_timer = new QTimer();
      watchDog = new QTimer();

      connect(recv_timer,SIGNAL(timeout()),this,SLOT( RefreshRecvData()));
      recv_timer->start(500);
      connect(send_timer,SIGNAL(timeout()),this,SLOT( RefreshSendData()));
      send_timer->start(500);

      connect(watchDog,SIGNAL(timeout()),this,SLOT( RefreshWatchDog()));
      watchDog->start(10 * 1000);
      watchDogOK = false;
      lastHeartBeats = 0;

}
ModbusDataProcess::~ModbusDataProcess()
{
    dataThread->deleteLater();
    recv_timer->deleteLater();
    send_timer->deleteLater();
    watchDog->deleteLater();
}

void ModbusDataProcess::RefreshRecvData()
{
//    int i = 0;
//    int j = 0;
//    //控制系统状态等
//    for(i=0,j=0;i<7;i++,j++)
//    {
//        //modbusdata.readBool_buff(&CCdata_bool[i],8192+j,j);
//        modbusdata.readBool_buff(&CCdata_bool[i],8192,j);
//        //qDebug()<<"CCDataBool3"<<CCdata_int[0]<<CCdata_bool[3];
//    }
//    //电罗经数据
//    for(i=7,j=0;i<11;i++,j++)
//    {
//        modbusdata.readBool_buff(&CCdata_bool[i],8193,j);
//    }
//    //风速风向仪数据
//    for(i=11,j=0;i<15;i++,j++)
//    {
//        modbusdata.readBool_buff(&CCdata_bool[i],8194,j);
//    }
//    //推进器使能信号状态
//    for(i=15,j=0;i<20;i++,j++)
//    {
//        modbusdata.readBool_buff(&CCdata_bool[i],8196,j);
//    }
//    //推进器就绪信号状态
//    for(i=20,j=0;i<25;i++,j++)
//    {
//        modbusdata.readBool_buff(&CCdata_bool[i],8197,j);
//    }
//    //推进器硬件错误报警
//    for(i=25,j=0;i<30;i++,j++)
//    {
//        modbusdata.readBool_buff(&CCdata_bool[i],8198,j);
//    }
//    //推进器跟随错误报警
//    for(i=30,j=0;i<35;i++,j++)
//    {
//        modbusdata.readBool_buff(&CCdata_bool[i],8199,j);
//    }
//    //当前控制模式、当前控制增益、当前旋转中心编号、当前控制器心跳
//    for(i=0,j=0;i<4;i++,j+=2)
//    {
//        modbusdata.readUint32_buff(&CCdata_int[i],8208+j);
////        qDebug()<<"CCdata_int:"<<CCdata_int[0];
//    }
//    //所有浮点数
//    for(i=0,j=0;i<430;i++,j+=2)
//    {
//        modbusdata.readFloat_buff(&CCdata_float[i],8216+j);
//    }



//----------------将cc收到的数据赋给界面显示的变量-------------//
    //传感器就绪
    bool temp_bool;
    modbusdata.readBool_buff(&temp_bool,8193,0);
    if(temp_bool == true){
        State_Gyro = 0;//正常
    }
    else State_Gyro = 1;//未就绪

    modbusdata.readBool_buff(&temp_bool,8194,0);
    if(temp_bool == true)
    {
        State_Wind = 0;//正常
    }
    else State_Wind = 1;//未就绪

    //qDebug()<<"----otrecv----state:"<<State_Gyro<<State_Wind;
   //推进器就绪
    modbusdata.readBool_buff(&fbk_StateReady,             8192,0);
    modbusdata.readBool_buff(&fbk_StateSimulation,        8192,1);
    modbusdata.readBool_buff(&fbk_StateBypass,            8192,2);
    modbusdata.readBool_buff(&fbk_StateAutoHeading,       8192,3);
    modbusdata.readBool_buff(&headTunningFinished,        8192,4);
    modbusdata.readBool_buff(&jsReqSwitch,                8192,5);

    modbusdata.readBool_buff(&Ready_prop1,      8196,0);
    modbusdata.readBool_buff(&Ready_prop2,      8196,1);
    modbusdata.readBool_buff(&Ready_prop3,      8196,2);
    modbusdata.readBool_buff(&Ready_rudder1,    8196,3);
    modbusdata.readBool_buff(&Ready_rudder2,    8196,4);

    modbusdata.readBool_buff(&Run_prop1,        8197,0);
    modbusdata.readBool_buff(&Run_prop2,        8197,1);
    modbusdata.readBool_buff(&Run_prop3,        8197,2);
    modbusdata.readBool_buff(&Run_rudder1,      8197,3);
    modbusdata.readBool_buff(&Run_rudder2,      8197,4);

//qDebug()<<Ready_prop1<<Ready_prop2<<Ready_prop3<<Ready_rudder1<<Ready_rudder2;
    modbusdata.readUint32_buff(&cc_hearbeat,    8214);
    modbusdata.readUint32_buff(&fbk_rotateCenter, 8212);
    modbusdata.readUint32_buff(&fbk_controlMode,8208);


//    qDebug()<<"cc_heartBeat"<<cc_hearbeat<<watchDogOK<<lastHeartBeats;
    if(cc_hearbeat == 0 || watchDogOK == false)
    {
        CCdata_alarm[15] = true;//控制器通信故障
    }
    else
        CCdata_alarm[15] = false;

    modbusdata.readFloat_buff(&Rwind_spd,       8228);
    modbusdata.readFloat_buff(&Rwind_dir,       8226);

    modbusdata.readFloat_buff(&mes_heading,     8216);
    modbusdata.readFloat_buff(&heading,         8218);

    modbusdata.readFloat_buff(&speed_r,  8220);
    modbusdata.readFloat_buff(&mes_winddir,     8222);
    modbusdata.readFloat_buff(&mes_windspd,     8224);

    //qDebug()<<"----otrecv----wind:"<<Rwind_spd<<Rwind_dir;

    modbusdata.readFloat_buff(&fbk_prop1_spd,   8254);
    modbusdata.readFloat_buff(&cmd_prop1_spd,   8256);

    modbusdata.readFloat_buff(&fbk_prop2_pitch, 8258);
    modbusdata.readFloat_buff(&cmd_prop2_pitch, 8260);

    modbusdata.readFloat_buff(&fbk_prop3_pitch, 8262);
    modbusdata.readFloat_buff(&cmd_prop3_pitch, 8264);

    modbusdata.readFloat_buff(&fbk_rudder1_ang, 8266);
    modbusdata.readFloat_buff(&cmd_rudder1_ang, 8268);

    modbusdata.readFloat_buff(&fbk_rudder2_ang, 8270);
    modbusdata.readFloat_buff(&cmd_rudder2_ang, 8272);

//    modbusdata.readFloat_buff(&cmd_Fx,          8286);
//    modbusdata.readFloat_buff(&cmd_Fy,          8288);
//    modbusdata.readFloat_buff(&cmd_Nz,          8290);

    modbusdata.readFloat_buff(&fbk_Fx,          8292);
    modbusdata.readFloat_buff(&fbk_Fy,          8294);
    modbusdata.readFloat_buff(&fbk_Nz,          8296);

    //qDebug()<<"----otrecv---- fx,fy,nz:"<<cmd_Fx<<cmd_Fy<<cmd_Nz;
    //qDebug()<<"----otrecv---- fbk_fx,fy,nz:"<<fbk_Fx<<fbk_Fy<<fbk_Nz;

    //控制器报警数据获取
    modbusdata.readBool_buff(&CCdata_alarm[0],  8192,6);//控制器硬件损坏报警
    modbusdata.readBool_buff(&CCdata_alarm[1],  8193,2);//罗经硬件报警
    modbusdata.readBool_buff(&CCdata_alarm[2],  8193,3);//罗经野值报警
    modbusdata.readBool_buff(&CCdata_alarm[3],  8194,2);//气象仪硬件报警
    modbusdata.readBool_buff(&CCdata_alarm[4],  8194,3);//气象仪野值报警
    modbusdata.readBool_buff(&CCdata_alarm[5],  8198,0);//艏侧推硬件损坏报警
    modbusdata.readBool_buff(&CCdata_alarm[6],  8198,1);//左主推硬件损坏报警
    modbusdata.readBool_buff(&CCdata_alarm[7],  8198,2);//右主推硬件损坏报警
    modbusdata.readBool_buff(&CCdata_alarm[8],  8198,3);//左舵硬件损坏报警
    modbusdata.readBool_buff(&CCdata_alarm[9],  8198,4);//右舵硬件损坏报警
    modbusdata.readBool_buff(&CCdata_alarm[10], 8199,0);//艏侧推跟随错误报警
    modbusdata.readBool_buff(&CCdata_alarm[11], 8199,1);//左主推跟随错误报警
    modbusdata.readBool_buff(&CCdata_alarm[12], 8199,2);//右主推跟随错误报警
    modbusdata.readBool_buff(&CCdata_alarm[13], 8199,3);//左舵跟随错误报警
    modbusdata.readBool_buff(&CCdata_alarm[14], 8199,4);//右舵跟随错误报警

    //控制器提示信息获取
    modbusdata.readBool_buff(&CCdata_info[0],   8192,0);//控制器状态（0-未就绪，1-启动）
    modbusdata.readBool_buff(&CCdata_info[1],   8193,0);//罗经就绪
    modbusdata.readBool_buff(&CCdata_info[2],   8194,0);//气象仪就绪
    modbusdata.readBool_buff(&CCdata_info[3],   8196,0);//艏侧推就绪信号状态
    modbusdata.readBool_buff(&CCdata_info[4],   8196,1);//左主推就绪信号状态
    modbusdata.readBool_buff(&CCdata_info[5],   8196,2);//右主推就绪信号状态
    modbusdata.readBool_buff(&CCdata_info[6],   8196,3);//左舵就绪信号状态
    modbusdata.readBool_buff(&CCdata_info[7],   8196,4);//右舵就绪信号状态
    CCdata_info[8] = jsReqSwitch;//Joystick模式开关状态
}

void ModbusDataProcess::RefreshSendData()
{
    //return;
    if(Run_mode == 1)//仿真模式
    {
        modbusdata.writeBool_buff(true,		24576,0);//仿真模式使能-T
        modbusdata.writeBool_buff(false,	24577,0);//旁路模式使能-F
        //仿真值
        modbusdata.writeFloat_buff(100.0, 	24618);
        modbusdata.writeFloat_buff(0.5, 	24620);
        modbusdata.writeFloat_buff(0.5, 	24622);
        modbusdata.writeFloat_buff(300.0, 	24624);

        //qDebug()<<"仿真模式";
    }
    else if(Run_mode == 2)//实船模式
    {
        modbusdata.writeBool_buff(false,	24576,0);//仿真模式使能-F
        modbusdata.writeBool_buff(false,	24577,0);//旁路模式使能-F
        //qDebug()<<"实船模式";
    }
    else
    {
        modbusdata.writeBool_buff(true,24577,0);//旁路模式使能-T
        modbusdata.writeBool_buff(false,24576,0);//仿真模式使能-F
        //qDebug()<<"仿真模式";
    }

//    modbusdata.writeBool_buff(true,24576,0);//仿真模式使能-T
//    modbusdata.writeBool_buff(false,24577,0);//仿真模式使能-F

    if(Operate_mode == 4)//自动艏向模式
    {
        modbusdata.writeBool_buff(true,24578,0);//自动艏向使能-true
    }
    else
    {
        modbusdata.writeBool_buff(false,24578,0);//自动艏向使能-false
    }

    //qDebug()<<"----otsend----Enable_gyro_on:"<<Enable_gyro_on;
    modbusdata.writeBool_buff(Enable_gyro_on,24579,0);//罗经使能
    modbusdata.writeBool_buff(Enable_wind_on,24580,0);//风速风向仪使能
    //modbusdata.writeBool_buff(Run_mode,24581,0);//GNSS使能
    modbusdata.writeBool_buff(Enable_prop1_on,24582,0);//艏侧推使能
    modbusdata.writeBool_buff(Enable_prop2_on,24583,0);//左主推使能
    modbusdata.writeBool_buff(Enable_prop3_on,24584,0);//右主推使能
    modbusdata.writeBool_buff(Enable_rudder1_on,24585,0);//左舵使能
    modbusdata.writeBool_buff(Enable_rudder2_on,24586,0);//右舵使能
    modbusdata.writeBool_buff(flag_windcomp,24587,0);//风力补偿标志

    //gainlevel = 2;

    //qDebug()<<"----otsend----gainlevel:"<<gainlevel;
    //qDebug()<<"----otsend----point_rot:"<<point_rot;
    modbusdata.writeUint32_buff((quint32)Operate_mode,24608);//控制模式请求
    modbusdata.writeUint32_buff((quint32)gainlevel,24610);//控制器增益
    modbusdata.writeUint32_buff((quint32)set_maxRudderAngle,24616);//最大允许舵角
    modbusdata.writeUint32_buff((quint32)point_rot,24612);//旋转中心编
    modbusdata.writeUint32_buff(1,24614);//shouxianjiaojiasudu--xiesiwei 1

    //qDebug()<<point_rot<<fbk_rotateCenter;
    //joystick_y = 0.1;
    //qDebug()<<"----otsend----joystick_y:"<<joystick_y;
    modbusdata.writeFloat_buff(0,24616);//最大允许舵角
    modbusdata.writeFloat_buff(joystick_y,24626);//手操杆横向力
    modbusdata.writeFloat_buff(joystick_x,24628);//手操杆纵向力
    modbusdata.writeFloat_buff(joystick_z,24630);//手操杆扭矩
    modbusdata.writeFloat_buff(set_heading,24632);//艏向目标值
    modbusdata.writeFloat_buff(set_rot,24634);//艏向角速度目标值

}


void ModbusDataProcess::RefreshWatchDog(){
    if(cc_hearbeat <= lastHeartBeats ){
        watchDogOK = false;
    }
    else{
        watchDogOK = true;
    }
    lastHeartBeats = cc_hearbeat;
}
