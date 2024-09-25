#include "../Inc/fsm_clock_2state.h"
int state = ON_OFF;
void fsm_init(){
	setTimer(0,500);
	disable0();
	disable1();
};

void fsm_run(){
	switch(state){
	case ON_OFF:
		if(getFlag(0) == 1) {
			state = OFF_ON;
			setTimer(0, 500);
		};
		enable0();
		disable1();
		display7SEG(1);
		break;
	case OFF_ON:
		if(getFlag(0) == 1) {
			state = ON_OFF;
			setTimer(0, 500);
		};
		enable1();
		disable0();
		display7SEG(2);
		break;
	default:
		break;
	};
};
