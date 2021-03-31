#include "../src/include/reversePolishNotation.hpp"
#include <assert.h>
#include <string.h>

int main () {

  assert(reversePolishNotation("((A+B)*(C-(F/D)))").compare("AB+CFD/-*"));
  
  assert(reversePolishNotation("").compare(""));

  assert(reversePolishNotation("(((A+B)*(C-(F/D)))").compare("Expressao invalida.")); // um '(' a mais

  assert(reversePolishNotation("((A+B)*(C-(F/D))))").compare("Expressao invalida.")); // um ')' a mais

  return 0;
}