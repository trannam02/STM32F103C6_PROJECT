#include "../Inc/exercise6.h"


// EXERCISE 6 + 7


//int redTime = 5;
//int yellowTime = 2;
//int greenTime = 3;
void clearAllClock() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
}
;
void init_exercise6() {
	clearAllClock();
}
;
void run_exercise6() {

}
;

