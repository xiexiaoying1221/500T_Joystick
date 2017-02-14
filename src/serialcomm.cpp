#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "serialcomm.h"
#include "dataCommit.h"
#include <QDebug>
#include <math.h>

//float SerialComm::joystick_x_old[5] = {0.0};
//float SerialComm::joystick_y_old[5] = {0.0};
//float SerialComm::joystick_z_old[5] = {0.0};

long error_count = 0;

SerialComm* SerialComm::_singleton = nullptr;

SerialComm::SerialComm(QObject *parent) :
    QObject(parent)
{
    stateError = true;
}

//全局单例模式
SerialComm* SerialComm::Instance( void ){
    if( _singleton == nullptr ){
        _singleton = new SerialComm();
    }
    return _singleton;
}


void SerialComm::OpenMyCom()
{
    _overTime = new QTimer(this);
    _overTime->setSingleShot(true);
    connect(_overTime,SIGNAL(timeout()),this,SLOT(overTimeError()));
    _overTime->start(10*1000);

    bool open_flag = false;
    _sendTimer = new QTimer(this);

    myCom = new QSerialPort(this);
#ifdef PORTABLE_STATION
    //便携式串口
    myCom->setPortName("COM1");
    //数据位设置，我们设置为8位数据位
    myCom->setDataBits(QSerialPort::Data8);
    //停止位设置，我们设置为1位停止位
    myCom->setStopBits(QSerialPort::OneStop);
    //奇偶校验设置，我们设置为无校验
    myCom->setParity(QSerialPort::NoParity);
    //数据流控制设置，我们设置为无数据流控制
    myCom->setFlowControl(QSerialPort::NoFlowControl);
    //波特率设置，我们设置为9600
    myCom->setBaudRate(9600);
#else
    //固定式串口
    myCom->setPortName("COM2");
    //数据位设置，我们设置为8位数据位
    myCom->setDataBits(QSerialPort::Data8);
    //停止位设置，我们设置为1位停止位
    myCom->setStopBits(QSerialPort::OneStop);
    //奇偶校验设置，我们设置为无校验
    myCom->setParity(QSerialPort::NoParity);
    //数据流控制设置，我们设置为无数据流控制
    myCom->setFlowControl(QSerialPort::NoFlowControl);
    //波特率设置，我们设置为9600
    myCom->setBaudRate(9600);
    //固定端要发送
    _sendTimer->setSingleShot(false);
    connect(_sendTimer,SIGNAL(timeout()),this,SLOT(sendMyCom()));
    _sendTimer->start(200);
#endif
    //以读写方式打开串口
    open_flag = myCom->open(QIODevice::ReadWrite);

    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作


#ifdef SIMULATION
    //仿真模式
    connect(_sendTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));
    _sendTimer->start(500);
#endif

}

void SerialComm::readMyCom()
{
    static bool newdata_flag = false;
    static int num = 0;
    int len = 0;
    QByteArray temp_data = myCom->readAll();
#ifdef PORTABLE_STATION

#ifdef SIMULATION
    //仿真
    temp_data.append(0x24).append(0x2C);
    temp_data.append(char(0x00)).append(0xB9).append(0x2C);
    temp_data.append(char(0x00)).append(0xA5).append(0x2C);
    temp_data.append(char(0x00)).append(0x4A).append(0x2C);
    temp_data.append(char(0x00)).append(0x0A);
//    qDebug()<<"SerialComm::readMyCom"<<"simulation"<<temp_data<<temp_data.size();
#endif
    len = temp_data.size();
    if(len == 0){
        newdata_flag = true;
        error_count +=1;
    }
    else{
        //注意：移动端手柄的编码格式是ASCII和Hex混编，不用固定式的QString::append()方法
        //必须先把Hex转换为ASCII编码
        error_count = 0;
        char* pChar = temp_data.data();
        quint16 tempInt = 0;
        for(int i =0; i<temp_data.size(); i++){
            if(*(pChar+i) == ','){
                //','是分隔符
                myCom_data.append(QString::number(tempInt)).append(",");
                tempInt = 0;
            }
            else{
                tempInt = tempInt * 256;
                quint8 tempInt8 = *(pChar+i);
                tempInt = tempInt + tempInt8;
            }
        }
        myCom_data.append(QString::number(tempInt));
        num += len;
//        qDebug()<<"SerialComm::readMyCom"<<"transform to ASCii"<<myCom_data;
    }
    if(num >= 13){
        newdata_flag = false;
        HandleMyComData();
        stateError = false;
        num = 0;
        myCom_data.clear();
    }
    if(error_count > 80){
        OpenMyCom();
        error_count = 0;
        stateError = true;
    }
#else

    len = temp_data.size();
//    qDebug()<<len<<temp_data;
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
//        qDebug()<<"SerialComm::readMyCom"<<myCom_data;
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
#endif

}

void SerialComm::HandleMyComData()
{
    int i = 0;
    static float joystick_x_old[50] = {0.0};
    static float joystick_y_old[50] = {0.0};
    static float joystick_z_old[50] = {0.0};
    //2016.09.09以下为修改部分
    _overTime->start(10*1000);
    //qDebug()<<"SerialComm::readMyCom"<<myCom_data;
#ifdef PORTABLE_STATION
    //移动式终端的取值
    QStringList list = myCom_data.split(",");
    qDebug()<<"SerialComm::HandleMyComData"<<list;
    rawX = (float)list[1].toInt();
    rawY = (float)list[2].toInt();
    rawZ = (float)list[3].toInt();
	
#else
    //固定式终端的正则表达式
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
//    qDebug()<<list[6]<<list[7]<<list[8]<<pos;
    rawX = list[6].toFloat();
    rawY = list[7].toFloat();
    rawZ = list[8].toFloat();

#endif


    float zeroBig,zeroSmall;
//计算x轴
    zeroBig = setStickXZero + setStickXDeadband;
    zeroSmall = setStickXZero - setStickXDeadband;
    if(setStickXMax >= setStickXMin){
        //设置的最大值大于设置的最小值
        //从小到大  Min<zeroSmall<zero<zeroBig<Max
        if(rawX >= zeroBig){
            //根据定义，X轴位于前进区
            joystick_x = 100.0*( rawX- zeroBig) / (setStickXMax - zeroBig);
        }
        else if(rawX <= zeroSmall){
            //根据定义，X轴位于后退区
            joystick_x = -100.0*(zeroSmall - rawX) /(zeroSmall - setStickXMin);
        }
        else{
            //零位
            joystick_x = 0.0;
        }
    }
    else{
        //设置的最大值小于设置的最小值
        //从小到大  Max<zeroSmall<zero<zeroBig<Min
        if(rawX >= zeroBig){
            //根据定义，X轴位于前进区
            joystick_x = 100.0*( rawX- zeroBig) / (setStickXMin - zeroBig);
        }
        else if(rawX <= zeroSmall){
            //根据定义，X轴位于后退区
            joystick_x = -100.0*(zeroSmall - rawX) /(zeroSmall - setStickXMax);
        }
        else{
            //零位
            joystick_x = 0.0;
        }
    }
//计算y轴
    zeroBig = setStickYZero + setStickYDeadband;
    zeroSmall = setStickYZero - setStickYDeadband;
    if(setStickYMax >= setStickYMin){
        //设置的最大值大于设置的最小值
        //从小到大  Min<zeroSmall<zero<zeroBig<Max
        if(rawY >= zeroBig){
            //根据定义，Y轴位于右平移区
            joystick_y = 100.0*( rawY- zeroBig) / (setStickYMax - zeroBig);
        }
        else if(rawY <= zeroSmall){
            //根据定义，Y轴位于左平移区
            joystick_y = -100.0*(zeroSmall - rawY) /(zeroSmall - setStickYMin);
        }
        else{
            //零位
            joystick_y = 0.0;
        }
    }
    else{
        //设置的最大值小于设置的最小值
        //从小到大  Max<zeroSmall<zero<zeroBig<Min
        if(rawY >= zeroBig){
            //根据定义，Y轴位于右平移区
            joystick_y = 100.0*( rawY- zeroBig) / (setStickYMin - zeroBig);
        }
        else if(rawY <= zeroSmall){
            //根据定义，Y轴位于左平移区
            joystick_y = -100.0*(zeroSmall - rawY) /(zeroSmall - setStickYMax);
        }
        else{
            //零位
            joystick_y = 0.0;
        }
    }
//计算z轴
    zeroBig = setStickZZero + setStickZDeadband;
    zeroSmall = setStickZZero - setStickZDeadband;
    if(setStickZMax >= setStickZMin){
        //设置的最大值大于设置的最小值
        //从小到大  Min<zeroSmall<zero<zeroBig<Max
        if(rawZ >= zeroBig){
            //根据定义，Z轴位于右旋转区
            joystick_z = 100.0*( rawZ- zeroBig) / (setStickZMax - zeroBig);
        }
        else if(rawZ <= zeroSmall){
            //根据定义，Y轴位于左旋转区
            joystick_z = -100.0*(zeroSmall - rawZ) /(zeroSmall - setStickZMin);
        }
        else{
            //零位
            joystick_z = 0.0;
        }
    }
    else{
        //设置的最大值小于设置的最小值
        //从小到大  Max<zeroSmall<zero<zeroBig<Min
        if(rawZ >= zeroBig){
            //根据定义，Y轴位于右旋转区
            joystick_z = 100.0*( rawZ- zeroBig) / (setStickZMin - zeroBig);
        }
        else if(rawY <= zeroSmall){
            //根据定义，Y轴位于左旋转区
            joystick_z = -100.0*(zeroSmall - rawZ) /(zeroSmall - setStickZMax);
        }
        else{
            //零位
            joystick_z = 0.0;
        }
    }
//    老程序2016.11.22替换
//    joystick_x = 100.0 * (rawX - zero6)/half6;//(rawX - zero6)/half6;
//    joystick_y = 100.0 * (rawY - zero7)/half7;//(rawY - zero7)/half7;
//    joystick_z = 100.0 * (rawZ - zero8)/half8;//(rawZ - zero8)/half8;

    if(!flag_fullprop){
        joystick_x /= 2.0;
        joystick_y /= 2.0;
        joystick_z /= 2.0;
    }
//第一次启动时，所有设置都为0，此时的输出值也为0
    if(setStickXMax ==0 && setStickXMin ==0 && setStickXZero ==0){
        joystick_x = 0.0;
        joystick_y = 0.0;
        joystick_z = 0.0;
    }

#ifndef PORTABLE_STATION
//固定端专用
//断线报警
//2016.11.22
    if(rawX <= setStickXMin -0.1 || rawX >= setStickXMax +0.1 )
    {
        OTdata_alarm[0] = 1;
		joystick_x = joystick_x_old[0];
    }
    else 
	{
		OTdata_alarm[0] = 0;

        for(i=0;i<49;i++)
		{
            joystick_x_old[i] = joystick_x_old[i+1];
		}
        joystick_x_old[49] = joystick_x;
    }
    if(rawY <= setStickYMin -0.1 || rawY >= setStickYMax +0.1 )
    {
        OTdata_alarm[1] = 1;
		joystick_y = joystick_y_old[0];
    }
    else 
	{
		OTdata_alarm[1] = 0;

        for(i=0;i<49;i++)
		{
            joystick_y_old[i] = joystick_y_old[i+1];
		}
        joystick_y_old[49] = joystick_y;
    }
    if(rawZ <= setStickZMin -0.1 || rawZ >= setStickZMax +0.1)
    {
        OTdata_alarm[2] = 1;
		joystick_z = joystick_z_old[0];
    }
    else 
    {
		OTdata_alarm[2] = 0;
        for(i=0;i<49;i++)
        {
            joystick_z_old[i] = joystick_z_old[i+1];
        }
        joystick_z_old[49] = joystick_z;
    }
#else
//移动端专用
//断线报警
//2016.11.22
    if(rawX <= setStickXMin -5 || rawX >= setStickXMax +5 )
    {
        OTdata_alarm[0] = 1;
        joystick_x = joystick_x_old[0];
    }
    else
    {
        OTdata_alarm[0] = 0;

        for(i=0;i<49;i++)
        {
            joystick_x_old[i] = joystick_x_old[i+1];
        }
        joystick_x_old[49] = joystick_x;
    }
    if(rawY <= setStickYMin -5 || rawY >= setStickYMax +5 )
    {
        OTdata_alarm[1] = 1;
        joystick_y = joystick_y_old[0];
    }
    else
    {
        OTdata_alarm[1] = 0;

        for(i=0;i<49;i++)
        {
            joystick_y_old[i] = joystick_y_old[i+1];
        }
        joystick_y_old[49] = joystick_y;
    }
    if(rawZ <= setStickZMin -5 || rawZ >= setStickZMax +5)
    {
        OTdata_alarm[2] = 1;
        joystick_z = joystick_z_old[0];
    }
    else
    {
        OTdata_alarm[2] = 0;
        for(i=0;i<49;i++)
        {
            joystick_z_old[i] = joystick_z_old[i+1];
        }
        joystick_z_old[49] = joystick_z;
    }
#endif

//限幅
    if(fabs(joystick_x)>100)
        joystick_x = 100.0 * joystick_x/fabs(joystick_x);
    if(fabs(joystick_y)>100)
        joystick_y = 100.0 * joystick_y/fabs(joystick_y);
    if(fabs(joystick_z)>100)
        joystick_z = 100.0 * joystick_z/fabs(joystick_z);

//    qDebug()<<"Joystick x,y,z"<<joystick_x<<joystick_y<<joystick_z;
    //cmd_Fx 牛顿 joystick_x 百分比
    cmd_Fx = SwitchJoy2Force(joystick_x,1);
    cmd_Fy = SwitchJoy2Force(joystick_y,2);
    cmd_Nz = SwitchJoy2Force(joystick_z,3);

    //qDebug()<<"cmd_Fx,y,z"<<cmd_Fx<<cmd_Fy<<cmd_Nz;
    //如果本机是主站，masterJoystick跟踪本站数值
    if( stat_master ){
        masterJoystick_x = joystick_x;
        masterJoystick_y = joystick_y;
        masterJoystick_z = joystick_z;
    }
}


void SerialComm::sendMyCom()
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


void SerialComm::overTimeError(){
    stateError = true;
    OTdata_alarm[0] = 1;
    OTdata_alarm[1] = 1;
    OTdata_alarm[2] = 1;
}
