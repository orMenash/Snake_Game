#pragma once
#ifndef DRAWING_SNAKE
#define DRAWING_SNAKE
#include <windows.h> 
#include "../Snake_Game/snake.h"

#define SNAKE_DRAWING 178
#define FOOD_DRAWNING 219

void gotoxy(int x, int y);
void draw_snake(snake_t snake, size_t snake_size);
void clear_snake(snake_t snake, size_t snake_size);
void draw_food(uint8_t* food);


#endif // !DRAWING_SNAKE

