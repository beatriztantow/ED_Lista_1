test: testDeque
	build/testDeque
	valgrind --leak-check=full --error-exitcode=1 -s build/testDeque

testDeque: test/testDeque.cpp
	mkdir -p build
	g++ -g test/testDeque.cpp -o build/testDeque -Wall -Wextra -Werror

clean: 
	rm -rf build/*

run:
