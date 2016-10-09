#include "udpreceiver.h"
#include "dataCommit.h"

udpreceiver::udpreceiver()
{

}
void udpreceiver::receivedatagram()
{
    //udpSocket = new QUdpSocket(this);
    udpSocket.bind(QHostAddress::Any, broadcastPort, QUdpSocket::ShareAddress
                    | QUdpSocket::ReuseAddressHint);

    connect(&udpSocket, SIGNAL(readyRead()),
            this, SLOT(readBroadcastDatagram()));

}

void udpreceiver::processPendingDatagrams()
{

    QHostAddress senderIp;
    quint16 senderPort;

    while (udpSocket.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(datagram.data(), datagram.size());
    }
}

void udpreceiver::readBroadcastDatagram()
{

    while (udpSocket.hasPendingDatagrams())
    {
        QHostAddress senderIp;
        quint16 senderPort;
        QByteArray datagram;
        int i=0,j=0;
        int pos=0,datanum = 0;
        char tempstr[100][20]={0};
        double tempdata1 = 0.0,tempdata2 = 0.0;
        datagram.resize(udpSocket.pendingDatagramSize());
        if (udpSocket.readDatagram(datagram.data(), datagram.size(),
                                         &senderIp, &senderPort) == -1)
        {
            qDebug("readbroadcast ERROR!\n");
            continue;
        }

        else
        {
            //qDebug("read broadcast ok! %d",datagram.size());
            //qDebug("data : %d",QString(datagram.data()));
            qDebug()<<"recv str:"<<datagram.data();
        }
        for(i=0;i<datagram.size();i++)
        {
            if(datagram.data()[i] == ',')
            {
                //qDebug(", pos is %d\n",i);
                for(j=pos;j<i;j++)
                {
                    tempstr[datanum][j-pos]=datagram.data()[j];
                }
                datanum+=1;
                pos=i+1;
            }
        }
        heading = atoi(tempstr[0]);
        pos_north = atof(tempstr[1]);
        pos_east = atof(tempstr[1]);
        speed_u = atof(tempstr[1]);
        speed_v = atof(tempstr[1]);
        speed_r = atof(tempstr[1]);
        cmd_prop1_spd = atof(tempstr[1]);
        cmd_prop2_spd = atof(tempstr[1]);
        cmd_prop1_spd = atof(tempstr[1]);
        cmd_prop1_spd = atof(tempstr[1]);
        cmd_prop1_spd = atof(tempstr[1]);
        cmd_prop1_spd = atof(tempstr[1]);

        qDebug("UDPRECV:data1 %d,data2 %.1f",tempdata1,tempdata2);



        /*
        QList<QByteArray> list = datagram.split('@');
        if (list.size() != 2)
            continue;

        int senderServerPort = list.at(1).toInt();
        if (isLocalHostAddress(senderIp) && senderServerPort == serverPort)
            continue;

        if (!client->hasConnection(senderIp)) {
            Connection *connection = new Connection(this);
            emit newConnection(connection);
            connection->connectToHost(senderIp, senderServerPort);

        }
        */
    }
}
