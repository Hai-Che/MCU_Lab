/*
 * display7seg.c
 *
 *  Created on: Oct 27, 2022
 *      Author: Admin
 */

#include "display7SEG.h"
#include "main.h"
#include "timer.h"

int index_led = 0;
int led_buffer[4] = {0, 0, 0, 0};

void display7SEG(int num)
{
	switch(num)
	{
	case 0:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, RESET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, RESET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, RESET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, SET);
	break;
	case 1:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, SET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, SET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, SET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, SET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, SET);
	break;
	case 2:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, SET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, RESET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, RESET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, SET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, RESET);
	break;
	case 3:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, RESET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, SET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, SET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, RESET);
	break;
	case 4:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, SET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, SET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, SET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, RESET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, RESET);
	break;
	case 5:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, SET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, RESET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, SET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, RESET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, RESET);
	break;
	case 6:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, SET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, RESET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, RESET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, RESET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, RESET);
	break;
	case 7:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, SET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, SET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, SET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, SET);
	break;
	case 8:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, RESET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, RESET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, RESET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, RESET);
	break;
	default:
	HAL_GPIO_WritePin ( S0_GPIO_Port, S0_Pin, RESET);
	HAL_GPIO_WritePin ( S1_GPIO_Port, S1_Pin, RESET);
	HAL_GPIO_WritePin ( S2_GPIO_Port, S2_Pin, RESET);
	HAL_GPIO_WritePin ( S3_GPIO_Port, S3_Pin, RESET);
	HAL_GPIO_WritePin ( S4_GPIO_Port, S4_Pin, SET);
	HAL_GPIO_WritePin ( S5_GPIO_Port, S5_Pin, RESET);
	HAL_GPIO_WritePin ( S6_GPIO_Port, S6_Pin, RESET);
	}
}

void update7SEG (int index) {
	switch(index) {
	case 0:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		display7SEG(led_buffer[index]);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		display7SEG(led_buffer[index]);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		display7SEG(led_buffer[index]);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		display7SEG(led_buffer[index]);
		break;
	default:
		break;
	}
}


void update7SEGBuffer() {
	led_buffer[0] = timer1counter/1000;
	led_buffer[1] = (timer1counter%1000)/100 + 1;
	led_buffer[2] = timer2counter/1000;
	led_buffer[3] = (timer2counter%1000)/100 + 1;
	if (((timer1counter%1000)/100 + 1) % 10 == 0) {
		led_buffer[0] = ((timer1counter%1000)/100 + 1)/10;
		led_buffer[1] = 0;
	}
	if (((timer2counter%1000)/100 + 1) % 10 == 0) {
		led_buffer[2] = ((timer2counter%1000)/100 + 1)/10;
		led_buffer[3] = 0;
	}
}
void display() {
	if (timer3flag == 1) {
	  		  update7SEG(index_led++);
	  		  if (index_led>=4) {
	  			index_led=0;
	  		  }
	  		  update7SEGBuffer();
	  		  setTimer3(250);
	  	  }
}
