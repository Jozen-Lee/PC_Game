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
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

/* RTOS Resources ------------------------------------------------------------*/
/* Queues */
extern QueueHandle_t  USART_RxPort;
extern QueueHandle_t  USART_TxPort;
extern QueueHandle_t	Action_Port;

/* Mutexes */
/* Notifications */
/* Other Resources -----------------------------------------------------------*/
#define USART1_RX_BUFFER_SIZE 32
#define USART2_RX_BUFFER_SIZE	64

extern uint8_t Uart1_Rx_Buff[USART1_RX_BUFFER_SIZE];
extern uint8_t Uart2_Rx_Buff[USART2_RX_BUFFER_SIZE];

#define DIR_UP 		1
#define DIR_DOWN 	2 
#define DIR_RIGHT 3
#define DIR_LEFT	4
#define GAME_OVER 5
#define GAME_CONTINUE 6

#endif
/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/
