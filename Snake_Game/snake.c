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

bool will_snake_reach_food_on_next_move(snake_t snake, size_t snake_size, uint8_t* food, direction_t direction) {
	uint8_t* head = snake[snake_size - 1];
	switch (direction)
	{
	case UP:
		return ( (head[0] == food[0]) && ( (head[1] - 1) == food[1]) );
		break;
	case DOWN:
		return ( (head[0] == food[0]) && ( (head[1] + 1) == food[1]) );
		break;
	case LEFT:
		return ( ( (head[0] - 1) == food[0]) && (head[1] == food[1]) );
		break;
	case RIGHT:
		return ( ( (head[0] + 1) == food[0]) && (head[1] == food[1]) );
		break;
	default:
		return false;
		break;
	}
}

// Creating random number between minimum to maximum number.
uint8_t random_number_btween_min_to_max(int min, int max) {
	return (uint8_t)(rand() % (max - min)) + min;
}

// Setting a new food loction.
void set_new_food_location(snake_t snake, uint8_t snake_size, uint8_t food[]) {
	do {
		food[0] = random_number_btween_min_to_max(0, BOARD_WIDTH) + BOARD_WIDTH_SPACE;
		food[1] = random_number_btween_min_to_max(0, BOARD_HEIGHT) + BOARD_HEIGHT_SPACE;
	} while (true == is_food_on_snake(snake, snake_size, food));
}

// Makes sure the new food doesn't "land on the snake".
bool is_food_on_snake(snake_t snake, uint8_t size_snake, uint8_t food[]) {
	int i;
	for (i = 0; i < size_snake; i++) {
		if (snake[i][0] == food[0] && snake[i][1] == food[1]) return true;
	}
	return false;
}