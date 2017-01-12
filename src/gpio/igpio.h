#ifndef IGPIO_H
#define IGPIO_H


class IGPIO
{
public:
    IGPIO(){}
    virtual ~IGPIO(){}

    virtual void init(void)=0;
    virtual void setIODirection(int pinNum, int direction)=0;
    virtual void writeIO(int pinNum, bool status)=0;
    virtual bool readIO(int pinNum)=0;
    virtual bool isReady(void)=0;
};

#endif // IGPIO_H
