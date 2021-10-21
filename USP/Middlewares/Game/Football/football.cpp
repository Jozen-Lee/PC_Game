/**
  ******************************************************************************
  * Copyright (c) 2021 - ~, TuTu Studio
  * @file    football.cpp
  * @author  LJY 2250017028@qq.com
  * @brief   Code for Football game.
  * @date    2021-10-20
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
#include "football.h"
#include "main.h"
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private type --------------------------------------------------------------*/
/* Private function declarations ---------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
 *@brief 绘制游戏整体画面
 */ 
void Football::Game_Init(void)
{
	// 分数初始化
	role1.index = 1; role1.score = 0;
	role2.index = 2; role2.score = 0;

	// 玩家位置初始化
	role1.loc[0] = 80; role1.loc[1] = 120; 
	role2.loc[0] = 240; role2.loc[1] = 120; 
	
	// 足球位置初始化
	b.loc[0] = 160; b.loc[1] = 120;
	
	// 绘制整体界面
	Draw_Map();
	
	// 绘制背景
	Draw_BackGround();
	
	// 更新分数
	Update_Score();
	
	// 绘制玩家
	Draw_Player(role1);
	Draw_Player(role2);
	
	// 绘制球
	Draw_Ball(b);

}
/**
 *@brief 绘制游戏整体画面
 */ 
void Football::Draw_Map(void)
{
	// 边界
	POINT_COLOR = BLACK;
	for(int i = 0; i <= 5; i++)
	LCD_DrawRectangle(i,i,320-i,240-i);
	LCD_Fill(0,0,320,20,POINT_COLOR);
	
	// 计分表
	POINT_COLOR = BLACK;
	LCD_Fill(140,0,180,18,WHITE);
	LCD_DrawRectangle(140,0,180,18);
	LCD_ShowChar(160-4,2,':',16,0);
	
	// 球门
	POINT_COLOR = WHITE;
	LCD_Fill(0,100,5,140,POINT_COLOR);
	LCD_Fill(320-5,100,320,140,POINT_COLOR);
}

/**
 *@brief 绘制背景
 */ 
void Football::Draw_BackGround(void)
{
	POINT_COLOR = BLACK;
	LCD_DrawLine(160,20+1,160,240-5-1);
	LCD_Fill(5+1,20+1,160-1,240-5-1,RED);
	LCD_Fill(160+1,20+1,320-5-1,240-5-1,BLUE);
}

/**
 *@brief 更新分数
 */ 
void Football::Update_Score(void)
{
	// 玩家一
	LCD_ShowNum(144,2,score1,1,16);
	
	// 玩家二
	LCD_ShowNum(168,2,score2,1,16);
}

/**
 *@brief 绘制玩家
 */ 
void Football::Draw_Player(player& role)
{
//	POINT_COLOR = role.index == 1 ? BLUE : RED;
	POINT_COLOR = YELLOW;
	// 画线
	LCD_DrawLine(role.loc[0], 21, role.loc[0], 240-6);
	
	// 画板
	LCD_Fill(role.loc[0]-BOARD_DWIDTH, role.loc[1]-BOARD_DHEIGTH,role.loc[0]+BOARD_DWIDTH,role.loc[1]+BOARD_DHEIGTH, POINT_COLOR);
}

/**
 *@brief 绘制足球
 */ 
void Football::Draw_Ball(ball& b)
{
	POINT_COLOR = WHITE;
	for(int i = 1; i <= BALL_SIZE; i ++)
	{
		LCD_Draw_Circle(b.loc[0],b.loc[1],i);
	}
}

/**
 *@brief 足球碰壁检测,返回的方位是相对于足球而言的
 */ 
uint8_t Football::Collision_Detect(ball& b, float dx, float dy)
{
	player* p;
	float x_new = b.loc[0] + dx;
	float y_new = b.loc[1] + dy;
	
	// 边界检测
	if(x_new - BOARD_DWIDTH <= LIMIT_LEFT) 		return COLLISION_LEFT;
	if(x_new + BOARD_DWIDTH >= LIMIT_RIGHT) 	return COLLISION_RIGHT;
	if(y_new - BOARD_DHEIGTH <= LIMIT_UP) 		return COLLISION_UP;
	if(y_new + BOARD_DHEIGTH >= LIMIT_DOWN) 	return COLLISION_DOWN;	
	
	// 碰碰板检测
	for(int i = 0; i < 2; i ++)
	{
		p = i ? &role2 : & role1;
		if(y_new <= p->loc[1] + BOARD_DHEIGTH && y_new >= p->loc[1] - BOARD_DHEIGTH)
		{
			if(b.loc[0] < p->loc[0] && x_new >= p->loc[0] - BOARD_DWIDTH) return COLLISION_RIGHT;
			if(b.loc[0] > p->loc[0] && x_new <= p->loc[0] + BOARD_DWIDTH) return COLLISION_LEFT;
		}
		if(x_new <= p->loc[0] + BOARD_DWIDTH && x_new >= p->loc[0] - BOARD_DWIDTH)
		{
			if(b.loc[1] < p->loc[1] && y_new >= p->loc[1] - BOARD_DHEIGTH) return COLLISION_DOWN;
			if(b.loc[1] > p->loc[1] && y_new <= p->loc[0] + BOARD_DHEIGTH) return COLLISION_UP;			
		}
	}
	return COLLISION_NULL;
}

/**
 *@brief 玩家碰壁检测 0 未碰壁 1 碰壁
 */ 
uint8_t Football::Collision_Detect(player& role, float dx, float dy)
{
	float x_new = role.loc[0] + dx;
	float y_new = role.loc[1] + dy;
	if(role.index == 1)
	{
		if(x_new - BOARD_DWIDTH < LIMIT_LEFT || x_new + BOARD_DWIDTH > LIMIT_MID ||
			y_new - BOARD_DHEIGTH < LIMIT_UP || y_new + BOARD_DHEIGTH > LIMIT_DOWN) return 1;
		else return 0;
	}
	else if(role.index == 2)
	{
		if(x_new - BOARD_DWIDTH < LIMIT_MID || x_new + BOARD_DWIDTH > LIMIT_RIGHT ||
			y_new - BOARD_DHEIGTH < LIMIT_UP || y_new + BOARD_DHEIGTH > LIMIT_DOWN) return 1;
		else return 0;		
	}
	return 0;
}

/**
 *@brief 足球运动
 */ 
void Football::Ball_Sport(ball& b)
{
	for(int i = 0; i < abs(int(b.vel[0])); i ++)
	{
//		if(Collision_Detect(b,1,1))
	}
}

/**
 *@brief 玩家运动
 */ 
void Football::Player_Move(player& role, float dx, float dy)
{
	
}

	/************************ COPYRIGHT(C) TuTu Studio **************************/
