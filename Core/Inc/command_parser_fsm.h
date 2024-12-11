#ifndef _COMMAND_PARSER_H
#define _COMMAND_PARSER_H

#include <main.h>

#define MAX_BUFFER_SIZE 30

#define INIT 8
#define IDLE 0
#define STATE_MARK 1
#define STATE_R 2
#define STATE_S 3
#define STATE_T 4
#define STATE_O 5
#define STATE_K 6
#define STATE_SHARP 7

void command_parser_init();
void command_parser_fsm();

uint8_t getReqFlag();
void setReqFlag(uint8_t value);

uint8_t getOKFlag();
void setOKFlag(uint8_t value);

uint8_t getBufferFlag();
void setBufferFlag(uint8_t value);

#endif
