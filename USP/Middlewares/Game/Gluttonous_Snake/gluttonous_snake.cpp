/**
  ******************************************************************************
  * Copyright (c) 2021 - ~, TuTu Studio
  * @file    gluttonous_snake.cpp
  * @author  LJY 2250017028@qq.com
  * @brief   Code for Gluttonous_Snake Game.
  * @date    2021-09-04
  * @version 1.0
  * @par Change Log:
  * <table>
  * <tr><th>Date        <th>Version  <th>Author     <th>Description
  * <tr><td>2021-09-04  <td> 1.0     <td>TuTu  			<td>Creator
  * </table>
  *
  ==============================================================================
                              How to use this driver  
  ==============================================================================
    @note
      -# ��ʼ��
		 
    @warning	
      -# 
	  
  ******************************************************************************
  * @attention
  * 
  * if you had modified this file, please make sure your code does not have many 
  * bugs, update the version Number, write dowm your name and the date, the most
  * important is make sure the users will have clear and definite understanding 
  * through your new brief.
  *
  * <h2><center>&copy; Copyright (c) 2021 - ~,TuTu Studio.
  * All rights reserved.</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gluttonous_snake.h"
#include "lcd.h"
#include "text.h"
#include "touch.h"

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Private type --------------------------------------------------------------*/
/* Private function declarations ---------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

//��m��n�η�,n>=0
uint32_t To_decarate_Num(uint32_t m,uint8_t n)
{
	uint8_t i;
	uint32_t j=1;
	for(i=0;i<n;i++)
	{
		j*=m;
	}
	return j;
}

/**
 *@brief ����ҳ��
 */ 
void Gluttonous_Snake::Game_Map(void)
{
	//̰������ҳ��
	LCD_Clear(WHITE);
	POINT_COLOR=BLACK;
	LCD_DrawRectangle(1, 1, 180, 200);
	LCD_DrawRectangle(2, 2, 179, 199);
	if(object.Get_Snake().size==2)
	{
	LCD_DrawLine(3,3,3,198);
	LCD_DrawLine(178,3,178,198);//Ϊ�˼�ⷽ��,�Ӷ�����
	}
	if(object.Get_Snake().size==3)
	{
	LCD_DrawLine(3,3,179,3);
	LCD_Fill(3,3,5,199,BLACK);
	LCD_Fill(177,3,178,199,BLACK);	
	}
	
	//�ɼ���ӡ��
	LCD_DrawRectangle(180, 1, 240, 100);
	LCD_DrawRectangle(181, 2, 239,  99);
	
	//�ٶȴ�ӡ��
	LCD_DrawRectangle(179, 99, 240,  200);
	LCD_DrawRectangle(180, 100, 239,  199);
	LCD_DrawRectangle(179, 199, 240,  320);
	
	//��һĿ�������ӡ��
	LCD_DrawRectangle(180, 200, 239,  319);
	LCD_DrawRectangle(1, 199, 180,  320);
	
	//������
	LCD_DrawRectangle(2, 200, 179,  319);
	
	//��������
	LCD_Draw_Circle(90 ,230,25); 	//�ϼ�
	LCD_Draw_Circle(90,290,25); 	//�¼�
	LCD_Draw_Circle(40,260,25);		//���
	LCD_Draw_Circle(140,260,25);	//�Ҽ�
}

/**
 *@brief ���ִ�ӡ
 */ 
void Gluttonous_Snake::Font_Print(void)
{
	//�ɼ����ӡ
	POINT_COLOR=BLUE;
 Show_Str(185,10,200,30,(uint8_t*)"�ɼ�",24,0);
	POINT_COLOR=BLACK;
	LCD_DrawLine(181,50, 240, 50);
	POINT_COLOR=RED;
	LCD_ShowNum(190,67,object.Get_Current_Score(),3,16);
	
	//�ٶȿ��ӡ
	POINT_COLOR=BLUE;
  Show_Str(185,110,200,30,(uint8_t*)"�ٶ�",24,0);
	POINT_COLOR=BLACK;
	LCD_DrawLine(181,150, 240, 150);
	POINT_COLOR=RED;
	LCD_ShowNum(195,167,object.Get_Snake().speed,2,16);
	
	//ͨ�ط������ӡ
	POINT_COLOR=BLUE;
	Show_Str(195,210,200,16,(uint8_t*)"ͨ��",16,0);
	Show_Str(195,230,200,16,(uint8_t*)"����",16,0);
  POINT_COLOR=BLACK;
	LCD_DrawLine(181,250, 240, 250);
  LCD_DrawLine(181,275, 240, 275);
	POINT_COLOR=RED;
	LCD_ShowNum(190,255,object.Get_Target_Score(),3,16);
	
	//������ӡ
  Show_Font(90-8,230-8,(uint8_t*)"��",16,0);
	Show_Font(90-8,290-8,(uint8_t*)"��",16,0);
	Show_Font(40-8,260-8,(uint8_t*)"��",16,0);
	Show_Font(140-8,260-8,(uint8_t*)"��",16,0);
}

/**
 *@brief ������ӡ
 */ 
void Gluttonous_Snake::Grade_Print(void)
{
	POINT_COLOR=RED;
	LCD_ShowNum(190,67,object.Get_Current_Score(),3,16);
	LCD_ShowNum(195,167,object.Get_Snake().speed,2,16);
	LCD_ShowNum(190,255,object.Get_Target_Score(),3,16);
}

/**
 *@brief ��Ϸ�����ʼ��
 */ 
void Gluttonous_Snake::Map_Init(void)
{
	// �����ʳ���ʼ��
	object.Snake_Init();
	
	// ��Ϸ�����ͼ��ʼ��
	Game_Map();
	
	// �������ֳ�ʼ��
	Font_Print();
}

/**
 *@brief ��ʼ��Ϣ
 */ 
void Gluttonous_Snake::Beginning_Information(void)
{
	READJ:
	LCD_Clear(BLACK);
	POINT_COLOR=RED;
	Show_Str(120-48,50,200,24,(uint8_t*)"��ʼ��Ϸ",24,1);
	Show_Str(120-48,100,200,24,(uint8_t*)"��Ϸ˵��",24,1);
	POINT_COLOR=WHITE;
	Show_Str(10,250,80,16,(uint8_t*)"����:���Ͱ�����",16,1);
	Show_Str(10,267,40,16,(uint8_t*)"��Ա:",16,1);
	Show_Str(50,267,200,16,(uint8_t*)"���Ŀ�",16,1);
	Show_Str(50,284,200,16,(uint8_t*)"���๢",16,1);
	Show_Str(50,301,200,16,(uint8_t*)"�����",16,1);
		while(1)
	{
					tp_dev.scan(0); 
			if(tp_dev.sta&TP_PRES_DOWN)
			{
		     if(tp_dev.x[0]>(120-48)&&tp_dev.x[0]<(120+48)&&tp_dev.y[0]>(50-0)&&tp_dev.y[0]<(50+24))
				 {
					 break;
				 }
				 if(tp_dev.x[0]>(120-48)&&tp_dev.x[0]<(120+48)&&tp_dev.y[0]>(100-0)&&tp_dev.y[0]<(100+24))
				 {
					 LCD_Clear(WHITE);
					 HAL_Delay(500);
					 Game_Introduction();
					 goto READJ;
				 }
				 
			}
			HAL_Delay(20);
	}
}

/**
 *@brief ��Ϸ˵��
 */ 
void Gluttonous_Snake::Game_Introduction(void)
{
	LCD_Clear(WHITE);
	POINT_COLOR=BLACK;
	Show_Str(20,20,200,24,(uint8_t*)"����ʳ��:",24,0);
	Show_Str(20,48,200,32,(uint8_t*)"С��ÿ��4��ʳ��,�����һ�μ�ǿʳ��",16,0);
	
	//BUFF˵��
	LCD_Fill(20,90-4,20+8,90+4,BROWN);
	Show_Str(20+9,85,200,16,(uint8_t*)":��2��",16,0);
	LCD_Fill(20,110-4,20+8,110+4,BLUE);
	Show_Str(20+9,105,200,16,(uint8_t*)":��3��",16,0);
	LCD_Fill(20,130-4,20+8,130+4,GREEN);
	Show_Str(20+9,125,200,16,(uint8_t*)":��4��",16,0);
	LCD_Fill(20,150-4,20+8,150+4,RED);
	Show_Str(20+9,145,200,16,(uint8_t*)":��5��",16,0);
	
	
	Show_Str(20,180,200,24,(uint8_t*)"�����ٶ�:",24,0);
	Show_Str(20,210,200,48,(uint8_t*)"С�ߵĳɼ�ÿ�θ���ͨ�ط���,�ٶȻ��1,�ٶ����ֵΪ100",16,0);
	
	POINT_COLOR=BLACK;
  LCD_DrawRectangle(120-30,280-30,120+30,280);	
	POINT_COLOR=RED;
	Show_Str(120-24,280-24,48,24,(uint8_t*)"����",24,0);
	
	while(1)
	{
		// ɨ�败������
		tp_dev.scan(0); 
		if(tp_dev.sta&TP_PRES_DOWN)
		{
			 if(tp_dev.x[0]>(120-30)&&tp_dev.x[0]<(120+30)&&tp_dev.y[0]>(280-15)&&tp_dev.y[0]<(280+15))
			 {
				 Map_Init();
				 break;
			 }
		 }
		HAL_Delay(20);
	 }
}

/**
 *@brief ��Ϸ��ʼ����
 */ 
void Gluttonous_Snake::Beginning_Vedio(void)
{
	uint16_t i=0;
	uint16_t j=0;
	uint16_t k=0;
	uint16_t num;
	LCD_Clear(WHITE);
	POINT_COLOR=BLACK;
	LCD_ShowString(120-52,120,112,16,16,(uint8_t*)"Loading...00%");
	LCD_DrawRectangle(120-50,140,120+50,140+20);
  for(i=1;i<=80;i++)
	{
		//�õ���λ����,�ұ�֤num<100
		num=i*100/81; 
		
		//��������ʾ
	  LCD_Fill(120-50,140,120-50+num+1,140+20,BLACK);
		
		//������ʾ
		for(j=0;j<2;j++)
		{
		  k=num/To_decarate_Num(10,1-j);
		  LCD_ShowNum(120-52+80+j*8,120,k,1,16);//������ʾʮλ,��λ
			num-=k*To_decarate_Num(10,1-j);
		}
		HAL_Delay(150);
	}
	
	//100%������ʾ
	LCD_ShowString(120-52,120,112,16,16,(uint8_t*)"Loading...100%");
  HAL_Delay(1000);
}


/**
 *@brief ��Ϸ��ʼ��
 */ 
void Gluttonous_Snake::Game_Init(void)
{
	// ��ӡ��ʼ��Ϣ
	Beginning_Information();
	
	// ���ض���
	Beginning_Vedio();
	
	// �����ʼ��
	Map_Init();
//	TIM3_Init(899,7199); //ÿ100ms���һ��ʳ��
//	TIM2_Init(1499,7199); //�ٶȾ�����ʱ������ֵ
}

	/************************ COPYRIGHT(C) TuTu Studio **************************/
