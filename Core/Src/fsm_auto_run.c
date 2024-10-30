#include "../Inc/fsm_auto_run.h"

int status = MAN_RED_GREEN;

void fsm_auto_init(){
	status = MAN_RED_GREEN;
	setTimer(2, 3000);
};

void fsm_auto_run(){
	switch(status){
	case MAN_RED_GREEN:

		break;
	case MAN_RED_YELLOW:
		break;
	case MAN_GREEN_RED:
		break;
	case MAN_YELLOW_RED:
		break;
	}
}
