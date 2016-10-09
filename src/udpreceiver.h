#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QObject>
#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>

class udpreceiver : public QObject
{
Q_OBJECT
public:
    udpreceiver();

    void receivedatagram();
private slots:
    void processPendingDatagrams();
    void readBroadcastDatagram();


private:
    QUdpSocket udpSocket;
    static const unsigned broadcastPort = 45000;
};

#endif // UDPRECEIVER_H
