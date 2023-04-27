#include "snake.h"


// Creates a snake in coordinate (x,y):
uint8_t** create_snake(uint8_t x, uint8_t y);
// Free snake’s memory (remember: it’s a double pointer array!)
void free_snake(uint8_t** snake, size_t snake_size);