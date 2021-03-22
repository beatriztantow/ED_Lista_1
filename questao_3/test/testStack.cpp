#include <iostream>
#include <assert.h>
#include "../src/include/stack.hpp"

int main() {

  linkedStack<int> *s = new linkedStack<int>();
  int aux;

  s->push(1);
  assert(s->top() == 1);

  s->push(2);
  assert(s->top() == 2);

  s->push(3);
  assert(s->top() == 3);

  aux = s->pop();
  assert(aux == 3);

  try {
    s->pop();
    s->pop();
    s->pop();
    assert(false);
  }
  catch(const emptyStackException& e) {
    assert(true);
  }
  

  return 0;
}