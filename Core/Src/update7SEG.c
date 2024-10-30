#include "../Inc/update7SEG.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {0,0,0,0};

void update7SEGBuffer(int led0, int led1, int led2, int led3){
	led_buffer[0] = led0;
	led_buffer[1] = led1;
	led_buffer[2] = led2;
	led_buffer[3] = led3;
};

void update7SEG_init() {
	// init four led segment
	index_led = 0;
	enable0();
	display7SEG(led_buffer[0]);

	// init timer
	setTimer(3, 250);
}
;
void update7SEG_run() {
	if (getTimerFlag(3) == 1) {
		update7SEG(++index_led % 4);
		setTimer(3, 250);
	};
}
;
void update7SEG(int index) {
	switch (index) {
	case 0:
		enable0();
		display7SEG(led_buffer[0]);
		break;
	case 1:
		// Display the second 7 SEG with led_buffer [1]
		enable1();
		display7SEG(led_buffer[1]);
		break;
	case 2:
		// Display the third 7 SEG with led_buffer [2]
		enable2();
		display7SEG(led_buffer[2]);
		break;
	case 3:
		// Display the forth 7 SEG with led_buffer [3]
		enable3();
		display7SEG(led_buffer[3]);
		break;
	default:
		break;
	}
}
;

