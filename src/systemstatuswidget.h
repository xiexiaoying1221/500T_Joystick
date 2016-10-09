#ifndef SYSTEMSTATUSWIDGET_H
#define SYSTEMSTATUSWIDGET_H

#include <QWidget>
#include "globalSettings.h"
#include "dataCommit.h"

namespace Ui {
    class SystemStatusWidget;
}

class SystemStatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemStatusWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~SystemStatusWidget();

    void changeDNMode();
    void refreshData();
    void Refresh_changless_words();

private:
    Ui::SystemStatusWidget *ui;
};

#endif // SYSTEMSTATUSWIDGET_H
