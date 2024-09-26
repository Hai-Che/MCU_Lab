/*
 * button.h
 *
 *  Created on: Oct 31, 2022
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int buttonflag1;
extern int buttonflag2;
extern int buttonflag3;

void getKey1Input();
void getKey2Input();
void getKey3Input();

#endif /* INC_BUTTON_H_ */
