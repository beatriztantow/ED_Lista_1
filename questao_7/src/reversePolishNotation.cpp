#include "../../questao_3/src/include/stack.hpp"
#include "include/reversePolishNotation.hpp"

std::string reversePolishNotation(const char* expression) {
  std::string rpn;
  linkedStack<char> *s1 = new linkedStack<char>();
  linkedStack<char> *s2 = new linkedStack<char>();
  int i = 0;

  while(expression[i] != '\0') {

    if (expression[i] == '(') {
      s1->push(expression[i]);
    } else if(expression[i] == ')') {
      try {
        s1->pop();
        rpn.push_back(s2->pop());
      }
      catch(const std::exception& e) {
        return "Expressao invalida.\n";
      }
    } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
      s2->push(expression[i]);
    } else {
      rpn.push_back(expression[i]);
    }
    i++;
  }

  rpn.push_back('\0');
  if (!s1->isEmpty() || !s2->isEmpty()) {
      return "Expressao invalida.\n";
    }

  return rpn;
}