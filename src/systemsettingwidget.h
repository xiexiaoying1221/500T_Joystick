#ifndef SYSTEMSETTINGWIDGET_H
#define SYSTEMSETTINGWIDGET_H

#include <QWidget>
#include <QTime>
#include <windows.h>
#include <windowsx.h>
#include "lineedit.h"
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

    QLineEdit *leDay;
    QLineEdit *leMonth;
    QLineEdit *leYear;
    QLineEdit *leHour;
    QLineEdit *leMinute;
    QLineEdit *leSecond;
    QLineEdit *leClose;
    QLineEdit *leRestart;

    QLineEdit *leCurrent;//当前点击的时间输入框
    int valCurrent;//当前的修改的时间值



signals:
    void ok_signal(QString);
    void cancel_signal(QString);

private slots:
    void pbOk_clicked();
    void pbCancel_clicked();

    void gbpbNumber_click();
    void gbplCancel_click();
    void gbpbOK_click();
    void leTime_click();//时间输入框 点击事件

    void leCloseOrRestart_click();//关闭、重新启动


};

#endif // SYSTEMSETTINGWIDGET_H
