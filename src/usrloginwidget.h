#ifndef USRLOGINWIDGET_H
#define USRLOGINWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QStandardItemModel>
#include <QThread>
#include "globalSettings.h"
#include "characterconversion.h"
#include "usrmanager.h"
#include "promptwidgets/promptwidgetlogin.h"
#include "promptwidgets/promptwidgetusrsetting.h"

namespace Ui {
class UsrLogInWidget;
}

class UsrLogInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UsrLogInWidget(QWidget *parent = 0, QRect rect = QRect(0,0,0,0));
    ~UsrLogInWidget();

    void changeDNMode();
    void Refresh_changlese_words();

private slots:
    //登录状态改变
    void usrLogInChanged();
    //弹出界面结束
    void promptFinished();

    void on_pbCancel_clicked();

    void on_pbAutoLogOut_clicked();

    void on_pbLogOut_clicked();

    void on_pbLogIn_clicked();
protected:
    void showEvent(QShowEvent *);

private:
    Ui::UsrLogInWidget *ui;
    UsrManager *_manager;
    PromptWidgetLogIn *_promptWidgetLogIn;
    PromptWidgetUsrSetting *_promptWidgetUsrSetting;

signals:
    void ok_signal(QString);
    void cancel_signal(QString);

};

#endif // USRLOGINWIDGET_H
