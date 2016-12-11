#ifndef LIMITSETWIDGET_H
#define LIMITSETWIDGET_H

#include <QWidget>
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
    void pbOk_clicked();
    void pbCancel_clicked();
    void Refresh_changless_words();

signals:
    void ok_signal(QString);
    void cancel_signal(QString);

private slots:
    void on_leHeadWarnLimit__editingFinished();
    void on_leHeadAlarmLimit__editingFinished();
    void on_pbHeadWarnActive__clicked();
    void on_pbHeadAlarmActive__clicked();

private:
    Ui::limitSetWidget *ui;
};

#endif // LIMITSETWIDGET_H
