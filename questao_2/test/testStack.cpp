#include "../src/include/stack.hpp"
#include<assert.h>

int main() {

  int aux;
  stack<int> s;

  s.push(1);
  assert(s.top() == 1);
  
  s.push(2);
  assert(s.top() == 2);

  aux = s.pop();
  assert(aux == 2);

  s.push(3);
  assert(s.top() == 3);

  aux = s.pop();
  assert(aux == 3);

  aux = s.pop();
  assert(aux == 1);

  return 0;
}