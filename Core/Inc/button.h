#ifndef BUTTON_H
#define BUTTON_H

#include "global.h"
#include "softwareTimer.h"
// BUTTON STATE
#define NORMAL_STATE 1
#define PRESSED_STATE 0

// BUTTON FSM STATE
#define RELEASED 0
#define PRESSED 1
#define LONG_PRESSED 2

#define LONG_PRESS_DURATION 100
#define NO_BUTTON 3

void button_init();
void button_run();
void getKeyInput();

// PRESS
int getButtonPressFlag(int index);
void setButtonPressFlag(int index, int value);
// LONG PRESS
int getButtonLongPressFlag(int index);
void setButtonLongPressFlag(int index, int value);
#endif
