#include "fsm_setting.h"

int mode = 2;

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
			mode = 3;
			tempData = 0;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) {
			tempData++;
			mode = 2;
			update7SEGBuffer((timeGreen + timeYellow + tempData) % 100 / 10,
					(timeGreen + timeYellow + tempData) % 100 % 10, 0, mode);
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) {
			// apply data to timeGreen and timeYellow
			timeGreen = (timeGreen + tempData) % 100;
			tempData = 0;
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
			mode = 4;
			tempData = 0;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) {
			tempData++;
			mode = 3;
			update7SEGBuffer((timeYellow + tempData) % 100 / 10,
					(timeYellow + tempData) % 100 % 10, 0, mode);
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) {
			// apply data to timeGreen and timeYellow
			timeYellow = (timeYellow + tempData) % 100;
			tempData = 0;
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
			mode = 1;
			tempData = 0;
			Vertical_value = timeGreen + timeYellow;
			Horizontal_value = timeGreen;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) {
			tempData++;
			mode = 4;
			update7SEGBuffer((timeGreen + tempData) % 100 / 10,
					(timeGreen + tempData) % 100 % 10, 0, mode);
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) {
			// apply data to timeGreen and timeYellow
			timeGreen = (timeGreen + tempData) % 100;
			tempData = 0;
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
