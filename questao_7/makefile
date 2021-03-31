test: test-testQuestao7
	./build/testQuestao7

reverse-polish-notation: src/reversePolishNotation.cpp src/include/reversePolishNotation.hpp
	g++ -c src/reversePolishNotation.cpp -o build/reversePolishNotation

test-testQuestao7: reverse-polish-notation test/testQuestao7.cpp
	g++ -Wall -Wextra -Werror -g test/testQuestao7.cpp build/reversePolishNotation -o build/testQuestao7

debug-questao7:
	gdb build/testQuestao7

clean:
	rm -rf build/*

run: