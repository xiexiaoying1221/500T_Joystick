#ifndef MainViewWidget_H
#define MainViewWidget_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QFrame>
#include <QTimer>
#include <QSpinBox>
#include <QPixmap>
#include <QDebug>

#include "math.h"
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
