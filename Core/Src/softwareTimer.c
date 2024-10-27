#include "../Inc/softwareTimer.h"
#include "../Inc/update7SEG.h"
int timerArray[20];
int timerFlag[20];
int timerArrayCount = 0;
void setTimer(int timer, int duration) {
	if (timer >= timerArrayCount)
		timerArrayCount++;
	timerArray[timer] = duration / 10;
	timerFlag[timer] = 0;
}
;
int getTimerFlag(int timer) {
	return timerFlag[timer];
}
void timerRun() {
	// loop all element in timerArray, decrease 1
	timerArray[0]--;
	timerArray[1]--;
	timerArray[2]--;
	timerArray[3]--;
	timerArray[4]--;
	timerArray[5]--;
	timerArray[6]--;
	timerArray[7]--;
	timerArray[8]--;
	timerArray[9]--;
	timerArray[10]--;
	if (timerArray[0] <= 0) {
		timerFlag[0] = 1;
	}
	;
	if (timerArray[1] <= 0) {
		timerFlag[1] = 1;
	}
	;
	if (timerArray[2] <= 0) {
		timerFlag[2] = 1;
	}
	;
	if (timerArray[3] <= 0) {
		timerFlag[3] = 1;
	}
	;
	if (timerArray[4] <= 0) {
		timerFlag[4] = 1;
	}
	;
	if (timerArray[5] <= 0) {
		timerFlag[5] = 1;
	}
	;
	if (timerArray[6] <= 0) {
		timerFlag[6] = 1;
	}
	;
	if (timerArray[7] <= 0) {
		timerFlag[7] = 1;
	}
	;
	if (timerArray[8] <= 0) {
		timerFlag[8] = 1;
	}
	;
	if (timerArray[9] <= 0) {
		timerFlag[9] = 1;
	};
	if (timerArray[10] <= 0) {
		timerFlag[10] = 1;
	};
}
;
