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
	int i;
	if (snake == NULL) return;
	for (i = 0; i < snake_size; i++) {
		free(*(snake + i));
	}
	free(snake);
}

// Grows the snake.
size_t grow_snake(snake_t* snake_ptr, size_t snake_size, direction_t direction) {

	snake_t new_snake_ptr = NULL;
	if (snake_ptr == NULL) return 1;

	new_snake_ptr = (snake_t)realloc(*snake_ptr, (snake_size + 1) * sizeof(uint8_t*) );
	if (new_snake_ptr == NULL) return 1; // If allocet fialed.
	
	new_snake_ptr[snake_size] = (uint8_t*)malloc(2 * sizeof(uint8_t) );
	if (new_snake_ptr[snake_size] == NULL) return 1; // If allocet fialed.

	// Update the new element based on the direction.

	new_snake_ptr[snake_size][0] = new_snake_ptr[snake_size - 1][0];
	new_snake_ptr[snake_size][1] = new_snake_ptr[snake_size - 1][1];

	switch (direction) {
	case UP:
		new_snake_ptr[snake_size][1]--;
		break;
	case DOWN:
		new_snake_ptr[snake_size][1]++;
		break;
	case LEFT:
		new_snake_ptr[snake_size][0]--;
		break;
	case RIGHT:
		new_snake_ptr[snake_size][0]++;
		break;
	}

	//-----------------------------------------------
	*snake_ptr = new_snake_ptr;

	return 0;
}

// Move the snake
void move_snake(snake_t snake, size_t snake_size, direction_t to_where) {
	int i;

	for (i = 0; i < snake_size - 1; i++) {
		snake[i][0] = snake[i + 1][0];
		snake[i][1] = snake[i + 1][1];
	}

	switch (to_where){
	case UP:
		snake[snake_size - 1][1]--;
		break;
	case DOWN:
		snake[snake_size - 1][1]++;
		break;
	case RIGHT:
		snake[snake_size - 1][0]++;
		break;
	case LEFT:
		snake[snake_size - 1][0]--;
		break;
	default:
		break;
	}

}