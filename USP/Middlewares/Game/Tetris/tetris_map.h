#ifndef __TETRIS__MAP_H_
#define __TETRIS__MAP_H_
#include "stm32f4xx_hal.h"

#define MAP_WIDTH 180
#define MAP_HEIGTH 200

extern char Map[MAP_WIDTH][MAP_HEIGTH];

void Draw_Inf(void);
void Draw_Map(void);
void Map_Init(void);
uint8_t Game_Interface_Show(void);
uint8_t Game_Show(uint8_t mode);
#endif
