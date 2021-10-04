/**
  ***********************************************************************************
  * @file   : Service_Communication.cpp
  * @brief  : Communication support file.This file provides access ports to interface
  *           with connected devices.
  ***********************************************************************************
                                 ##### Port List #####
  =================================================================================
  |Port Name     Physical-Layer     Data-Link-Layer    Application-Layer    Number
  |————————————————————————————————————————
  |EXAMPLE_Port       CAN1               CAN                CUSTOM            0
  |CAN2_Port          CAN2               CAN                Custom            1
  |EBUG_Port         USART1             Custom              Custom            2
  |USART2_Port       USART2              DBUS               DJI-DR16          3
  *
**/
/* Includes ------------------------------------------------------------------*/
#include "Service_Communication.h"
#include "Sentry_UpGimbal.h"
#include "CheckLink.h"
#include "PCvision.h"
#include "Sentry_Controler.h"
/* Private define ------------------------------------------------------------*/
void Task_UsartRecieve(void *arg);
void Task_UsartTransmit(void *arg);
void Task_CAN1Transmit(void *arg);
void Task_CAN2Transmit(void *arg);
void Task_CAN1Receive(void *arg);
void Task_CAN2Receive(void *arg);

/**
* @brief  Initialization of communication service
* @param  None.
* @return None.
*/
void Service_Communication_Init(void)
{
  
  /* CAN Filter Config*/
  CAN_Filter_Mask_Config(&hcan1, CanFilter_1 |CanFifo_0|Can_STDID|Can_DataType,ChassisToGimbal_ID,0x000);//筛选器:|编号|FIFOx|ID类型|帧类型|ID|屏蔽位(0x3ff,0x1FFFFFFF)|
  CAN_Filter_Mask_Config(&hcan2, CanFilter_15|CanFifo_0|Can_STDID|Can_DataType,0x200,0x000);//筛选器:|编号|FIFOx|ID类型|帧类型|ID|屏蔽位(0x3ff,0x1FFFFFFF)|
  CAN_Filter_Mask_Config(&hcan1, CanFilter_14|CanFifo_0|Can_STDID|Can_DataType,0x199,0x000);//筛选器:|编号|FIFOx|ID类型|帧类型|ID|屏蔽位(0x3ff,0x1FFFFFFF)|
  
  xTaskCreate(Task_UsartRecieve,	"Com.Usart RxPort" , 	Small_Stack_Size,    		NULL, PriorityHigh,   			&UsartRxPort_Handle);
  xTaskCreate(Task_UsartTransmit,	"Com.Usart TxPort" , 	Small_Stack_Size,    		NULL, PriorityHigh,   			&UsartTxPort_Handle);
	xTaskCreate(Task_CAN1Receive,		"Com.CAN1 RxPort" , 	Normal_Stack_Size,    	NULL, PriorityHigh,   			&CAN1RxPort_Handle);
	xTaskCreate(Task_CAN2Receive,		"Com.CAN2 RxPort" , 	Normal_Stack_Size,    	NULL, PriorityHigh,   			&CAN2RxPort_Handle);
	xTaskCreate(Task_CAN1Transmit,	"Com.CAN1 TxPort" , 	Normal_Stack_Size,    	NULL, PriorityHigh,   			&CAN1TxPort_Handle);
	xTaskCreate(Task_CAN2Transmit,	"Com.CAN2 TxPort" , 	Normal_Stack_Size,    	NULL, PriorityHigh,   			&CAN2TxPort_Handle);
}

/*----------------------------------------------- CAN Manager ---------------------------------------------*/
/*Task Define ---------------------------*/
TaskHandle_t CAN1TxPort_Handle;
TaskHandle_t CAN2TxPort_Handle;
TaskHandle_t CAN1RxPort_Handle;
TaskHandle_t CAN2RxPort_Handle;
static void Convert_Data(CAN_RxMessage* input, CAN_COB* output);


/*Function Prototypes--------------------*/
void Task_CAN1Transmit(void *arg)
{
  /* Cache for Task */
//  uint8_t free_can_mailbox;
	CAN_COB CAN_TxMsg;
	
  /* Pre-Load for task */
  
  /* Infinite loop */
  for(;;)
  {
    /* CAN1 Send Port */
    if(xQueueReceive(CAN1_TxPort,&CAN_TxMsg,portMAX_DELAY) == pdPASS)
    {
//      do{
//        free_can_mailbox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
//      }while(free_can_mailbox == 0);
      CANx_SendData(&hcan1,CAN_TxMsg.ID,CAN_TxMsg.Data,CAN_TxMsg.DLC);
    }
  }
}

void Task_CAN2Transmit(void *arg)
{
  /* Cache for Task */
//  uint8_t free_can_mailbox;
	CAN_COB CAN_TxMsg;
	
  /* Pre-Load for task */
  
  /* Infinite loop */
  for(;;)
  {
    /* CAN2 Send Port */
    if(xQueueReceive(CAN2_TxPort,&CAN_TxMsg,portMAX_DELAY) == pdPASS)
    {
//      do{
//        free_can_mailbox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan2);
//      }while(free_can_mailbox == 0);
      CANx_SendData(&hcan2,CAN_TxMsg.ID,CAN_TxMsg.Data,CAN_TxMsg.DLC);
    }
  }	
}

void Task_CAN1Receive(void *arg)
{
  /* Cache for Task */
  CAN_COB CAN_RxMsg;
	
  /* Pre-Load for task */
  
  /* Infinite loop */
  
  for(;;)
  {
    /* CAN1 Receive Port */
    if(xQueueReceive(CAN1_RxPort,&CAN_RxMsg,portMAX_DELAY) == pdPASS)
    {
			/* 更新CAN1连接状态标志位 */
			checklink.Flag_Update(Check_CAN1);
			
			/* 更新电机数据 */
			sentry.Update_Motor_Data(&CAN_RxMsg);
			
			/* 更新电机连接状态 */
			if(checklink.Get_Status(Check_Motors) == Unconnected)
			{
				if(sentry.Get_Motors_Linkness()) checklink.Flag_Update(Check_Motors);
			}
			else
			{
				checklink.Flag_Update(Check_Motors);
			}
    }
  }
}
void Task_CAN2Receive(void *arg)
{
  /* Cache for Task */
  CAN_COB CAN_RxMsg;
	
  /* Pre-Load for task */
  
  /* Infinite loop */
  
  for(;;)
  {
    /* CAN2 Receive Port */
    if(xQueueReceive(CAN2_RxPort,&CAN_RxMsg,portMAX_DELAY) == pdPASS)
    {
			/* 更新CAN2连接状态标志位 */
			checklink.Flag_Update(Check_CAN2);
			
			/* 更新底盘传输过来的数据 */
			sentry.Update_Chassis_Data(&CAN_RxMsg);
			
			/* 更新Dr16状态 */
			if(CAN_RxMsg.ID == Dr16_S1S2 || CAN_RxMsg.ID == Dr16_LXY_NORE)
			{
				checklink.Flag_Update(Check_Dr16);
				
				/* 根据底盘发送过来的Dr16数据进行控制 */
				if(sentry.mode.ctrl_mode == Dr16_Ctrl)
				{
					xTaskNotifyGive(Dr16Control_Handle);
					//xTaskNotifyGive(SinControl_Handle);
				}
				else if(sentry.mode.ctrl_mode == PC_Lost && sentry.Get_S1_Data() == DR16_SW_UP)
				{
					xTaskNotifyGive(PCvisionPatrol_Handle);
				}
			}
			
			/* 更新referee状态 */
			if(CAN_RxMsg.ID == UpperCtrlID) 
			{
				checklink.Flag_Update(Check_Referee);				
			}			
    }
  }
}
/**
* @brief  Callback function in CAN Interrupt
* @param  None.
* @return None.
*/
void CAN1_CallBack(CAN_RxBuffer *CAN_RxMessage)
{
  static CAN_COB   CAN_RxCOB;
  Convert_Data(CAN_RxMessage,&CAN_RxCOB);
  //Send To CAN Receive Queue
  if(CAN1_RxPort != NULL)
    xQueueSendFromISR(CAN1_RxPort,&CAN_RxCOB,0);
}

void CAN2_CallBack(CAN_RxBuffer *CAN_RxMessage)
{
  static CAN_COB   CAN_RxCOB;
  Convert_Data(CAN_RxMessage,&CAN_RxCOB);
  //Send To CAN Receive Queue
  if(CAN2_RxPort != NULL)
    xQueueSendFromISR(CAN2_RxPort,&CAN_RxCOB,0);
}

/**
* @brief  Data convertion，provide lower layer access port 
          for application layer.
* @param  CAN_RxMsg：Lower layer CAN frame.
          CAN_RxCOB：Application layer CAN Frame.
* @return None.
*/
static void Convert_Data(CAN_RxMessage* input, CAN_COB* output)
{
  output->ID = input->header.StdId;
  output->DLC = input->header.DLC;
  memcpy(output->Data, input->data, output->DLC);
}

/*---------------------------------------------- USART Manager --------------------------------------------*/
/*Task Define ---------------------------*/
TaskHandle_t UsartRxPort_Handle;
TaskHandle_t UsartTxPort_Handle;

/*Function Prototypes--------------------*/
/**
* @brief  Tasks for USART Management.
          Attention:In this version we passing the pointer of data not copying
          data itself and we only have one buff zone, so user need to process 
          the data as soon as possible in case of over-write.
* @param  None.
* @return None.
*/

void Task_UsartRecieve(void *arg)
{
	USART_COB Usart_RxCOB;
	for(;;)
  {
    /* Usart Recevice Port */ 
		if(xQueueReceive(USART_RxPort,&Usart_RxCOB,portMAX_DELAY) == pdPASS)
    {
			switch(Usart_RxCOB.port_num)
			{
				case 2: break;
				case 3: break;
				case 4: break;
				case 5: break;
				case 6:
					vision.ReceiveMsgFromPC(&Usart_RxCOB);
				
					/* 更新连接状态 */
					if(vision.data.flag == PC_Patrol || vision.data.flag == PC_Track)
					{
						checklink.Flag_Update(Check_PCvision);
					}
					
					/* 进入视觉指定的任务 */
					if(sentry.mode.ctrl_mode == PC_Ctrl)
					{
						/* 结合云台手的判断选择任务 */
						if(sentry.Get_UpperOperation() == Operation_OutEngineer && vision.data.flag == PC_Track)
						{
							xTaskNotifyGive(PCvisionPatrol_Handle);
						}
						else
						{
							if(vision.data.flag == PC_Patrol)
							{
								sentry.mode.auto_mode = Auto_Patrol;
								xTaskNotifyGive(PCvisionPatrol_Handle);
							}
							else if(vision.data.flag == PC_Track)
							{
								sentry.mode.auto_mode = Auto_Track;
								xTaskNotifyGive(PCvisionTrack_Handle);						
							}
						}
					}
					break;
			}
    }
  }
}

void Task_UsartTransmit(void *arg)
{
  /* Cache for Task */
	PackToVisionDef pack;
	
  /* Pre-Load for task */
	pack.head = 0x00;
	pack.tail = 0xFF;
  
	float pitch_speed_send, yaw_speed_send;
  /* Infinite loop */
  TickType_t xLastWakeTime_t = xTaskGetTickCount();
	TickType_t _xTicksToWait = pdMS_TO_TICKS(1);
  for(;;)
  {
		/* 更新数据包 */
		pack.Pitch = sentry.status._gim.pitch_angle;
		sentry.SpeedOut(&pitch_speed_send, &yaw_speed_send);
		pack.YawSpeed = yaw_speed_send / 16.4f;
		pack.PitchSpeed = pitch_speed_send / 16.4f;
		pack.hightower_flag = sentry.Get_HighTower_Status();
		pack.SelfColor = sentry.chassis_com.OtherInformationPack.SelfColour;
		if(sentry.chassis_com.OtherInformationPack.SelfColour == red) 
		{
			if(sentry.Get_Outpost_Status() || (sentry.Get_S1_Data() == DR16_SW_MID && sentry.Get_S2_Data() == DR16_SW_DOWN))
				pack.SelfColor = RED_OUTPOST_L;
			else pack.SelfColor = RED_OUTPOST_D;
		}
		else if(sentry.chassis_com.OtherInformationPack.SelfColour == blue)
		{
			if(sentry.Get_Outpost_Status() || (sentry.Get_S1_Data() == DR16_SW_MID && sentry.Get_S2_Data() == DR16_SW_DOWN))
				pack.SelfColor = BLUE_OUTPOST_L;
			else pack.SelfColor = BLUE_OUTPOST_D;			
		}
		
		/* 发送数据给小电脑 */
		vision.SendMsgToPC(&pack);
		vTaskDelayUntil(&xLastWakeTime_t, _xTicksToWait);
  }	
}

/**
* @brief  Callback function in USART Interrupt
* @param  None.
* @return None.
*/

uint32_t User_UART2_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen)
{
  static USART_COB Usart_RxCOB;
  //Send To UART Receive Queue
  if(USART_RxPort != NULL)
  {
    Usart_RxCOB.port_num = 2;
    Usart_RxCOB.len      = ReceiveLen;
    Usart_RxCOB.address  = Recv_Data;
    xQueueSendFromISR(USART_RxPort,&Usart_RxCOB,0);
  }
  return 0;
}

uint32_t User_UART3_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen)
{
  static USART_COB Usart_RxCOB;
  //Send To UART Receive Queue
  if(USART_RxPort != NULL)
  {
    Usart_RxCOB.port_num = 3;
    Usart_RxCOB.len      = ReceiveLen;
    Usart_RxCOB.address  = Recv_Data;
    xQueueSendFromISR(USART_RxPort,&Usart_RxCOB,0);
  }
  return 0;
}

uint32_t User_UART4_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen)
{
  static USART_COB Usart_RxCOB;
  //Send To UART Receive Queue
  if(USART_RxPort != NULL)
  {
    Usart_RxCOB.port_num = 4;
    Usart_RxCOB.len      = ReceiveLen;
    Usart_RxCOB.address  = Recv_Data;
    xQueueSendFromISR(USART_RxPort,&Usart_RxCOB,0);
  }
  return 0;
}

uint32_t User_UART5_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen)
{
  static USART_COB Usart_RxCOB;
  //Send To UART Receive Queue
  if(USART_RxPort != NULL)
  {
    Usart_RxCOB.port_num = 5;
    Usart_RxCOB.len      = ReceiveLen;
    Usart_RxCOB.address  = Recv_Data;
    xQueueSendFromISR(USART_RxPort,&Usart_RxCOB,0);
  }
  return 0;
}

uint32_t User_UART6_RxCpltCallback(uint8_t* Recv_Data, uint16_t ReceiveLen)
{
  static USART_COB Usart_RxCOB;
  //Send To UART Receive Queue
  if(USART_RxPort != NULL)
  {
    Usart_RxCOB.port_num = 6;
    Usart_RxCOB.len      = ReceiveLen;
    Usart_RxCOB.address  = Recv_Data;
    xQueueSendFromISR(USART_RxPort,&Usart_RxCOB,0);
  }
  return 0;
}
/************************ COPYRIGHT(C) SCUT-ROBOTLAB **************************/
