#include <conio.h>
#include "../Snake_Game/snake.h"
#include "drawing.h"






int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //tofix in linux need to remove.
	char key;
	size_t snake_size;
	bool game_time = true;
	direction_t direction = UP;

	//To random number
	srand((unsigned int)time(NULL));   

	//create snake
	snake_t snake = create_snake(10, 10);
	snake_size = 1;

	//create food
	uint8_t food[2];
	set_new_food_location(snake, 1, food);

	//create board
	draw_borders();
	while (game_time) {
		//drawing snake and food
		draw_snake(snake, snake_size);
		draw_food(food);

		// get direction from user or quit.
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case 'w':
				if (can_snake_move_in_direction(direction, UP)) {
					direction = UP;
				}
				break;
			case 's':
				if (can_snake_move_in_direction(direction, DOWN)) {
					direction = DOWN;
				}
				break;
			case 'a':
				if (can_snake_move_in_direction(direction, LEFT)) {
					direction = LEFT;
				}
				break;
			case 'd':
				if (can_snake_move_in_direction(direction, RIGHT)) {
					direction = RIGHT;
				}
				break;
			case '0':
				game_time = false;
				break;
			}
		}

		//checking if false
		if (will_snake_colide(snake, snake_size, direction)) {
			game_time = false;
		}

		Sleep(300);

		//clear old snake
		clear_snake(snake, snake_size);

		// check if should grow: ///
		if (will_snake_reach_food_on_next_move(snake ,snake_size, food, direction)) {
			snake_size = grow_snake(&snake, snake_size, direction);
			set_new_food_location(snake, snake_size, food);
			MessageBeep(MB_OK);
		}
		else {
			move_snake(snake, snake_size, direction);
		}
	}

	//free memory of snake
	free_snake(snake, snake_size);


	gotoxy((int)GAME_HEIGHT / 2 + 10, (int)(GAME_HEIGHT / 2));
	printf("!GAME OVER!");

	gotoxy(0, GAME_HEIGHT + 5);
	return 0;
}