/********************************************************************************
** Form generated from reading UI file 'headingsetpwidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADINGSETPWIDGET_H
#define UI_HEADINGSETPWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeadingSetpWidget
{
public:
    QDial *dial;
    QLineEdit *leHead;
    QPushButton *pbAdd;
    QPushButton *pbOK;
    QPushButton *pbReduce;
    QPushButton *pbCancel;

    void setupUi(QWidget *HeadingSetpWidget)
    {
        if (HeadingSetpWidget->objectName().isEmpty())
            HeadingSetpWidget->setObjectName(QString::fromUtf8("HeadingSetpWidget"));
        HeadingSetpWidget->resize(438, 710);
        dial = new QDial(HeadingSetpWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(70, 180, 290, 240));
        dial->setAutoFillBackground(false);
        dial->setMinimum(0);
        dial->setMaximum(3600);
        dial->setValue(1800);
        dial->setOrientation(Qt::Vertical);
        dial->setWrapping(true);
        leHead = new QLineEdit(HeadingSetpWidget);
        leHead->setObjectName(QString::fromUtf8("leHead"));
        leHead->setGeometry(QRect(110, 105, 231, 54));
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setWeight(75);
        leHead->setFont(font);
        leHead->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leHead->setAlignment(Qt::AlignCenter);
        leHead->setReadOnly(true);
        pbAdd = new QPushButton(HeadingSetpWidget);
        pbAdd->setObjectName(QString::fromUtf8("pbAdd"));
        pbAdd->setGeometry(QRect(243, 465, 88, 36));
        pbAdd->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        pbOK = new QPushButton(HeadingSetpWidget);
        pbOK->setObjectName(QString::fromUtf8("pbOK"));
        pbOK->setGeometry(QRect(122, 595, 88, 36));
        pbOK->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        pbReduce = new QPushButton(HeadingSetpWidget);
        pbReduce->setObjectName(QString::fromUtf8("pbReduce"));
        pbReduce->setGeometry(QRect(122, 466, 88, 36));
        pbReduce->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        pbCancel = new QPushButton(HeadingSetpWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(243, 595, 88, 36));
        pbCancel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));

        retranslateUi(HeadingSetpWidget);

        QMetaObject::connectSlotsByName(HeadingSetpWidget);
    } // setupUi

    void retranslateUi(QWidget *HeadingSetpWidget)
    {
        leHead->setText(QApplication::translate("HeadingSetpWidget", "0.0", 0, QApplication::UnicodeUTF8));
        pbAdd->setText(QString());
        pbOK->setText(QString());
        pbReduce->setText(QString());
        pbCancel->setText(QString());
        Q_UNUSED(HeadingSetpWidget);
    } // retranslateUi

};

namespace Ui {
    class HeadingSetpWidget: public Ui_HeadingSetpWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADINGSETPWIDGET_H
