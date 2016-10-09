#include "gpioresponse.h"

GpioResponse::GpioResponse(QObject *parent) :
    QObject(parent)
{
}
void GpioResponse::GpioInit()
{
    int res = EApiLibInitialize();
    res = EApiLibUnInitialize();

}

void GpioResponse::GpioOutput()
{
//    unsigned long in=1,out=2;
//    int unanswer_num = 0;
//    int i = 0;

//    for(i = 0; i<atlen ; i++)
//    {
//        if(AlarmOrderList[i][0] == "*")
//            unanswer_num +=1;

//    }
//    if(unanswer_num > 0)
//    {
////        EApiGPIOGetLevel(EAPI_GPIO_ID0,1,&in);
//        EApiGPIOSetLevel(EAPI_GPIO_ID0,1,out);
//    }
}
