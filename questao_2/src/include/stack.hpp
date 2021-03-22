#ifndef STACK_H
#define STACK_H

#include "../../../questao_1/src/include/deque.hpp"
#include<iostream>

template<class TElem>
class queue {
  private:
    linkedDeque<TElem> *lD;

  public:
    queue() {
      lD = new linkedDeque<TElem>();
    }
    void enqueue(TElem x) {
      lD->insertTail(x);
    };
    
    TElem dequeue() {
      return lD->removeHead();
    }
};

template<class TElem>
class stack {
  private:
    queue<TElem> *queueMain;
    queue<TElem> *queueAux;
    int count;

  public:
    stack() {
      queueMain = new queue<TElem>();
      queueAux = new queue<TElem>();
      count = 0;
    };

    TElem pop() {
      TElem resp;
      if (count > 0) {
        for (int i = 0; i < count - 1; i++) {
          queueAux->enqueue(queueMain->dequeue());
        }
        resp = queueMain->dequeue();
        count--;
        for (int i = 0; i < count; i++) {
          queueMain->enqueue(queueAux->dequeue());
        }
      }else {
        std::cout << "Esta pilha esta vazia.\n";
      }
      return resp;
    };

    void push(TElem x) {
      queueMain->enqueue(x);
      count++;
    };

    TElem top() {
      TElem resp;
      if (count > 0) {
        resp = pop();
        push(resp);
      }else {
        std::cout << "Esta pilha esta vazia.\n";
      }
      return resp;
    };
};


#endif
