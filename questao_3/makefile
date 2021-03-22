test: test-stack test-queue test-queue-using-stack
	./build/testStack
	valgrind --leak-check=full --error-exitcode=1 -s build/testStack
	./build/testQueue
	valgrind --leak-check=full --error-exitcode=1 -s build/testQueue
	./build/testQueueUsingStack
	valgrind --leak-check=full --error-exitcode=1 -s build/testQueueUsingStack

test-queue: test/testQueue.cpp
	mkdir -p build
	g++ -g test/testQueue.cpp -o build/testQueue -Wall -Wextra -Werror

debug-queue:
	gdb build/testQueue

test-queue-using-stack: test/testQueueUsingStack.cpp
	mkdir -p build
	g++ -g test/testQueueUsingStack.cpp -o build/testQueueUsingStack -Wall -Wextra -Werror

debug-queue-using-stack:
	gdb build/testQueueUsingStack

test-stack: test/testStack.cpp
	mkdir -p build
	g++ -g test/testStack.cpp -o build/testStack -Wall -Wextra -Werror

debug-stack:
	gdb build/testStack

clean: 
	rm -rf build/*

run:
