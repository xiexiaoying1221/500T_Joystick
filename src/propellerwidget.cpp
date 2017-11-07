/*
    推进器视图
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "propellerwidget.h"
#include "ui_propellerwidget.h"

PropellerWidget::PropellerWidget(QWidget *parent,QRect viewRect) :
    QWidget(parent),
    ui(new Ui::PropellerWidget)
{
    ui->setupUi(this);
    this->setGeometry(viewRect.x(),  viewRect.y() + 20, viewRect.width()-2,viewRect.height());

//    QPalette p;
//    p.setBrush(this->backgroundRole(),QBrush(QPixmap(PicNameD_15)));//"images/推进器视图-日.png"
//    p.setColor(QPalette::WindowText,COLOR_15);
//    ui->label_1->setPalette(p);
//    ui->label_2->setPalette(p);
//    ui->label_3->setPalette(p);
//    ui->label_4->setPalette(p);
//    ui->label_5->setPalette(p);

    /*

    ui->leangle_rudder1->setFont(FONT_11);
    ui->leangle_rudder2->setFont(FONT_11);
    ui->lepitch_p1->setFont(FONT_11);
    ui->lepitch_p2->setFont(FONT_11);
    ui->lepitch_p3->setFont(FONT_11);
    ui->lespeed_p1->setFont(FONT_11);
    ui->lespeed_p2->setFont(FONT_11);
    ui->lespeed_p3->setFont(FONT_11);
    */

//    this->setPalette(p);
    changeDNMode();

    this->setAutoFillBackground(true);

}



/*刷新数据*/
void PropellerWidget::refreshData()
{
   QPalette pe;
   //就绪
   if(Ready_prop1 == false)
   {
        pe.setColor(QPalette::Base,COLOR_18);//禁用颜色
   }
   else
   {
        pe.setColor(QPalette::Base,COLOR_20);//启用颜色
   }
   ui->leready_p1->setAutoFillBackground(true);
   ui->leready_p1->setPalette(pe);

   if(Ready_prop2 == false)
   {
        pe.setColor(QPalette::Base,COLOR_18);
   }
   else
   {
        pe.setColor(QPalette::Base,COLOR_20);
   }
   ui->leready_p2->setAutoFillBackground(true);
   ui->leready_p2->setPalette(pe);


   if(Ready_prop3 == false)
   {
        pe.setColor(QPalette::Base,COLOR_18);
   }
   else
   {
        pe.setColor(QPalette::Base,COLOR_20);
   }
   ui->leready_p3->setAutoFillBackground(true);
   ui->leready_p3->setPalette(pe);


   if(Ready_rudder1 == false)
   {
        pe.setColor(QPalette::Base,COLOR_18);
   }
   else
   {
        pe.setColor(QPalette::Base,COLOR_20);
   }
   ui->leready_rudder1 ->setAutoFillBackground(true);
   ui->leready_rudder1->setPalette(pe);

   if(Ready_rudder2 == false)
   {
        pe.setColor(QPalette::Base,COLOR_18);
   }
   else
   {
        pe.setColor(QPalette::Base,COLOR_20);
   }
   ui->leready_rudder2 ->setAutoFillBackground(true);
   ui->leready_rudder2->setPalette(pe);


   //运行
   ui->leenable_p1->setAutoFillBackground(true);
   ui->lerun_p1->setAutoFillBackground(true);

   if(Enable_prop1_on == 1)
   {
        pe.setColor(QPalette::Base,COLOR_20);//绿色
        ui->leenable_p1->setPalette(pe);
        if(Ready_prop1)
            ui->lerun_p1->setPalette(pe);
        else
        {
            pe.setColor(QPalette::Base,COLOR_18);
            ui->lerun_p1->setPalette(pe);
        }
   }
   else
   {
       pe.setColor(QPalette::Base,COLOR_18);
       ui->lerun_p1->setPalette(pe);
       ui->leenable_p1->setPalette(pe);
   }



   ui->leenable_p2->setAutoFillBackground(true);
   ui->lerun_p2->setAutoFillBackground(true);

   if(Enable_prop2_on == 1)
   {
        pe.setColor(QPalette::Base,COLOR_20);
        ui->leenable_p2->setPalette(pe);
        if(Ready_prop2)
            ui->lerun_p2->setPalette(pe);
        else
        {
            pe.setColor(QPalette::Base,COLOR_18);
            ui->lerun_p2->setPalette(pe);
        }
   }
   else
   {
       pe.setColor(QPalette::Base,COLOR_18);
       ui->lerun_p2->setPalette(pe);
       ui->leenable_p2->setPalette(pe);
   }



   ui->leenable_p3->setAutoFillBackground(true);
   ui->lerun_p3->setAutoFillBackground(true);

   if(Enable_prop3_on == 1)
   {
        pe.setColor(QPalette::Base,COLOR_20);
        ui->leenable_p3->setPalette(pe);
        if(Ready_prop3)
            ui->lerun_p3->setPalette(pe);
        else
        {
            pe.setColor(QPalette::Base,COLOR_18);
            ui->lerun_p3->setPalette(pe);
        }
   }
   else
   {
       pe.setColor(QPalette::Base,COLOR_18);
       ui->lerun_p3->setPalette(pe);
       ui->leenable_p3->setPalette(pe);
   }





   ui->leenable_rudder1->setAutoFillBackground(true);
   ui->lerun_rudder1->setAutoFillBackground(true);

   if(Enable_rudder1_on == 1)
   {
        pe.setColor(QPalette::Base,COLOR_20);
        ui->leenable_rudder1->setPalette(pe);
        if(Ready_rudder1)
            ui->lerun_rudder1->setPalette(pe);
        else
        {
            pe.setColor(QPalette::Base,COLOR_18);
            ui->lerun_rudder1->setPalette(pe);
        }
   }
   else
   {
       pe.setColor(QPalette::Base,COLOR_18);
       ui->lerun_rudder1->setPalette(pe);
       ui->leenable_rudder1->setPalette(pe);
   }


   ui->leenable_rudder2->setAutoFillBackground(true);
   ui->lerun_rudder2->setAutoFillBackground(true);

   if(Enable_rudder2_on == 1)
   {
        pe.setColor(QPalette::Base,COLOR_20);
        ui->leenable_rudder2->setPalette(pe);
        if(Ready_rudder2)
            ui->lerun_rudder2->setPalette(pe);
        else
        {
            pe.setColor(QPalette::Base,COLOR_18);
            ui->lerun_rudder2->setPalette(pe);
        }
   }
   else
   {
       pe.setColor(QPalette::Base,COLOR_18);
       ui->lerun_rudder2->setPalette(pe);
       ui->leenable_rudder2->setPalette(pe);
   }

//   ui->lepitch_p1->setText(QString::number(fbk_prop1_pitch,'f',1));
   ui->lepitch_p1->setText("N/A");
   ui->lepitch_p2->setText(QString::number(fbk_prop2_pitch,'f',1));
   ui->lepitch_p3->setText(QString::number(fbk_prop3_pitch,'f',1));

   ui->lespeed_p1->setText(QString::number(fbk_prop1_spd,'f',1));
//   ui->lespeed_p2->setText(QString::number(fbk_prop2_spd,'f',1));
//   ui->lespeed_p3->setText(QString::number(fbk_prop3_spd,'f',1));
   ui->lespeed_p2->setText("N/A");
   ui->lespeed_p3->setText("N/A");

   ui->leangle_rudder1->setText(QString::number(fbk_rudder1_ang,'f',1));
   ui->leangle_rudder2->setText(QString::number(fbk_rudder2_ang,'f',1));
}
//白天、夜晚模式切换
void PropellerWidget::changeDNMode()
{
    QPalette p;
    if(daynight_mode == DAYMODE)
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameD_15)));//"images/推进器视图-日.png"
        this->setPalette(p);

        p.setColor(QPalette::WindowText,COLOR_15);
        ui->label_1->setStyleSheet(StyleSheet_DayColor);
        ui->label_2->setStyleSheet(StyleSheet_DayColor);
        ui->label_3->setStyleSheet(StyleSheet_DayColor);
        ui->label_4->setStyleSheet(StyleSheet_DayColor);
        ui->label_5->setStyleSheet(StyleSheet_DayColor);
        ui->label_6->setStyleSheet(StyleSheet_DayColor);
        ui->label_7->setStyleSheet(StyleSheet_DayColor);
        ui->label_8->setStyleSheet(StyleSheet_DayColor);
        ui->label_9->setStyleSheet(StyleSheet_DayColor);
        ui->label_10->setStyleSheet(StyleSheet_DayColor);
        ui->label_11->setStyleSheet(StyleSheet_DayColor);
        ui->label_12->setStyleSheet(StyleSheet_DayColor);
        ui->label_13->setStyleSheet(StyleSheet_DayColor);
        ui->label_14->setStyleSheet(StyleSheet_DayColor);
        ui->label_15->setStyleSheet(StyleSheet_DayColor);
        ui->label_16->setStyleSheet(StyleSheet_DayColor);

        p.setColor(QPalette::Text,COLOR_15);
        ui->leangle_rudder1->setPalette(p);
        ui->leangle_rudder2->setPalette(p);
        ui->leenable_p1->setPalette(p);
        ui->leenable_p2->setPalette(p);
        ui->leenable_p3->setPalette(p);
        ui->leenable_rudder1->setPalette(p);
        ui->leenable_rudder2->setPalette(p);
        ui->lepitch_p1->setPalette(p);
        ui->lepitch_p2->setPalette(p);
        ui->lepitch_p3->setPalette(p);
        ui->leready_p1->setPalette(p);
        ui->leready_p2->setPalette(p);
        ui->leready_p3->setPalette(p);
        ui->leready_rudder1->setPalette(p);
        ui->leready_rudder2->setPalette(p);
        ui->lerun_p1->setPalette(p);
        ui->lerun_p2->setPalette(p);
        ui->lerun_p3->setPalette(p);
        ui->lerun_rudder1->setPalette(p);
        ui->lerun_rudder2->setPalette(p);
        ui->lespeed_p1->setPalette(p);
        ui->lespeed_p2->setPalette(p);
        ui->lespeed_p3->setPalette(p);

    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(QPixmap(PicNameE_15)));//"images/推进器视图-夜.png"
        this->setPalette(p);
        //p.setColor(QPalette::WindowText,COLOR_23);
        ui->label_1->setStyleSheet(StyleSheet_NgtColor);
        ui->label_2->setStyleSheet(StyleSheet_NgtColor);
        ui->label_3->setStyleSheet(StyleSheet_NgtColor);
        ui->label_4->setStyleSheet(StyleSheet_NgtColor);
        ui->label_5->setStyleSheet(StyleSheet_NgtColor);
        ui->label_6->setStyleSheet(StyleSheet_NgtColor);
        ui->label_7->setStyleSheet(StyleSheet_NgtColor);
        ui->label_8->setStyleSheet(StyleSheet_NgtColor);
        ui->label_9->setStyleSheet(StyleSheet_NgtColor);
        ui->label_10->setStyleSheet(StyleSheet_NgtColor);
        ui->label_11->setStyleSheet(StyleSheet_NgtColor);
        ui->label_12->setStyleSheet(StyleSheet_NgtColor);
        ui->label_13->setStyleSheet(StyleSheet_NgtColor);
        ui->label_14->setStyleSheet(StyleSheet_NgtColor);
        ui->label_15->setStyleSheet(StyleSheet_NgtColor);
        ui->label_16->setStyleSheet(StyleSheet_NgtColor);
        p.setColor(QPalette::Text,COLOR_23);
        ui->leangle_rudder1->setPalette(p);
        ui->leangle_rudder2->setPalette(p);
        ui->leenable_p1->setPalette(p);
        ui->leenable_p2->setPalette(p);
        ui->leenable_p3->setPalette(p);
        ui->leenable_rudder1->setPalette(p);
        ui->leenable_rudder2->setPalette(p);
        ui->lepitch_p1->setPalette(p);
        ui->lepitch_p2->setPalette(p);
        ui->lepitch_p3->setPalette(p);
        ui->leready_p1->setPalette(p);
        ui->leready_p2->setPalette(p);
        ui->leready_p3->setPalette(p);
        ui->leready_rudder1->setPalette(p);
        ui->leready_rudder2->setPalette(p);
        ui->lerun_p1->setPalette(p);
        ui->lerun_p2->setPalette(p);
        ui->lerun_p3->setPalette(p);
        ui->lerun_rudder1->setPalette(p);
        ui->lerun_rudder2->setPalette(p);
        ui->lespeed_p1->setPalette(p);
        ui->lespeed_p2->setPalette(p);
        ui->lespeed_p3->setPalette(p);
    }


}

void PropellerWidget::Refresh_changless_words()
{
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);


//    painter.setFont(FONT_15);
    ui->label_1->setFont(FONT_15);
    ui->label_2->setFont(FONT_15);
    ui->label_3->setFont(FONT_15);
    ui->label_4->setFont(FONT_15);
    ui->label_5->setFont(FONT_15);

    ui->label_1->setText(str_shoucetui);
    ui->label_2->setText(str_weizuozhutui);
    ui->label_3->setText(str_weiyouzhutui);
    ui->label_4->setText(str_zuoduoji);
    ui->label_5->setText(str_youduoji);

 //   painter.setFont(FONT_3);
    ui->label_6->setFont(FONT_2);
    ui->label_7->setFont(FONT_2);
    ui->label_8->setFont(FONT_2);
    ui->label_9->setFont(FONT_2);
    ui->label_10->setFont(FONT_2);
    ui->label_11->setFont(FONT_2);
    ui->label_12->setFont(FONT_2);
    ui->label_13->setFont(FONT_2);
    ui->label_14->setFont(FONT_2);
    ui->label_15->setFont(FONT_2);
    ui->label_16->setFont(FONT_2);


    ui->label_6->setText(str_luoju);
    ui->label_7->setText(str_luoju);
    ui->label_8->setText(str_luoju);
    ui->label_9->setText(str_duojiao);
    ui->label_10->setText(str_duojiao);
    ui->label_11->setText(str_zhuansu);
    ui->label_12->setText(str_zhuansu);
    ui->label_13->setText(str_zhuansu);
    ui->label_14->setText(str_jiuxu);
    ui->label_15->setText(str_yunxing);
    ui->label_16->setText(str_qiyong);


}

PropellerWidget::~PropellerWidget()
{
    delete ui;
}


