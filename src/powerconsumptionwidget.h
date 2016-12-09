#ifndef POWERCONSUMPTIONWIDGET_H
#define POWERCONSUMPTIONWIDGET_H

#include <QWidget>
#include <QPainter>
#include "globalSettings.h"
#include "dataCommit.h"

namespace Ui {
    class PowerConsumptionWidget;
}

class PowerConsumptionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PowerConsumptionWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    void paintEvent(QPaintEvent *);
    ~PowerConsumptionWidget();

    void changeDNMode();
    void refreshData();
    void Refresh_changless_words();

private:
    Ui::PowerConsumptionWidget *ui;
};

#endif // POWERCONSUMPTIONWIDGET_H
