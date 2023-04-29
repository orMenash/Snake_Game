#include "collision_with_itself_test.h"

int snake_collision_with_itself() {
	bool expected, uctual;
	//Arrang
	direction_t directions[] = { RIGHT, UP ,UP, RIGHT, DOWN};
	snake_t snake = create_long_snake(10, 10, directions, 5);
	expected = true;

	//Act
	uctual = will_snake_collide_with_itself_on_next_move(snake, 6, LEFT);
	free_snake(snake, 6);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int snake_not_collision_with_itself() {
	bool expected, uctual;
	//Arrang
	direction_t directions[] = { RIGHT, UP ,UP, RIGHT, DOWN };
	snake_t snake = create_long_snake(10, 10, directions, 5);
	expected = false;

	//Act
	uctual = will_snake_collide_with_itself_on_next_move(snake, 6, DOWN);
	free_snake(snake, 6);

	//Assert
	return (expected == uctual) ? 0 : 1;
}