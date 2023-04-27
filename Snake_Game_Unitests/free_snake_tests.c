#include "free_snake_tests.h"

int get_null_snake() {
	//Arrange
	snake_t expected = NULL;
	size_t snake_size = 6;
	
	//Act
	snake_t uctual = NULL;
	free_snake(uctual, snake_size);

	//Assert
	return (expected == uctual) ? 0 : 1;
}