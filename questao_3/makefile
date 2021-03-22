test: test-stack test-queue test-queue-using-stack
	./build/testStack
	./build/testQueue
	./build/testQueueUsingStack

test-queue: test/testQueue.cpp
	g++ -g test/testQueue.cpp -o build/testQueue

debug-queue:
	gdb build/testQueue

test-queue-using-stack: test/testQueueUsingStack.cpp
	g++ -g test/testQueueUsingStack.cpp -o build/testQueueUsingStack

debug-queue-using-stack:
	gdb build/testQueueUsingStack

test-stack: test/testStack.cpp
	g++ -g test/testStack.cpp -o build/testStack

debug-stack:
	gdb build/testStack

clean: 
	rm -rf build/*

run: