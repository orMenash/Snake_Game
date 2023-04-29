#include "collide_border_test.h"

int  the_snake_collide_border_on_next_move_test(snake_t snake, size_t snake_size, direction_t direction) {
	bool expected, uctual;
	//Arrang

	snake_t snake = create_snake(1,1);
	expected = true;

	//Act
	uctual = will_snake_collide_border_on_next_move(snake, 3, LEFT);

	//Assert
	return (expected == uctual) ? 0 : 1;
}