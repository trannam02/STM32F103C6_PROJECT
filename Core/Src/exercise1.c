#include "../Inc/exercise1.h"

const int TIME = 2;
int redTime = TIME;
int yellowTime = TIME;
char redStatus = 1;
char yellowStatus = 0;
void init_exercise1(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
};
void run_exercise1(){
	if(redTime <= 0){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		redTime = TIME;
	};
	if(yellowTime <= 0){
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			yellowTime = TIME;
	};
	redTime--;
	yellowTime--;
};
