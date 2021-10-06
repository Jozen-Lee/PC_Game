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
#include "oled.h"
#include "logo.h"
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Private type --------------------------------------------------------------*/
/* Private function declarations ---------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Start_Interface(void)
{
	int delta;
	// 背景色
	LCD_Clear(WHITE);
	
	// 小太阳
	LCD_Draw_Picture(5,5,5+48,5+32,DARKBLUE,WHITE,gImage_sun);
	
	POINT_COLOR=GREEN;
	Show_Str_Mid(0,60,(uint8_t*)"开始游戏",24,240);
	
	POINT_COLOR=BLUE;
	Show_Str_Mid(0,100,(uint8_t*)"阿巴阿巴出品",24,240);
	Show_Str(70,130,40,16,(uint8_t*)"成员:",12,1);
	Show_Str(110,130,36,48,(uint8_t*)"李爵煜王玲丽张文迪李洪文",12,1);
	
	POINT_COLOR=RED;
	for(int i = 0; i < 4; i ++)
	{
		delta = i*40;
		LCD_DrawRectangle(45+delta,200,45+delta+30,260);
		LCD_DrawRectangle(50+delta,280,50+delta+20,320);
		LCD_Draw_Circle(60+delta,230,10);
		LCD_DrawLine(60+delta,245,60+delta,280);
	}
	
	POINT_COLOR=DARKBLUE;
	LCD_DrawRectangle(40,90,200,200);
}

void GamesChoose_Interface(void)
{
	LCD_Clear(WHITE);
	POINT_COLOR=BLUE;
	Show_Str_Mid(0,80-16,(uint8_t*)"贪吃蛇",32,240);
	POINT_COLOR=RED;
	Show_Str_Mid(0,240-16,(uint8_t*)"俄罗斯方块",32,240);
	
	POINT_COLOR=BLACK;
	LCD_DrawRectangle(30,60,200,100);
	LCD_DrawRectangle(30,220,200,260);
}

	/************************ COPYRIGHT(C) TuTu Studio **************************/
