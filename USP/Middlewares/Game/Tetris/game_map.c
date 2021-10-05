#include "game_map.h"
#include "process.h"
#include "object.h"
#include "diamond_picture.h"

extern Condition con_next;
extern Condition con_now;
extern int Scores;

//创建地图
//0:未填充
//1:该位置已经填充 
char Map[MAP_RIGHT][MAP_BOTTOM];

//void Draw_Inf(void)
//{
//	if(con_now.alive == 0) Draw_Diamond(con_next, 0, 1); //清除
//	else Draw_Diamond(con_next, 1, 1); // 显示下一个方块的形状
//	OLED_DrawLine(92,0,92,64,1);
//	OLED_DrawLine(92,32,128,32,1);
//	OLED_ShowString(100,0,(u8*)"Next",12);
//	OLED_ShowString(96,33,(u8*)"Score",12);
//	OLED_ShowNum(93,50,Scores,4,16);
//}

//void Draw_Map(void)
//{
//	int i,j;
//	for(i=0;i<MAP_RIGHT;i++)
//	{
//		for(j=0;j<MAP_BOTTOM;j++)
//		{
//			if(Map[i][j]) OLED_DrawPoint(i,j,1);
//			else OLED_DrawPoint(i,j,0);
//		}
//	}
//}

//void Map_Init(void)
//{
//	int i, j;
//	for(i=0;i<MAP_RIGHT;i++)
//	{
//		for(j=0;j<MAP_BOTTOM;j++)
//		{
//			Map[i][j] = 0;
//		}
//	}
//}

////返回1:进入游戏
////返回0:退出该界面
//u8 Game_Interface_Show(void)
//{
//	u8 key;
//		OLED_Clear();
//		Show_Str(72,16,48,16,(u8*)"Tetris", 16);
//		Show_Str(72,32,48,16,(u8*)"Worlds", 16);
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
//}

////返回1:进入游戏
////返回0:退出游戏
////mode: 0 开始游戏 1 重新游戏
//u8 Game_Show(u8 mode)
//{
//	u8 key;
//	int choice = 0;
//	OLED_Clear();
//	if(mode)
//	{
//		Show_Str(28,8,72,16,(u8*)"Game Over", 16);		
//		Show_Str(16,26,96,16,(u8*)"Your Scores:", 16);
//		OLED_ShowNum(52,44,Scores, 3, 16);
//		OLED_Refresh_Gram();
//		My_delay(100); //2s	
//		OLED_Clear();
//		Show_Str(36,14,56,16,(u8*)"Restart", 16);		
//		Show_Str(48,34,32,16,(u8*)"Quit", 16);		
//	}
//	else
//	{
//		Show_Str(44,14,40,16,(u8*)"Start", 16);
//		Show_Str(48,34,32,16,(u8*)"Quit", 16);
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
//}

