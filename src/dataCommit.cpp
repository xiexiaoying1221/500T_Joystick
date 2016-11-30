#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "dataCommit.h"

float mes_heading = 0.0;
float mes_winddir = 0.0;
float mes_windspd = 0.0;

float setStickXMax;
float setStickXZero;
float setStickXMin;
float setStickXDeadband;

float setStickYMax;
float setStickYZero;
float setStickYMin;
float setStickYDeadband;

float setStickZMax;
float setStickZZero;
float setStickZMin;
float setStickZDeadband;

quint32 cc_hearbeat = 0;
quint32 fbk_rotateCenter = 0;
quint32 fbk_controlMode = 0;
bool stat_master=false;

unsigned short State_cc_net1 = 0;//0-正常；1-异常
unsigned short State_cc_net2 = 0;
unsigned short State_cc_com1 = 0;
unsigned short State_cc_com2 = 0;
unsigned short State_cc_com3 = 0;
unsigned short State_cc_com4 = 0;
unsigned short State_cc_com5 = 0;
unsigned short State_cc_com6 = 0;

unsigned short State_ot_net1 = 0;
unsigned short State_ot_net2 = 0;
unsigned short State_ot_CAN1 = 0;
unsigned short State_ot_CAN2 = 0;

QString State_language = "Chinese";


//_Sensor_Data
//data of sensor-from eth
unsigned short mode_GPS = 0;//A=自主定位，D=差分，E=估算，M=手工输入，S=仿真，N=数据无效
float latitude = 0.0;//WEI
unsigned char semi_latitude = 0;
float longitude = 0.0;//JING
unsigned char semi_longitude = 0;
float speed = 0.0;
float speed_u = 0.0;
float speed_v = 0.0;
float speed_r = 0.0;
float T_heading = 0.0;

long utc_time = 0;//1970年至今的秒数，time_t
float Rwind_dir= 0.0;//相对风向，范围0.00~359.99
float Rwind_spd = 0.0;//相对风速
float Twind_dir = 0.0;
float Twind_spd = 0.0;
short unit_wind = 0;
float heading = 0.0;//范围0.00~359.99
float roll = 0.0;//范围-90.00~90.00
float pitch = 0.0;//范围-90.00~90.00
float pos_north = 0.0;
float pos_east = 0.0;


//_Btns_Msg

//btns respone
unsigned short btn_dim = 0;
unsigned short btnlight_dim = 0;
unsigned short screen_light = 0;
unsigned short btn_test = 0;
unsigned short btnlight_test = 0;
unsigned short btn_answer = 0;
unsigned short btnlight_answer = 0;
unsigned short btn_view = 0;
unsigned short btn_system = 0;
unsigned short btn_daynight = 0;
unsigned short btn_alm = 0;
unsigned short btn_general_setup = 0;
unsigned short btn_sensor = 0;
unsigned short btn_prop = 0;
unsigned short btn_limitset = 0;
unsigned short btn_setautop = 0;
unsigned short btn_fullforce = 0;
unsigned short btn_take = 0;
unsigned short btnlight_take = 0;
unsigned short btn_give = 0;
unsigned short btnlight_give = 0;
unsigned short btn_stdby = 0;
unsigned short btnlight_stdby = 0;
unsigned short btn_joystick = 0;
unsigned short btnlight_joystick = 0;
unsigned short btn_poskeeping = 0;
unsigned short btnlight_poskeeping = 0;
unsigned short btn_autopilot = 0;
unsigned short btnlight_autopilot = 0;
unsigned short btn_autoheading = 0;
unsigned short btnlight_autoheading = 0;
unsigned short btn_autosurge = 0;
unsigned short btnlight_autosurge = 0;
unsigned short btn_autosway = 0;
unsigned short btnlight_autosway = 0;
unsigned short btn_presentheading = 0;
unsigned short btnlight_presentheading = 0;
unsigned short btn_headingset = 0;
unsigned short btnlight_headingset = 0;
unsigned short btn_language = 0;


//_OT_SettingData

unsigned short Run_mode = 1;//1仿真；2实船；3测试
unsigned short Operate_mode = 0;//1待机，2手操，3位置保持,4自动舵，5自动艏向，6自动纵向，7自动横向，8自动艏向自动纵向，9自动艏向自动横向，10自动纵向自动横向
float set_heading = 0.0;
float set_north = 0.0;
float set_east = 0.0;
float set_rot = 0.3;
float set_spd = 0.0;
float set_pos_x = 0.0;
float set_pos_y = 0.0;
float joystick_x = 0;//百分比，保留一位小数
float joystick_y = 0;
float joystick_z = 0;//范围[-100.0,100.0]

float masterJoystick_x = 0.0;
float masterJoystick_y = 0.0;
float masterJoystick_z = 0.0;

short gain_prop = 0;//1-全推力，0-50%推力
bool flag_fullprop = false;
short point_rot = 0;//1:船首，0：船舯，-1：船艉
bool flag_warningh = false;//1-yes,0-no
float Warning_head = 3;//default:3
bool flag_alarmh = false;
float Alarm_head = 5;//default:5
bool flag_warningp = true;
float Warning_pos = 5;//default:5
bool flag_alarmp = true;
float Alarm_pos = 10;//default:10
bool flag_windcomp = false;
short mode_thrAlloc = 0;
short drughttype = 0;
short gain_autopilot = 0;
float max_rudangle = 35;
int gainlevel = 0;
int set_maxRudderAngle = 45;
bool flag_weathercomp = false;
unsigned int avlb_power = 0;
unsigned int real_power = 0;
short part_operate = 0;
bool Enable_gps1_on = false;
bool Enable_gps2_on = false;
bool Enable_wind_on = false;
bool Enable_gyro_on = false;
bool Enable_vrs_on = false;
bool Enable_prop1_on = false;
bool Enable_prop2_on = false;
bool Enable_prop3_on = false;
bool Enable_rudder1_on = false;
bool Enable_rudder2_on = false;


unsigned short State_GPS1 = 0;//值为0 正常;值为1 GPS未就绪(橙色 其余都是红 位置参考系统);值为2  位置数据丢失;值为3 参考位置数据冻结;值为4 参考数据方差过大
unsigned short State_GPS2 = 0;//值为0 正常;值为1 GPS未就绪(橙色 其余都是红 位置参考系统);值为2  位置数据丢失;值为3 参考位置数据冻结;值为4 参考数据方差过大
unsigned short State_Wind = 0;//值为0 正常;值为1 wind未就绪(橙色 其余都是红 );值为2 wind故障;值为3 拒用的风速风向仪数据
unsigned short State_Gyro = 0;//值为0 正常;值为1 Gyro未就绪;值为2 艏向数据预测错误;值为3 艏向数据丢失;值为4 1号陀螺罗经数据预测错误
unsigned short State_VRS = 0;//值为0 正常;值为1 VRS未就绪
unsigned short State_Spd = 0;//值为0 正常;值为1 速度传感器 未就绪
//OT alarm data
bool OTdata_alarm[10] = {0};


//控制器发送的数据
//bool CCdata_bool[41] = {0};
unsigned int CCdata_int[4] = {0};
//float CCdata_float[43] = {0.0};
bool CCdata_alarm[20] = {0};
bool CCdata_info[20] = {0};//提示信息

float Power_sum = 0.0;
float Power_now = 0.0;


//float cmd_prop1_spd = 0.0;
//float cmd_prop2_spd = 0.0;
//float cmd_prop3_spd = 0.0;
//float cmd_rudder1_spd = 0.0;
//float cmd_rudder2_spd = 0.0;

float cmd_prop1_pitch = 0.0;
float cmd_prop2_pitch = 0.0;
float cmd_prop3_pitch = 0.0;
float cmd_prop1_spd = 0.0;
float cmd_prop2_spd = 0.0;
float cmd_prop3_spd = 0.0;
float cmd_rudder1_ang = 0.0;
float cmd_rudder2_ang = 0.0;

float cmd_f1 = 0.0;//推力分配给艏侧推的推力指令
float cmd_f2 = 0.0;//推力分配给艉左主推的推力指令
float cmd_f3 = 0.0;//推力分配给艉右主推的推力指令
float cmd_f4 = 0.0;//推力分配给左舵机的推力指令
float cmd_f5 = 0.0;//推力分配给右舵机的推力指令
float cmd_Fx = 0.0;//x手柄推进值对应的推力指令
float cmd_Fy = 0.0;//y手柄推进值对应的推力指令
float cmd_Nz = 0.0;//z手柄推进值对应的推力指令
float cmd_Fx_old[10] = {0.0};
float cmd_Fy_old[10] = {0.0};
float cmd_Nz_old[10] = {0.0};

bool jsReqSwitch = false;//Joystick模式开关
bool headTunningFinished = false;//自动艏向调节完成
short switch2Joystick = 0;
bool Ready_prop1 = 0;
bool Ready_prop2 = 0;
bool Ready_prop3 = 0;
bool Ready_rudder1 = 0;
bool Ready_rudder2 = 0;
bool Run_prop1 = 0;
bool Run_prop2 = 0;
bool Run_prop3 = 0;
bool Run_rudder1 = 0;
bool Run_rudder2 = 0;

bool fbk_StateReady = 0;
bool fbk_StateSimulation = 0;
bool fbk_StateBypass = 0;
bool fbk_StateAutoHeading = 0;

float fbk_prop1_pitch = 0.0;
float fbk_prop2_pitch = 0.0;
float fbk_prop3_pitch = 0.0;
float fbk_prop1_spd = 0.0;
float fbk_prop2_spd = 0.0;
float fbk_prop3_spd = 0.0;
float fbk_rudder1_ang = 0.0;
float fbk_rudder2_ang = 0.0;
float fbk_f1 = 0.0;//艏侧推实际推力反馈
float fbk_f2 = 0.0;//艉左主推实际推力反馈
float fbk_f3 = 0.0;//艉右主推实际推力反馈
float fbk_f4 = 0.0;//左舵机实际推力反馈
float fbk_f5 = 0.0;//右舵机实际推力反馈
float fbk_Fx = 0.0;//x手柄推进值对应的推力反馈
float fbk_Fy = 0.0;//y手柄推进值对应的推力反馈
float fbk_Nz = 0.0;//z手柄推进值对应的推力反馈

float Fwind_1 = 0.0;//抵抗风力的艏侧推力
float Fwind_2 = 0.0;//抵抗风力的艉左主推推力
float Fwind_3 = 0.0;//抵抗风力的艉右主推推力

float Fwind_x = 0.0;//抵抗风力的纵向推力
float Fwind_y = 0.0;//抵抗风力的横向推力
float Fwind_z = 0.0;//抵抗风力的艏向推力矩

float Fx = 0.0;//由手柄推进值及环境力求得的纵向推力指令,该值用来求船舶模型运动状态求解
float Fy = 0.0;//由手柄推进值及环境力求得的横向推力指令,该值用来求船舶模型运动状态求解
float Nz = 0.0;//由手柄推进值及环境力求得的转向推力指令,该值用来求船舶模型运动状态求解
float Fx_Alloc = 0.0;//由手柄推进值及环境力求得的纵向推力指令
float Fy_Alloc = 0.0;//由手柄推进值及环境力求得的横向推力指令
float Nz_Alloc = 0.0;//由手柄推进值及环境力求得的转向推力指令


//gloable data

float MAX_Fsum = 0.0;//船舶推力最大合力
float MAX_Nsum = 0.0;//船舶推力最大合力矩
float F_sum = 0.0;//当前船舶推进器推力合力大小
float F_ang = 0.0;//当前船舶推进器推力合力方向
float N_sum = 0.0;//当前船舶推进器推力合力矩

float MAX_F1 = 1.5;//艏侧推最大推力，最小推力为-3.39
float MAX_F23 = 5.85;//艉主推最大推力，最小推力-5.65，左、右主推一样。
float MAX_PROP1_SPD = 20;//艏侧推最大转速,20RPS

float MAX_PX = 11.3;//推进器提供的X轴最大推力
float MAX_PY = 3.39;//推进器提供的Y轴最大推力
float MAX_PZ = 5.12;//推进器提供的Z轴最大推力

float MAX_RX = 0.0;//舵提供Y轴最大推力
float MAX_RY = 0.0;//舵提供X轴最大推力
float MAX_RZ = 0.0;//

float MAX_FX = (390 * 1000); //纵荡最大力	390kN
float MAX_FY = (20 * 1000);  //横荡最大力	20kN
float MAX_NZ = (820 * 1000); //最大回转力矩820kNm

float ship_m = 552.2;
float ship_mx = 43.0;
float ship_my = 38.2;
float ship_iz = 350.0;
float ship_jz = 225.0;
float ship_l1 = 1.038;
float ship_l2 = 0.112;
float SHIP_LEN = 134.0;
float SHIP_WIDTH = 22.0;//实船型宽

float set_heading_old = 0.0;

float u_old = 0.0;
float v_old = 0.0;
float r_old = 0.0;

float cmd_f1_old = 0.0;
float cmd_f2_old = 0.0;
float cmd_f3_old = 0.0;
float cmd_f4_old = 0.0;
float cmd_f5_old = 0.0;

//初次进入各模式的标志
bool isManual_first = false;
bool isReady_first = false;
bool isKeeppos_first = false;
bool isAutoplt_first = false;
bool isHeading_first = false;
bool isKeepX_first = false;
bool isKeepY_first = false;
bool isKeepXD_first = false;
bool isKeepYD_first = false;
bool isKeepXY_first = false;

//自动艏向模式用到的全局变量
float heading_give = 0.0;//步长
float heading_diff = 0.0;//当前艏向与设定艏向间的偏差
short turn_direc = 0;//旋转方向，1：顺时针，-1：逆时针

float stop_diff = 1.0;

//位置保持模式用到的全局变量
float east_give = 0.0,north_give = 0.0;

//自动纵向或自动横向时的全局变量
float pos_x = 0.0;
float pos_y = 0.0;
float acpt_diff = 0.005;

//白天、夜晚模式
bool daynight_mode = true; // 1 白天 0 夜晚
//功耗
float Max_power1 = 600.0;
float Max_power23 = 4500.0;



float HeadingControl();
void AutoPlt_ShipModule();
void PointControl();
float KeepX_ShipModule();
float KeepY_ShipModule();
void KeepXD_ShipModule();
void KeepYD_ShipModule();

short qHIWORD(int data)
{
    short hiword = 0;
    hiword = (short)(data>>16);
    return hiword;
}
short qLOWORD(int data)
{
    short loword = 0;
    loword = (short)data;
    return loword;
}
char qHIBYTE(short data)
{
    char hibyte = 0;
    hibyte = (char)(data>>8);
    return hibyte;
}
char qLOBYTE(short data)
{
    char lobyte = 0;
    lobyte = (char)(data);
    return lobyte;
}


void InitData(bool forced)
{
    int ret = loadParameters();

    if(ret!=0  || forced){

        //初始化环境力-初始化传感器数据
        mode_GPS = 65;//A=自主定位，D=差分，E=估算，M=手工输入，S=仿真，N=数据无效
        latitude = 31.1294444;//北纬31 7 46;
        semi_latitude = 0;//0-北纬，1-南纬
        longitude = 121.3736111;//东经121 22 25;
        semi_longitude = 0;//0-东经，1-西经
        speed = 0.0;//速度--北东坐标系
        speed_u = 0.0;//纵向速度--船体坐标系
        speed_v = 0.0;//横向速度--船体坐标系
        speed_r = 0.0;//回转率--船体坐标系
        T_heading = 0.0;//正北
        set_rot = 0.3;


        Twind_dir = 10.5;//设定绝对风向为10度
        Rwind_dir = 10.5;//相对风向，与船舶艏向角有关
        Rwind_spd = 5.0;//相对风速，为10m/s

        heading = 0.0;//艏向角
        pos_north = 0.0;
        pos_east = 0.0;

        MAX_Fsum = 15.0;//船舶推力最大合力-粗略值
        MAX_Nsum = 6.0;//船舶推力最大合力矩-粗略值

        point_rot = 0;//1:船首，0：船舯，2：船艉

        Operate_mode = READY_MODE;//开机第一次运行，待机模式
        //isReady_first = true;
        //qDebug()<<"111Rwind_spd is %f"<<Rwind_spd;

        Power_sum = Max_power1 + 2.0 * Max_power23;//单位kW
#ifdef PORTABLE_STATION
        setStickXMax = (float)0x0129;//前进到底
        setStickXMin = (float)0x0020;//后退到底
        setStickXZero = (setStickXMax - setStickXMin)/2 + setStickXMin;//前后零位
        setStickXDeadband = (float)0x0010;//前后的零位死区

        setStickYMax = (float)0x0127;//右移到底
        setStickYMin = (float)0x0020;//左移到底
        setStickYZero = (setStickYMax - setStickYMin)/2 + setStickYMin;//左右零位
        setStickYDeadband = (float)0x0010;//左右的零位死区

        setStickZMax = (float)0x00FA;//右转到底
        setStickZMin = (float)0x004A;//左转到底
        setStickZZero = (setStickZMax - setStickZMin)/2 + setStickZMin;//左右转零位
        setStickZDeadband = (float)0x0010;//左右转的零位死区
#else
        setStickXMax = 8.089;//前进到底
        setStickXMin = 0.976;//后退到底
        setStickXZero = (setStickXMax - setStickXMin)/2 + setStickXMin;//前后零位
        setStickXDeadband = 0.2;//前后的零位死区

        setStickYMax = 8.089;//右移到底
        setStickYMin = 0.976;//左移到底
        setStickYZero = (setStickYMax - setStickYMin)/2 + setStickYMin;//左右零位
        setStickYDeadband = 0.2;//左右的零位死区

        setStickZMax = 8.089;//右转到底
        setStickZMin = 0.976;//左转到底
        setStickZZero = (setStickZMax - setStickZMin)/2 + setStickZMin;//左右转零位
        setStickZDeadband = 0.2;//左右转的零位死区
#endif
        saveParameters();
    }
}
int saveParameters(void){
    int ret;
    iLoadSaveProcessor* processor;
    processor = new loadSaveProcessorXml(0,false);
    ret = processor->transactionStart();
    if(ret != 0){
        delete processor;
        return -1;
    }
    processor->saveParameters("setStickXMax",       QString::number(setStickXMax));
    processor->saveParameters("setStickXMin",       QString::number(setStickXMin));
    processor->saveParameters("setStickXZero",      QString::number(setStickXZero));
    processor->saveParameters("setStickXDeadband",  QString::number(setStickXDeadband));
    processor->saveParameters("setStickYMax",       QString::number(setStickYMax));
    processor->saveParameters("setStickYMin",       QString::number(setStickYMin));
    processor->saveParameters("setStickYZero",      QString::number(setStickYZero));
    processor->saveParameters("setStickYDeadband",  QString::number(setStickYDeadband));
    processor->saveParameters("setStickZMax",       QString::number(setStickZMax));
    processor->saveParameters("setStickZMin",       QString::number(setStickZMin));
    processor->saveParameters("setStickZZero",      QString::number(setStickZZero));
    processor->saveParameters("setStickZDeadband",  QString::number(setStickZDeadband));

    ret = processor->saveFile("jsParameter.xml");
    if(ret != 0){
        delete processor;
        return -1;
    }
    delete processor;
    return 0;
}

int loadParameters(void){
    int ret;
    QString temp;
    iLoadSaveProcessor* processor;
    processor = new loadSaveProcessorXml(0,false);
    ret = processor->transactionStart();
    if(ret != 0){
        delete processor;
        return -1;
    }
    ret = processor->loadFile("jsParameter.xml");
    if(ret != 0){
        delete processor;
        return -1;
    }
    processor->loadParameters("setStickXMax",&temp);
    setStickXMax = temp.toFloat();
    processor->loadParameters("setStickXMin",&temp);
    setStickXMin = temp.toFloat();
    processor->loadParameters("setStickXZero",&temp);
    setStickXZero = temp.toFloat();
    processor->loadParameters("setStickXDeadband",&temp);
    setStickXDeadband = temp.toFloat();
    processor->loadParameters("setStickYMax",&temp);
    setStickYMax = temp.toFloat();
    processor->loadParameters("setStickYMin",&temp);
    setStickYMin = temp.toFloat();
    processor->loadParameters("setStickYZero",&temp);
    setStickYZero = temp.toFloat();
    processor->loadParameters("setStickYDeadband",&temp);
    setStickYDeadband = temp.toFloat();
    processor->loadParameters("setStickZMax",&temp);
    setStickZMax = temp.toFloat();
    processor->loadParameters("setStickZMin",&temp);
    setStickZMin = temp.toFloat();
    processor->loadParameters("setStickZZero",&temp);
    setStickZZero = temp.toFloat();
    processor->loadParameters("setStickZDeadband",&temp);
    setStickZDeadband = temp.toFloat();


    delete processor;
    return 0;
}

void RefreshData()
{

}

void PowerMoniter()
{

    float power1 = 0.0,power2 = 0.0,power3 = 0.0;
    power1 = fabs(Max_power1 * fbk_f1/MAX_F1);
    power2 = fabs(Max_power23 * fbk_f2/MAX_F23);
    power3 = fabs(Max_power23 * fbk_f3/MAX_F23);

    Power_now = (power1 + power2 + power3) * 0.8;

    if(Power_now > Power_sum)
        Power_now = Power_sum * 0.9;
}


void Modulespd2Shipspeed(float *speed_value)
{

    float multi = 0.0;
    float temp_spd = 0.0;

    multi = sqrt((float)LAMBDA);
//    qDebug()<<"speed is "<<*speed_value<<"multi is "<<multi;


    temp_spd = (*speed_value) * multi;
    *speed_value = temp_spd;
//    qDebug()<<"speed_value2="<<*speed_value;

}

//处理风力数据。设定流速为0节。风速为10m/s
//f1为首侧推力，f2为艉左推推力，f3为艉右推推力,Rwind_dir为相对风向角
//void HandleWind(float Rwind_dir,float *f1, float *f2, float *f3,float *fw_x,float *fw_y,float *fw_z)


//将dim对应自由度的手柄位移百分比值转换为推力值
float SwitchJoy2Force(float joyvalue,short dim)
{
    float force = 0.0;
    float max_force = 0.0;
    switch(dim)
    {
    case 1:
        max_force = MAX_FX;
        break;
    case 2:
        max_force = MAX_FY;
        break;
    case 3:
        max_force =  MAX_NZ;
        break;
    default:
        max_force = 0;
        break;
    }
    force = joyvalue * max_force*0.01;

    return force;
}

void JoystickCmd2Fbk()
{
    //由cmd_fx,cmd_fy,cmd_nz求出fbk_fx,fbk_fy,fbk_nz

    int i = 0;

//    fbk_Fx = 0.9 * cmd_Fx;
//    fbk_Fy = 0.9 * cmd_Fy;
//    fbk_Nz = 0.9 * cmd_Nz;
    fbk_Fx = cmd_Fx_old[5];
    fbk_Fy = cmd_Fy_old[5];
    fbk_Nz = cmd_Nz_old[5];


//    if(cmd_Fx == cmd_Fx_old[2] && cmd_Fx_old[2] == cmd_Fx_old[1] && cmd_Fx_old[1] == cmd_Fx_old[0])
 //       fbk_Fx = cmd_Fx;
 //   if(cmd_Fy == cmd_Fy_old[2] && cmd_Fy_old[2] == cmd_Fy_old[1] && cmd_Fy_old[1] == cmd_Fy_old[0])
//        fbk_Fy = cmd_Fy;
//    if(cmd_Nz == cmd_Nz_old[2])
//        fbk_Nz = cmd_Nz;


    cmd_Fx_old[0] = cmd_Fx;
    cmd_Fy_old[0] = cmd_Fy;
    cmd_Nz_old[0] = cmd_Nz;

    for(i = 9; i > 0 ; i--)
    {
        cmd_Fx_old[i] = cmd_Fx_old[i-1];
        cmd_Fy_old[i] = cmd_Fy_old[i-1];
        cmd_Nz_old[i] = cmd_Nz_old[i-1];
    }


}



//推力分配，分配的是手柄的推力指令。用于主视图区三推进器的进度条显示。
void ThrustAlloc()
{
    float nz_rest = 0.0;//除去侧推外，无法满足的剩余旋转力矩
    float max_n_y = 0.0;


    float diff_x = 0.0;//三角x

    //static float frest_old = 0.0;
    //qDebug()<<"Alloc input,FX_ALLOC,FY,NZ"<<Fx_Alloc<<Fy_Alloc<<Nz_Alloc;
    max_n_y = MAX_F23 * ship_l2;

    if(Fy_Alloc > MAX_PY)
    {
        cmd_f1 = MAX_PY;//艏侧推
    }
    else
    {
        cmd_f1 = Fy_Alloc;//艏侧推
    }

    //剔除野值
    if(fabs(cmd_f1 - cmd_f1_old) > 3)
        cmd_f1 = (cmd_f1_old - cmd_f1)/2.0;

    nz_rest = Nz_Alloc - cmd_f1 * ship_l1;
    //qDebug("***************************");
    //qDebug()<<"nz_rest"<<nz_rest;

    //推力分配 - 艏向优先

    if(nz_rest == 0)
    {
        cmd_f2 = cmd_f3 = Fy_Alloc/2;
    }

    else
    {
        if(nz_rest < (2.0*max_n_y))
        {
            if(nz_rest < max_n_y)
            {
                cmd_f2 = Fy_Alloc;
                //if(cmd_f2)
            }
            diff_x = (nz_rest/ship_l2 - Fx_Alloc)/2;

            cmd_f2 = diff_x + Fx_Alloc;
            cmd_f3 = -(diff_x);

            if(fabs(cmd_f2) > MAX_F23)
                cmd_f2 = MAX_F23 * cmd_f2/fabs(cmd_f2);
            if(fabs(cmd_f3) > MAX_F23)
                cmd_f3 = MAX_F23 * cmd_f3/fabs(cmd_f3);
        }
        else
        {

        }

    }


    fbk_f1 = 0.9 * cmd_f1;
    fbk_f2 = 0.9 * cmd_f2;
    fbk_f3 = 0.9 * cmd_f3;
    fbk_f4 = cmd_f4;
    fbk_f5 = cmd_f5;

    fbk_rudder1_ang = fbk_f4;
    fbk_rudder2_ang = fbk_f5;

    if(cmd_f1 == cmd_f1_old)
        fbk_f1 = cmd_f1;
    if(cmd_f2 == cmd_f2_old)
        fbk_f2 = cmd_f2;
    if(cmd_f3 == cmd_f3_old)
        fbk_f3 = cmd_f3;
    if(cmd_f4 == cmd_f2_old)
        fbk_f4 = cmd_f4;
    if(cmd_f5 == cmd_f5_old)
        fbk_f5 = cmd_f5;

    cmd_f1_old = cmd_f1;
    cmd_f2_old = cmd_f2;
    cmd_f3_old = cmd_f3;
    cmd_f4_old = cmd_f4;
    cmd_f5_old = cmd_f5;
    \
    //qDebug()<<"Alloc result，cmd f1,f2,f3"<<cmd_f1<<cmd_f2<<cmd_f3;

}

//船舶模型计算.求出船舶运动状态[u,v,r]。需要循环运行
void RunShipModel()
{
    int m=0;

    float m1 = ship_m + ship_mx;
    float m2 = ship_m + ship_my;
    float m3 = ship_iz + ship_jz;
    float temp1 = 0.0,temp2 = 0.0,temp3 = 0.0;
    //根据船舶所受的力（推力和环境力），求出船舶的运动状态[u,v,r]
    //qDebug()<<"looptime is"<<LOOP_TIME<<"LOOP_TIME is"<<LOOP_TIME;
    if(ship_iz != 0 || ship_jz != 0)
        speed_r = Nz*LOOP_TIME/m3+ r_old;
    else
        speed_r = 0;
    //Modulespd2Shipspeed(&speed_r);

    temp1 = Nz*LOOP_TIME*LOOP_TIME/m3+r_old*LOOP_TIME;//rt

    temp2 = Fy*LOOP_TIME+m2*v_old;// - (Fx+m1*u_old)*temp1;

    temp3 = m2;//*(1+temp1*temp1);

    if(temp3 != 0)
    {
        speed_v = temp2/temp3;
    }
    else
       speed_v = 0;


    //Modulespd2Shipspeed(&speed_v);


    temp2 = Fx*LOOP_TIME+m1*u_old;//+ (Fy+m2*v_old)*temp1;

    temp3 = m1;//*(1+temp1*temp1);

    if(temp3 != 0)
    {
        speed_u = temp2/temp3;
    }
    else
        speed_u = 0;


    if(fabs(speed_u) > MAX_SPEED)
        speed_u = MAX_SPEED * speed_u/fabs(speed_u);
    if(fabs(speed_v) > MAX_SPEED)
        speed_v = MAX_SPEED * speed_v/fabs(speed_v);


    //Modulespd2Shipspeed(&speed_u);

    //qDebug()<<"u "<<speed_u<<",v "<<speed_v<<",r \n"<<speed_r;
    //qDebug()<<"LOOP_TIME is"<<LOOP_TIME;

    //求船舶的艏向角及位置
    //qDebug()<<"00heading is"<<heading;
    heading = heading+speed_r*LOOP_TIME;

    if(heading >= 360 || heading < 0)
    {
        m = (int)heading/360;
        heading = heading-m*360;
        if(heading < 0)
            heading = heading+360;
    }

    //qDebug()<<"heading is"<<heading<<"speed_r is"<<speed_r;


    speed = sqrt(speed_u*speed_u+speed_v*speed_v);   

    pos_north = pos_north + speed * sin(heading*PI/180.0) * LOOP_TIME;
    pos_east = pos_east + speed * cos(heading*PI/180.0) * LOOP_TIME;

    //根据船舶艏向角和绝对风向角，求出相对风向角
    Rwind_dir = Twind_dir - heading;

    if(Rwind_dir >= 360 || Rwind_dir < 0)
    {
        m = (int)Rwind_dir/360;
        //qDebug()<<"m is"<<m;
        Rwind_dir = Rwind_dir-m*360;
        if(Rwind_dir < 0)
            Rwind_dir = Rwind_dir+360;
        //qDebug()<<"Rwind_dir is"<<Rwind_dir;
    }



    u_old = speed_u;
    v_old = speed_v;
    r_old = speed_r;

    //qDebug()<<"heading is"<<heading<<"pos is "<<pos_north<<pos_east;
    //qDebug()<<"speed is"<<speed;
    //qDebug()<<"Rwind_dir is"<<Rwind_dir;

}



//----------------------------控制主程序--（操作模式处理）-----------------------------------------------------------
//Operate_mode = 0;//1待机，2手操，3位置保持,4自动舵，5自动艏向，6自动纵向，7自动横向，8自动艏向自动纵向，9自动艏向自动横向，10自动纵向自动横向
void ControlMain()
{
    switch(Operate_mode)
    {
    case READY_MODE:
        //待机模式
//        Fx = 0;//Fwind_x;
//        Fy = 0;//Fwind_y;
//        Nz = 0;//Fwind_z;
        Fx = Fwind_x;
        Fy = Fwind_y;
        Nz = Fwind_z;

        //qDebug()<<"111 FXYZ TO MODEL "<<Fx<<Fy<<Nz;
        RunShipModel();

        cmd_Fx = 0.0;
        cmd_Fy = 0.0;
        cmd_Nz = 0.0;

        cmd_f1 = 0.0;
        cmd_f2 = 0.0;
        cmd_f3 = 0.0;
        cmd_f4 = 0.0;
        cmd_f5 = 0.0;
        fbk_f1 = 0.0;
        fbk_f2 = 0.0;
        fbk_f3 = 0.0;
        fbk_f4 = 0.0;
        fbk_f5 = 0.0;

//        Fx_Alloc = 0;
//        Fy_Alloc = 0;
//        Nz_Alloc = 0;

//        ThrustAlloc();
        break;
    case MANUAL_MODE:
        //手操

        //船舶状态，速度，艏向，位置
        Fx = cmd_Fx + Fwind_x;
        Fy = cmd_Fy + Fwind_y;
        Nz = cmd_Nz + Fwind_z;

        //qDebug()<<"cmd_fx,fy"<<cmd_Fx<<cmd_Fy<<"find_x,y"<<Fwind_x<<Fwind_y;
        //qDebug()<<"222 FXYZ TO MODEL "<<Fx<<Fy<<Nz;
        RunShipModel();
        //qDebug()<<"speed_u ,speed_v"<<speed_u<<speed_v<<Fx<<Fy;

        //位置区，求手柄推进进度条值cmd和fbk
        JoystickCmd2Fbk();

        //视图区，各推进器进度条值
        Fx_Alloc = cmd_Fx;
        Fy_Alloc = cmd_Fy;
        Nz_Alloc = cmd_Nz;
        ThrustAlloc();

        //qDebug()<<"u,v,r is"<<speed_u<<speed_v<<speed_r;


        break;
    case KEEPPOS_MODE:
        //位置保持
//        temp_fx = ship_m * speed_u/LOOP_TIME;
//        temp_fy = ship_m * speed_v/LOOP_TIME;
//        temp_nz = ship_iz * speed_r/LOOP_TIME;

//        Fx = temp_fx -Fwind_x;
//        Fy = temp_fy -Fwind_y;
//        Nz = temp_nz -Fwind_z;
        PointControl();//求出Fx和Fy,速度，位置，艏向等
        Nz = HeadingControl();//求出Nz

        //求出新的船舶运动状态，速度，位置，艏向等
        //RunShipModel();

        if(fabs(heading-set_heading) < stop_diff)
        {
            heading = set_heading;
            speed_r = 0.0;
            Nz = 0.0;
        }


        Fx_Alloc = Fx;
        Fy_Alloc = Fy;
        Nz_Alloc = Nz;

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();



        break;
    case AUTOPLT_MODE:

        //求出船舶运动状态和方位值，和Fx。
        AutoPlt_ShipModule();

        Fy = 0;

        Fx_Alloc = Fx;
        Fy_Alloc = 0.0;

        if(set_heading != heading)
        {
            Nz = HeadingControl();
            Nz_Alloc = Nz;
        }
        else
        {
            Nz_Alloc = Fwind_z;
            Nz = 0.0;
        }




        //给出位置区手柄推进值显示进度条的值，自动舵下只显示纵向的推力值。
        cmd_Fy = 0.0;
        cmd_Nz = 0.0;
        JoystickCmd2Fbk();

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();

        break;
    case HEADING_MODE:
        Fx = cmd_Fx + Fwind_x;
        Fy = cmd_Fy + Fwind_y;
        Nz = 0;
        RunShipModel();

        Nz = HeadingControl();

        JoystickCmd2Fbk();

        Fx_Alloc = Fx-Fwind_x;
        Fy_Alloc = Fy-Fwind_y;
        Nz_Alloc = Nz-Fwind_z;

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();

        break;
    case KEEPX_MODE:
        //自动定纵模式
        cmd_Fx =0.0;
        Fx = KeepX_ShipModule();
        Fy = cmd_Fy;
        Nz = cmd_Nz;

        JoystickCmd2Fbk();

        Fx_Alloc = Fx - Fwind_x;
        Fy_Alloc = Fy - Fwind_y;
        Nz_Alloc = Nz - Fwind_z;

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();

        break;
    case KEEPY_MODE:
        //自动横向模式
        cmd_Fy =0.0;
        Fx = cmd_Fx;
        Fy = KeepY_ShipModule();
        Nz = cmd_Nz;
        JoystickCmd2Fbk();

        Fx_Alloc = Fx - Fwind_x;
        Fy_Alloc = Fy - Fwind_y;
        Nz_Alloc = Nz - Fwind_z;

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();

        break;
    case KEEPXD_MODE:
        //自动纵向+自动艏向模式
        cmd_Fx = 0.0;
        cmd_Nz = 0.0;
        Fy = cmd_Fy;
        KeepXD_ShipModule();//求出定纵+定艏向需要的Fx和Nz

        JoystickCmd2Fbk();

        Fx_Alloc = Fx - Fwind_x;
        Fy_Alloc = Fy - Fwind_y;
        Nz_Alloc = Nz - Fwind_z;

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();

        //qDebug()<<"----xd mode-----";
        //qDebug()<<"speed u v r"<<speed_u<<speed_v<<speed_r;
        //qDebug()<<"Fx Fy Nz"<<Fx<<Fy<<Nz;

        break;
    case KEEPYD_MODE:
        //自动横向+自动艏向模式
        cmd_Fy = 0.0;
        cmd_Nz = 0.0;

        Fx = cmd_Fx;
        KeepYD_ShipModule();//求出定横+定艏向需要的Fy和Nz

        JoystickCmd2Fbk();

        Fx_Alloc = Fx - Fwind_x;
        Fy_Alloc = Fy - Fwind_y;
        Nz_Alloc = Nz - Fwind_z;

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();
        break;
    case KEEPXY_MODE:
        //自动横向+自动艏向模式
        cmd_Fx = 0.0;
        cmd_Fy = 0.0;

        PointControl();//求出Fx和Fy

        Nz = cmd_Nz - Fwind_z;


        JoystickCmd2Fbk();

        //求出新的船舶运动状态，速度，位置，艏向等
        //RunShipModel();

        if(fabs(heading-set_heading) < stop_diff)
        {
            heading = set_heading;
            speed_r = 0.0;
            Nz = 0.0;
        }

        Fx_Alloc = Fx;
        Fy_Alloc = Fy;
        Nz_Alloc = Nz;

        //给出视图区三个推进器的进度条显示值
        ThrustAlloc();
        break;


    default:
        break;

    }

}

void PointControl()
{

    static float set_east_old = 0.0, set_north_old = 0.0,ang = 0.0;
    float kk1 = 0.0, kk2 = 0.0,kk3 = 0.0;
    static float k_speed = 0.0;
    static int flag = 0;
    float a = 0.0;
    float x_diff = 0.0,y_diff = 0.0,Kpx = 15.0, Kpy = 5.0;

    //上一次设定值与当前设定值间的差（的平方）
    kk1 = (set_east_old - set_east)*(set_east_old - set_east) + (set_north_old-set_north)*(set_north_old-set_north);
    if(kk1 > 4 || isKeeppos_first == true)
    {
        isKeeppos_first =false;
        east_give = pos_east;
        north_give = pos_north;
        ang = atan2(set_east-pos_east,set_north-pos_north);//设定点与当前点间线段的角度
        set_east_old = set_east;
        set_north_old = set_north;

    }
    //设定点和当前位置点间的距离
    kk2 = sqrt((pos_east - set_east)*(pos_east - set_east) + (pos_north - set_north)*(pos_north - set_north));

    if(kk2 >= 50) k_speed = 0.3;
    if((kk2 >= 25) && (kk2 < 50)) k_speed = 0.2;
    if((kk2 < 25) &&  (kk2 >= 1))k_speed = 0.1;
    if(kk2 < 1) k_speed = 0.05;

    //设定点和给定点间的距离
    kk3 = sqrt((east_give - set_east)*(east_give - set_east) + (north_give - set_north)*(north_give - set_north));
    if(kk3 > 4 && flag != 1)
    {
        east_give = east_give + k_speed*LOOP_TIME*sin(ang);
        north_give = north_give + k_speed*LOOP_TIME*cos(ang);
    }
    else
    {
        east_give = set_east;
        north_give = set_north;
        flag = 1;
    }

    a = heading*PI/180;


    x_diff = sin(a)*(east_give - pos_east) + cos(a)*(north_give - pos_north);

    Fx = Kpx * x_diff;
    Fy = Kpy * y_diff;

    speed_u = k_speed * cos(heading * PI / 180.0);
    speed_v = k_speed * sin(heading * PI / 180.0);

    pos_north = east_give;
    pos_north = north_give;

    if(fabs(Fx) > MAX_FX) Fx = MAX_FX*Fx/fabs(Fx);
    if(fabs(Fy) > MAX_FY) Fy = MAX_FY*Fy/fabs(Fy);

}

//自动舵模式运动模型
//手柄纵向推进值代表速度。最大航速MAX_SPEED
void AutoPlt_ShipModule()
{
    int dirc = 0;
    float diff = 0.0;
    float kp = 10;

    ///////////////////////////////////////////////////////

//    cmd_f4 = 0.7 * max_rudangle * cmd_Fx/MAX_FX;
//    cmd_f5 = 0.7 * max_rudangle * cmd_Fx/MAX_FX;

//    fbk_rudder1_ang = fbk_f4 = max_rudangle * fbk_Fx/MAX_FX;
//    fbk_rudder2_ang = fbk_f5 = max_rudangle * fbk_Fx/MAX_FX;

    set_spd = joystick_x * 0.01 * MAX_SPEED;
    diff = set_spd - speed_u;
    dirc = (set_spd - speed_u)/fabs(set_spd - speed_u);

    if(fabs(diff) > 1.0)
    {
        speed_u = speed_u + dirc * 0.2;
    }
    else if(fabs(diff) < 1.0 && fabs(diff) > 0.01)
    {
        speed_u = speed_u + dirc*0.01;
    }
    else
    {
        speed_u = set_spd;
    }
    if(fabs(speed_u) > MAX_SPEED)
        speed_u = MAX_SPEED * speed_u/fabs(speed_u);

    Fx = kp * diff;

    if(fabs(speed_v)<0.01)
    {
        speed_v = 0.0;
    }

    else
        speed_v = v_old-0.1;



    if(fabs(speed_v) > MAX_SPEED)
        speed_v = MAX_SPEED * speed_v/fabs(speed_v);


    pos_east += speed_u * LOOP_TIME;
    pos_north += speed_v*LOOP_TIME;

    u_old = speed_u;
    v_old = speed_v;
    r_old = speed_r;
}

void KeepXD_ShipModule()
{
    static short speed_zero_first = 0;//0-初始值，1-第一次速度为零，2-第二次速度为零
    float org_speed = 0.0;


    if(isKeepXD_first == true)
    {
        pos_x = 0.0;
        pos_y = 0.0;
        set_east = pos_east;
        set_north = pos_north;
        org_speed = speed_u;

        isKeepXD_first = false;
    }

    if(fabs(speed_u) > 0.01)
    {
        if(speed_u > 0)
            speed_u = speed_u - 0.005;
        else if(speed_u <= 0)
            speed_u = speed_u + 0.005;
    }
    else
    {
        speed_u = 0.0;
        if(speed_zero_first == 0)
        {
            speed_zero_first = 1;
        }
        else
        {
            speed_zero_first = 2;
        }
    }
    if(speed_zero_first == 1)
    {
        speed_u = -org_speed;
    }
    //qDebug()<<"******u_old"<<u_old<<"speed_u"<<speed_u;
    //剔除野值，速度值变化超过允许差值acpt_diff即认为是野值，该值根据实船船速的允许范围得出
    if(fabs(speed_u - u_old) > acpt_diff)
        u_old = speed_u;
    //qDebug()<<"u_old"<<u_old<<"speed_u"<<speed_u;

    if(fabs(speed_u) > MAX_SPEED)
        speed_u = MAX_SPEED * speed_u/fabs(speed_u);
    if(fabs(speed_v) > MAX_SPEED)
        speed_v = MAX_SPEED * speed_v/fabs(speed_v);


    //Modulespd2Shipspeed(&speed_u);


    Fx = -(speed_u - u_old) * ship_m;

    if(fabs(Fx) > MAX_FX)
    {
        Fx = MAX_FX*Fx/fabs(Fx);
    }


    pos_x = pos_x + speed_u * LOOP_TIME;

    //qDebug()<<"pos_x "<<pos_x;
    speed_v = (Fy-Fwind_y)/ship_m;//v_old + (Fy-Fwind_y)/ship_m;
    //Modulespd2Shipspeed(&speed_v);

    pos_y += speed_v * LOOP_TIME;


    speed = sqrt(speed_u*speed_u+speed_v*speed_v);

    pos_north = pos_north + speed * sin(heading*PI/180.0) * LOOP_TIME;
    pos_east = pos_east + speed * cos(heading*PI/180.0) * LOOP_TIME;


    Nz = HeadingControl();

    u_old = speed_u;

}

void KeepYD_ShipModule()
{
    static short speed_zero_first = 0;//0-初始值，1-第一次速度为零，2-第二次速度为零
    float org_speed = 0.0;

    if(isKeepYD_first == true)
    {
        set_pos_x = 0.0;
        set_pos_y = 0.0;
        pos_x = 0.0;
        pos_y = 0.0;
        set_east = pos_east;
        set_north = pos_north;
        org_speed = speed_u;

        isKeepYD_first = false;
    }

    if(fabs(speed_v) > 0.01)
    {
        if(speed_v > 0)
            speed_v = speed_v - 0.005;
        else if(speed_v <= 0)
            speed_v = speed_v + 0.005;
    }
    else
    {
        speed_v = 0.0;
        if(speed_zero_first == 0)
        {
            speed_zero_first = 1;
        }
        else
        {
            speed_zero_first = 2;
        }
    }

    //剔除野值，速度值变化超过允许差值acpt_diff即认为是野值，该值根据实船船速的允许范围得出
    if(fabs(speed_v - v_old) > acpt_diff)
        v_old = speed_v;


    if(speed_zero_first == 1)
    {
        speed_v = -org_speed;
    }
    //Modulespd2Shipspeed(&speed_v);

    //qDebug()<<"pos_y"<<pos_y<<"set_pos_y"<<set_pos_y;


    Fy = -(speed_v - v_old) * ship_m;

    if(fabs(Fy) > MAX_FY)
    {
        Fy = MAX_FY*Fy/fabs(Fy);
    }


    pos_y = pos_y + speed_v * LOOP_TIME;



    //qDebug()<<"pos_y "<<pos_y;

    speed_u = (Fx-Fwind_x)/ship_m;//v_old + (Fy-Fwind_y)/ship_m;
    //Modulespd2Shipspeed(&speed_u);

    if(fabs(speed_u) > MAX_SPEED)
        speed_u = MAX_SPEED * speed_u/fabs(speed_u);
    if(fabs(speed_v) > MAX_SPEED)
        speed_v = MAX_SPEED * speed_v/fabs(speed_v);

    if(fabs(speed_u) < 0.05)
        speed_u = 0.0;


    pos_x += speed_u * LOOP_TIME;


    speed = sqrt(speed_u*speed_u+speed_v*speed_v);

    pos_north = pos_north + speed * sin(heading*PI/180.0) * LOOP_TIME;
    pos_east = pos_east + speed * cos(heading*PI/180.0) * LOOP_TIME;


    Nz = HeadingControl();

    if(fabs(heading-set_heading) < 0.2)
    {
        heading = set_heading;
        speed_r = 0.0;
        Nz = 0.0;
    }

    v_old = speed_v;

}



//定纵模式运动模型-返回值为定纵需要的纵向推力。同时计算得出speed_u,speed_v,speed_r,heading,pos_east,pos_north等船舶运动参数。
float KeepX_ShipModule()
{
    static short speed_zero_first = 0;//0-初始值，1-第一次速度为零，2-第二次速度为零
    float org_speed = 0.0;
    float needF = 0.0;


    if(isKeepX_first == true)
    {
        pos_x = 0.0;
        pos_y = 0.0;
        set_east = pos_east;
        set_north = pos_north;
        org_speed = speed_u;

        isKeepX_first = false;
    }

    if(fabs(speed_u) > 0.01)
    {
        if(speed_u > 0.0)
            speed_u = speed_u - 0.005;
        else if(speed_u <= 0.0)
            speed_u = speed_u + 0.005;

    }
    else
    {
        speed_u = 0.0;
        if(speed_zero_first == 0)
        {
            speed_zero_first = 1;
        }
        else
        {
            speed_zero_first = 2;
        }
    }
    if(speed_zero_first == 1)
    {
        speed_u = -org_speed;
    }

    //qDebug()<<"speed_u"<<speed_u;
    //剔除野值，速度值变化超过允许差值acpt_diff即认为是野值，该值根据实船船速的允许范围得出
    if(fabs(speed_u - u_old) > acpt_diff)
        u_old = speed_u;
    //Modulespd2Shipspeed(&speed_u);

    //qDebug()<<"speed u old"<<speed_u<<u_old;

    if(fabs(speed_u) > MAX_SPEED)
        speed_u = MAX_SPEED * speed_u/fabs(speed_u);
    if(fabs(speed_v) > MAX_SPEED)
        speed_v = MAX_SPEED * speed_v/fabs(speed_v);


    needF = -(speed_u - u_old) * ship_m;

    if(fabs(needF) > MAX_FX)
    {
        needF = MAX_FX*needF/fabs(needF);
    }


    pos_x = pos_x + speed_u * LOOP_TIME;

    speed_v = (Fy-Fwind_y)/ship_m;//v_old + (Fy-Fwind_y)/ship_m;

    if(fabs(speed_v) < 0.05)
        speed_v = 0.0;

    pos_y += speed_v * LOOP_TIME;

    speed_r = Nz/ship_iz *LOOP_TIME;// + r_old;

    if(fabs(speed_r) < 0.05) speed_r = 0.0;

    ///////////////////////////////////////////////

    heading = heading+speed_r*LOOP_TIME;

    speed = sqrt(speed_u*speed_u+speed_v*speed_v);

    pos_north = pos_north + speed * sin(heading*PI/180.0) * LOOP_TIME;
    pos_east = pos_east + speed * cos(heading*PI/180.0) * LOOP_TIME;



      u_old = speed_u;
//    v_old = speed_v;
//    r_old = speed_r;

      return needF;
}

//自动定横运动模型。返回定横需要的Y轴推力。
float KeepY_ShipModule()
{
    static short speed_zero_first = 0;//0-初始值，1-第一次速度为零，2-第二次速度为零
    float org_speed = 0.0;
    float needF = 0.0;

    if(isKeepY_first == true)
    {
        pos_x = 0.0;
        pos_y = 0.0;
        set_east = pos_east;
        set_north = pos_north;
        org_speed = speed_v;

        isKeepY_first = false;
    }

    if(fabs(speed_v) > 0.01)
    {
        if(speed_v > 0)
            speed_v = speed_v - 0.005;
        else if(speed_v <= 0)
            speed_v = speed_v + 0.005;
    }
    else
    {
        speed_v = 0.0;
        if(speed_zero_first == 0)
        {
            speed_zero_first = 1;
        }
        else
        {
            speed_zero_first = 2;
        }
    }

    //剔除野值，速度值变化超过允许差值acpt_diff即认为是野值，该值根据实船船速的允许范围得出
    if(fabs(speed_v - v_old) > acpt_diff)
        v_old = speed_v;


    if(speed_zero_first == 1)
    {
        speed_v = -org_speed;
    }

    if(fabs(speed_u) > MAX_SPEED)
        speed_u = MAX_SPEED * speed_u/fabs(speed_u);
    if(fabs(speed_v) > MAX_SPEED)
        speed_v = MAX_SPEED * speed_v/fabs(speed_v);

    //Modulespd2Shipspeed(&speed_v);

    needF = -(speed_v - v_old) * ship_m;
    if(fabs(needF) > MAX_FY)
    {
        needF = MAX_FY*needF/fabs(needF);
    }


    pos_y = pos_y + speed_v * LOOP_TIME;

    speed_u = (Fx-Fwind_x)/ship_m;//v_old + (Fy-Fwind_y)/ship_m;

    if(fabs(speed_u) < 0.05)
        speed_u = 0.0;

    pos_x += speed_u * LOOP_TIME;

    speed_r = Nz/ship_iz *LOOP_TIME;// + r_old;

    if(fabs(speed_r) < 0.05) speed_r = 0.0;

    ///////////////////////////////////////////////

    heading = heading+speed_r*LOOP_TIME;

    speed = sqrt(speed_u*speed_u+speed_v*speed_v);

    pos_north = pos_north + speed * sin(heading*PI/180.0) * LOOP_TIME;
    pos_east = pos_east + speed * cos(heading*PI/180.0) * LOOP_TIME;


//    u_old = speed_u;
    v_old = speed_v;
//    r_old = speed_r;
    return needF;
}


float HeadingControl()
{
    static float k_turn = 24, set_heading_old = 0.0;//旋转角速度
    float kk = 0.0;


    float Kp = 1.0,d_p = 0.0;

    //求当前与设定艏向的角度偏差
    heading_diff = heading - set_heading;
    while (heading_diff > 180.0) heading_diff -= 360.0;
    while (heading_diff <= -180.0) heading_diff += 360.0;

    kk = set_heading_old - set_heading;
    while (kk > 180.0) kk -= 360.0;
    while (kk <= -180.0) kk += 360.0;

    if(fabs(kk) > 0.3 || isHeading_first == true || isAutoplt_first == true || isKeeppos_first == true)
    {
        heading_give = heading;//将heading_give赋初值
        set_heading_old = set_heading;
        isHeading_first = false;
    }

    if(heading_diff < 0)
        turn_direc =1;//顺时针
    else
        turn_direc = -1;//逆时针

    if((set_rot - 0.4)>0.01)
    {
        if(fabs(heading_diff) <15) k_turn = 0.2;
        else
            k_turn = 0.4;
    }
    else if((set_rot - 0.1) > 0.01)
    {
        if(fabs(heading_diff) > 20) k_turn = 0.4;
        else
            k_turn = 0.2;
    }
    else
        k_turn = 0.4;






    heading_give = heading_give + turn_direc *k_turn*LOOP_TIME*LOOP_TIME;

    speed_r = k_turn;
    heading = heading_give;

    if(fabs(heading_diff) < 0.1)
    {
        speed_r = 0.0;
        heading = set_heading;
    }



    if(speed_r >= 0.4)
    {
        fbk_rudder1_ang = fbk_f4 = turn_direc * 25;
        fbk_rudder2_ang = fbk_f5 = turn_direc * 25;
    }
    else

    {
        fbk_rudder1_ang = fbk_f4 = turn_direc * speed_r * 25.0 / 0.4;
        fbk_rudder2_ang = fbk_f5 = turn_direc * speed_r * 25.0 / 0.4;
    }

    cmd_f4 = cmd_f5 = 1.1*fbk_f4;

    d_p = heading_give - heading;
    while (d_p > 180.0) d_p -= 360.0;
    while (d_p <= -180.0) d_p += 360.0;
    if(fabs(d_p)<0.01) d_p = 0;

    Nz = Kp * d_p;// - Fwind_z;
    if(fabs(Nz) > MAX_NZ) Nz = MAX_NZ * Nz/fabs(Nz);

    return Nz;

}




void HandleWind()
{
    float temp_f1 = 0.0;
    float temp_f2 = 0.0;
    float temp_f3 = 0.0;
    int x11 =0,x12 = 0;
    int x21 =0,x22 = 0;
    int x31 =0,x32 = 0;
    int y0 = 0;
    float lambda = 50.0;//缩尺比=50
    int m=0;
    float multi = pow(lambda,3)*1.025;

    Rwind_dir = Twind_dir - heading;

    if((Rwind_dir >= 360) || (Rwind_dir < 0))
    {
        m = (int)(Rwind_dir/360.0);
        Rwind_dir = Rwind_dir - m*360.0;
        if(Rwind_dir < 0)
            Rwind_dir = Rwind_dir+360;
    }

    if((Rwind_dir >= 0) && (Rwind_dir <5))
    {
        y0 = 0;

        x11=0;
        x12=-4;

        x21 = -14;
        x22 = -32;

        x31 = -14;
        x32 = 4;
    }
    else if((Rwind_dir >= 5) && (Rwind_dir <10))
    {
        y0 = 5;

        x11=-4;
        x12=-12;

        x21 = -32;
        x22 = -70;

        x31 = 4;
        x32 = 16;
    }
    else if((Rwind_dir >= 10) && (Rwind_dir < 15))
    {
        y0 = 10;

        x11=-12;
        x12=-20;

        x21 = -70;
        x22 = -82;

        x31 = 16;
        x32 = 28;
    }
    else if((Rwind_dir >= 15) && (Rwind_dir <20))
    {
        y0 = 15;

        x11=-20;
        x12=-28;

        x21 = -82;
        x22 = -94;

        x31 = 28;
        x32 = 40;
    }
    else if((Rwind_dir >= 20) && (Rwind_dir < 25))
    {
        y0 = 20;

        x11=-28;
        x12=-40;

        x21 = -94;
        x22 = -110;

        x31 = 40;
        x32 = 58;
    }
    else if((Rwind_dir >= 25) && (Rwind_dir < 30))
    {
        y0 = 25;

        x11=-40;
        x12=-54;

        x21 = -110;
        x22 = -124;

        x31 = 58;
        x32 = 74;
    }
    else if((Rwind_dir >= 30) && (Rwind_dir < 35))
    {
        y0 = 30;

        x11=-54;
        x12=-72;

        x21 = -124;
        x22 = -148;

        x31 = 74;
        x32 = 96;
    }
    else if((Rwind_dir >= 35) && (Rwind_dir < 40))
    {
        y0 = 35;

        x11=-72;
        x12=-96;

        x21 = -148;
        x22 = -184;

        x31 = 96;
        x32 = 132;
    }
    else if((Rwind_dir >= 40) && (Rwind_dir < 45))
    {
        y0 = 40;

        x11=-96;
        x12=-110;

        x21 = -184;
        x22 = -196;

        x31 = 132;
        x32 = 148;
    }
    else if((Rwind_dir >= 45) && (Rwind_dir <50))
    {
        y0 = 45;

        x11=-110;
        x12=-112;

        x21 = -196;
        x22 = -197;

        x31 = 148;
        x32 = 150;
    }
    else if((Rwind_dir >= 50) && (Rwind_dir <55))
    {
        y0 = 50;

        x11=-112;
        x12=-126;

        x21 = -197;
        x22 = -198;

        x31 = 150;
        x32 = 166;
    }
    else if((Rwind_dir >= 55) && (Rwind_dir < 60))
    {
        y0 = 55;

        x11=-126;
        x12=-136;

        x21 = -198;
        x22 = -204;

        x31 = 166;
        x32 = 180;
    }
    else if((Rwind_dir >= 60) && (Rwind_dir < 65))
    {
        y0 = 60;

        x11=-136;
        x12=-128;

        x21 = -204;
        x22 = -174;

        x31 = 180;
        x32 = 162;
    }
    else if((Rwind_dir >= 65) && (Rwind_dir < 70))
    {
        y0 = 65;

        x11=-128;
        x12=-136;

        x21 = -174;
        x22 = -170;

        x31 = 162;
        x32 = 170;
    }
    else if((Rwind_dir >= 70) && (Rwind_dir < 75))
    {
        y0 = 70;

        x11 = -136;
        x12 = -142;

        x21 = -170;
        x22 = -164;

        x31 = 170;
        x32 = 174;
    }
    else if((Rwind_dir >= 75) && (Rwind_dir < 80))
    {
        y0 = 75;

        x11 = -142;
        x12 = -146;

        x21 = -164;
        x22 = -154;

        x31 = 174;
        x32 = 176;
    }
    else if((Rwind_dir >= 80) && (Rwind_dir < 85))
    {
        y0 = 80;

        x11 = -146;
        x12 = -148;

        x21 = -154;
        x22 = -142;

        x31 = 176;
        x32 = 176;
    }
    else if((Rwind_dir >= 85) && (Rwind_dir < 90))
    {
        y0 = 85;

        x11 = -148;
        x12 = -148;

        x21 = -142;
        x22 = -132;

        x31 = 176;
        x32 = 172;
    }
    else if((Rwind_dir >= 90) && (Rwind_dir < 95))
    {
        y0 = 90;

        x11=-148;
        x12=-164;

        x21 = -132;
        x22 = 358;

        x31 = 172;
        x32 = -282;
    }
    else if((Rwind_dir >= 95) && (Rwind_dir < 100))
    {
        y0 = 95;

        x11=-164;
        x12=-134;

        x21 = 358;
        x22 = 288;

        x31 = -282;
        x32 = -220;
    }
    else if((Rwind_dir >= 100) && (Rwind_dir < 105))
    {
        y0 = 100;

        x11=-134;
        x12=-134;

        x21 = 288;
        x22 = 276;

        x31 = -220;
        x32 = -202;
    }
    else if((Rwind_dir >= 105) && (Rwind_dir < 110))
    {
        y0 = 105;

        x11=-134;
        x12=-136;

        x21 = 276;
        x22 = 232;

        x31 = -202;
        x32 = -146;
    }
    else if((Rwind_dir >= 110) && (Rwind_dir < 115))
    {
        y0 = 110;

        x11=-136;
        x12=-134;

        x21 = 232;
        x22 = 216;

        x31 = -146;
        x32 = -124;
    }
    else if((Rwind_dir >= 115) && (Rwind_dir < 120))
    {
        y0 = 115;

        x11 = -134;
        x21 = 216;
        x31 = -124;

        x12 = -128;
        x22 = 196;
        x32 = -104;
    }
    else if((Rwind_dir >= 120) && (Rwind_dir < 125))
    {
        y0 = 120;

        x11 = -128;
        x21 = 196;
        x31 = -104;

        x12 = -122;
        x22 = 176;
        x32 = -84;
    }
    else if((Rwind_dir >= 125) && (Rwind_dir < 130))
    {
        y0 = 125;

        x11 = -122;
        x21 = 176;
        x31 = -84;

        x12 = -114;
        x22 = 156;
        x32 = -64;
    }
    else if((Rwind_dir >= 130) && (Rwind_dir < 135))
    {
        y0 = 130;
        x11 = -114;
        x21 = 156;
        x31 = -64;

        x12 = -114;
        x22 = 174;
        x32 = -76;
    }
    else if((Rwind_dir >= 135) && (Rwind_dir < 140))
    {
        y0 = 135;
        x11 = -114;
        x21 = 174;
        x31 = -76;

        x12 = -96;
        x22 = 226;
        x32 = -138;
    }
    else if((Rwind_dir >= 140) && (Rwind_dir < 145))
    {
        y0 = 140;
        x11 = -96;
        x21 = 226;
        x31 = -138;

        x12 = -74;
        x22 = 168;
        x32 = -90;
    }
    else if((Rwind_dir >= 145) && (Rwind_dir < 150))
    {
        y0 = 145;
        x11 = -74;
        x21 = 168;
        x31 = -90;

        x12 = -64;
        x22 = 100;
        x32 = -28;
    }
    else if((Rwind_dir >= 150) && (Rwind_dir < 155))
    {
        y0 = 150;

        x11 = -64;
        x21 = 100;
        x31 = -28;

        x12 = -50;
        x22 = 88;
        x32 = -22;
    }
    else if((Rwind_dir >= 155) && (Rwind_dir < 160))
    {
        y0 = 155;
        x11 = -50;
        x21 = 88;
        x31 = -22;

        x12 = -36;
        x22 = 78;
        x32 = -16;
    }
    else if((Rwind_dir >= 160) && (Rwind_dir < 165))
    {
        y0 = 160;

        x11 = -36;
        x21 = 78;
        x31 = -16;

        x12 = -26;
        x22 = 66;
        x32 = -8;
    }
    else if((Rwind_dir >= 165) && (Rwind_dir < 170))
    {
        y0 = 165;

        x11 = -26;
        x21 = 66;
        x31 = -8;

        x12 = -8;
        x22 = 36;
        x32 = 2;
    }
    else if((Rwind_dir >= 170) && (Rwind_dir < 175))
    {
        y0 = 170;

        x11 = -8;
        x21 = 36;
        x31 = 2;

        x12 = -6;
        x22 = 4;
        x32 = 30;
    }
    else if((Rwind_dir >= 175) && (Rwind_dir < 180))
    {
        y0 = 175;

        x11 = -6;
        x21 = 4;
        x31 = 30;

        x12 = -2;
        x22 = 4;
        x32 = 28;
    }
    else if((Rwind_dir >= 180) && (Rwind_dir < 185))
    {
        y0 = 180;

        x11 = -2;
        x21 = 4;
        x31 = 28;

        x12 = 6;
        x22 = 30;
        x32 = 45;
    }
    else if((Rwind_dir >= 185) && (Rwind_dir < 190))
    {
        y0 = 185;
        x11 = 6;
        x21 = 30;
        x31 = 45;

        x12 = 8;
        x22 = 2;
        x32 = 50;
    }
    else if((Rwind_dir >= 190) && (Rwind_dir < 195))
    {
        y0 = 190;
        x11 = 8;
        x21 = 2;
        x31 = 36;

        x12 = 26;
        x22 = -8;
        x32 = 66;
    }
    else if((Rwind_dir >= 195) && (Rwind_dir < 200))
    {
        y0 = 195;

        x11 = 26;
        x21 = -8;
        x31 = 66;

        x12 = 36;
        x22 = -16;
        x32 = 78;
    }
    else if((Rwind_dir >= 200) && (Rwind_dir < 205))
    {
        y0 = 200;

        x11 = 36;
        x21 = -16;
        x31 = 78;

        x12 = 50;
        x22 = -22;
        x32 = 88;
    }
    else if((Rwind_dir >= 205) && (Rwind_dir < 210))
    {
        y0 = 205;
        x11 = 50;
        x21 = -22;
        x31 = 88;

        x12 = 64;
        x22 = -28;
        x32 = 100;
    }
    else if((Rwind_dir >= 210) && (Rwind_dir < 215))
    {
        y0 = 210;
        x11 = 64;
        x21 = -28;
        x31 = 100;

        x12 = 74;
        x22 = -90;
        x32 = 168;
    }
    else if((Rwind_dir >= 215) && (Rwind_dir < 220))
    {
        y0 = 215;
        x11 = 74;
        x21 = -90;
        x31 = 168;

        x12 = 96;
        x22 = -138;
        x32 = 226;
    }
    else if((Rwind_dir >= 220) && (Rwind_dir < 225))
    {
        y0 = 220;

        x11 = 96;
        x21 = -138;
        x31 = 226;

        x12 = 114;
        x22 = -76;
        x32 = 174;
    }
    else if((Rwind_dir >= 225) && (Rwind_dir < 230))
    {
        y0 = 225;

        x11 = 114;
        x21 = -76;
        x31 = 174;

        x12 = 114;
        x22 = -64;
        x32 = 156;
    }
    else if((Rwind_dir >= 230) && (Rwind_dir < 235))
    {
        y0 = 130;

        x11= 114;
        x12= 122;

        x21 = -64;
        x22 = -84;

        x31 = 156;
        x32 = 176;
    }
    else if((Rwind_dir >= 235) && (Rwind_dir < 240))
    {
        y0 = 235;

        x11= 122;
        x12= 128;

        x21 = -84;
        x22 = -104;

        x31 = 176;
        x32 = 196;
    }
    else if((Rwind_dir >= 240) && (Rwind_dir < 245))
    {
        y0 = 240;

        x11= 128;
        x12= 134;

        x21 = -104;
        x22 = -124;

        x31 = 196;
        x32 = 216;
    }
    else if((Rwind_dir >= 245) && (Rwind_dir < 250))
    {
        y0 = 245;

        x11= 134;
        x12= 136;

        x21 = -124;
        x22 = -146;

        x31 = 216;
        x32 = 232;
    }
    else if((Rwind_dir >= 250) && (Rwind_dir < 255))
    {
        y0 = 250;

        x11= 136;
        x12= 134;

        x21 = -146;
        x22 = -202;

        x31 = 232;
        x32 = 276;
    }
    else if((Rwind_dir >= 255) && (Rwind_dir < 260))
    {
        y0 = 255;

        x11= 134;
        x12= 134;

        x21 = -202;
        x22 = -220;

        x31 = 276;
        x32 = 288;
    }
    else if((Rwind_dir >= 260) && (Rwind_dir < 265))
    {
        y0 = 260;

        x11= 134;
        x12= 164;

        x21 = -220;
        x22 = -282;

        x31 = 288;
        x32 = 358;
    }
    else if((Rwind_dir >= 265) && (Rwind_dir < 270))
    {
        y0 = 265;

        x11 = 164;
        x12 = 148;

        x21 = -282;
        x22 = 172;

        x31 = 358;
        x32 = -132;
    }
    else if((Rwind_dir >= 270) && (Rwind_dir < 275))
    {
        y0 = 270;

        x11 = 148;
        x12 = 148;

        x21 = 172;
        x22 = 176;

        x31 = -132;
        x32 = -142;
    }
    else if((Rwind_dir >= 275) && (Rwind_dir < 280))
    {
        y0 = 275;

        x11 = 148;
        x12 = 146;

        x21 = 176;
        x22 = 176;

        x31 = -142;
        x32 = -154;
    }
    else if((Rwind_dir >= 280) && (Rwind_dir < 285))
    {
        y0 = 280;

        x11 = 146;
        x12 = 142;

        x21 = 176;
        x22 = 174;

        x31 = -154;
        x32 = -164;
    }
    else if((Rwind_dir >= 285) && (Rwind_dir < 290))
    {
        y0 = 285;

        x11 = 142;
        x12 = 136;

        x21 = 174;
        x22 = 170;

        x31 = -164;
        x32 = -170;
    }
    else if((Rwind_dir >= 290) && (Rwind_dir < 295))
    {
        y0 = 290;

        x11= 136;
        x12= 128;

        x21 = 170;
        x22 = 162;

        x31 = -170;
        x32 = -174;
    }
    else if((Rwind_dir >= 295) && (Rwind_dir < 300))
    {
        y0 = 295;

        x11= 128;
        x12= 136;

        x21 = 162;
        x22 = 180;

        x31 = -174;
        x32 = -204;
    }
    else if((Rwind_dir >= 300) && (Rwind_dir < 305))
    {
        y0 = 300;

        x11= 136;
        x12= 126;

        x21 = 180;
        x22 = 166;

        x31 = -204;
        x32 = -198;
    }
    else if((Rwind_dir >= 305) && (Rwind_dir < 310))
    {
        y0 = 305;

        x11= 126;
        x12= 112;

        x21 = 166;
        x22 = 150;

        x31 = -198;
        x32 = -188;
    }
    else if((Rwind_dir >= 310) && (Rwind_dir < 315))
    {
        y0 = 310;

        x11= 112;
        x12= 110;

        x21 = 150;
        x22 = 148;

        x31 = -188;
        x32 = -196;
    }
    else if((Rwind_dir >= 315) && (Rwind_dir < 320))
    {
        y0 = 315;

        x11= 110;
        x12= 96;

        x21 = 148;
        x22 = 132;

        x31 = -196;
        x32 = -184;
    }
    else if((Rwind_dir >= 320) && (Rwind_dir < 325))
    {
        y0 = 320;

        x11= 96;
        x12= 72;

        x21 = 132;
        x22 = 96;

        x31 = -184;
        x32 = -148;
    }
    else if((Rwind_dir >= 325) && (Rwind_dir < 330))
    {
        y0 = 325;

        x11= 72;
        x12= 54;

        x21 = 96;
        x22 = 74;

        x31 = -148;
        x32 = -124;
    }
    else if((Rwind_dir >= 330) && (Rwind_dir < 335))
    {
        y0 = 130;

        x11= 54;
        x12= 40;

        x21 = 74;
        x22 = 58;

        x31 = -124;
        x32 = -110;
    }
    else if((Rwind_dir >= 335) && (Rwind_dir < 340))
    {
        y0 = 335;

        x11= 40;
        x12= 28;

        x21 = 58;
        x22 = 40;

        x31 = -110;
        x32 = -94;
    }
    else if((Rwind_dir >= 340) && (Rwind_dir < 345))
    {
        y0 = 340;

        x11= 28;
        x12= 20;

        x21 = 40;
        x22 = 28;

        x31 = -94;
        x32 = -82;
    }
    else if((Rwind_dir >= 345) && (Rwind_dir < 350))
    {
        y0 = 345;

        x11= 20;
        x12= 12;

        x21 = 28;
        x22 = 16;

        x31 = -82;
        x32 = -70;
    }
    else if((Rwind_dir >= 350) && (Rwind_dir < 355))
    {
        y0 = 350;

        x11= 12;
        x12= 4;

        x21 = 16;
        x22 = 4;

        x31 = -70;
        x32 = -32;
    }
    else if((Rwind_dir >= 355) && (Rwind_dir < 360))
    {
        y0 = 355;

        x11 = 4;
        x12 = 0;

        x21 = 4;
        x22 = -14;

        x31 = -32;
        x32 = -14;
    }

    temp_f1 = ((float)((x21 - x11)*(Rwind_dir - y0))/5.0 + x11)*10.0/multi * Twind_spd * Twind_spd;//Twind_spdm/s风对应的力//1000.0/multi;//10m/s的风对应的力//单位N
    temp_f2 = ((float)((x22 - x21)*(Rwind_dir - y0))/5.0 + x21)*10.0/multi * Twind_spd * Twind_spd;//Twind_spdm/s风对应的力//1000.0/multi;//单位N
    temp_f3 = ((float)((x32 - x31)*(Rwind_dir - y0))/5.0 + x31)*10.0/multi * Twind_spd * Twind_spd;//Twind_spdm/s风对应的力//1000.0/multi;//单位N

    /*
    //为了抵抗10m/s，真风向为10的风时，各推进器的推力及各自由度的分力/力矩。
    *f1 = temp_f1;
    *f2 = temp_f2;
    *f3 = temp_f3;
    *fw_x = temp_f2 + temp_f3;
    *fw_y = temp_f1;
    *fw_z = temp_f1 * ship_l1 + (temp_f2 - temp_f3)*ship_l2;
    */
    //10m/s，真风向为10的风对船舶的产生的影响分布到各推进器和各自由度的分力/力矩。
    Fwind_1 = -temp_f1;
    Fwind_2 = -temp_f2;
    Fwind_3 = -temp_f3;
    Fwind_x = -temp_f2 - temp_f3;
    Fwind_y = -temp_f1;
    Fwind_z = -temp_f1 * ship_l1 + (-temp_f2 + temp_f3)*ship_l2;



    //qDebug()<<"Fwind_x="<<Fwind_x<<",Fwind_y="<<Fwind_y<<",Fwind_z="<<Fwind_z;
    //qDebug()<<"Fwind_1="<<Fwind_1<<",Fwind_2="<<Fwind_2<<",Fwind_3="<<Fwind_3;

}





/**/
