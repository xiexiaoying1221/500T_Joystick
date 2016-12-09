#ifndef USRMANAGEWIDGET_H
#define USRMANAGEWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QStandardItemModel>
#include "usrmanager.h"
#include "promptwidgets/promptwidgetusrnew.h"
#include "promptwidgets/promptwidgetchangname.h"
#include "promptwidgets/promptwidgetchangpswd.h"

namespace Ui {
class UsrManageWidget;
}

class UsrManageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UsrManageWidget(QWidget *parent = 0, QRect rect = QRect(0,0,0,0));
    ~UsrManageWidget();

    void changeDNMode();
    void Refresh_changlese_words();


private slots:
    //处理用户列表改变
    void updateModel();
    //登录状态改变
    void usrLogInChanged();
    //弹出界面结束
    void promptFinished();

    void on_pbChangeName_clicked();

    void on_pbChangePswd_clicked();

    void on_pbNewUsr_clicked();

    void on_pbDeleteUsr_clicked();

    void on_pbCancel_clicked();

    void on_tableView_clicked(const QModelIndex &index);
protected:
    void showEvent(QShowEvent *);

private:
    Ui::UsrManageWidget *ui;
    QStandardItemModel* _model;
    UsrManager *_manager;
    PromptWidgetChangeName *_promptWidgetChangeName;
    PromptWidgetChangePswd *_promptWidgetChangePswd;
    PromptWidgetUsrNew *_promptWidgetUsrNew;

signals:
    void ok_signal(QString);
    void cancel_signal(QString);

};

#endif // USRMANAGEWIDGET_H
