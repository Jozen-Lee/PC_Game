#include "object.h"

/********************创建不同的方块******************
POS_1: **
			 **
			 
POS_2: ****

POS_3: *
			 *
			 **

POS_4:  *
				*
			 **
			 
POS_5:  *
			 ***

POS_6: *
			 **
			  *

POS_7:  *
			 **
			 *
****************************************************/


struct POS_1 pos_1;
struct POS_2 pos_2;
struct POS_3 pos_3;
struct POS_4 pos_4;
struct POS_5 pos_5;
struct POS_6 pos_6;
struct POS_7 pos_7;

void Object_Init(void)
{
	uint8_t i;
	/*oxxo
		oxxo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_1.shape[0][i]   = 0x0ff0;
	for(i=4;i<8;i++) pos_1.shape[0][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_1.shape[0][i]  = 0x0000;
	for(i=12;i<16;i++) pos_1.shape[0][i] = 0x0000;	
	
	/*oxoo
		oxoo
		oxoo
		oxoo*/
	for(i=0;i<4;i++) pos_2.shape[0][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_2.shape[0][i]   = 0x0f00;
	for(i=8;i<12;i++) pos_2.shape[0][i]  = 0x0f00;
	for(i=12;i<16;i++) pos_2.shape[0][i] = 0x0f00;
	
	/*oooo
		xxxx
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_2.shape[1][i]   = 0x0000;
	for(i=4;i<8;i++) pos_2.shape[1][i]   = 0xffff;
	for(i=8;i<12;i++) pos_2.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_2.shape[1][i] = 0x0000;
	
	/*oxoo
		oxoo
		oxxo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[0][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_3.shape[0][i]   = 0x0f00;
	for(i=8;i<12;i++) pos_3.shape[0][i]  = 0x0ff0;
	for(i=12;i<16;i++) pos_3.shape[0][i] = 0x0000;
	
	/*ooxo
		xxxo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[1][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_3.shape[1][i]   = 0xfff0;
	for(i=8;i<12;i++) pos_3.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_3.shape[1][i] = 0x0000;

	/*xxoo
		oxoo
		oxoo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[2][i]   = 0xff00;
	for(i=4;i<8;i++) pos_3.shape[2][i]   = 0x0f00;
	for(i=8;i<12;i++) pos_3.shape[2][i]  = 0x0f00;
	for(i=12;i<16;i++) pos_3.shape[2][i] = 0x0000;	

	/*oooo
		xxxo
		xooo
		oooo*/
	for(i=0;i<4;i++) pos_3.shape[3][i] =   0x0000;
	for(i=4;i<8;i++) pos_3.shape[3][i] =   0xfff0;
	for(i=8;i<12;i++) pos_3.shape[3][i] =  0xf000;
	for(i=12;i<16;i++) pos_3.shape[3][i] = 0x0000;	

	/*ooxo
		ooxo
		oxxo
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[0][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_4.shape[0][i]   = 0x00f0;
	for(i=8;i<12;i++) pos_4.shape[0][i]  = 0x0ff0;
	for(i=12;i<16;i++) pos_4.shape[0][i] = 0x0000;
	
	
	/*oooo
		oxxx
		ooox
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[1][i]   = 0x0000;
	for(i=4;i<8;i++) pos_4.shape[1][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_4.shape[1][i]  = 0x000f;
	for(i=12;i<16;i++) pos_4.shape[1][i] = 0x0000;	
	
	/*ooxx
		ooxo
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[2][i]   = 0x00ff;
	for(i=4;i<8;i++) pos_4.shape[2][i]   = 0x00f0;
	for(i=8;i<12;i++) pos_4.shape[2][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_4.shape[2][i] = 0x0000;	

	
	/*oxoo
		oxxx
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_4.shape[3][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_4.shape[3][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_4.shape[3][i]  = 0x0000;
	for(i=12;i<16;i++) pos_4.shape[3][i] = 0x0000;	
	
	/*ooxo
		oxxx
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[0][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_5.shape[0][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_5.shape[0][i]  = 0x0000;
	for(i=12;i<16;i++) pos_5.shape[0][i] = 0x0000;	

	/*ooxo
		oxxo
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[1][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_5.shape[1][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_5.shape[1][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_5.shape[1][i] = 0x0000;		
	
	/*oooo
		oxxx
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[2][i]   = 0x0000;
	for(i=4;i<8;i++) pos_5.shape[2][i]   = 0x0fff;
	for(i=8;i<12;i++) pos_5.shape[2][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_5.shape[2][i] = 0x0000;
	
	/*ooxo
		ooxx
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_5.shape[3][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_5.shape[3][i]   = 0x00ff;
	for(i=8;i<12;i++) pos_5.shape[3][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_5.shape[3][i] = 0x0000;
	
	/*oxoo
		oxxo
		ooxo
		oooo*/
	for(i=0;i<4;i++) pos_6.shape[0][i]   = 0x0f00;
	for(i=4;i<8;i++) pos_6.shape[0][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_6.shape[0][i]  = 0x00f0;
	for(i=12;i<16;i++) pos_6.shape[0][i] = 0x0000;
	
	/*oxxo
		xxoo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_6.shape[1][i]   = 0x0ff0;
	for(i=4;i<8;i++) pos_6.shape[1][i]   = 0xff00;
	for(i=8;i<12;i++) pos_6.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_6.shape[1][i] = 0x0000;
	
	/*ooxo
		oxxo
		oxoo
		oooo*/
	for(i=0;i<4;i++) pos_7.shape[0][i]   = 0x00f0;
	for(i=4;i<8;i++) pos_7.shape[0][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_7.shape[0][i]  = 0x0f00;
	for(i=12;i<16;i++) pos_7.shape[0][i] = 0x0000;

	
	/*xxoo
		oxxo
		oooo
		oooo*/
	for(i=0;i<4;i++) pos_7.shape[1][i]   = 0xff00;
	for(i=4;i<8;i++) pos_7.shape[1][i]   = 0x0ff0;
	for(i=8;i<12;i++) pos_7.shape[1][i]  = 0x0000;
	for(i=12;i<16;i++) pos_7.shape[1][i] = 0x0000;
}


//mode: 0 清除 1 显示
//place: 0 显示在游戏界面 1 显示在信息界面
void Draw_Diamond(Condition con, char mode, char place)
{
	uint8_t i, j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if(con.pos[i] & 0x8000)
			{
				if(place) 
				{
					switch(con.num)
					{
//						case 1:	 OLED_DrawPoint(102+j,18+i,mode); break;					
//						case 2:  OLED_DrawPoint(102+j,14+i,mode); break;
//						case 3:  OLED_DrawPoint(104+j,16+i,mode); break;
//						case 4:  OLED_DrawPoint(100+j,18+i,mode); break;
//						case 5:  OLED_DrawPoint(100+j,18+i,mode); break;
//						case 6:  OLED_DrawPoint(104+j,18+i,mode); break;
//						case 7:  OLED_DrawPoint(104+j,18+i,mode); break;
					}	
				}
				else 
				{
//					if(con.y+i >= 0) OLED_DrawPoint(con.x+j,con.y+i,mode);
				}
			}
			con.pos[i] <<=1;
		}
	}
}

