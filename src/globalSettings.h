#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

#include "dataCommit.h"
#include "characterconversion.h"

//如果是便携式操作站则启用，固定式则注释掉
#define PORTABLE_STATION

/*
整体宽度定义为100%
按键区占37%，艏向和位置区占1.5个单位25%，视图区占38%

整体高度定义为100%
标题栏和信息栏各占10%
艏向区和位置区各占40%
*/
//窗口的长宽
#define WINDOWWIDTH 1024    //窗口宽度
#define WINDOWHEIGHT 768    //窗口高度
#define TITLE_HEIGHT_PERCENTAGE     0.04     //标题栏高所占比例
#define INFO_HEIGHT_PERCENTAGE      0.04     //信息栏高所占比例
#define HEAD_HEIGHT_PERCENTAGE      0.44     //艏向区高所占比例
#define POSITION_HEIGHT_PERCENTAGE  0.48     //位置区高所占比例
#define VIEW_HEIGHT_PERCENTAGE      (1 - TITLE_HEIGHT_PERCENTAGE - INFO_HEIGHT_PERCENTAGE)     //位置区高所占比例

#define HEAD_WIDTH_PERCENTAGE       0.254    //艏向区宽所占比例
#define POSITION_WIDTH_PERCENTAGE   HEAD_WIDTH_PERCENTAGE    //位置区宽所占比例
#define VIEW_WIDTH_PERCENTAGE       (1 - HEAD_WIDTH_PERCENTAGE)    //视图区宽所占比例
#define KEY_WIDTH_PERCENTAGE        0.317   //按键区宽所占比例

#define DAYMODE     1   //白天模式
#define NIGHTMODE   0   //夜晚模式

/*全局区域*/

/*颜色*/
#define COLOR_1 QColor(231,228,209)//白天模式，背景色
#define COLOR_2 QColor(255,255,255)//夜晚模式，字体颜色
#define COLOR_3 QColor(68,68,68)//夜晚模式，背景色
#define COLOR_4 QColor(255,255,255)//夜晚模式，字体颜色
#define COLOR_5 QColor(0,0,135)//标题栏背景色
#define COLOR_6 QColor(255,255,255)//标题栏字体颜色
#define COLOR_7 QColor(224,176,176)//速度/角速度降低/左转箭头颜色
#define COLOR_8 QColor(193,231,169)//速度/角速度增加/右转箭头颜色
//#define COLOR_9 QColor(41,41,102)//设定进度条颜色
#define COLOR_9 QColor(36,0,252)//设定进度条颜色(蓝)
//#define COLOR_10 QColor(64,132,75)//反馈进度条颜色
#define COLOR_10 QColor(1,196,65)//反馈进度条颜色(绿)
#define COLOR_11 QColor(162,160,145)//深灰色/提示信息背景区域颜色
#define COLOR_12 QColor(250,245,230)//浅灰色背景区域颜色
#define COLOR_13 QColor(177,177,127)//艏向区边框颜色
#define COLOR_14 QColor(0,0,0)//黑 应答按键字体颜色
#define COLOR_15 QColor(65,65,65)//白天模式下，船速、设定艏向等字体颜色
#define COLOR_16 QColor(252,252,0) //预报警/高亮显示区颜色 黄色
#define COLOR_17 QColor(255,128,0) //故障颜色 橙色
#define COLOR_18 QColor(255,0,0) //报警/禁用颜色 红色
#define COLOR_19 QColor(128,0,0) //紧急报警颜色
#define COLOR_20 QColor(0,255,0) //启用颜色
#define COLOR_21 QColor(102,102,102)//单位字体
#define COLOR_22 QColor(33,155,0) //中绿
#define COLOR_23 QColor(196,196,196) //夜模式下，标题字的颜色
#define COLOR_24 QColor(25,25,25);//按键区 按键字体颜色

/*画刷*/
#define BRUSH_1 QBrush(COLOR_8)//浅绿色画刷
#define BRUSH_2 QBrush(COLOR_7)//浅红色画刷
#define BRUSH_3 QBrush(COLOR_17)//橙色画刷
#define BRUSH_4 QBrush(Qt::black)//黑色画刷
#define BRUSH_5 QBrush(COLOR_10)//深绿色画刷
#define BRUSH_6 QBrush(Qt::red)//红色
#define BRUSH_7 QBrush(COLOR_12)//浅灰色
#define BRUSH_8 QBrush(COLOR_9)
#define BRUSH_9 QBrush(COLOR_18)
#define BRUSH_10 QBrush(COLOR_15)
#define BRUSH_11 QBrush(COLOR_20)


/*画笔*/

//白天
#define PEN_1  QPen(COLOR_15)//灰色
#define PEN_2  QPen(QColor(65,65,65))//淡黑色
#define PEN_3  QPen(COLOR_14)//黑字体
#define PEN_4  QPen(COLOR_18,1)//风向区 红色边线
#define PEN_5  QPen(QColor(128,128,128))// 风向区 灰色边线
#define PEN_6  QPen(QColor(64,132,75),2)
#define PEN_7  QPen(COLOR_9,10,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin)//艏向区设定进度条
#define PEN_8  QPen(COLOR_10,10,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin)//艏向区反馈进度条
#define PEN_9  QPen(COLOR_15,1,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin)
#define PEN_10 QPen(COLOR_15,1, Qt::DashLine, Qt::FlatCap, Qt::RoundJoin)//灰 虚线
#define PEN_11 QPen(Qt::black,1, Qt::DashLine, Qt::FlatCap, Qt::RoundJoin)//黑 虚线
#define PEN_12 QPen(COLOR_9,15, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin)//点
#define PEN_13 QPen(COLOR_9,2)
#define PEN_14 QPen(COLOR_17)//故障
#define PEN_15 QPen(COLOR_17,10,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin)
#define PEN_16 QPen(COLOR_18,10,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin)
#define PEN_17 QPen(Qt::white)
#define PEN_18 QPen(COLOR_9)//艏向区 艏向标示线
#define PEN_19 QPen(COLOR_21)
#define PEN_WARN QPen(COLOR_15)
#define PEN_ALARM QPen(COLOR_2)
#define PEN_INFO QPen(COLOR_14)

//黑夜
#define PEN_1_1 QPen(COLOR_23)


/*字体*/
//#define FONT_1  QFont("微软雅黑",8)
//#define FONT_2  QFont("微软雅黑",10,QFont::Bold)
//#define FONT_3  QFont("微软雅黑",12)
//#define FONT_4  QFont("微软雅黑",24,QFont::Bold)
//#define FONT_5  QFont("微软雅黑",10)
#define FONT_6  QFont("Arial",8)//N E
#define FONT_7  QFont("Arial",10)//Microsoft Sans Serif
#define FONT_8  QFont("Arial",12,QFont::Bold)//N E数值字体
#define FONT_9  QFont("Arial",16,QFont::Bold)
#define FONT_10 QFont("Arial",16)
#define FONT_11 QFont("Arial",20,QFont::Bold)
#define FONT_12 QFont("Arial",32,QFont::Bold)//艏向实时值
#define FONT_13 QFont("Arial",38)
#define FONT_14 QFont("Arial",26,QFont::Bold)//风力区实时值


extern QFont FONT_1;
extern QFont FONT_2;
extern QFont FONT_3;
extern QFont FONT_4;
extern QFont FONT_5;
extern QFont FONT_15;//视图区标题文字字体
extern QFont FONT_16;//按键键名字体

extern bool isAlarm_pos;
extern bool isAlarm_head;
extern bool isWarn_pos;
extern bool isWarn_head;
extern bool isAlarm_posx;
extern bool isWarn_posx;
extern bool isAlarm_posy;
extern bool isWarn_posy;

//图片名称
//adjustingbrightnesswidget.cpp
#define PicNameD_1  ":/images/调光-日.png"
#define PicNameE_1  ":/images/调光-夜.png"
//alarmlistwidget.cpp
#define PicNameD_2  ":/images/报警页背景-日.png"
#define PicNameE_2  ":/images/报警页背景-夜.png"
//autoruddersettingwidget.cpp
#define PicNameD_3  ":/images/设置艏向-日.png"
#define PicNameE_3  ":/images/设置艏向-夜.png"
#define PicNameD_4  ":/images/推进器启用设置-日.png"
#define PicNameE_4  ":/images/推进器启用设置-夜.png"
//generalsettingwidget.cpp
#define PicNameD_5  ":/images/总体设置-日.png"
#define PicNameE_5  ":/images/总体设置-夜.png"
//headingsetpwidget.cpp
#define PicNameD_6  ":/images/设置艏向-日.png"
#define PicNameE_6  ":/images/设置艏向-夜.png"
//keyWidget.cpp
#define PicNameD_7  ":/images/按键区-日.png"
#define PicNameE_7  ":/images/按键区-夜.png"
//limitsetwidget.cpp
#define PicNameD_8  ":/images/限值设置-日.png"
#define PicNameE_8  ":/images/限值设置-夜.png"
//mainViewWidget.cpp
#define PicNameD_9  ":/images/主视图区-日.png"
#define PicNameE_9  ":/images/主视图区-夜.png"
//mainwindow.cpp
#define PicNameD_10 ":/images/backgournd.png"
#define PicNameE_10 ":/images/backgournd_night.png"
//positionreferencewidget.cpp
#define PicNameD_11 ":/images/位置参考视图-日.png"
#define PicNameE_11 ":/images/位置参考视图-夜.png"
//powerconsumptionwidget.cpp
#define PicNameD_12 ":/images/功耗视图-日.png"
#define PicNameE_12 ":/images/功耗视图-夜.png"
//promptwidget.cpp
#define PicNameD_13 ":/images/对话框-日.png"
#define PicNameE_13 ":/images/对话框-夜.png"
//propellerenablewidget.cpp
#define PicNameD_14 ":/images/推进器启用设置-日.png"
#define PicNameE_14 ":/images/推进器启用设置-夜.png"
//propellerwidget.cpp
#define PicNameD_15 ":/images/推进器视图-日.png"
#define PicNameE_15 ":/images/推进器视图-夜.png"
//sensorenablewidget.cpp
#define PicNameD_16 ":/images/传感器启用设置-日.png"
#define PicNameE_16 ":/images/传感器启用设置-夜.png"
//sensorwidget.cpp
#define PicNameD_17 ":/images/传感器视图-日.png"
#define PicNameE_17 ":/images/传感器视图-夜.png"
//systemsettingwidget.cpp
#define PicNameD_18 ":/images/系统设置-日.png"
#define PicNameE_18 ":/images/系统设置-夜.png"
//systemstatuswidget.cpp
#define PicNameD_19 ":/images/systemstatus.png"
#define PicNameE_19 ":/images/systemstatus.png"
//deviceviewwidget.cpp
#define PicNameD_20 ":/images/设备视图-日.png"
#define PicNameE_20 ":/images/设备视图-夜.png"
//tokenWidget.cpp
#define PicNameD_21 ":/images/令牌管理-日.png"
#define PicNameE_21 ":/images/令牌管理-夜.png"
//promptwidgetwithsyn.cpp
#define PicNameD_22 ":/images/对话框长-日.png"
#define PicNameE_22 ":/images/对话框长-夜.png"

#define PicBlank ":/images/视图区空背景.png"

#define StyleSheet_DayColor "color: rgb(65, 65, 65);"
#define StyleSheet_NgtColor "color: rgb(196, 196, 196);"


#endif // GLOBALSETTINGS_H
