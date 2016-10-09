/********************************************************************************
** Form generated from reading UI file 'generalsettingwidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSETTINGWIDGET_H
#define UI_GENERALSETTINGWIDGET_H

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

class Ui_GeneralSettingWidget
{
public:
    QPushButton *pbOk;
    QLineEdit *leDraughtType_;
    QLineEdit *leThrusterAlloc_;
    QLineEdit *leGainLevel_;
    QLineEdit *leWindComp_;
    QPushButton *pbCancel;
    QGroupBox *groupBox;
    QPushButton *pb5;
    QPushButton *pb2;
    QPushButton *pbPoint;
    QPushButton *gbpbOK;
    QPushButton *pb6;
    QPushButton *pb3;
    QPushButton *pb4;
    QPushButton *pb9;
    QPushButton *pb0;
    QPushButton *pb7;
    QPushButton *pb1;
    QPushButton *pb8;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *leThrusterAlloc_1;
    QLineEdit *leRateTurn_;

    void setupUi(QWidget *GeneralSettingWidget)
    {
        if (GeneralSettingWidget->objectName().isEmpty())
            GeneralSettingWidget->setObjectName(QString::fromUtf8("GeneralSettingWidget"));
        GeneralSettingWidget->resize(454, 768);
        GeneralSettingWidget->setAutoFillBackground(false);
        pbOk = new QPushButton(GeneralSettingWidget);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));
        pbOk->setGeometry(QRect(120, 593, 91, 41));
        QFont font;
        font.setPointSize(16);
        pbOk->setFont(font);
        pbOk->setFocusPolicy(Qt::NoFocus);
        pbOk->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leDraughtType_ = new QLineEdit(GeneralSettingWidget);
        leDraughtType_->setObjectName(QString::fromUtf8("leDraughtType_"));
        leDraughtType_->setGeometry(QRect(235, 360, 131, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        leDraughtType_->setFont(font1);
        leDraughtType_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leDraughtType_->setAlignment(Qt::AlignCenter);
        leThrusterAlloc_ = new QLineEdit(GeneralSettingWidget);
        leThrusterAlloc_->setObjectName(QString::fromUtf8("leThrusterAlloc_"));
        leThrusterAlloc_->setGeometry(QRect(237, 117, 131, 41));
        leThrusterAlloc_->setFont(font1);
        leThrusterAlloc_->setAutoFillBackground(false);
        leThrusterAlloc_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leThrusterAlloc_->setAlignment(Qt::AlignCenter);
        leGainLevel_ = new QLineEdit(GeneralSettingWidget);
        leGainLevel_->setObjectName(QString::fromUtf8("leGainLevel_"));
        leGainLevel_->setGeometry(QRect(235, 300, 91, 40));
        leGainLevel_->setFont(font1);
        leGainLevel_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leGainLevel_->setAlignment(Qt::AlignCenter);
        leWindComp_ = new QLineEdit(GeneralSettingWidget);
        leWindComp_->setObjectName(QString::fromUtf8("leWindComp_"));
        leWindComp_->setGeometry(QRect(235, 240, 85, 40));
        leWindComp_->setFont(font1);
        leWindComp_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leWindComp_->setAlignment(Qt::AlignCenter);
        pbCancel = new QPushButton(GeneralSettingWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(240, 593, 91, 41));
        pbCancel->setFont(font);
        pbCancel->setFocusPolicy(Qt::NoFocus);
        pbCancel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        groupBox = new QGroupBox(GeneralSettingWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(280, 230, 161, 171));
        groupBox->setAutoFillBackground(true);
        pb5 = new QPushButton(groupBox);
        pb5->setObjectName(QString::fromUtf8("pb5"));
        pb5->setGeometry(QRect(60, 50, 41, 31));
        pb2 = new QPushButton(groupBox);
        pb2->setObjectName(QString::fromUtf8("pb2"));
        pb2->setGeometry(QRect(60, 90, 41, 31));
        pbPoint = new QPushButton(groupBox);
        pbPoint->setObjectName(QString::fromUtf8("pbPoint"));
        pbPoint->setGeometry(QRect(60, 130, 41, 31));
        gbpbOK = new QPushButton(groupBox);
        gbpbOK->setObjectName(QString::fromUtf8("gbpbOK"));
        gbpbOK->setGeometry(QRect(110, 130, 41, 31));
        pb6 = new QPushButton(groupBox);
        pb6->setObjectName(QString::fromUtf8("pb6"));
        pb6->setGeometry(QRect(110, 50, 41, 31));
        pb3 = new QPushButton(groupBox);
        pb3->setObjectName(QString::fromUtf8("pb3"));
        pb3->setGeometry(QRect(110, 90, 41, 31));
        pb4 = new QPushButton(groupBox);
        pb4->setObjectName(QString::fromUtf8("pb4"));
        pb4->setGeometry(QRect(10, 50, 41, 31));
        pb9 = new QPushButton(groupBox);
        pb9->setObjectName(QString::fromUtf8("pb9"));
        pb9->setGeometry(QRect(110, 10, 41, 31));
        pb0 = new QPushButton(groupBox);
        pb0->setObjectName(QString::fromUtf8("pb0"));
        pb0->setGeometry(QRect(10, 130, 41, 31));
        pb7 = new QPushButton(groupBox);
        pb7->setObjectName(QString::fromUtf8("pb7"));
        pb7->setGeometry(QRect(10, 10, 41, 31));
        pb1 = new QPushButton(groupBox);
        pb1->setObjectName(QString::fromUtf8("pb1"));
        pb1->setGeometry(QRect(10, 90, 41, 31));
        pb8 = new QPushButton(groupBox);
        pb8->setObjectName(QString::fromUtf8("pb8"));
        pb8->setGeometry(QRect(60, 10, 41, 31));
        label_1 = new QLabel(GeneralSettingWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(40, 117, 171, 41));
        label_1->setAutoFillBackground(false);
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(GeneralSettingWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 180, 171, 41));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(GeneralSettingWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 240, 171, 41));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(GeneralSettingWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 300, 171, 41));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(GeneralSettingWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 360, 171, 41));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leThrusterAlloc_1 = new QLineEdit(GeneralSettingWidget);
        leThrusterAlloc_1->setObjectName(QString::fromUtf8("leThrusterAlloc_1"));
        leThrusterAlloc_1->setGeometry(QRect(320, 230, 131, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
        font2.setPointSize(12);
        leThrusterAlloc_1->setFont(font2);
        leThrusterAlloc_1->setAutoFillBackground(false);
        leThrusterAlloc_1->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leThrusterAlloc_1->setAlignment(Qt::AlignCenter);
        leRateTurn_ = new QLineEdit(GeneralSettingWidget);
        leRateTurn_->setObjectName(QString::fromUtf8("leRateTurn_"));
        leRateTurn_->setGeometry(QRect(235, 180, 85, 40));
        leRateTurn_->setFont(font1);
        leRateTurn_->setAutoFillBackground(false);
        leRateTurn_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leRateTurn_->setAlignment(Qt::AlignCenter);
        leWindComp_->raise();
        leRateTurn_->raise();
        leGainLevel_->raise();
        leDraughtType_->raise();
        leThrusterAlloc_->raise();
        pbOk->raise();
        pbCancel->raise();
        groupBox->raise();
        label_1->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        leThrusterAlloc_1->raise();

        retranslateUi(GeneralSettingWidget);

        QMetaObject::connectSlotsByName(GeneralSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *GeneralSettingWidget)
    {
        GeneralSettingWidget->setWindowTitle(QApplication::translate("GeneralSettingWidget", "Form", 0, QApplication::UnicodeUTF8));
        pbOk->setText(QString());
        leDraughtType_->setText(QString());
        leThrusterAlloc_->setText(QString());
        leGainLevel_->setText(QString());
        leWindComp_->setText(QString());
        pbCancel->setText(QString());
        groupBox->setTitle(QString());
        pb5->setText(QApplication::translate("GeneralSettingWidget", "5", 0, QApplication::UnicodeUTF8));
        pb2->setText(QApplication::translate("GeneralSettingWidget", "2", 0, QApplication::UnicodeUTF8));
        pbPoint->setText(QApplication::translate("GeneralSettingWidget", "\357\274\216", 0, QApplication::UnicodeUTF8));
        gbpbOK->setText(QApplication::translate("GeneralSettingWidget", "\357\274\257\357\274\253", 0, QApplication::UnicodeUTF8));
        pb6->setText(QApplication::translate("GeneralSettingWidget", "6", 0, QApplication::UnicodeUTF8));
        pb3->setText(QApplication::translate("GeneralSettingWidget", "3", 0, QApplication::UnicodeUTF8));
        pb4->setText(QApplication::translate("GeneralSettingWidget", "4", 0, QApplication::UnicodeUTF8));
        pb9->setText(QApplication::translate("GeneralSettingWidget", "9", 0, QApplication::UnicodeUTF8));
        pb0->setText(QApplication::translate("GeneralSettingWidget", "0", 0, QApplication::UnicodeUTF8));
        pb7->setText(QApplication::translate("GeneralSettingWidget", "7", 0, QApplication::UnicodeUTF8));
        pb1->setText(QApplication::translate("GeneralSettingWidget", "1", 0, QApplication::UnicodeUTF8));
        pb8->setText(QApplication::translate("GeneralSettingWidget", "8", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("GeneralSettingWidget", "\346\216\250\345\212\233\345\210\206\351\205\215\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GeneralSettingWidget", "\350\256\276\345\200\274\345\233\236\350\275\254\347\216\207", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GeneralSettingWidget", "\351\243\216\345\212\233\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GeneralSettingWidget", "\345\242\236\347\233\212\347\255\211\347\272\247", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GeneralSettingWidget", "\350\210\271\350\210\266\345\220\203\346\260\264\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        leThrusterAlloc_1->setText(QString());
        leRateTurn_->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GeneralSettingWidget: public Ui_GeneralSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSETTINGWIDGET_H
