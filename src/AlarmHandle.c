//#include <malloc.h>
#include "MyConfig.h"
#include "AlarmHandle.h"
#include "MyTime.h"
#include "stdio.h"



typedef struct timearray
{
	long timedata;
	int index;
}TimeArray;
TimeArray timevalue[512]={0};
int atlen=0;//带报警标志的参数测点数量。
char AtimeDsp[512][30]={0};//should be atimedsp[512][19];
int AtIndex[512]={0};

extern time_t AlarmTime[513];
//extern void GetSysTime(void);
unsigned short AlarmSignDisplay[513]={0};//用于显示的报警标志。每点标志只存在一种报警级别，和闪光/平光标志。
long AlarmTimeDisplay[513]={0};//用于显示的每点报警时间。


/*-------------------------------------------------------------------
*unsigned short GetAlarmLevel(unsigned short)--计算报警级别
*返回值：0x0-正常,0x01-一级,0x02-二级,0x04-三级,0x08-断线。
*/
unsigned short GetAlarmLevel(unsigned short level1)
{
	unsigned short level2=0;
	if((level1 & 0x0808) != 0)			
		{
		level2=0x08;
		}
		else
		{
			if((level1 & 0x0404) != 0)			level2=0x04;
				else
				{
					if((level1 & 0x0202) != 0)			level2=0x02;
						else
							{
								if((level1 & 0x0101) != 0)			level2=0x01;
									else level2=0;
							}
				}
				
		}
		//printf("level2=%d\n",level2);
	return level2;		
}

/*--------------------------------------------------------
*unsigned short GetAlarmSign(unsigned short)--计算报警标志。
*0x0:normal;0x08:断线报警
*0x01:上限一级报警;0x0100:下限一级报警;
*0x02:上限二级报警;0x0200:下限二级报警;
*0x04:上限三级报警;0x0400:下限三级报警;
*/
unsigned short GetAlarmBZ(unsigned short bz1)
{
	unsigned short bz2=0;

	if((bz1 & 0x08) != 0)		//下限断线	
		{
			bz2=0x08;
			return bz2;
		}
	else if((bz1 & 0x0800) != 0)		//上限断线	
		{
			bz2=0x0800;
			return bz2;
		}
	else if((bz1 & 0x04) != 0)//下限3级
		{
			bz2=0x04;
		  return bz2;	  		
	  }
	else if((bz1 & 0x0400) != 0)//上限3级
		{
			bz2=0x0400;
		  return bz2;	  		
	  }
	else if((bz1 & 0x02) != 0)//下限2级
		{
			bz2=0x02;
		  return bz2;	  		
	  }
	else if((bz1 & 0x0200) != 0)//上限2级
		{
			bz2=0x0200;
		  return bz2;	  		
	  }
	else if((bz1 & 0x01) != 0)//下限1级
		{
			bz2=0x01;
		  return bz2;	  		
	  }
	else if((bz1 & 0x0100) != 0)//上限1级
		{
			bz2=0x0100;
		  return bz2;	  		
	  }
	else
		{
			bz2=0x0;//正常
		  return bz2;	  		
	  }
}


/*---------------------------------------------------------------------
*报警处理函数。
*输入：当前的报警时间，报警级别，报警实测值;(取自全局数组)
*输出：AlarmSignDisplay[i],AlarmTimeDisplay[i];
*/
void AlarmHandle()
{
	int i;	
	unsigned short biaoZhi=0;
	unsigned short jiBie0=0;
	unsigned short jiBie1=0;
	unsigned short yingDa=0;
	unsigned short fuWei=0;
	unsigned short temp=0;
	unsigned short shift1=0;
	unsigned short shift2=0;
	
	while(1)
	{
	//printf("0infopage:66=%d,67=%d,68=%d\n",RealData[66],RealData[67],RealData[68]);
	for ( i=1;i<513;i++)
		{
		if(GPID[i]!=0||(AlarmSignDisplay[i]&0x0020)==0)//非空，非屏蔽
			{
			yingDa=RealData[18];//应答键
			fuWei=RealData[21];//复位键
			//printf("yingda=%d, fuwei=%d\n",yingDa,fuWei);
			biaoZhi=GetAlarmBZ(AlarmSign[i]);
			if(yingDa == 1)//如果应答，则清除所有报警的闪光标志
				{
				//printf("ying da found!\n");
				AlarmSignDisplay[i]=AlarmSignDisplay[i]&0xffef;
				}

			else
				{//如果没有应答继续
				jiBie0=GetAlarmLevel(biaoZhi);
				jiBie1=GetAlarmLevel(AlarmSignDisplay[i]);
				
				if(jiBie0==jiBie1)
					{
					if((biaoZhi&AlarmSignDisplay[i])==0 && biaoZhi!=0)//同级跳变，将同级的原报警置零，保留其他报警，并添加新报警，并闪光。
						{
						AlarmSignDisplay[i]=(!jiBie0)&AlarmSignDisplay[i];
						AlarmSignDisplay[i]=(!(jiBie0<<8))&AlarmSignDisplay[i];
						AlarmSignDisplay[i]=0x0010|(biaoZhi|AlarmSignDisplay[i]);
						AlarmTimeDisplay[i]=AlarmTime[i];
						//printf("tjtb at=%ld\n",AlarmTime[i]);
						}
					}
				if(jiBie0>jiBie1)//报警级别升高
					{
					AlarmSignDisplay[i]=0x0010|(biaoZhi|AlarmSignDisplay[i]);
					AlarmTimeDisplay[i]=AlarmTime[i];
					//printf("jbsg at=%ld i=%d\n",AlarmTime[i],i);
					}
				if(jiBie0<jiBie1)//报警级别降低
					{
					if((AlarmSignDisplay[i]&0x0010) == 0)//不闪光
						{
							//unsigned short shift=jiBie1;
						if((AlarmSignDisplay[i]&0x08) != 0)
							{
							AlarmSignDisplay[i]&=0xfff7;
							jiBie1=GetAlarmLevel(AlarmSignDisplay[i]);
							time(&AlarmTimeDisplay[i]);//time 函数:取当前时间。防止断线报警降级
							}
						temp=AlarmSignDisplay[i];
						if((AlarmSignDisplay[i]&0x0606)==0 || fuWei==1)//不包含2、3级报警，或者已复位
							{
							if(jiBie0==0)
								{
								shift2=0;
								}
							else 
								{
								shift1=jiBie0-1;
								shift2=(shift1<<8)|shift1;
								}
							 AlarmSignDisplay[i]&=shift2;
							 if((biaoZhi&temp) != 0)
							 	{
						 		AlarmTimeDisplay[i]=AlarmTime[i];
						 		AlarmSignDisplay[i]|=biaoZhi;
						 		}
							 else
							 	{
					 			if(biaoZhi!=0)
					 				{
				 					AlarmSignDisplay[i]=0x10|(AlarmSignDisplay[i]|biaoZhi);
				 					AlarmTimeDisplay[i]=AlarmTime[i];
					 				}
					 			else
					 				{
				 					AlarmSignDisplay[i]=0x0;
				 					AlarmTimeDisplay[i]=AlarmTime[i];
									//printf("jbjd3 at=%ld\n",AlarmTime[i]);
					 				}
							 	}
							}
						}					
					}//END 级别降低					
				}
			}//END if(GPID[i]！=0||AlarmSignDisplay[i]&0x0020==0)
		}//END for ( int i=1；i<513;i++)
		taskDelay(100);//every tick is 5ms
	}
}

/*----------------------------------------------------------
*GetAlltime(),得到所有带报警标志的参数的报警时间和测点索引号。
*将报警时间值和索引号写入结构体timevalue[512]中
*/
void GetAlltime()
{	
	int i=0,j=0;
	atlen=0;
	
	for(i=1;i<513;i++)
	{
		if((AlarmSignDisplay[i] & 0x0f0f) != 0)
 		{
 		//printf("asd=%d\n",AlarmSignDisplay[i]);
 			timevalue[j].timedata=AlarmTimeDisplay[i];
 			timevalue[j].index=i;
			atlen+=1;
			j++;
 		}
	}

}

/*---------------------------------------------------------------------
*
*/


/*----------------------------------------------------------------
*冒泡排序，最终得到按照报警时间从小到大的测点索引号。
*/
void BubbleSort()
{    
   unsigned long temp1=0;
   int temp2=0;
   int i=0,j=0;
   
   for(i=0;i<atlen;i++)
   {
    for(j=i;j<atlen;j++)
    {
     if(timevalue[j].timedata>timevalue[i].timedata)
     	{
	      temp1=timevalue[i].timedata;
	      timevalue[i].timedata=timevalue[j].timedata;
	      timevalue[j].timedata=temp1;
		  	temp2=timevalue[i].index;
	      timevalue[i].index=timevalue[j].index;
	      timevalue[j].index=temp2;	      
     }
    }
  }
   //for(i=0;i<atlen;i++)
   //printf("timedata=%d , index=%d \n",timevalue[i].timedata,timevalue[i].index);
}
 
/********************************** 
 struct tm
{
    int tm_sec;	//seconds after the minute	- [0, 59] 
    int tm_min;	//minutes after the hour	- [0, 59] 
    int tm_hour;	//hours after midnight		- [0, 23] 
    int tm_mday;	// day of the month		- [1, 31] 
    int tm_mon;	// months since January		- [0, 11]
    int tm_year;	// years since 1900	
    int tm_wday;	// days since Sunday		- [0, 6]
    int tm_yday;	// days since January 1		- [0, 365]
    int tm_isdst;	// Daylight Saving Time flag
};//BIOS下的时间结构体
************************************/

/******************************************************
*ULtime2Dsptime(),将unsigned long类型的时间转换成tm时间结构体，
*并且最终转换成用来tilcon显示的时间值。
*/
void ULtime2Dsptime()
{
	unsigned long systime=0;
	struct tm *realtime;
	int i=0;
	int sec=0;
	int min=0;
	int hour=0;
	int day=0;
	int month=0;
	int year=0;

	
	for(i=0;i<atlen;i++)
	{
		systime=timevalue[i].timedata;
		//printf("systime=%ld!\n",systime);
		realtime=localtime(&systime);
		if(realtime==NULL)
			continue;
		sec=realtime->tm_sec;
		min=realtime->tm_min;
		hour=realtime->tm_hour;
		day=realtime->tm_mday;
		month=realtime->tm_mon+1;
		year=realtime->tm_year+1900;//since 1900
		sprintf(&AtimeDsp[i][0],"%d-%d-%d %d:%d:%d",year,month,day,hour,min,sec);	
		/*printf("year=%d,month=%d,day=%d,hour=%d,min=%d,sec=%d\n",realtime->tm_year,realtime->tm_mon,\
													realtime->tm_mday,realtime->tm_hour,\
													realtime->tm_min,realtime->tm_sec);*/
	}

}

/******************************************************
*ULtime2Dsptime(),将unsigned long类型的时间转换成tm时间结构体，
*并且最终转换成用来tilcon显示的时间值。
*/
void GetIndex()
{
	int i=0;

	for(i=0;i<atlen;i++)
	{
	// printf("index:=%d   ",timevalue[i].index);
		AtIndex[i]=timevalue[i].index;
		//printf("AtIndex[i]=%d\n",AtIndex[i]);
	}
}

/******************************************************
*GetADspData(),最终得到用于tilcon界面显示的三个变量：
*AtIndex：按照报警时间顺序排列的测点索引号。
*AtDsp:用于显示的报警时间。
*atlen:报警数量,[0,512]。
*/
void alarmdspdata()
{	
  	//AlarmHandle();
	GetAlltime();
	BubbleSort();
	ULtime2Dsptime();
	GetIndex();
	//printf("getalarmdspdata\n");
}



