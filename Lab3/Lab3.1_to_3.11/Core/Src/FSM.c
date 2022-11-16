/*
 * FSM.c
 *
 *  Created on: Oct 27, 2022
 *      Author: Admin
 */

#include "FSM.h"
#include "button.h"
#include "FSM_man.h"

int t_red=5;
int t_green=3;
int t_yellow=2;

void FSM1_run() {
	switch(status1) {
	case INIT1:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		status1 = AUTO_RED1;
		setTimer1(t_red*1000);
		setTimer3(250);
		break;
	case AUTO_RED1:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			display();
		if (timer1flag == 1) {
			status1 = AUTO_GREEN1;
			setTimer1(t_green*1000);
		}
		if (buttonflag1 == 1) {
					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
					status1 = 0;
					status2 = 0;
					status = MAN_RED;
					buttonflag1 = 0;
					setTimer3(250);
					setTimer4(500);
				}
		break;
	case AUTO_GREEN1:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			display();
		if (timer1flag == 1) {
			status1 = AUTO_YELLOW1;
			setTimer1(t_yellow*1000);
		}
		if (buttonflag1 == 1) {
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
					status1 = 0;
					status2 = 0;
					status = MAN_RED;
					buttonflag1 = 0;
					setTimer3(250);
					setTimer4(500);
				}
		break;
	case AUTO_YELLOW1:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
			display();
		if (timer1flag == 1) {
			status1 = AUTO_RED1;
			setTimer1(t_red*1000);
		}
		if (buttonflag1 == 1) {
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
					status1 = 0;
					status2 = 0;
					status = MAN_RED;
					buttonflag1 = 0;
					setTimer3(250);
					setTimer4(500);
				}
		break;
	default:
		break;
	}
}
void FSM2_run() {
	switch(status2) {
	case INIT2:
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		status2 = AUTO_GREEN2;
		setTimer2(t_green*1000);
		break;
	case AUTO_GREEN2:
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);

		if (timer2flag == 1) {
			status2 = AUTO_YELLOW2;
			setTimer2(t_yellow*1000);
		}
		break;
	case AUTO_YELLOW2:
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);

		if (timer2flag == 1) {
			status2 = AUTO_RED2;
			setTimer2(t_red*1000);
		}
		break;
	case AUTO_RED2:
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);

		if (timer2flag == 1) {
			status2 = AUTO_GREEN2;
			setTimer2(t_green*1000);
		}
		break;
	default:
		break;
	}
}
