#include <exercise8.h>

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
void init_exercise8() {
	clearAllClock();
}
;
void setNumberOnClock(int number) {
	switch (number) {
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
		break;
	case 10:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		break;
	case 11:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
		break;
	};
}
;

void clearNumberOnClock(int number){
	switch (number) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
			break;
		case 10:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
			break;
		case 11:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
			break;
		};
};
