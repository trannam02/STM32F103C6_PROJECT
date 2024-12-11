#include <uart_communication_fsm.h>

int state = UART_INIT;//				<<<====================================================

uint32_t adc_value = 0;
uint8_t str[100];
void uart_communication_init(){

};
void uart_communication_fsm(){
	switch(state){
	case UART_INIT:
		state = UART_IDLE;
		break;
	case UART_IDLE:
		if(getReqFlag() == 1){
			setReqFlag(0);
			state = SEND_PERIOD;
			adc_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (void*)str, sprintf((char*)str, "!ADC=%d#", (int)adc_value), 1000);
			setTimer(2, 2000);
		};
		if(getOKFlag() == 1){
			setOKFlag(0);
		};
		break;
	case SEND_PERIOD:
		if(getOKFlag() == 1){
			setOKFlag(0);
			state = UART_IDLE;
		};
		if(getTimerFlag(2) == 1){
			setTimer(2, 2000);
			HAL_UART_Transmit(&huart2, (void*)str, sizeof(str), 1000);
		};
		break;
	default:
		break;
	};
};
