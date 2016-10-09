#ifndef PROMPTDIALOGWIDGET_H
#define PROMPTDIALOGWIDGET_H

#include <qwidget.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qpainter.h>
#include <qtimer.h>
#include <globalSettings.h>

class PromptWidget : public QWidget
{
    Q_OBJECT
public:
    PromptWidget(QWidget *parent=0, QWidget *singalReceiver=0, QRect rect = QRect(0,0,0,0));

private slots:
    void clickOk();
    void clickCancel();

signals:
    void changemode(bool);
private:
    QLabel *lblPrompt;

    QPushButton *pbCancel;
    QPushButton *pbOK;
protected:
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);


public:
    QString message;//消息
    int set_mode;//设置模式

    void changeDNMode();
    void Refresh_changless_words();
};

#endif // PROMPTDIALOGWIDGET_H
