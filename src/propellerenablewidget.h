#ifndef PROPELLERENABLEWIDGET_H
#define PROPELLERENABLEWIDGET_H

#include <QWidget>
#include <qlineedit.h>
#include "lineedit.h"
#include "globalSettings.h"

namespace Ui {
    class PropellerEnableWidget;
}

class PropellerEnableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PropellerEnableWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~PropellerEnableWidget();

    void changeDNMode();
    void refreshData();
    void Refresh_changless_words();

protected slots:
    void leEnable_Prop1_click();
    void leEnable_Prop2_click();
    void leEnable_Prop3_click();
    void leEnable_Rudder1_click();
    void leEnable_Rudder2_click();


    //确定-取消按钮
    void pbOK_clicked();
    void pbCancel_clicked();

signals:
    void ok_signal(QString);
    void cancel_signal(QString);


private:
    Ui::PropellerEnableWidget *ui;

    QLineEdit *leEnable_Prop1;
    QLineEdit *leEnable_Prop2;
    QLineEdit *leEnable_Prop3;
    QLineEdit *leEnable_Rudder1;
    QLineEdit *leEnable_Rudder2;

};

#endif // PROPELLERENABLEWIDGET_H
