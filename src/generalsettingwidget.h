#ifndef GENERALSETTINGWIDGET_H
#define GENERALSETTINGWIDGET_H

#include <QWidget>
#include <qchar.h>
#include <QPushButton>
#include "sticksettingwidget.h"
#include "dataCommit.h"
#include "globalSettings.h"

namespace Ui {
    class GeneralSettingWidget;
}

class GeneralSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralSettingWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~GeneralSettingWidget();

    void changeDNMode();
    void Refresh_changless_words();

private:
    Ui::GeneralSettingWidget *ui;
    StickSettingWidget* _prompt;

private slots:
    void leThrusterAlloc_click();
    void leRateTurn_click();
    void leDraughtType_click();
    void leWindComp_click();
    void leGainLevel_click();
    void leMaxRudderAngle_click();

    //确定按钮
    void pbOK_clicked();
    void pbCancel_clicked();

    void on_pbStickSetting_clicked();
    void promptFinished();

    void on_leRateTurn__editingFinished();

    void on_leMaxRudderAngle__editingFinished();

signals:
    void ok_signal(QString);
    void cancel_signal(QString);

};

#endif // GENERALSETTINGWIDGET_H
