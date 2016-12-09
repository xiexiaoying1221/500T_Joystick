#ifndef PROMPTWIDGETLOGIN_H
#define PROMPTWIDGETLOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QMessageBox>
#include "globalSettings.h"
#include "usrmanager.h"

class PromptWidgetLogIn : public QWidget
{
    Q_OBJECT
public:
    PromptWidgetLogIn(QWidget *parent=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickOk();
    void clickCancel();

private:
    QLabel *_lblName;//用户名
    QLabel *_lblPswd;//密码

    QLineEdit * _leName;
    QLineEdit * _lePswd;

    QPushButton *_pbCancel;//取消
    QPushButton *_pbOK; //登录

    UsrManager *_manager;

protected:
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);

signals:
    void promptFinished(void);

public:
    void changeDNMode();
    void Refresh_changless_words();
    void initWidget();
};

#endif // PROMPTWIDGETLOGIN_H
