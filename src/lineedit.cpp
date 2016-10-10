#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "lineedit.h"

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    this->setAlignment(Qt::AlignCenter);

    this->setStyleSheet("border-color: #b7b7b7;border-width: 3px;border-style: solid;");
}

void LineEdit::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        emit clicked();
    }
    QLineEdit::mousePressEvent(event);
}
