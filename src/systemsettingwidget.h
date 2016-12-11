#ifndef SYSTEMSETTINGWIDGET_H
#define SYSTEMSETTINGWIDGET_H

#include <QWidget>
#include <QTime>
#include <windows.h>
#include <windowsx.h>
#include "globalSettings.h"

namespace Ui {
    class SystemSettingWidget;
}

class SystemSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSettingWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~SystemSettingWidget();

    void changeDNMode();
    void Refresh_changless_words();

private:
    Ui::SystemSettingWidget *ui;

signals:
    void ok_signal(QString);
    void cancel_signal(QString);

private slots:
    void pbOk_clicked();
    void pbCancel_clicked();

    void on_leYear__editingFinished();
    void on_leHour__editingFinished();
    void on_leMonth__editingFinished();
    void on_leMinute__editingFinished();
    void on_leDay__editingFinished();
    void on_leSecond__editingFinished();
    void on_pbClose__clicked();
    void on_pbRestart__clicked();
};

#endif // SYSTEMSETTINGWIDGET_H
