#ifndef TOKENWIDGET_H
#define TOKENWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QStandardItemModel>
#include <QThread>
#include "tmtokenmanager.h"
#include "promptwidgetwithsyn.h"
#include "promptwidget.h"
#include "buzzergovernor.h"
#include "globalSettings.h"

namespace Ui {
class TokenWidget;
}

class TokenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TokenWidget(QWidget *parent = 0, QRect rect = QRect(0,0,0,0));
    ~TokenWidget();

    void changeDNMode();
    void refreshData();
    void Refresh_changlese_words();


    tmTokenManager *manager;
    PromptWidgetWithSyn *promptWidgetWithSyn;
    PromptWidget *promptWidget;

private slots:
    void updateModel(int index);//更新从站列表
    void updateMasterString();//更新主站信息
    void selfStateChanged(quint64 state);//更新本机的状态
    void prompFinished(bool ok);//处理弹出界面完成
    void lostToken();//处理网络令牌丢失，本机需要获得令牌的故障
    void multiToken();//处理网络令牌重复，本机需要让出令牌的故障

    //按钮
    void on_pbAct_clicked();

    void on_pbCancel_clicked();

    void on_pbOk_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::TokenWidget *ui;
    QStandardItemModel* _model;
    QThread *_comm;
    unsigned short _promptRes;
    buzzerGovernor *_buzzer;
signals:
    void ok_signal(QString);
    void cancel_signal(QString);

};

#endif // TOKENWIDGET_H
