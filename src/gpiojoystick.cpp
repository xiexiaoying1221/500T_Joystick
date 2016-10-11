#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//-----------------------------------------------------------------------------
//	GPIO
//-----------------------------------------------------------------------------
//  GPIO interface included in "REL_SUSI.H"
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
    //QObject(parent),mylib("EAPI_1.dll")
}

int GpioJoystick::GpioInit()
{
    static int setbuzzer = 0;
    static int setbuzzer_old = 0;
    static bool first = true;
    //mylib("EAPI_1.dll");
   // mylib.isLibrary("EAPI_1.dll");
    QLibrary mylib("Susi.dll");

    bool init;

    if(Enable_buzzer == true)
        setbuzzer = 1;
    else
        setbuzzer = 0;

    if(setbuzzer != setbuzzer_old || first == true)
    {
        if(first == true)
            first = false;

        if (mylib.load())
        {
            qDebug()<<"DLL load is OK!";

            init = mylib.resolve("SusiDllInit");
            if(init)
            {
                qDebug()<<"init GPIO OK!";
            }
            else
            {
                qDebug()<<"init GPIO ERROR!";
            }


            /*
            open=(Fun1)mylib.resolve("EApiLibInitialize");
            set=(Fun)mylib.resolve("EApiGPIOSetLevel");
            if (open)
            {
                result=open();
            }
            else
            {
                qDebug()<<"Link to Function open() is not OK!";
            }
            if (set)
            {
                result=set(EAPI_GPIO_ID2,1,setbuzzer);
            }
            else
            {
                 qDebug()<<"Link to Function set() is not OK!";
            }
            */

            return OK;
        }
        else
        {
            qDebug()<<"DLL is not loaded!";
            return ERROR;
        }

        setbuzzer_old = setbuzzer;
    }

}

void GpioJoystick::Gpio2Buzzer()
{
    static bool setbuzzer = 0;
    static int setbuzzer_old = 0;
    static bool first = true;
    Fun2 init;
    Fun3 setdirection;
    Fun4 setstatus;

    QLibrary mylib("Susi.dll");



    if(Enable_buzzer == true)
        setbuzzer = 1;
    else
        setbuzzer = 0;

    if(setbuzzer != setbuzzer_old || first == true){
        if(first == true)
            first = false;

        if (mylib.load()){
            qDebug()<<"DLL load is OK!";


            init = (Fun2)mylib.resolve("SusiDllInit");
            if(init){
                init();
                //qDebug()<<"LINK init GPIO OK!";
            }
            else{
                qDebug()<<"LINK init GPIO ERROR!";
            }

            //将第一路GPIO设置为写
            setdirection = (Fun3)mylib.resolve("SusiIOSetDirectionMulti");
            if(setdirection){
                //BOOL SusiIOSetDirectionMulti(DWORD TargetPinMask, DWORD *PinDirMask);
                //TargetPinMask=0000 0001(only set gpio0 direction)
                //0-write,1-read.
                setdirection(1,0);
                //qDebug()<<"LINK setdirection GPIO OK!";
            }
            else
            {
                qDebug()<<"LINK setdirection GPIO ERROR!";
            }

            setstatus = (Fun4)mylib.resolve("SusiIOWriteEx");
            if(setstatus)
            {
                //BOOL SusiIOWriteEx(BYTE PinNum, BOOL status);
                setstatus(0,setbuzzer);
                //qDebug()<<"LINK setstatus GPIO OK!";
                qDebug()<<"setbuzzer"<<setbuzzer;
            }
            else
            {
                qDebug()<<"LINK setstatus GPIO ERROR!";
            }
//            return OK;
        }
        else
        {
            qDebug()<<"DLL is not loaded!";
//            return ERROR;
        }

        setbuzzer_old = setbuzzer;
    }
}

