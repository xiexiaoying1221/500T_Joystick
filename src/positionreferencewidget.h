#ifndef POSITIONREFERENCEWIDGET_H
#define POSITIONREFERENCEWIDGET_H

#include <QWidget>
#include <QPainter>
#include "globalSettings.h"
#include "dataCommit.h"

namespace Ui {
    class PositionReferenceWidget;
}

class PositionReferenceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PositionReferenceWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~PositionReferenceWidget();

    void changeDNMode();
    void refreshData();
    void Refresh_changless_words();

public slots:
    void test();

protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::PositionReferenceWidget *ui;
};

#endif // POSITIONREFERENCEWIDGET_H
