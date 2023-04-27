#include "create_snake_tests.h"


int what_return_when_get_good_numbers() {
	//Arrange
	int x = 2;
	int y = 4;
	snake_t expected = (snake_t)malloc(sizeof(uint8_t*));
	if (expected == NULL) return 1;
	*expected = (uint8_t*)malloc(2 * sizeof(uint8_t));
	if (*expected == NULL) return 1;
	(*expected)[0] = x;
	(*expected)[1] = y;

	//Act
	snake_t uctual = create_snake(x, y);

	//Assert
	return ( (  (*expected)[0] == (*uctual)[0] ) && ( (*expected)[1] == (*uctual)[1] ) ) ? 0 : 1;
}