#ifndef QUEUE_H
#define QUEUE_H

#include "queueExceptions.hpp"

template<class T>
class queue {
  public:
    virtual void enqueue(T elem) = 0;
    virtual T dequeue() = 0;
    virtual T peekHead() = 0;
    virtual T peekTail() = 0;
    virtual bool isEmpty() = 0;
    virtual void clean() = 0;
    virtual ~queue() = default;
};

template<class T>
class linkedQueue : queue<T> {
  private:
    struct node {
      T info;
      node *next;

      node(T elem) : info(elem), next(nullptr) {};

    } *headNode{nullptr};

  node* goTail() {
    node *resp = headNode;
    while (resp->next) {
      resp = resp->next;
    }
    return resp;
  };

  public:
    linkedQueue() : headNode(nullptr) {};

    linkedQueue(T elem) : headNode(new node(elem)) {};
    ~linkedQueue() {
      if(headNode==nullptr) return;
      auto aux = headNode;
      while(aux) {
	auto aux2=aux->next;
	delete aux;
	aux=aux2;
      }
    }

    void enqueue(T elem) {
      if(isEmpty()) {
        headNode = new node(elem);
        return;
      }
      node *newNode = new node(elem);
      node *tailNode = goTail();
      tailNode->next = newNode;
    };

    T dequeue() {
      if(isEmpty()) {
        throw emptyQueueException();
      }
      T resp = headNode->info;
      node *aux = headNode;
      if (headNode->next) {
        headNode = headNode->next;
      }else{
        headNode = nullptr;
      }
      delete aux;
      return resp;
    };

    T peekHead() {
      return headNode->info;
    };

    T peekTail() {
      node *aux = goTail();
      return aux->info;
    };

    bool isEmpty() {
      return (headNode == nullptr);
    };

    void clean() {
      while (!isEmpty()) {
        dequeue();
      }
    };

};

/*
TODO sequential implementation
*/

#endif
