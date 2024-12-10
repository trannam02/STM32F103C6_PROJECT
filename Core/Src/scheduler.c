#include <scheduler.h>

uint8_t SCH_tasks_valid[SCH_MAX_TASKS];
sTask SCH_tasks[SCH_MAX_TASKS];
sTask *p_SCH_tasks[SCH_MAX_TASKS];

uint8_t SCH_task_count = 0;

int present = 0;
int SCH_old_dispatched = 0;

uint8_t pre = 0;
uint8_t runMeFlag = 0;

void SCH_Init() {
	for (int i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_tasks_valid[i] = 0;
		p_SCH_tasks[i] = NULL;
	};

}
;

uint8_t SCH_Add_Task(void (*func)(void*), void * args, uint32_t _delay, uint32_t _period) {
	uint32_t delay = _delay/TIMER_DIVIDER;
	uint32_t period = _period/TIMER_DIVIDER;
	if (SCH_task_count >= SCH_MAX_TASKS) {
		return 0xFF;
	};
	// set infor of task (add task thi se su dung count, delete task thi don ve dau tien)
	int id = 0;
	for (id = 0; id < SCH_MAX_TASKS; id++) {
		if (SCH_tasks_valid[id] == 0) {
			SCH_tasks_valid[id] = 1;
			break;
		};
	};
	SCH_tasks[id].pTask = func;
	SCH_tasks[id].args = args;
	SCH_tasks[id].Delay = delay;
	SCH_tasks[id].Period = period;
	SCH_tasks[id].RunMe = 0;
	SCH_tasks[id].TaskID = id;

	// add new task
	int newValue = delay;
	int i = 0;
	int tempResult = 0;
	while (i < SCH_task_count) {
		tempResult = newValue
				- p_SCH_tasks[(i + present) % SCH_MAX_TASKS]->Delay;
		if (tempResult >= 0) {
			newValue = tempResult;
		} else
			break;
		i++;
	};

	int j = SCH_task_count + present;
	while (j > (i + present)) { // move timers to the end
		p_SCH_tasks[j % SCH_MAX_TASKS] = p_SCH_tasks[(j - 1) % SCH_MAX_TASKS];
		j--;
	};
	if (j != (SCH_task_count + present))
		p_SCH_tasks[(i + 1 + present) % SCH_MAX_TASKS]->Delay -= newValue;

	SCH_tasks[i].Delay = newValue;
	p_SCH_tasks[(i + present) % SCH_MAX_TASKS] = &SCH_tasks[i];
	SCH_task_count++;
	return id;
}
;

void SCH_Update() { // timer Run
	if (p_SCH_tasks[pre] == NULL)
		return;

	if (p_SCH_tasks[pre]->Delay > 0)
		p_SCH_tasks[pre]->Delay--;

	if (p_SCH_tasks[pre]->Delay <= 0) {
		p_SCH_tasks[pre]->RunMe = 1;
		if(p_SCH_tasks[SCH_old_dispatched % SCH_MAX_TASKS]->RunMe == 0) SCH_old_dispatched = present;
		present++;
		pre = present % SCH_MAX_TASKS;
		SCH_task_count--;
	};
}
;
void SCH_Dispatch_Task() {
	unsigned char index;
	unsigned char flag = 0;

	if(p_SCH_tasks[TRUEIDX(0,SCH_old_dispatched)]->RunMe == 0) return;

	int sl = present - SCH_old_dispatched;
	for (index = 0; index < sl; index++) {
		if (p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->Delay <= 0) {

			if(flag == 0 && p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->RunMe == 1) flag = 1;

			(*(p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->pTask))(p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->args);
			p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->RunMe = 0;
			if (p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->Period != 0) {
				// copy old first pointer to the end
				p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->Delay = p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->Period;

				// add to new position
				int newValue = p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->Delay;
				int i = 0;
				int tempResult = 0;
				while (i < SCH_task_count) {
					tempResult = newValue
							- p_SCH_tasks[(i + present) % SCH_MAX_TASKS]->Delay;
					if (tempResult >= 0) {
						newValue = tempResult;
					} else
						break;
					i++;
				};

				int j = SCH_task_count + present;
				while (j > (i + present)) { // move timers to the end
					p_SCH_tasks[j % SCH_MAX_TASKS] = p_SCH_tasks[(j - 1)
							% SCH_MAX_TASKS];
					j--;
				};
				if (j != (SCH_task_count + present))
					p_SCH_tasks[(i + 1 + present) % SCH_MAX_TASKS]->Delay -=
							newValue;

				p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)]->Delay = newValue;
				p_SCH_tasks[(i + present) % SCH_MAX_TASKS] = p_SCH_tasks[TRUEIDX(index,SCH_old_dispatched)];
				SCH_task_count++;
				/* printf("hehe"); */

			} else {
//				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				// counter unchange (because counter -- in update)
//				SCH_tasks_valid[index] = 0;
			};
		}else{ // delay > 0

			if(flag == 1) {
//				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
				break;
			};
		};
	};
}
;
void SCH_Delete_Task(unsigned int taskID) {
	if (SCH_task_count == 0)
		return;

	int i = 0;
	for (i = 0; i < SCH_task_count; i++) {
		/* printf("%d - %d\n", p_SCH_tasks[(i+present)%SCH_MAX_TASKS]->TaskID, taskID); */
		if (p_SCH_tasks[(i + present) % SCH_MAX_TASKS]->TaskID == taskID)
			break;
	};
	int restDelay = p_SCH_tasks[(i + present) % SCH_MAX_TASKS]->Delay;
	for (int j = i; j < SCH_task_count - 1; j++) {
		p_SCH_tasks[(j + present) % SCH_MAX_TASKS] = p_SCH_tasks[(j + 1
				+ present) % SCH_MAX_TASKS];
	};
	p_SCH_tasks[(i + present) % SCH_MAX_TASKS]->Delay += restDelay; // increase next delay

	p_SCH_tasks[(SCH_task_count - 1 + present) % SCH_MAX_TASKS] = NULL; // remove last element
	SCH_tasks_valid[taskID] = 0;

	SCH_task_count--;
}
;
