/********************************************************************************
** Form generated from reading UI file 'sensorenablewidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORENABLEWIDGET_H
#define UI_SENSORENABLEWIDGET_H

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

class Ui_SensorEnableWidget
{
public:
    QLineEdit *leready_gypo;
    QLineEdit *leenable_gyro;
    QLineEdit *leenable_wind;
    QPushButton *pbOk;
    QPushButton *pbCancel;
    QLineEdit *leready_wind;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_1;

    void setupUi(QWidget *SensorEnableWidget)
    {
        if (SensorEnableWidget->objectName().isEmpty())
            SensorEnableWidget->setObjectName(QString::fromUtf8("SensorEnableWidget"));
        SensorEnableWidget->resize(438, 710);
        leready_gypo = new QLineEdit(SensorEnableWidget);
        leready_gypo->setObjectName(QString::fromUtf8("leready_gypo"));
        leready_gypo->setGeometry(QRect(220, 154, 25, 27));
        QFont font;
        font.setPointSize(16);
        leready_gypo->setFont(font);
        leready_gypo->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_gypo->setFrame(false);
        leready_gypo->setReadOnly(true);
        leenable_gyro = new QLineEdit(SensorEnableWidget);
        leenable_gyro->setObjectName(QString::fromUtf8("leenable_gyro"));
        leenable_gyro->setGeometry(QRect(287, 150, 52, 34));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        leenable_gyro->setFont(font1);
        leenable_gyro->setStyleSheet(QString::fromUtf8(""));
        leenable_gyro->setFrame(false);
        leenable_gyro->setAlignment(Qt::AlignCenter);
        leenable_gyro->setReadOnly(true);
        leenable_wind = new QLineEdit(SensorEnableWidget);
        leenable_wind->setObjectName(QString::fromUtf8("leenable_wind"));
        leenable_wind->setGeometry(QRect(287, 210, 52, 34));
        leenable_wind->setFont(font1);
        leenable_wind->setStyleSheet(QString::fromUtf8(""));
        leenable_wind->setFrame(false);
        leenable_wind->setAlignment(Qt::AlignCenter);
        leenable_wind->setReadOnly(true);
        pbOk = new QPushButton(SensorEnableWidget);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));
        pbOk->setGeometry(QRect(120, 592, 90, 40));
        pbOk->setFont(font);
        pbOk->setFocusPolicy(Qt::NoFocus);
        pbOk->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        pbCancel = new QPushButton(SensorEnableWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(240, 592, 90, 40));
        pbCancel->setFont(font);
        pbCancel->setFocusPolicy(Qt::NoFocus);
        pbCancel->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"border-style:outset;"));
        leready_wind = new QLineEdit(SensorEnableWidget);
        leready_wind->setObjectName(QString::fromUtf8("leready_wind"));
        leready_wind->setGeometry(QRect(220, 214, 25, 27));
        leready_wind->setFont(font);
        leready_wind->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_wind->setFrame(false);
        leready_wind->setReadOnly(true);
        label_2 = new QLabel(SensorEnableWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 210, 100, 41));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(SensorEnableWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 270, 100, 41));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(SensorEnableWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 330, 100, 41));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(SensorEnableWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 390, 100, 41));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(SensorEnableWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 100, 61, 31));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(SensorEnableWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 100, 61, 31));
        label_7->setAlignment(Qt::AlignCenter);
        label_1 = new QLabel(SensorEnableWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(80, 150, 100, 41));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(SensorEnableWidget);

        QMetaObject::connectSlotsByName(SensorEnableWidget);
    } // setupUi

    void retranslateUi(QWidget *SensorEnableWidget)
    {
        SensorEnableWidget->setWindowTitle(QApplication::translate("SensorEnableWidget", "Form", 0, QApplication::UnicodeUTF8));
        leready_gypo->setPlaceholderText(QString());
        leenable_gyro->setText(QString());
        leenable_wind->setText(QString());
        pbOk->setText(QString());
        pbCancel->setText(QString());
        label_2->setText(QApplication::translate("SensorEnableWidget", "\346\260\224\350\261\241\344\273\252", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QApplication::translate("SensorEnableWidget", "\345\260\261\347\273\252", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SensorEnableWidget", "\345\220\257\347\224\250", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("SensorEnableWidget", "\347\224\265\347\275\227\347\273\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SensorEnableWidget: public Ui_SensorEnableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORENABLEWIDGET_H
