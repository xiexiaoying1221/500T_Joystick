#define WIN32_LEAN_AND_MEAN
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QApplication>


#include "modbusdataprocess.h"
#include "dataCommit.h"
#include "mainwindow.h"
#include "globalSettings.h"
#include "softwareoperationwidget.h"
#include "positionreferencewidget.h"
#include "powerconsumptionwidget.h"
#include "generalsettingwidget.h"
#include "sensorenablewidget.h"
#include "propellerenablewidget.h"
#include "limitsetwidget.h"
#include "autoruddersettingwidget.h"
#include "deviceviewwidget.h"
#include "systemsettingwidget.h"
#include "softwareoperationwidget.h"
#include "alarmlistwidget.h"
#include "headingsetpwidget.h"
#include "adjustingbrightnesswidget.h"
#include "mainViewWidget.h"


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
