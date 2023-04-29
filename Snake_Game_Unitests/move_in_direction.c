#include "move_in_direction.h"


int up_to_down() {
	bool expected, uctual;
	//Arrang
	expected = false;

	//Act
	uctual = can_snake_move_in_direction(UP, DOWN);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int down_to_up() {
	bool expected, uctual;
	//Arrang
	expected = false;

	//Act
	uctual = can_snake_move_in_direction(DOWN, UP);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int left_to_right() {
	bool expected, uctual;
	//Arrang
	expected = false;

	//Act
	uctual = can_snake_move_in_direction(LEFT, RIGHT);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int right_to_left() {
	bool expected, uctual;
	//Arrang
	expected = false;

	//Act
	uctual = can_snake_move_in_direction(RIGHT, LEFT);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int up_to_right() {
	bool expected, uctual;
	//Arrang
	expected = true;

	//Act
	uctual = can_snake_move_in_direction(UP, RIGHT);

	//Assert
	return (expected == uctual) ? 0 : 1;
}