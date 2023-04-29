#include "collide_border_test.h"

int  the_snake_collide_left_border_test() {
	bool expected, uctual;
	//Arrang
	snake_t snake = create_snake(1,1);
	expected = true;

	//Act
	uctual = will_snake_collide_border_on_next_move(snake, 1, LEFT);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int  the_snake_collide_up_border_test() {
	bool expected, uctual;
	//Arrang
	snake_t snake = create_snake(1, 1);
	expected = true;

	//Act
	uctual = will_snake_collide_border_on_next_move(snake, 1, UP);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int  the_snake_collide_down_border_test() {
	bool expected, uctual;
	//Arrang
	snake_t snake = create_snake(1, GAME_HEIGHT - 1);
	expected = true;

	//Act
	uctual = will_snake_collide_border_on_next_move(snake, 1, DOWN);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int  the_snake_collide_right_border_test() {
	bool expected, uctual;
	//Arrang
	snake_t snake = create_snake(GAME_WIDTH - 1, 1);
	expected = true;

	//Act
	uctual = will_snake_collide_border_on_next_move(snake, 1, RIGHT);

	//Assert
	return (expected == uctual) ? 0 : 1;
}

int  the_snake_not_collide_border_test() {
	bool expected, uctual;
	//Arrang
	snake_t snake = create_snake(10, 10);
	expected = false;

	//Act
	uctual = will_snake_collide_border_on_next_move(snake, 1, RIGHT);

	//Assert
	return (expected == uctual) ? 0 : 1;
}