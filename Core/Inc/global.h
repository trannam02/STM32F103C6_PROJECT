#ifndef GLOBAL_H
#define GLOBAL_H

#include <main.h>

#define TICK 10

#define MAN_RED_GREEN 1
#define MAN_RED_YELLOW 2
#define MAN_GREEN_RED 3
#define MAN_YELLOW_RED 4

#define MODE_EDIT_RED 5
#define MODE_EDIT_YELLOW 6
#define MODE_EDIT_GREEN 7

extern int status;
extern int timeGreen;
extern int timeYellow;
extern int mode;
extern int Vertical_value;
extern int Horizontal_value;
#endif
