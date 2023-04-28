#include "move_snake_tests.h"

int move_snake__When_UP() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t anake_b;
	anake_b = create_snake(10, 9);
	if (anake_b == NULL) return 1;
	expected = 0;
	//Act
	snake_a = create_snake(10, 10);
	move_snake(snake_a, 1, UP);
	uctual = are_same_snake(snake_a, anake_b, 1);

	free_snake(anake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int move_snake__When_DOWN() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t anake_b;
	anake_b = create_snake(10, 11);
	if (anake_b == NULL) return 1;
	expected = 0;

	//Act
	snake_a = create_snake(10, 10);
	move_snake(snake_a, 1, DOWN);
	uctual = are_same_snake(snake_a, anake_b, 1);

	free_snake(anake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int move_snake__When_RIGHT() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t anake_b;
	anake_b = create_snake(11, 10);
	if (anake_b == NULL) return 1;
	expected = 0;

	//Act
	snake_a = create_snake(10, 10);
	move_snake(snake_a, 1, RIGHT);
	uctual = are_same_snake(snake_a, anake_b, 1);

	free_snake(anake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int move_snake__When_LEFT() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t anake_b;
	anake_b = create_snake(9, 10);
	if (anake_b == NULL) return 1;
	expected = 0;

	//Act
	snake_a = create_snake(10, 10);
	move_snake(snake_a, 1, LEFT);
	uctual = are_same_snake(snake_a, anake_b, 1);

	free_snake(anake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}