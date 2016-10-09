#include "qudpsender.h"
#include <QtDebug>
#include <QByteArray>
#include <QThread>
#include "dataCommit.h"




Qudpsender::Qudpsender()
{

//    messageNo = 1;
//    DanboPort = 45000;
//    udpsocket = new QUdpSocket(this);


//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
//    timer->start(1000);


//    while(messageNo <= 100)
//    {
//        qDebug()<<"messageno is"<<messageNo;

//        QByteArray datagram = "Broadcast message xxy" + QByteArray::number(messageNo);
//        udpsocket->writeDatagram(datagram.data(), datagram.size(),
//                                 QHostAddress::QHostAddress("192.168.1.1"), 45454);
//        ++messageNo;
//        //QThread::wait(500);
//    }

}

void Qudpsender::senddatagram()
{

    bool bindresult = false;

    messageNo = 1;
/*
    udpsocket = new QUdpSocket(this);

    bindresult = udpsocket->bind(QHostAddress::LocalHost,DanboPort, QUdpSocket::ShareAddress);
    if(bindresult == false)
        qDebug("bind error!");
    else
    {
        qDebug("bind ok!");
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(DanboDatagram()));
    timer->start(1000);
*/
    updateAddresses();

    bindresult = broadcastSocket.bind(QHostAddress::Any, broadcastPort, QUdpSocket::ShareAddress
                         | QUdpSocket::ReuseAddressHint);
    if(bindresult == false)
        qDebug("bind error!");
    else
    {
        qDebug("bind ok!");
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sendBroadcastDatagram()));
    timer->start(1000);

}

void Qudpsender::DanboDatagram()
{
    static int msgnum = 0;
    int temp = 0;
    double joy_x = 1.1;
    double joy_y = 2.2;
    double joy_z = 3.3;
    char datagram[100] = {0};
    int len = 0;

    msgnum += 1;

    datagram[0] = msgnum;//序号
    datagram[1] = 0x09;//标识
    datagram[2] = 0x00;//长度-高字节
    datagram[3] = 0x40;//长度-低字节

    datagram[8] = Run_mode;
    datagram[9] = Operate_mode;
    set_heading = 359.9;
    temp = (int)(set_heading*10);
    datagram[10] = qHIBYTE(qHIWORD(temp));
    datagram[11] = qLOBYTE(qHIWORD(temp));
    datagram[12] = qHIBYTE(qLOWORD(temp));
    datagram[13] = qLOBYTE(qLOWORD(temp));

    temp = (short)(joy_x * 10);
    datagram[14] = qHIBYTE(temp);
    datagram[15] = qLOBYTE(temp);

    temp = (short)(joy_y * 10);
    datagram[16] = qHIBYTE(temp);
    datagram[17] = qLOBYTE(temp);

    temp = (short)(joy_z * 10);
    datagram[18] = qHIBYTE(temp);
    datagram[19] = qLOBYTE(temp);

    qDebug("send datagram10-13 is:%d,%d,%d,%d\n",datagram[10],datagram[11],datagram[12],datagram[13]);
    qDebug("send datagram is %s\n",datagram);

    len = sizeof(datagram);

    //qDebug("danbo now");
    //QByteArray datagram = "Danbo message xxy" + QByteArray::number(messageNo);
    if(udpsocket->writeDatagram(datagram, len, QHostAddress("192.168.10.10") , DanboPort) == -1)
        qDebug("danbo send error!\n");//QHostAddress::LocalHost
    else
    {
        ++msgnum;
    }

}

void Qudpsender::sendBroadcastDatagram()
{
    static int msgnum = 0;
    int temp = 0;
    double temp_setheading = 359.9;
    double temp_joyx = 78.1;
    double temp_joyy = 23.11;
    double temp_joyz = 34.123;
    double joy_x = 1.1;
    double joy_y = 2.2;
    double joy_z = 3.3;
    char datagram[100] = {0};
    QByteArray Broadcast_datagram;
    bool validBroadcastAddresses = true;


    Broadcast_datagram.isNull();
    Broadcast_datagram.append("$");
//    qDebug("Broadcast_datagram is %s \n",Broadcast_datagram.data());
    Broadcast_datagram.append(Broadcast_datagram.number(messageNo));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(Run_mode));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(Operate_mode));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(set_heading,'%f',1));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(set_north,'%f',1));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(set_east,'%f',2));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(joystick_x,'%f',3));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(joystick_y,'%f',3));
    Broadcast_datagram.append(",");
    Broadcast_datagram.append(Broadcast_datagram.number(joystick_z,'%f',3));
    Broadcast_datagram.append(";");
    qDebug("UDPSEND: %s \n",Broadcast_datagram.data());

/*数组打包发送

    msgnum += 1;

    datagram[0] = 0x01;//序号
    datagram[1] = 0x09;//标识
    datagram[2] = 0x00;//长度-高字节
    datagram[3] = 0x40;//长度-低字节

    datagram[8] = Run_mode;
    datagram[9] = Operate_mode;
    set_heading = 359.9;
    temp = (int)(set_heading*10);
    qDebug("set_heading = %d\n",temp);
    datagram[10] = qHIBYTE(qHIWORD(temp));
    datagram[11] = qLOBYTE(qHIWORD(temp));
    datagram[12] = qHIBYTE(qLOWORD(temp));
    datagram[13] = qLOBYTE(qLOWORD(temp));

    temp = (short)(joy_x * 10);
    datagram[14] = qHIBYTE(temp);
    datagram[15] = qLOBYTE(temp);

    temp = (short)(joy_y * 10);
    datagram[16] = qHIBYTE(temp);
    datagram[17] = qLOBYTE(temp);

    temp = (short)(joy_z * 10);
    datagram[18] = qHIBYTE(temp);
    datagram[19] = qLOBYTE(temp);


    qDebug("send datagram10-13 is:%d,%d,%d,%d,%d,%d\n",datagram[0],datagram[1],datagram[10],datagram[11],datagram[12],datagram[13]);
*/
    foreach (QHostAddress address, broadcastAddresses)
    {
        //if (broadcastSocket.writeDatagram(datagram, address,broadcastPort) == -1)//发送数组报文
        if (broadcastSocket.writeDatagram(Broadcast_datagram.data(), Broadcast_datagram.size(),address,broadcastPort) == -1)//发送数组报文
            validBroadcastAddresses = false;
    }
    messageNo++;


    if (!validBroadcastAddresses)
    {
        updateAddresses();
    }
    else
    {
        //qDebug("send broadcast now");
    }

}



void Qudpsender::updateAddresses()
{
    broadcastAddresses.clear();
    ipAddresses.clear();
    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces()) {
        foreach (QNetworkAddressEntry entry, interface.addressEntries()) {
            QHostAddress broadcastAddress = entry.broadcast();
            if (broadcastAddress != QHostAddress::Null && entry.ip() != QHostAddress::LocalHost) {
                broadcastAddresses << broadcastAddress;
                ipAddresses << entry.ip();
            }
        }
    }
}
