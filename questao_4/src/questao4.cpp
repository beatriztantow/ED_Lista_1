#include "../../questao_3/src/include/stack.hpp"
#include "../../questao_3/src/include/queue.hpp"

template<class T>
void invertsStackUsingOneQueue(linkedStack<T> *s) {
  if(s != nullptr && !s->isEmpty()) {
    linkedQueue<T> *q = new linkedQueue<T>();

    while (!s->isEmpty()) {
      q->enqueue(s->pop());
    }

    while (!q->isEmpty()) {
      s->push(q->dequeue());
    }
  }
}

template<class T>
void invertsStackUsingTwoStacks(linkedStack<T> *s) {
  if(s != nullptr && !s->isEmpty()) {
    linkedStack<T> *sAux1 = new linkedStack<int>;
    linkedStack<T> *sAux2 = new linkedStack<int>;

    while (!s->isEmpty()) {
      sAux1->push(s->pop());
    }
    while (!sAux1->isEmpty()) {
      sAux2->push(sAux1->pop());
    }
    while (!sAux2->isEmpty()) {
      s->push(sAux2->pop());
    }
  }
}

template<class T>
void invertsStackUsingOneStack(linkedStack<T> *s) {
  if(s != nullptr && !s->isEmpty()) {
    T temp;
    int count = 0;
    linkedStack<T> *sAux = new linkedStack<T>();

    temp = s->pop();
    while (!s->isEmpty()) {
      sAux->push(s->pop());
      count++;
    }
    s->push(temp);
    while (!sAux->isEmpty()) {
      s->push(sAux->pop());
    }

    while (count > 1) {
      temp = s->pop();
      for (int i = 0; i < count - 1; i++) {
        sAux->push(s->pop());
      }
      s->push(temp);
      while (!sAux->isEmpty()) {
        s->push(sAux->pop());
      }
      count--;
    }
  }
}