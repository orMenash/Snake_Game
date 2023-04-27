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