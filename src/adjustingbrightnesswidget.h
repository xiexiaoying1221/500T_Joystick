#ifndef ADJUSTINGBRIGHTNESSWIDGET_H
#define ADJUSTINGBRIGHTNESSWIDGET_H

#include <QWidget>

#include <windows.h>
#include <windowsx.h>
#include <WinGDI.h>
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

    int GetGamma();
    int SetGamma(int);
    void changeDNMode();
    void Refresh_changless_words();

private:
    Ui::AdjustingBrightnessWidget *ui;

    int maxBright;//最大亮度
    int nowBright;//当前亮度
    int tempRight;//临时
    int lastBright;

    //亮度lbl 位置 大小
    int lblx;
    int lbly;
    int lblw;
    int lblh;


signals:
    void ok_signal(QString);
    void cancel_signal(QString);


private slots:
    void pbOk_clicked();
    void pbCancel_clicked();
    void pbAdd_clicked();
    void pbReduce_clicked();

};

#endif // ADJUSTINGBRIGHTNESSWIDGET_H
