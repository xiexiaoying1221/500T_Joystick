#ifndef SENSORENABLEWIDGET_H
#define SENSORENABLEWIDGET_H

#include <QWidget>
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
    //确定按钮
    void pbOK_clicked();
    void pbCancel_clicked();


private slots:
    void on_pbEnableGyro_clicked();
    void on_pbEnableWind_clicked();

private:
    Ui::SensorEnableWidget *ui;

};

#endif // SENSORENABLEWIDGET_H
