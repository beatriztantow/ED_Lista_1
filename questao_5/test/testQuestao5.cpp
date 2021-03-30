#include "../../questao_3/src/include/queue.hpp"
#include "../src/questao5.cpp"
#include <assert.h>
#include <iostream>

void mount(linkedQueue<int> *qMain, linkedQueue<int> *qComparison) {
  int n = 3;
  for (int i = 0; i < n; i++) {
    qMain->enqueue(i);
  }

  for (int i = n - 1; i >= 0; i--) {
    qComparison->enqueue(i);
  }
}

bool isEqual (linkedQueue<int> *qMain, linkedQueue<int> *qComparison) {
  while (!qMain->isEmpty() && !qComparison->isEmpty()) {
    if (qMain->dequeue() != qComparison->dequeue()) {
      return false;
    }
  }
  if(!qComparison->isEmpty() || !qComparison->isEmpty()){
    return false;
  }
  return true;
}

int main() {
  linkedQueue<int> *qMain = new linkedQueue<int>();
  linkedQueue<int> *qComparison = new linkedQueue<int>();

  mount(qMain, qComparison);
  invertsQueueUsingOneStack(qMain);
  isEqual(qMain, qComparison);

  mount(qMain, qComparison);
  invertsQueueUsingTwoQueues(qMain);
  isEqual(qMain, qComparison);

  return 0;
}