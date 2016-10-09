/********************************************************************************
** Form generated from reading UI file 'adjustingbrightnesswidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTINGBRIGHTNESSWIDGET_H
#define UI_ADJUSTINGBRIGHTNESSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdjustingBrightnessWidget
{
public:
    QPushButton *pbOk;
    QPushButton *pbCancel;
    QPushButton *pbAdd;
    QPushButton *pbReduce;
    QLabel *lblBright;
    QLabel *label;

    void setupUi(QWidget *AdjustingBrightnessWidget)
    {
        if (AdjustingBrightnessWidget->objectName().isEmpty())
            AdjustingBrightnessWidget->setObjectName(QString::fromUtf8("AdjustingBrightnessWidget"));
        AdjustingBrightnessWidget->resize(438, 710);
        pbOk = new QPushButton(AdjustingBrightnessWidget);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));
        pbOk->setGeometry(QRect(120, 594, 91, 37));
        QFont font;
        font.setPointSize(16);
        pbOk->setFont(font);
        pbOk->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        pbCancel = new QPushButton(AdjustingBrightnessWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(240, 594, 95, 37));
        pbCancel->setFont(font);
        pbCancel->setAutoFillBackground(false);
        pbCancel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        pbAdd = new QPushButton(AdjustingBrightnessWidget);
        pbAdd->setObjectName(QString::fromUtf8("pbAdd"));
        pbAdd->setGeometry(QRect(365, 204, 55, 41));
        pbAdd->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        pbReduce = new QPushButton(AdjustingBrightnessWidget);
        pbReduce->setObjectName(QString::fromUtf8("pbReduce"));
        pbReduce->setGeometry(QRect(28, 204, 60, 41));
        pbReduce->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        lblBright = new QLabel(AdjustingBrightnessWidget);
        lblBright->setObjectName(QString::fromUtf8("lblBright"));
        lblBright->setGeometry(QRect(105, 204, 16, 41));
        lblBright->setStyleSheet(QString::fromUtf8("border-width:5;\n"
"background-color: rgb(0, 0, 0);\n"
""));
        label = new QLabel(AdjustingBrightnessWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 100, 191, 51));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\350\260\203\345\205\211-\346\227\245.png);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(AdjustingBrightnessWidget);

        QMetaObject::connectSlotsByName(AdjustingBrightnessWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustingBrightnessWidget)
    {
        AdjustingBrightnessWidget->setWindowTitle(QApplication::translate("AdjustingBrightnessWidget", "Form", 0, QApplication::UnicodeUTF8));
        pbOk->setText(QString());
        pbCancel->setText(QString());
        pbAdd->setText(QString());
        pbReduce->setText(QString());
        lblBright->setText(QApplication::translate("AdjustingBrightnessWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdjustingBrightnessWidget", "\344\272\256\345\272\246\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdjustingBrightnessWidget: public Ui_AdjustingBrightnessWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTINGBRIGHTNESSWIDGET_H
