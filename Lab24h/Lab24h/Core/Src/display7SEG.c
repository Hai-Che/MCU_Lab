/*
 * display7SEG.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "display7SEG.h"
#include "main.h"
#include "timer.h"


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



