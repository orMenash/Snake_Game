#include "is_food_on_snake_test.h"

int food_on_snake() {
	bool expected, uctual;
	//Arrang
	uint8_t food[2] = { 11, 10 };
	direction_t directions[] = {RIGHT, UP};
	snake_t snake = create_long_snake(10, 10, directions, 2);
	expected = true;

	//Act
	uctual = is_food_on_snake(snake, 3, food);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int food_not_on_snake() {
	bool expected, uctual;
	//Arrang
	uint8_t food[2] = { 10, 11 };
	direction_t directions[] = { RIGHT, UP };
	snake_t snake = create_long_snake(10, 10, directions, 2);
	expected = false;

	//Act
	uctual = is_food_on_snake(snake, 3, food);

	//Assert
	return (expected == uctual) ? 0 : 1;
}