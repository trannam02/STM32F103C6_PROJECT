#include "../Inc/update7SEG.h"

const int MAX_LED = 4;
int index_led = 0;
int dot_state = ON;
int hour = 15;
int minute = 59;
int second = 58;
int led_buffer[4] = { 1, 5, 5, 9 };

void update7SEG_run() {
	if (getFlag(0) == 1) {
		update7SEG(++index_led % 4);
		setTimer(0, 250);
	};
	if (getFlag(1) == 1) {
		if (dot_state == 1) {
			disableDOT();
			dot_state = OFF;
		} else {
			enableDOT();
			dot_state = ON;
		};
		// calc time
		second++;
		if (second >= 60) {
			second = 0;
			minute++;
		};
		if (minute >= 60) {
			minute = 0;
			hour++;
		};
		if (hour >= 24) {
			hour = 0;
		};

		led_buffer[0] = hour / 10;
		led_buffer[1] = hour % 10;
		led_buffer[2] = minute / 10;
		led_buffer[3] = minute % 10;
		setTimer(1, 1000);
	};
}
;

void update7SEG_init() {
	// init four led segment
	index_led = 0;
	enable0();
	display7SEG(led_buffer[0]);

	// init dot
	dot_state = ON;
	enableDOT();

	// init timer
	setTimer(0, 250);
	setTimer(1, 1000);
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

