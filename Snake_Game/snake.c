#include "snake.h"


// Creates a snake in coordinate (x,y):
snake_t create_snake(uint8_t x, uint8_t y) {
	if (x < 0 || y < 0) return NULL; // If get minus numbers.

	snake_t snake = (snake_t)malloc(sizeof(uint8_t*));
	if (snake == NULL) return NULL; //If snaek allocat failed.

	*snake = (uint8_t*)malloc(2 * sizeof(uint8_t));
	if (*snake == NULL) return NULL;//If *snake allocat failed.

	
	(*snake)[0] = x;
	(*snake)[1] = y;

	return snake;
}
// Free snake’s memory (remember: it’s a double pointer array!)
void free_snake(snake_t snake, size_t snake_size) {

}