#include "help_functions.h"

int are_same_snake(snake_t a, snake_t b, size_t size_snake) {
	int i, j;
	for (i = 0; i < size_snake; i++) {
		for (j = 0; j < 2; j++) {
			if (a[i][j] != b[i][j]) return 1;
		}
	}
	return 0;
}

snake_t get_example_snake_with_2_links(uint8_t x, uint8_t y) {
	snake_t example;
	example = (snake_t)malloc(2 * sizeof(uint8_t*));
	if (example == NULL) return NULL;

	example[0] = (uint8_t*)malloc(2 * sizeof(uint8_t));
	example[1] = (uint8_t*)malloc(2 * sizeof(uint8_t));

	if ((example[0] == NULL) || (example[1] == NULL)) return NULL;

	example[0][0] = BASIC_X;
	example[0][1] = BASIC_Y;

	example[1][0] = x;
	example[1][1] = y;
	return example;
}