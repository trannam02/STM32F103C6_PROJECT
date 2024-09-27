#include "../Inc/updateLEDMatrix.h"

const int MAX_LED_MATRIX = 8;
int index_matrix = 0;
uint8_t matrix_buffer[8] = {0x18, 0x24, 0x66, 0x42, 0x81, 0xFF, 0x81, 0x81};

void updateLEDMatrix_init() {
	updateLEDMatrix(0);
	setTimer(0, 100);
}
;
void updateLEDMatrix_run() {
	if (getFlag(0) == 1) {
		updateLEDMatrix(++index_matrix % 8);
		setTimer(0, 100);
	};
}
;
void updateLEDMatrix(int index_matrix) {
	switch (index_matrix) {
	case 0:
		displayLEDMatrix(0, matrix_buffer[0]);
		break;
	case 1:
		displayLEDMatrix(1, matrix_buffer[1]);
		break;
	case 2:
		displayLEDMatrix(2, matrix_buffer[2]);
		break;
	case 3:
		displayLEDMatrix(3, matrix_buffer[3]);
		break;
	case 4:
		displayLEDMatrix(4, matrix_buffer[4]);
		break;
	case 5:
		displayLEDMatrix(5, matrix_buffer[5]);
		break;
	case 6:
		displayLEDMatrix(6, matrix_buffer[6]);
		break;
	case 7:
		displayLEDMatrix(7, matrix_buffer[7]);
		break;
	default:
		break;
	};
}
;

