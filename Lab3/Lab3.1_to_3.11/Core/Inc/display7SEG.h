/*
 * display7seg.h
 *
 *  Created on: Oct 27, 2022
 *      Author: Admin
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

extern int index_led;
extern int led_buffer[4];

void display7SEG(int num);
void display();
void update7SEG(int index);
void update7SEGBuffer() ;
#endif /* INC_DISPLAY7SEG_H_ */
