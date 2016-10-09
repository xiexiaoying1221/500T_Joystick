/********************************************************************************
** Form generated from reading UI file 'systeminfowidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMINFOWIDGET_H
#define UI_SYSTEMINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemInfoWidget
{
public:
    QLabel *label_1;
    QLabel *lblIP;
    QLabel *label_2;
    QLabel *lblSWDeliveryVersion;
    QLabel *label_7;
    QLabel *lblWindowVersion;
    QLabel *lblSWBasisVersion;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *lblPanelPromVersion;
    QLabel *label_5;
    QLabel *lblGMSVersion;
    QLabel *label_6;
    QLabel *lblOSKVersion;

    void setupUi(QWidget *SystemInfoWidget)
    {
        if (SystemInfoWidget->objectName().isEmpty())
            SystemInfoWidget->setObjectName(QString::fromUtf8("SystemInfoWidget"));
        SystemInfoWidget->resize(1024, 768);
        SystemInfoWidget->setWindowOpacity(0);
        label_1 = new QLabel(SystemInfoWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(150, 110, 220, 25));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblIP = new QLabel(SystemInfoWidget);
        lblIP->setObjectName(QString::fromUtf8("lblIP"));
        lblIP->setGeometry(QRect(390, 110, 141, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lblIP->setFont(font1);
        lblIP->setStyleSheet(QString::fromUtf8("color: rgb(136, 136, 136);"));
        label_2 = new QLabel(SystemInfoWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 150, 220, 25));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblSWDeliveryVersion = new QLabel(SystemInfoWidget);
        lblSWDeliveryVersion->setObjectName(QString::fromUtf8("lblSWDeliveryVersion"));
        lblSWDeliveryVersion->setGeometry(QRect(390, 150, 51, 25));
        lblSWDeliveryVersion->setFont(font1);
        lblSWDeliveryVersion->setStyleSheet(QString::fromUtf8("color: rgb(136, 136, 136);"));
        label_7 = new QLabel(SystemInfoWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 380, 220, 25));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblWindowVersion = new QLabel(SystemInfoWidget);
        lblWindowVersion->setObjectName(QString::fromUtf8("lblWindowVersion"));
        lblWindowVersion->setGeometry(QRect(390, 380, 162, 25));
        lblWindowVersion->setFont(font1);
        lblWindowVersion->setStyleSheet(QString::fromUtf8("color: rgb(136, 136, 136);"));
        lblSWBasisVersion = new QLabel(SystemInfoWidget);
        lblSWBasisVersion->setObjectName(QString::fromUtf8("lblSWBasisVersion"));
        lblSWBasisVersion->setGeometry(QRect(390, 190, 51, 25));
        lblSWBasisVersion->setFont(font1);
        lblSWBasisVersion->setStyleSheet(QString::fromUtf8("color: rgb(136, 136, 136);"));
        label_3 = new QLabel(SystemInfoWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 190, 220, 25));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(SystemInfoWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 230, 220, 25));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblPanelPromVersion = new QLabel(SystemInfoWidget);
        lblPanelPromVersion->setObjectName(QString::fromUtf8("lblPanelPromVersion"));
        lblPanelPromVersion->setGeometry(QRect(390, 230, 61, 25));
        lblPanelPromVersion->setFont(font1);
        lblPanelPromVersion->setStyleSheet(QString::fromUtf8("color: rgb(136, 136, 136);"));
        label_5 = new QLabel(SystemInfoWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 300, 220, 25));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblGMSVersion = new QLabel(SystemInfoWidget);
        lblGMSVersion->setObjectName(QString::fromUtf8("lblGMSVersion"));
        lblGMSVersion->setGeometry(QRect(390, 300, 81, 25));
        lblGMSVersion->setFont(font1);
        lblGMSVersion->setStyleSheet(QString::fromUtf8("color: rgb(136, 136, 136);"));
        label_6 = new QLabel(SystemInfoWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 340, 220, 25));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblOSKVersion = new QLabel(SystemInfoWidget);
        lblOSKVersion->setObjectName(QString::fromUtf8("lblOSKVersion"));
        lblOSKVersion->setGeometry(QRect(390, 340, 54, 25));
        lblOSKVersion->setFont(font1);
        lblOSKVersion->setStyleSheet(QString::fromUtf8("color: rgb(136, 136, 136);"));

        retranslateUi(SystemInfoWidget);

        QMetaObject::connectSlotsByName(SystemInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *SystemInfoWidget)
    {
        SystemInfoWidget->setWindowTitle(QApplication::translate("SystemInfoWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("SystemInfoWidget", "IP Address\357\274\232", 0, QApplication::UnicodeUTF8));
        lblIP->setText(QApplication::translate("SystemInfoWidget", "192.168.1.101", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SystemInfoWidget", "SW Version\357\274\232", 0, QApplication::UnicodeUTF8));
        lblSWDeliveryVersion->setText(QApplication::translate("SystemInfoWidget", "1.0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SystemInfoWidget", "Windows Version\357\274\232", 0, QApplication::UnicodeUTF8));
        lblWindowVersion->setText(QApplication::translate("SystemInfoWidget", "xp sp3", 0, QApplication::UnicodeUTF8));
        lblSWBasisVersion->setText(QApplication::translate("SystemInfoWidget", "7.0.1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SystemInfoWidget", "Sw Config. Version\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SystemInfoWidget", "Controller SW Version:", 0, QApplication::UnicodeUTF8));
        lblPanelPromVersion->setText(QApplication::translate("SystemInfoWidget", "1.0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SystemInfoWidget", "SDK Version\357\274\232", 0, QApplication::UnicodeUTF8));
        lblGMSVersion->setText(QApplication::translate("SystemInfoWidget", "4.7.2", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SystemInfoWidget", "IDE Version\357\274\232", 0, QApplication::UnicodeUTF8));
        lblOSKVersion->setText(QApplication::translate("SystemInfoWidget", "2.1.0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemInfoWidget: public Ui_SystemInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMINFOWIDGET_H
