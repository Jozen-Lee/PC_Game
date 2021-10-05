#ifndef __OBJECT_H_
#define __OBJECT_H_
#include "stm32f4xx_hal.h"
#include "process.h"
struct POS_1
{
	uint16_t shape[1][16];
} ;

struct POS_2
{
	uint16_t shape[2][16];
};

struct POS_3
{
	uint16_t shape[4][16];
};

struct POS_4
{
	uint16_t shape[4][16];
};

struct POS_5
{
	uint16_t shape[4][16];	
};

struct POS_6
{
	uint16_t shape[2][16];
};

struct POS_7
{
	uint16_t shape[2][16];	
};

extern struct POS_1 pos_1;
extern struct POS_2 pos_2;
extern struct POS_3 pos_3;
extern struct POS_4 pos_4;
extern struct POS_5 pos_5;
extern struct POS_6 pos_6;
extern struct POS_7 pos_7;

void Object_Init(void);
void Draw_Diamond(Condition con, char mode, char place);
#endif
