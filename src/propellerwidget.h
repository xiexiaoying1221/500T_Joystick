#ifndef PROPELLERWIDGET_H
#define PROPELLERWIDGET_H

#include <QWidget>
#include "globalSettings.h"
#include "dataCommit.h"

namespace Ui {
    class PropellerWidget;
}

class PropellerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PropellerWidget(QWidget *parent = 0, QRect rect = QRect(0,0,0,0));
    ~PropellerWidget();

    void changeDNMode();

    void refreshData();
    void Refresh_changless_words();
private:
    Ui::PropellerWidget *ui;
};

#endif // PROPELLERWIDGET_H
