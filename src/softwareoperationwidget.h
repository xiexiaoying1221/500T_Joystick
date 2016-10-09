#ifndef SOFTWAREOPERATIONWIDGET_H
#define SOFTWAREOPERATIONWIDGET_H

#include <QWidget>
#include <qprocess.h>
#include <windows.h>
#include <windowsx.h>
#include <math.h>
#include <algorithm>
#include <qlineedit.h>
#include "lineedit.h"
#include "globalSettings.h"

namespace Ui {
    class SoftwareOperationWidget;
}

class SoftwareOperationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SoftwareOperationWidget(QWidget *parent = 0, QRect rect = QRect(0,0,0,0));
    ~SoftwareOperationWidget();

private slots:
    void shutDown();
    void restartThis();
//    bool test();
//    int SetGamma(int);

private:
    Ui::SoftwareOperationWidget *ui;

    QLineEdit *leShutDown;
    QLineEdit *leRestartThis;
    QLineEdit *leUpgradeRemote;
    QLineEdit *leUpgradeRemoteStatus;
    QLineEdit *leClearFlash;
    QLineEdit *leClearFlashStatus;
    QLineEdit *leUpgradeFlash;
    QLineEdit *leUpgadeFlashStatus;
    QLineEdit *leRestartRemote;
    QLineEdit *leRestartRemoteStatus;
    QLineEdit *leStartedAsStatus;
    QLineEdit *leModeStatus;
    QLineEdit *leFileVersionStatus;
};

#endif // SOFTWAREOPERATIONWIDGET_H
