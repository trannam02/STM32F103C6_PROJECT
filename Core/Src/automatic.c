#include "./../Inc/automatic.h"
#include "../Inc/traffic.h"
void automatic_init();
void automatic_run(){
	switch(status){
	case INIT:
		if(1) {
			status = GREEN_RED;
			setTimer(5000); // timer1 chuyen trang thai o auto
		};
		break;
	case GREEN_RED:
		traffic_green_red();
		if(timer2_flag == 1){
			// update display hien thi so
			setTimer3(1000); // 1s update lai so hien thi ( thay lam timer2 ????)
		};
		if(timer1_flag == 1){
			status = YELLOW_RED;
			setTimer(2000); // timer 1 chuyen trang thai o auto
		};
		if(button1_flag == 1){
			status = MAN_GREEN_RED;
			button1_flag = 0;
			setTimer2(10000); // timer2 doi 10s quay ve auto
		};
		break;
	default:
		break;
	};
};

