/*
 * button.c
 *
 *  Created on: Oct 31, 2022
 *      Author: Admin
 */

#include "button.h"
#include "main.h"
#include "FSM_man.h"
#include "FSM.h"

int buttonflag1 = 0;
int buttonflag2 = 0;
int buttonflag3 = 0;

int Key1Reg0 = NORMAL_STATE;
int Key1Reg1 = NORMAL_STATE;
int Key1Reg2 = NORMAL_STATE;
int Key1Reg3 = NORMAL_STATE;

int Key2Reg0 = NORMAL_STATE;
int Key2Reg1 = NORMAL_STATE;
int Key2Reg2 = NORMAL_STATE;
int Key2Reg3 = NORMAL_STATE;

int Key3Reg0 = NORMAL_STATE;
int Key3Reg1 = NORMAL_STATE;
int Key3Reg2 = NORMAL_STATE;

int timerforKey1Press = 50;
int timerforKey2Press = 50;

void getKey1Input() {
	Key1Reg0 = Key1Reg1;
	Key1Reg1 = Key1Reg2;
	Key1Reg2 = HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);
	if ((Key1Reg0 == Key1Reg1) && (Key1Reg1 == Key1Reg2)) {
		if (Key1Reg3 != Key1Reg2) {
			Key1Reg3 = Key1Reg2;
			if (Key1Reg2 == PRESSED_STATE) {
						buttonflag1 = 1;
						timerforKey1Press = 300;
					}
		}else {
			timerforKey1Press--;
			if(timerforKey1Press == 0) {
				if (Key1Reg2 == PRESSED_STATE) {
					buttonflag1 = 1;
				}
				timerforKey1Press = 100;
			}
		}
	}
}

void getKey2Input() {
	Key2Reg0 = Key2Reg1;
	Key2Reg1 = Key2Reg2;
	Key2Reg2 = HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin);
	if ((Key2Reg0 == Key2Reg1) && (Key2Reg1 == Key2Reg2)) {
		if (Key2Reg3 != Key2Reg2) {
			Key2Reg3 = Key2Reg2;
			if (Key2Reg2 == PRESSED_STATE) {
						buttonflag2 = 1;
						timerforKey2Press = 100;
					}
		}else {
			timerforKey2Press--;
			if(timerforKey2Press == 0) {
				if (Key2Reg2 == PRESSED_STATE) {
					switch (status) {
					case MAN_RED:
						t_red+=1;
						if (t_red>=100) {
							t_red = 1;
						}
						led_buffer[2] = t_red / 10;
						led_buffer[3] = t_red % 10;
						break;
					case MAN_GREEN:
						t_green+=1;
						if (t_green>=100) {
							t_green = 1;
						}
						led_buffer[2] = t_green / 10;
						led_buffer[3] = t_green % 10;
						break;
					case MAN_YELLOW:
						t_yellow+=1;
						if (t_yellow>=100) {
							t_yellow = 1;
						}
						led_buffer[2] = t_yellow / 10;
						led_buffer[3] = t_yellow % 10;
						break;
					}
				}
				timerforKey2Press = 100;
			}
		}
	}
}

void getKey3Input() {
	Key3Reg0 = Key3Reg1;
	Key3Reg1 = Key3Reg2;
	Key3Reg2 = HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin);
	if ((Key3Reg0 == Key3Reg1) && (Key3Reg1 == Key3Reg2)) {
			if (Key3Reg2 == PRESSED_STATE) {
						buttonflag3 = 1;
			}
	}
}
