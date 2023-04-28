#include "help_functions.h"

// The function return 0 if the snakes are same.
int are_same_snake(snake_t a, snake_t b, size_t size_snake) {//tofix add testings.
	int i, j;

	if (a == NULL && b == NULL) return 0;
	if (a == NULL || b == NULL) return 1;

	for (i = 0; i < size_snake; i++) {
		for (j = 0; j < 2; j++) {
			if (a[i][j] != b[i][j]) return 1;
		}
	}
	return 0;
} 

snake_t get_example_snake_with_2_links(uint8_t x, uint8_t y) {
	snake_t example;
	example = (snake_t)malloc(2 * sizeof(uint8_t*));
	if (example == NULL) return NULL;

	example[0] = (uint8_t*)malloc(2 * sizeof(uint8_t));
	example[1] = (uint8_t*)malloc(2 * sizeof(uint8_t));

	if ((example[0] == NULL) || (example[1] == NULL)) return NULL;

	example[0][0] = BASIC_X;
	example[0][1] = BASIC_Y;

	example[1][0] = x;
	example[1][1] = y;
	return example;
}

snake_t create_long_snake(uint8_t x, uint8_t y, direction_t* growth_directions, size_t num_growth_directions) {
	snake_t long_snake = NULL;
	int i;

	if (growth_directions == NULL && num_growth_directions != 0) {
		return NULL;
	}

	long_snake = create_snake(x, y);

	for (i = 0; i < num_growth_directions; i++) {
		if (1 == grow_snake(&long_snake, i + 1, growth_directions[i])) {
			free_snake(long_snake, i + 1);
			return NULL;
		}
	}

	return long_snake;
}


//---------------testing help funcions--------------------

// ----------- create_long_snake tests---------------
int are_not_same_snake_test() {
	int uctual, expected;
	//Arrang
	snake_t snake_a = create_snake(BASIC_X, BASIC_X) ;
	snake_t snake_b = create_snake(BASIC_X + 1, BASIC_X);
	expected = 1;

	//Act
	uctual = are_same_snake(snake_a, snake_b, 1);
	free_snake(snake_a, 1);
	free_snake(snake_b, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int are_same_snake_test() {
	int uctual, expected;
	//Arrang
	snake_t snake_a = create_snake(BASIC_X, BASIC_X);
	snake_t snake_b = create_snake(BASIC_X, BASIC_X);
	expected = 0;

	//Act
	uctual = are_same_snake(snake_a, snake_b, 1);
	free_snake(snake_a, 1);
	free_snake(snake_b, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int one_snake_is_null() {
	int uctual, expected;
	//Arrang
	snake_t snake_a = create_snake(BASIC_X, BASIC_X);
	snake_t snake_b = NULL;
	expected = 1;

	//Act
	uctual = are_same_snake(snake_a, snake_b, 1);
	free_snake(snake_a, 1);
	free_snake(snake_b, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

// ----------- create_long_snake tests---------------
int create_c_shape_test() {
	int uctual, expected;
	//Arrang
	snake_t snake_a;
	snake_t snake_b;
	direction_t growth_directions[] = { LEFT, UP, UP, RIGHT };
	snake_b = create_snake(10, 10);
	if (snake_b == NULL)return 1;
	
	if (1 == grow_snake(&snake_b, 1, LEFT)) {
		free_snake(snake_b, 1);
		return 1;
	}
	if (1 == grow_snake(&snake_b, 2, UP)) {
		free_snake(snake_b, 1);
		return 1;
	}
	if (1 == grow_snake(&snake_b, 3, UP)) {
		free_snake(snake_b, 1);
		return 1;
	}
	if (1 == grow_snake(&snake_b, 4, RIGHT)) {
		free_snake(snake_b, 1);
		return 1;
	}

	expected = 0;

	//Act
	snake_a = create_long_snake(10, 10, growth_directions, 4);
	
	uctual = are_same_snake(snake_a, snake_b, 1);

	free_snake(snake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}