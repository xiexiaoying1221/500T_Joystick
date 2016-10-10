#ifndef ALARMLISTWIDGET_H
#define ALARMLISTWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include "globalSettings.h"
#include "AlarmHandle.h"

namespace Ui {
    class AlarmListWidget;
}

class AlarmListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmListWidget(QWidget *parent=0,QRect viewAreaRect = QRect(0,0,0,0));
    ~AlarmListWidget();

    void refreshData();
    void changeDNMode();
    void Refresh_changless_words();

private:
    Ui::AlarmListWidget *ui;
    QStandardItemModel *alarm_model;

};

#endif // ALARMLISTWIDGET_H
