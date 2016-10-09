#ifndef MainViewWidget_H
#define MainViewWidget_H

#include <qwidget.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qpainter.h>
#include <qframe.h>
#include <qtimer.h>
#include <qspinbox.h>
#include <math.h>
#include <qpixmap.h>
#include <QDebug>
#include "dataCommit.h"
#include "globalSettings.h"
#include "characterconversion.h"

class MainViewWidget: public QWidget{
    Q_OBJECT
public:
    MainViewWidget(QWidget *parent=0,QRect viewAreaRect = QRect(0,0,0,0));

    void refreshData();
    void changeDNMode();

protected:
    void paintEvent(QPaintEvent *);

private:
    double hypotenuse( double x, double y);
};

#endif // MainViewWidget_H
