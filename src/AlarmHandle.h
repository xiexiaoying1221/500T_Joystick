#ifndef ALARMHANDLE_H
#define ALARMHANDLE_H

#include <QTime>
#include<math.h>
#include<QDebug>
#include "dataCommit.h"
#include "globalSettings.h"
#include "buzzergovernor.h"

#define STARTTIME 20
#define ALM_LINE 20

extern int run_time;
extern int atlen;
extern QString AlarmOrderList[50][8];

void AlarmListMain();

void CCAlarmHandle();
void OTAlarmHandle();
void Refresh_Alarm_words();
void EnableBuzzer();

#endif // ALARMHANDLE_H
