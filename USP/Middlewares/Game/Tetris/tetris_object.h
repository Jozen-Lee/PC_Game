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

#ifndef __TETRIS_OBJECT_H_
#define __TETRIS_OBJECT_H_ 

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
									
/* Private include -----------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
	 
/* Private type --------------------------------------------------------------*/
typedef struct 
{
	uint16_t shape[1][16];
}POS_1;

typedef struct 
{
	uint16_t shape[2][16];
}POS_2;

typedef struct 
{
	uint16_t shape[4][16];
}POS_3;

typedef struct 
{
	uint16_t shape[4][16];
}POS_4;

typedef struct 
{
	uint16_t shape[4][16];	
}POS_5;

typedef struct 
{
	uint16_t shape[2][16];
}POS_6;

typedef struct 
{
	uint16_t shape[2][16];	
}POS_7;

/* Exported macros -----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
class Tetris_Object
{
public:
	Tetris_Object(){Object_Init();}
	~Tetris_Object(){}
	POS_1 pos_1;
	POS_2 pos_2;
	POS_3 pos_3;
	POS_4 pos_4;
	POS_5 pos_5;
	POS_6 pos_6;
	POS_7 pos_7;
private:
	void Object_Init(void);
};

/* Exported variables --------------------------------------------------------*/
/* Exported function declarations --------------------------------------------*/

#endif	/* __cplusplus */

#endif	/* define */
	/************************ COPYRIGHT(C) TuTu Studio **************************/