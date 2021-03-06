﻿#ifndef ADJUSTINGBRIGHTNESSWIDGET_H
#define ADJUSTINGBRIGHTNESSWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QProcess>
#include <windows.h>
#include <windowsx.h>
#include <WinUser.h>
#include <QWindow>

#include "dataCommit.h"
#include "globalSettings.h"

namespace Ui {
    class AdjustingBrightnessWidget;
}

class AdjustingBrightnessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustingBrightnessWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~AdjustingBrightnessWidget();

//    int GetGamma();
//    int SetGamma(int);
    void changeDNMode();
    void Refresh_changless_words();
    void attachWindow(void);
    void hideWindow( bool visible );

private:
    Ui::AdjustingBrightnessWidget *ui;

//    int maxBright;//最大亮度
//    int nowBright;//当前亮度
//    int tempRight;//临时
//    int lastBright;

//    //亮度lbl 位置 大小
//    int lblx;
//    int lbly;
//    int lblw;
//    int lblh;

    QProcess* m_dimProg;
    QWindow* m_window;
    QWidget* m_widget;
signals:
    void ok_signal(QString);
    void cancel_signal(QString);


private slots:
    void on_pbOk_clicked();
    void on_pbCancel_clicked();
};

#endif // ADJUSTINGBRIGHTNESSWIDGET_H
