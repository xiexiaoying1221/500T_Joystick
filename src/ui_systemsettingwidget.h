/********************************************************************************
** Form generated from reading UI file 'systemsettingwidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSETTINGWIDGET_H
#define UI_SYSTEMSETTINGWIDGET_H

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

class Ui_SystemSettingWidget
{
public:
    QPushButton *pbOk;
    QLineEdit *leHour_;
    QLineEdit *leMinute_;
    QLineEdit *leSecond_;
    QLineEdit *leDay_;
    QLineEdit *leMonth_;
    QLineEdit *leYear_;
    QPushButton *pbOK;
    QPushButton *pbCancel;
    QLineEdit *leClose_;
    QLineEdit *leRestart_;
    QGroupBox *groupBox;
    QPushButton *pb5;
    QPushButton *gbpbCancel;
    QPushButton *gbpbOK;
    QPushButton *pb6;
    QPushButton *pb4;
    QPushButton *pb9;
    QPushButton *pb0;
    QPushButton *pb7;
    QPushButton *pb8;
    QPushButton *pb1;
    QPushButton *pb2;
    QPushButton *pb3;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *SystemSettingWidget)
    {
        if (SystemSettingWidget->objectName().isEmpty())
            SystemSettingWidget->setObjectName(QString::fromUtf8("SystemSettingWidget"));
        SystemSettingWidget->resize(438, 710);
        pbOk = new QPushButton(SystemSettingWidget);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));
        pbOk->setGeometry(QRect(120, 593, 90, 40));
        QFont font;
        font.setPointSize(12);
        pbOk->setFont(font);
        pbOk->setFocusPolicy(Qt::NoFocus);
        pbOk->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leHour_ = new QLineEdit(SystemSettingWidget);
        leHour_->setObjectName(QString::fromUtf8("leHour_"));
        leHour_->setGeometry(QRect(265, 110, 90, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        leHour_->setFont(font1);
        leHour_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leMinute_ = new QLineEdit(SystemSettingWidget);
        leMinute_->setObjectName(QString::fromUtf8("leMinute_"));
        leMinute_->setGeometry(QRect(265, 162, 90, 40));
        leMinute_->setFont(font1);
        leMinute_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leSecond_ = new QLineEdit(SystemSettingWidget);
        leSecond_->setObjectName(QString::fromUtf8("leSecond_"));
        leSecond_->setGeometry(QRect(265, 213, 90, 40));
        leSecond_->setFont(font1);
        leSecond_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leDay_ = new QLineEdit(SystemSettingWidget);
        leDay_->setObjectName(QString::fromUtf8("leDay_"));
        leDay_->setGeometry(QRect(105, 215, 90, 40));
        leDay_->setFont(font1);
        leDay_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leMonth_ = new QLineEdit(SystemSettingWidget);
        leMonth_->setObjectName(QString::fromUtf8("leMonth_"));
        leMonth_->setGeometry(QRect(105, 161, 91, 41));
        leMonth_->setFont(font1);
        leMonth_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leYear_ = new QLineEdit(SystemSettingWidget);
        leYear_->setObjectName(QString::fromUtf8("leYear_"));
        leYear_->setGeometry(QRect(105, 110, 90, 40));
        leYear_->setFont(font1);
        leYear_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        pbOK = new QPushButton(SystemSettingWidget);
        pbOK->setObjectName(QString::fromUtf8("pbOK"));
        pbOK->setGeometry(QRect(300, 820, 91, 31));
        pbCancel = new QPushButton(SystemSettingWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(240, 593, 90, 40));
        pbCancel->setFont(font);
        pbCancel->setFocusPolicy(Qt::NoFocus);
        pbCancel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leClose_ = new QLineEdit(SystemSettingWidget);
        leClose_->setObjectName(QString::fromUtf8("leClose_"));
        leClose_->setGeometry(QRect(265, 380, 56, 35));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leClose_->sizePolicy().hasHeightForWidth());
        leClose_->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
        font2.setPointSize(16);
        leClose_->setFont(font2);
        leClose_->setAutoFillBackground(false);
        leClose_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leClose_->setAlignment(Qt::AlignCenter);
        leClose_->setReadOnly(true);
        leRestart_ = new QLineEdit(SystemSettingWidget);
        leRestart_->setObjectName(QString::fromUtf8("leRestart_"));
        leRestart_->setGeometry(QRect(265, 430, 56, 35));
        sizePolicy.setHeightForWidth(leRestart_->sizePolicy().hasHeightForWidth());
        leRestart_->setSizePolicy(sizePolicy);
        leRestart_->setFont(font2);
        leRestart_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leRestart_->setAlignment(Qt::AlignCenter);
        leRestart_->setReadOnly(true);
        groupBox = new QGroupBox(SystemSettingWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(70, 10, 311, 91));
        groupBox->setAutoFillBackground(true);
        pb5 = new QPushButton(groupBox);
        pb5->setObjectName(QString::fromUtf8("pb5"));
        pb5->setGeometry(QRect(210, 10, 41, 31));
        gbpbCancel = new QPushButton(groupBox);
        gbpbCancel->setObjectName(QString::fromUtf8("gbpbCancel"));
        gbpbCancel->setGeometry(QRect(210, 50, 41, 31));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        gbpbCancel->setFont(font3);
        gbpbOK = new QPushButton(groupBox);
        gbpbOK->setObjectName(QString::fromUtf8("gbpbOK"));
        gbpbOK->setGeometry(QRect(260, 50, 41, 31));
        gbpbOK->setFont(font3);
        pb6 = new QPushButton(groupBox);
        pb6->setObjectName(QString::fromUtf8("pb6"));
        pb6->setGeometry(QRect(260, 10, 41, 31));
        pb4 = new QPushButton(groupBox);
        pb4->setObjectName(QString::fromUtf8("pb4"));
        pb4->setGeometry(QRect(160, 10, 41, 31));
        pb9 = new QPushButton(groupBox);
        pb9->setObjectName(QString::fromUtf8("pb9"));
        pb9->setGeometry(QRect(110, 10, 41, 31));
        pb0 = new QPushButton(groupBox);
        pb0->setObjectName(QString::fromUtf8("pb0"));
        pb0->setGeometry(QRect(160, 50, 41, 31));
        pb7 = new QPushButton(groupBox);
        pb7->setObjectName(QString::fromUtf8("pb7"));
        pb7->setGeometry(QRect(10, 10, 41, 31));
        pb8 = new QPushButton(groupBox);
        pb8->setObjectName(QString::fromUtf8("pb8"));
        pb8->setGeometry(QRect(60, 10, 41, 31));
        pb1 = new QPushButton(groupBox);
        pb1->setObjectName(QString::fromUtf8("pb1"));
        pb1->setGeometry(QRect(10, 50, 41, 31));
        pb2 = new QPushButton(groupBox);
        pb2->setObjectName(QString::fromUtf8("pb2"));
        pb2->setGeometry(QRect(60, 50, 41, 31));
        pb3 = new QPushButton(groupBox);
        pb3->setObjectName(QString::fromUtf8("pb3"));
        pb3->setGeometry(QRect(110, 50, 41, 31));
        label_1 = new QLabel(SystemSettingWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(20, 120, 71, 21));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(SystemSettingWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 175, 61, 21));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(SystemSettingWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 225, 61, 21));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(SystemSettingWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 120, 61, 21));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(SystemSettingWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 175, 61, 21));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(SystemSettingWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(190, 225, 61, 21));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(SystemSettingWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 330, 101, 31));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(SystemSettingWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 380, 191, 31));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(SystemSettingWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 430, 191, 31));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(SystemSettingWidget);

        QMetaObject::connectSlotsByName(SystemSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *SystemSettingWidget)
    {
        SystemSettingWidget->setWindowTitle(QApplication::translate("SystemSettingWidget", "Form", 0, QApplication::UnicodeUTF8));
        pbOk->setText(QApplication::translate("SystemSettingWidget", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        leYear_->setText(QString());
        pbOK->setText(QApplication::translate("SystemSettingWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pbCancel->setText(QApplication::translate("SystemSettingWidget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        leClose_->setText(QString());
        leRestart_->setText(QString());
        groupBox->setTitle(QString());
        pb5->setText(QApplication::translate("SystemSettingWidget", "5", 0, QApplication::UnicodeUTF8));
        gbpbCancel->setText(QApplication::translate("SystemSettingWidget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        gbpbOK->setText(QApplication::translate("SystemSettingWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pb6->setText(QApplication::translate("SystemSettingWidget", "6", 0, QApplication::UnicodeUTF8));
        pb4->setText(QApplication::translate("SystemSettingWidget", "4", 0, QApplication::UnicodeUTF8));
        pb9->setText(QApplication::translate("SystemSettingWidget", "9", 0, QApplication::UnicodeUTF8));
        pb0->setText(QApplication::translate("SystemSettingWidget", "0", 0, QApplication::UnicodeUTF8));
        pb7->setText(QApplication::translate("SystemSettingWidget", "7", 0, QApplication::UnicodeUTF8));
        pb8->setText(QApplication::translate("SystemSettingWidget", "8", 0, QApplication::UnicodeUTF8));
        pb1->setText(QApplication::translate("SystemSettingWidget", "1", 0, QApplication::UnicodeUTF8));
        pb2->setText(QApplication::translate("SystemSettingWidget", "2", 0, QApplication::UnicodeUTF8));
        pb3->setText(QApplication::translate("SystemSettingWidget", "3", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("SystemSettingWidget", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SystemSettingWidget", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SystemSettingWidget", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SystemSettingWidget", "\346\227\266", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SystemSettingWidget", "\345\210\206", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SystemSettingWidget", "\347\247\222", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SystemSettingWidget", "\345\205\263\351\227\255\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SystemSettingWidget", "\345\205\263\351\227\255\346\255\244\346\223\215\344\275\234\347\273\210\347\253\257", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SystemSettingWidget", "\351\207\215\345\220\257\346\255\244\346\223\215\344\275\234\347\273\210\347\253\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemSettingWidget: public Ui_SystemSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTINGWIDGET_H
