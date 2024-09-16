/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "button.h"
#include "main.h"
#include "global.h"

int buttonflag1 = 0;
int buttonflag2 = 0;
int buttonflag3 = 0;

int Key1Reg0 = NORMAL_STATE;
int Key1Reg1 = NORMAL_STATE;
int Key1Reg2 = NORMAL_STATE;

int Key2Reg0 = NORMAL_STATE;
int Key2Reg1 = NORMAL_STATE;
int Key2Reg2 = NORMAL_STATE;
int Key2Reg3 = NORMAL_STATE;

int Key3Reg0 = NORMAL_STATE;
int Key3Reg1 = NORMAL_STATE;
int Key3Reg2 = NORMAL_STATE;
int Key3Reg3 = NORMAL_STATE;

int timerforKey2Press = 300;
int timerforKey3Press = 300;

void getKey1Input() {
	Key1Reg0 = Key1Reg1;
	Key1Reg1 = Key1Reg2;
	Key1Reg2 = HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);
	if ((Key1Reg0 == Key1Reg1) && (Key1Reg1 == Key1Reg2)) {
			if (Key1Reg2 == PRESSED_STATE) {
						buttonflag1 = 1;
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
						timerforKey2Press = 300;
					}
		}else {
			timerforKey2Press--;
			if(timerforKey2Press == 0) {
				if (Key2Reg2 == PRESSED_STATE) {
					counter++;
					if (counter>=10) {counter = 0;}
					display7SEG(counter);
					setTimer2(3000);
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
		if (Key3Reg3 != Key3Reg2) {
			Key3Reg3 = Key3Reg2;
			if (Key3Reg2 == PRESSED_STATE) {
						buttonflag3 = 1;
						timerforKey3Press = 300;
					}
		}else {
			timerforKey3Press--;
			if(timerforKey3Press == 0) {
				if (Key3Reg2 == PRESSED_STATE) {
					counter--;
					if (counter<0) {counter = 9;}
					display7SEG(counter);
					setTimer2(3000);
				}
				timerforKey3Press = 100;
			}
		}
	}
}


