#include "grow_snake_tests.h"

int grow_snake__When_UP() {
	int uctual, expected;
	//Arrang
	snake_t snake_a;
	snake_t snake_b;
	snake_b = get_example_snake_with_2_links(10, 9);
	expected = 0;
	//Act
	snake_a = create_snake(10, 10);
	grow_snake(&snake_a, 1, UP);

	uctual = are_same_snake(snake_a, snake_b, 2);

	free_snake(snake_b, 2);
	free_snake(snake_a, 2);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int grow_snake__When_DOWN() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;
	snake_b = get_example_snake_with_2_links(10, 11);
	expected = 0;

	//Act
	snake_a = create_snake(10, 10);
	grow_snake(&snake_a, 1, DOWN);

	uctual = are_same_snake(snake_a, snake_b, 2);

	free_snake(snake_b, 2);
	free_snake(snake_a, 2);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int grow_snake__When_RIGHT() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;
	snake_b = get_example_snake_with_2_links(11, 10);
	expected = 0;

	//Act
	snake_a = create_snake(10, 10);
	grow_snake(&snake_a, 1, RIGHT);
	uctual = are_same_snake(snake_a, snake_b, 2);

	free_snake(snake_b, 2);
	free_snake(snake_a, 2);

	//Assert
	
	return (uctual == expected) ? 0 : 1;
}

int grow_snake__When_LEFT() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;
	snake_b = get_example_snake_with_2_links(9, 10);
	expected = 0;

	//Act
	snake_a = create_snake(10, 10);
	grow_snake(&snake_a, 1, LEFT);
	uctual = are_same_snake(snake_a, snake_b, 2);

	free_snake(snake_b, 2);
	free_snake(snake_a, 2);

	//Assert

	return (uctual == expected) ? 0 : 1;
}

int grow_snake__When_MultipleCalls() {
	int uctual, expected, i;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;
	snake_b = (snake_t)malloc(5 * sizeof(uint8_t*));
	if (snake_b == NULL) return 1;

	for (i = 0; i < 5; i++) {
		snake_b[i] = (uint8_t*)malloc(2 * sizeof(uint8_t));
		if (snake_b[i] == NULL) return 1;
	}

	for (i = 0; i < 5; i++) {
		snake_b[i][0] = 10;
		snake_b[i][1] = 10 - i;
	}
	expected = 0;

	//Act
	snake_a = create_snake(10, 10);
	for (i = 0; i < 4; i++) {
		grow_snake(&snake_a, 1 + i, UP);
	}
	uctual = are_same_snake(snake_a, snake_b, 2);

	free_snake(snake_b, 5);
	free_snake(snake_a, 5);

	//Assert
	return (uctual == expected) ? 0 : 1;
}