/*
 * timer.h
 *
 *  Created on: Oct 27, 2022
 *      Author: Admin
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer1flag;
extern int timer2flag;
extern int timer3flag;
extern int timer4flag;
extern int timer1counter;
extern int timer2counter;
extern int timer3counter;
extern int timer4counter;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void timer1Run();
void timer2Run();
void timer3Run();
void timer4Run();

#endif /* INC_TIMER_H_ */
