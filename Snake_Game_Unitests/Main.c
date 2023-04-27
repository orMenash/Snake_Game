// A test function should:
// 1. return 0 on success or 1 9on failure.
// 2. test only once scenario/
// 3. be names after the scenario it checks in the following manner:
//   <Function>_When<Scenario>_Then<Result>
// 4. be built from three "steps": Arrange, Act, Assert.

#include "Header.h"
#include "create_snake_tests.h"
#include "free_snake_tests.h"

// ----- git ----
// 1. added functionality of <name_function> and several unit tests,   //start function.
//		intermediate commit - not yet finished.
// 2. Improved the test, and now it's failing.						 //improve test
// 3. fixed the bug - test passes.									 // fix bug
// 4. test - now it failse again on a <place>.						//impreve test
// 5. bugfix - fixed funciton - test pass.							// fix bug
// 6. Refactored the code.											//refactor

int main() {
	printf("tests are starting\n\n");
	//---- creat_snake tests ----------------
	bool isOk = 1;

	isOk &= (0 == what_return_when_get_good_numbers());

	//-----fee_snake tests -----------------
	isOk &= (0 == get_null_snake());


	printf("%d\n\n", isOk);

	return 0;
}



