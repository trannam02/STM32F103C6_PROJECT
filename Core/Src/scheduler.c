#include <scheduler.h>

sTask SCH_tasks[SCH_MAX_TASKS];
sTask * p_SCH_tasks[SCH_MAX_TASKS];
uint8_t SCH_task_count = 0;
int present = 0;
unsigned char pre = 0;

void SCH_Init(){

};

void SCH_Add_Task(void(*func)(void), unsigned int delay, unsigned int period){
	if(SCH_task_count >= SCH_MAX_TASKS){
		return;
	};
	// set infor of task (add task thi se su dung count, delete task thi don ve dau tien)
	SCH_tasks[SCH_task_count].pTask = func;
	SCH_tasks[SCH_task_count].Delay = delay;
	SCH_tasks[SCH_task_count].Period = period;
	SCH_tasks[SCH_task_count].RunMe = 0;
	SCH_tasks[SCH_task_count].TaskID = SCH_task_count;

	    // add new task
	    int newValue = delay;
	    int i = 0;

	    int tempResult = 0;
	    while(i < SCH_task_count) {
	        tempResult = newValue - p_SCH_tasks[(i + present)%max]->Delay;
	        if(tempResult >= 0) {
	            newValue = tempResult;
	        } else
	            break;
	        i++;
	    };

	    int j = SCH_task_count + present;
	    while(j > (i + present)){ // move timers to the end
	    	p_SCH_tasks[j%SCH_MAX_TASKS] = p_SCH_tasks[(j-1)%SCH_MAX_TASKS];
	        j--;
	    };
	    if(j != (SCH_task_count + present))
	    	p_SCH_tasks[i+1+present]->Delay -= newValue;

	    p_SCH_tasks[(i+present)%max] = &SCH_tasks[SCH_task_count];
	    SCH_task_count++;
};

void SCH_Update(){ // timer Run
	if(p_SCH_tasks[pre]->Delay > 0) p_SCH_tasks[pre]->Delay--;
	    if(p_SCH_tasks[pre]->Delay <= 0) {

	    	p_SCH_tasks[pre]->RunMe += 1;

	        present++;
	        pre = present%SCH_MAX_TASKS;
//	        SCH_task_count--;
	        // remove thisTimer
	    };
};
void SCH_Dispatch_Task(){
	unsigned char index;
	for(index = 0; index < SCH_task_count; index++){
		if(SCH_tasks[index].RunMe > 0){
			*(SCH_tasks[index].pTask)();
			SCH_tasks[index].RunMe -= 1;
			if(period != 0){
				// copy old first pointer to the end
				p_SCH_tasks[SCH_task_count + present] = &SCH_tasks[index];
				SCH_tasks[index]->Delay = SCH_tasks[index]->Period;
			}else{
				// counter --
				SCH_task_count--;
			}
		}
	}
};
void SCH_Delete_Task(unsigned int taskID);
