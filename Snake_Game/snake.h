#pragma once
#ifndef SNAKE
#define SNAKE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define snake_t uint8_t**
#define direction_t enum directions_enum

enum directions_enum { UP, DOWN, LEFT, RIGHT };


// Creates a snake in coordinate (x,y).
snake_t create_snake(uint8_t x, uint8_t y);

// Free snake’s memory.
void free_snake(snake_t snake, size_t snake_size);

// Grows the snake.
size_t grow_snake(uint8_t*** snake_ptr, size_t snake_size, direction_t direction);

// Move the snake
void move_snake(snake_t snake, size_t snake_size, direction_t to_where);

#endif // !SNAKE
