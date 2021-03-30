#include "../../questao_3/src/include/stack.hpp"
#include "../../questao_3/src/include/queue.hpp"

template<class T>
void invertsQueueUsingOneStack(linkedQueue<T> *q) {
  linkedStack<T> *s = new linkedStack<T>();
  while (!q->isEmpty()) {
    s->push(q->dequeue());
  }
  while (!s->isEmpty()) {
    q->enqueue(s->pop());
  }
}

template<class T>
void invertsQueueUsingTwoQueues(linkedQueue<T> *q) {
  linkedQueue<T> *qAux1 = new linkedQueue<T>();
  linkedQueue<T> *qAux2 = new linkedQueue<T>();
  int count = 0;

  while (!q->isEmpty()) {
    qAux1->enqueue(q->dequeue());
    count++;
  }
  while (count > 0) {
    for (int i = 0; i < count - 1; i++) {
      qAux2->enqueue(qAux1->dequeue());
    }
    q->enqueue(qAux1->dequeue());
    for (int i = 0; i < count - 1; i++) {
      qAux1->enqueue(qAux2->dequeue());
    }
    count--;
  }
}