#pragma once
#ifndef SNAKE
#define SNAKE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define snake_t uint8_t**

// Creates a snake in coordinate (x,y):
snake_t create_snake(uint8_t x, uint8_t y);
// Free snake’s memory (remember: it’s a double pointer array!)
void free_snake(snake_t snake, size_t snake_size);


#endif // !SNAKE
