#ifndef HEADINGSETPWIDGET_H
#define HEADINGSETPWIDGET_H

#include <QWidget>
#include "dataCommit.h"
#include "globalSettings.h"

namespace Ui {
    class HeadingSetpWidget;
}

class HeadingSetpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeadingSetpWidget(QWidget *parent = 0,QRect rect = QRect(0,0,0,0));
    ~HeadingSetpWidget();

    void refreshData();

    void changeDNMode();
    void Refresh_changless_words();


signals:
//   void changecurrenthead();

    void ok_signal(QString);
    void cancel_signal(QString);

protected slots:
    void dialValueChanged(int);
    void pbAdd_clicked();
    void pbOK_clicked();
    void pbCancel_clicked();
    void pbReduce_clicked();

private:
    Ui::HeadingSetpWidget *ui;


    int convert2dial (float value);
    float convert2Text (int dial);


};

#endif // HEADINGSETPWIDGET_H
