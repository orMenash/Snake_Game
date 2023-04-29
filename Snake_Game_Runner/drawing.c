#include "drawing.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(consoleHandle, coord);
}

void draw_snake(snake_t snake, size_t snake_size) {
	int i;
	if (snake == NULL)return;
	for (i = 0; i < snake_size; i++) {
		gotoxy(snake[i][0], snake[i][1]);
		printf("%c", SNAKE_COLOR);
	}
}

void clear_snake(snake_t snake, size_t snake_size) {
	int i;
	if (snake == NULL)return;
	for (i = 0; i < snake_size; i++) {
		gotoxy(snake[i][0], snake[i][1]);
		printf("%c", 176);
	}
}

void draw_food(uint8_t* food) {
	gotoxy(food[0], food[1]);
	printf("%c", FOOD_COLOR);
}

void draw_borders() {
	int i;
	for (i = 0; i < GAME_WIDTH; i++) {
		printf("%c", WALL_COLOR);
	}

	for (i = 1; i < GAME_HEIGHT; i++) {
		gotoxy(0, i);
		printf("%c", WALL_COLOR);
		gotoxy(GAME_WIDTH - 1, i);
		printf("%c", WALL_COLOR);
	}

	gotoxy(0, GAME_HEIGHT);

	for (i = 0; i < GAME_WIDTH; i++) {
		printf("%c", WALL_COLOR);
	}

	gotoxy(0, GAME_HEIGHT + 5);
	printf("\n");
}