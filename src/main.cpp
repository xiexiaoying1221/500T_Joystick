#define WIN32_LEAN_AND_MEAN
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QApplication>

#include "mainwindow.h"
#include "modbusdataprocess.h"


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    InitData();

    MainWindow * mw= new MainWindow;
    mw->move(0,0);
    mw->show();
    Sleep(3000);

    ModbusDataProcess mdata;

    Sleep(2 * 1000);


    return app.exec();
}
