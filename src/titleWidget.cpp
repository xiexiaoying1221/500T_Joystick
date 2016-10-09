#include "titleWidget.h"

TitleWidget::TitleWidget(QWidget *parent,QRect titleRect)
    :QWidget(parent, Qt::FramelessWindowHint){

    this->setGeometry(titleRect.x()+2,  titleRect.y()+2, titleRect.width()-2,titleRect.height() -2);

    QPalette whitePal(Qt::white);
    QPainter painter(this);

    QPalette orgPal ;
    orgPal.setColor(QPalette::WindowText,Qt::white);

    QFont sansFont("Arial", 10,QFont::Bold);
    QRect rect1(10,2,120,this->geometry().height()-10);//Joystick-711
    QLabel *label1 = new QLabel("CSIC-711 Joystick ",this);
    label1->setGeometry(rect1);
    label1->setPalette(orgPal);
    //label1->setAutoFillBackground(true);
    label1->setAlignment(Qt::AlignCenter);
    label1->setFont(sansFont);


    QRect rect2(this->geometry().width()/ 2 - 50 ,2,100,this->geometry().height()-10);//QT
    label2= new QLabel(str_caozuoduan,this);
    label2->setGeometry(rect2);
    label2->setPalette(orgPal);
    //label2->setAutoFillBackground(true);
    label2->setAlignment(Qt::AlignCenter);
    label2->setFont(sansFont);

    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间

    QRect rect3(this->geometry().width()- 200 ,2,180,this->geometry().height()-10);//Time
    QLabel *label3 = new QLabel(time.currentDateTime().toString("yyyy.MM.dd hh:mm:ss"),this);
    label3->setGeometry(rect3);
    label3->setObjectName("lblTime");
    label3->setPalette(orgPal);
//    label3->setFont(sansFont);

//    QTimer *timer = new QTimer(this);
//    connect(timer,SIGNAL(timeout()),SLOT(timerDone()));
//    timer->start(1000);
}
TitleWidget::~TitleWidget(){

}

void TitleWidget::Refresh_changlese_words()
{
    label2->setText(str_caozuoduan);
}

void TitleWidget::paintEvent(QPaintEvent *){

}
void TitleWidget::refreshData(){
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strTime = time.currentDateTime().toString("yyyy.MM.dd hh:mm:ss");

    QLabel * label = this->findChild<QLabel *>("lblTime");
    label->setFont(FONT_7);
    label->setText(strTime);
}
