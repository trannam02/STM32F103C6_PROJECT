#include "../Inc/exercise1.h"

int time = 2;
unsigned char ledState = 1;
void redOn(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
};
void yellowOn(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
};
void init_exercise1(){
	redOn();
};
void run_exercise1(){
	if(ledState == 1){
		redOn();
	};
	if(ledState == 0){
		yellowOn();
	};
	time--;
	if(time <= 0 || time > 2){
			time = 2;
			ledState = ledState ? 0 : 1;
	};
};
