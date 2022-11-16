/*
 * global.h
 *
 *  Created on: Oct 27, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "display7SEG.h"
#include "main.h"

#define INIT1			1
#define AUTO_RED1		2
#define AUTO_GREEN1		3
#define AUTO_YELLOW1	4
#define INIT2			7
#define AUTO_RED2		8
#define AUTO_GREEN2		9
#define AUTO_YELLOW2	10
#define MAN_RED			13
#define MAN_GREEN		14
#define MAN_YELLOW		15

extern int status1;
extern int status2;
extern int status;


#endif /* INC_GLOBAL_H_ */
