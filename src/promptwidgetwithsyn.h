#ifndef PROMPTWIDGETWITHSYN_H
#define PROMPTWIDGETWITHSYN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QTimer>
#include "globalSettings.h"

class PromptWidgetWithSyn : public QWidget{

    Q_OBJECT

public:
    PromptWidgetWithSyn(QWidget *parent=0, QWidget *singalReceiver=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickOk();
    void clickCancel();

signals:
    void changemode(bool);

private:
    QLabel *lblPrompt;
    QLabel *lblConst;
    QPushButton *pbCancel;
    QPushButton *pbOK;
protected:
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *);


public:
    QString message;//消息
    int targetState;//目标状态
    unsigned short *statePtr;//修改的状态位

    void refreshData();
    void changeDNMode();
    void Refresh_changless_words();
};

#endif // PROMPTWIDGETWITHSYN_H
