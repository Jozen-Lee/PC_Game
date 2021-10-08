/**
  ******************************************************************************
  * Copyright (c) 2021 - ~, TuTu Studio
  * @file    tetris.cpp
  * @author  LJY 2250017028@qq.com
  * @brief   Code for tetris game core code.
  * @date    2021-09-04
  * @version 1.0
  * @par Change Log:
  * <table>
  * <tr><th>Date        <th>Version  <th>Author     <th>Description
  * <tr><td>2021-10-08  <td> 1.0     <td>TuTu  			<td>Creator
  * </table>
  *
  ==============================================================================
                              How to use this driver  
  ==============================================================================
    @note
      -# 初始化
		 
    @warning	
      -# 
	  
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
#include "tetris.h"
#include "tetris_map.h"
#include "tetris_object.h"
#include "stdlib.h"
#include "time.h"
#include "lcd.h"
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
//储存当前的状态
Condition con_old;
Condition con_now;
Condition con_next;

uint16_t Scores;
uint8_t Over;
/* Private type --------------------------------------------------------------*/
/* Private function declarations ---------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
 *@brief 获取范围[min, max]随机数
 */ 
int Random(int min, int max)
{
	return (rand()%((max-min)+1) + min);
}

//mode: 0 清除 1 显示
//place: 0 显示在游戏界面 1 显示在信息界面
void Draw_Diamond(Condition con, char mode, char place)
{
	uint8_t i, j;
	if(mode) POINT_COLOR = BLACK;
	else POINT_COLOR = WHITE;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if(con.pos[i] & 0x8000)
			{
				if(place) 
				{
					switch(con.num)
					{
						case 1:	 LCD_DrawPoint(102+j,18+i); break;					
						case 2:  LCD_DrawPoint(102+j,14+i); break;
						case 3:  LCD_DrawPoint(104+j,16+i); break;
						case 4:  LCD_DrawPoint(100+j,18+i); break;
						case 5:  LCD_DrawPoint(100+j,18+i); break;
						case 6:  LCD_DrawPoint(104+j,18+i); break;
						case 7:  LCD_DrawPoint(104+j,18+i); break;
					}	
				}
				else 
				{
					if(con.y+i >= 0) LCD_DrawPoint(con.x+j,con.y+i);
				}
			}
			con.pos[i] <<=1;
		}
	}
}

void Game_Processing(uint8_t action)
{
	static uint8_t count = 0;
	if(con_now.alive == 0) Reset_Diamond();
	if(action == TETRIS_RIGHT) Go_R_L(1); 		 //向右移动
	else if(action == TETRIS_LEFT) Go_R_L(0); //向左移动
	if(action == TETRIS_TURN) Pos_Turn();		 //姿态变换
	if(action == TETRIS_QUIT) Over = 1;			 //退出
	count = (count+1)%3;								 //防止下落太快
	if(count == 0) 
	{
		if(Go_Down())	Update_Map(con_now);
		Game_Over();											
	}
	Show_Game();	
	if(con_now.alive == 0) Check_Map();
	
}

void Game_Init(void)
{
	Scores = 0;
	Over = 0;
	LCD_Clear(WHITE);
	Object_Init();
	Map_Init();
	Reset_Diamond(); //更新con_now
	con_now = con_next;
	con_old = con_now;
	Reset_Diamond(); //重置con_next
}

//重置方块信息
void Reset_Diamond(void)
{
	int i;
	if(con_now.alive == 0) 
	{
		con_now = con_next;
		con_old = con_now;
	}
	con_next.alive = 1;
	con_next.num = Random(1,7); //随机获得方块样式
	con_next.x = -4 + 4 * Random(0, 20); // 随机获得起始位置
	con_next.y = -16;
	switch(con_next.num)
	{
		case 1: con_next.pos_choice = 0;
						for(i=0;i<16;i++) con_next.pos[i] = pos_1.shape[con_next.pos_choice][i];
						break;
		case 2: con_next.pos_choice = Random(0,1);
						for(i=0;i<16;i++) con_next.pos[i] = pos_2.shape[con_next.pos_choice][i];
						break;
		case 3: con_next.pos_choice = Random(0,3);
						for(i=0;i<16;i++) con_next.pos[i] = pos_3.shape[con_next.pos_choice][i];
						break;
		case 4: con_next.pos_choice = Random(0,3);
						for(i=0;i<16;i++) con_next.pos[i] = pos_4.shape[con_next.pos_choice][i];
						break;
		case 5: con_next.pos_choice = Random(0,3);
						for(i=0;i<16;i++) con_next.pos[i] = pos_5.shape[con_next.pos_choice][i];
						break;
		case 6: con_next.pos_choice = Random(0,1);
						for(i=0;i<16;i++) con_next.pos[i] = pos_6.shape[con_next.pos_choice][i];
						break;
		case 7: con_next.pos_choice = Random(0,1);
						for(i=0;i<16;i++) con_next.pos[i] = pos_7.shape[con_next.pos_choice][i];
						break;
	}
}

//更新地图函数
void Update_Map(Condition con)
{
	int i, j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
				if(con.pos[i]&0x8000) 
				{
					if(con.y+i >=0)	Map[con.x+j][con.y+i] = 1;
				}
				con.pos[i] <<= 1;			
		}
	}
	con_now.alive = 0;	//更新地图后,该方块就莫得了
}

//清除
void Clear_Map(int p[])
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		if(p[i]!=-1)
		{
//			for(j=p[i]*4;j<p[i]*4+4;j++)
//			{
//				for(k=0;k<MAP_WIDTH;k++)
//				{
//					Map[k][j] = 0;
//				}
//			}
			for(j=p[i]*4+3;j>=0;j--)
			{
				if(j>=4)
				{
					for(k=0;k<MAP_WIDTH;k++)
					{
						Map[k][j] = Map[k][j-4];
					}
				}
				else 
				{
					for(k=0;k<MAP_WIDTH;k++)
					{
						Map[k][j] = 0;
					}					
				}
			}
		}
	}
}

//检测函数
void Check_Map(void)
{
	uint8_t check=0;
	int records[4] = {-1, -1, -1, -1};//记录需要清空的行
	uint8_t t=0;	
	uint8_t i, j;
	for(i=0;i<MAP_HEIGTH/4;i++)
	{
		for(j=0;j<MAP_WIDTH;j++)
		{
			if(Map[j][i*4]) check++;
			else break;
			if(check == MAP_WIDTH-1) 	records[t++] = i;
		}
		check = 0;
	}
	Clear_Map(records);
	Scores += Game_Score(records);
}

//方块下落函数
//0:下落成功
//1:下落失败
uint8_t Go_Down(void)
{
	con_now.y += 4;
	if(Judge_Bottom(con_now)) 
	{
		con_now.y -= 4;
		return 1;
	}
	else 
	{
		return 0;
	}
}

//0:左 1:右
void Go_R_L(char mode)
{
	if(mode) con_now.x += 4;
	else con_now.x -= 4;
	if(Judge_Side(con_now))
	{
		if(mode) con_now.x -= 4;
		else con_now.x += 4;
	}
}

//姿态转换函数
void Pos_Turn(void)
{
	uint8_t i;
	Condition con;
	con = con_now;
	switch(con.num)
	{
		case 1: con.pos_choice = (con.pos_choice + 1)%1;
						for(i=0;i<16;i++) con.pos[i] = pos_1.shape[con.pos_choice][i];
						break;
		case 2: con.pos_choice = (con.pos_choice + 1)%2;
						for(i=0;i<16;i++) con.pos[i] = pos_2.shape[con.pos_choice][i];
						break;
		case 3: con.pos_choice = (con.pos_choice + 1)%4;
						for(i=0;i<16;i++) con.pos[i] = pos_3.shape[con.pos_choice][i];
						break;
		case 4: con.pos_choice = (con.pos_choice + 1)%4;
						for(i=0;i<16;i++) con.pos[i] = pos_4.shape[con.pos_choice][i];
						break;
		case 5: con.pos_choice = (con.pos_choice + 1)%4;
						for(i=0;i<16;i++) con.pos[i] = pos_5.shape[con.pos_choice][i];
						break;
		case 6: con.pos_choice = (con.pos_choice + 1)%2;
						for(i=0;i<16;i++) con.pos[i] = pos_6.shape[con.pos_choice][i];
						break;
		case 7: con.pos_choice = (con.pos_choice + 1)%2;
						for(i=0;i<16;i++) con.pos[i] = pos_7.shape[con.pos_choice][i];
						break;
	}
	if((!Judge_Side(con)) && (!Judge_Bottom(con))) con_now = con;
}

//检测左右是否越界
//返回0:下一次运动未碰壁
//返回1:下一次运动碰壁,无法继续
uint8_t Judge_Side(Condition con)
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if((con.pos[i]&0x8000) && (con.x + j > MAP_WIDTH || Map[con.x + j][con.y + i])) return 1;
				con.pos[i] <<= 1;
		}
	}
	return 0;
}

//检测是否碰到下方
//返回0:下一次运动未碰壁
//返回1:下一次运动碰壁,无法继续
uint8_t Judge_Bottom(Condition con)
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if((con.pos[i] & 0x8000) && con.y+i>=0 && ((Map[con.x+j][con.y+i]) || (con.y + i >= MAP_HEIGTH))) return 1;		
			 con.pos[i] <<= 1;
		}
	}
	return 0;
}

//得分函数
uint8_t Game_Score(int p[])
{
	uint8_t i;
	uint8_t count = 0;
	for(i=0;i<4;i++)
	{
		if(p[i] != -1) count ++;
	}
	switch(count)
	{
		case 0: return 0;
		case 1: return 1;
		case 2: return 3;
		case 3: return 6;
		case 4: return 10;
	}
	return 0;
}

//游戏结束函数
//返回0: 游戏继续
//返回1: 游戏结束
void Game_Over(void)
{
	int i;
	if(Judge_Bottom(con_now) && con_now.y<0)
	{
		for(i=0;i<-con_now.y;i++)
		{
			if(con_now.pos[i]!=0) Over = 1;
		}
	}
}

void Show_Game(void)
{
	Draw_Map();
	Draw_Diamond(con_old,0,0); //清除上一次的方块
	Draw_Diamond(con_now,1,0); //更新当前的方块
	Draw_Inf();
	con_old = con_now; // 显示完后, 更新con_old
}


									/************************ COPYRIGHT(C) TuTu Studio **************************/
