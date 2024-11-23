#ifndef _SCHEDULER_H
#define _SCHEDULER_H

#include <global.h>

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

typedef struct struct_task{
	void (*pTask)(void);

		uint32_t Delay;

		uint32_t Period;

		uint8_t RunMe;

		uint32_t TaskID;
} sTask;

void SCH_Init();
void SCH_Add_Task(void(*func)(void), unsigned int delay, unsigned int period);
void SCH_Update();
void SCH_Dispatch_Task();
void SCH_Delete_Task(unsigned int taskID);
#endif
