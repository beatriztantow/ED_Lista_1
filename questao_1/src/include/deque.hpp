/*
#########################################################
#                   C O N T R A T O S                   #
#########################################################
# - procedimento insereInicio(ref D: Deque, x: <TElem>) #
# - procedimento insereFim(ref D: Deque, x: <TElem>)    #
# - função removeInicio(ref D: Deque): <TElem>          #
# - função removeFim(ref D: Deque): <TElem>             #
# - função buscaInicio(ref D: Deque): <TElem>           #
# - função buscaFim(ref D: Deque):                      #
#########################################################
*/
#ifndef DEQUE_H
#define DEQUE_H

#include<iostream>

template <class TElem>
class deque {
  public:
    virtual void insertHead(TElem x) = 0;
    virtual void insertTail(TElem x) = 0;
    virtual TElem removeHead() = 0;
    virtual TElem removeTail() = 0;
    virtual TElem searchHead() = 0;
    virtual TElem searchTail() = 0;
};

template <class TElem>
class linkedDeque : deque<TElem> {
  private:
    struct node {
      TElem item;
      node *next;
      node *prev;

      node(TElem x) : item(x), next(nullptr), prev(nullptr) {};

    } *m_node{nullptr};

  public:
    void printLinkedDeque() {
      if (m_node) {
        node *aux = m_node;
        while (aux->next) {
          std::cout << "[" << aux->item << "] ";
          aux = aux->next;
        }
        std::cout << "[" << aux->item << "]\n";
      } else {
        std::cout << "Nao ha elementos na fila.";
      }
      
    }

    linkedDeque() : m_node(nullptr) {};

    linkedDeque(TElem x) {
      m_node = new node(x);
    };

    void insertHead(TElem x) {
      if(!m_node) {
        m_node = new node(x);
        return;
      }
      node *newNode = new node(x);
      node *aux = m_node;
      while (aux->prev) {
        aux = aux->prev;
      }
      aux->prev = newNode;
      newNode->next = aux;
      m_node = newNode;
    };

    void insertTail(TElem x) {
      if(!m_node) {
        m_node = new node(x);
        return;
      }
      node *newNode = new node(x);
      node *aux = m_node;
      while (aux->next) {
        aux = aux->next;
      }
      aux->next = newNode;
      newNode->prev = aux;
    };

    TElem removeHead() {
      node *headNode = m_node;
      TElem aux = headNode->item;
      
      if (headNode->next) {  
        m_node = headNode->next;
        m_node->prev = nullptr;
      }else {
        m_node = nullptr;
      }
      
      delete headNode;
      return aux;
    };

    TElem removeTail() {
      node *tailNode = m_node;
      while (tailNode->next) {
        tailNode = tailNode->next;
      }
      if (tailNode->prev){
        tailNode->prev->next = nullptr;
      }else{
        TElem aux = tailNode->item;
        delete tailNode;
        m_node = nullptr;
        return aux;
      }
      TElem aux = tailNode->item;
      delete tailNode;
      return aux;
    };

    TElem searchHead() {
      return m_node->item;
    };

    TElem searchTail() {
      node *tailNode = m_node;
      while (tailNode->next) {
        tailNode = tailNode->next;
      }
      return tailNode->item;
    };
};


template <class TElem>
class sequentialDeque : deque<TElem> {
  private:
    TElem *sD;
    int head;
    int tail;
    int currentSize;
    int capacity;

  public:

    void printSequentialDeque() {
      for (int i = 0; i < currentSize; i++) {
        std::cout << "[" << sD[((head + i) % capacity)] << "] ";
      }
      std::cout << std::endl;
    }

    sequentialDeque() {
      sD = new TElem[2];
      head = 0;
      tail = -1;
      currentSize = 0;
      capacity = 2;
    };

    sequentialDeque(TElem x) {
      sD = new TElem[2];
      sD[0] = x;
      head = 0;
      tail = 0;
      currentSize = 1;
      capacity = 2;
    };
  ~sequentialDeque() {
    delete[] sD;
  };

    bool isFull() {
      return currentSize == capacity;
    };

    void increaseCapacity() {
      int size = currentSize;
      TElem *newSD = new TElem[capacity*2];
      TElem *oldSD = sD;
      for (int i = 0; i < size; i++) {
        newSD[i] = removeHead();
      }
      capacity = capacity*2;
      head = 0;
      tail = size - 1;
      currentSize = size;
      sD = newSD;
      delete[] oldSD;
    };


    void insertHead(TElem x) {
      if(currentSize == 0) {
        sD[0] = x;
        head = 0;
        tail = 0;
        currentSize = 1;
        return;
      }
      if(isFull()) {
        increaseCapacity();
      }
      if (head == 0){
        head = capacity - 1;
      }else {
        head -= 1;
      }
      currentSize++;
      sD[head] = x;
    };

    void insertTail(TElem x) {
      if(currentSize == 0) {
        sD[0] = x;
        head = 0;
        tail = 0;
        currentSize = 1;
        return;
      }
      if(isFull()) {
        increaseCapacity();
      }
      tail = (tail + 1) % capacity;
      currentSize++;
      sD[tail] = x;
    };

    TElem removeHead() {
      TElem aux = sD[head];
      head = (head + 1) % capacity;
      currentSize--;
      return aux;
    };

    TElem removeTail() {
      TElem aux = sD[tail];
      if (tail == 0) {
        tail = capacity - 1;
      }else {
        tail -= 1;
      }
      currentSize--;
      return aux;
    };

    TElem searchHead() {
      return sD[head];
    };

    TElem searchTail() {
      return sD[tail];
    };
};

#endif
