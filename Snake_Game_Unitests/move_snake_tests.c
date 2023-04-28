#include "move_snake_tests.h"

int move_snake__When_UP() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;

	direction_t growth_directions_b[] = { LEFT, UP, UP, RIGHT, UP };
	snake_b = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 5);
	if (snake_b == NULL) return 1;
	
	direction_t growth_directions_a[] = { LEFT, LEFT, UP, UP, RIGHT };
	snake_a = create_long_snake((BASIC_X + 1), BASIC_Y, growth_directions_a, 5);
	if (snake_a == NULL) return 1;
	expected = 0;
	
	//Act
	move_snake(snake_a, 6, UP);
	uctual = are_same_snake(snake_a, snake_b, 6);

	free_snake(snake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int move_snake__When_DOWN() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;

	direction_t growth_directions_b[] = { LEFT, UP, UP, RIGHT, DOWN };
	snake_b = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 5);
	if (snake_b == NULL) return 1;

	direction_t growth_directions_a[] = { LEFT, LEFT, UP, UP, RIGHT };
	snake_a = create_long_snake((BASIC_X + 1), BASIC_Y, growth_directions_a, 5);
	if (snake_a == NULL) return 1;

	expected = 0;

	//Act
	move_snake(snake_a, 6, DOWN);
	uctual = are_same_snake(snake_a, snake_b, 6);

	free_snake(snake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int move_snake__When_RIGHT() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;

	direction_t growth_directions_b[] = { LEFT, UP, RIGHT, UP, RIGHT };
	snake_b = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 5);
	if (snake_b == NULL) return 1;

	direction_t growth_directions_a[] = { LEFT, LEFT, UP, RIGHT, UP};
	snake_a = create_long_snake((BASIC_X + 1), BASIC_Y, growth_directions_a, 5);
	if (snake_a == NULL) return 1;

	expected = 0;

	//Act
	move_snake(snake_a, 6, RIGHT);
	uctual = are_same_snake(snake_a, snake_b, 6);

	free_snake(snake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int move_snake__When_LEFT() {
	int uctual, expected;

	//Arrang
	snake_t snake_a;
	snake_t snake_b;
	
	direction_t growth_directions_b[] = { LEFT, UP, RIGHT, UP, LEFT };
	snake_b = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 5);
	if (snake_b == NULL) return 1;

	direction_t growth_directions_a[] = { LEFT, LEFT, UP, RIGHT, UP };
	snake_a = create_long_snake((BASIC_X + 1), BASIC_Y, growth_directions_a, 5);
	if (snake_a == NULL) return 1;

	expected = 0;

	//Act
	move_snake(snake_a, 6, LEFT);
	uctual = are_same_snake(snake_a, snake_b, 6);

	free_snake(snake_b, 1);
	free_snake(snake_a, 1);

	//Assert
	return (uctual == expected) ? 0 : 1;
}