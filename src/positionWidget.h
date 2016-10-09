#ifndef POSITIONWIDGET_H
#define POSITIONWIDGET_H
#include <QDebug>
#include <qwidget.h>
#include <qpainter.h>
#include <math.h>
#include "globalSettings.h"
#include "characterconversion.h"

class PositionWidget : public QWidget{
    Q_OBJECT

public :
    PositionWidget(QWidget *parent=0, QRect titleRect= QRect(0,0,0,0));

    void refreshData();
    void changeDNMode();

protected:
    void paintEvent(QPaintEvent *);
    QPoint getPoint(float a,int interval);

private:
    //上一次位置
    float pre_posNorth;
    float pre_posEast;
    float pre_pos;

    float pre_cmdFx;
    float pre_cmdFy;
};

#endif // POSITIONWIDGET_H
