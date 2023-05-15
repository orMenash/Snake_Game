#pragma once
#ifndef SNAKE
#define SNAKE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS //tofix in linux need to remove.
#define _CRTDBG_MAP_ALLOC //tofix in linux need to remove.
#include <crtdbg.h> //tofix in linux need to remove.

#define snake_t uint8_t**
#define direction_t enum directions_enum
#define GAME_WIDTH (40)
#define GAME_HEIGHT (20)
#define BOARD_WIDTH_SPACE 0 
#define BOARD_HEIGHT_SPACE 0 

enum directions_enum { UP, DOWN, LEFT, RIGHT };


// Creates a snake in coordinate (x,y).
snake_t create_snake(uint8_t x, uint8_t y);

// Free snake’s memory.
void free_snake(snake_t snake, size_t snake_size);

// Grows the snake.
size_t grow_snake(uint8_t*** snake_ptr, size_t snake_size, direction_t direction);

// Move the snake
void move_snake(snake_t snake, size_t snake_size, direction_t to_where);

// Returns true if snakes will reach food after a single move in the // given direction.
bool will_snake_reach_food_on_next_move(snake_t snake, size_t snake_size, uint8_t* food, direction_t direction);

// Creating random number between minimum to maximum number.
uint8_t random_number_btween_min_to_max();

// Setting a new food loction.
void set_new_food_location(snake_t snake, size_t snake_size, uint8_t food[]);

// Makes sure the new food doesn't "land on the snake".
bool is_food_on_snake(snake_t snake, size_t snake_size, uint8_t food[]);

// Returns true if snakes will bump into itself after a single move in // the given direction.
bool will_snake_collide_with_itself_on_next_move(snake_t snake, size_t snake_size, direction_t direction);

// Changing place head to next move.
void get_head_after_next_move(uint8_t* head, direction_t direction);


bool will_snake_collide_border_on_next_move(snake_t snake, size_t snake_size, direction_t direction);

bool will_snake_colide(snake_t snake, size_t snake_size, direction_t direction);

bool can_snake_move_in_direction(direction_t current_direction, direction_t requested_direction);

#endif // !SNAKE
