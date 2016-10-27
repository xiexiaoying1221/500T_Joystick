#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "loadSaveProcessorXml.h"

/*
 * 构造函数
 * 输入参数：父QObject
 * 返回数值：无
 * 功能描述：
 * 1、进入Initialization状态，初始化内部变量
 * 2、读取本地xml文件
 * 3、如果读取正确，进入Ready状态
 */
loadSaveProcessorXml::loadSaveProcessorXml(QObject *parent, bool encrypt):baseDevice(parent)
{
    password = QString("fusion");
    salt = QString("fusion");
    aes = new QAesWrap(password.toUtf8(), salt.toUtf8(), QAesWrap::AES_256);
    needEncrypt = encrypt;

    setState( stateReady );
    setResXmlFilePath( QString(QCoreApplication::applicationDirPath() + "/configuration.xml"));
    readXmlFile();
}

/*
 * 析构函数
 * 输入参数：无
 * 返回数值：无
 * 功能描述：
 */
loadSaveProcessorXml::~loadSaveProcessorXml(){

}

/*
 * 读实例内的参数
 * 输入参数：
 * 1、传入参数的名称
 * 2、返回参数值
 * 返回数值：
 * 1、成功0，状态错误-1，找不到参数-2
 * 功能描述：
 * 1、子实例读取流程：a、移动到实例（MoveToInstance） b、读取参数（loadParameters） c、返回父实例（MoveBackToParent）
 * 2、读取当前parent位置下的指定paraName的paraValue
 * 3、找不到的话paraValue = -1，返回-2
 */
int loadSaveProcessorXml::loadParameters(QString & paraName, QString * paraValue){
    if(getState() != stateOccupied ){
        *paraValue = QString::null;
        return -1;
    }
    QDomElement temp;
    int ret = getElement(temp,paraName);//* 返回数值： 成功0，输入参数错误-1，找不到-2
    if( ret == 0 ){
        if( !temp.childNodes().isEmpty() ){
            *paraValue = temp.childNodes().at(0).toText().nodeValue();
            return 0;//找到了，且有文本
        }
    }
    *paraValue = QString::null;
    return -2;//找不到
}

/*
 * 写实例内的参数
 * 输入参数：
 * 1、传入参数的名称
 * 2、传入参数值
 * 返回数值：
 * 1、成功0，状态错误-1
 * 功能描述：
 * 1、子实例写入流程：a、创建新实例（CreateNewInstance） b、写入参数（saveParameters） c、返回父实例（MoveBackToParent）
 * 2、把的paraName和paraValue保存到当前parent位置下
 * 3、若参数存在，则覆盖。若不存在，则新建
 */
int loadSaveProcessorXml::saveParameters(QString &paraName, QString &paraValue){
    if(getState() != stateOccupied ){
        return -1;
    }
    QDomElement temp;
    int ret = getElement(temp,paraName);//* 返回数值： 成功0，输入参数错误-1，找不到-2
    //qDebug()<<"loadSaveProcessorXml::saveParameters"<<ret;
    //qDebug()<<"loadSaveProcessorXml::saveParameters"<<domElementParentList.size();
    if( ret == 0 ){
        if( !temp.childNodes().isEmpty() ){
            temp.childNodes().at(0).toText().setNodeValue( paraValue );
            return 0;//找到了
        }
        QDomText newOne = resXml.createTextNode( paraValue );
        temp.appendChild( newOne );
        return 0;
    }
    else if(ret == -2){
        QDomElement newElement  = resXml.createElement( paraName );
        QDomText    newOne      = resXml.createTextNode( paraValue );
        newElement.appendChild( newOne );
        getParent().appendChild( newElement );
        return 0;
    }
    else return -1;
}

/*
 * 移动到实例
 * 输入参数：
 * 1、ObjType 一般为类的名字
 * 2、Index 实例的序号，从0开始
 * 返回数值：
 * 1、成功0，状态错误-1，找不到对象-2
 * 功能描述：
 * 1、子实例读取流程：a、移动到实例（MoveToInstance） b、读取参数（loadParameters） c、返回父实例（MoveBackToParent）
 */
int loadSaveProcessorXml::moveToInstance(QString &ObjType, QString &index){
    if(getState() != stateOccupied ){
        return -1;
    }
    QDomNodeList newList = getParent().elementsByTagName(ObjType);
    if(newList.isEmpty()){
        return -2;
    }
    if(index.isNull()){
        pushParent(newList.at(0).toElement());
    }
    for(int i=0; i<newList.size(); i++){
        QDomElement newone = newList.at(i).toElement();
        if( newone.attribute("id") == index){
            pushParent(newone);
            return 0;
        }
    }
    return -2;
}
/*
 * 创建新实例
 * 输入参数：
 * 1、ObjType 一般为类的名字
 * 2、InstID实例标识符，一般为实例的名称
 * 返回数值：
 * 1、成功0，状态错误-1，数据错误-2
 * 功能描述：
 * 1、子实例写入流程：a、创建新实例（CreateNewInstance）b、移动到实例（MoveToInstance） c、写入参数（saveParameters） d、返回父实例（MoveBackToParent）
 */
int loadSaveProcessorXml::createNewInstance(QString &ObjType, QString &InstID){
    if(getState() != stateOccupied ){
        return -1;
    }
    QDomElement newone;
    if( setElement(newone, ObjType, InstID) >= 0){//成功0，已存在1，输入参数错误-1，
        return -2;
    }
    return 0;
}

/*
 * 移动到父实例
 * 输入参数：无
 * 返回数值：
 * 1、成功0，状态错误-1
 * 功能描述：
 * 1、子实例读取流程：a、移动到实例（MoveToInstance） b、读取参数（loadParameters） c、返回父实例（MoveBackToParent）
 * 2、子实例写入流程：a、创建新实例（CreateNewInstance）b、移动到实例（MoveToInstance） c、写入参数（saveParameters） d、返回父实例（MoveBackToParent）
 */
int loadSaveProcessorXml::moveBackToParent(){
    if(getState() != stateOccupied ){
        return -1;
    }
    popParent();
    return 0;
}

/*
 * 初始化xml文件
 * 输入参数：无
 * 返回数值：
 * 1、成功0，失败-1
 * 功能描述：
 * 1、初始化一个空的xml，并且写入基本信息
 * 2、写入文件
 * 3、发送文件更新信号
 */
int loadSaveProcessorXml::initXmlFile(){

    quint64 lastState = getState();
    setState( stateWriteFile );//进入指定写入文件模式

    resXml.clear();

    QString strHeader( "version=\"1.0\" encoding=\"UTF-8\"" );
    resXml.appendChild( resXml.createProcessingInstruction("xml", strHeader) );

    QDomElement rootElement = resXml.createElement( "config" );
    rootElement.setAttribute( "id", "test v1.0" );
    resXml.appendChild( rootElement );

    int ret = writeXmlFile();
    setState( lastState );//进入上个模式

    emit resXmlRefresh();

    return ret;

}
/*
 * 读取xml文件
 * 输入参数：无
 * 返回数值：
 * 1、成功0，失败-1，内容错误-2
 * 功能描述：
 * 1、判断文件是已存在且正确，否则失败。
 * 2、读取文件到DOM对象
 * 3、读取时进入ReadFile模式，发生错误后返回到NotReady模式，读取成功后进入原有模式
 */
int loadSaveProcessorXml::readXmlFile(){

    quint64 lastState = getState();
    setState( stateReadFile );//进入读取文件模式
    //qDebug()<<"loadSaveProcessorXml::readXmlFile"<<lastState;

    QFile file(resXmlFilePathWithoutProtocol);
    if( !file.exists()) {
        setError( errorFileNotFound );
        if (initXmlFile() != 0){
            setError( errorFileOpenFail );
            //qDebug()<<"loadSaveProcessorXml::readXmlFile"<<"errorFileOpenFail";
            setState( stateNotReady );//进入停止模式
            return -1;
        }
    }
    if(!file.open(QIODevice::ReadOnly)){
        //qDebug()<<"loadSaveProcessorXml::readXmlFile"<<"xml file open failed!\n"<<file.errorString();
        setError( errorFileOpenFail );
        file.close();
        setState( stateNotReady );//进入停止模式
        return -1;
    }

    QDataStream data(&file);
    char* buffer = (char*)malloc(file.size() * sizeof(char) );
    data.readRawData(buffer, file.size() );
    QByteArray orientalBytes = QByteArray(buffer, file.size() );
    delete buffer;
    file.close();

    bool ok;
#ifdef ENCRYPT
    QByteArray decrypedBytes = aes->decrypt(orientalBytes,QAesWrap::AES_ECB);
    qDebug()<<"loadSaveProcessorXml::readXmlFile"<<orientalBytes<<"||"<<decrypedBytes;
    qDebug()<<orientalBytes.length()<<decrypedBytes.length();
    ok = resXml.setContent(decrypedBytes);
#else
    ok = resXml.setContent(orientalBytes);
#endif

    if(!ok){
        setError( errorFlieFomatWrong );
        file.close();
        setState( stateNotReady );//进入停止模式
        return -2;
    }

    //qDebug()<<"loadSaveProcessorXml::readXmlFile"<<resXml.firstChildElement().nodeName();
    domElementParentList.clear();
    domElementParentList.append( resXml.firstChildElement() );
    //qDebug()<<domElementParentList.at(0).toElement().nodeName();
    emit resXmlRefresh();
    setState( lastState );//进入上个模式
    return 0;
}

/*
 * 写入xml文件
 * 输入参数：无
 * 返回数值：
 * 1、成功0，写入错误-1
 * 功能描述：
 * 1、把DOM对象写入文件
 * 2、发送文件更新信号
 * 3、读取时进入WriteFile模式，发生错误后返回到NotReady模式，读取成功后进入原有模式
 */
int loadSaveProcessorXml::writeXmlFile(){
    quint64 lastState = getState();
    setState( stateWriteFile );//进入写文件模式

    QFile file(resXmlFilePathWithoutProtocol);
    if( !file.open(QIODevice::WriteOnly) )
    {
        setError( errorFileWriteFail );
        //qDebug()<<"xml file write error!";
        setState( stateNotReady );//进入停止模式
        return -1;
    }

    QByteArray orientalBytes;
    QTextStream out( &orientalBytes );
    out.setCodec("UTF-8");
    resXml.save(out,4,QDomNode::EncodingFromTextStream);//4是子项目缩进长度

#ifdef ENCRYPT
        QByteArray encrypedBytes = aes->encrypt(orientalBytes,QAesWrap::AES_ECB);
        qDebug()<<"loadSaveProcessorXml::writeXmlFile"<<orientalBytes<<"||"<<encrypedBytes<<orientalBytes.size()<<encrypedBytes.size();
        qDebug()<<aes->decrypt(encrypedBytes, QAesWrap::AES_ECB);
        file.write( encrypedBytes, encrypedBytes.length());
#else
        file.write( orientalBytes.data(), orientalBytes.length());
#endif


    file.close();

    emit resXmlRefresh();
    setState( lastState );//进入上个模式

    return 0;
}

/*
 * 搜索xml元素
 * 输入参数：
 * 1、QDomElement 返回该xml元素的指针，找不到返回getParent()
 * 2、QString 被搜索元素的tagName
 * 3、QString 被搜索元素的id，可以不指定
 * 返回数值：
 * 1、成功0，输入参数错误-1，找不到-2
 * 功能描述：
 */
int loadSaveProcessorXml::getElement(QDomElement& res, QString tagName, QString id){
    if (domElementParentList.size() ==0 || resXml.isNull() ){
        res = getParent();
        return -1;
    }
    QDomNodeList selection = getParent().elementsByTagName(tagName);
    if(!selection.isEmpty()){
        if(id.isNull() ){
            res = selection.at(0).toElement();
            return 0;
        }
        for(int i=0; i<selection.count(); i++){
            res = selection.at(i).toElement();
            if(id == res.attribute("id")){
                return 0;
            }
        }
    }
    res = getParent();
    return -2;
}

/*
 * 新增xml元素
 * 输入参数：
 * 1、QDomElement 返回该xml元素的指针，
 * 2、QString 新元素的tagName
 * 3、QString 新元素的id，可以不指定
 * 返回数值：
 * 1、成功0，已存在1，输入参数错误-1，
 * 功能描述：
 * 1、在搜索范围内搜索
 * 2、若该元素存在，则直接返回
 * 3、若该元素不存在，则新建一个返回
 * 4、元素id可以不指定，此时返回tagName相同的第一个元素
 */
int loadSaveProcessorXml::setElement(QDomElement& res, QString tagName, QString id){
    if (domElementParentList.size() == 0 || resXml.isNull() ){
        res = getParent();
        return -1;
    }
    QDomNodeList selection = getParent().elementsByTagName(tagName);
    if( !selection.isEmpty() ){
        if( id.isNull() ){
            res = selection.at(0).toElement();
            return 0;
        }
        for(int i=0; i<selection.count(); i++){
            if( id == selection.at(i).toElement().attribute("id") ){
                res = selection.at(i).toElement();
                return 1;//已存在，不新建
            }
        }
    }
    res = resXml.createElement( tagName );
    if( !id.isNull() ){
        res.setAttribute( "id", id );
    }
    getParent().appendChild( res );//追加新建
    return 0;
}
/*
 * 设置文件路径
 * 输入参数：QString &name
 * 返回数值：无
 * 功能描述：
 * 1、写入无协议xml文件路径
 * 2、写入有协议xml文件路径，for QML
 * 3、每次写入都会检测文件名称
 */
void loadSaveProcessorXml::setResXmlFilePath(const QString &name){
//    QFileInfo test = QFileInfo(name);
//    if( !test.isFile() ){
//        setError( errorFileNameError );
//        return;
//    }
    resXmlFilePathWithoutProtocol = QDir::toNativeSeparators(name);
    resXmlFilePath = QDir::toNativeSeparators( "file:" + name );
    //qDebug()<<resXmlFilePath;
    //qDebug()<<resXmlFilePathWithoutProtocol;
    emit resXmlFilePathChanged();
}

/*
 * 读取文件路径
 * 输入参数：无
 * 返回数值：QString &name
 * 功能描述：
 * 1、返回有协议文件路径，for QML
 */
QString loadSaveProcessorXml::getResXmlFilePath(void){
    return resXmlFilePath;
}
/*
 * 读取xml文件
 * 输入参数：无
 * 返回数值：
 * 1、成功0，失败-1，文件内容错误-21
 * 功能描述：
 * 1、实施保存工作流程：a、启动事务(transactionStart) b、顶层实例顺序调用每个子实例的保存函数 c、子实例顺序调更下级的子实例保存函数 d、所有保存完毕后，顶层实例调用保存文件（saveFile） e、结束事务（transactionEnd）
 * 2、实施读取工作流程：a、启动事务(transactionStart) b、顶层实例调用读取文件（loadFile），可以是默认文件，也可以指定文件 c、顶层实例顺序调用每个子实例的读取函数 d、子实例顺序调更下级的子实例读取函数  e、结束事务（transactionEnd）
 */
int loadSaveProcessorXml::loadFile(QString fileName){
    if(fileName != NULL){
        setResXmlFilePath( fileName );
    }
    int ret = readXmlFile();
    //qDebug()<<ret;
    return ret;
}
/*
 * 保存xml文件
 * 输入参数：无
 * 返回数值：
 * 1、成功0，写入错误-1
 * 功能描述：
 * 1、实施保存工作流程：a、启动事务(transactionStart) b、顶层实例顺序调用每个子实例的保存函数 c、子实例顺序调更下级的子实例保存函数 d、所有保存完毕后，顶层实例调用保存文件（saveFile） e、结束事务（transactionEnd）
 * 2、实施读取工作流程：a、启动事务(transactionStart) b、顶层实例调用读取文件（loadFile），可以是默认文件，也可以指定文件 c、顶层实例顺序调用每个子实例的读取函数 d、子实例顺序调更下级的子实例读取函数  e、结束事务（transactionEnd）
 */
int loadSaveProcessorXml::saveFile(QString fileName){
    if(fileName != NULL){
        setResXmlFilePath( fileName );
    }
    return writeXmlFile();
}
/*
 * 启动事务
 * 输入参数：无
 * 返回数值：
 * 1、成功0，启动失败-1
 * 功能描述：
 * 1、实施保存工作流程：a、启动事务(transactionStart) b、顶层实例顺序调用每个子实例的保存函数 c、子实例顺序调更下级的子实例保存函数 d、所有保存完毕后，顶层实例调用保存文件（saveFile） e、结束事务（transactionEnd）
 * 2、实施读取工作流程：a、启动事务(transactionStart) b、顶层实例调用读取文件（loadFile），可以是默认文件，也可以指定文件 c、顶层实例顺序调用每个子实例的读取函数 d、子实例顺序调更下级的子实例读取函数  e、结束事务（transactionEnd）
 * 3、初始化domElementParentList
 */
int loadSaveProcessorXml::transactionStart(){
    if(getState() != stateReady) return -1;
    setState( stateOccupied );
    domElementParentList.clear();
    domElementParentList.append( resXml.firstChildElement() );
    return 0;
}
/*
 * 结束事务
 * 输入参数：无
 * 返回数值：
 * 1、成功0，结束失败-1
 * 功能描述：
 * 1、实施保存工作流程：a、启动事务(transactionStart) b、顶层实例顺序调用每个子实例的保存函数 c、子实例顺序调更下级的子实例保存函数 d、所有保存完毕后，顶层实例调用保存文件（saveFile） e、结束事务（transactionEnd）
 * 2、实施读取工作流程：a、启动事务(transactionStart) b、顶层实例调用读取文件（loadFile），可以是默认文件，也可以指定文件 c、顶层实例顺序调用每个子实例的读取函数 d、子实例顺序调更下级的子实例读取函数  e、结束事务（transactionEnd）
 */
int loadSaveProcessorXml::transactionEnd(){
    if(getState() != stateOccupied) return -1;
    setState( stateReady );
    return 0;
}
