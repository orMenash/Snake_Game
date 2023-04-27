#pragma once
#ifndef GROW_SNAKE_TEST
#define GROW_SNAKE_TEST
#include "Header.h"

//----help functions--------------
#define BASIC_X 10
#define BASIC_Y 10
int are_same_snake(snake_t a, snake_t b, size_t size_snake);
snake_t get_example_snake_with_2_links(uint8_t x, uint8_t);


// --------------test functions--------------
int grow_snake__When_UP();
int grow_snake__When_DOWN();
int grow_snake__When_RIGHT();
int grow_snake__When_LEFT();
int grow_snake__When_MultipleCalls(); // call grow_snake five times in various directions!


#endif // !GROW_SNAKE_TEST

