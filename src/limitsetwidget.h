#ifndef LIMITSETWIDGET_H
#define LIMITSETWIDGET_H

#include <QWidget>
#include "lineedit.h"
#include "globalSettings.h"

namespace Ui {
    class limitSetWidget;
}

class LimitSetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LimitSetWidget(QWidget *parent = 0, QRect keyRect = QRect(0,0,0,0));

    ~LimitSetWidget();

    void changeDNMode();

public slots:
    void setActive();
    void setWarningLimit();
    void setAlarmLimit();

    void pbOk_clicked();
    void pbCancel_clicked();
    void Refresh_changless_words();


signals:
    void ok_signal(QString);
    void cancel_signal(QString);
private:
    Ui::limitSetWidget *ui;

    /*艏向限定*/
    LineEdit *leHeadWarnActive;
    LineEdit *leHeadAlarmActive;
    LineEdit *leHeadWarnLimit;
    LineEdit *leHeadAlarmLimit;
    /*位置限定*/
    LineEdit *lePositionWarnActive;
    LineEdit *lePositionAlarmActive;
    LineEdit *lePositionWarnLimit;
    LineEdit *lePositionAlarmLimit;
};

#endif // LIMITSETWIDGET_H
