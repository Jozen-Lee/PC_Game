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

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
TaskHandle_t DeviceIMU_Handle;


/* Private function declarations ---------------------------------------------*/
//void Device_IMU(void *arg);

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
//	xTaskCreate(Device_IMU,							"Dev.IMU", 						Large_Stack_Size,     NULL, PriorityHigh, 			 &DeviceIMU_Handle);
}


/**
 *@brief IMU任务
 */ 
//void Device_IMU(void *arg)
//{
//  /* Cache for Task */
//  TickType_t xLastWakeTime_t = xTaskGetTickCount();
//	TickType_t _xTicksToWait = pdMS_TO_TICKS(1);
//  /* Pre-Load for task */
//  
//  /* Infinite loop */
//  for(;;)
//  {
//		/* 更新IMU数据  */
//		imu.Update();
//		
//		/* 更新电机的角速度状态 */
//		sentry.Update_Motor_Gyro(imu.data.gyro[1], -imu.data.gyro[2]);	
//		
//		/* 更新云台内部IMU状态 */
//		sentry.Update_IMU_Data(-imu.data.pos.pitch, -imu.data.pos.yaw, imu.data.pos.roll);
//		
//		/* 刷新IMU的连接状态 */
//		if(imu.Get_Init_Flag())
//		{
//			checklink.Flag_Update(Check_IMU);
//		}
//		vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);	
//	}
//}


/* User Code End Here ---------------------------------*/

/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/
