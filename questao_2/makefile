testStack: src/include/stack.hpp test/testStack.cpp
	g++ -g test/testStack.cpp -o build/testStack

test: testStack
	./build/testStack

debug: testStack
	gdb build/testStack

clean: 
	rm -rf build/*

run_all: test
