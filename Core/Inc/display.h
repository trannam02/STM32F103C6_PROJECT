#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "main.h"
void display7SEG(int number);
void enable0();
void enable1();
void enable2();
void enable3();

void enableDOT();
void disableDOT();

void displayLEDMatrix(int row, uint8_t col);
#endif
