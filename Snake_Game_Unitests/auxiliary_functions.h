#pragma once
#ifndef AUXILIARY_FUNCTIONS
#define AUXILIARY_FUNCTIONS
#include "Header.h"

#define BASIC_X 10
#define BASIC_Y 10

int are_same_snake(snake_t a, snake_t b, size_t size_snake);
snake_t get_example_snake_with_2_links(uint8_t x, uint8_t);
snake_t create_long_snake(uint8_t x, uint8_t y, direction_t* growth_directions, size_t num_growth_directions);


//---------------testing auxiliary functions--------------------
// 
// ----------- create_long_snake tests----------------
int are_not_same_snake_test();
int one_snake_is_null();
int are_same_snake_test();

// ----------- create_long_snake tests---------------
int create_c_shape_test();



#endif // !AUXILIARY_FUNCTIONS

