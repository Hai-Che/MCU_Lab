/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer1flag;
extern int timer2flag;
extern int timer3flag;


void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void timer1Run();
void timer2Run();
void timer3Run();


#endif /* INC_TIMER_H_ */
