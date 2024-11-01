#include "../Inc/fsm_manual.h"

void fsm_manual_init() {
}
;
void fsm_manual_run() {
	switch (status) {
	case MAN_INIT:
		update7SEGBuffer(0, 0, 0, 1);
		status = MAN_V_RED_H_RED;
		break;
	case MAN_V_RED_H_RED:
		V_Red();
		H_Red();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_YELLOW_H_RED;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_RED_H_YELLOW;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_RED_H_YELLOW:
		V_Red();
		H_Yellow();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_YELLOW_H_YELLOW;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_RED_H_GREEN;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_RED_H_GREEN:
		V_Red();
		H_Green();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_YELLOW_H_GREEN;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_RED_H_RED;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_YELLOW_H_RED:
		V_Yellow();
		H_Red();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_GREEN_H_RED;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_YELLOW_H_YELLOW;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_YELLOW_H_YELLOW:
		V_Yellow();
		H_Yellow();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_GREEN_H_YELLOW;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_YELLOW_H_GREEN;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_YELLOW_H_GREEN:
		V_Yellow();
		H_Green();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_GREEN_H_GREEN;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_YELLOW_H_RED;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_GREEN_H_RED:
		V_Green();
		H_Red();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_RED_H_RED;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_GREEN_H_YELLOW;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_GREEN_H_YELLOW:
		V_Green();
		H_Yellow();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_RED_H_YELLOW;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_GREEN_H_GREEN;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	case MAN_V_GREEN_H_GREEN:
		V_Green();
		H_Green();
		update7SEGBuffer(0, 0, 0, 1);
		if (getButtonPressFlag(0) == 1) {
			status = MODE_EDIT_INIT;
			setButtonPressFlag(0, 0);
		}
		;
		if (getButtonPressFlag(1) == 1) { // change Vertical traffic light
			status = MAN_V_RED_H_GREEN;
			setButtonPressFlag(1, 0);
		}
		;
		if (getButtonPressFlag(2) == 1) { // change Horizontal traffic light
			status = MAN_V_GREEN_H_RED;
			setButtonPressFlag(2, 0);
		}
		;
		break;
	default:
		break;
	}
}
;
