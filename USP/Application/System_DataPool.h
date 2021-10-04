/**
  ******************************************************************************
  * @file   System_DataPool.h
  * @brief  All used resources are contained in this file.
  ******************************************************************************
  * @note
  *  - User can define datas including variables ,structs ,and arrays in
  *    this file, which are used in deffrient tasks or services.
**/
#ifndef _DATA_POOL_H_
#define _DATA_POOL_H_

/* Includes ------------------------------------------------------------------*/
/* Middlewares & Drivers Support */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>
#include <stm32f4xx.h>
#include <SRML.h>
#include <TSML.h>
#include "MPUprocess.h"
#include "UpGimbal_Config.h"

/* Macro Definitions ---------------------------------------------------------*/
#define Tiny_Stack_Size       64
#define Small_Stack_Size      128
#define Normal_Stack_Size     256
#define Large_Stack_Size      512
#define Huge_Stack_Size       1024
#define PriorityVeryLow       1
#define PriorityLow           2
#define PriorityBelowNormal   3
#define PriorityNormal        4
#define PriorityAboveNormal   5
#define PriorityHigh          6
#define PrioritySuperHigh     7
#define PriorityRealtime      8

/* HAL Handlers --------------------------------------------------------------*/
extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

extern TIM_HandleTypeDef htim4;

// extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;

extern SPI_HandleTypeDef hspi1;
/* RTOS Resources ------------------------------------------------------------*/
/* Queues */
extern QueueHandle_t  USART_RxPort;
extern QueueHandle_t  USART_TxPort;
extern QueueHandle_t  CAN1_RxPort;
extern QueueHandle_t  CAN2_RxPort;
extern QueueHandle_t  CAN1_TxPort;
extern QueueHandle_t  CAN2_TxPort;

/* Semaphores */
extern SemaphoreHandle_t SemaphoreTargetHandle;
/* Mutexes */
/* Notifications */
/* Other Resources -----------------------------------------------------------*/
#define USART1_RX_BUFFER_SIZE 32
#define USART2_RX_BUFFER_SIZE	64
#define USART3_RX_BUFFER_SIZE 128
#define USART4_RX_BUFFER_SIZE 256
#define USART5_RX_BUFFER_SIZE 512
#define USART6_RX_BUFFER_SIZE 64

/* 通信数据包的ID号 */
#define DR16_ID										19
#define PCvision_ID								37
#define UpGimbalToChassisID_Pitch 0x005
#define UpGimbalToChassisID_Yaw   0x006
#define ChassisToGimbal_ID   			0x003


extern uint8_t Uart1_Rx_Buff[USART1_RX_BUFFER_SIZE];
extern uint8_t Uart2_Rx_Buff[USART2_RX_BUFFER_SIZE];
extern uint8_t Uart3_Rx_Buff[USART3_RX_BUFFER_SIZE];
extern uint8_t Uart4_Rx_Buff[USART4_RX_BUFFER_SIZE];
extern uint8_t Uart5_Rx_Buff[USART5_RX_BUFFER_SIZE];
extern uint8_t Uart6_Rx_Buff[USART6_RX_BUFFER_SIZE];


#endif
/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/
