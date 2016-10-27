#ifndef ILOADSAVEPROCESSOR
#define ILOADSAVEPROCESSOR

#include <QObject>
#include <QDebug>

class iLoadSaveProcessor
{
public:
    iLoadSaveProcessor(){}

    //读写实例内的参数
    //参数1：读：传入参数的名称 写：传入参数的名称
    //参数2：读：返回参数值   写：传入参数值
    virtual int loadParameters(QString & paraName, QString * paraValue) = 0;
    virtual int saveParameters(QString & paraName, QString & paraValue) = 0;

    //子实例读取流程：a、移动到实例（MoveToInstance） b、读取参数（loadParameters） c、返回父实例（MoveBackToParent）
    //子实例写入流程：a、创建新实例（CreateNewInstance）b、移动到实例（MoveToInstance） c、写入参数（saveParameters） d、返回父实例（MoveBackToParent）
    //参数1：ObjType 一般为类的名字
    //参数2：InstID实例标识符，一般为实例的序号
    virtual int moveToInstance(QString & ObjType, QString & InstID) =0;
    virtual int createNewInstance(QString & ObjType, QString & InstID) =0;
    virtual int moveBackToParent() =0;

    //实施保存工作流程：a、启动事务(transactionStart) b、顶层实例顺序调用每个子实例的保存函数 c、子实例顺序调更下级的子实例保存函数 d、所有保存完毕后，顶层实例调用保存文件（saveFile） e、结束事务（transactionEnd）
    //实施读取工作流程：a、启动事务(transactionStart) b、顶层实例调用读取文件（loadFile），可以是默认文件，也可以指定文件 c、顶层实例顺序调用每个子实例的读取函数 d、子实例顺序调更下级的子实例读取函数  e、结束事务（transactionEnd）
    virtual int transactionStart() =0;
    virtual int transactionEnd() =0;
    virtual int loadFile(QString fileName = NULL) =0;
    virtual int saveFile(QString fileName = NULL) =0;

};



#endif // ILOADSAVEPROCESSOR

