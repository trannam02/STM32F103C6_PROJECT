#include "../Inc/fsm_auto_run.h"

int status = MAN_RED_GREEN;
int timeGreen = 3;
int timeYellow = 2;
int Vertical_value = 3 + 2;
int Horizontal_value = 3;

void fsm_auto_init() {
	status = MAN_RED_GREEN;
	V_Red();
	H_Green();

	update7SEGBuffer(Vertical_value / 10, Vertical_value % 10,
			Horizontal_value / 10, Horizontal_value % 10);
	update7SEG_init();

	setTimer(2, timeGreen * 1000);
	setTimer(4, 1000);
}
;

void fsm_auto_run() {
	switch (status) {
	case MAN_RED_GREEN:
		if (getTimerFlag(4) == 1) {
			Vertical_value--;
			Horizontal_value--;
			setTimer(4, 1000);
		}
		;
		if (getTimerFlag(2) == 1) {
			status = MAN_RED_YELLOW;
			Horizontal_value = timeYellow;
			setTimer(2, timeYellow * 1000);
		}
		;
		update7SEGBuffer(Vertical_value / 10, Vertical_value % 10,
				Horizontal_value / 10, Horizontal_value % 10);

		V_Red();
		H_Green();

		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_RED;
			resetAllSingleLed();
			update7SEGBuffer((timeGreen + timeYellow) / 10,
					(timeGreen + timeYellow) % 10, 0, 2);
			setButtonPressFlag(0, 0);
		}
		;
		break;
	case MAN_RED_YELLOW:
		if (getTimerFlag(4) == 1) {
			Vertical_value--;
			Horizontal_value--;
			setTimer(4, 1000);
		}
		;
		if (getTimerFlag(2) == 1) {
			status = MAN_GREEN_RED;
			Vertical_value = timeGreen;
			Horizontal_value = timeGreen + timeYellow;
			setTimer(2, timeGreen * 1000);
		}
		;
		update7SEGBuffer(Vertical_value / 10, Vertical_value % 10,
				Horizontal_value / 10, Horizontal_value % 10);

		V_Red();
		H_Yellow();

		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_RED;
			resetAllSingleLed();
			update7SEGBuffer((timeGreen + timeYellow) / 10,
					(timeGreen + timeYellow) % 10, 0, 2);
			setButtonPressFlag(0, 0);
		}
		;
		break;
	case MAN_GREEN_RED:
		if (getTimerFlag(4) == 1) {
			Vertical_value--;
			Horizontal_value--;
			setTimer(4, 1000);
		}
		;
		if (getTimerFlag(2) == 1) {
			status = MAN_YELLOW_RED;
			Vertical_value = timeYellow;
			setTimer(2, timeYellow * 1000);
		}
		;

		update7SEGBuffer(Vertical_value / 10, Vertical_value % 10,
				Horizontal_value / 10, Horizontal_value % 10);

		V_Green();
		H_Red();

		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_RED;
			resetAllSingleLed();
			update7SEGBuffer((timeGreen + timeYellow) / 10,
					(timeGreen + timeYellow) % 10, 0, 2);
			setButtonPressFlag(0, 0);
		}
		;
		break;
	case MAN_YELLOW_RED:
		if (getTimerFlag(4) == 1) {
			Vertical_value--;
			Horizontal_value--;
			setTimer(4, 1000);
		}
		;
		if (getTimerFlag(2) == 1) {
			status = MAN_RED_GREEN;
			Vertical_value = timeGreen + timeYellow;
			Horizontal_value = timeGreen;
			setTimer(2, timeGreen * 1000);
		}
		;
		update7SEGBuffer(Vertical_value / 10, Vertical_value % 10,
				Horizontal_value / 10, Horizontal_value % 10);

		V_Yellow();
		H_Red();

		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_RED;
			resetAllSingleLed();
			update7SEGBuffer((timeGreen + timeYellow) / 10,
					(timeGreen + timeYellow) % 10, 0, 2);
			setButtonPressFlag(0, 0);
		}
		;
		break;
	default:
		break;
	};

	update7SEG_run();
}
;
