#include <command_parser_fsm.h>

int status = IDLE;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t idx = 0;
uint8_t buffer_flag = 0;

uint8_t request_flag = 0;
uint8_t ok_flag = 0;


void command_parser_init() {
	HAL_UART_Receive_IT(&huart2, &temp, 1);
}
;
uint8_t getReqFlag(){
	return request_flag;
};
void setReqFlag(uint8_t value){
	request_flag = value;
};
uint8_t getOKFlag(){
	return ok_flag;
};
void setOKFlag(uint8_t value){
	ok_flag = value;
};
uint8_t getBufferFlag(){
	return buffer_flag;
};
void setBufferFlag(uint8_t value){
	buffer_flag = value;
};
void command_parser_fsm() {
	switch (status) {
	case INIT:
		status = IDLE;
		break;
	case IDLE:
		idx = index_buffer-1 >= 0 ? index_buffer-1 : MAX_BUFFER_SIZE - 1;
		if (buffer[idx] == '!') {
			status = STATE_MARK;
			buffer_flag = 0;
			break;
		}
		;
	case STATE_MARK: // this is !
		idx = index_buffer-1 >= 0 ? index_buffer-1 : MAX_BUFFER_SIZE - 1;
		if (buffer[idx] == '!') {
			status = STATE_MARK;
			buffer_flag = 0;
			break;
		}
		;
		if (buffer[idx] == 'R') {
			status = STATE_R;
			buffer_flag = 0;
			break;
		}
		;
		if (buffer[idx] == 'O') {
			status = STATE_O;
			buffer_flag = 0;
			break;
		}
		;
		status = IDLE;
		buffer_flag = 0;
		break;
	case STATE_R:
		idx = index_buffer-1 >= 0 ? index_buffer-1 : MAX_BUFFER_SIZE - 1;
		if (buffer[idx] == '!') {
			status = STATE_MARK;
			buffer_flag = 0;
			break;
		}
		;
		if (buffer[idx] == 'S') {
			status = STATE_S;
			buffer_flag = 0;
			break;
		}
		;
		status = IDLE;
		buffer_flag = 0;
		break;
	case STATE_S:
		idx = index_buffer-1 >= 0 ? index_buffer-1 : MAX_BUFFER_SIZE - 1;
		if (buffer[idx] == '!') {
			status = STATE_MARK;
			buffer_flag = 0;
			break;
		}
		;
		if (buffer[idx] == 'T') {
			status = STATE_T;
			buffer_flag = 0;
			break;
		}
		;
		status = IDLE;
		buffer_flag = 0;
		break;
	case STATE_T:
		idx = index_buffer-1 >= 0 ? index_buffer-1 : MAX_BUFFER_SIZE - 1;
		if (buffer[idx] == '!') {
			status = STATE_MARK;
			buffer_flag = 0;
			break;
		}
		;
		if (buffer[idx] == '#') {
			status = IDLE;
			// do something like set flag, timer 3s ...
//			HAL_UART_Transmit(&huart2, (uint8_t*)"hehe\n", 4, 50);
			request_flag = 1;
			buffer_flag = 0;
			break;
		}
		;
		status = IDLE;
		buffer_flag = 0;
		break;
	case STATE_O:
		idx = index_buffer-1 >= 0 ? index_buffer-1 : MAX_BUFFER_SIZE - 1;
		if (buffer[idx] == '!') {
			status = STATE_MARK;
			buffer_flag = 0;
			break;
		}
		;
		if (buffer[idx] == 'K') {
			status = STATE_K;
			// do something like set flag, timer 3s ...
			buffer_flag = 0;
			break;
		}
		;
		status = IDLE;
		buffer_flag = 0;
		break;
	case STATE_K:
		idx = index_buffer-1 >= 0 ? index_buffer-1 : MAX_BUFFER_SIZE - 1;
		if (buffer[idx] == '!') {
			status = STATE_MARK;
			buffer_flag = 0;
			break;
		}
		;
		if (buffer[idx] == '#') {
			status = IDLE;
			// do something like set flag, timer 3s ...
//			HAL_UART_Transmit(&huart2, (uint8_t*)"Ngon", 4, 50);
			ok_flag = 1;
			buffer_flag = 0;
			break;
		}
		;
		status = IDLE;
		buffer_flag = 0;
		break;
	case STATE_SHARP:
		status = IDLE;
		break;
	default:
		break;
	};
}
;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) {
		buffer[index_buffer++] = temp;
		if (index_buffer == 30)
			index_buffer = 0;
		buffer_flag = 1;
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	};
}
;
