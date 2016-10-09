/********************************************************************************
** Form generated from reading UI file 'softwareoperationwidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTWAREOPERATIONWIDGET_H
#define UI_SOFTWAREOPERATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SoftwareOperationWidget
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *leShutDown_;
    QLineEdit *leRestartThis_;
    QLineEdit *leUpgradeRemote_;
    QLineEdit *leUpgradeRemoteStatus_;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *leUpgradeFlash_;
    QLineEdit *leRestartRemote_;
    QLineEdit *leClearFlash_;
    QLineEdit *leUpgadeFlashStatus_;
    QLineEdit *leRestartRemoteStatus_;
    QLineEdit *leClearFlashStatus_;
    QLineEdit *leModeStatus_;
    QLineEdit *leFileVersionStatus_;
    QLineEdit *leStartedAsStatus_;
    QLabel *label_6;
    QPushButton *pbOK;

    void setupUi(QWidget *SoftwareOperationWidget)
    {
        if (SoftwareOperationWidget->objectName().isEmpty())
            SoftwareOperationWidget->setObjectName(QString::fromUtf8("SoftwareOperationWidget"));
        SoftwareOperationWidget->resize(456, 768);
        groupBox = new QGroupBox(SoftwareOperationWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 40, 441, 141));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 30, 256, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 70, 240, 16));
        label_4->setFrameShape(QFrame::NoFrame);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 110, 256, 16));
        leShutDown_ = new QLineEdit(groupBox);
        leShutDown_->setObjectName(QString::fromUtf8("leShutDown_"));
        leShutDown_->setGeometry(QRect(310, 30, 40, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        leShutDown_->setFont(font1);
        leRestartThis_ = new QLineEdit(groupBox);
        leRestartThis_->setObjectName(QString::fromUtf8("leRestartThis_"));
        leRestartThis_->setGeometry(QRect(310, 70, 40, 20));
        leRestartThis_->setFont(font1);
        leUpgradeRemote_ = new QLineEdit(groupBox);
        leUpgradeRemote_->setObjectName(QString::fromUtf8("leUpgradeRemote_"));
        leUpgradeRemote_->setGeometry(QRect(310, 110, 40, 20));
        leUpgradeRemote_->setFont(font1);
        leUpgradeRemoteStatus_ = new QLineEdit(groupBox);
        leUpgradeRemoteStatus_->setObjectName(QString::fromUtf8("leUpgradeRemoteStatus_"));
        leUpgradeRemoteStatus_->setGeometry(QRect(390, 110, 35, 20));
        leUpgradeRemoteStatus_->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        label = new QLabel(SoftwareOperationWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 2, 151, 20));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label_2 = new QLabel(SoftwareOperationWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 30, 32, 16));
        label_2->setFont(font2);
        groupBox_2 = new QGroupBox(SoftwareOperationWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 220, 431, 271));
        groupBox_2->setFont(font2);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 30, 88, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 70, 256, 16));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 110, 216, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 230, 144, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 150, 200, 16));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 190, 136, 16));
        leUpgradeFlash_ = new QLineEdit(groupBox_2);
        leUpgradeFlash_->setObjectName(QString::fromUtf8("leUpgradeFlash_"));
        leUpgradeFlash_->setGeometry(QRect(300, 70, 40, 20));
        leUpgradeFlash_->setFont(font1);
        leRestartRemote_ = new QLineEdit(groupBox_2);
        leRestartRemote_->setObjectName(QString::fromUtf8("leRestartRemote_"));
        leRestartRemote_->setGeometry(QRect(300, 110, 40, 20));
        leRestartRemote_->setFont(font1);
        leClearFlash_ = new QLineEdit(groupBox_2);
        leClearFlash_->setObjectName(QString::fromUtf8("leClearFlash_"));
        leClearFlash_->setGeometry(QRect(300, 30, 40, 20));
        leClearFlash_->setFont(font1);
        leUpgadeFlashStatus_ = new QLineEdit(groupBox_2);
        leUpgadeFlashStatus_->setObjectName(QString::fromUtf8("leUpgadeFlashStatus_"));
        leUpgadeFlashStatus_->setGeometry(QRect(380, 70, 35, 20));
        leUpgadeFlashStatus_->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        leRestartRemoteStatus_ = new QLineEdit(groupBox_2);
        leRestartRemoteStatus_->setObjectName(QString::fromUtf8("leRestartRemoteStatus_"));
        leRestartRemoteStatus_->setGeometry(QRect(380, 110, 35, 20));
        leRestartRemoteStatus_->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        leClearFlashStatus_ = new QLineEdit(groupBox_2);
        leClearFlashStatus_->setObjectName(QString::fromUtf8("leClearFlashStatus_"));
        leClearFlashStatus_->setGeometry(QRect(380, 30, 35, 20));
        leClearFlashStatus_->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        leModeStatus_ = new QLineEdit(groupBox_2);
        leModeStatus_->setObjectName(QString::fromUtf8("leModeStatus_"));
        leModeStatus_->setGeometry(QRect(380, 190, 35, 20));
        leModeStatus_->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        leFileVersionStatus_ = new QLineEdit(groupBox_2);
        leFileVersionStatus_->setObjectName(QString::fromUtf8("leFileVersionStatus_"));
        leFileVersionStatus_->setGeometry(QRect(380, 230, 35, 20));
        leFileVersionStatus_->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        leStartedAsStatus_ = new QLineEdit(groupBox_2);
        leStartedAsStatus_->setObjectName(QString::fromUtf8("leStartedAsStatus_"));
        leStartedAsStatus_->setGeometry(QRect(380, 150, 35, 20));
        leStartedAsStatus_->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        label_6 = new QLabel(SoftwareOperationWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(390, 210, 32, 16));
        label_6->setFont(font2);
        pbOK = new QPushButton(SoftwareOperationWidget);
        pbOK->setObjectName(QString::fromUtf8("pbOK"));
        pbOK->setGeometry(QRect(300, 560, 91, 31));

        retranslateUi(SoftwareOperationWidget);

        QMetaObject::connectSlotsByName(SoftwareOperationWidget);
    } // setupUi

    void retranslateUi(QWidget *SoftwareOperationWidget)
    {
        SoftwareOperationWidget->setWindowTitle(QApplication::translate("SoftwareOperationWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SoftwareOperationWidget", "\346\223\215\344\275\234\347\273\210\347\253\257", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SoftwareOperationWidget", "Shut Down this Operator Terminal", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SoftwareOperationWidget", "Restart this Operator Terminal", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SoftwareOperationWidget", "Upgrade From Remote Control Unit", 0, QApplication::UnicodeUTF8));
        leShutDown_->setText(QApplication::translate("SoftwareOperationWidget", "No", 0, QApplication::UnicodeUTF8));
        leRestartThis_->setText(QApplication::translate("SoftwareOperationWidget", "No", 0, QApplication::UnicodeUTF8));
        leUpgradeRemote_->setText(QApplication::translate("SoftwareOperationWidget", "No", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SoftwareOperationWidget", "\350\275\257\344\273\266\345\215\207\347\272\247\345\222\214\347\263\273\347\273\237\351\207\215\345\220\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SoftwareOperationWidget", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SoftwareOperationWidget", "\350\277\234\347\250\213\346\216\247\345\210\266\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SoftwareOperationWidget", "Clear Flash", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SoftwareOperationWidget", "Upgrade Flash From this Terminal", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SoftwareOperationWidget", "Restart Remote Control Unit", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SoftwareOperationWidget", "File Version Match", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SoftwareOperationWidget", "Started as a Flash System", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SoftwareOperationWidget", "Mode swith Normal", 0, QApplication::UnicodeUTF8));
        leUpgradeFlash_->setText(QApplication::translate("SoftwareOperationWidget", "No", 0, QApplication::UnicodeUTF8));
        leRestartRemote_->setText(QApplication::translate("SoftwareOperationWidget", "No", 0, QApplication::UnicodeUTF8));
        leClearFlash_->setText(QApplication::translate("SoftwareOperationWidget", "No", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SoftwareOperationWidget", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        pbOK->setText(QApplication::translate("SoftwareOperationWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SoftwareOperationWidget: public Ui_SoftwareOperationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTWAREOPERATIONWIDGET_H
