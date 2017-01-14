#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//-----------------------------------------------------------------------------
//	USB RELAY, portable station
//-----------------------------------------------------------------------------
#include <QByteArray>
#include <QDebug>
#include "usbrelay.h"

UsbRelay* UsbRelay::_singleton = nullptr;

UsbRelay::UsbRelay(QObject *parent) :
    QObject(parent)
{
    ready = false;
    handle = NULL;
    checkTimer = new QTimer(this);
    checkTimer->setSingleShot(false);
    checkTimer->setInterval(10*1000);
    connect(checkTimer,SIGNAL(timeout()),this,SLOT(stateCheck()));
}
//全局单例模式
UsbRelay* UsbRelay::Instance( void ){
    if( _singleton == nullptr ){
        _singleton = new UsbRelay();
    }
    return _singleton;
}
UsbRelay::~UsbRelay(){
    usb_relay_device_close(handle);
    usb_relay_exit();
    delete checkTimer;
}

void UsbRelay::init(){
    int ret = -1;
    ready = false;
    if(handle != NULL){
        usb_relay_device_close(handle);
        ret = usb_relay_exit();
    }

    ret = usb_relay_init();
    if(ret == 0){
        struct usb_relay_device_info* res = usb_relay_device_enumerate();
        if(res==NULL) return;
        do{
            handle = usb_relay_device_open(res);
            if(handle!=NULL){
                usb_relay_device_close_all_relay_channel(handle);
                ready = true;
                break;
            }
            res = res->next;
        }while(res->next!= NULL );
        usb_relay_device_free_enumerate(res);
    }

    checkTimer->start();
}

void UsbRelay::setIODirection(int pinNum, int direction){
    //always output.
}

void UsbRelay::writeIO(int pinNum, bool status){
    if(status)//energize
    {
        usb_relay_device_open_one_relay_channel(handle, pinNum);
    }
    else//denergize
    {
        usb_relay_device_close_one_relay_channel(handle, pinNum);
    }
}

bool UsbRelay::readIO(int pinNum){
    if(pinNum > 8 || pinNum < 0 ) return false;
    unsigned int res = 0;
    usb_relay_device_get_status(handle, &res);
    int mask = 1;
    mask = mask<<(pinNum - 1 );
    if( res & mask ){
        return true;
    }
    return false;
}

void UsbRelay::stateCheck(){
    unsigned int res;
    /*
    status bit: High --> Low 0000 0000 0000 0000 0000 0000 0000 0000, one bit indicate a relay status.
    the lowest bit 0 indicate relay one status, 1 -- means open status, 0 -- means closed status.
    bit 0/1/2/3/4/5/6/7/8 indicate relay 1/2/3/4/5/6/7/8 status
    @returns: 0 -- success; 1 -- error
    */
    int ret = usb_relay_device_get_status(handle, &res);
    if(ret ==1 ){
        init();
    }
}
