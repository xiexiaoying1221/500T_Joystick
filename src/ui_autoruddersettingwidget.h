/********************************************************************************
** Form generated from reading UI file 'autoruddersettingwidget.ui'
**
** Created: Sat Oct 8 15:51:51 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORUDDERSETTINGWIDGET_H
#define UI_AUTORUDDERSETTINGWIDGET_H

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

class Ui_AutoRudderSettingWidget
{
public:
    QLineEdit *leWeather_;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *leGainLevel_;
    QGroupBox *groupBox;
    QPushButton *pb8;
    QPushButton *pb2;
    QPushButton *pb6;
    QPushButton *pb3;
    QPushButton *pb9;
    QPushButton *pb7;
    QPushButton *pb0;
    QPushButton *pbPoint;
    QPushButton *pb5;
    QPushButton *pb4;
    QPushButton *pb1;
    QPushButton *pbOK;
    QLineEdit *leAutoTrim_;
    QLabel *label_3;
    QLineEdit *leCounterRudder_;
    QLabel *label_2;
    QLabel *label_7;
    QLineEdit *leRateTurn_;

    void setupUi(QWidget *AutoRudderSettingWidget)
    {
        if (AutoRudderSettingWidget->objectName().isEmpty())
            AutoRudderSettingWidget->setObjectName(QString::fromUtf8("AutoRudderSettingWidget"));
        AutoRudderSettingWidget->resize(456, 768);
        leWeather_ = new QLineEdit(AutoRudderSettingWidget);
        leWeather_->setObjectName(QString::fromUtf8("leWeather_"));
        leWeather_->setGeometry(QRect(170, 260, 120, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
        font.setPointSize(16);
        leWeather_->setFont(font);
        leWeather_->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        leWeather_->setAlignment(Qt::AlignCenter);
        label = new QLabel(AutoRudderSettingWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(12, 50, 141, 41));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(AutoRudderSettingWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-28, 200, 181, 21));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(AutoRudderSettingWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 500, 91, 31));
        QFont font1;
        font1.setPointSize(16);
        pushButton->setFont(font1);
        label_5 = new QLabel(AutoRudderSettingWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(32, 260, 121, 31));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leGainLevel_ = new QLineEdit(AutoRudderSettingWidget);
        leGainLevel_->setObjectName(QString::fromUtf8("leGainLevel_"));
        leGainLevel_->setGeometry(QRect(170, 50, 121, 40));
        leGainLevel_->setFont(font);
        leGainLevel_->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        leGainLevel_->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(AutoRudderSettingWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(290, 330, 161, 171));
        groupBox->setAutoFillBackground(false);
        pb8 = new QPushButton(groupBox);
        pb8->setObjectName(QString::fromUtf8("pb8"));
        pb8->setGeometry(QRect(60, 10, 41, 31));
        pb2 = new QPushButton(groupBox);
        pb2->setObjectName(QString::fromUtf8("pb2"));
        pb2->setGeometry(QRect(60, 90, 41, 31));
        pb6 = new QPushButton(groupBox);
        pb6->setObjectName(QString::fromUtf8("pb6"));
        pb6->setGeometry(QRect(110, 50, 41, 31));
        pb3 = new QPushButton(groupBox);
        pb3->setObjectName(QString::fromUtf8("pb3"));
        pb3->setGeometry(QRect(110, 90, 41, 31));
        pb9 = new QPushButton(groupBox);
        pb9->setObjectName(QString::fromUtf8("pb9"));
        pb9->setGeometry(QRect(110, 10, 41, 31));
        pb7 = new QPushButton(groupBox);
        pb7->setObjectName(QString::fromUtf8("pb7"));
        pb7->setGeometry(QRect(10, 10, 41, 31));
        pb0 = new QPushButton(groupBox);
        pb0->setObjectName(QString::fromUtf8("pb0"));
        pb0->setGeometry(QRect(10, 130, 41, 31));
        pbPoint = new QPushButton(groupBox);
        pbPoint->setObjectName(QString::fromUtf8("pbPoint"));
        pbPoint->setGeometry(QRect(60, 130, 41, 31));
        pb5 = new QPushButton(groupBox);
        pb5->setObjectName(QString::fromUtf8("pb5"));
        pb5->setGeometry(QRect(60, 50, 41, 31));
        pb4 = new QPushButton(groupBox);
        pb4->setObjectName(QString::fromUtf8("pb4"));
        pb4->setGeometry(QRect(10, 50, 41, 31));
        pb1 = new QPushButton(groupBox);
        pb1->setObjectName(QString::fromUtf8("pb1"));
        pb1->setGeometry(QRect(10, 90, 41, 31));
        pbOK = new QPushButton(groupBox);
        pbOK->setObjectName(QString::fromUtf8("pbOK"));
        pbOK->setGeometry(QRect(110, 130, 41, 31));
        leAutoTrim_ = new QLineEdit(AutoRudderSettingWidget);
        leAutoTrim_->setObjectName(QString::fromUtf8("leAutoTrim_"));
        leAutoTrim_->setGeometry(QRect(170, 190, 120, 40));
        leAutoTrim_->setFont(font);
        leAutoTrim_->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(AutoRudderSettingWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(42, 130, 111, 21));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leCounterRudder_ = new QLineEdit(AutoRudderSettingWidget);
        leCounterRudder_->setObjectName(QString::fromUtf8("leCounterRudder_"));
        leCounterRudder_->setGeometry(QRect(170, 120, 121, 40));
        leCounterRudder_->setFont(font);
        leCounterRudder_->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(AutoRudderSettingWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(82, 340, 71, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(AutoRudderSettingWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(290, 325, 61, 35));
        label_7->setFont(font);
        leRateTurn_ = new QLineEdit(AutoRudderSettingWidget);
        leRateTurn_->setObjectName(QString::fromUtf8("leRateTurn_"));
        leRateTurn_->setGeometry(QRect(170, 330, 121, 40));
        leRateTurn_->setFont(font);
        leRateTurn_->setAlignment(Qt::AlignCenter);
        leWeather_->raise();
        label->raise();
        label_4->raise();
        pushButton->raise();
        label_5->raise();
        leGainLevel_->raise();
        leAutoTrim_->raise();
        label_3->raise();
        leCounterRudder_->raise();
        label_2->raise();
        label_7->raise();
        leRateTurn_->raise();
        groupBox->raise();

        retranslateUi(AutoRudderSettingWidget);

        QMetaObject::connectSlotsByName(AutoRudderSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *AutoRudderSettingWidget)
    {
        AutoRudderSettingWidget->setWindowTitle(QApplication::translate("AutoRudderSettingWidget", "Form", 0, QApplication::UnicodeUTF8));
        leWeather_->setText(QApplication::translate("AutoRudderSettingWidget", "On", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AutoRudderSettingWidget", "\345\242\236\347\233\212\346\260\264\345\271\263", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AutoRudderSettingWidget", "\350\207\252\345\212\250\350\210\265\347\272\265\345\200\276\344\277\256\346\255\243", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AutoRudderSettingWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AutoRudderSettingWidget", "\347\216\257\345\242\203\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        leGainLevel_->setText(QApplication::translate("AutoRudderSettingWidget", "Med", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        pb8->setText(QApplication::translate("AutoRudderSettingWidget", "8", 0, QApplication::UnicodeUTF8));
        pb2->setText(QApplication::translate("AutoRudderSettingWidget", "2", 0, QApplication::UnicodeUTF8));
        pb6->setText(QApplication::translate("AutoRudderSettingWidget", "6", 0, QApplication::UnicodeUTF8));
        pb3->setText(QApplication::translate("AutoRudderSettingWidget", "3", 0, QApplication::UnicodeUTF8));
        pb9->setText(QApplication::translate("AutoRudderSettingWidget", "9", 0, QApplication::UnicodeUTF8));
        pb7->setText(QApplication::translate("AutoRudderSettingWidget", "7", 0, QApplication::UnicodeUTF8));
        pb0->setText(QApplication::translate("AutoRudderSettingWidget", "0", 0, QApplication::UnicodeUTF8));
        pbPoint->setText(QApplication::translate("AutoRudderSettingWidget", "\357\274\216", 0, QApplication::UnicodeUTF8));
        pb5->setText(QApplication::translate("AutoRudderSettingWidget", "5", 0, QApplication::UnicodeUTF8));
        pb4->setText(QApplication::translate("AutoRudderSettingWidget", "4", 0, QApplication::UnicodeUTF8));
        pb1->setText(QApplication::translate("AutoRudderSettingWidget", "1", 0, QApplication::UnicodeUTF8));
        pbOK->setText(QApplication::translate("AutoRudderSettingWidget", "\357\274\257\357\274\253", 0, QApplication::UnicodeUTF8));
        leAutoTrim_->setText(QApplication::translate("AutoRudderSettingWidget", "100.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AutoRudderSettingWidget", "\345\233\236\350\210\265\345\242\236\347\233\212", 0, QApplication::UnicodeUTF8));
        leCounterRudder_->setText(QApplication::translate("AutoRudderSettingWidget", "100.0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AutoRudderSettingWidget", "\345\233\236\350\275\254\347\216\207", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AutoRudderSettingWidget", "\302\260/min", 0, QApplication::UnicodeUTF8));
        leRateTurn_->setText(QApplication::translate("AutoRudderSettingWidget", "10.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AutoRudderSettingWidget: public Ui_AutoRudderSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORUDDERSETTINGWIDGET_H
