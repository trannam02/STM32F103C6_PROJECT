#ifndef GLOBAL_H
#define GLOBAL_H

#include <main.h>

#define TICK 10

#define AUTO_INIT 0
#define AUTO_RED_GREEN 1
#define AUTO_RED_YELLOW 2
#define AUTO_GREEN_RED 3
#define AUTO_YELLOW_RED 4

#define MAN_INIT 20
#define MAN_V_RED_H_RED 5
#define MAN_V_RED_H_YELLOW 6
#define MAN_V_RED_H_GREEN 7

#define MAN_V_YELLOW_H_RED 8
#define MAN_V_YELLOW_H_YELLOW 9
#define MAN_V_YELLOW_H_GREEN 10

#define MAN_V_GREEN_H_RED 11
#define MAN_V_GREEN_H_YELLOW 12
#define MAN_V_GREEN_H_GREEN 13

#define MODE_EDIT_INIT 14
#define MODE_EDIT_RED 15
#define MODE_EDIT_YELLOW 16
#define MODE_EDIT_GREEN 17

extern int status;
extern int timeGreen;
extern int timeYellow;
extern int mode;
extern int Vertical_value;
extern int Horizontal_value;



#endif
