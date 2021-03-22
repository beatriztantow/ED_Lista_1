#ifndef STACK_H
#define STACK_H

#include "stackExceptions.hpp"

template<class T>
class stack {
  public:
    virtual void push(T elem) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual bool isEmpty() = 0;
    virtual void clean() = 0;
};

template<class T>
class linkedStack : stack<T> {
  private:
    struct node {
      T info;
      node *next;

      node(T elem) : info(elem), next(nullptr) {};
      node(T elem, node *refNext) : info(elem), next(refNext) {};

    } *topNode{nullptr};
    
  public:
    linkedStack() : topNode(nullptr) {};

    linkedStack(T elem) : topNode(new node(elem)) {};

    void printStack() {
      node *aux = topNode;
      if (isEmpty()) {
        return;
      }
      while (aux->next) {
        std::cout << "[" << aux->info << "] ";
        aux = aux->next;
      }
      std::cout << "[" << aux->info << "]\n";
    };

    void push(T elem) {
      if (isEmpty()) {
        topNode = new node(elem);
        return;
      }
      node *newNode = new node(elem, topNode);
      topNode = newNode;
    };

    T pop() {
      if (isEmpty()) {
        throw emptyStackException();
      }
      T resp = topNode->info;
      node *aux = topNode;
      if(topNode->next) {
        topNode = topNode->next;
      }else {
        topNode = nullptr;
      }
      delete aux;
      return resp;
    };

    T top() {
      T resp = pop();
      push(resp);
      return resp;
    };

    bool isEmpty() {
      return (topNode == nullptr);
    };

    void clean() {
      while(!isEmpty()) {
        pop();
      }
    };
};

/*
TODO sequential implementation
*/

#endif