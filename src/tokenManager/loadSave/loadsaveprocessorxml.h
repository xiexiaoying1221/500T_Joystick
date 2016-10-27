#ifndef LOADSAVEPROCESSORXML_H
#define LOADSAVEPROCESSORXML_H

#include <QDebug>
#include <QList>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QCoreApplication>
#include <QDir>
#include <QtXmlPatterns>
#include <QFileInfo>
#include "iloadsaveprocessor.h"
#include "common/basedevice.h"
#include "QAes/qaeswrap.h"

#define ENCRYPT

class loadSaveProcessorXml :  public baseDevice, public iLoadSaveProcessor
{
    Q_OBJECT
public:
    loadSaveProcessorXml(QObject *parent = 0, bool encrypt = false);
    ~loadSaveProcessorXml();

    Q_PROPERTY(QString resXmlFilePath READ getResXmlFilePath WRITE setResXmlFilePath NOTIFY resXmlFilePathChanged)

    enum state: quint64{
        stateNotReady        = 0x0000000000000001ULL,      //Save&Load处理器未就绪
        stateReady           = 0x0000000000000002ULL,      //Save&Load处理器就绪
        stateOccupied        = 0x0000000000000004ULL,      //Save&Load处理器占用中
        stateReadFile        = 0x0000000000000008ULL,      //Save&Load处理器正在读文件
        stateWriteFile       = 0x0000000000000010ULL,      //Save&Load处理器正在写文件
    };
    virtual QString getStateString(int lang = 0 ) const{
        if( lang == langEN){
            switch(getState()){
            case stateNotReady:
                return QString("Save&Load processor not ready!");
            case stateReady:
                return QString("Save&Load processor ready!");
            case stateOccupied:
                return QString("Save&Load processor occupied");
            case stateReadFile:
                return QString("Save&Load processor reading");
            case stateWriteFile:
                return QString("Save&Load processor writing");
            default:
                return QString("error code not found");
            }
        }
        else{
            switch(getState()){
            case stateNotReady:
                return QString("Save&Load处理器未就绪");
            case stateReady:
                return QString("Save&Load处理器就绪");
            case stateOccupied:
                return QString("Save&Load处理器占用中");
            case stateReadFile:
                return QString("Save&Load处理器正在读文件");
            case stateWriteFile:
                return QString("Save&Load处理器正在写文件");
            default:
                return QString("找不到错误代码");
            }
        }
     };
    enum errorType : quint64 {
        errorFlieFomatWrong              = 0x0000000000000001ULL,       //xml文件格式错误
        errorFileNotFound                = 0x0000000000000002ULL,       //xml文件找不到，新建
        errorFileOpenFail                = 0x0000000000000004ULL,       //xml文件打开失败
        errorFileWriteFail               = 0x0000000000000008ULL,       //xml文件写入失败
        errorLoadFail                    = 0x0000000000000010ULL,       //读取时遇到错误
        errorSaveFail                    = 0x0000000000000020ULL,       //保存时遇到错误
        errorFileNameError               = 0x0000000000000040ULL,       //xml文件名称错误
    };
protected:
    virtual QString getErrorString(quint64 errorCode, int lang =0 ) const{
        if( lang == langEN){
            switch(errorCode){
                case errorFlieFomatWrong:
                    return QString("xml format error");
                case errorFileNotFound:
                    return QString("file not found, new");
                case errorFileOpenFail:
                    return QString("file open fail");
                case errorFileWriteFail:
                    return QString("file write fail");
                case errorLoadFail:
                    return QString("error during reading");
                case errorSaveFail:
                    return QString("error during writing");
                case errorFileNameError:
                    return QString("file name error");
                default:
                    return QString("error code not found");
            }
        }
        else{
            switch(errorCode){
                case errorFlieFomatWrong:
                    return QString("xml文件格式错误");
                case errorFileNotFound:
                    return QString("xml文件找不到，新建");
                case errorFileOpenFail:
                    return QString("xml文件打开失败");
                case errorFileWriteFail:
                    return QString("xml文件写入失败");
                case errorLoadFail:
                    return QString("读取时遇到错误");
                case errorSaveFail:
                    return QString("保存时遇到错误");
                case errorFileNameError:
                    return QString("xml文件名称错误");
                default:
                    return QString("找不到错误代码");
            }
        }
    }

public:

    virtual int loadParameters(QString & paraName, QString *paraValue);
    virtual int saveParameters(QString & paraName, QString & paraValue);
    virtual int moveToInstance(QString & ObjType, QString & index);
    virtual int createNewInstance(QString & ObjType, QString & InstID);
    virtual int moveBackToParent();

    void    setResXmlFilePath(const QString &name);
    QString getResXmlFilePath(void);

    //不实现iLoadSave
    virtual int load(iLoadSaveProcessor *processor){return 0;}
    virtual int save(iLoadSaveProcessor *processor){return 0;}

    virtual int transactionStart();
    virtual int transactionEnd();
    virtual int loadFile(QString fileName = NULL);
    virtual int saveFile(QString fileName = NULL);

    bool needEncrypt;
    QString password;
    QString salt;

private:
    QAesWrap* aes;
    QString resXmlFilePath;//for QML
    QString resXmlFilePathWithoutProtocol;//for C++
    QDomDocument resXml;//DomDoc
    QList<QDomElement> domElementParentList;//element父目录清单

    int initXmlFile();
    int readXmlFile();
    int writeXmlFile();

    int getElement(QDomElement& res, QString tagName, QString id = QString::null);
    int setElement(QDomElement& res, QString tagName, QString id = QString::null);

    inline QDomElement getParent(){
        if (domElementParentList.size() ==0 )
            return resXml.childNodes().at(0).toElement();
        return domElementParentList.last();
    }
    inline int popParent(){
        if (domElementParentList.size() ==1 )
            return -1;
        domElementParentList.removeLast();
        return 0;
    }
    inline int pushParent(QDomElement newone){
        domElementParentList.append(newone);
        return 0;
    }


signals:
    void resXmlRefresh   (void);
    void resXmlFilePathChanged (void);

};

#endif // loadSaveProcessorXml_H
