#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "basedevice.h"

baseDevice::baseDevice(QObject *parent):QObject(parent),iErrMsg()
{
    name = "";
    state = 0;
    error = 0;
    errorMask = 0;
    //errorMask,对应位=1则不能被外部复位,（必须使用protected:int resetErrorState(quint64 errorCode)复位）
    //默认都可以被外部复位
}

//State
quint64 baseDevice::getState() const{
    return state;
}

//error
QStringList baseDevice::getErrorStringList(int lang) const{
    QStringList ret;
    quint64 test=1;
    if(getError() == 0){
        if(lang == langEN){
            ret<<"OK";
            return ret;
        }
        else{
            ret<<QString("无错误");
            return ret;
        }
    }
    for(int i=0; i<=63; i++){
       if(test & getError()){
           ret<<getErrorString(test,lang);
       }
       test = test<<1;
    }
    return ret;
}
bool baseDevice::getError(quint64 errorCode) const{
    if(error & errorCode) {
        return true;
    }
    return false;
}
quint64 baseDevice::getError() const{
    return error;
}


//name
QString baseDevice::getName(void) const{
    return name;
}
void baseDevice::setName(QString newName){
    name = newName;
    emit msgNameChanged(name);
    emit msgDeviceChanged(name);
}


//errorMask,对应位=1则不能被外部复位,（必须使用protected:int resetErrorState(quint64 errorCode)复位）
//默认都可以被外部复位
quint64 baseDevice::getErrorMask() const{
    return errorMask;
}

//外部复位，全复位
void baseDevice::resetAll(){
    reset(0xFFFFFFFFFFFFFFFF);
}
//外部复位，
void baseDevice::reset(quint64 resetCode){
    //外部输入 restCode=  0x0000 0010
    //       errorMask=  0x0000 0110
    //实际允许外部复位的 restCode = 0x0000 0000
    resetCode = resetCode & (~errorMask);
    resetError( resetCode);
}
//baseDevice的信息保存
int baseDevice::save(iLoadSaveProcessor* processor){
    processor->saveParameters(QString("name"), name);
    processor->saveParameters(QString("state"),QString::number(state));
    processor->saveParameters(QString("error"),QString::number(error));
    processor->saveParameters(QString("errorMask"),QString::number(errorMask));
    return 0;
}
//baseDevice的信息读取
int baseDevice::load(iLoadSaveProcessor *processor){
    QString value;
    bool ok;
    processor->loadParameters(QString("name"),&value);
    setName(name);
    processor->loadParameters(QString("state"),&value);
    setState( value.toLong(&ok, 10) );
    processor->loadParameters(QString("error"),&value);
    updateError( value.toLong(&ok, 10) );
    processor->loadParameters(QString("errorMask"),&value);
    setErrorMask( value.toLong(&ok, 10) );
    return 0;
}

//State修改
void baseDevice::setState(quint64 newState){
    if(state != newState){
        state = newState;
        emit msgStateChanged(state);
        emit msgDeviceChanged(name);
        //qDebug()<<"newState";
    }
}
//error修改，只增
int baseDevice::setError(quint64 errorCode){
    int qty=0;
    quint64 test = 1;
    for(int i=0;i<=63;i++){
        //errorCode  = 0x0000 0110 初始
        //test       = 0x0000 0010 初始
        //error      = 0x0000 1100 初始
        //~error     = 0x1111 0011 取反
        //新报警 errorCode & test & ~error
        if(errorCode & test & (~error) ){
            //test       = 0x0000 0001 初始
            //error      = 0x0000 1100 初始
            //error      = 0x0000 1101 结果
            //qDebug()<<"baseDevice::setError1#"<<error<<i<<test<<errorCode;
            error = error | test;
            //qDebug()<<"baseDevice::setError2#";
            emit msgErrorSet(test);
            emit msgDeviceChanged(name);
            //qDebug()<<"baseDevice::setError3#";
            qty++;
        }
        test = test<<1;
    }
    return qty;
}

//error修改，可增可减
int baseDevice::updateError(quint64 errorCode){
    int qty=0;
    quint64 test = 1;
    for(int i=0;i<=63;i++){
        //errorCode  = 0x0000 0110 初始
        //test       = 0x0000 0001 初始
        //error      = 0x0000 1100 初始
        //~error     = 0x1111 0011 取反
        //新报警 errorCode & test & ~error
        if(errorCode & test & (~error) ){
            //test       = 0x0000 0001 初始
            //error      = 0x0000 1100 初始
            //error      = 0x0000 1101 结果
            //qDebug()<<"baseDevice::setError1#"<<error<<i<<test<<errorCode;
            error = error | test;
            //qDebug()<<"baseDevice::setError2#";
            emit msgErrorSet(test);
            emit msgDeviceChanged(name);
            //qDebug()<<"baseDevice::setError3#";
            qty++;
        }
        //errorCode  = 0x0000 0110 初始
        //~errorCode = 0x1111 1001 取反
        //test       = 0x0000 1000 初始
        //error      = 0x0000 1100 初始
        //去报警 (~errorCode) & test & error
        if( (~errorCode) & test & error ){
            //test       = 0x0000 1000 初始
            //~test      = 0x1111 0111 取反
            //error      = 0x0000 1100 初始
            //error      = 0x0000 0100 结果
            //qDebug()<<"baseDevice::setError4#"<<error<<i<<test<<errorCode;
            error = error & (~test);
            //qDebug()<<"baseDevice::setError5#";
            emit msgErrorReset(test);
            emit msgDeviceChanged(name);
            //qDebug()<<"baseDevice::setError6#";
            qty++;
        }
        test = test<<1;
    }
    return qty;
}

//error修改，只减
int baseDevice::resetError(quint64 resetCode){
    //resetCode  = 0x0000 0110 初始
    //test       = 0x0000 0001 初始
    //error      = 0x0000 1100 初始
    //发射 resetCode & test & error
    int qty = 0;
    quint64 test = 1;
    for(int i=0;i<=63;i++){
        if( resetCode & error & test ){
        //test       = 0x0000 0100 初始
        //~test      = 0x1111 1011 取反
        //error      = 0x0000 1100 初始
        //error      = 0x0000 1000 结果
            error &= (~test);
            emit msgErrorReset(test);
            emit msgDeviceChanged(name);
            //qDebug()<<"goneError"<<error;
            qty++;
        }
        test = test<<1;
    }
    return qty;
}

//errorMask修改
int baseDevice::setErrorMask(quint64 errorCode){
    errorMask = errorCode;
    return 0;
}
