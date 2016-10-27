#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "characterconversion.h"

QFont FONT_1 = QFont("微软雅黑",8);
QFont FONT_2 = QFont("微软雅黑",10,QFont::Bold);
QFont FONT_3 = QFont("微软雅黑",12);
QFont FONT_4 = QFont("微软雅黑",24,QFont::Bold);
QFont FONT_5 = QFont("微软雅黑",10);
QFont FONT_15;//视图区标题文字字体
QFont FONT_16;//按键键名字体
QFont FONT_17;//报警页字体

QString view1_xuanzhuanzhongxin =   "旋转中心：";
QString str_chuanshou =             "船艏";
QString str_chuanzhong =            "船舯";
QString str_chuanwei =              "船艉";
QString view1_juchuanshou =         "距船艏";
QString view1_juyouxian =           "距右舷";
QString view1_chuansu =             "船速";
QString view1_shedingshouxiang =    "设定艏向";
QString sensor_dianluojing =        "电罗经";
QString sensor_fengsufengxiangyi =  "风速风向仪";
QString sensor_yundongcankaodanyuan = "运动参考单元";
QString sensor_gps1 =               "GPS1";
QString sensor_gps2 =               "GPS2";
QString sensor_vrs =                "VRS";
QString sensor_suduchuanganqi =     "速度传感器";
QString joystickRequest =           "Joystick模式";

//按键的键名字符串
QString btnstr_shitu;
QString btnstr_xitong;
QString btnstr_riye;
QString btnstr_baojing;
QString btnstr_zongtishezhi;
QString btnstr_xianzhishezhi;
QString btnstr_xitongshezhi;
QString btnstr_zidongduoshezhi;
QString btnstr_qiyongshezhi;
QString btnstr_quantuili;
QString btnstr_shouxiangshezhi;
QString btnstr_daiji;
QString btnstr_simulation;
QString btnstr_dangqianshangxiang;
QString btnstr_shoucao;
QString btnstr_weizhibaochi;
QString btnstr_zidongduo;
QString btnstr_zidongshouxiang;
QString btnstr_zidongzongxiang;
QString btnstr_zidonghengxiang;
QString btnstr_chuanzhong;
QString btnstr_chuanshou;
QString btnstr_chuanwei;
QString btnstr_zhuanru;
QString btnstr_zhuanchu;
QString btnstr_qiangqie;
QString btnstr_ceshi;
QString btnstr_tiaoguang;
QString btnstr_zhongyingwen;
QString btnstr_yingda;
QString btnstr_fanhui;
QString btnstr_lingpai;

QString str_huizhuanlv;
QString str_shouxiang;
QString str_bei;
QString str_dong;
QString str_fengsu;
QString str_fengxiang;
QString str_zongyao;
QString str_hengyao;
QString str_jiuxu;
QString str_yunxing;
QString str_qiyong;
QString str_zuoxian;
QString str_youxian;
QString str_duojiao;
QString str_sudu;

QString str_yes;
QString str_no;
QString str_shouxiangxianzhi;
QString str_weizhixianzhi;
QString str_jinggao;
QString str_baojing;
QString str_xianzhi;


QString str_shoucetui;
QString str_weizuozhutui;
QString str_weiyouzhutui;
QString str_zuoduoji;
QString str_youduoji;
QString str_luoju;
QString str_zhuansu;
QString str_queding;
QString str_quxiao;

QString str_zhanminchen;
QString str_zhanzhuangtai;
QString str_zhancuowu;
QString str_benji;

QString danwei_jie = "节";
QString danwei_du = "°";
QString danwei_mi = "米";
QString danwei_mimiao = "米/秒";
QString danwei_dufen = "°/分";
QString danwei_dumiao = "°/秒";

QString str_kongzhigui;
QString str_caozuoduan;
QString str_gps1weijiuxu;
QString str_gps2weijiuxu;
QString str_gyroweijiuxu;
QString str_windweijiuxu;
QString str_shoucetuiready;
QString str_weizuozhutuiready;
QString str_weiyouzhutuiready;
QString str_zuoduojiready;
QString str_youduojiready;
QString str_windshujucuowu;
QString str_shouxiangwarning;
QString str_shouxiangalarm;
QString str_weizhiwarning;
QString str_weizhialarm;
QString str_xwarning;
QString str_xalarm;
QString str_ywarning;
QString str_yalarm;

QString almstr_jinggao;
QString almstr_baojing;
QString almstr_tishi;
QString almstr_jinji;

QString almtitle_yingda;
QString almtitle_laiyuan;
QString almtitle_shijian;
QString almtitle_jibie;
QString almtitle_leixing;
QString almtitle_miaoshu;
QString almtitle_xinxi;

//系统信息视图页
QString str_ip;
QString str_config;
QString str_otsw;
QString str_ctlsw;
QString str_sdk;
QString str_ide;
QString str_windows;

//状态视图页
QString str_zuoduo;
QString str_youduo;
QString str_weizuo;
QString str_weiyou;

QString str_GPS1_ZTST;              //GPS1
QString str_GPS2_ZTST;              //GPS2
QString str_fengsu_ZTST;            //风速
QString str_dianluojing_ZTST;       //电罗经
QString str_chuankou_ZTST;          //串口
QString str_IO_ZTST;                //IO
QString str_yitaiwang_ZTST;         //以太网
QString str_duanlu_ZTST;            //断路

//总体设置图
QString str_tuilifenpeimoshi_ZTSZ;  //推力分配模式
QString str_shezhihuizhuanlv_ZTSZ;  //设置回转率
QString str_fenglibuchang_ZTSZ;     //风力补偿
QString str_zengyidengji_ZTSZ;      //增益等级
QString str_chuanbochishuileixing_ZTSZ;  //船舶吃水类型
QString str_zuidaduojiao_ZTSZ; //最大舵角

//传感器启用设置
QString str_dianluojing_CQSZ;       //电罗经
QString str_GPS1_CQSZ;              //GPS1
QString str_GPS2_CQSZ;              //GPS2
QString str_fengsufengxiangyi_CQSZ; //风速风向仪
QString str_VDR_CQSZ;               //VRS
QString str_qidong;                 //起动

//系统设置
QString str_year_XTSZ;//年
QString str_month_XTSZ;//月
QString str_day_XTSZ;//日
QString str_hour_XTSZ;//时
QString str_minute_XTSZ;//分
QString str_second_XTSZ;//秒
QString str_guanbixitong_XTSZ;//关闭系统
QString str_guanbizhongduan_XTSZ;//秒
QString str_chongqizhongduan_XTSZ;//关闭系统

//对话框
QString str_JoyStick;//手操模式
QString str_PositionKeep;//位置保持模式
QString str_AutoPilot;//自动舵模式
QString str_AutoHead;//自动艏向模式
QString str_AutoSurge;//自动纵向模式
QString str_AutoSway;//自动横向模式
QString str_Standby;
QString str_AutoHSu;
QString str_AutoHSw;
QString str_AutoSuSw;

QString str_nomatch_joystick;
QString str_nomatch_standby;
QString str_nomatch_poskeep;
QString str_nomatch_autopilot;
QString str_nomatch_autohead;
QString str_nomatch_autosurge;
QString str_nomatch_autosway;
QString str_nomatch_headsurge;
QString str_nomatch_headsway;
QString str_nomatch_surgesway;

QString str_take_out;
QString str_give_in;
QString str_gonglvxiaohao;
QString str_keyonggonglv;

QString str_shedingweizhi;
QString str_dangqianweizhi;
QString str_cankaoyuandian;
QString str_gpsmingcheng;
QString str_zhuangtai;
QString str_jiaquan;
QString str_zaixian;
QString str_lixian;

QString str_moshi1;
QString str_moshi2;
QString str_moshi3;

QString str_liangdushezhi;
QString str_kecaozuo;
QString str_cuowu;
QString str_kaijishijian;
QString str_beizhu;
QString str_shebeimingcheng;

QString str_on;
QString str_off;
QString str_gao;
QString str_zhong;
QString str_di;

QString str_baitian;
QString str_wanshang;
//报警信息
QString str_CCalm0;
QString str_CCalm1;
QString str_CCalm2;
QString str_CCalm3;
QString str_CCalm4;
QString str_CCalm5;
QString str_CCalm6;
QString str_CCalm7;
QString str_CCalm8;
QString str_CCalm9;
QString str_CCalm10;
QString str_CCalm11;
QString str_CCalm12;
QString str_CCalm13;
QString str_CCalm14;
QString str_CCalm15;
//提示信息
QString str_CCinfo0;
QString str_CCinfo1;
QString str_CCinfo2;
QString str_CCinfo3;
QString str_CCinfo4;
QString str_CCinfo5;
QString str_CCinfo6;
QString str_CCinfo7;
QString str_CCinfo8;
QString str_CCinfo9;
QString str_CCinfo10;
QString str_CCinfo11;
QString str_CCinfo12;
QString str_CCinfo13;
QString str_CCinfo14;
QString str_CCinfo15;
QString str_CCinfo16;
QString str_CCinfo17;

QString str_OTalm0;
QString str_OTalm1;
QString str_OTalm2;
QString str_OTalm3;
QString str_OTalm4;


CharacterConversion::CharacterConversion(QObject *parent) :
    QObject(parent)
{


}

void CharacterConversion::Refresh_character(QString language)
{

    if(language == "English")
    {
        FONT_1 = QFont("Arial",8);
        FONT_2 = QFont("Arial",10,QFont::Bold);
        FONT_3 = QFont("Arial",12,QFont::Bold);
        FONT_4 = QFont("Arial",26,QFont::Bold);
        FONT_5 = QFont("Arial",10,QFont::Bold);
        FONT_15 = QFont("Arial",16,QFont::Bold);
        FONT_16 = QFont("Arial",10,QFont::Bold | QFont::Decorative | Qt::AlignCenter);//按键键名字体


        view1_xuanzhuanzhongxin = "CntofRot:";
        str_chuanshou = "Fore";
        str_chuanzhong = "Center";
        str_chuanwei = "Stern";
        view1_juchuanshou = "ToBow:";
        view1_juyouxian = "ToStbd:";
        view1_chuansu = "Speed";
        view1_shedingshouxiang = "OrdHead.";

        sensor_dianluojing = "Gyro ";
        sensor_fengsufengxiangyi = "Wind ";
        sensor_yundongcankaodanyuan = "MRU ";
        sensor_gps1 = "GPS1 ";
        sensor_gps2 = "GPS2 ";
        sensor_vrs = "VRS ";
        sensor_suduchuanganqi = "SpeedGPS ";
        joystickRequest =           "Joystick Mode";

        str_shouxiang = "Hd.";
        str_bei = "N";
        str_dong = "E";
        str_fengsu = "wSpd.";
        str_fengxiang = "wDirc.";
        str_zongyao = "Roll";
        str_hengyao = "Pitch";
        str_jiuxu = "Ready";
        str_yunxing = "Run.";
        str_qiyong = "Enable";
        str_zuoxian = "Port";
        str_youxian = "Stbd.";
        str_duojiao = "Ang.";
        str_sudu = "Spd.";

        //按键键名的字符串
        btnstr_shitu = "View";
        btnstr_xitong = "System";
        btnstr_riye = "Day/\nNight";
        btnstr_baojing = "Alarms";
        btnstr_zongtishezhi = "General\nsetup";
        btnstr_xianzhishezhi = "Limits\nsetup";
        btnstr_xitongshezhi = "System\nsetup";
        btnstr_zidongduoshezhi = "Autoplt.\nsetup";
        btnstr_qiyongshezhi = "Enable\nsetup";
        btnstr_quantuili = "Full\nthrust";
        btnstr_shouxiangshezhi = "Head.\nsetup";
        btnstr_daiji = "Stand\nby";
        btnstr_simulation = "Simulate\nmode";
        btnstr_dangqianshangxiang = "Present\nhead.";
        btnstr_shoucao = "Joystick";
        btnstr_weizhibaochi = "Position\nkeeping";
        btnstr_zidongduo = "Autoplt.";
        btnstr_zidongshouxiang = "Auto\nhead.";
        btnstr_zidongzongxiang = "Auto\nsurge";
        btnstr_zidonghengxiang = "Auto\nsway";
        btnstr_chuanzhong = "Centre\npivot";
        btnstr_chuanshou = "Bow\npivot";
        btnstr_chuanwei = "Stern\npivot";
        btnstr_zhuanru = "Take";
        btnstr_zhuanchu = "Give";
        btnstr_qiangqie = "Force Take";
        btnstr_ceshi = "Test";
        btnstr_tiaoguang = "Light";
        btnstr_zhongyingwen = "中文";
        btnstr_yingda = "Ack/Silence";
        btnstr_fanhui = "Back";
        btnstr_lingpai = "Token";

        str_huizhuanlv = "ROT";
        str_shoucetui = "BowTunnel";
        str_weizuozhutui = "StnPortThru.";
        str_weiyouzhutui = "StnStbdThru.";
        str_zuoduoji = "StnPortRud.";
        str_youduoji = "StnStbdRud.";
        str_luoju = "pitch";
        str_zhuansu = "speed";

        str_yes = "Yes";
        str_no = "No";
        str_shouxiangxianzhi = "Heading";
        str_weizhixianzhi = "Position";
        str_jinggao = "Warn.";
        str_baojing = "Alarm";
        str_xianzhi = "Limits";

        str_queding = "Enter";
        str_quxiao = "Cancel";

        str_zhanminchen = "name";
        str_zhanzhuangtai = "state";
        str_zhancuowu = "last error";
        str_benji = "self";

        danwei_jie = "knt";
        danwei_du = "°";
        danwei_mi = "m";
        danwei_mimiao = "m/s";
        danwei_dufen = "°/min";
        danwei_dumiao = "°/s";

        str_kongzhigui = "Controllor";
        str_caozuoduan = "Operator";
        str_gps1weijiuxu = "GPS1 not ready";
        str_gps2weijiuxu = "GPS2 not ready";
        str_gyroweijiuxu = "Gyro not ready";
        str_windweijiuxu = "Wind not ready";
        str_windshujucuowu = "Wind wrong data";
        str_windweijiuxu = "Wind not ready";
        str_shoucetuiready = "Bowtunnel ready";
        str_weizuozhutuiready = "SternPortThru. ready";
        str_weiyouzhutuiready = "SternStbdThru. ready";
        str_zuoduojiready = "PortRud. ready";
        str_youduojiready = "StbdRud. ready";
        str_shouxiangwarning = "Head. over warn limit";
        str_shouxiangalarm = "Head. over alarm limit";
        str_weizhiwarning = "Pos. over warn limit";
        str_weizhialarm = "Pos. over alarm limit";
        str_xwarning = "X is over warn limit";
        str_xalarm = "X is over alarm limit";
        str_ywarning = "Y is over warn limit";
        str_yalarm = "Y is over alarm limit";


        almstr_jinggao = "W";
        almstr_baojing = "A";
        almstr_tishi = "I";
        almstr_jinji = "E";

        almtitle_yingda = "Answ.";
        almtitle_laiyuan = "OriEqp.";
        almtitle_shijian = "Time";
        almtitle_jibie = "Pri.";
        almtitle_leixing = "State";
        almtitle_miaoshu = "Text";
        almtitle_xinxi = "Info.";

        str_ip = "IP Address:";
        str_config = "Config. Version:";
        str_otsw = "OT SW Version:";
        str_ctlsw = "Ctrl SW Version:";
        str_sdk = "SDK Version:";
        str_ide = "IDE Version:";
        str_windows = "Windows Version:";

        str_zuoduo = "StPtRd.";
        str_youduo = "StSbdRd.";
        str_weizuo = "StPtThru.";
        str_weiyou = "StSbdThru.";
        str_GPS1_ZTST = "GPS1";
        str_GPS2_ZTST = "GPS2";
        str_fengsu_ZTST = "wind";
        str_dianluojing_ZTST = "Gyro";
        str_chuankou_ZTST = "Serial";//串口
        str_IO_ZTST = "IO";
        str_yitaiwang_ZTST = "Net";//以太网
        str_duanlu_ZTST = "Off";//断路

        str_tuilifenpeimoshi_ZTSZ = "Alloc.Mode";//推力分配模式
        str_shezhihuizhuanlv_ZTSZ = "ROT"; //设置回转率
        str_fenglibuchang_ZTSZ = "Wind Comp."; //风力补偿
        str_zengyidengji_ZTSZ = "Gain Level";//增益等级
        str_zuidaduojiao_ZTSZ = "Max Rudder Angle";//最大舵角
        str_chuanbochishuileixing_ZTSZ = "Draught Type ";//船舶吃水类型

        str_dianluojing_CQSZ = "Gyro";//电罗经
        str_GPS1_CQSZ = "GPS1";//GPS1
        str_GPS2_CQSZ = "GPS2";//GPS2
        str_fengsufengxiangyi_CQSZ = "Wind";//
        str_VDR_CQSZ = "VRS";//
        str_qidong = "Start";//起动

        str_year_XTSZ = "Year";//年
        str_month_XTSZ = "Month";//月
        str_day_XTSZ = "Day";//日
        str_hour_XTSZ = "Hour";//时
        str_minute_XTSZ = "Minute";//分
        str_second_XTSZ = "Second";//秒
        str_guanbixitong_XTSZ = "TurnOff";//关闭系统
        str_guanbizhongduan_XTSZ = "TurnOffTerminal";//关闭终端
        str_chongqizhongduan_XTSZ = "RestartTeiminal";//关闭系统

        str_JoyStick = "Enter the JoyStickmode?";//手操模式
        str_PositionKeep = "Enter the \nPositionKeeping mode?";//位置保持模式
        str_AutoPilot = "Enter the AutoPilot mode?";//自动舵模式
        str_AutoHead = "Enter the AutoHead mode?";//自动艏向模式
        str_AutoSurge = "Enter the AutoSurge mode?";//自动纵向模式
        str_AutoSway = "Enter the AutoSway mode?";//自动横向模式
        str_Standby = "Enter the Standby mode?";
        str_AutoHSu = "Enter the \nAutoHead&Surge mode?";
        str_AutoHSw = "Enter the \nAutoHead&Sway mode?";
        str_AutoSuSw = "Enter the \nAutoSurge&Sway mode?";

        str_nomatch_joystick = "Don't match run conditions\nof Joystick!";
        str_nomatch_standby = "Don't match run conditions\nof Standby!";
        str_nomatch_poskeep = "Don't match run conditions\nof Positionkeeping!";
        str_nomatch_autopilot = "Don't match run conditions\nof AutoPilot!";
        str_nomatch_autohead = "Don't match run conditions\nof AutoHeading!";
        str_nomatch_autosurge = "Don't match run conditions\nof AutoSurge!";
        str_nomatch_autosway = "Don't match run conditions\nof AutoSway!";
        str_nomatch_headsurge = "Don't match run conditions\nof AutoHead&Surge!";
        str_nomatch_headsway = "Don't match run conditions\nof AutoHead&Sway!";
        str_nomatch_surgesway = "Don't match run conditions\nof AutoSurge&Sway!";

        str_take_out = "Station '%1'\n required to take out the control token.";
        str_give_in = "Station '%1'\n required to give the control token";
        str_gonglvxiaohao = "Power Consumption";
        str_keyonggonglv = "Avalible Power:";

        str_shedingweizhi = "Set Position";
        str_dangqianweizhi = "Current Position";
        str_cankaoyuandian = "Ori. Reference Sensor:";
        str_gpsmingcheng = "Sensor' name";
        str_zhuangtai = "State";
        str_jiaquan = "Weight";
        str_zaixian = "Online";
        str_lixian = "Offline";

        str_moshi1 = "Mode 1";
        str_moshi2 = "Mode 2";
        str_moshi3 = "Mode 3";

        str_liangdushezhi = "Brightness setup:";
        str_kecaozuo = "Operational";
        str_cuowu = "Erro";
        str_kaijishijian = "Start Time";
        str_beizhu = "Info.";
        str_shebeimingcheng = "DeviceName";

        str_on = "On";
        str_off = "Off";
        str_gao = "High";
        str_zhong = "Middle";
        str_di = "Low";

        str_baitian = "Day";
        str_wanshang = "Night";


        str_CCalm0 = "Controller Hardware Error";
        str_CCalm1 = "Gyro Communication Fault";
        str_CCalm2 = "Gyro Wrong Measurement";
        str_CCalm3 = "Wind Communication Fault";
        str_CCalm4 = "Wind Wrong Measurement";
        str_CCalm5 = "Tunnel Communication Fault";
        str_CCalm6 = "L.Thr Communication Fault";
        str_CCalm7 = "R.Thr Communication Fault";
        str_CCalm8 = "L.Rud Communication Fault";
        str_CCalm9 = "R.Rud Communication Fault";
        str_CCalm10 = "Tunnel Wrong Measurement";
        str_CCalm11 = "L.Thr Wrong Measurement";
        str_CCalm12 = "R.Thr Wrong Measurement";
        str_CCalm13 = "L.Rud Wrong Measurement";
        str_CCalm14 = "R.Rud Wrong Measurement";
        str_CCalm15 = "Controller communication Fault";

        str_CCinfo0 = "Controller Not Ready";//控制器状态（0-未就绪，1-启动）
        str_CCinfo1 = "Controller Ready";//控制器状态（0-未就绪，1-启动）
        str_CCinfo2 = "Gyro Not Ready";//罗经就绪
        str_CCinfo3 = "Gyro Ready";//罗经就绪
        str_CCinfo4 = "Wind Not Ready";
        str_CCinfo5 = "Wind Ready";
        str_CCinfo6 = "Tunnel Not Ready";
        str_CCinfo7 = "Tunnel Ready";
        str_CCinfo8 = "L.Thr Not Ready";
        str_CCinfo9 = "L.Thr Ready";
        str_CCinfo10 = "R.Thr Not Ready";
        str_CCinfo11 = "R.Thr Ready";
        str_CCinfo12 = "L.Rud Not Ready";
        str_CCinfo13 = "L.Rud Ready";
        str_CCinfo14 = "R.Rud Not Ready";
        str_CCinfo15 = "R.Rud Ready";
        str_CCinfo16 = "Joystick Mode Off";
        str_CCinfo17 = "Joystick Mode On";

        str_OTalm0 = "Joystick x Error";
        str_OTalm1 = "Joystick y Error";
        str_OTalm2 = "Joystick z Error";
        str_OTalm3 = "Heading Waring";
        str_OTalm4 = "Heading Alarm";
    }
    else
    {
        FONT_1 = QFont("微软雅黑",8);
        FONT_2 = QFont("微软雅黑",10,QFont::Bold);
        FONT_3 = QFont("微软雅黑",12,QFont::Bold);
        FONT_4 = QFont("微软雅黑",24,QFont::Bold);
        FONT_5 = QFont("微软雅黑",10);
        FONT_15 = QFont("微软雅黑",14,QFont::Bold);
        FONT_16 = QFont("微软雅黑",10, QFont::Bold | QFont::Decorative | Qt::AlignCenter);//按键键名字体


        view1_xuanzhuanzhongxin = "旋转中心：";
        str_chuanshou = "船艏";
        str_chuanzhong = "船舯";
        str_chuanwei = "船艉";
        view1_juchuanshou = "距船艏:";
        view1_juyouxian = "距右舷:";
        view1_chuansu = "船速";
        view1_shedingshouxiang = "设定艏向";
        sensor_dianluojing = "电罗经";
        sensor_fengsufengxiangyi = "风速风向仪";
        sensor_yundongcankaodanyuan = "运动参考单元";
        sensor_gps1 = "GPS1";
        sensor_gps2 = "GPS2";
        sensor_vrs = "VRS";
        sensor_suduchuanganqi = "速度传感器";
        joystickRequest =           "Joystick模式";

        str_shouxiang = "艏向";
        str_bei = "北";
        str_dong = "东";
        str_fengsu = "风速";
        str_fengxiang = "风向";
        str_zongyao = "纵摇";
        str_hengyao = "横摇";
        str_jiuxu = "就绪";
        str_yunxing = "运行";
        str_qiyong = "启用";
        str_zuoxian = "左舷";
        str_youxian = "右舷";
        str_duojiao = "舵角";
        str_sudu = "速度";


        btnstr_shitu = "视图";
        btnstr_xitong = "系统";
        btnstr_riye = "白天/\n晚上";
        btnstr_baojing = "报警";
        btnstr_zongtishezhi = "总体\n设置";
        btnstr_xianzhishezhi = "限值\n设置";
        btnstr_xitongshezhi = "系统\n设置";
        btnstr_zidongduoshezhi = "自动舵\n设置";
        btnstr_qiyongshezhi = "启用\n设置";
        btnstr_quantuili = "全推力";
        btnstr_shouxiangshezhi = "艏向\n设置";
        btnstr_daiji = "待机";
        btnstr_simulation = "仿真\n模式";
        btnstr_dangqianshangxiang = "当前\n艏向";
        btnstr_shoucao = "手操";
        btnstr_weizhibaochi = "位置\n保持";
        btnstr_zidongduo = "自动舵";
        btnstr_zidongshouxiang = "自动\n艏向";
        btnstr_zidongzongxiang = "自动\n纵向";
        btnstr_zidonghengxiang = "自动\n横向";
        btnstr_chuanzhong = "船舯\n旋转";
        btnstr_chuanshou = "船艏\n旋转";
        btnstr_chuanwei = "船艉\n旋转";
        btnstr_zhuanru = "转入";
        btnstr_zhuanchu = "转出";
        btnstr_qiangqie = "强切";
        btnstr_ceshi = "测试";
        btnstr_tiaoguang = "调光";
        btnstr_zhongyingwen = "English"; //暂时没用
        btnstr_yingda = "应答/消声";
        btnstr_fanhui = "返回";
        btnstr_lingpai = "令牌";

        str_huizhuanlv = "艏向角速度";
        str_shoucetui = "艏侧推";
        str_weizuozhutui = "艉左主推";
        str_weiyouzhutui = "艉右主推";
        str_zuoduoji = "左舵机";
        str_youduoji = "右舵机";
        str_luoju = "螺距";
        str_zhuansu = "转速";

        str_yes = "是";
        str_no = "否";
        str_shouxiangxianzhi = "艏向限值";
        str_weizhixianzhi = "位置限值";
        str_jinggao = "警告";
        str_baojing = "报警";
        str_xianzhi = "限值";

        str_queding = "确定";
        str_quxiao = "取消";

        str_zhanminchen = "站名称";
        str_zhanzhuangtai = "状态";
        str_zhancuowu = "最后错误";
        str_benji = "本站";

        danwei_jie = "节";
        danwei_du = "°";
        danwei_mi = "米";
        danwei_mimiao = "米/秒";
        danwei_dufen = "°/分";
        danwei_dumiao = "°/秒";

        str_kongzhigui = "控制柜";
        str_caozuoduan = "操作终端";
        str_gps1weijiuxu = "GPS1未就绪";
        str_gps2weijiuxu = "GPS2未就绪";
        str_gyroweijiuxu = "Gyro未就绪";
        str_windweijiuxu = "Wind未就绪";
        str_windshujucuowu = "风速风向仪数据错误";
        str_windweijiuxu = "风速风向仪未就绪";
        str_shoucetuiready = "艏侧推已就绪";
        str_weizuozhutuiready = "艉左推已就绪";
        str_weiyouzhutuiready = "艉右推已就绪";
        str_zuoduojiready = "左舵机已就绪";
        str_youduojiready = "右舵机已就绪";
        str_shouxiangwarning = "艏向偏差大";
        str_shouxiangalarm = "艏向偏差过大";
        str_weizhiwarning = "位置偏差大";
        str_weizhialarm = "位置偏差过大";
        str_xwarning = "X位置偏差大";
        str_xalarm = "X位置偏差过大";
        str_ywarning = "Y位置偏差大";
        str_yalarm = "Y位置偏差过大";

        almstr_jinggao = "警告";
        almstr_baojing = "报警";
        almstr_tishi = "提示";
        almstr_jinji = "紧急";

        almtitle_yingda = "应答";
        almtitle_laiyuan = "来源";
        almtitle_shijian = "时间";
        almtitle_jibie = "级别";
        almtitle_leixing = "类型";
        almtitle_miaoshu = "描述";
        almtitle_xinxi = "信息";

        str_ip = "IP地址：";
        str_config = "配置文件版本：";
        str_otsw = "操作端软件版本：";
        str_ctlsw = "控制器软件版本：";
        str_sdk = "开发库版本：";
        str_ide = "编辑器版本:";
        str_windows = "操作系统版本：";

        str_zuoduo = "左舵";
        str_youduo = "右舵";
        str_weizuo = "艉左推";
        str_weiyou = "艉右推";
        str_GPS1_ZTST = "GPS1";
        str_GPS2_ZTST = "GPS2";
        str_fengsu_ZTST = "风速";//wind
        str_dianluojing_ZTST = "电罗经";//Gyro
        str_chuankou_ZTST = "串口";//Serial
        str_IO_ZTST = "IO";
        str_yitaiwang_ZTST = "以太网";//Net
        str_duanlu_ZTST = "断路";//Off

        str_tuilifenpeimoshi_ZTSZ = "推力分配模式";//Alloc.Mode
        str_shezhihuizhuanlv_ZTSZ = "设置回转率";//ROT
        str_fenglibuchang_ZTSZ = "风力补偿";//WindComp.
        str_zengyidengji_ZTSZ = "增益等级";//GainLevel
        str_zuidaduojiao_ZTSZ = "最大舵角";//Max Rudder Angle
        str_chuanbochishuileixing_ZTSZ = "船舶吃水类型";//Graught Type

        str_dianluojing_CQSZ = "电罗经";//电罗经Gyro
        str_GPS1_CQSZ = "GPS1";//GPS1
        str_GPS2_CQSZ = "GPS2";//GPS2
        str_fengsufengxiangyi_CQSZ = "风速风向仪";//Wind
        str_VDR_CQSZ = "VRS";//VRS
        str_qidong = "起动";

        str_year_XTSZ = "年";//年
        str_month_XTSZ = "月";//月
        str_day_XTSZ = "日";//日
        str_hour_XTSZ = "时";//时
        str_minute_XTSZ = "分";//分
        str_second_XTSZ = "秒";//秒
        str_guanbixitong_XTSZ = "关闭系统";//关闭系统
        str_guanbizhongduan_XTSZ = "关闭此操作终端";//关闭终端
        str_chongqizhongduan_XTSZ = "重启此操作终端";//重启终端

        str_JoyStick = "确认进入手操模式?";//手操模式
        str_PositionKeep = "确认进入位置保持模式?";//位置保持模式
        str_AutoPilot = "确认进入自动舵模式?";//自动舵模式
        str_AutoHead = "确认进入自动艏向模式?";//自动艏向模式
        str_AutoSurge = "确认进入自动纵向模式?";//自动纵向模式
        str_AutoSway = "确认进入自动横向模式?";//自动横向模式
        str_Standby = "确认进入待机模式?";
        str_AutoHSu = "确认进入自动艏向纵向模式?";
        str_AutoHSw = "确认进入自动艏向横向模式?";
        str_AutoSuSw = "确认进入自动纵向横向模式?";

        str_nomatch_joystick = "不满足进入手操模式的条件!";
        str_nomatch_standby = "不满足进入待机模式的条件!";
        str_nomatch_poskeep = "不满足进入位置保持模式的条件!";
        str_nomatch_autopilot = "不满足进入自动舵模式的条件!";
        str_nomatch_autohead = "不满足进入自动艏向模式的条件!";
        str_nomatch_autosurge = "不满足进入自动纵向模式的条件!";
        str_nomatch_autosway = "不满足进入自动横向模式的条件!";
        str_nomatch_headsurge = "不满足进入自动艏向纵向模式的条件!";
        str_nomatch_headsway = "不满足进入自动艏向横向模式的条件!";
        str_nomatch_surgesway = "不满足进入自动纵向横向模式的条件!";


        str_take_out = "控制站'%1'\n请求获得控制权。";
        str_give_in =  "控制站'%1'\n请求让出控制权。";
        str_gonglvxiaohao = "功率消耗";
        str_keyonggonglv = "可用功率：";

        str_shedingweizhi = "设定位置";
        str_dangqianweizhi = "当前位置";
        str_cankaoyuandian = "坐标原点参考传感器：";
        str_gpsmingcheng = "传感器名称";
        str_zhuangtai = "状态";
        str_jiaquan = "加权";
        str_zaixian = "在线";
        str_lixian = "离线";

        str_moshi1 = "模式一";
        str_moshi2 = "模式二";
        str_moshi3 = "模式三";

        str_liangdushezhi = "亮度设置：";
        str_kecaozuo = "可操作";
        str_cuowu = "错误";
        str_kaijishijian = "开机时间";
        str_beizhu = "备注";
        str_shebeimingcheng = "设备名称";

        str_on = "开";
        str_off = "关";
        str_gao = "高";
        str_zhong = "中";
        str_di = "低";

        str_baitian = "白天";
        str_wanshang = "晚上";

        str_CCalm0 = "控制器硬件损坏报警";
        str_CCalm1 = "罗经硬件警报";
        str_CCalm2 = "罗经野值警报";
        str_CCalm3 = "风速风向仪硬件警报";
        str_CCalm4 = "风速风向仪野值警报";
        str_CCalm5 = "艏侧推硬件错误警报";
        str_CCalm6 = "左主推硬件错误警报";
        str_CCalm7 = "右主推硬件错误警报";
        str_CCalm8 = "左舵硬件错误警报";
        str_CCalm9 = "右舵硬件错误警报";
        str_CCalm10 = "艏侧推跟随错误警报";
        str_CCalm11 = "左主推跟随错误警报";
        str_CCalm12 = "右主推跟随错误警报";
        str_CCalm13 = "左舵跟随错误警报";
        str_CCalm14 = "右舵跟随错误警报";
        str_CCalm15 = "控制器通信故障";

        str_CCinfo0 = "控制器未就绪";//控制器状态（0-未就绪，1-启动）
        str_CCinfo1 = "控制器启动";//控制器状态（0-未就绪，1-启动）
        str_CCinfo2 = "罗经未就绪";//罗经就绪
        str_CCinfo3 = "罗经就绪";//罗经就绪
        str_CCinfo4 = "风速风向仪未就绪";
        str_CCinfo5 = "风速风向仪就绪";
        str_CCinfo6 = "艏侧推未就绪";
        str_CCinfo7 = "艏侧推就绪";
        str_CCinfo8 = "左主推未就绪";
        str_CCinfo9 = "左主推就绪";
        str_CCinfo10 = "右主推未就绪";
        str_CCinfo11 = "右主推就绪";
        str_CCinfo12 = "左舵未就绪";
        str_CCinfo13 = "左舵就绪";
        str_CCinfo14 = "右舵未就绪";
        str_CCinfo15 = "右舵就绪";
        str_CCinfo16 = "Joystick模式关";
        str_CCinfo17 = "Joystick模式开";

        str_OTalm0 = "x轴断线 ";
        str_OTalm1 = "y轴断线";
        str_OTalm2 = "z轴断线";
        str_OTalm3 = "艏向偏差警告";
        str_OTalm4 = "艏向偏差报警";
    }
}
