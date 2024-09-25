#ifndef _SOFTWARE_TIMER_H
#define _SOFTWARE_TIMER_H

#include "main.h"

void setTimer(int timer, int duration);
unsigned int getFlag(int timer);
void timerRun();
#endif
