#ifndef PROMPTWIDGETCHANGENAME_H
#define PROMPTWIDGETCHANGENAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QMessageBox>
#include "globalSettings.h"
#include "usrmanager.h"

class PromptWidgetChangeName : public QWidget
{
    Q_OBJECT
public:
    PromptWidgetChangeName(QWidget *parent=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickOk();
    void clickCancel();

private:
    QLabel *_lblOldName;
    QLabel *_lblNewName;
    QLabel *_lblPswd;

    QLineEdit * _leOldName;
    QLineEdit * _leNewName;
    QLineEdit * _lePswd;

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

#endif // PROMPTWIDGETCHANGENAME_H
