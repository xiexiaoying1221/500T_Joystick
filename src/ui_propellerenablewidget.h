/********************************************************************************
** Form generated from reading UI file 'propellerenablewidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPELLERENABLEWIDGET_H
#define UI_PROPELLERENABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropellerEnableWidget
{
public:
    QLineEdit *leenable_prop2;
    QLineEdit *leenable_prop3;
    QPushButton *pbOK;
    QLineEdit *lerun_prop2;
    QLineEdit *lerun_prop3;
    QLineEdit *leenable_prop1;
    QLineEdit *lerun_prop1;
    QLineEdit *leready_prop3;
    QLineEdit *leready_prop1;
    QLineEdit *leready_prop2;
    QLineEdit *lerun_rudder2;
    QLineEdit *leenable_rudder1;
    QLineEdit *leenable_rudder2;
    QLineEdit *lerun_rudder1;
    QPushButton *pbCancel;
    QLineEdit *leready_rudder1;
    QLineEdit *leready_rudder2;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *PropellerEnableWidget)
    {
        if (PropellerEnableWidget->objectName().isEmpty())
            PropellerEnableWidget->setObjectName(QString::fromUtf8("PropellerEnableWidget"));
        PropellerEnableWidget->resize(438, 710);
        leenable_prop2 = new QLineEdit(PropellerEnableWidget);
        leenable_prop2->setObjectName(QString::fromUtf8("leenable_prop2"));
        leenable_prop2->setGeometry(QRect(325, 210, 54, 33));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        leenable_prop2->setFont(font);
        leenable_prop2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leenable_prop2->setAlignment(Qt::AlignCenter);
        leenable_prop2->setReadOnly(true);
        leenable_prop3 = new QLineEdit(PropellerEnableWidget);
        leenable_prop3->setObjectName(QString::fromUtf8("leenable_prop3"));
        leenable_prop3->setGeometry(QRect(325, 270, 54, 33));
        leenable_prop3->setFont(font);
        leenable_prop3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leenable_prop3->setAlignment(Qt::AlignCenter);
        leenable_prop3->setReadOnly(true);
        pbOK = new QPushButton(PropellerEnableWidget);
        pbOK->setObjectName(QString::fromUtf8("pbOK"));
        pbOK->setGeometry(QRect(120, 593, 90, 40));
        QFont font1;
        font1.setPointSize(16);
        pbOK->setFont(font1);
        pbOK->setFocusPolicy(Qt::NoFocus);
        pbOK->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        lerun_prop2 = new QLineEdit(PropellerEnableWidget);
        lerun_prop2->setObjectName(QString::fromUtf8("lerun_prop2"));
        lerun_prop2->setGeometry(QRect(263, 213, 27, 27));
        QFont font2;
        font2.setPointSize(15);
        lerun_prop2->setFont(font2);
        lerun_prop2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        lerun_prop2->setReadOnly(true);
        lerun_prop3 = new QLineEdit(PropellerEnableWidget);
        lerun_prop3->setObjectName(QString::fromUtf8("lerun_prop3"));
        lerun_prop3->setGeometry(QRect(263, 273, 27, 27));
        lerun_prop3->setFont(font2);
        lerun_prop3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        lerun_prop3->setReadOnly(true);
        leenable_prop1 = new QLineEdit(PropellerEnableWidget);
        leenable_prop1->setObjectName(QString::fromUtf8("leenable_prop1"));
        leenable_prop1->setGeometry(QRect(325, 150, 54, 33));
        leenable_prop1->setFont(font);
        leenable_prop1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leenable_prop1->setAlignment(Qt::AlignCenter);
        leenable_prop1->setReadOnly(true);
        lerun_prop1 = new QLineEdit(PropellerEnableWidget);
        lerun_prop1->setObjectName(QString::fromUtf8("lerun_prop1"));
        lerun_prop1->setGeometry(QRect(263, 153, 27, 27));
        lerun_prop1->setFont(font2);
        lerun_prop1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        lerun_prop1->setReadOnly(true);
        leready_prop3 = new QLineEdit(PropellerEnableWidget);
        leready_prop3->setObjectName(QString::fromUtf8("leready_prop3"));
        leready_prop3->setGeometry(QRect(199, 273, 27, 27));
        leready_prop3->setFont(font2);
        leready_prop3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_prop3->setReadOnly(true);
        leready_prop1 = new QLineEdit(PropellerEnableWidget);
        leready_prop1->setObjectName(QString::fromUtf8("leready_prop1"));
        leready_prop1->setGeometry(QRect(199, 153, 27, 27));
        leready_prop1->setFont(font2);
        leready_prop1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"background-image: url(:/images/\346\216\250\350\277\233\345\231\250\345\220\257\347\224\250\350\256\276\347\275\256-\346\227\245.png);\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_prop1->setReadOnly(true);
        leready_prop2 = new QLineEdit(PropellerEnableWidget);
        leready_prop2->setObjectName(QString::fromUtf8("leready_prop2"));
        leready_prop2->setGeometry(QRect(199, 213, 27, 27));
        leready_prop2->setFont(font2);
        leready_prop2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_prop2->setReadOnly(true);
        lerun_rudder2 = new QLineEdit(PropellerEnableWidget);
        lerun_rudder2->setObjectName(QString::fromUtf8("lerun_rudder2"));
        lerun_rudder2->setGeometry(QRect(263, 392, 27, 27));
        lerun_rudder2->setFont(font2);
        lerun_rudder2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        lerun_rudder2->setReadOnly(true);
        leenable_rudder1 = new QLineEdit(PropellerEnableWidget);
        leenable_rudder1->setObjectName(QString::fromUtf8("leenable_rudder1"));
        leenable_rudder1->setGeometry(QRect(325, 329, 54, 33));
        leenable_rudder1->setFont(font);
        leenable_rudder1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leenable_rudder1->setAlignment(Qt::AlignCenter);
        leenable_rudder1->setReadOnly(true);
        leenable_rudder2 = new QLineEdit(PropellerEnableWidget);
        leenable_rudder2->setObjectName(QString::fromUtf8("leenable_rudder2"));
        leenable_rudder2->setGeometry(QRect(325, 389, 54, 33));
        leenable_rudder2->setFont(font);
        leenable_rudder2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leenable_rudder2->setAlignment(Qt::AlignCenter);
        leenable_rudder2->setReadOnly(true);
        lerun_rudder1 = new QLineEdit(PropellerEnableWidget);
        lerun_rudder1->setObjectName(QString::fromUtf8("lerun_rudder1"));
        lerun_rudder1->setGeometry(QRect(263, 332, 27, 27));
        lerun_rudder1->setFont(font2);
        lerun_rudder1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        lerun_rudder1->setReadOnly(true);
        pbCancel = new QPushButton(PropellerEnableWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(240, 593, 90, 40));
        pbCancel->setFont(font1);
        pbCancel->setFocusPolicy(Qt::NoFocus);
        pbCancel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_rudder1 = new QLineEdit(PropellerEnableWidget);
        leready_rudder1->setObjectName(QString::fromUtf8("leready_rudder1"));
        leready_rudder1->setGeometry(QRect(199, 332, 27, 27));
        leready_rudder1->setFont(font2);
        leready_rudder1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_rudder1->setReadOnly(true);
        leready_rudder2 = new QLineEdit(PropellerEnableWidget);
        leready_rudder2->setObjectName(QString::fromUtf8("leready_rudder2"));
        leready_rudder2->setGeometry(QRect(199, 392, 27, 27));
        leready_rudder2->setFont(font2);
        leready_rudder2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_rudder2->setReadOnly(true);
        label_1 = new QLabel(PropellerEnableWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 150, 161, 41));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(PropellerEnableWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 210, 161, 41));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(PropellerEnableWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 270, 161, 41));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(PropellerEnableWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 330, 161, 41));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(PropellerEnableWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 390, 161, 41));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(PropellerEnableWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(185, 90, 51, 31));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(PropellerEnableWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 90, 51, 31));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(PropellerEnableWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(325, 90, 51, 31));
        label_8->setAlignment(Qt::AlignCenter);

        retranslateUi(PropellerEnableWidget);

        QMetaObject::connectSlotsByName(PropellerEnableWidget);
    } // setupUi

    void retranslateUi(QWidget *PropellerEnableWidget)
    {
        PropellerEnableWidget->setWindowTitle(QApplication::translate("PropellerEnableWidget", "Form", 0, QApplication::UnicodeUTF8));
        leenable_prop2->setText(QString());
        leenable_prop3->setText(QString());
        pbOK->setText(QString());
        leenable_prop1->setText(QString());
        leenable_rudder1->setText(QString());
        leenable_rudder2->setText(QString());
        pbCancel->setText(QString());
        label_1->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PropellerEnableWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PropellerEnableWidget: public Ui_PropellerEnableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPELLERENABLEWIDGET_H
