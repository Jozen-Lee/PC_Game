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
#include "Service_Devices.h"
#include "Sentry_UpGimbal.h"
#include "CheckLink.h"
#include "iwdg.h"

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
TaskHandle_t DeviceUpdateStatus_Handle;
TaskHandle_t DeviceIMU_Handle;
TaskHandle_t DeviceSetYawOffset_Handle;
TaskHandle_t FeedDog_Handle;

/* Private function declarations ---------------------------------------------*/
void Device_UpdateStatus(void *arg);
void Device_IMU(void *arg);
void Device_SetYawOffset(void *arg);
void Device_FeedDog(void *arg);

/* Exported devices ----------------------------------------------------------*/
/* Motor & ESC & Other actuators*/
/* Remote control */

/* IMU & NUC & Other sensors */

/* Other boards */

/* Function prototypes -------------------------------------------------------*/
/**
* @brief  Initialization of device management service
* @param  None.
* @return None.
*/
void Service_Devices_Init(void)
{
  xTaskCreate(Device_UpdateStatus, 		"Dev.UpdateStatus",  	Small_Stack_Size,    	NULL, PriorityHigh,        &DeviceUpdateStatus_Handle);
	xTaskCreate(Device_IMU,							"Dev.IMU", 						Large_Stack_Size,     NULL, PriorityHigh, 			 &DeviceIMU_Handle);
	xTaskCreate(Device_SetYawOffset,		"Dev.SetYawOffset", 	Tiny_Stack_Size,   	  NULL, PriorityHigh, 			 &DeviceSetYawOffset_Handle);
//	xTaskCreate(Device_FeedDog,  		 		"Dev.FeedDog",  			Tiny_Stack_Size,    	NULL, PriorityHigh,        &FeedDog_Handle);
}

/**
 *@brief 连接状态更新任务
 */ 
void Device_UpdateStatus(void *arg)
{
  /* Cache for Task */
  /* Pre-Load for task */

  /* Infinite loop */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(80);
  for(;;)
  {
		/* 更新连接状态 */
		checklink.Status_Update();
		
		/* 若遥控器成功连接，且S1为下挡，则由遥控器控制 */	
		if(checklink.Get_Status(Check_Dr16) == Connected)	
		{
			/* 激光灯和摩擦轮配置 */
			switch(sentry.Get_S1_Data())
			{
				case DR16_SW_UP:
						/* 底盘巡逻关掉激光灯 */
						HAL_GPIO_WritePin(INFRARED_GPIO_Port, INFRARED_Pin, GPIO_PIN_RESET);
						break;
				case DR16_SW_MID:
						/* 开启激光 */
						HAL_GPIO_WritePin(INFRARED_GPIO_Port, INFRARED_Pin, GPIO_PIN_SET);
						break;
				case DR16_SW_DOWN:	
						HAL_GPIO_WritePin(INFRARED_GPIO_Port, INFRARED_Pin, GPIO_PIN_SET);
						break;
			}
			
			/* 模式配置 */
			if(sentry.Get_S1_Data() == DR16_SW_DOWN)
			{
				sentry.mode.ctrl_mode = Dr16_Ctrl;
				sentry.mode.auto_mode = Auto_Dr16;
			}
			else
			{
				if(checklink.Get_Status(Check_PCvision) == Connected)
					sentry.mode.ctrl_mode = PC_Ctrl;
				else
				{
					sentry.mode.ctrl_mode = PC_Lost;
					sentry.mode.auto_mode = Auto_Dr16;
				}
			}
		}
		else
		{
			sentry.mode.ctrl_mode = Dr16_Lost;
			sentry.mode.auto_mode = Auto_Dr16;
			HAL_GPIO_WritePin(INFRARED_GPIO_Port, INFRARED_Pin, GPIO_PIN_RESET);
		}
		
		
    /* Pass control to the next task */
    vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);
  }
}

/**
 *@brief IMU任务
 */ 
void Device_IMU(void *arg)
{
  /* Cache for Task */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(1);
  /* Pre-Load for task */
  
  /* Infinite loop */
  for(;;)
  {
		/* 更新IMU数据  */
		imu.Update();
		
		/* 更新电机的角速度状态 */
		sentry.Update_Motor_Gyro(imu.data.gyro[1], -imu.data.gyro[2]);	
		
		/* 更新云台内部IMU状态 */
		sentry.Update_IMU_Data(-imu.data.pos.pitch, -imu.data.pos.yaw, imu.data.pos.roll);
		
		/* 刷新IMU的连接状态 */
		if(imu.Get_Init_Flag())
		{
			checklink.Flag_Update(Check_IMU);
		}
		vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);	
	}
}

/**
 *@brief Yaw轴误差修正任务
 */ 
void Device_SetYawOffset(void *arg)
{
  /* Cache for Task */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(1e4);
  /* Pre-Load for task */
  
  /* Infinite loop */
  for(;;)
  {
		/* 校准陀螺仪Yaw数据  */
		sentry.CorrectYaw();
		
		vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);	
	}
}

/* 喂狗任务 */
void Device_FeedDog(void *arg)
{
  /* Infinite loop */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(10);
	
	/* 开启看门狗 */
	MX_IWDG_Init();
  for(;;)
 {
		/* 喂狗 */
		HAL_IWDG_Refresh(&hiwdg);
	 
    /* Pass control to the next task */
    vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);
  }	
}

/* User Code End Here ---------------------------------*/

/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/
