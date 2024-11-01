#include "fsm_setting.h"

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
			update7SEGBuffer(timeYellow / 10,
								timeYellow % 10, 0, 3);
			tempData = 0;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) {
			tempData++;
			update7SEGBuffer((timeGreen + timeYellow + tempData) % 100 / 10,
					(timeGreen + timeYellow + tempData) % 100 % 10, 0, 2);
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
			update7SEGBuffer(timeGreen / 10,
											timeGreen % 10, 0, 4);
			tempData = 0;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) {
			tempData++;
			update7SEGBuffer((timeYellow + tempData) % 100 / 10,
					(timeYellow + tempData) % 100 % 10, 0, 3);
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
			tempData = 0;

			Vertical_value = timeGreen + timeYellow;
			Horizontal_value = timeGreen;
			update7SEGBuffer(Vertical_value / 10, Vertical_value % 10,
							Horizontal_value / 10, Horizontal_value % 10);
			V_Red();
			H_Green();
			setTimer(2, timeGreen * 1000);
			setTimer(4, 1000);

			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) {
			tempData++;

			update7SEGBuffer((timeGreen + tempData) % 100 / 10,
					(timeGreen + tempData) % 100 % 10, 0, 4);
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
