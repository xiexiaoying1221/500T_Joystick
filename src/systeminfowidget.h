#ifndef SYSTEMINFOWIDGET_H
#define SYSTEMINFOWIDGET_H

#include <QWidget>
#include "globalSettings.h"

namespace Ui {
    class SystemInfoWidget;
}

class SystemInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemInfoWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~SystemInfoWidget();

    void changeDNMode();
    void Refresh_changless_words();

private:
    Ui::SystemInfoWidget *ui;
};

#endif // SYSTEMINFOWIDGET_H
