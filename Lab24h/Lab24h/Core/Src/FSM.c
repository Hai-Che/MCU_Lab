/*
 * FSM.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "FSM.h"
#include "button.h"

void FSM_run() {
	switch(status) {
	case NORMAL:
		if (timer2flag == 1) {
			  display7SEG(counter--);
			  if (timer3flag == 0) {
			  if (counter < 0) {
				  counter = 9;
			  }
			  } else if (timer3flag == 1) {
				  if (counter < 0) {
					  counter = 0;
				  }
			  }
			  setTimer2(1000);
		}
		if (buttonflag1 == 1) {
			status = RES;
			setTimer2(10);
			setTimer3(10000);
			buttonflag1 = 0;
		}
		if (buttonflag2 == 1) {
			status = INC;
			setTimer2(5000);
			setTimer3(10000);
			buttonflag2 = 0;
		}
		if (buttonflag3 == 1) {
			status = DEC;
			setTimer2(5000);
			setTimer3(10000);
			buttonflag3 = 0;
		}
		break;
	case RES:
		counter = 0;
		display7SEG(counter);
		if (timer2flag == 1) {
			status = NORMAL;
			setTimer2(10);
		}
		break;
	case INC:
		if (buttonflag2 == 1) {
			counter++;
			if (counter>=10) {counter = 0;}
			display7SEG(counter);
			buttonflag2 = 0;
			setTimer2(3000);
			setTimer3(10000);
		}
		if (buttonflag3 == 1) {
			status = DEC;
			setTimer2(5000);
			setTimer3(10000);
			buttonflag3 = 0;
		}
		if (timer2flag == 1) {
			status = NORMAL;
			setTimer2(10);
		}
		if (buttonflag1 == 1) {
			status = RES;
			setTimer2(10);
			setTimer3(10000);
			buttonflag1 = 0;
		}
		break;
	case DEC:
		if (buttonflag3 == 1) {
			counter--;
			if (counter<0) {counter = 9;}
			display7SEG(counter);
			buttonflag3 = 0;
			setTimer2(3000);
			setTimer3(10000);
		}
		if (buttonflag2 == 1) {
			status = INC;
			setTimer2(5000);
			setTimer3(10000);
			buttonflag2 = 0;
		}
		if (timer2flag == 1) {
			status = NORMAL;
			setTimer2(10);
		}
		if (buttonflag1 == 1) {
			status = RES;
			setTimer2(10);
			setTimer3(10000);
			buttonflag1 = 0;
		}
		break;
	default:
		break;
	}
}
