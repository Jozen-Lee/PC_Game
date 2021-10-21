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

// 挡板参数
#define BOARD_DWIDTH 	4
#define BOARD_DHEIGTH	12

// 足球参数
#define BALL_SIZE 5

// 游戏边界
#define LIMIT_UP 20
#define LIMIT_DOWN (240-5)
#define LIMIT_LEFT 5
#define LIMIT_RIGHT (320-5)
#define LIMIT_MID 160

// 碰壁类型
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
	uint16_t loc[2];	// 球心位置x,y
	int	vel[2];				// 球运动速度
	uint16_t radius;	// 球半径
	uint8_t flag;			// 存活的标志位
}	ball;

typedef struct player_t
{
	uint16_t loc[2];	// 玩家挡板位置x,y
	float	vel;				// 挡板运动速度
	uint8_t index;		// 玩家编号
	uint8_t score;		// 得分
}	player;
/* Exported macros -----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
class Football
{
public:
	Football(){}
	~Football(){}
	void Game_Init(void);			// 游戏初始化 
		
private:
	
	/*====================================界面=======================================*/
	void Draw_Map(void);						// 绘制游戏画面
	void Draw_BackGround(void);			// 绘制游戏背景
	void Update_Score(void);				// 更新游戏分数
	void Draw_Player(player& role);	// 绘制玩家
	void Draw_Ball(ball& b);				// 绘制足球

	/*====================================逻辑=======================================*/
	void Ball_Sport(ball& b);		// 足球正常运动
	void Ball_Bound(ball& b);		// 足球碰板反弹
	void Check_Victory(void);		// 检测足球是否入洞,即一方胜利
	uint8_t Collision_Detect(ball& b, float dx, float dy);			// 足球碰壁检测
	uint8_t Collision_Detect(player& role, float dx, float dy);	// 玩家碰壁检测
	/*====================================交互=======================================*/
	void Player_Move(player& role, float dx, float dy);	// 控制某方玩家移动

	/*====================================变量=======================================*/
	ball b; // 足球
	player role1,role2;	// 玩家
	uint8_t score1, score2;
};

/* Exported variables --------------------------------------------------------*/
/* Exported function declarations --------------------------------------------*/

#endif	/* __cplusplus */

#endif	/* define */
	/************************ COPYRIGHT(C) TuTu Studio **************************/
