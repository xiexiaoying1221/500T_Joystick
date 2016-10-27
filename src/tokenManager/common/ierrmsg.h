/**************************************************************************************************
 * standard interface
 * error & message
 * 错误及其消息的标准接口
 *
 * errorState,每一位都是一个错误状态。=0正常，=1错误
 * errorMask,复位屏蔽。=0时不可以外部复位，=1时可以外部复位
 *
 * setError/resetError 产生/复位故障，子类程序发现故障/发现故障消失，调用该方法
 * setErrorMask/getErrorMask 设置/获取复位屏蔽码，子类程序设置故障能否被外部复位
 *
 * reset/resetAll 外部复位故障，外部（如ui中的按钮）复位故障。
 *
 * getErrorString 子类程序实现，用于返回故障描述。
 * getErrorStringList 用于返回所有故障描述。
 **************************************************************************************************/
#ifndef IERRMSG_H
#define IERRMSG_H

#include <QObject>

class iErrMsg
{
public:
    explicit iErrMsg(){}


    //errorState
    virtual QStringList getErrorStringList(int lang=0) const = 0;
    virtual bool getError(quint64 errorCode) const = 0;
    virtual quint64 getError() const = 0;

//    errorMask,对应位=1则不能被外部复位,（必须使用protected:int resetErrorState(quint64 errorCode)复位）
//    默认都可以被外部复位
    virtual quint64 getErrorMask() const = 0;

    virtual void resetAll() = 0;//外部复位，全复位
    virtual void reset(quint64 resetCode) = 0;//外部复位，

    virtual int updateError(quint64 errorCode) = 0;
    virtual int setError(quint64 errorCode) = 0;
    virtual int resetError(quint64 errorCode) = 0;
    virtual int setErrorMask(quint64 errorCode) = 0;
    virtual QString getErrorString(quint64 errorCode, int lang=0) const = 0;
private:


};

#endif // IERRMSG_H
