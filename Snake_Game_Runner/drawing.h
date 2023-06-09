#pragma once
#ifndef DRAWING_SNAKE
#define DRAWING_SNAKE
#include <windows.h> 
#include "../Snake_Game/snake.h"

#define SNAKE_COLOR 254
#define FOOD_COLOR 240
#define WALL_COLOR 219
//#define GAME_WIDTH (30)
//#define GAME_HEIGHT (30)


void gotoxy(int x, int y);
void draw_snake(snake_t snake, size_t snake_size);
void clear_snake(snake_t snake, size_t snake_size);
void draw_food(uint8_t* food);
void draw_borders();


#endif // !DRAWING_SNAKE

