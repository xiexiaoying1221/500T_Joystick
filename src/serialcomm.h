#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QObject>
#include <QStringList>
#include <QRegExp>
#include  <QSerialPort>

#define MAX_DATA8 6.879
//#define ZERO_DATA8 4.543
#define MIN_DATA8 2.137

#define MAX_DATA7 8.085
//#define ZERO_DATA7 4.524
#define MIN_DATA7 0.897

#define MAX_DATA6 8.154
//#define ZERO_DATA6 4.508
#define MIN_DATA6 0.936


class SerialComm : public QObject
{
    Q_OBJECT
public:
    explicit SerialComm(QObject *parent = 0);

signals:
private:
    QString myCom_data;
    QSerialPort * myCom;

public slots:
    void readMyCom();
    void sendMyCom();
    void OpenMyCom();
    void HandleMyComData();
    void closeMyCom();

};

#endif // SERIALCOMM_H
