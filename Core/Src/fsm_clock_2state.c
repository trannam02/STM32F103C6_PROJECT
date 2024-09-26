#include "../Inc/fsm_clock_2state.h"
int state = ON_0;
void fsm_init() {
	setTimer(0, 500);
	enable0();
	enableDOT();
}
;

void fsm_run() {
	switch (state) {
	case ON_0:
		if (getFlag(0) == 1) {
			state = ON_1;
			setTimer(0, 500);
		}
		;
		enable0();
		enableDOT();
		display7SEG(1);
		break;
	case ON_1:
		if (getFlag(0) == 1) {
			state = ON_2;
			setTimer(0, 500);
		}
		;
		enable1();
		display7SEG(2);
		break;
	case ON_2:
		if (getFlag(0) == 1) {
			state = ON_3;
			setTimer(0, 500);
		}
		;
		enable2();
		disableDOT();
		display7SEG(3);
		break;
	case ON_3:
		if (getFlag(0) == 1) {
			state = ON_0;
			setTimer(0, 500);
		}
		;
		enable3();
		display7SEG(0);
		break;
	default:
		break;
	};
}
;
