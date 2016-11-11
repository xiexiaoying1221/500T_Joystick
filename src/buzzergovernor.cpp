#include "buzzergovernor.h"

buzzerGovernor::buzzerGovernor(QObject *parent) : QObject(parent)
{
    _t05 = new QTimer(this);
    connect(_t05,SIGNAL(timeout()),this,SLOT(process()));
    _t05->start(500);


}

void buzzerGovernor::process(void){
    //方波发生器
    if(_sq05Hz){
        _sq05Hz = false;
    }
    else{
        _sq05Hz = true;
    }

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
    if(_counterBuzzer1Hz >=0 ){
        if(_counterBuzzer1Hz==0){
            controlBits.buzzer1Hz = false;
        }
        _counterBuzzer1Hz --;
    }
    if(_counterBuzzer05Hz >=0 ){
        if(_counterBuzzer05Hz==0){
            controlBits.buzzer05Hz = false;
        }
        _counterBuzzer05Hz --;
    }
    if(_counterBuzzer2Hz >=0 ){
        if(_counterBuzzer2Hz==0){
            controlBits.buzzer2Hz = false;
        }
        _counterBuzzer2Hz --;
    }
    if(_counterBuzzerContinuous >=0 ){
        if(_counterBuzzerContinuous==0){
            controlBits.buzzer2Hz = false;
        }
        _counterBuzzerContinuous --;
    }

    //处理输出
    if(controlBits.buzzer05Hz){
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
}


void buzzerGovernor::silence(void){
    controlBits.buzzer1Hz=false;
    controlBits.buzzer2Hz=false;
    controlBits.buzzer05Hz=false;
    controlBits.buzzerContinuous=false;
    _counterBuzzer1Hz = -1;
    _counterBuzzer2Hz = -1;
    _counterBuzzer05Hz = -1;
    _counterBuzzerContinuous = -1;
}

void buzzerGovernor::set1Hz(long during){
    controlBits.buzzer1Hz=true;
    _counterBuzzer1Hz = during *2;
}
void buzzerGovernor::reset1Hz(void){
    controlBits.buzzer1Hz=false;
    _counterBuzzer1Hz = -1;
}

void buzzerGovernor::set05Hz(long during){
    controlBits.buzzer05Hz=true;
    _counterBuzzer05Hz = during *2;
}
void buzzerGovernor::reset05Hz(void){
    controlBits.buzzer05Hz=false;
    _counterBuzzer05Hz = -1;
}

void buzzerGovernor::set2Hz(long during){
    controlBits.buzzer2Hz=true;
    _counterBuzzer2Hz = during *2;
}
void buzzerGovernor::reset2Hz(void){
    controlBits.buzzer2Hz=false;
    _counterBuzzer2Hz = -1;
}

void buzzerGovernor::setContinurous(long during){
    controlBits.buzzerContinuous=true;
    _counterBuzzerContinuous = during *2;
}
void buzzerGovernor::resetContinurous(void){
    controlBits.buzzerContinuous=false;
    _counterBuzzerContinuous = -1;
}
