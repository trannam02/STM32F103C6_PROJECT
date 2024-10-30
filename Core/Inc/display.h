#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "main.h"

void V_Red();
void V_Yellow();
void V_Green();
void H_Red();
void H_Yellow();
void H_Green();

void resetAll();
void blinkAll();
void display7SEG(int number);

void enable0();
void enable1();
void enable2();
void enable3();
#endif
