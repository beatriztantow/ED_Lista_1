#include "../src/include/deque.hpp"
#include <assert.h>


int main() {
  
  int aux;

  linkedDeque<int> lD;
  sequentialDeque<int> sD;

  lD.insertHead(0);
  assert(lD.searchHead() == 0);

  lD.insertTail(1);
  assert(lD.searchTail() == 1);

  aux = lD.removeHead();
  assert(aux == 0);

  aux = lD.searchTail();
  assert(aux == 1);

  aux = lD.searchHead();
  assert(aux == 1);

  aux = lD.removeTail();
  assert(aux == 1);

  lD.insertHead(2);
  assert(lD.searchHead() == 2);

  aux = lD.searchHead();
  assert(aux == 2);

  aux = lD.removeTail();
  assert(aux == 2);


/*##################################*/
  sD.insertHead(0);
  assert(sD.searchHead() == 0);

  sD.insertTail(1);
  assert(sD.searchTail() == 1);

  aux = sD.removeHead();
  assert(aux == 0);

  aux = sD.searchTail();
  assert(aux == 1);

  aux = sD.searchHead();
  assert(aux == 1);

  aux = sD.removeTail();
  assert(aux == 1);

  sD.insertHead(2);
  assert(sD.searchHead() == 2);

  aux = sD.searchHead();
  assert(aux == 2);

  aux = sD.removeTail();
  assert(aux == 2);

  sD.insertHead(1);
  assert(sD.searchHead() == 1);

  sD.insertHead(2);
  assert(sD.searchHead() == 2);

  sD.insertHead(3);
  assert(sD.searchHead() == 3);

  return 0;
}