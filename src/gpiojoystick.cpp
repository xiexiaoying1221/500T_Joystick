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

#include "gpiojoystick.h"




GpioJoystick::GpioJoystick(QObject *parent) :
    QObject(parent)
{
    m_lib = nullptr;
    setbuzzer = 0;
    setbuzzer_old = 0;
    first = true;
    ready = false;
}

void GpioJoystick::GpioInit(){

    Fun1 initial;
    Fun5 setdirection;

    DWORD ret = 0;
    bool ok;

    if(m_lib == nullptr){
        m_lib = new QLibrary("Susi.dll", this);
    }
    if(Enable_buzzer)
        setbuzzer = 1;
    else
        setbuzzer = 0;

    if(first){
        first = false;
        if (m_lib->load()){
            initial = (Fun1)m_lib->resolve("SusiDllInit");
            if( initial ){
                    if( initial() ){
                        qDebug()<<"init GPIO OK!";
                        //将第一路GPIO设置为写
                        setdirection = (Fun5)m_lib->resolve("SusiIOSetDirection");
                        if(setdirection){
                            //IO: 0-write,1-read.
                            //BOOL SusiIOSetDirection(BYTE PinNum, BYTE IO, DWORD *PinDirMask);
                            ok = setdirection(0,0,&ret);
                            if(ok){
                                //qDebug()<<"Successed! set GPIO 0 to write, GPIO ready!";
                                ready = true;
                            }
                            else{
                                qDebug()<<"Error!, set GPIO 0 to write fail";
                                ready = false;
                            }
                        }
                        else{
                            qDebug()<<"Error, SusiIOSetDirection not found";
                            ready = false;
                        }
                    }
                    else{
                        qDebug()<<"Error, susi dll init fail";
                        ready = false;
                    }
            }
            else{
                qDebug()<<"Error, susi dll init not found!";
                ready = false;
            }
        }
        else{
            qDebug()<<"Error, susi dll load fail";
            ready = false;
        }
    }
}

void GpioJoystick::Gpio2Buzzer(){
    Fun4 setstatus;

    bool ok;

    if(m_lib == nullptr || !ready){
        qDebug()<<"Error, susi GPIO not ready";
        GpioInit();
        return;
    }
    if(Enable_buzzer)
        setbuzzer = 1;
    else
        setbuzzer = 0;

    if(setbuzzer != setbuzzer_old){
        setstatus = (Fun4)m_lib->resolve("SusiIOWriteEx");
        if(setstatus){
            //BOOL SusiIOWriteEx(BYTE PinNum, BOOL status);
            ok = setstatus(0,Enable_buzzer);
            if(ok){
                //qDebug()<<"Successed! setbuzzer"<<Enable_buzzer;
                setbuzzer_old = setbuzzer;
            }
            else{
                qDebug()<<"Error, SusiIOWriteEx fail";
            }
        }
        else
        {
            qDebug()<<"Error, SusiIOWriteEx not found!";
        }
    }
}

