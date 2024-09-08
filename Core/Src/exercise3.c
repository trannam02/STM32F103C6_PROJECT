#include "../Inc/exercise3.h"

//int redTime = 5;
//int yellowTime = 2;
//int greenTime = 3;
int sum = RED + GREEN + YELLOW;
int count1 = 10;
int count2 = 5;
void redOnV() {
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, SET);
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET);
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET);
}
;
void yellowOnV() {
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, SET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET);
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, SET);
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET);
}
;
void greenOnV() {
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, SET);
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET);
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET);
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, SET);
}
;
void redOnH() {
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, SET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, SET);
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET);
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET);
}
;
;
void yellowOnH() {
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, SET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET);
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET);
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, SET);

}
;
void greenOnH() {
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET);
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, SET);
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET);

}
;
void init_exercise3() {
	redOnV();
	greenOnH();
}
;
void run_exercise3() {
	if (count1 > (sum - RED) && count1 <= sum) {
		redOnV();
	};
	if (count1 > (sum - RED - GREEN) && count1 <= (sum - RED)) {
		greenOnV();
	};
	if (count1 > 0 && count1 <= (sum - RED - GREEN)) {
		yellowOnV();
	};
	if (count2 > (sum - RED) && count2 <= sum) {
		redOnH();
	};
	if (count2 > (sum - RED - GREEN) && count2 <= (sum - RED)) {
		greenOnH();
	};
	if (count2 > 0 && count2 <= (sum - RED - GREEN)) {
		yellowOnH();
	};
	count1--;
	count2--;
	if (count1 <= 0 || count1 > sum)
		count1 = sum;
	if (count2 <= 0 || count2 > sum)
		count2 = sum;
}
;
