/**
  ******************************************************************************
  * Copyright (c) 2021 - ~, TuTu Studio
  * @file    App_Drawing.c
  * @author  LJY 2250017028@qq.com
  * @brief   Code for Interface Drawing.
  * @date    2021-10-05
  * @version 1.0
  * @par Change Log:
  * <table>
  * <tr><th>Date        <th>Version  <th>Author     <th>Description
  * <tr><td>2021-09-04  <td> 1.0     <td>TuTu  			<td>Creator
  * </table>
  *
  ==============================================================================
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
#include "App_Drawing.h"
#include "text.h"
#include "lcd.h"
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Private type --------------------------------------------------------------*/
/* Private function declarations ---------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Start_IF_Interface(void)
{
	 
	LCD_Clear(BLACK);
	POINT_COLOR=RED;
	Show_Str(120-48,100,200,24,(uint8_t*)"游戏说明",24,1);
	POINT_COLOR=WHITE;
	Show_Str(10,250,160,16,(uint8_t*)"制作:阿巴阿巴组",16,1);
	Show_Str(10,267,40,16,(uint8_t*)"成员:",16,1);
	Show_Str(50,267,200,16,(uint8_t*)"罗文凯",16,1);
	Show_Str(50,284,200,16,(uint8_t*)"刘洁耿",16,1);
	Show_Str(50,301,200,16,(uint8_t*)"李爵煜",16,1);	
}

	/************************ COPYRIGHT(C) TuTu Studio **************************/
