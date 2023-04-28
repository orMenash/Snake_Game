#include "will_snake_reach_food_on_next_move_test.h"

int food_in_left_and_snake_take_right_test() {
	bool uctual, expected;
	//Arrang
	uint8_t food[2] = { 9, 8 };

	direction_t growth_directions_b[] = { UP, UP };
	snake_t snake = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 2);	

	expected = false;

	//Act
	uctual = will_snake_reach_food_on_next_move(snake, 3, food, RIGHT);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int food_in_left_and_snake_take_up_test() {
	bool uctual, expected;
	//Arrang
	uint8_t food[2] = { 9, 8 };

	direction_t growth_directions_b[] = { UP, UP };
	snake_t snake = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 2);

	expected = false;

	//Act
	uctual = will_snake_reach_food_on_next_move(snake, 3, food, UP);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int food_in_left_and_snake_take_down_test() {
	bool uctual, expected;
	//Arrang
	uint8_t food[2] = { 9, 8 };

	direction_t growth_directions_b[] = { UP, UP };
	snake_t snake = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 2);

	expected = false;

	//Act
	uctual = will_snake_reach_food_on_next_move(snake, 3, food, DOWN);

	//Assert
	return (uctual == expected) ? 0 : 1;
}

int food_in_left_and_snake_take_left_test() {
	bool uctual, expected;
	//Arrang
	uint8_t food[2] = { 9, 8 };

	direction_t growth_directions_b[] = { UP, UP };
	snake_t snake = create_long_snake(BASIC_X, BASIC_Y, growth_directions_b, 2);

	expected = true;

	//Act
	uctual = will_snake_reach_food_on_next_move(snake, 3, food, LEFT);

	//Assert
	return (uctual == expected) ? 0 : 1;
}