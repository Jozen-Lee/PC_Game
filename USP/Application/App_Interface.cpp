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
#include "App_Interface.h"
#include "Service_Devices.h"
#include "App_Drawing.h"
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
TaskHandle_t StartIF_Handle;
TaskHandle_t GamesIF_Handle;

/* Private function declarations ---------------------------------------------*/
void IF_Start(void *arg);
void IF_Games(void *arg);

/* Exported devices ----------------------------------------------------------*/
/* Motor & ESC & Other actuators*/
/* Remote control */

/* IMU & NUC & Other sensors */

/* Other boards */

/* Function prototypes -------------------------------------------------------*/
/**
* @brief  Initialization of interface
* @param  None.
* @return None.
*/
void App_Interface_Init(void)
{
	xTaskCreate(IF_Start,				"IF.Start", 				Small_Stack_Size,     NULL, PriorityHigh, 			 &StartIF_Handle);
	xTaskCreate(IF_Games,				"IF.Games", 				Small_Stack_Size,     NULL, PriorityHigh, 			 &GamesIF_Handle);
}


/**
 *@brief 开始界面任务
 */ 
void IF_Start(void *arg)
{
  /* Cache for Task */
	Start_IF_Interface();
  /* Pre-Load for task */
  /* Infinite loop */
  for(;;)
  {
		vTaskDelay(50);
	}
}

/**
 *@brief 开始界面的触摸屏检测函数
 */ 
uint8_t StartIF_TouchTask(void)
{
	
}

/**
 *@brief 游戏选择界面任务
 */ 
void IF_Games(void *arg)
{
  /* Cache for Task */

  /* Pre-Load for task */
  /* Infinite loop */
  for(;;)
  {
		vTaskDelay(50);
	}
}



/* User Code End Here ---------------------------------*/

/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/
