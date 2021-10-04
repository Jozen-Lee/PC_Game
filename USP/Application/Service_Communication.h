/**
  **********************************************************************************
  * @file   ：Service_Communication.h
  * @brief  ：Header of Service_Communication.cpp
  **********************************************************************************
**/
#ifndef  _SERVICE_COMMUNICATE_H_
#define  _SERVICE_COMMUNICATE_H_

#include "System_DataPool.h"
#ifdef  __cplusplus
extern uint8_t Uart1_Rx_Buff[USART1_RX_BUFFER_SIZE];
extern uint8_t Uart2_Rx_Buff[USART2_RX_BUFFER_SIZE];
extern uint8_t Uart3_Rx_Buff[USART3_RX_BUFFER_SIZE];
extern uint8_t Uart4_Rx_Buff[USART4_RX_BUFFER_SIZE];
extern uint8_t Uart5_Rx_Buff[USART5_RX_BUFFER_SIZE];
extern uint8_t Uart6_Rx_Buff[USART6_RX_BUFFER_SIZE];

extern "C"{
#endif
/*------------------------------ System Handlers ------------------------------*/
extern TaskHandle_t CAN1TxPort_Handle;
extern TaskHandle_t CAN2TxPort_Handle;
extern TaskHandle_t CAN1RxPort_Handle;
extern TaskHandle_t CAN2RxPort_Handle;
extern TaskHandle_t UsartRxPort_Handle;
extern TaskHandle_t UsartTxPort_Handle;

/*------------------------------Function prototypes ---------------------------*/
uint32_t User_UART2_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen);
uint32_t User_UART3_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen);
uint32_t User_UART4_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen);
uint32_t User_UART5_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen);
uint32_t User_UART6_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen);

void CAN1_CallBack(CAN_RxBuffer *CAN_RxMessage);	
void CAN2_CallBack(CAN_RxBuffer *CAN_RxMessage);
	
void Service_Communication_Init(void);
	
#ifdef  __cplusplus
}
#endif
#endif  

/************************* COPYRIGHT SCUT-ROBOTLAB *****END OF FILE****************/

