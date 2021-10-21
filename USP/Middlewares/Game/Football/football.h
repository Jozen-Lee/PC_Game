/**
  ******************************************************************************
  * Copyright (c) 2021 - ~, TuTu Studio
	* @file    football.h
  * @author  LJY 2250017028@qq.com
  * @brief   Code for Football game.
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

#ifndef _FOOTBALL_H_
#define _FOOTBALL_H_

#ifdef __cplusplus
 extern "C" {
#endif

#ifdef __cplusplus
}
#endif	

#ifdef __cplusplus

/* Includes ------------------------------------------------------------------*/  
#include "System_DataPool.h"
#include "text.h"
/* Private define ------------------------------------------------------------*/
#define NARMAL_SPEED 10
#define FAST_SPEED 5

// �������
#define BOARD_DWIDTH 	4
#define BOARD_DHEIGTH	12

// �������
#define BALL_SIZE 5

// ��Ϸ�߽�
#define LIMIT_UP 20
#define LIMIT_DOWN (240-5)
#define LIMIT_LEFT 5
#define LIMIT_RIGHT (320-5)
#define LIMIT_MID 160

// ��������
#define COLLISION_NULL 	0
#define COLLISION_UP 		1 
#define COLLISION_DOWN 	2 
#define COLLISION_LEFT 	3 
#define COLLISION_RIGHT 4 
/* Private include -----------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
	 
/* Private type --------------------------------------------------------------*/
typedef struct ball_t
{
	uint16_t loc[2];	// ����λ��x,y
	int	vel[2];				// ���˶��ٶ�
	uint16_t radius;	// ��뾶
	uint8_t flag;			// ���ı�־λ
}	ball;

typedef struct player_t
{
	uint16_t loc[2];	// ��ҵ���λ��x,y
	float	vel;				// �����˶��ٶ�
	uint8_t index;		// ��ұ��
	uint8_t score;		// �÷�
}	player;
/* Exported macros -----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
class Football
{
public:
	Football(){}
	~Football(){}
	void Game_Init(void);			// ��Ϸ��ʼ�� 
		
private:
	
	/*====================================����=======================================*/
	void Draw_Map(void);						// ������Ϸ����
	void Draw_BackGround(void);			// ������Ϸ����
	void Update_Score(void);				// ������Ϸ����
	void Draw_Player(player& role);	// �������
	void Draw_Ball(ball& b);				// ��������

	/*====================================�߼�=======================================*/
	void Ball_Sport(ball& b);		// ���������˶�
	void Ball_Bound(ball& b);		// �������巴��
	void Check_Victory(void);		// ��������Ƿ��붴,��һ��ʤ��
	uint8_t Collision_Detect(ball& b, float dx, float dy);			// �������ڼ��
	uint8_t Collision_Detect(player& role, float dx, float dy);	// ������ڼ��
	/*====================================����=======================================*/
	void Player_Move(player& role, float dx, float dy);	// ����ĳ������ƶ�

	/*====================================����=======================================*/
	ball b; // ����
	player role1,role2;	// ���
	uint8_t score1, score2;
};

/* Exported variables --------------------------------------------------------*/
/* Exported function declarations --------------------------------------------*/

#endif	/* __cplusplus */

#endif	/* define */
	/************************ COPYRIGHT(C) TuTu Studio **************************/
