/**
  ******************************************************************************
  * Copyright (c) 2021 - ~, TuTu Studio
	* @file    .h
  * @author  LJY 2250017028@qq.com
  * @brief   Code for .
  ******************************************************************************
  * @attention
  * 
  * if you had modified this file, please make sure your code does not have many 
  * bugs, update the version Number, write dowm your name and the date, the most
  * important is make sure the users will have clear and definite understanding 
  * through your new brief.
  *
  * <h2><center>&copy; Copyright (c) 2021 - ~, TuTu Studio.
  * All rights reserved.</center></h2>
  ******************************************************************************
  */ 

#ifndef __TETRIS_H_
#define __TETRIS_H_

#ifdef __cplusplus
 extern "C" {
#endif

#ifdef __cplusplus
}
#endif	

#ifdef __cplusplus

/* Includes ------------------------------------------------------------------*/  
#include "stm32f4xx_hal.h"

/* Private define ------------------------------------------------------------*/
#define TETRIS_LEFT  	1	
#define TETRIS_RIGHT 	2
#define TETRIS_TURN 	3
#define TETRIS_QUIT 	4		

/* Private include -----------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
	 
/* Private type --------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/


//储存方块的状态
typedef struct 
{
	uint8_t num; 			 		//当前正在运动的方块
	uint8_t pos_choice; 	//该姿态对应的编号
	uint16_t pos[16]; 		//运动方块对应的姿态
	int x;				 				//方块的横坐标
	int y;				 				//方块的纵坐标
	uint8_t alive;			 	//0:失活 1:存活
} Condition;	

class Tetris
{
public:
	void Game_Init(void);
	void Game_Processing(uint8_t action);
	void Reset_Diamond(void);
	void Update_Map(Condition con);
	void Clear_Map(int p[]);
	void Check_Map(void);
	void Draw_Diamond(Condition con, char mode, char place);
	uint8_t Go_Down(void);
	void Go_R_L(char mode);
	void Pos_Turn(void);
	uint8_t Judge_Side(Condition con);
	uint8_t Judge_Bottom(Condition con);
	void Game_Over(void);
	uint8_t Game_Score(int p[]);
	void Show_Game(void);
	int Random(int a, int b);
private:
};

/* Exported variables --------------------------------------------------------*/
extern Condition con_next;
/* Exported function declarations --------------------------------------------*/

#endif	/* __cplusplus */

#endif	/* define */
	/************************ COPYRIGHT(C) TuTu Studio **************************/
