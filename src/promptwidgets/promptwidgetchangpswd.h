#ifndef PROMPTWIDGETCHANGEPSWD_H
#define PROMPTWIDGETCHANGEPSWD_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QPainter>
#include "globalSettings.h"
#include "usrmanager.h"

class PromptWidgetChangePswd : public QWidget
{
    Q_OBJECT
public:
    PromptWidgetChangePswd(QWidget *parent=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickOk();
    void clickCancel();

private:
    QLabel *_lblName;
    QLabel *_lblOldPswd;
    QLabel *_lblNewPswd;
    QLabel *_lblNewRepeatPswd;

    QLineEdit * _leName;
    QLineEdit * _leOldPswd;
    QLineEdit * _leNewPswd;
    QLineEdit * _leNewRepeatPswd;

    QPushButton *_pbCancel;
    QPushButton *_pbOK;

    UsrManager *_manager;

    QString _targetUsrName;

protected:
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);

signals:
    void promptFinished(void);

public:
    void changeDNMode();
    void Refresh_changless_words();

    void setTargetUsrName(const QString& usrName);

    void initWidget();
};

#endif // PROMPTWIDGETCHANGEPSWD_H
