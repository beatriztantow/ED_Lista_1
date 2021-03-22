testStack: src/include/stack.hpp test/testStack.cpp
	mkdir -p build
	g++ -g test/testStack.cpp -o build/testStack -Wall -Wextra -Werror

test: testStack
	build/testStack
	valgrind --leak-check=full --error-exitcode=1 -s build/testStack

debug: testStack
	mkdir -p build
	gdb build/testStack

clean: 
	rm -rf build/*

run_all: test
