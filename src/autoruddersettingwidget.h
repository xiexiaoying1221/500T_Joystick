#ifndef AUTORUDDERSETTINGWIDGET_H
#define AUTORUDDERSETTINGWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "lineedit.h"
#include "globalSettings.h"

namespace Ui {
    class AutoRudderSettingWidget;
}

class AutoRudderSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AutoRudderSettingWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~AutoRudderSettingWidget();

    void changeDNMode();

protected slots:
    void leGainLevel_click();
    void leCounterRudder_click();
    void leAutoTrim_click();
    void leWeather_click();
    void leRateTurn_click();

    /*小键盘*/
    void gbpbNumber_click();
    void gbpbOK_click();

private:
    Ui::AutoRudderSettingWidget *ui;

    QLineEdit *leGainLevel;
    QLineEdit *leCounterRudder;
    QLineEdit *leAutoTrim;
    QLineEdit *leWeather;
    QLineEdit *leRateTurn;
};

#endif // AUTORUDDERSETTINGWIDGET_H
