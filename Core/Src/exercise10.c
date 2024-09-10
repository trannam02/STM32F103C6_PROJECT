#include "../Inc/exercise10.h"

// EXERCISE 10

int h = 10;
int m = 16;
int s = 45;

void displayAnalogClock(int _h, int _m, int _s);
void clearClock(int _h, int _m, int _s);
void init_exercise10() {
	clearAllClock();
}
;

void run_exercise10() {
	displayAnalogClock(h, m, s);
	s++;
	if (s >= 60) {
		s = 0;
		m++;
	}
	;
	if (m >= 60) {
		m = 0;
		h++;
	}
	;
	if (h >= 24) {
		h = 0;
	};
}
;
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

void clearNumberOnClock(int number) {
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
}
;

void displayAnalogClock(int _h, int _m, int _s) {
	int h = _h % 12;
	int m = _m / 5;
	int s = _s / 5;
	// fit with index of clock
	if (h == 0)
		h = 12;
	if (m == 0)
		m = 12;
	if (s == 0)
		s = 12;
	h--;
	m--;
	s--;
	clearAllClock();
	setNumberOnClock(h);
	setNumberOnClock(m);
	setNumberOnClock(s);
}
;
