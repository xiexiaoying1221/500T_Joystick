/********************************************************************************
** Form generated from reading UI file 'limitsetwidget.ui'
**
** Created: Sat Oct 8 15:51:50 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIMITSETWIDGET_H
#define UI_LIMITSETWIDGET_H

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

class Ui_limitSetWidget
{
public:
    QPushButton *pbOk;
    QLineEdit *leHeadWarnActive_;
    QLineEdit *leHeadWarnLimit_;
    QLineEdit *leHeadAlarmActive_;
    QLineEdit *leHeadAlarmLimit_;
    QPushButton *pbCancel;
    QLabel *label_1;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *limitSetWidget)
    {
        if (limitSetWidget->objectName().isEmpty())
            limitSetWidget->setObjectName(QString::fromUtf8("limitSetWidget"));
        limitSetWidget->resize(438, 710);
        pbOk = new QPushButton(limitSetWidget);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));
        pbOk->setGeometry(QRect(120, 593, 91, 38));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
        font.setPointSize(16);
        pbOk->setFont(font);
        pbOk->setFocusPolicy(Qt::NoFocus);
        pbOk->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leHeadWarnActive_ = new QLineEdit(limitSetWidget);
        leHeadWarnActive_->setObjectName(QString::fromUtf8("leHeadWarnActive_"));
        leHeadWarnActive_->setGeometry(QRect(147, 167, 52, 34));
        leHeadWarnActive_->setFont(font);
        leHeadWarnActive_->setContextMenuPolicy(Qt::NoContextMenu);
        leHeadWarnActive_->setAutoFillBackground(false);
        leHeadWarnActive_->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leHeadWarnActive_->setFrame(true);
        leHeadWarnActive_->setAlignment(Qt::AlignCenter);
        leHeadWarnActive_->setReadOnly(true);
        leHeadWarnLimit_ = new QLineEdit(limitSetWidget);
        leHeadWarnLimit_->setObjectName(QString::fromUtf8("leHeadWarnLimit_"));
        leHeadWarnLimit_->setGeometry(QRect(250, 166, 82, 36));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leHeadWarnLimit_->sizePolicy().hasHeightForWidth());
        leHeadWarnLimit_->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        leHeadWarnLimit_->setFont(font1);
        leHeadWarnLimit_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leHeadWarnLimit_->setAlignment(Qt::AlignCenter);
        leHeadWarnLimit_->setReadOnly(true);
        leHeadAlarmActive_ = new QLineEdit(limitSetWidget);
        leHeadAlarmActive_->setObjectName(QString::fromUtf8("leHeadAlarmActive_"));
        leHeadAlarmActive_->setGeometry(QRect(147, 217, 52, 34));
        leHeadAlarmActive_->setFont(font);
        leHeadAlarmActive_->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-width:0;\n"
"border-style:outset;"));
        leHeadAlarmActive_->setAlignment(Qt::AlignCenter);
        leHeadAlarmActive_->setDragEnabled(false);
        leHeadAlarmActive_->setReadOnly(true);
        leHeadAlarmLimit_ = new QLineEdit(limitSetWidget);
        leHeadAlarmLimit_->setObjectName(QString::fromUtf8("leHeadAlarmLimit_"));
        leHeadAlarmLimit_->setGeometry(QRect(250, 215, 82, 36));
        sizePolicy.setHeightForWidth(leHeadAlarmLimit_->sizePolicy().hasHeightForWidth());
        leHeadAlarmLimit_->setSizePolicy(sizePolicy);
        leHeadAlarmLimit_->setFont(font1);
        leHeadAlarmLimit_->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        leHeadAlarmLimit_->setAlignment(Qt::AlignCenter);
        leHeadAlarmLimit_->setReadOnly(true);
        pbCancel = new QPushButton(limitSetWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(240, 593, 91, 38));
        pbCancel->setFont(font);
        pbCancel->setFocusPolicy(Qt::NoFocus);
        pbCancel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        label_1 = new QLabel(limitSetWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(60, 95, 81, 31));
        label_1->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(limitSetWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 170, 71, 31));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(limitSetWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 218, 71, 31));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(limitSetWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(140, 128, 61, 31));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(limitSetWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(260, 128, 61, 31));
        label_10->setAlignment(Qt::AlignCenter);

        retranslateUi(limitSetWidget);

        QMetaObject::connectSlotsByName(limitSetWidget);
    } // setupUi

    void retranslateUi(QWidget *limitSetWidget)
    {
        limitSetWidget->setWindowTitle(QApplication::translate("limitSetWidget", "Form", 0, QApplication::UnicodeUTF8));
        pbOk->setText(QString());
        leHeadWarnActive_->setText(QString());
        leHeadWarnLimit_->setText(QString());
        leHeadAlarmActive_->setText(QString());
        leHeadAlarmLimit_->setText(QString());
        pbCancel->setText(QString());
        label_1->setText(QApplication::translate("limitSetWidget", " \350\211\217\345\220\221\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("limitSetWidget", "\350\255\246\345\221\212", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("limitSetWidget", "\350\255\246\345\221\212", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("limitSetWidget", "\345\220\257\347\224\250", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("limitSetWidget", "\345\220\257\347\224\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class limitSetWidget: public Ui_limitSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIMITSETWIDGET_H
