#include "AlarmHandle.h"
#include<math.h>
#include<QDebug>

bool Enable_buzzer = false;//使能蜂鸣器，为true时蜂鸣器响。

int run_time = 0;

bool flag_alm_head = false;
bool flag_alm_x = false;
bool flag_alm_y = false;
bool flag_alm_pos = false;
bool flag_alm_spd = false;


bool isAlarm_pos = false;
bool isAlarm_head = false;
bool isWarn_pos = false;
bool isWarn_head = false;
bool isAlarm_posx = false;
bool isWarn_posx = false;
bool isAlarm_posy = false;
bool isWarn_posy = false;

void BubbleSort();

typedef struct alarmarry
{
        QString timedata;
        int index;

}AlarmArray;


AlarmArray allalarm[50]={0};
int atlen = 0;

QString AlarmList[50][9];

QString AlarmOrderList[50][8];

//测点列表
//1-GPS1状态
//2-GPS1状态
//3-wind状态
//4-电罗经状态
//5-艏侧推就绪
//6-左主推
//7-右主推
//8-左舵机
//9-右舵机
//10-艏向偏差
//11-位置偏差


void CCAlarmHandle();
void AlarmAnswer();
void Alarm4Disp();
void InfoHandle();

void GetAlmFlag()
{
    switch(Operate_mode)
    {
    case READY_MODE:
        flag_alm_head = false;
        flag_alm_x = false;
        flag_alm_y = false;
        flag_alm_pos = false;
        flag_alm_spd = false;
        break;
    case MANUAL_MODE:
        flag_alm_head = false;
        flag_alm_x = false;
        flag_alm_y = false;
        flag_alm_pos = false;
        flag_alm_spd = false;

        break;
    case KEEPPOS_MODE:
        flag_alm_head = false;
        flag_alm_x = false;
        flag_alm_y = false;
        flag_alm_pos = true;
        flag_alm_spd = false;

        break;
    case AUTOPLT_MODE:
        flag_alm_head = true;
        flag_alm_x = false;
        flag_alm_y = false;
        flag_alm_pos = false;
        flag_alm_spd = true;
        break;
    case HEADING_MODE:
        flag_alm_head = true;
        flag_alm_x = false;
        flag_alm_y = false;
        flag_alm_pos = false;
        flag_alm_spd = false;

        break;
    case KEEPX_MODE:
        flag_alm_head = false;
        flag_alm_x = true;
        flag_alm_y = false;
        flag_alm_pos = false;
        flag_alm_spd = false;
        break;
    case KEEPY_MODE:
        flag_alm_head = false;
        flag_alm_x = false;
        flag_alm_y = true;
        flag_alm_pos = false;
        flag_alm_spd = false;
        break;
    case KEEPXD_MODE:
        flag_alm_head = true;
        flag_alm_x = true;
        flag_alm_y = false;
        flag_alm_pos = false;
        flag_alm_spd = false;
        break;
    case KEEPYD_MODE:
        flag_alm_head = true;
        flag_alm_x = false;
        flag_alm_y = true;
        flag_alm_pos = false;
        flag_alm_spd = false;
        break;
    case KEEPXY_MODE:
        flag_alm_head = false;
        flag_alm_x = false;
        flag_alm_y = false;
        flag_alm_pos = true;
        flag_alm_spd = false;
        break;
    default:
        flag_alm_head = false;
        flag_alm_x = false;
        flag_alm_y = false;
        flag_alm_pos = false;
        flag_alm_spd = false;
        break;
    }

}

void AlarmListMain()
{
    CCAlarmHandle();//处理控制柜过来的报警信息
    InfoHandle();//处理控制柜过来的提示信息
    OTAlarmHandle();//
    AlarmAnswer();//报警应答
    BubbleSort();//报警排序
    Alarm4Disp();//报警显示数组更新
    EnableBuzzer();//使能蜂鸣器
    Refresh_Alarm_words();
}

//alarmlist count number from 0 to 14, sum 15
void CCAlarmHandle()
{
    QTime cTime = QTime::currentTime();
    QDate cDate = QDate::currentDate();

    QString alm_time;
    QString alm_date;

    static bool alm_flag[30] = {false};

    int i;

    for( i = 0 ; i<16 ; i++ )
    {
        if(CCdata_alarm[i] == true && alm_flag[i] == false)//新报警
        {
            alm_flag[i] = true;//报警已存在,锁定报警时间
            //qDebug()<<"ccalarm------------i:"<<i;
            alm_time = cTime.toString("hh:mm:ss");//时分秒
            alm_date = cDate.toString("yyyy-MM-dd");//年月日

            AlarmList[i][0] = "*";//报警应答状态
            AlarmList[i][2] = QString("%1 %2").arg(alm_date).arg(alm_time);//报警时间
            AlarmList[i][4] = QString("ON");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;
            AlarmList[i][6] = QString(" ");//报警信息

        }

        if(CCdata_alarm[i] == false )//报警恢复
        {
            AlarmList[i][4] = QString("--");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;
            alm_flag[i] = false;
        }
    }


}
//alarmlist count number from 15 to 22, sum 8
void InfoHandle()
{
    QTime cTime = QTime::currentTime();
    QDate cDate = QDate::currentDate();

    QString alm_time;
    QString alm_date;

    static bool first_enter = true;
    static bool last_info[20] = {false};

    int i;
    int j;

    if(first_enter == true)//CCdata_info[i] != last_info[i] 初始化
    {
        for(i=0,j=16;i<8;i++,j++)//控制柜共有8条提示信息需要显示
        {
//            qDebug()<<"info["<<i<<"]:"<<CCdata_info[i]<<last_info[i]<<first_enter;
            if(CCdata_info[i] == false)//第一次进入，未就绪提示
            {
                last_info[i] = false;
//                qDebug()<<"info------------i:"<<i;
                alm_time = cTime.toString("hh:mm:ss");//时分秒
                alm_date = cDate.toString("yyyy-MM-dd");//年月日

                AlarmList[j][0] = "*";//报警应答状态
                AlarmList[j][2] = QString("%1 %2").arg(alm_date).arg(alm_time);//报警时间
                AlarmList[j][4] = QString("H");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;
                AlarmList[j][6] = QString(" ");//报警信息
            }

            if(CCdata_info[i] == true)//第一次进入，已就绪提示
            {
                last_info[i] = true;

                alm_time = cTime.toString("hh:mm:ss");//时分秒
                alm_date = cDate.toString("yyyy-MM-dd");//年月日
                AlarmList[j][0] = "*";//报警应答状态
                AlarmList[j][1] = str_kongzhigui;//报警来源设备
                AlarmList[j][2] = QString("%1 %2").arg(alm_date).arg(alm_time);//报警时间
                AlarmList[j][3] = almstr_tishi;//QString("警告");//报警类型-警告、报警、紧急、提示
                AlarmList[j][4] = QString("H");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;

                switch(i)
                {
                case 0:
                    AlarmList[j][5] = str_CCinfo1;//报警描述
                    break;
                case 1:
                    AlarmList[j][5] = str_CCinfo3;//报警描述
                    break;
                case 2:
                    AlarmList[j][5] = str_CCinfo5; //报警描述
                    break;
                case 3:
                    AlarmList[j][5] = str_CCinfo7;//报警描述
                    break;
                case 4:
                    AlarmList[j][5] = str_CCinfo9;//报警描述
                    break;
                case 5:
                    AlarmList[j][5] = str_CCinfo11;//报警描述
                    break;
                case 6:
                    AlarmList[j][5] = str_CCinfo13;//报警描述
                    break;
                case 7:
                    AlarmList[j][5] = str_CCinfo15;//报警描述
//                    qDebug()<<"2R.RUD"<<j<<AlarmList[j][5];
                    break;
                default:
                    break;
                }
            }
            first_enter = false;
        }
    }
    else
    {
        for(i=0,j=16;i<8;i++,j++)//控制柜共有8条提示信息需要显示
        {
            if(CCdata_info[i] == false && last_info[i] != false )//未就绪提示
            {
                last_info[i] = false;
                alm_time = cTime.toString("hh:mm:ss");//时分秒
                alm_date = cDate.toString("yyyy-MM-dd");//年月日

                AlarmList[j][0] = "*";//报警应答状态
                AlarmList[j][2] = QString("%1 %2").arg(alm_date).arg(alm_time);//报警时间
                AlarmList[j][4] = QString("H");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;
                AlarmList[j][6] = QString(" ");//报警信息
            }
            if(CCdata_info[i] == true &&  last_info[i] != true )//已就绪提示
            {
                last_info[i] = true;

                alm_time = cTime.toString("hh:mm:ss");//时分秒
                alm_date = cDate.toString("yyyy-MM-dd");//年月日

                AlarmList[j][0] = "*";//报警应答状态
                AlarmList[j][1] = str_kongzhigui;//报警来源设备
                AlarmList[j][2] = QString("%1 %2").arg(alm_date).arg(alm_time);//报警时间
                AlarmList[j][3] = almstr_tishi;//QString("警告");//报警类型-警告、报警、紧急、提示
                AlarmList[j][4] = QString("H");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;
            }
        }
    }
}

//alarmlist count number from 23 to 27, sum 5
void OTAlarmHandle()
{
    QTime cTime = QTime::currentTime();
    QDate cDate = QDate::currentDate();

    QString alm_time;
    QString alm_date;

    static bool ota_flag[30] = {false};

    int i,j;

    for(i=0,j=24;i<5;i++)
    {
        if(OTdata_alarm[i] == true && ota_flag[i] != true)
        {
            ota_flag[i] = true;//报警已存在,锁定报警时间
//            qDebug()<<"OTALM------------i:"<<i;
            alm_time = cTime.toString("hh:mm:ss");//时分秒
            alm_date = cDate.toString("yyyy-MM-dd");//年月日

            AlarmList[j][0] = "*";//报警应答状态
            AlarmList[j][2] = QString("%1 %2").arg(alm_date).arg(alm_time);//报警时间
            AlarmList[j][4] = QString("ON");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;
            AlarmList[j][6] = QString(" ");//报警信息
         }

        if(CCdata_alarm[i] == false )//报警恢复
        {
            AlarmList[i][4] = QString("--");//报警状态-模拟量报警状态：HS,HH,H,L,LL,LS;开关量报警状态-ON;正常-‘--’;
            ota_flag[i] = false;
        }
    }
}


void AlarmAnswer()
{
    int num , i;
    if(btn_answer == 1){//确认
        for(num = 0; num <30 ; num++){
            AlarmList[num][0] = "";
        }
    }
    for(num = 0, i = 0; num <30 ; num++){
        if( (AlarmList[num][0] == "*") || ( (AlarmList[num][4] != "--") && (AlarmList[num][4] != NULL) ) ){
            //记录测点列表中存在报警的测点报警时间和测点序号
            allalarm[i].timedata = AlarmList[num][2];
            allalarm[i].index = num;
            i += 1;
            //qDebug()<<"alarm order index"<<num;
        }
    }
    atlen = i;

//	for( num = 0; num < atlen; num++){
//		i = allalarm[num].index;
//		qDebug()<<i<<AlarmList[i][5];
//	}
//	qDebug()<<"end";

}

//报警排序
void BubbleSort()
{
    QString temp1;
    int temp2=0;
    int i=0,j=0;

    for(i=0;i<atlen;i++)
    {
        for(j=i;j<atlen;j++)
        {
             if(allalarm[j].timedata>allalarm[i].timedata)
             {
                  temp1=allalarm[i].timedata;
                  allalarm[i].timedata=allalarm[j].timedata;
                  allalarm[j].timedata=temp1;
                            temp2=allalarm[i].index;
                  allalarm[i].index=allalarm[j].index;
                  allalarm[j].index=temp2;
             }
        }
    }
}


void Alarm4Disp()
{
    int i = 0,j = 0;
    int node = 0;
    //按照排序好的报警序号，得到显示用的报警列表AlarmOrderList


//    qDebug()<<"baojingshu atlen "<<atlen;
    for(i = 0; i < atlen; i++)
    {
        node = allalarm[i].index;
        for(j = 0; j < 7; j++)
        {
            AlarmOrderList[i][j] = AlarmList[node][j];
        }
    }
}


void Refresh_Alarm_words()
{
    int i = 0,j = 0;
    int node = 0;
    //按照排序好的报警序号，得到显示用的报警列表AlarmOrderList

    for(i = 0; i < atlen; i++)
    {
        node = allalarm[i].index;
        if( node < 16){
            AlarmList[node][1] = str_kongzhigui;//报警来源设备
            AlarmList[node][3] = almstr_jinggao;//QString("警告");//报警类型-警告、报警、紧急、提示
        }
        else if( node < 24){
            AlarmList[node][1] = str_kongzhigui;//报警来源设备
            AlarmList[node][3] = almstr_tishi;//QString("警告");//报警类型-警告、报警、紧急、提示
        }
        else if( node < 29){
            AlarmList[node][1] = str_caozuoduan;//报警来源设备
            AlarmList[node][3] = almstr_baojing;//QString("警告");//报警类型-警告、报警、紧急、提示
        }
        switch(node)
        {
        case 0:
            AlarmList[node][5] = str_CCalm0;//报警描述
            break;
        case 1:
            AlarmList[node][5] = str_CCalm1;//报警描述
            break;
        case 2:
            AlarmList[node][5] = str_CCalm2;//报警描述
            break;
        case 3:
            AlarmList[node][5] = str_CCalm3;//报警描述
            break;
        case 4:
            AlarmList[node][5] = str_CCalm4;//报警描述
            break;
        case 5:
            AlarmList[node][5] = str_CCalm5;//报警描述
            break;
        case 6:
            AlarmList[node][5] = str_CCalm6;//报警描述
            break;
        case 7:
            AlarmList[node][5] = str_CCalm7;//报警描述
            break;
        case 8:
            AlarmList[node][5] = str_CCalm8;//报警描述
            break;
        case 9:
            AlarmList[node][5] = str_CCalm9;//报警描述
            break;
        case 10:
            AlarmList[node][5] = str_CCalm10;//报警描述
            break;
        case 11:
            AlarmList[node][5] = str_CCalm11;//报警描述
            break;
        case 12:
            AlarmList[node][5] = str_CCalm12;//报警描述
            break;
        case 13:
            AlarmList[node][5] = str_CCalm13;//报警描述
            break;
        case 14:
            AlarmList[node][5] = str_CCalm14;//报警描述
            break;
        case 15:
            AlarmList[node][5] = str_CCalm15;//报警描述
            break;
        case 16:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo0;
            }
            else{
                AlarmList[node][5] = str_CCinfo1;
            }
            break;
        case 17:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo2;
            }
            else{
                AlarmList[node][5] = str_CCinfo3;
            }
            break;
        case 18:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo4;
            }
            else{
                AlarmList[node][5] = str_CCinfo5;
            }
            break;
        case 19:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo6;
            }
            else{
                AlarmList[node][5] = str_CCinfo7;
            }
            break;
        case 20:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo8;
            }
            else{
                AlarmList[node][5] = str_CCinfo9;
            }
            break;
        case 21:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo10;
            }
            else{
                AlarmList[node][5] = str_CCinfo11;
            }
            break;
        case 22:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo12;
            }
            else{
                AlarmList[node][5] = str_CCinfo13;
            }
            break;
        case 23:
            if(!CCdata_info[node - 16]){
                AlarmList[node][5] = str_CCinfo14;
            }
            else{
                AlarmList[node][5] = str_CCinfo15;
            }
            break;
        case 24:
            AlarmList[node][5] = str_OTalm0;
            break;
        case 25:
            AlarmList[node][5] = str_OTalm1;
            break;
        case 26:
            AlarmList[node][5] = str_OTalm2;
            break;
        case 27:
            AlarmList[node][5] = str_OTalm3;
            break;
        case 28:
            AlarmList[node][5] = str_OTalm4;
            break;

        default:
            break;

        }

    }

}

void EnableBuzzer()
{
    int unanswer_num = 0;
    int i = 0;

    for(i = 0; i<atlen ; i++)
    {
        if(AlarmOrderList[i][0] == "*")
            unanswer_num +=1;
    }
    //qDebug()<<"unanswer num is "<<unanswer_num;
    if(unanswer_num > 0)
    {
        Enable_buzzer = true;
    }
    else
        Enable_buzzer = false;
}



