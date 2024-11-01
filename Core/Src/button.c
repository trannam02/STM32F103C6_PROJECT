#include "../Inc/button.h"

int keyReg0s[NO_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE };
int keyReg1s[NO_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE };
int keyReg2s[NO_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE };
int keyRegStables[NO_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE } ;

int longPressDurations[NO_BUTTON] = {LONG_PRESS_DURATION,LONG_PRESS_DURATION,LONG_PRESS_DURATION };

int states[NO_BUTTON] = {RELEASED,RELEASED,RELEASED};
int pressedFlags[NO_BUTTON] = {0,0,0};
int longPressedFlags[NO_BUTTON] = {0,0,0};
void button_init() {
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
//	setTimer(1, TICK);
}
;

//void button_run() {
////	if (getTimerFlag(1) == 1) {
////		setTimer(1, TICK);
////		getKeyInput();
////	};
//	if (pressedFlags[0] == 1) {
//		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
////		pressedFlags[0] = 0;
//	};
//	if (longPressedFlags[0] == 1) {
//		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
//		longPressedFlags[0] = 0;
//	};
//	if (pressedFlags[1] == 1) {
//		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
////		pressedFlags[1] = 0;
//	};
//	if (longPressedFlags[1] == 1) {
//			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
//			longPressedFlags[1] = 0;
//		};
//	if (pressedFlags[2] == 1) {
//		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
////		pressedFlags[2] = 0;
//	};
//	if (longPressedFlags[2] == 1) {
//			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
//			longPressedFlags[2] = 0;
//	};
//}
//;

int getButtonPressFlag(int index){return pressedFlags[index];};
void setButtonPressFlag(int index, int value){pressedFlags[index] = value;};
int getButtonLongPressFlag(int index){return longPressedFlags[index];};
void setButtonLongPressFlag(int index, int value){longPressedFlags[index] = value;};

void getKeyInput() {
	keyReg2s[0] = keyReg1s[0];
	keyReg1s[0] = keyReg0s[0];
	keyReg0s[0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

	keyReg2s[1] = keyReg1s[1];
	keyReg1s[1] = keyReg0s[1];
	keyReg0s[1] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);

	keyReg2s[2] = keyReg1s[2];
	keyReg1s[2] = keyReg0s[2];
	keyReg0s[2] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	for (int i = 0; i < NO_BUTTON; i++) {
		if ((keyReg0s[i] == keyReg1s[i]) && (keyReg1s[i] == keyReg2s[i])) {
			keyRegStables[i] = keyReg0s[i];
			switch (states[i]) {
			case RELEASED:
				if (keyRegStables[i] == PRESSED_STATE) {
					states[i] = PRESSED;
					longPressDurations[i] = LONG_PRESS_DURATION;
				}
				;
				break;
			case PRESSED:
				if (keyRegStables[i] == NORMAL_STATE) {
					pressedFlags[i] = 1;
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
					states[i] = RELEASED;
				} else {
					longPressDurations[i]--;
				}
				;
				if (longPressDurations[i] == 0) {
					longPressedFlags[i] = 1;
					states[i] = LONG_PRESSED;
					longPressDurations[i] = LONG_PRESS_DURATION;
				}
				;
				break;
			case LONG_PRESSED:
				if (keyRegStables[i] == NORMAL_STATE) {
					states[i] = RELEASED;
				} else {
					longPressDurations[i]--;
				}
				;
				if (longPressDurations[i] == 0) {
					longPressedFlags[i] = 1;
					longPressDurations[i] = LONG_PRESS_DURATION;
				}
				;
				break;
			default:
				break;
			};
		};
	};
}
;
