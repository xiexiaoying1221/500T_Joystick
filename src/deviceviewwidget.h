#ifndef DEVICEVIEWWIDGET_H
#define DEVICEVIEWWIDGET_H

#include <QWidget>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include "globalSettings.h"
#include "AlarmHandle.h"

namespace Ui {
    class DeviceViewWidget;
}

class DeviceViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceViewWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~DeviceViewWidget();

    void Refresh_changless_words();
    void changeDNMode();

private:
    Ui::DeviceViewWidget *ui;

    QString start_time;
};

#endif // DEVICEVIEWWIDGET_H
