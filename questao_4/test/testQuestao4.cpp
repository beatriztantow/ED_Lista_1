#include "../../questao_3/src/include/stack.hpp"
#include "../src/questao4.cpp"
#include <assert.h>
#include <iostream>

void mount(linkedStack<int> *sMain, linkedStack<int> *sComparison) {
  int n = 3;
  for (int i = 0; i < n; i++) {
    sMain->push(i);
  }

  for (int i = n - 1; i >= 0; i--) {
    sComparison->push(i);
  }
}

bool isEqual (linkedStack<int> *sMain, linkedStack<int> *sComparison) {
  while (!sMain->isEmpty() && !sComparison->isEmpty()) {
    if (sMain->pop() != sComparison->pop()) {
      return false;
    }
  }
  if(!sComparison->isEmpty() || !sComparison->isEmpty()){
    return false;
  }
  return true;
}

int main() {

  linkedStack<int> *sMain = new linkedStack<int>();
  linkedStack<int> *sComparison = new linkedStack<int>();

  mount(sMain, sComparison);
  invertsStackUsingOneQueue(sMain);
  assert(isEqual(sMain, sComparison));

  mount(sMain, sComparison);
  invertsStackUsingOneStack(sMain);
  assert(isEqual(sMain, sComparison));

  mount(sMain, sComparison);
  invertsStackUsingTwoStacks(sMain);
  assert(isEqual(sMain, sComparison));

  return 0;
}