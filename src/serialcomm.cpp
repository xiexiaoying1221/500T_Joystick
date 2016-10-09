#include "serialcomm.h"
#include "dataCommit.h"
#include <QDebug>
#include <math.h>

float zero6 = 0.0,zero7 = 0.0,zero8 = 0.0;
float half6 = 0.0,half7 = 0.0,half8 = 0.0;
long error_count = 0;

SerialComm::SerialComm(QObject *parent) :
    QObject(parent)
{
    //myCom = new Win_QextSerialPort("COM5",QextSerialBase::EventDriven);

}

void SerialComm::OpenMyCom()
{
    bool open_flag = false;
    myCom = new Win_QextSerialPort("COM2",QextSerialBase::EventDriven);

    //定义串口对象，指定串口名和查询模式，这里使用事件驱动EventDriven

    open_flag = myCom ->open(QIODevice::ReadWrite);
    qDebug()<<"open_flag:"<<open_flag;
    //以读写方式打开串口

    myCom->setBaudRate(BAUD9600);
    //波特率设置，我们设置为9600

    myCom->setDataBits(DATA_8);
    //数据位设置，我们设置为8位数据位

    myCom->setParity(PAR_NONE);
    //奇偶校验设置，我们设置为无校验

    myCom->setStopBits(STOP_1);
    //停止位设置，我们设置为1位停止位

    myCom->setFlowControl(FLOW_OFF);
    //数据流控制设置，我们设置为无数据流控制

    myCom->setTimeout(500);

    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作

    half6 = (MAX_DATA6 - MIN_DATA6)/2.0;
    zero6 = (MAX_DATA6 + MIN_DATA6)/2.0;
    half7 = (MAX_DATA7 - MIN_DATA7)/2.0;
    zero7 = (MAX_DATA7 + MIN_DATA7)/2.0;
    half8 = (MAX_DATA8 - MIN_DATA8)/2.0;
    zero8 = (MAX_DATA8 + MIN_DATA8)/2.0;

}

void SerialComm::readMyCom()
{
    static bool newdata_flag = false;
    static int num = 0;
    int len = 0;
    QString str;
    QByteArray temp_data = myCom->readAll();
    len = temp_data.size();
    //qDebug()<<len<<temp_data;
    //qDebug()<<"serial rcv len = "<<len;

    if(len == 0)
    {
//        qDebug("serial receive is 0!");
        newdata_flag = true;
//        num = 0;
        error_count +=1;
    }
    else
    {
        error_count = 0;
        //只有当newdata_flag == true时，说明当前及后面共56个串口数据为一帧，否则即使有数据也不采纳
        myCom_data.append(temp_data.data());//str
        num += len;
//        qDebug()<<"num:"<<num<<"rec_data"<<QString( myCom_data );
    }
    if(num >= 55)
    {
        //qDebug()<<"SerialComm::readMyCom"<<myCom_data;
        newdata_flag = false;
        HandleMyComData();
        num = 0;
        myCom_data.clear();

    }


    if(error_count > 80)
    {
       qDebug("SerialCom receive wrong!");
//        myCom = new Win_QextSerialPort("COM5",QextSerialBase::EventDriven);

//        myCom->close();
       // Sleep(1000);
        OpenMyCom();
        //Sleep(6000);
        error_count = 0;
    }

}

void SerialComm::HandleMyComData()
{
    //2016.09.09以下为修改部分
    //qDebug()<<"SerialComm::readMyCom"<<myCom_data;
    QRegExp rx("\\+(\\d+\\.\\d+)"
               "\\+(\\d+\\.\\d+)"
               "\\+(\\d+\\.\\d+)"
               "\\+(\\d+\\.\\d+)"
               "\\+(\\d+\\.\\d+)"
               "\\+(\\d+\\.\\d+)"
               "\\+(\\d+\\.\\d+)"
               "\\+(\\d+\\.\\d+)");
    int pos = rx.indexIn(myCom_data);
    QStringList list = rx.capturedTexts();
    //qDebug()<<rx.errorString()<<pos<<list;
    //qDebug()<<list[6]<<list[7]<<list[8]<<pos;
    float com_data6 = 0.0,com_data7 = 0.0,com_data8 = 0.0;
    com_data6 = list[6].toFloat();
    com_data7 = list[7].toFloat();
    com_data8 = list[8].toFloat();
    //qDebug()<<"com_data6,7,8"<<com_data6<<com_data7<<com_data8;

    //2016.09.09以下为之前原有部分
//    int i = 0,from = 0;
//    QString str;

//    float com_data6 = 0.0,com_data7 = 0.0,com_data8 = 0.0;

//    int index1 = 0,index2 = 0,index3 = 0,index4 =0,index5 = 0,index6 = 0,index7 = 0,index8 = 0;

//    for(i=0;i<56;i++)
//    {
//        index1 = myCom_data.indexOf("+",0);
//        index2 = myCom_data.indexOf("+",index1+1);
//        index3 = myCom_data.indexOf("+",index2+1);
//        index4 = myCom_data.indexOf("+",index3+1);
//        index5 = myCom_data.indexOf("+",index4+1);
//        index6 = myCom_data.indexOf("+",index5+1);
//        index7 = myCom_data.indexOf("+",index6+1);
//        index8 = myCom_data.indexOf("+",index7+1);
//    }
//    //qDebug()<<"index1-8:"<<index1<<index2<<index3<<index4<<index5<<index6<<index7<<index8;
//    if(index1 != 0)
//    {
//        index8 = index7;
//        index7 = index6;
//        index6 = index5;
//        index5 = index4;
//        index4 = index3;
//        index3 = index2;
//        index2 = index1;
//        index1 = -1;
//    }

//    //qDebug()<<"index1-8:"<<index1<<index2<<index3<<index4<<index5<<index6<<index7<<index8;

//    if(index1 != -1)
//    {
//        from = index1 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//            //qDebug()<<"str"<<str;
//            myCom_data1.append(str);
//        }
//    }
//    if(index2 != -1)
//    {
//        from = index2 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//           // qDebug()<<"str"<<str;
//            myCom_data2.append(str);
//        }
//    }
//    if(index3 != -1)
//    {
//        from = index3 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//            //qDebug()<<"str"<<str;
//            myCom_data3.append(str);
//        }
//    }
//    if(index4 != -1)
//    {
//        from = index4 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//           // qDebug()<<"str"<<str;
//            myCom_data4.append(str);
//        }
//    }
//    if(index5 != -1)
//    {
//        from = index5 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//            //qDebug()<<"str"<<str;
//            myCom_data5.append(str);
//        }
//    }
//    if(index6 != -1)
//    {
//        from = index6 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//            //qDebug()<<"str"<<str;
//            myCom_data6.append(str);
//        }
//    }
//    if(index7 != -1)
//    {
//        from = index7 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//            //qDebug()<<"str"<<str;
//            myCom_data7.append(str);
//        }
//    }
//    if(index8 != -1)
//    {
//        from = index8 + 1;
//        for(i=from; i<(from + 6);i++)
//        {
//            str = myCom_data.data()[i];
//            //qDebug()<<"str"<<str;
//            myCom_data8.append(str);
//        }
//    }
//
//    com_data6 = myCom_data6.toFloat();
//    com_data7 = myCom_data7.toFloat();//toDouble();
//    com_data8 = myCom_data8.toFloat();//toDouble();

//    qDebug()<<"com_data6,7,8"<<com_data6<<com_data7<<com_data8;


    //handle
    if(com_data6 <= 0.0 || com_data6 >= 10.0)
    {
        OTdata_alarm[0] = 1;
    }
    else OTdata_alarm[0] = 0;
    if(com_data7 <= 0.0 || com_data7 >= 10.0)
    {
        OTdata_alarm[1] = 1;
    }
    else OTdata_alarm[1] = 0;
    if(com_data8 <= 0.0 || com_data8 >= 10.0)
    {
        OTdata_alarm[2] = 1;
    }
    else OTdata_alarm[2] = 0;

    joystick_x = 100.0 * (com_data6 - zero6)/half6;//(com_data6 - zero6)/half6;
    joystick_y = 100.0 * (com_data7 - zero7)/half7;//(com_data7 - zero7)/half7;
    joystick_z = 100.0 * (com_data8 - zero8)/half8;//(com_data8 - zero8)/half8;

    if(!flag_fullprop){
        joystick_x /= 2;
        joystick_y /= 2;
        joystick_z /= 2;
    }

    if(fabs(joystick_x)>100)
        joystick_x = 100.0 * joystick_x/fabs(joystick_x);
    if(fabs(joystick_y)>100)
        joystick_y = 100.0 * joystick_y/fabs(joystick_y);
    if(fabs(joystick_z)>100)
        joystick_z = 100.0 * joystick_z/fabs(joystick_z);

    //qDebug()<<"Joystick x,y,z"<<joystick_x<<joystick_y<<joystick_z;

    cmd_Fx = SwitchJoy2Force(joystick_x,1);
    cmd_Fy = SwitchJoy2Force(joystick_y,2);
    cmd_Nz = SwitchJoy2Force(joystick_z,3);

    //qDebug()<<"cmd_Fx,y,z"<<cmd_Fx<<cmd_Fy<<cmd_Nz;
}

void SerialComm::sendMyCom()  //发送数据
{
    int result =0;
    //int rcv_len = myCom_data.size();
    char wdata[10] = "#01\r";
    //先处理上一次收到的串口数据
    //qDebug()<<"myCom_data"<<myCom_data;
    /*
    if(rcv_len >= 55)
    {
        HandleMyComData();
        qDebug()<<"myCom_data1"<<myCom_data1<<"joystick_x"<<joystick_x;
        qDebug()<<"joystick_x,y,z"<<joystick_x<<joystick_y<<joystick_z;
    }
    */

    result = myCom->write(wdata);

    //qDebug()<<"write result is :"<<result;
    //qDebug()<<"serial send now!"<<myCom->isOpen();
    //以ASCII码形式将数据写入串口
    //qDebug() << "write: "<<myCom->bytesToWrite()<<"bytes";
    //输出要发送的字节数
}

void SerialComm::closeMyCom()
{
    myCom ->close();
}


