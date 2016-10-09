#ifndef QUDPSENDER_H
#define QUDPSENDER_H

#include <QObject>
#include <QList>
#include <QtNetwork>
#include <QUdpSocket>
#include <QTimer>
#include <QHostAddress>
#include "dataCommit.h"

class Qudpsender : public QObject
{
Q_OBJECT
public:
    Qudpsender();//QObject *parent = 0
    void senddatagram();

private slots:
    void DanboDatagram();

    void sendBroadcastDatagram();
private:
    void updateAddresses();

    QUdpSocket *udpsocket;
    QTimer *timer;
    int messageNo;
    QList<QHostAddress> ipAddresses;
    static const unsigned DanboPort = 45000;
    QList<QHostAddress> broadcastAddresses;

    static const qint32 BroadcastInterval = 2000;
    static const unsigned broadcastPort = 46000;

    QUdpSocket broadcastSocket;

};

#endif // QUDPSENDER_H
