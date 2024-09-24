#include "../Inc/exercise1.h"

int t1c = 100;
void setTimer(){

};
void timerRun(){
	if(t1c < 0){
			t1c = 100;
//			HAL_GPIO_TogglePin(GPIO, GPIO_Pin);
		};
		t1c--;
};
