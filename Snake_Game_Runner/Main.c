#include "../Snake_Game/snake.h"
#include "drawing.h"

int main() {
	srand((unsigned int)time(NULL));   
	//printf("runner is workring\n\n");

	snake_t snake = create_snake(1, 1);
	snake_t snakea = create_snake(2, 1);
	draw_borders();
	draw_snake(snake, 1);
	draw_food(snakea[0]);

	gotoxy(0, GAME_HEIGHT + 5);
	return 0;
}