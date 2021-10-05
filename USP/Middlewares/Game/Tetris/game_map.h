#ifndef __GAME_MAP_H_
#define __GAME_MAP_H_
#include "stm32f4xx_hal.h"

#define MAP_RIGHT 92
#define MAP_BOTTOM 64

extern char Map[MAP_RIGHT][MAP_BOTTOM];

void Draw_Inf(void);
void Draw_Map(void);
void Map_Init(void);
uint8_t Game_Interface_Show(void);
uint8_t Game_Show(uint8_t mode);
#endif
