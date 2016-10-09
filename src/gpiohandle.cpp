#include "gpiohandle.h"




GpioHandle::GpioHandle(QObject *parent):
QObject(parent),mylib("EAPI_1.dll")
{
//     GpioInit();
  //  mylib("EAPI_1.dll");

}

int GpioHandle::GpioInit()
{
    int result;
    //mylib("EAPI_1.dll");
   // mylib.isLibrary("EAPI_1.dll");

    if (mylib.load())
    {
        //QMessageBox::information(NULL,"OK","DLL load is OK!");
        qDebug()<<"DLL load is OK!";

        open=(Fun1)mylib.resolve("EApiLibInitialize");
        set=(Fun)mylib.resolve("EApiGPIOSetLevel");
        if (open)
        {
            result=open();
        }
        else
        {
            //QMessageBox::information(NULL,"NO","Linke to Function is not OK!!!!");
            qDebug()<<"Link to Function open() is not OK!";
        }
        if (set)
        {
            result=set(EAPI_GPIO_ID2,1,0);
        }
        else
        {
            //QMessageBox::information(NULL,"NO","Linke to Function is not OK!!!!");
            qDebug()<<"Link to Function set() is not OK!";
        }

        return OK;
    }
    else
    {
        //QMessageBox::information(NULL,"NO","DLL is not loaded!");
        qDebug()<<"DLL is not loaded!";
        return ERROR;
    }

}

void GpioHandle::GpioSet(int channel,int data)
{
    //set(channel,1,data);
}

void GpioHandle::Gpio2Buzzer()
{
    STATUS result= OK;
    int buzzer_channel = EAPI_GPIO_ID2;
    int i = 0;
    static bool test = true;


    if(OK == result)
    {
//        if(Enable_buzzer == true)
//        {
//            GpioSet(buzzer_channel,1);
//        }
//        else
//        {
//            GpioSet(buzzer_channel,0);
//        }
//        if(test == true)
//        {
//           set(EAPI_GPIO_ID2,1,1);

//        }
//        else
//        {
//            set(EAPI_GPIO_ID2,1,0);

//        }
        if(test == true)
            test = false;
        else
            test = true;
    }
}
