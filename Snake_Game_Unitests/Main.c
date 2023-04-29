// A test function should:
// 1. return 0 on success or 1 9on failure.
// 2. test only once scenario/
// 3. be names after the scenario it checks in the following manner:
//   <Function>_When<Scenario>_Then<Result>
// 4. be built from three "steps": Arrange, Act, Assert.

#include "Header.h"
#include "create_snake_tests.h"
#include "free_snake_tests.h"
#include "grow_snake_tests.h"
#include "move_snake_tests.h"
#include "will_snake_reach_food_on_next_move_test.h"
#include "is_food_on_snake_test.h"
#include "collision_with_itself_test.h"
#include "collide_border_test.h"
#include "move_in_direction.h"

// ----- git ----
// 1. added functionality of <name_function> and several unit tests,   //start function.
//		intermediate commit - not yet finished.
// 2. Improved the test, and now it's failing.						 //improve test
// 3. fixed the bug - test passes.									 // fix bug
// 4. test - now it failse again on a <place>.						//impreve test
// 5. bugfix - fixed funciton - test pass.							// fix bug
// 6. Refactored the code.											//refactor

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //tofix in linux need to remove.

	printf("tests are starting\n\n");
	//---- creat_snake tests ----------------
	bool isOk = 1;

	isOk &= (0 == what_return_when_get_good_numbers());

	//-----free_snake tests -----------------
	isOk &= (0 == get_null_snake());

	//----- auxiliary functions are_same_snake tests ---------------
	isOk &= (0 == are_not_same_snake_test()); 
	isOk &= (0 == are_same_snake_test());
	isOk &= (0 == one_snake_is_null());

	//----- grow_snake tests ----------------
	isOk &= (0 == grow_snake__When_UP());
	isOk &= (0 == grow_snake__When_DOWN());
	isOk &= (0 == grow_snake__When_RIGHT());
	isOk &= (0 == grow_snake__When_LEFT());
	isOk &= (0 == grow_snake__When_MultipleCalls());

	//-----move_snake tests ---------------
	isOk &= (0 == move_snake__When_UP());
	isOk &= (0 == move_snake__When_DOWN());
	isOk &= (0 == move_snake__When_RIGHT());
	isOk &= (0 == move_snake__When_LEFT());

	//----- auxiliary functions creat_long_snake tests ---------------
	isOk &= (0 == create_c_shape_test());


	//----- auxiliary functions will_snake_reach_food_on_next_move tests ---------------
	isOk &= (0 == food_in_left_and_snake_take_right_test());
	isOk &= (0 == food_in_left_and_snake_take_up_test());
	isOk &= (0 == food_in_left_and_snake_take_down_test());
	isOk &= (0 == food_in_left_and_snake_take_left_test());

	//---- is_food_on_snake tests-------------------
	isOk &= (0 == food_on_snake());
	isOk &= (0 == food_not_on_snake());

	//---- collision_with_itself tests-------------------
	isOk &= (0 == snake_collision_with_itself());
	isOk &= (0 == snake_not_collision_with_itself());



	//----- collide_border tests ---------------
	isOk &= (0 == the_snake_not_collide_border_test());
	isOk &= (0 == the_snake_collide_left_border_test());
	isOk &= (0 == the_snake_collide_up_border_test());
	isOk &= (0 == the_snake_collide_down_border_test());
	isOk &= (0 == the_snake_collide_right_border_test());

	//-----move_direction tests ---------------
	isOk &= (0 == up_to_right());
	isOk &= (0 == right_to_left());
	isOk &= (0 == left_to_right());
	isOk &= (0 == down_to_up());
	isOk &= (0 == up_to_down());

	printf("%d\n\n", isOk);

	return 0;
}



