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
      -# ��ʼ��
		 
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
//���浱ǰ��״̬
Condition con_old;
Condition con_now;
Condition con_next;

uint16_t Scores;
uint8_t Over;
/* Private type --------------------------------------------------------------*/
/* Private function declarations ---------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
 *@brief ��ȡ��Χ[min, max]�����
 */ 
int Random(int min, int max)
{
	return (rand()%((max-min)+1) + min);
}

//mode: 0 ��� 1 ��ʾ
//place: 0 ��ʾ����Ϸ���� 1 ��ʾ����Ϣ����
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
	if(action == TETRIS_RIGHT) Go_R_L(1); 		 //�����ƶ�
	else if(action == TETRIS_LEFT) Go_R_L(0); //�����ƶ�
	if(action == TETRIS_TURN) Pos_Turn();		 //��̬�任
	if(action == TETRIS_QUIT) Over = 1;			 //�˳�
	count = (count+1)%3;								 //��ֹ����̫��
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
	Reset_Diamond(); //����con_now
	con_now = con_next;
	con_old = con_now;
	Reset_Diamond(); //����con_next
}

//���÷�����Ϣ
void Reset_Diamond(void)
{
	int i;
	if(con_now.alive == 0) 
	{
		con_now = con_next;
		con_old = con_now;
	}
	con_next.alive = 1;
	con_next.num = Random(1,7); //�����÷�����ʽ
	con_next.x = -4 + 4 * Random(0, 20); // ��������ʼλ��
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

//���µ�ͼ����
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
	con_now.alive = 0;	//���µ�ͼ��,�÷����Ī����
}

//���
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

//��⺯��
void Check_Map(void)
{
	uint8_t check=0;
	int records[4] = {-1, -1, -1, -1};//��¼��Ҫ��յ���
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

//�������亯��
//0:����ɹ�
//1:����ʧ��
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

//0:�� 1:��
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

//��̬ת������
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

//��������Ƿ�Խ��
//����0:��һ���˶�δ����
//����1:��һ���˶�����,�޷�����
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

//����Ƿ������·�
//����0:��һ���˶�δ����
//����1:��һ���˶�����,�޷�����
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

//�÷ֺ���
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

//��Ϸ��������
//����0: ��Ϸ����
//����1: ��Ϸ����
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
	Draw_Diamond(con_old,0,0); //�����һ�εķ���
	Draw_Diamond(con_now,1,0); //���µ�ǰ�ķ���
	Draw_Inf();
	con_old = con_now; // ��ʾ���, ����con_old
}


									/************************ COPYRIGHT(C) TuTu Studio **************************/
