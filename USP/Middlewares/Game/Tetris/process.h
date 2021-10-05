#ifndef __PROCESS_H_
#define __PROCESS_H_
#include "stm32f4xx_hal.h"

#define LEFT  0
#define RIGHT 1

//���淽���״̬
typedef struct 
{
	uint8_t num; 			 //��ǰ�����˶��ķ���
	uint8_t pos_choice; //����̬��Ӧ�ı��
	uint16_t pos[16]; 		 //�˶������Ӧ����̬
	int x;				 //����ĺ�����
	int y;				 //�����������
	uint8_t alive;			 //0:ʧ�� 1:���
} Condition;

extern Condition con_next;

void Game_Init(void);
void Game_Processing(void);
void Reset_Diamond(void);
void Update_Map(Condition con);
void Clear_Map(int p[]);
void Check_Map(void);
uint8_t Go_Down(void);
void Go_R_L(char mode);
void Pos_Turn(void);
uint8_t Judge_Side(Condition con);
uint8_t Judge_Bottom(Condition con);
void Game_Over(void);
uint8_t Game_Score(int p[]);
void Show_Game(void);
//��������
int Random(int a, int b);
#endif
