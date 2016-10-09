#ifndef HEADWIDGET_H
#define HEADWIDGET_H

#include <qwidget.h>
#include <qpainter.h>
#include <math.h>
#include <QTimer>
#include <qpoint.h>
#include <globalSettings.h>
#include <dataCommit.h>
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
