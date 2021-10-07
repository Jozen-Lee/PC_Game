/**
  ******************************************************************************
  * @file   Service_Devices.cpp
  * @brief  Devices service running file.
  ******************************************************************************
  * @note
  *  - Before running your devices, just do what you want ~ !
  *  - More devices or using other classification is decided by yourself ~ !
  ===============================================================================
                                    Task List
  ===============================================================================
  * <table>
  * <tr><th>Task Name     <th>Priority          <th>Frequency/Hz    <th>Stack/Byte
  * <tr><td>              <td>                  <td>                <td>    
  * </table>
  *
 */
/* Includes ------------------------------------------------------------------*/
#include "App_Game.h"
#include "App_Drawing.h"
#include "App_Interface.h"
#include "Service_Devices.h"
#include "gluttonous_snake.h"
#include "ps2.h"
#include "touch.h"
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

// 贪吃蛇
Gluttonous_Snake snake;
TaskHandle_t SnakeGame_Handle;
TaskHandle_t SnakeFood_Handle;
TaskHandle_t SnakeSport_Handle;
TaskHandle_t SnakeOver_Handle;
TaskHandle_t SnakeCtrl_Handle;

//俄罗斯方块
TaskHandle_t TetrisGame_Handle;
//TaskHandle_t DeviceTouch_Handle;

/* Private function declarations ---------------------------------------------*/
void Game_Snake(void *arg);
void Snake_Food(void *arg);
void Snake_Sport(void *arg);
void Snake_Over(void *arg);
void Snake_Ctrl(void *arg);

void Game_Tetris(void *arg);
//void Device_Touch(void *arg);

/* Exported devices ----------------------------------------------------------*/
/* Motor & ESC & Other actuators*/
/* Remote control */

/* IMU & NUC & Other sensors */

/* Other boards */

/* Function prototypes -------------------------------------------------------*/
/**
* @brief  Initialization of game
* @param  None.
* @return None.
*/
void App_Games_Init(void)
{
	// 贪吃蛇
	xTaskCreate(Game_Snake,							"Game.Snake", 					Normal_Stack_Size,    NULL, PriorityHigh, 			 &SnakeGame_Handle);
	xTaskCreate(Snake_Food,							"Snake.Food", 					Small_Stack_Size,     NULL, PriorityHigh, 			 &SnakeFood_Handle);
	xTaskCreate(Snake_Sport,						"Snake.Sport", 					Small_Stack_Size,     NULL, PriorityHigh, 			 &SnakeSport_Handle);
	xTaskCreate(Snake_Over,							"Snake.Over", 					Small_Stack_Size,     NULL, PriorityHigh, 			 &SnakeOver_Handle);	
	xTaskCreate(Snake_Ctrl,							"Snake.Ctrl", 					Small_Stack_Size,     NULL, PriorityHigh, 			 &SnakeCtrl_Handle);
	
	// 俄罗斯方块
	xTaskCreate(Game_Tetris,						"Game.Tetris", 					Small_Stack_Size,     NULL, PriorityHigh, 			 &TetrisGame_Handle);
	
	// 任务全挂起
	vTaskSuspend(SnakeGame_Handle); 
	vTaskSuspend(SnakeFood_Handle); 
	vTaskSuspend(SnakeSport_Handle);
	vTaskSuspend(SnakeOver_Handle);
	vTaskSuspend(SnakeCtrl_Handle);
	vTaskSuspend(TetrisGame_Handle);
}

/* ----------------------------------------------- 贪吃蛇 -------------------------------------------------------------------------*/
/**
 *@brief 贪吃蛇控制任务
 */ 
void Snake_Ctrl(void *arg)
{
  /* Cache for Task */
  /* Pre-Load for task */
	uint8_t cmd;
  /* Infinite loop */
  for(;;)
  {
		if(xQueueReceive(Ctrl_Port,&cmd,portMAX_DELAY) == pdPASS)
		{
			if(cmd == DIR_UP || cmd == DIR_DOWN || cmd == DIR_LEFT || cmd == DIR_RIGHT)		
			{
				snake.object.Get_Snake().direction = cmd;
			}
			OLED_DrawingArrow(cmd);
		}
	}	
}

/**
 *@brief 贪吃蛇说明界面的触屏函数
 */ 
uint8_t Snake_ID_Touch(void)
{
	// 扫描触屏按键
	tp_dev.scan(0); 
	if(tp_dev.sta&TP_PRES_DOWN)
	{
		 if(tp_dev.x[0]>(120-60)&&tp_dev.x[0]<(120+60)&&tp_dev.y[0]>(280-15)&&tp_dev.y[0]<(280+15))
		 {
				return 1;
		 }
		 else return 0;
	}
	else return 0;
}

/**
 *@brief 游戏运行界面的触屏函数
 */ 
uint8_t Snake_Processing_Touch(void)
{ 
	tp_dev.scan(0); 
	uint8_t cmd;
	if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
	{	
		if(tp_dev.x[0]>(90-25)&&tp_dev.x[0]<(90+25)&&tp_dev.y[0]>(230-25)&&tp_dev.y[0]<(230+25))
		{	
			cmd = DIR_UP;
			xQueueSend(Ctrl_Port, &cmd, 0);
		} 
		if(tp_dev.x[0]>(90-25)&&tp_dev.x[0]<(90+25)&&tp_dev.y[0]>(290-25)&&tp_dev.y[0]<(290+25))
		{	
			cmd = DIR_DOWN;
			xQueueSend(Ctrl_Port, &cmd, 0);	
		}
		if(tp_dev.x[0]>(40-25)&&tp_dev.x[0]<(40+25)&&tp_dev.y[0]>(260-25)&&tp_dev.y[0]<(260+25))
		{	
			cmd = DIR_LEFT;
			xQueueSend(Ctrl_Port, &cmd, 0);			
		} 
		if(tp_dev.x[0]>(140-25)&&tp_dev.x[0]<(140+25)&&tp_dev.y[0]>(260-25)&&tp_dev.y[0]<(260+25))
		{	
			cmd = DIR_RIGHT;
			xQueueSend(Ctrl_Port, &cmd, 0);			
		}  			
	}
	return 0;
}

/**
 *@brief 贪吃蛇结束界面的触屏函数
 */ 
uint8_t SnakeOver_Touch(void)
{
	// 扫描触屏按键
	tp_dev.scan(0); 
	if(tp_dev.sta&TP_PRES_DOWN)
	{
		 // 重新开始
		 if(tp_dev.x[0]>40&&tp_dev.x[0]<200&&tp_dev.y[0]>80&&tp_dev.y[0]<110)
		 {
				return 1;
		 }
		 // 返回
		 else if(tp_dev.x[0]>40&&tp_dev.x[0]<200&&tp_dev.y[0]>200&&tp_dev.y[0]<230)
		 {
			 return 2;
		 }
		 else return 0;
	}
	else return 0;
}

/**
 *@brief 贪吃蛇游戏任务
 */ 
void Game_Snake(void *arg)
{
  /* Cache for Task */
	
  /* Pre-Load for task */
	uint8_t res;
  /* Infinite loop */
  for(;;)
  {
		// 说明界面
		snake.Game_Introduction();
		HAL_Delay(500);
		touch_func = Snake_ID_Touch;
		
		// 等待
		xQueueReceive(Action_Port,&res,portMAX_DELAY);
		
		// 游戏初始化
		touch_func = Snake_Processing_Touch;
		snake.Game_Init();
		vTaskResume(SnakeFood_Handle);
		vTaskResume(SnakeSport_Handle);
		vTaskResume(SnakeOver_Handle);
		vTaskResume(SnakeCtrl_Handle);
		
		if(xQueueReceive(Action_Port,&res,portMAX_DELAY) == pdPASS)
		{
			if(res == GAME_OVER) 
			{
				vTaskSuspend(SnakeFood_Handle);
				vTaskSuspend(SnakeSport_Handle);
				vTaskSuspend(SnakeCtrl_Handle);
				vTaskSuspend(NULL);
			}
		}
	}
}

/**
 *@brief 贪吃蛇游戏中的食物更新任务
 */ 
void Snake_Food(void *arg)
{
  /* Cache for Task */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(100);
  /* Pre-Load for task */
  /* Infinite loop */
  for(;;)
  {
		snake.Food_Update();
		vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);	
	}	
}

/**
 *@brief 贪吃蛇游戏中的小蛇移动任务
 */ 
void Snake_Sport(void *arg)
{
  /* Cache for Task */
  /* Pre-Load for task */
	TickType_t _xTicksToWait;
  /* Infinite loop */
  for(;;)
  {
		_xTicksToWait = snake.Get_SnakeSpeed();
		snake.Snake_Sport();
		vTaskDelay(_xTicksToWait);
	}	
}

/**
 *@brief 贪吃蛇游戏中的游戏结束任务
 */ 
void Snake_Over(void *arg)
{
  /* Cache for Task */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(50);
  /* Pre-Load for task */
		uint8_t over;
  /* Infinite loop */
  for(;;)
  {
		if(snake.Game_Over()) 
		{
			// 终止游戏
			over = GAME_OVER;
			xQueueSend(Action_Port, &over, 0);
			vTaskDelay(200);
			
			// 游戏结束界面
			snake.GameOver_Inf();
			HAL_Delay(500);
			touch_func = SnakeOver_Touch;
			if(xQueueReceive(Action_Port,&over,portMAX_DELAY) == pdPASS)
			{
				touch_func = NULL;
				if(over == 1) vTaskResume(SnakeGame_Handle);
				else if(over == 2) vTaskResume(StartIF_Handle);
				vTaskSuspend(NULL);
			}
		}
		vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);	
	}	
}


/**
 *@brief 俄罗斯方块任务
 */ 
void Game_Tetris(void *arg)
{
  /* Cache for Task */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(20);
  /* Pre-Load for task */
  /* Infinite loop */
  for(;;)
  {
		LCD_Clear(BLUE);
		vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);	
	}
}



/* User Code End Here ---------------------------------*/

/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/
