#ifndef PROMPTWIDGETUSRSETTING_H
#define PROMPTWIDGETUSRSETTING_H

#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QTimer>
#include <QIntValidator>
#include "globalSettings.h"
#include "usrmanager.h"

class PromptWidgetUsrSetting : public QWidget
{
    Q_OBJECT
public:
    PromptWidgetUsrSetting(QWidget *parent=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickOk();
    void clickCancel();

signals:
    void promptFinished(void);

private:
    QLabel *_lblAutoLogOut;
    QLabel *_lblDelayMin;

    QCheckBox * _cbAutoLogOut;
    QLineEdit * _leDelayMin;

    QPushButton *_pbCancel; //取消
    QPushButton *_pbOK;     //确认

    UsrManager *_manager;

protected:
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);

public:
    void changeDNMode();
    void Refresh_changless_words();

    void initWidget();
};

#endif // PROMPTWIDGETUSRSETTING_H
