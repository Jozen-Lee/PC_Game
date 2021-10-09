/**
  ******************************************************************************
  * Copyright (c) 2021 - ~, TuTu Studio
  * @file    tetris_object.cpp
  * @author  LJY 2250017028@qq.com
  * @brief   Code for tetirs_object.
  * @date    2021-09-04
  * @version 1.0
  * @par Change Log:
  * <table>
  * <tr><th>Date        <th>Version  <th>Author     <th>Description
  * <tr><td>2021-09-04  <td> 1.0     <td>TuTu  			<td>Creator
  * </table>
  *
  ==============================================================================
			---------------------------创建不同的方块----------------------------
			POS_1: **
						 **
						 
			POS_2: ****

			POS_3: *
						 *
						 **

			POS_4:  *
							*
						 **
						 
			POS_5:  *
						 ***

			POS_6: *
						 **
							*

			POS_7:  *
						 **
						 *  
  ******************************************************************************
  * @attention
  * 
  * if you had modified this file, please make sure your code does not have many 
  * bugs, update the version Number, write dowm your name and the date, the most
  * important is make sure the users will have clear and definite understanding 
  * through your new brief.
  *
  * <h2><center>&copy; Copyright (c) 2021 - ~,TuTu Studio.
  * All rights reserved.</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "tetris_object.h"
#include "lcd.h"

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Private type --------------------------------------------------------------*/
/* Private function declarations ---------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

	
void Tetris_Object::Object_Init(void)
{
	uint8_t i;
	/*oxxo
		oxxo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_1.shape[0][i]   = 0x0ff0;
	for(i=4;i<8;i++) pos_1.shape[0][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_1.shape[0][i]  = 0x0000;
	for(i=12;i<16;i++) pos_1.shape[0][i] = 0x0000;	
	
	/*oxoo
		oxoo
		oxoo
		oxoo*/
	for(i=0;i<4;i++) pos_2.shape[0][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_2.shape[0][i]   = 0x0f00;
	for(i=8;i<12;i++) pos_2.shape[0][i]  = 0x0f00;
	for(i=12;i<16;i++) pos_2.shape[0][i] = 0x0f00;
	
	/*oooo
		xxxx
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_2.shape[1][i]   = 0x0000;
	for(i=4;i<8;i++) pos_2.shape[1][i]   = 0xffff;
	for(i=8;i<12;i++) pos_2.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_2.shape[1][i] = 0x0000;
	
	/*oxoo
		oxoo
		oxxo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[0][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_3.shape[0][i]   = 0x0f00;
	for(i=8;i<12;i++) pos_3.shape[0][i]  = 0x0ff0;
	for(i=12;i<16;i++) pos_3.shape[0][i] = 0x0000;
	
	/*ooxo
		xxxo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[1][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_3.shape[1][i]   = 0xfff0;
	for(i=8;i<12;i++) pos_3.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_3.shape[1][i] = 0x0000;

	/*xxoo
		oxoo
		oxoo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[2][i]   = 0xff00;
	for(i=4;i<8;i++) pos_3.shape[2][i]   = 0x0f00;
	for(i=8;i<12;i++) pos_3.shape[2][i]  = 0x0f00;
	for(i=12;i<16;i++) pos_3.shape[2][i] = 0x0000;	

	/*oooo
		xxxo
		xooo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[3][i] =   0x0000;
	for(i=4;i<8;i++) pos_3.shape[3][i] =   0xfff0;
	for(i=8;i<12;i++) pos_3.shape[3][i] =  0xf000;
	for(i=12;i<16;i++) pos_3.shape[3][i] = 0x0000;	

	/*ooxo
		ooxo
		oxxo
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[0][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_4.shape[0][i]   = 0x00f0;
	for(i=8;i<12;i++) pos_4.shape[0][i]  = 0x0ff0;
	for(i=12;i<16;i++) pos_4.shape[0][i] = 0x0000;
	
	
	/*oooo
		oxxx
		ooox
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[1][i]   = 0x0000;
	for(i=4;i<8;i++) pos_4.shape[1][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_4.shape[1][i]  = 0x000f;
	for(i=12;i<16;i++) pos_4.shape[1][i] = 0x0000;	
	
	/*ooxx
		ooxo
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[2][i]   = 0x00ff;
	for(i=4;i<8;i++) pos_4.shape[2][i]   = 0x00f0;
	for(i=8;i<12;i++) pos_4.shape[2][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_4.shape[2][i] = 0x0000;	

	
	/*oxoo
		oxxx
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[3][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_4.shape[3][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_4.shape[3][i]  = 0x0000;
	for(i=12;i<16;i++) pos_4.shape[3][i] = 0x0000;	
	
	/*ooxo
		oxxx
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[0][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_5.shape[0][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_5.shape[0][i]  = 0x0000;
	for(i=12;i<16;i++) pos_5.shape[0][i] = 0x0000;	

	/*ooxo
		oxxo
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[1][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_5.shape[1][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_5.shape[1][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_5.shape[1][i] = 0x0000;		
	
	/*oooo
		oxxx
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[2][i]   = 0x0000;
	for(i=4;i<8;i++) pos_5.shape[2][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_5.shape[2][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_5.shape[2][i] = 0x0000;
	
	/*ooxo
		ooxx
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[3][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_5.shape[3][i]   = 0x00ff;
	for(i=8;i<12;i++) pos_5.shape[3][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_5.shape[3][i] = 0x0000;
	
	/*oxoo
		oxxo
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_6.shape[0][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_6.shape[0][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_6.shape[0][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_6.shape[0][i] = 0x0000;
	
	/*oxxo
		xxoo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_6.shape[1][i]   = 0x0ff0;
	for(i=4;i<8;i++) pos_6.shape[1][i]   = 0xff00;
	for(i=8;i<12;i++) pos_6.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_6.shape[1][i] = 0x0000;
	
	/*ooxo
		oxxo
		oxoo
		oooo*/
	for(i=0;i<4;i++) pos_7.shape[0][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_7.shape[0][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_7.shape[0][i]  = 0x0f00;
	for(i=12;i<16;i++) pos_7.shape[0][i] = 0x0000;

	
	/*xxoo
		oxxo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_7.shape[1][i]   = 0xff00;
	for(i=4;i<8;i++) pos_7.shape[1][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_7.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_7.shape[1][i] = 0x0000;
}

									/************************ COPYRIGHT(C) TuTu Studio **************************/
