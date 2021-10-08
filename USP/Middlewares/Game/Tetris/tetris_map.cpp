#include "tetris_map.h"
#include "tetris.h"
#include "tetris_object.h"
#include "diamond_picture.h"
#include "text.h"
#include "delay.h"

extern Condition con_next;
extern Condition con_now;
extern int Scores;

//创建地图
//0:未填充
//1:该位置已经填充 
char Map[MAP_WIDTH][MAP_HEIGTH];

void Draw_Inf(void)
{
	if(con_now.alive == 0) Draw_Diamond(con_next, 0, 1); //清除
	else Draw_Diamond(con_next, 1, 1); // 显示下一个方块的形状
	//贪吃蛇主页面
	LCD_Clear(WHITE);
	POINT_COLOR=BLACK;
	LCD_DrawRectangle(1, 1, 180, 200);
	LCD_DrawRectangle(2, 2, 179, 199);
	LCD_DrawLine(3,3,179,3);
	LCD_Fill(3,3,5,199,BLACK);
	LCD_Fill(177,3,178,199,BLACK);	
	
	
	//下一个图案的打印框
	LCD_DrawRectangle(180, 1, 240, 100);
	LCD_DrawRectangle(181, 2, 239,  99);
	Show_Str_Mid(180,40,(uint8_t*)"下一个",16,60);
	
	//得分打印框
	LCD_DrawRectangle(179, 99, 240,  200);
	LCD_DrawRectangle(180, 100, 239,  199);
	LCD_DrawRectangle(179, 199, 240,  320);
	Show_Str_Mid(180,140,(uint8_t*)"得分",16,60);
	
	
	//操作框
	LCD_DrawRectangle(2, 200, 179,  319);
	
	//操作按键
//	LCD_Draw_Circle(90 ,230,25); 	//上键
//	LCD_Draw_Circle(90,290,25); 	//下键
	LCD_Draw_Circle(40,260,25);		//左键
	LCD_Draw_Circle(140,260,25);	//右键
	
//	OLED_DrawLine(92,0,92,64,1);
//	OLED_DrawLine(92,32,128,32,1);
//	OLED_ShowString(100,0,(uint8_t*)"Next",12);
//	OLED_ShowString(96,33,(uint8_t*)"Score",12);
//	OLED_ShowNum(93,50,Scores,4,16);
}

void Draw_Map(void)
{
	int i,j;
	for(i=0;i<MAP_WIDTH;i++)
	{
		for(j=0;j<MAP_HEIGTH;j++)
		{
			if(Map[i][j]) POINT_COLOR = BLACK;
			else POINT_COLOR = WHITE;
			LCD_DrawPoint(i,j);
		}
	}
}

void Map_Init(void)
{
	int i, j;
	for(i=0;i<MAP_WIDTH;i++)
	{
		for(j=0;j<MAP_HEIGTH;j++)
		{
			Map[i][j] = 0;
		}
	}
}

//返回1:进入游戏
//返回0:退出该界面
uint8_t Game_Interface_Show(void)
{
//	uint8_t key;
//		OLED_Clear();
//		Show_Str(72,16,48,16,(uint8_t*)"Tetris", 16);
//		Show_Str(72,32,48,16,(uint8_t*)"Worlds", 16);
//		OLED_Draw_Picture(2, 10, 66, 60, 1, gImage_diamond);
//		OLED_DrawRectangle(0, 0, 127, 63, 1);
//		OLED_Refresh_Gram();
//		while(1)
//		{
//			key = KEY_Scan(0);
//			if(key == WKUP_PRES) return 1;
//			else if(key == KEY2_PRES) return 0;
//			delay_ms(100);
//		}
}

//返回1:进入游戏
//返回0:退出游戏
//mode: 0 开始游戏 1 重新游戏
uint8_t Game_Show(uint8_t mode)
{
//	uint8_t key;
//	int choice = 0;
//	OLED_Clear();
//	if(mode)
//	{
//		Show_Str(28,8,72,16,(uint8_t*)"Game Over", 16);		
//		Show_Str(16,26,96,16,(uint8_t*)"Your Scores:", 16);
//		OLED_ShowNum(52,44,Scores, 3, 16);
//		OLED_Refresh_Gram();
//		delay_ms(2000); 
//		OLED_Clear();
//		Show_Str(36,14,56,16,(uint8_t*)"Restart", 16);		
//		Show_Str(48,34,32,16,(uint8_t*)"Quit", 16);		
//	}
//	else
//	{
//		Show_Str(44,14,40,16,(uint8_t*)"Start", 16);
//		Show_Str(48,34,32,16,(uint8_t*)"Quit", 16);
//	}
//	OLED_DrawRectangle(30,13,98,31, !choice);		//初始位置
//	OLED_Refresh_Gram();
//	while(1)
//	{
//		key = KEY_Scan(0);
//		if(key == WKUP_PRES)
//		{
//			if(choice == 0) return 1;
//			else return 0;
//		}
//		else if(key == KEY0_PRES||key == KEY1_PRES) 
//		{
//			if(key == KEY0_PRES)
//			{			
//				choice ++;
//				if(choice == 2) choice = 0;
//			}
//			else
//			{
//				choice --;
//				if(choice < 0) choice = 1;
//			}
//		}
//		OLED_DrawRectangle(30,13,98,31, !choice);
//		OLED_DrawRectangle(30,33,98,51,  choice);
//		OLED_Refresh_Gram();
//		My_delay(5); //延时100ms
//	}
}

