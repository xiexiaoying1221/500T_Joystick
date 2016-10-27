/**************************************************************************************************
 * standard interface
 * load & save
 * 状态保存&读取的标准接口
 *
 **************************************************************************************************/
#ifndef ILOADSAVE_H
#define ILOADSAVE_H

#include <QObject>
#include "iLoadSaveProcessor.h"

class iLoadSave
{
public:
    explicit iLoadSave(){}
    //每个对象都要实现的存取接口
    //参数1：读写本实例所对应的读写处理器。
    virtual int save(iLoadSaveProcessor* processor)=0;
    virtual int load(iLoadSaveProcessor* processor)=0;
};

#endif // ILOADSAVE_H
