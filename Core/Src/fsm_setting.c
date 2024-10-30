#include "fsm_setting.h"

extern int status;
int tempData = 0;
void fsm_setting_init() {
	setTimer(5, 500);
}
;
void fsm_setting_run() {
	switch (status) {
	case MODE_EDIT_RED:
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_YELLOW;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) {
					tempData++;
					setButtonPressFlag(1, 0);
				}
				;
		if (getButtonPressFlag(2) == 1) {
			// apply data to timeGreen and timeYellow
			setButtonPressFlag(2, 0);
		}
		;
		if (getTimerFlag(5) == 1) {
			blinkAll();
			setTimer(5, 500);
		}
		;
		break;
	case MODE_EDIT_YELLOW:
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_GREEN;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) {
			// apply data to timeGreen and timeYellow
			setButtonPressFlag(2, 0);
		}
		;
		if (getTimerFlag(5) == 1) {
			blinkAll();
			setTimer(5, 500);
		}
		;
		break;
	case MODE_EDIT_GREEN:
		if (getButtonPressFlag(0) == 1) {
			status = MAN_RED_GREEN;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) {
			// apply data to timeGreen and timeYellow
			setButtonPressFlag(2, 0);
		}
		;
		if (getTimerFlag(5) == 1) {
			blinkAll();
			setTimer(5, 500);
		}
		;
		break;
	default:
		break;
	};
}
;
