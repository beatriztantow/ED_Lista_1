#include "../src/questao6.cpp"
#include <assert.h>
#include <iostream>

int main () {

  PilhaMin *p = new PilhaMin();

  p->push(3);
  p->push(4);
  assert(p->obterMinimo() == 3);
  p->push(2);
  p->push(5);
  assert(p->obterMinimo() == 2);
  p->pop();
  p->pop();
  assert(p->obterMinimo() == 3);

  return 0;
}