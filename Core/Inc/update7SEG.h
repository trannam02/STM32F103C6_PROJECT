#ifndef _UPDATE_7_SEG_H
#define _UPDATE_7_SEG_H

#include "main.h"
#include "display.h"
#include "softwareTimer.h"

#define ON 1
#define OFF 0

void update7SEG_init();
void update7SEG_run();
void update7SEG(int index);

#endif
