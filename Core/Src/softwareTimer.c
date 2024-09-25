#include "../Inc/softwareTimer.h"

int timerArray[10];
unsigned int timerFlag[10];
int timerArrayCount = 0;
void setTimer(int timer, int duration){
	if(timer >= timerArrayCount) timerArrayCount ++;
	timerArray[timer] = duration / 10;
	timerFlag[timer] = 0;
};
unsigned int getFlag(int timer){
	return timerFlag[timer];
}
void timerRun(){
	// loop all element in timerArray, decrease by 1
	timerArray[0]--;
	if(timerArray[0] <= 0){
		timerFlag[0] = 1;
	};
};
