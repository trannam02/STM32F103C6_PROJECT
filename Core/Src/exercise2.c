#include "../Inc/exercise2.h"

int redTime = 5;
int yellowTime = 2;
int greenTime = 3;
int sum = 10;
int count = 10;
void redOn(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
};
void yellowOn(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
};
void greenOn(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
};
void init_exercise2(){
	redOn();
};
void run_exercise2(){
	if(count > (sum-redTime) && count <= sum){
		redOn();
	};
	if(count > (sum - redTime - yellowTime)  && count <= (sum - redTime)){
		yellowOn();
	};
	if(count > 0 && count <= (sum - redTime - yellowTime)){
		greenOn();
	};
	count--;
	if(count <= 0 || count > sum) count = sum;
};
