/********************************************************************************
** Form generated from reading UI file 'positionreferencewidget.ui'
**
** Created: Sat Oct 8 15:51:50 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONREFERENCEWIDGET_H
#define UI_POSITIONREFERENCEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PositionReferenceWidget
{
public:
    QLineEdit *leNCurrentPosition;
    QLineEdit *leROS;
    QLineEdit *leRef1;
    QLineEdit *leRef2;
    QLineEdit *leStatus1;
    QLineEdit *leStatus2;
    QLineEdit *leWeight1;
    QLineEdit *leWeight2;
    QLineEdit *leECurrentPosition;
    QLineEdit *leNPositionSetpoint;
    QLineEdit *leEPositionSetpoint;
    QLineEdit *leWeight3;
    QLineEdit *leRef3;
    QLineEdit *leStatus3;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *PositionReferenceWidget)
    {
        if (PositionReferenceWidget->objectName().isEmpty())
            PositionReferenceWidget->setObjectName(QString::fromUtf8("PositionReferenceWidget"));
        PositionReferenceWidget->resize(766, 768);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PositionReferenceWidget->sizePolicy().hasHeightForWidth());
        PositionReferenceWidget->setSizePolicy(sizePolicy);
        leNCurrentPosition = new QLineEdit(PositionReferenceWidget);
        leNCurrentPosition->setObjectName(QString::fromUtf8("leNCurrentPosition"));
        leNCurrentPosition->setGeometry(QRect(190, 148, 191, 39));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        leNCurrentPosition->setFont(font);
        leNCurrentPosition->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leNCurrentPosition->setAlignment(Qt::AlignCenter);
        leNCurrentPosition->setReadOnly(true);
        leROS = new QLineEdit(PositionReferenceWidget);
        leROS->setObjectName(QString::fromUtf8("leROS"));
        leROS->setGeometry(QRect(306, 280, 141, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        leROS->setFont(font1);
        leROS->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(102, 102, 102);\n"
"border-width:0;\n"
"border-style:outset;"));
        leROS->setAlignment(Qt::AlignCenter);
        leROS->setReadOnly(true);
        leRef1 = new QLineEdit(PositionReferenceWidget);
        leRef1->setObjectName(QString::fromUtf8("leRef1"));
        leRef1->setGeometry(QRect(150, 364, 130, 40));
        leRef1->setFont(font1);
        leRef1->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leRef1->setAlignment(Qt::AlignCenter);
        leRef1->setReadOnly(true);
        leRef2 = new QLineEdit(PositionReferenceWidget);
        leRef2->setObjectName(QString::fromUtf8("leRef2"));
        leRef2->setGeometry(QRect(150, 408, 130, 40));
        leRef2->setFont(font1);
        leRef2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leRef2->setAlignment(Qt::AlignCenter);
        leRef2->setReadOnly(true);
        leStatus1 = new QLineEdit(PositionReferenceWidget);
        leStatus1->setObjectName(QString::fromUtf8("leStatus1"));
        leStatus1->setGeometry(QRect(290, 364, 180, 40));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        leStatus1->setFont(font2);
        leStatus1->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leStatus1->setAlignment(Qt::AlignCenter);
        leStatus1->setReadOnly(true);
        leStatus2 = new QLineEdit(PositionReferenceWidget);
        leStatus2->setObjectName(QString::fromUtf8("leStatus2"));
        leStatus2->setGeometry(QRect(290, 408, 180, 40));
        leStatus2->setFont(font2);
        leStatus2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leStatus2->setAlignment(Qt::AlignCenter);
        leStatus2->setReadOnly(true);
        leWeight1 = new QLineEdit(PositionReferenceWidget);
        leWeight1->setObjectName(QString::fromUtf8("leWeight1"));
        leWeight1->setGeometry(QRect(510, 364, 60, 40));
        leWeight1->setFont(font);
        leWeight1->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leWeight1->setAlignment(Qt::AlignCenter);
        leWeight1->setReadOnly(true);
        leWeight2 = new QLineEdit(PositionReferenceWidget);
        leWeight2->setObjectName(QString::fromUtf8("leWeight2"));
        leWeight2->setGeometry(QRect(510, 408, 60, 40));
        leWeight2->setFont(font);
        leWeight2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leWeight2->setAlignment(Qt::AlignCenter);
        leWeight2->setReadOnly(true);
        leECurrentPosition = new QLineEdit(PositionReferenceWidget);
        leECurrentPosition->setObjectName(QString::fromUtf8("leECurrentPosition"));
        leECurrentPosition->setGeometry(QRect(190, 206, 191, 39));
        leECurrentPosition->setFont(font);
        leECurrentPosition->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leECurrentPosition->setAlignment(Qt::AlignCenter);
        leECurrentPosition->setReadOnly(true);
        leNPositionSetpoint = new QLineEdit(PositionReferenceWidget);
        leNPositionSetpoint->setObjectName(QString::fromUtf8("leNPositionSetpoint"));
        leNPositionSetpoint->setGeometry(QRect(433, 148, 191, 39));
        leNPositionSetpoint->setFont(font);
        leNPositionSetpoint->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leNPositionSetpoint->setAlignment(Qt::AlignCenter);
        leNPositionSetpoint->setReadOnly(true);
        leEPositionSetpoint = new QLineEdit(PositionReferenceWidget);
        leEPositionSetpoint->setObjectName(QString::fromUtf8("leEPositionSetpoint"));
        leEPositionSetpoint->setGeometry(QRect(433, 206, 191, 39));
        leEPositionSetpoint->setFont(font);
        leEPositionSetpoint->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leEPositionSetpoint->setAlignment(Qt::AlignCenter);
        leEPositionSetpoint->setReadOnly(true);
        leWeight3 = new QLineEdit(PositionReferenceWidget);
        leWeight3->setObjectName(QString::fromUtf8("leWeight3"));
        leWeight3->setGeometry(QRect(510, 452, 60, 40));
        leWeight3->setFont(font2);
        leWeight3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leWeight3->setAlignment(Qt::AlignCenter);
        leWeight3->setReadOnly(true);
        leRef3 = new QLineEdit(PositionReferenceWidget);
        leRef3->setObjectName(QString::fromUtf8("leRef3"));
        leRef3->setGeometry(QRect(125, 452, 130, 40));
        leRef3->setFont(font2);
        leRef3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leRef3->setAlignment(Qt::AlignCenter);
        leRef3->setReadOnly(true);
        leStatus3 = new QLineEdit(PositionReferenceWidget);
        leStatus3->setObjectName(QString::fromUtf8("leStatus3"));
        leStatus3->setGeometry(QRect(290, 452, 180, 40));
        leStatus3->setFont(font2);
        leStatus3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leStatus3->setAlignment(Qt::AlignCenter);
        leStatus3->setReadOnly(true);
        label_5 = new QLabel(PositionReferenceWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 280, 251, 35));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(PositionReferenceWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 150, 61, 35));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(PositionReferenceWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 200, 61, 35));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_1 = new QLabel(PositionReferenceWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(210, 90, 161, 35));
        label_1->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(PositionReferenceWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 90, 161, 35));
        label_2->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(PositionReferenceWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 330, 151, 35));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(PositionReferenceWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 330, 151, 35));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(PositionReferenceWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(470, 330, 151, 35));
        label_8->setAlignment(Qt::AlignCenter);

        retranslateUi(PositionReferenceWidget);

        QMetaObject::connectSlotsByName(PositionReferenceWidget);
    } // setupUi

    void retranslateUi(QWidget *PositionReferenceWidget)
    {
        PositionReferenceWidget->setWindowTitle(QApplication::translate("PositionReferenceWidget", "Form", 0, QApplication::UnicodeUTF8));
        leNCurrentPosition->setText(QString());
        leROS->setText(QApplication::translate("PositionReferenceWidget", "GPS1", 0, QApplication::UnicodeUTF8));
        leRef1->setText(QString());
        leRef2->setText(QString());
        leStatus1->setText(QString());
        leStatus2->setText(QString());
        leWeight1->setText(QString());
        leWeight2->setText(QString());
        leECurrentPosition->setText(QString());
        leNPositionSetpoint->setText(QString());
        leEPositionSetpoint->setText(QString());
        leWeight3->setText(QString());
        leRef3->setText(QString());
        leStatus3->setText(QString());
        label_5->setText(QApplication::translate("PositionReferenceWidget", "\345\235\220\346\240\207\345\216\237\347\202\271\345\217\202\350\200\203\344\274\240\346\204\237\345\231\250\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PositionReferenceWidget", "\345\214\227", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PositionReferenceWidget", "\345\214\227", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("PositionReferenceWidget", "\350\256\276\345\256\232\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PositionReferenceWidget", "\345\275\223\345\211\215\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PositionReferenceWidget", "\344\274\240\346\204\237\345\231\250\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PositionReferenceWidget", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PositionReferenceWidget", "\345\212\240\346\235\203", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PositionReferenceWidget: public Ui_PositionReferenceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONREFERENCEWIDGET_H
