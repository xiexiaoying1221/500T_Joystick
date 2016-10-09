/********************************************************************************
** Form generated from reading UI file 'sensorwidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORWIDGET_H
#define UI_SENSORWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensorWidget
{
public:
    QLineEdit *leready_gyro;
    QLineEdit *leheading_gyro;
    QLineEdit *leready_wind;
    QLineEdit *leenable_gyro;
    QLineEdit *leenable_wind;
    QLineEdit *lespeed_wind;
    QLineEdit *ledirection_wind;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_shouxiang;
    QLabel *label_fengsu;
    QLabel *label_fengxiang;
    QLabel *label_jiuxu;
    QLabel *label_qiyong;
    QLabel *label_shouxiang_dw;
    QLabel *label_fengsu_dw;
    QLabel *label_fengxiang_dw;

    void setupUi(QWidget *SensorWidget)
    {
        if (SensorWidget->objectName().isEmpty())
            SensorWidget->setObjectName(QString::fromUtf8("SensorWidget"));
        SensorWidget->resize(766, 768);
        leready_gyro = new QLineEdit(SensorWidget);
        leready_gyro->setObjectName(QString::fromUtf8("leready_gyro"));
        leready_gyro->setGeometry(QRect(594, 173, 27, 27));
        QFont font;
        font.setPointSize(16);
        leready_gyro->setFont(font);
        leready_gyro->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_gyro->setReadOnly(true);
        leheading_gyro = new QLineEdit(SensorWidget);
        leheading_gyro->setObjectName(QString::fromUtf8("leheading_gyro"));
        leheading_gyro->setGeometry(QRect(260, 165, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        leheading_gyro->setFont(font1);
        leheading_gyro->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leheading_gyro->setAlignment(Qt::AlignCenter);
        leheading_gyro->setReadOnly(true);
        leready_wind = new QLineEdit(SensorWidget);
        leready_wind->setObjectName(QString::fromUtf8("leready_wind"));
        leready_wind->setGeometry(QRect(594, 243, 27, 27));
        leready_wind->setFont(font);
        leready_wind->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leready_wind->setReadOnly(true);
        leenable_gyro = new QLineEdit(SensorWidget);
        leenable_gyro->setObjectName(QString::fromUtf8("leenable_gyro"));
        leenable_gyro->setGeometry(QRect(643, 173, 27, 27));
        leenable_gyro->setFont(font);
        leenable_gyro->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leenable_gyro->setReadOnly(true);
        leenable_wind = new QLineEdit(SensorWidget);
        leenable_wind->setObjectName(QString::fromUtf8("leenable_wind"));
        leenable_wind->setGeometry(QRect(643, 243, 27, 27));
        leenable_wind->setFont(font);
        leenable_wind->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leenable_wind->setReadOnly(true);
        lespeed_wind = new QLineEdit(SensorWidget);
        lespeed_wind->setObjectName(QString::fromUtf8("lespeed_wind"));
        lespeed_wind->setGeometry(QRect(260, 234, 102, 41));
        lespeed_wind->setFont(font1);
        lespeed_wind->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        lespeed_wind->setAlignment(Qt::AlignCenter);
        lespeed_wind->setReadOnly(true);
        ledirection_wind = new QLineEdit(SensorWidget);
        ledirection_wind->setObjectName(QString::fromUtf8("ledirection_wind"));
        ledirection_wind->setGeometry(QRect(450, 234, 111, 39));
        ledirection_wind->setFont(font1);
        ledirection_wind->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        ledirection_wind->setAlignment(Qt::AlignCenter);
        ledirection_wind->setReadOnly(true);
        label_1 = new QLabel(SensorWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(20, 168, 150, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        label_1->setFont(font2);
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(SensorWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 238, 150, 31));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_shouxiang = new QLabel(SensorWidget);
        label_shouxiang->setObjectName(QString::fromUtf8("label_shouxiang"));
        label_shouxiang->setGeometry(QRect(191, 175, 60, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        label_shouxiang->setFont(font3);
        label_shouxiang->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_fengsu = new QLabel(SensorWidget);
        label_fengsu->setObjectName(QString::fromUtf8("label_fengsu"));
        label_fengsu->setGeometry(QRect(191, 245, 60, 21));
        label_fengsu->setFont(font3);
        label_fengsu->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_fengxiang = new QLabel(SensorWidget);
        label_fengxiang->setObjectName(QString::fromUtf8("label_fengxiang"));
        label_fengxiang->setGeometry(QRect(390, 245, 60, 21));
        label_fengxiang->setFont(font3);
        label_fengxiang->setLayoutDirection(Qt::RightToLeft);
        label_fengxiang->setInputMethodHints(Qt::ImhNone);
        label_fengxiang->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_jiuxu = new QLabel(SensorWidget);
        label_jiuxu->setObjectName(QString::fromUtf8("label_jiuxu"));
        label_jiuxu->setGeometry(QRect(580, 130, 51, 31));
        label_jiuxu->setFont(font3);
        label_jiuxu->setAlignment(Qt::AlignCenter);
        label_qiyong = new QLabel(SensorWidget);
        label_qiyong->setObjectName(QString::fromUtf8("label_qiyong"));
        label_qiyong->setGeometry(QRect(630, 130, 51, 31));
        label_qiyong->setFont(font3);
        label_qiyong->setAlignment(Qt::AlignCenter);
        label_shouxiang_dw = new QLabel(SensorWidget);
        label_shouxiang_dw->setObjectName(QString::fromUtf8("label_shouxiang_dw"));
        label_shouxiang_dw->setGeometry(QRect(366, 170, 16, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        label_shouxiang_dw->setFont(font4);
        label_fengsu_dw = new QLabel(SensorWidget);
        label_fengsu_dw->setObjectName(QString::fromUtf8("label_fengsu_dw"));
        label_fengsu_dw->setGeometry(QRect(366, 240, 16, 16));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
        font5.setPointSize(10);
        label_fengsu_dw->setFont(font5);
        label_fengxiang_dw = new QLabel(SensorWidget);
        label_fengxiang_dw->setObjectName(QString::fromUtf8("label_fengxiang_dw"));
        label_fengxiang_dw->setGeometry(QRect(560, 240, 21, 16));
        label_fengxiang_dw->setFont(font5);

        retranslateUi(SensorWidget);

        QMetaObject::connectSlotsByName(SensorWidget);
    } // setupUi

    void retranslateUi(QWidget *SensorWidget)
    {
        SensorWidget->setWindowTitle(QApplication::translate("SensorWidget", "Form", 0, QApplication::UnicodeUTF8));
        leheading_gyro->setText(QString());
        lespeed_wind->setText(QString());
        ledirection_wind->setText(QString());
        label_1->setText(QApplication::translate("SensorWidget", "1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SensorWidget", "2", 0, QApplication::UnicodeUTF8));
        label_shouxiang->setText(QString());
        label_fengsu->setText(QString());
        label_fengxiang->setText(QString());
        label_jiuxu->setText(QString());
        label_qiyong->setText(QString());
        label_shouxiang_dw->setText(QString());
        label_fengsu_dw->setText(QString());
        label_fengxiang_dw->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SensorWidget: public Ui_SensorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORWIDGET_H
