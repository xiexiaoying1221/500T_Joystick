/********************************************************************************
** Form generated from reading UI file 'alarmlistwidget.ui'
**
** Created: Sat Oct 8 15:51:50 2016
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMLISTWIDGET_H
#define UI_ALARMLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmListWidget
{
public:
    QTableView *alarm_tableView;

    void setupUi(QWidget *AlarmListWidget)
    {
        if (AlarmListWidget->objectName().isEmpty())
            AlarmListWidget->setObjectName(QString::fromUtf8("AlarmListWidget"));
        AlarmListWidget->resize(1024, 768);
        alarm_tableView = new QTableView(AlarmListWidget);
        alarm_tableView->setObjectName(QString::fromUtf8("alarm_tableView"));
        alarm_tableView->setEnabled(false);
        alarm_tableView->setGeometry(QRect(19, 40, 991, 760));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        alarm_tableView->setFont(font);
        alarm_tableView->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(AlarmListWidget);

        QMetaObject::connectSlotsByName(AlarmListWidget);
    } // setupUi

    void retranslateUi(QWidget *AlarmListWidget)
    {
        AlarmListWidget->setWindowTitle(QApplication::translate("AlarmListWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AlarmListWidget: public Ui_AlarmListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMLISTWIDGET_H
