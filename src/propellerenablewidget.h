#ifndef PROPELLERENABLEWIDGET_H
#define PROPELLERENABLEWIDGET_H

#include <QWidget>
#include <qlineedit.h>
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

    //确定-取消按钮
    void pbOK_clicked();
    void pbCancel_clicked();

signals:
    void ok_signal(QString);
    void cancel_signal(QString);


private slots:
    void on_pbEnableProp1_clicked();
    void on_pbEnableProp2_clicked();
    void on_pbEnableProp3_clicked();
    void on_pbEnableRudder1_clicked();
    void on_pbEnableRudder2_clicked();

private:
    Ui::PropellerEnableWidget *ui;
};

#endif // PROPELLERENABLEWIDGET_H
