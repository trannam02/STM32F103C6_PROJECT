#include "../Inc/button.h"
int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;
int keyRegStable = NORMAL_STATE;
const int DURATION = 100;
int longPressDuration = DURATION;

void button_init(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	setTimer(0, 2);
};

void button_run(){
	if(getTimerFlag(0) == 1){
		getKeyInput();
		setTimer(0, 2);
	};
};

void getKeyInput(){
	keyReg2 = keyReg1;
	keyReg1 = keyReg0;
	keyReg0 = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);

	if( (keyReg0 == keyReg1) && (keyReg1 == keyReg2) ){
		if(keyReg0 != keyRegStable){ // doi trang thai
			keyRegStable = keyReg0;
			if(keyRegStable == PRESSED_STATE){
				longPressDuration = DURATION;
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
			};
		}else{ // khong doi trang thai
			longPressDuration--;
			if(longPressDuration == 0){
				longPressDuration = DURATION;
				if(keyRegStable == PRESSED_STATE){
					// TODO long press
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				};
			};
		};
	};
};
