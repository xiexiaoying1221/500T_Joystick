#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QtGui>
#include "qwidget.h"
#include "qlineedit.h"

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    LineEdit(QWidget *parent = 0);

protected:
    virtual void mousePressEvent(QMouseEvent *event);

private slots:

signals:
    void clicked();
};

#endif // LINEEDIT_H
