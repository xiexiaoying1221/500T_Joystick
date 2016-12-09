#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//-----------------------------------------------------------------------------
//	GPIO
//-----------------------------------------------------------------------------

//GPIO interface included in "REL_SUSI.H"
//int SusiIOAvailable();
//BOOL SusiIOCountEx(DWORD *inCount, DWORD *outCount);
//BOOL SusiIOQueryMask(DWORD flag, DWORD *Mask);
//BOOL SusiIOReadEx(BYTE PinNum, BOOL *status);
//BOOL SusiIOReadMultiEx(DWORD TargetPinMask, DWORD *StatusMask);
//BOOL SusiIOSetDirection(BYTE PinNum, BYTE IO, DWORD *PinDirMask);
//BOOL SusiIOSetDirectionMulti(DWORD TargetPinMask, DWORD *PinDirMask);
//BOOL SusiIOWriteEx(BYTE PinNum, BOOL status);
//BOOL SusiIOWriteMultiEx(DWORD TargetPinMask, DWORD StatusMask);

#include "gpio/susigpio.h"

SusiGpio* SusiGpio::_singleton = nullptr;

SusiGpio::SusiGpio(QObject *parent) :
    QObject(parent)
{
    _lib = nullptr;
    _funInitial = nullptr;
    _funSetDirection = nullptr;
    _funSetStatus = nullptr;
    ready = false;
}
//全局单例模式
SusiGpio* SusiGpio::Instance( void ){
    if( _singleton == nullptr ){
        _singleton = new SusiGpio();
    }
    return _singleton;
}

void SusiGpio::init(){

    ready = false;
    if(_lib != nullptr){
        delete _lib;
    }
    _lib = new QLibrary("Susi.dll", this);
    ready = false;

    if (!_lib->load()){
//        qDebug()<<"error, susi dll load fail";
        ready = false;
        return;
    }

    _funInitial =      (Fun1)_lib->resolve("SusiDllInit");
    _funSetDirection = (Fun5)_lib->resolve("SusiIOSetDirection");
    _funSetStatus =    (Fun4)_lib->resolve("SusiIOWriteEx");
    if( _funInitial==nullptr || _funSetDirection==nullptr
            || _funSetStatus==nullptr ){
//        qDebug()<<"error, susi dll function not found!";
        ready = false;
        return;
    }

    if( _funInitial() ){
        qDebug()<<"gpio ready!";
        ready = true;
    }
    else{
//        qDebug()<<"error, susi dll init fail";
    }

}

bool SusiGpio::setIODirection(int pinNum, int direction){
    if(_funSetDirection == nullptr || !ready){
//        qDebug()<<"error, susi GPIO not ready";
        return false;
    }

    DWORD ret = 0;
    bool ok;

    //IO: 0-write,1-read.
    //BOOL SusiIOSetDirection(BYTE PinNum, BYTE IO, DWORD *PinDirMask);
    ok = _funSetDirection(pinNum , direction , &ret);
    if(ok){
//        qDebug()<<"successed! set GPIO direction!";
        return true;
    }
    else{
//        qDebug()<<"error!, set GPIO direction fail";
        return false;
    }

}

bool SusiGpio::writeIO(int pinNum, bool status){
    if(_funSetStatus == nullptr || !ready){
//        qDebug()<<"Error, susi GPIO not ready";
        return false;
    }

    bool ok;
    //BOOL SusiIOWriteEx(BYTE PinNum, BOOL status);
    ok = _funSetStatus(pinNum , status);
    if(ok){
//        qDebug()<<"Successed! setPin";
        return true;
    }
    else{
//        qDebug()<<"Error, SusiIOWriteEx fail";
        return false;
    }

}
