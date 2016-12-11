#ifndef HEADWIDGET_H
#define HEADWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QPoint>
#include "math.h"
#include "globalSettings.h"
#include "dataCommit.h"
#include "characterconversion.h"

class HeadWidget: public QWidget{
    Q_OBJECT
public:
    HeadWidget(QWidget *parent=0, QRect headRect= QRect(0,0,0,0));

    void refreshData();
    void changeDNMode();

protected:
    void paintEvent(QPaintEvent *);

protected slots:

private:
   float preHeading;

};
#endif // HEADWIDGET_H
