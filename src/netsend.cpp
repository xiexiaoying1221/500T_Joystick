#include "netsend.h"
#include <QtDebug>
#include <QByteArray>
#include <QThread>




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
    udpsocket = new QUdpSocket(this);


    bindresult = udpsocket->bind(QHostAddress::LocalHost,DanboPort, QUdpSocket::ShareAddress);
    if(bindresult == false)
        qDebug("bind error!");
    else
    {
        qDebug("bind ok!");
    }

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

    //qDebug("danbo now");
    QByteArray datagram = "Danbo message xxy" + QByteArray::number(messageNo);
    udpsocket->writeDatagram(datagram.data(), datagram.size(),
                            QHostAddress("192.168.1.245") , DanboPort);//QHostAddress::LocalHost
    ++messageNo;
}

void Qudpsender::sendBroadcastDatagram()
{
    //double joy_x = 3.12423;
    //double joy_y = 5.234545;
    //double joy_z = 80.23421;
    QByteArray datagram(QByteArray::number(joystick_x));
    datagram.append(';');
    datagram.append(QByteArray::number(joystick_y));
    // datagram("helloxxy2014");
    datagram.append(';');
    datagram.append(QByteArray::number(joystick_z));
    datagram.append(';');

    bool validBroadcastAddresses = true;
    foreach (QHostAddress address, broadcastAddresses)
    {
        if (broadcastSocket.writeDatagram(datagram, address,broadcastPort) == -1)
            validBroadcastAddresses = false;
    }
    messageNo++;


    if (!validBroadcastAddresses)
    {
        updateAddresses();
    }
    else
        qDebug("broadcast now");

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
