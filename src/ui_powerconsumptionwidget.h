/********************************************************************************
** Form generated from reading UI file 'powerconsumptionwidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERCONSUMPTIONWIDGET_H
#define UI_POWERCONSUMPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowerConsumptionWidget
{
public:
    QLineEdit *lepower_now;
    QLineEdit *lepower_sum;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *PowerConsumptionWidget)
    {
        if (PowerConsumptionWidget->objectName().isEmpty())
            PowerConsumptionWidget->setObjectName(QString::fromUtf8("PowerConsumptionWidget"));
        PowerConsumptionWidget->resize(766, 768);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        PowerConsumptionWidget->setFont(font);
        lepower_now = new QLineEdit(PowerConsumptionWidget);
        lepower_now->setObjectName(QString::fromUtf8("lepower_now"));
        lepower_now->setGeometry(QRect(341, 371, 102, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(20);
        lepower_now->setFont(font1);
        lepower_now->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        lepower_now->setAlignment(Qt::AlignCenter);
        lepower_now->setReadOnly(true);
        lepower_sum = new QLineEdit(PowerConsumptionWidget);
        lepower_sum->setObjectName(QString::fromUtf8("lepower_sum"));
        lepower_sum->setGeometry(QRect(341, 529, 102, 40));
        lepower_sum->setFont(font1);
        lepower_sum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        lepower_sum->setAlignment(Qt::AlignCenter);
        lepower_sum->setReadOnly(true);
        label_1 = new QLabel(PowerConsumptionWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(290, 50, 201, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(24);
        label_1->setFont(font2);
        label_1->setLayoutDirection(Qt::LeftToRight);
        label_1->setFrameShape(QFrame::NoFrame);
        label_1->setFrameShadow(QFrame::Sunken);
        label_1->setAlignment(Qt::AlignCenter);
        label_1->setMargin(0);
        label_2 = new QLabel(PowerConsumptionWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 525, 201, 51));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(PowerConsumptionWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(460, 540, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(14);
        label_3->setFont(font3);
        label_4 = new QLabel(PowerConsumptionWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 380, 71, 31));
        label_4->setFont(font3);
        lepower_now->raise();
        lepower_sum->raise();
        label_1->raise();
        label_4->raise();
        label_3->raise();
        label_2->raise();

        retranslateUi(PowerConsumptionWidget);

        QMetaObject::connectSlotsByName(PowerConsumptionWidget);
    } // setupUi

    void retranslateUi(QWidget *PowerConsumptionWidget)
    {
        PowerConsumptionWidget->setWindowTitle(QApplication::translate("PowerConsumptionWidget", "Form", 0, QApplication::UnicodeUTF8));
        lepower_now->setText(QString());
        lepower_sum->setText(QString());
        label_1->setText(QApplication::translate("PowerConsumptionWidget", "\345\212\237\347\216\207\346\266\210\350\200\227", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PowerConsumptionWidget", "\345\217\257\347\224\250\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PowerConsumptionWidget", "kW", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PowerConsumptionWidget", "kW", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PowerConsumptionWidget: public Ui_PowerConsumptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERCONSUMPTIONWIDGET_H
