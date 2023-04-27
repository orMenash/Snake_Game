#include "grow_snake_tests.h"

int grow_snake__When_UP() {
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = get_example_snake_with_2_links(10, 9);

	//Act
	uctual = create_snake(10, 10);

	grow_snake(&uctual, 1, UP);

	//Assert
	int result = are_same_snake(uctual, expected, 2);
	
	free_snake(expected, 2);
	free_snake(uctual, 2);

	return result;
}

int grow_snake__When_DOWN() {
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = get_example_snake_with_2_links(10, 11);

	//Act
	uctual = create_snake(10, 10);
	grow_snake(&uctual, 1, DOWN);

	//Assert
	int result = are_same_snake(uctual, expected, 2);

	free_snake(expected, 2);
	free_snake(uctual, 2);

	return result;
}

int grow_snake__When_RIGHT() {
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = get_example_snake_with_2_links(11, 10);

	//Act
	uctual = create_snake(10, 10);
	grow_snake(&uctual, 1, RIGHT);

	//Assert
	int result = are_same_snake(uctual, expected, 2);

	free_snake(expected, 2);
	free_snake(uctual, 2);

	return result;
}

int grow_snake__When_LEFT() {
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = get_example_snake_with_2_links(9, 10);

	//Act
	uctual = create_snake(10, 10);
	grow_snake(&uctual, 1, LEFT);

	//Assert
	int result = are_same_snake(uctual, expected, 2);

	free_snake(expected, 2);
	free_snake(uctual, 2);

	return result;
}

int grow_snake__When_MultipleCalls() {
	int i;
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = (snake_t)malloc(5 * sizeof(uint8_t*));
	if (expected == NULL) return 1;

	for (i = 0; i < 5; i++) {
		expected[i] = (uint8_t*)malloc(2 * sizeof(uint8_t));
		if (expected[i] == NULL) return 1;
	}

	for (i = 0; i < 5; i++) {
		expected[i][0] = 10;
		expected[i][1] = 10 - i;
	}

	//Act
	uctual = create_snake(10, 10);
	for (i = 0; i < 4; i++) {
		grow_snake(&uctual, 1 + i, UP);
	}

	//Assert
	int result = are_same_snake(uctual, expected, 2);

	free_snake(expected, 2);
	free_snake(uctual, 2);

	return result;
}


int are_same_snake(snake_t a, snake_t b, size_t size_snake) {
	int i, j;
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