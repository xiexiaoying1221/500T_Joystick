#ifndef PROMPTWIDGETUSRNEW_H
#define PROMPTWIDGETUSRNEW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QTimer>
#include <QComboBox>
#include "globalSettings.h"
#include "usrmanager.h"

class PromptWidgetUsrNew : public QWidget
{
    Q_OBJECT
public:
    PromptWidgetUsrNew(QWidget *parent=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickOk();
    void clickCancel();

signals:
    void promptFinished(void);

private:
    QLabel* _lblName;
    QLabel* _lblPswd;
    QLabel* _lblRepeatPswd;
    QLabel* _lblLevel;

    QLineEdit* _leName;
    QLineEdit* _lePswd;
    QLineEdit* _leRepeatPswd;
    QComboBox* _cbxLevel;

    QPushButton *_pbCancel;
    QPushButton *_pbOK;

    UsrManager *_manager;

protected:
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);

public:
    void changeDNMode();
    void Refresh_changless_words();

    void initWidget();
};

#endif // PROMPTWIDGETUSRNEW_H
