#ifndef DATACOMMIT_H
#define DATACOMMIT_H

//#include <QString>
//#include <QtDebug>
//#include <QtMath>
//#include <iostream>
//#include <math.h>

#include "loadsaveprocessorxml.h"
#include "globalSettings.h"

#define SHIP_CZ 0
#define SHIP_JD 1
#define SHIP_BK 0

/*
#if SHIP_CZ

#define SHIP_LEN 135
#define MAX_FX 1016
#define MAX_FY 640
#define MAX_MZ 44212
#define MAX_FPROP1 640
#define MAX_FPROP2 631
#define MAX_FPROP3 631
#define M 4390000
#define M_X 0
#define M_Y 0
#define I_Z 0
#define J_Z 0
#define SHIP_L1 60.35
#define SHIP_L2 5.5

#endif
*/
#if SHIP_JD
/*
#define MAX_F1 164
#define MIN_F1 -164
#define MAX_F23 379
#define MIN_F23 -376
#define SHIP_LEN 135
#define MAX_FX 164
#define MAX_FY 758
#define MAX_MZ 44212

#define MAX_FPROP1 640
#define MAX_FPROP2 631
#define MAX_FPROP3 631
#define MAX_RUDDER 12425 //max liju

#define MAX_FPROP1 350
#define MAX_FPROP2 750
#define MAX_FPROP3 750
#define MAX_RUDDER 363300 //max liju
*/
#define MAX_FPROP1 164000
#define MAX_FPROP2 379000
#define MAX_FPROP3 379000
#define MAX_RUDDER 255128 //max liju
#define MAX_SPEED 0.95 //船模最大航速 m/s，最大航速13节

#define READY_MODE 0
#define MANUAL_MODE 1
#define KEEPPOS_MODE 2
#define AUTOPLT_MODE 3
#define HEADING_MODE 4
#define KEEPX_MODE 5
#define KEEPY_MODE 6
#define KEEPXD_MODE 7
#define KEEPYD_MODE 8
#define KEEPXY_MODE 9
#define LAMBDA 50  //suochibi
#define KSPEED 1.94 //速度系数

#endif

#define LOOP_TIME 0.3//单位s
#define PI 3.1416

extern float mes_heading;
extern float mes_winddir;
extern float mes_windspd;
//x轴，前后。定义Max为最前，定义Min为最后
extern float setStickXMax;//前进到底
extern float setStickXZero;//前后零位
extern float setStickXMin;//后退到底
extern float setStickXDeadband;//前后的零位死区
//y轴，左右。定义Max为最右，定义Min为最左
extern float setStickYMax;//右移到底
extern float setStickYZero;//左右零位
extern float setStickYMin;//左移到底
extern float setStickYDeadband;//左右的零位死区
//z轴，左右旋转。定义Max为最右转，定义Min为最左转
extern float setStickZMax;//右转到底
extern float setStickZZero;//左右转零位
extern float setStickZMin;//左转到底
extern float setStickZDeadband;//左右转的零位死区

extern quint32 cc_hearbeat;
extern quint32 fbk_rotateCenter;
extern quint32 fbk_controlMode;
extern bool stat_master;

extern unsigned short State_cc_net1;
extern unsigned short State_cc_net2;
extern unsigned short State_cc_com1;
extern unsigned short State_cc_com2;
extern unsigned short State_cc_com3;
extern unsigned short State_cc_com4;
extern unsigned short State_cc_com5;
extern unsigned short State_cc_com6;

extern unsigned short State_ot_net1;
extern unsigned short State_ot_net2;
extern unsigned short State_ot_CAN1;
extern unsigned short State_ot_CAN2;

extern QString State_language;



//_Sensor_Data
//data of sensor-from eth
extern unsigned short mode_GPS;//A=自主定位，D=差分，E=估算，M=手工输入，S=仿真，N=数据无效
extern float latitude;//WEI
extern unsigned char semi_latitude;
extern float longitude;//JING
extern unsigned char semi_longitude;
extern float speed;
extern float speed_u;
extern float speed_v;
extern float speed_r;
extern float T_heading;

extern long utc_time;//1970年至今的秒数，time_t
extern float Rwind_dir;//范围0.00~359.99
extern float Rwind_spd;
extern float Twind_dir;
extern float Twind_spd;
extern short unit_wind;
extern float heading;//范围0.00~359.99
extern float roll;//范围-90.00~90.00
extern float pitch;//范围-90.00~90.00
extern float pos_north;
extern float pos_east;


//_Btns_Msg

//btns respone
extern unsigned short btn_dim;
extern unsigned short btnlight_dim;
extern unsigned short screen_light;
extern unsigned short btn_test;
extern unsigned short btnlight_test;
extern unsigned short btn_answer;
extern unsigned short btnlight_answer;
extern unsigned short btn_view;
extern unsigned short btn_system;
extern unsigned short btn_daynight;
extern unsigned short btn_alm;
extern unsigned short btn_general_setup;
extern unsigned short btn_sensor;
extern unsigned short btn_prop;
extern unsigned short btn_limitset;
extern unsigned short btn_setautop;
extern unsigned short btn_fullforce;
extern unsigned short btn_take;
extern unsigned short btnlight_take;
extern unsigned short btn_give;
extern unsigned short btnlight_give;
extern unsigned short btn_stdby;
extern unsigned short btnlight_stdby;
extern unsigned short btn_joystick;
extern unsigned short btnlight_joystick;
extern unsigned short btn_poskeeping;
extern unsigned short btnlight_poskeeping;
extern unsigned short btn_autopilot;
extern unsigned short btnlight_autopilot;
extern unsigned short btn_autoheading;
extern unsigned short btnlight_autoheading;
extern unsigned short btn_autosurge;
extern unsigned short btnlight_autosurge;
extern unsigned short btn_autosway;
extern unsigned short btnlight_autosway;
extern unsigned short btn_presentheading;
extern unsigned short btnlight_presentheading;
extern unsigned short btn_headingset;
extern unsigned short btnlight_headingset;
extern unsigned short btn_language;


//_OT_SettingData
extern unsigned short Run_mode;//1仿真；2实船；3测试
extern unsigned short Operate_mode;//1待机，2手操，3位置保持,4自动舵，5自动艏向，6自动纵向，7自动横向，8自动艏向自动纵向，9自动艏向自动横向，10自动纵向自动横向
extern float set_heading;
extern float set_north;
extern float set_east;
extern float set_rot;
extern float set_spd;
extern float set_pos_x;
extern float set_pos_y;
extern float joystick_x;//baifenbi,
extern float joystick_y;
extern float joystick_z;//fanwei[-100,100]
extern float masterJoystick_x;
extern float masterJoystick_y;
extern float masterJoystick_z;
extern short gain_prop;//1-全推力，0-50%推力
extern bool flag_fullprop;
extern short point_rot;//1:船首，0：船舯，-1：船艉
extern bool flag_warningh;//1-yes,0-no
extern float Warning_head;//default:3
extern bool flag_alarmh;
extern float Alarm_head;//default:5
extern bool flag_warningp;
extern float Warning_pos;//default:5
extern bool flag_alarmp;
extern float Alarm_pos;//default:10
extern bool flag_windcomp;
extern short mode_thrAlloc;
extern short drughttype;
extern short gain_autopilot;
extern float max_rudangle;
extern int gainlevel;
extern float set_maxRudderAngle;
extern bool flag_weathercomp;
extern unsigned int avlb_power;
extern unsigned int real_power;
extern short part_operate;
extern bool Enable_gps1_on;
extern bool Enable_gps2_on;
extern bool Enable_wind_on;
extern bool Enable_gyro_on;
extern bool Enable_vrs_on;
extern bool Enable_prop1_on;
extern bool Enable_prop2_on;
extern bool Enable_prop3_on;
extern bool Enable_rudder1_on;
extern bool Enable_rudder2_on;

extern unsigned short State_GPS1;//值为0 正常;值为1 GPS未就绪(橙色 其余都是红 位置参考系统);值为2  位置数据丢失;值为3 参考位置数据冻结;值为4 参考数据方差过大
extern unsigned short State_GPS2;//值为0 正常;值为1 GPS未就绪(橙色 其余都是红 位置参考系统);值为2  位置数据丢失;值为3 参考位置数据冻结;值为4 参考数据方差过大
extern unsigned short State_Wind;//值为0 正常;值为1 wind未就绪(橙色 其余都是红 );值为2 wind故障;值为3 拒用的风速风向仪数据
extern unsigned short State_Gyro;//值为0 正常;值为1 Gyro未就绪;值为2 艏向数据预测错误;值为3 艏向数据丢失;值为4 1号陀螺罗经数据预测错误
extern unsigned short State_VRS;//值为0 正常;值为1 VRS未就绪
extern unsigned short State_Spd;//值为0 正常;值为1 速度传感器 未就绪
//OT ALARM DATA
extern bool OTdata_alarm[10];
//控制器发送的数据
extern bool CCdata_bool[41];
extern unsigned int CCdata_int[4];
//extern float CCdata_float[43];
extern bool CCdata_alarm[20];//报警信息
extern bool CCdata_info[20];//提示信息



extern float Power_sum;
extern float Power_now;


extern float cmd_prop1_pitch;
extern float cmd_prop2_pitch;
extern float cmd_prop3_pitch;
extern float cmd_prop1_spd;
extern float cmd_prop2_spd;
extern float cmd_prop3_spd;
extern float cmd_rudder1_ang;
extern float cmd_rudder2_ang;


extern float cmd_Fx;
extern float cmd_Fy;
extern float cmd_Nz;
//extern float cmd_prop1_spd;
//extern float cmd_prop2_spd;
//extern float cmd_prop3_spd;
//extern float cmd_rudder1_spd;
//extern float cmd_rudder2_spd;
extern float cmd_prop1_force;
extern float cmd_prop2_force;
extern float cmd_prop3_force;
extern float cmd_rudder1_force;
extern float cmd_rudder2_force;

extern float cmd_f1 ;//推力分配给艏侧推的推力指令
extern float cmd_f2 ;//推力分配给艉左主推的推力指令
extern float cmd_f3 ;//推力分配给艉右主推的推力指令
extern float cmd_f4 ;//推力分配给左舵机的推力指令
extern float cmd_f5 ;//推力分配给右舵机的推力指令
extern float cmd_Fx ;//x手柄推进值对应的推力指令
extern float cmd_Fy ;//y手柄推进值对应的推力指令
extern float cmd_Nz ;//z手柄推进值对应的推力指令
extern float cmd_Fx_old[10];//由手柄推进值及环境力求得的纵向推力指令
extern float cmd_Fy_old[10];//由手柄推进值及环境力求得的横向推力指令
extern float cmd_Nz_old[10];//由手柄推进值及环境力求得的转向推力指令


extern bool jsReqSwitch;//Joystick模式开关
extern bool headTunningFinished;//自动艏向调节完成
extern short switch2Joystick;
extern bool Ready_prop1;
extern bool Ready_prop2;
extern bool Ready_prop3;
extern bool Ready_rudder1;
extern bool Ready_rudder2;
extern bool Run_prop1;
extern bool Run_prop2;
extern bool Run_prop3;
extern bool Run_rudder1;
extern bool Run_rudder2;
extern bool fbk_StateReady;
extern bool fbk_StateSimulation;
extern bool fbk_StateBypass;
extern bool fbk_StateAutoHeading;

extern float fbk_prop1_pitch;
extern float fbk_prop2_pitch;
extern float fbk_prop3_pitch;
extern float fbk_prop1_spd;
extern float fbk_prop2_spd;
extern float fbk_prop3_spd;
extern float fbk_rudder1_ang;
extern float fbk_rudder2_ang;
extern float fbk_f1;//艏侧推实际推力反馈
extern float fbk_f2;//艉左主推实际推力反馈
extern float fbk_f3;//艉右主推实际推力反馈
extern float fbk_f4;//左舵机实际推力反馈
extern float fbk_f5;//右舵机实际推力反馈
extern float fbk_Fx;
extern float fbk_Fy;
extern float fbk_Nz;

extern float Fwind_1;//抵抗风力的艏侧推力
extern float Fwind_2;//抵抗风力的艉左主推推力
extern float Fwind_3;//抵抗风力的艉右主推推力

extern float Fwind_x;//抵抗风力的纵向推力
extern float Fwind_y;//抵抗风力的横向推力
extern float Fwind_z;//抵抗风力的艏向推力矩

extern float Fx;//由手柄推进值及环境力求得的纵向推力指令,该值用来求船舶模型运动状态求解
extern float Fy;//由手柄推进值及环境力求得的横向推力指令,该值用来求船舶模型运动状态求解
extern float Nz;//由手柄推进值及环境力求得的转向推力指令,该值用来求船舶模型运动状态求解
extern float Fx_Alloc;//由手柄推进值及环境力求得的纵向推力指令
extern float Fy_Alloc;//由手柄推进值及环境力求得的横向推力指令
extern float Nz_Alloc;//由手柄推进值及环境力求得的转向推力指令


 //gloable data

extern float MAX_Fsum;//船舶推力最大合力
extern float MAX_Nsum;//船舶推力最大合力矩
extern float F_sum;//当前船舶推进器推力合力大小
extern float F_ang;//当前船舶推进器推力合力方向
extern float N_sum;//当前船舶推进器推力合力矩

extern float MAX_F1;//艏侧推最大推力，最小推力为-3.39
extern float MAX_F23;//艉主推最大推力，最小推力-5.65，左、右主推一样。
extern float MAX_PROP1_SPD;//艏侧推最大转速


extern float MAX_FX;
extern float MAX_FY;
extern float MAX_NZ;
extern float ship_m;
extern float ship_mx;
extern float ship_my;
extern float ship_iz;
extern float ship_jz;
extern float ship_l1;
extern float ship_l2;
extern float SHIP_LEN;
extern float SHIP_WIDTH;

extern float u_old;
extern float v_old;
extern float r_old;

extern float cmd_f1_old;
extern float cmd_f2_old;
extern float cmd_f3_old;


extern bool isManual_first;
extern bool isReady_first;
extern bool isKeeppos_first;
extern bool isAutoplt_first;
extern bool isHeading_first;
extern bool isKeepX_first;
extern bool isKeepY_first;
extern bool isKeepXD_first;
extern bool isKeepYD_first;
extern bool isKeepXY_first;

extern bool daynight_mode;

extern float pos_x;
extern float pos_y;


float SwitchJoy2Force(float joyvalue,short dim);
extern void InitData(bool forced = false);
void HandleWind();
void ControlMain();
void RunShipModel();

extern int saveParameters(void);
extern int loadParameters(void);

extern short qHIWORD(int data);
extern short qLOWORD(int data);
extern char qHIBYTE(short data);
extern char qLOBYTE(short data);


#endif // DATACOMMIT_H

