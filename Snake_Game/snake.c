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

	get_head_after_next_move(new_snake_ptr[snake_size], direction);

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

	get_head_after_next_move(snake[snake_size - 1], to_where);
}

// Returns true if snakes will reach food after a single move in the // given direction.
bool will_snake_reach_food_on_next_move(snake_t snake, size_t snake_size, uint8_t* food, direction_t direction) {
	uint8_t head[2];
	head[0] = snake[snake_size - 1][0];
	head[1] = snake[snake_size - 1][1];
	get_head_after_next_move(head, direction);
	return ( (head[0]  == food[0]) && (head[1] == food[1]));
}

// Changing place head to next move.
void get_head_after_next_move(uint8_t* head, direction_t direction) {
	switch (direction)
	{
	case UP:
		head[1]--;
		break;
	case DOWN:
		head[1]++;
		break;
	case LEFT:
		head[0]--;
		break;
	case RIGHT:
		head[0]++;
		break;
	}
}

// Creating random number between minimum to maximum number.
uint8_t random_number_btween_min_to_max(int min, int max) {
	return (uint8_t)(rand() % (max - min)) + min;
}

// Setting a new food loction.
void set_new_food_location(snake_t snake, size_t snake_size, uint8_t food[]) {
	do {
		food[0] = random_number_btween_min_to_max(0, GAME_WIDTH) + BOARD_WIDTH_SPACE;
		food[1] = random_number_btween_min_to_max(0, GAME_HEIGHT) + BOARD_HEIGHT_SPACE;
	} while (true == is_food_on_snake(snake, snake_size, food));
}

// Makes sure the new food doesn't "land on the snake".
bool is_food_on_snake(snake_t snake, size_t snake_size, uint8_t* food) {
	int i;
	for (i = 0; i < snake_size; i++) {
		if (snake[i][0] == food[0] && snake[i][1] == food[1]) return true;
	}
	return false;
}

// Returns true if snakes will bump into itself after a single move in // the given direction.
bool will_snake_collide_with_itself_on_next_move(snake_t snake, size_t snake_size, direction_t direction) {
	uint8_t head[2];
	head[0] = snake[snake_size - 1][0];
	head[1] = snake[snake_size - 1][1];
	get_head_after_next_move(head, direction);


	return is_food_on_snake(snake, snake_size - 1, head);

}

bool will_snake_collide_border_on_next_move(snake_t snake, size_t snake_size, direction_t direction) {
	return true;
}
