#include <iostream>
#include <assert.h>
#include "../src/include/queueUsingStack.hpp"

int main() {

  queueUsingStack<int> *q = new queueUsingStack<int>();
  int aux;

  q->enqueue(1);
  assert(q->peekTail() == 1);  

  q->enqueue(2);
  assert(q->peekTail() == 2);
  
  q->enqueue(3);
  assert(q->peekTail() == 3);

  aux = q->dequeue();
  assert(aux == 1);

  aux = q->dequeue();
  assert(aux == 2);
  

  aux = q->dequeue();
  assert(aux == 3);

  try {
    q->dequeue();
    assert(false);
  } catch(const emptyQueueException e) {
    assert(true);
  }

  return 0;

}