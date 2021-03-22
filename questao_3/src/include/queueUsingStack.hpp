#ifndef QUEUEUSINGSTACK_H
#define QUEUEUSINGSTACK_H

#include "stack.hpp"
#include "queue.hpp"
#include "queueUsingStackException.hpp"

template<class T>
class queueUsingStack : queue<T>{
  private:
    linkedStack<T> *stackMain;
    linkedStack<T> *stackAux;

  public:
    queueUsingStack() : stackMain(nullptr), stackAux(nullptr) {};
    ~queueUsingStack() {
      delete stackMain;
      delete stackAux;
    }
    void printQUS() {
      if(!isEmpty()){
        stackMain->printStack();
      }
    };

    void enqueue(T elem) {
      if (isEmpty()) {
        stackMain = new linkedStack<T>(elem);
        stackAux = new linkedStack<T>();
        return;
      }
      stackMain->push(elem);
    };

    T dequeue() {
      if (isEmpty()) {
        throw emptyQueueUsingStackException();
      }
      T resp;
      while (!stackMain->isEmpty()) {
        stackAux->push(stackMain->pop());
      }

      resp = stackAux->pop();

      while (!stackAux->isEmpty()) {
        stackMain->push(stackAux->pop());
      }

      return resp;
    };

    T peekHead() {
      if (isEmpty()) {
        throw emptyQueueUsingStackException();
      }
      T resp;      
      while (!stackMain->isEmpty()) {
        stackAux->push(stackMain->pop());
      }
      stackAux->push(stackMain->pop());

      resp = stackAux->top();

      while (!stackAux->isEmpty()) {
        stackMain->push(stackAux->pop());
      }
      stackMain->push(stackAux->pop());

      return resp;
    };

    T peekTail() {
       if (isEmpty()) {
        throw emptyQueueUsingStackException();
      }
      return stackMain->top();
    };

    bool isEmpty() {
      if (!(stackMain == nullptr)){
        return (stackMain->isEmpty());
      }
      return true;
    };

    void clean() {
      while (!stackMain->isEmpty()) {
        stackMain->pop();
      }

    };


};


#endif
