#ifndef _UART_COMMUNICATION_FSM_H
#define _UART_COMMUNICATION_FSM_H

#include <main.h>
#include <command_parser_fsm.h>
#include <stdio.h>
#include <softwareTimer.h>

#define UART_INIT 0
#define UART_IDLE 1
#define READ_AND_SEND 2
#define SEND_PERIOD 3

void uart_communication_init();
void uart_communication_fsm();

#endif
