#include "serialrelay.h"

SerialRelay* SerialRelay::_singleton = nullptr;

SerialRelay::SerialRelay(QObject *parent) :
    QObject(parent)
{
    ready = false;
    port = nullptr;
    state = 0xFF;

    //if serrial port doesnt recev any data for 10sec, restart port;
    blankTimer = new QTimer(this);
    blankTimer->setSingleShot(true);
    blankTimer->setInterval(1000*1000);
    connect(blankTimer,SIGNAL(timeout()),this,SLOT(init()));
}

//全局单例模式
SerialRelay* SerialRelay::Instance( void ){
    if( _singleton == nullptr ){
        _singleton = new SerialRelay();
    }
    return _singleton;
}
SerialRelay::~SerialRelay(){
    if(port!= nullptr){
        port->close();
        delete port;
    }
    delete blankTimer;
}

void SerialRelay::init(){
    ready = false;
    state = 0xFF;
    if(port!= nullptr){
        port->close();
        delete port;
    }
    port = new QSerialPort();
    //固定式串口
    port->setPortName("COM10");
    //数据位设置，我们设置为8位数据位
    port->setDataBits(QSerialPort::Data8);
    //停止位设置，我们设置为1位停止位
    port->setStopBits(QSerialPort::OneStop);
    //奇偶校验设置，我们设置为无校验
    port->setParity(QSerialPort::NoParity);
    //数据流控制设置，我们设置为无数据流控制
    port->setFlowControl(QSerialPort::NoFlowControl);
    //波特率设置，我们设置为9600
    port->setBaudRate(9600);
    //以读写方式打开串口
    ready = port->open(QIODevice::ReadWrite);

    connect(port,SIGNAL(readyRead()),this,SLOT(read()));
    blankTimer->start();
    //初始化
    if(ready){
        char wdata[10] = "PQ";
        port->write(wdata);
    }

}
void SerialRelay::setIODirection(int pinNum, int direction){
    //always output.
}

void SerialRelay::writeIO(int pinNum, bool status){
    if(pinNum > 4 || pinNum < 0 ){
        return;
    }
    if(status){
        //energize
        quint8 temp = 0x01;
        temp = temp<<( pinNum - 1 );
        temp = ~temp;
        state = state & temp;
    }
    else{
        //denergize
        quint8 temp = 0x01;
        temp = temp<<( pinNum - 1 );
        state = state | temp;
    }
    port->write( (char*)&state, 1 );
}

bool SerialRelay::readIO(int pinNum){
    if(pinNum > 4 || pinNum < 0 ){
        return false;
    }
    quint8 temp = 0x01;
    temp<<( pinNum - 1 );
    if(state & temp){
        return false;
    }
    return true;
}

void SerialRelay::read(void){
    blankTimer->start();
}
