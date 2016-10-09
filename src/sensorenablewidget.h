#ifndef SENSORENABLEWIDGET_H
#define SENSORENABLEWIDGET_H

#include <QWidget>
#include <lineedit.h>
#include <globalSettings.h>

namespace Ui {
    class SensorEnableWidget;
}

class SensorEnableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SensorEnableWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~SensorEnableWidget();

    void changeDNMode();
    void refreshData();
    void Refresh_changless_words();


signals:
    void ok_signal(QString);
    void cancel_signal(QString);


protected slots:
    void leGyroEnable_click();
    void leWindEnable_click();
    void leVrsEnable_click();
    void leGps1Enable_click();
    void leGps2Enable_click();
    //确定按钮
    void pbOK_clicked();
    void pbCancel_clicked();


private:
    Ui::SensorEnableWidget *ui;

    QLineEdit *leGyroReady;
    QLineEdit *leGyroEnable;
    QLineEdit *leGps1Ready;
    QLineEdit *leGps1Enable;
    QLineEdit *leGps2Ready;
    QLineEdit *leGps2Enable;
    QLineEdit *leWindReady;
    QLineEdit *leWindEnable;
    QLineEdit *leVrsReady;
    QLineEdit *leVrsEnable;
};

#endif // SENSORENABLEWIDGET_H
