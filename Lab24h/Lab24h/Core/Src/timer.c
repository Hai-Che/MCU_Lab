/*
 * timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include"timer.h"

int timer1counter = 0;
int timer2counter = 0;
int timer3counter = 0;

int timer1flag = 0;
int timer2flag = 0;
int timer3flag = 0;


void setTimer1 (int duration) {
	timer1counter = duration/10;
	timer1flag = 0;
}
void setTimer2 (int duration) {
	timer2counter = duration/10;
	timer2flag = 0;
}
void setTimer3 (int duration) {
	timer3counter = duration/10;
	timer3flag = 0;
}

void timer1Run() {
	if (timer1counter > 0) {
		timer1counter--;
		if (timer1counter <= 0) {
			timer1flag = 1;
		}
	}
}
void timer2Run() {
	if (timer2counter > 0) {
		timer2counter--;
		if (timer2counter <= 0) {
			timer2flag = 1;
		}
	}
}
void timer3Run() {
	if (timer3counter > 0) {
		timer3counter--;
		if (timer3counter <= 0) {
			timer3flag = 1;
		}
	}
}

