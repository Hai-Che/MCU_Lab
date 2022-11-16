/*
 * FSM_man.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#include "FSM_man.h"
#include "FSM.h"
#include "display7SEG.h"
#include "button.h"


void FSM_man_run() {
	switch (status) {
	case MAN_RED:
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		led_buffer[0] = 0;
		led_buffer[1] = 1;
		led_buffer[2] = t_red / 10;
		led_buffer[3] = t_red % 10;
			if (timer4flag == 1) {
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				setTimer4(500);
			}
			if (timer3flag == 1) {
			  		  update7SEG(index_led++);
			  		  if (index_led>=4) {
			  			index_led=0;
			  		  }
			  		  setTimer3(250);
			  	  }
			if (buttonflag2 == 1 ) {
				t_red+=1;
				if (t_red>=100) {
					t_red = 1;
				}
				led_buffer[2] = t_red / 10;
				led_buffer[3] = t_red % 10;
				buttonflag2 = 0;
			}
			if (buttonflag3 == 1 ) {
				status1 = INIT1;
				status2 = INIT2;
				buttonflag3 = 0;
				status = 0;
			}
			if (buttonflag1 == 1) {
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
				status = MAN_GREEN;
				buttonflag1 = 0;
				setTimer3(250);
				setTimer4(500);
			}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		led_buffer[0] = 0;
		led_buffer[1] = 2;
		led_buffer[2] = t_green / 10;
		led_buffer[3] = t_green % 10;
			if (timer4flag == 1) {
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				setTimer4(500);
			}
			if (timer3flag == 1) {
			  		  update7SEG(index_led++);
			  		  if (index_led>=4) {
			  			index_led=0;
			  		  }
			  		  setTimer3(250);
			  	  }
			if (buttonflag2 == 1 ) {
				t_green+=1;
				if (t_green>=100) {
					t_green = 1;
				}
				led_buffer[2] = t_green / 10;
				led_buffer[3] = t_green % 10;
				buttonflag2 = 0;
			}
			if (buttonflag3 == 1 ) {
				status1 = INIT1;
				status2 = INIT2;
				buttonflag3 = 0;
				status = 0;
			}
			if (buttonflag1 == 1) {
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
				status = MAN_YELLOW;
				buttonflag1 = 0;
				setTimer3(250);
				setTimer4(500);
			}
		break;
	case MAN_YELLOW:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		led_buffer[0] = 0;
		led_buffer[1] = 3;
		led_buffer[2] = t_yellow / 10;
		led_buffer[3] = t_yellow % 10;
			if (timer4flag == 1) {
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer4(500);
			}
			if (timer3flag == 1) {
			  		  update7SEG(index_led++);
			  		  if (index_led>=4) {
			  			index_led=0;
			  		  }
			  		  setTimer3(250);
			  	  }
			if (buttonflag2 == 1 ) {
				t_yellow+=1;
				if (t_yellow>=100) {
					t_yellow = 1;
				}
				led_buffer[2] = t_yellow / 10;
				led_buffer[3] = t_yellow % 10;
				buttonflag2 = 0;
			}
			if (buttonflag3 == 1 ) {
				status1 = INIT1;
				status2 = INIT2;
				buttonflag3 = 0;
				status = 0;
			}
			if (buttonflag1 == 1) {
				status1 = INIT1;
				status2 = INIT2;
				buttonflag1 = 0;
				status = 0;
			}
		break;
	default:
		break;
	}
}
