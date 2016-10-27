/**************************************************************************************************
 * standard interface
 * state & message
 * 对象状态及其消息的标准接口
 *
 * state,是许多独立的状态值
 *
 * setState 子类程序实现，调用该方法改变状态
 *
 * getStateString 子类程序实现，用于返回状态描述。
 *
 * getState 子类程序实现，用于返回状态。

 **************************************************************************************************/
#ifndef ISTATEMSG_H
#define ISTATEMSG_H

#include <QObject>

class iStateMsg
{
public:
    explicit iStateMsg(){}
    virtual QString getStateString(int lang=0) const = 0;
    virtual inline quint64 getState() const = 0;

    virtual inline void setState(quint64 newState) = 0;

private:
};

#endif // ISTATEMSG_H
