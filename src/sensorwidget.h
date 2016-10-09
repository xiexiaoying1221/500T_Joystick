#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include "globalSettings.h"
#include "dataCommit.h"
#include "characterconversion.h"

namespace Ui {
    class SensorWidget;
}

class SensorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SensorWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~SensorWidget();

    void changeDNMode();
    void refreshData();
    void Refresh_changless_words();

private:
    Ui::SensorWidget *ui;

};

#endif // SENSORWIDGET_H
