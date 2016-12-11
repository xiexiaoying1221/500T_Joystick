#ifndef INFOWIDGET_H
#define INFOWIDGET_H
#include <QWidget>
#include <QPainter>

#include "AlarmHandle.h"
#include "globalSettings.h"

class InfoWidget: public QWidget{
    Q_OBJECT
public:
    InfoWidget(QWidget *parent=0, QRect infoRect= QRect(0,0,0,0));
    void refreshData();
protected:
    void paintEvent(QPaintEvent *);
};
#endif // INFOWIDGET_H
