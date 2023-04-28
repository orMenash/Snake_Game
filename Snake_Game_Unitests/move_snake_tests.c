#include "move_snake_tests.h"

int move_snake__When_UP() {
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = create_snake(10, 9);
	if (expected == NULL) return 1;

	//Act
	uctual = create_snake(10, 10);
	move_snake(uctual, 1, UP);

	//Assert
	int result = are_same_snake(uctual, expected, 1);

	free_snake(expected, 1);
	free_snake(uctual, 1);

	return result;
}

int move_snake__When_DOWN() {
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = create_snake(10, 11);
	if (expected == NULL) return 1;

	//Act
	uctual = create_snake(10, 10);
	move_snake(uctual, 1, DOWN);

	//Assert
	int result = are_same_snake(uctual, expected, 1);

	free_snake(expected, 1);
	free_snake(uctual, 1);

	return result;
}

int move_snake__When_RIGHT() {
	snake_t uctual;
	snake_t expected;
	//Arrang
	expected = create_snake(11, 10);
	if (expected == NULL) return 1;

	//Act
	uctual = create_snake(10, 10);
	move_snake(uctual, 1, RIGHT);

	//Assert
	int result = are_same_snake(uctual, expected, 1);

	free_snake(expected, 1);
	free_snake(uctual, 1);

	return result;
}

int move_snake__When_LEFT() {
	//Arrang
	snake_t uctual;
	snake_t expected;
	expected = create_snake(9, 10);
	if (expected == NULL) return 1;

	//Act
	uctual = create_snake(10, 10);
	move_snake(uctual, 1, LEFT);

	//Assert
	int result = are_same_snake(uctual, expected, 1);

	free_snake(expected, 1);
	free_snake(uctual, 1);

	return result;
}