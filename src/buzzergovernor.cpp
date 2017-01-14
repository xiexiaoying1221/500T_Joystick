#include "buzzergovernor.h"
#include "gpio/serialrelay.h"
#include "gpio/usbrelay.h"

buzzerGovernor* buzzerGovernor::_singleton = nullptr;

buzzerGovernor::buzzerGovernor(QObject *parent) : QObject(parent)
{
    _t05 = new QTimer(this);
    connect(_t05,SIGNAL(timeout()),this,SLOT(process()));
    _t05->start(500);



#ifdef PORTABLE_STATION
    _gpio = UsbRelay::Instance();
    buzzPort = 1;
#else
    _gpio = SerialRelay::Instance();
    buzzPort = 4;
    //green 2
    //red 3
    //buzz 4
#endif
    _gpio->init();
    _gpio->setIODirection(0, 0);

    controlBits.buzzer1Hz =false;
    controlBits.buzzer2Hz = false;
    controlBits.buzzer05Hz = false;
    controlBits.buzzerContinuous = false;
    _countdown1Hz =0;
    _countdown2Hz =0;
    _countdown05Hz = 0;
    _countdownContinuous =0;
    _counterBuzzer1Hz =0;
    _counterBuzzer2Hz =0;
    _counterBuzzer05Hz =0;

}
//全局单例模式
buzzerGovernor* buzzerGovernor::Instance( void ){
    if( _singleton == nullptr ){
        _singleton = new buzzerGovernor();
    }
    return _singleton;
}

void buzzerGovernor::process(void){
    //方波发生器
    //0.5Hz方波
    if(_sq05Hz){
        _sq05Hz = false;
    }
    else{
        _sq05Hz = true;
    }

    //1Hz方波
    if(_counterBuzzer1Hz>=2){
        _counterBuzzer1Hz =0;
        if(_sq1Hz){
            _sq1Hz = false;
        }
        else{
            _sq1Hz = true;
        }
    }
    else{
        _counterBuzzer1Hz++;
    }

    //2Hz方波
    if(_counterBuzzer2Hz>=4){
        _counterBuzzer2Hz =0;
        if(_sq2Hz){
            _sq2Hz = false;
        }
        else{
            _sq2Hz = true;
        }
    }
    else{
        _counterBuzzer2Hz++;
    }

    //处理延时
    if(_countdown1Hz >0 ){
        _countdown1Hz --;
    }
    if(_countdown1Hz==0){
        controlBits.buzzer1Hz = false;
    }

    if(_countdown05Hz >0 ){
        _countdown05Hz --;
    }
    if(_countdown05Hz==0){
        controlBits.buzzer05Hz = false;
    }

    if(_countdown2Hz >0 ){
        _countdown2Hz --;
    }
    if(_countdown2Hz==0){
        controlBits.buzzer2Hz = false;
    }

    if(_countdownContinuous >=0 ){
        _countdownContinuous --;
    }
    if(_countdownContinuous==0){
        controlBits.buzzerContinuous = false;
    }

    //处理输出
    if(controlBits.buzzer05Hz){
        _buzzer = _sq05Hz;
    }
    else if(controlBits.buzzer1Hz){
        _buzzer = _sq1Hz;
    }
    else if(controlBits.buzzer2Hz){
        _buzzer = _sq2Hz;
    }
    else if(controlBits.buzzerContinuous){
        _buzzer = true;
    }
    else{
        _buzzer = false;
    }

    //输出到GPIO 0
    if(_gpio->isReady()){
        _gpio->writeIO(buzzPort, _buzzer);
    }
    else{
        _gpio->init();
        _gpio->setIODirection(1, 0);
    }
}


void buzzerGovernor::silence(void){
    controlBits.buzzer1Hz=false;
    controlBits.buzzer2Hz=false;
    controlBits.buzzer05Hz=false;
    controlBits.buzzerContinuous=false;
    _countdown1Hz = -1;
    _countdown2Hz = -1;
    _countdown05Hz = -1;
    _countdownContinuous = -1;
}

void buzzerGovernor::set1Hz(long during){
    controlBits.buzzer1Hz=true;
    _countdown1Hz = during *2;
}
void buzzerGovernor::reset1Hz(void){
    controlBits.buzzer1Hz=false;
    _countdown1Hz = -1;
}

void buzzerGovernor::set05Hz(long during){
    controlBits.buzzer05Hz=true;
    _countdown05Hz = during *2;
}
void buzzerGovernor::reset05Hz(void){
    controlBits.buzzer05Hz=false;
    _countdown05Hz = -1;
}

void buzzerGovernor::set2Hz(long during){
    controlBits.buzzer2Hz=true;
    _countdown2Hz = during *2;
}
void buzzerGovernor::reset2Hz(void){
    controlBits.buzzer2Hz=false;
    _countdown2Hz = -1;
}

void buzzerGovernor::setContinurous(long during){
    controlBits.buzzerContinuous=true;
    _countdownContinuous = during *2;
}
void buzzerGovernor::resetContinurous(void){
    controlBits.buzzerContinuous=false;
    _countdownContinuous = -1;
}
