/**
  ******************************************************************************
  * @file   System_config.cpp
  * @brief  Deploy resources,tasks and services in this file.
  ******************************************************************************
  * @note
  *  - Before running your Task you should first include your headers and init- 
  *    ialize used resources in "System_Resource_Init()". This function will be 
  *    called before tasks Start.
  *    
  *  - All tasks should be created in "System_Tasks_Init()", this function will
  *    be called in 'defaultTask()'.
  *
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
#include "System_Config.h"
#include "System_DataPool.h"

/* Service */
#include "Service_Devices.h"
#include "Service_Debug.h"
#include "Service_Communication.h"

/* User support package & SRML */
#include <SRML.h>
#include <TSML.h>
#include "Sentry_Controler.h"
#include "UpperMonitor.h"
#include "Sentry_UpGimbal.h"
#include "CheckLink.h"

/* Private variables ---------------------------------------------------------*/
uint8_t mpu_set_offset = 0;
long offset_data[3];
/*Founctions------------------------------------------------------------------*/
/**
* @brief Load drivers ,modules, and data resources for tasks.
* @note  Edit this function to add Init-functions and configurations.
*/
void System_Resource_Init(void)
{
  /* Drivers Init ---------------------*/
  Timer_Init(&htim4, USE_HAL_DELAY);
  
	CAN_Init(&hcan1, &CAN1_CallBack);
  CAN_Init(&hcan2, &CAN2_CallBack);
  
  Uart_Init(&huart1, Uart1_Rx_Buff, USART1_RX_BUFFER_SIZE,RecHandle);
  Uart_Init(&huart6, Uart6_Rx_Buff, USART6_RX_BUFFER_SIZE,User_UART6_RxCpltCallback);
  
  
  /* RTOS resources Init --------------*/
  USART_RxPort    = xQueueCreate(4,sizeof(USART_COB));
  USART_TxPort    = xQueueCreate(4,sizeof(USART_COB));
  CAN1_RxPort 		= xQueueCreate(10,sizeof(CAN_COB));
	CAN2_RxPort			= xQueueCreate(4,sizeof(CAN_COB));
  CAN1_TxPort 		= xQueueCreate(10,sizeof(CAN_COB));
	CAN2_TxPort			= xQueueCreate(4,sizeof(CAN_COB));	
	
  /* Other resources Init -------------*/
	
	/* 激光灯 */
	HAL_GPIO_WritePin(INFRARED_GPIO_Port, INFRARED_Pin, GPIO_PIN_RESET);
	
	/* 状态指示 */
	checklink.Init(INDICATOR_SDA_GPIO_Port, INDICATOR_SCL_Pin, INDICATOR_SDA_Pin);
	
	/* PID定时器 */
	myPIDTimer::getMicroTick_regist(Get_SystemTimer); 
	
	/* 控制器 */
	Gimbal_Controler_init();
	
	/* IMU */
	imu.Init(IMU_SDA_GPIO_Port, IMU_SCL_Pin, IMU_SDA_Pin);
	if(mpu_set_offset)
	{
		output_offset_accel(offset_data);
		flash_erase_address(ADDR_FLASH_SECTOR_11, 3);
		flash_write_single_address(ADDR_FLASH_SECTOR_11, (uint32_t *)offset_data, 3);
	}
	else 
	{
		flash_read(ADDR_FLASH_SECTOR_11, (uint32_t *)offset_data, 3);
		set_offset_accel(offset_data);
	}
	
  /* Modules Init ---------------------*/
	sentry.Init();

  /* Service configurations -----------*/
	System_Tasks_Init();
}  

/**
* @brief Load and start User Tasks. 
* @note  Edit this function to add tasks into the activated tasks list.
*/
void System_Tasks_Init(void)
{ 
  /* Syetem Service init --------------*/
  Service_Debug_Init();
  Service_Devices_Init();
  Service_Communication_Init();
	
  /* Applications Init ----------------*/
	Sentry_Controler_Init();
}



/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/

