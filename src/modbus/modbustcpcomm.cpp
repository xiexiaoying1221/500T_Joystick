#include "modbustcpcomm.h"


ModbusTCPComm::ModbusTCPComm(){
   //ip = QHostAddress(QString("127.0.0.1"));
   ip = QHostAddress(QString("192.168.55.230"));
   myConnection = modbus_new_tcp(ip.toString().toLatin1().data(), MODBUS_TCP_DEFAULT_PORT);

   rollInterval = 500;
   readBuffer = (uint16_t*)malloc(sizeof(uint16_t) * RDBFF_LEN);
   memset(readBuffer, 0, sizeof(uint16_t) * RDBFF_LEN);
   writeBuffer = (uint16_t*)malloc(sizeof(uint16_t) * WRBFF_LEN);
   memset(writeBuffer, 0, sizeof(uint16_t) * WRBFF_LEN);
   connectOK = false;
   errCount = 0;

}


ModbusTCPComm::~ModbusTCPComm(){

    modbus_free (myConnection);
    delete myConnection;
    free(readBuffer);
    free(writeBuffer);
}


void ModbusTCPComm::startRoll(){


    timer = new QTimer();
    timer->start(rollInterval);
    connect(timer,SIGNAL( timeout() ),this,SLOT( refreshData() ));

    qDebug()<<"startRoll";

}

void ModbusTCPComm::refreshData(){

    if(connectOK == false){
        if (modbus_connect (myConnection) != 0){
                qDebug()<<"modbus connection error!";
            return;
        }
        modbus_set_slave(myConnection,1);
        modbus_flush (myConnection);
        connectOK = true;
    }

    int res;
    res=modbus_read_input_registers(myConnection, RDBFF_START_ADD, RDBFF_LEN, readBuffer);
    //qDebug()<<res;
    if(res <= 0){
        errCount++;
    }
    else {
        errCount = 0;
    }
    res=modbus_write_registers(myConnection, WRBFF_START_ADD, WRBFF_LEN, writeBuffer);
    //qDebug()<<res;
    if(res <= 0){
        errCount++;
    }
    else {
        errCount = 0;
    }
    if(errCount >= 10){
        qDebug()<<"modbus connection turn bad...";
    }
    if(errCount >= 50){
        qDebug()<<"modbus connection restart...";
        connectOK = false;
        errCount = 11;
    }

//    customer();
//    seastel 支持的功能码对应的函数原型如下：
//    int modbus_read_registers(modbus_t *ctx, int addr, int nb, uint16_t *dest);       //FC3
//    int modbus_read_input_registers(modbus_t *ctx, int addr, int nb, uint16_t *dest); //FC4
//    int modbus_write_register(modbus_t *ctx, int reg_addr, int value);                //FC6
//    int modbus_write_registers(modbus_t *ctx, int addr, int nb, const uint16_t *data);//FC16


}

int ModbusTCPComm::readBool_buff(bool* value, qint16 add, qint16 offset){
    int buff_add = add - RDBFF_START_ADD;
    if ( buff_add > RDBFF_LEN || buff_add < 0)  return -1;
    if ( offset > 15 || offset <0 ) return -1;
    //qDebug()<<"inside"<<*(readBuffer + 2);
    quint16 ctx = *(readBuffer + buff_add);
    quint16 i = 0x0001 << offset;
    //qDebug()<<buff_add<<ctx<<i;
    if( ctx & i) *value =true;
    else *value = false;

    return 0;
}
int ModbusTCPComm::readUint32_buff(quint32 *value, qint16 add){
    int buff_add = add - RDBFF_START_ADD;
    if ( buff_add > RDBFF_LEN || buff_add < 0)  return -1;
    *value = (*(readBuffer + buff_add) << 16) +  *(readBuffer + buff_add + 1 );
    //qDebug()<<*(readBuffer + buff_add)<<*(readBuffer + buff_add + 1 )<<*value;
    return 0;
}

int ModbusTCPComm::readFloat_buff(float *value, qint16 add){
    int buff_add = add - RDBFF_START_ADD;
    if ( buff_add > RDBFF_LEN || buff_add < 0)  return -1;
    //qDebug()<<"ModbusTCPComm::readFloat_buff"<<*(readBuffer + buff_add)<<*(readBuffer + buff_add + 1 );
    quint32 temp;
    //qDebug()<<"ModbusTCPComm::readFloat_buff"<<buff_add;
    temp =  *(quint32*)(readBuffer + buff_add) << 16  | *(readBuffer + buff_add + 1 );
    *value = *((float*)&temp);
    return 0;
}

int ModbusTCPComm::writeBool_buff(bool value, qint16 add, qint16 offset){
    int buff_add = add - WRBFF_START_ADD;
    if ( buff_add > WRBFF_LEN || buff_add < 0)  return -1;
    if ( offset > 15 || offset <0 ) return -1;

    quint32 i= 0x0001<<offset;
    if (value){
        *(writeBuffer +buff_add) |= i;
    }
    else {
        i =  ~i;
        *(writeBuffer +buff_add) &= i;
    }
    return 0;
}

int ModbusTCPComm::writeUint32_buff(quint32 value, qint16 add){
    int buff_add = add - WRBFF_START_ADD;
    if ( buff_add > WRBFF_LEN || buff_add < 0)  return -1;

    *(writeBuffer +buff_add) = value >>16;
    *(writeBuffer +buff_add +1 ) = value & 0xFFFF;
    return 0;
}

int ModbusTCPComm::writeFloat_buff(float value, qint16 add){

    quint32 temp;
    temp = *((quint32*)&value);
    //qDebug()<<value<<temp;
    writeUint32_buff(temp,add);

    return 0;

//    int buff_add = add - WRBFF_START_ADD;
//    if ( buff_add > WRBFF_LEN || buff_add < 0)  return -1;
//    quint8* value_temp = (quint8*)&value;
//    qDebug()<<value<<*value_temp<<*(value_temp + 1 )<<*(value_temp + 2 )<<*(value_temp + 3 );
//    *(writeBuffer +buff_add+0)= ((quint16)*(value_temp + 3 ))<<8 | *(value_temp + 2 );
//    *(writeBuffer +buff_add+1)= ((quint16)*(value_temp + 1 ))<<8 | *(value_temp + 0 );
//    qDebug()<<*(writeBuffer +buff_add)<<*(writeBuffer +buff_add+1);
//    return 0;
}

void ModbusTCPComm::customer(){
    #ifdef DEBUG
    bool testBool;
    readBool_buff(&testBool, 8192, 0);
    quint32 testUint32;
    readUint32_buff(&testUint32, 8208);
    //float testFloat;
    //readFloat_buff(&testFloat,8216);
    //qDebug()<<"modbus test Uint32 at 8208:"<<testUint32;
    //qDebug()<<"modbus test Bool at 8192.0:"<<testBool;
    //qDebug()<<"modbus data:"<<testBool<<testUint32<<testFloat;
    #endif
}
