#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <qwidget.h>
#include <qpushbutton.h>
#include <qpainter.h>
#include <qframe.h>
#include <qtimer.h>
#include <qspinbox.h>
#include <qdatetime.h>
#include <qlabel.h>

#include <globalSettings.h>

class TitleWidget: public QWidget{
    Q_OBJECT
public:
    //TitleWidget(QWidget *parent = 0);
    TitleWidget(QWidget *parent=0, QRect titleRect= QRect(0,0,0,0));
    ~TitleWidget();
    void refreshData();
    void Refresh_changlese_words();
protected:
    void paintEvent(QPaintEvent *);
    QLabel *label2 ;

};
#endif // TITLEWIDGET_H
