﻿#ifndef GENERALSETTINGWIDGET_H
#define GENERALSETTINGWIDGET_H

#include <QWidget>
#include <lineedit.h>
#include <qchar.h>
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

    QLineEdit *leThrusterAlloc;
    QLineEdit *leRateTurn;
    QLineEdit *leDraughtType;
    QLineEdit *leWindComp;
    QLineEdit *leGainLevel;

private slots:
    void leThrusterAlloc_click();
    void leRateTurn_click();
    void leDraughtType_click();
    void leWindComp_click();
    void leGainLevel_click();

    /*小键盘*/
    void gbpbNumber_click();
    void gbpbOK_click();

    //确定按钮
    void pbOK_clicked();
    void pbCancel_clicked();

signals:
    void ok_signal(QString);
    void cancel_signal(QString);

};

#endif // GENERALSETTINGWIDGET_H