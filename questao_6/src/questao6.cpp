#include "../../questao_3/src/include/stack.hpp"

#include <algorithm>

class PilhaMin : stack<int>{
  private:
    linkedStack<int> *sMain;
    linkedStack<int> *sMin;

  public:
    PilhaMin() {
      sMain = new linkedStack<int>();
      sMin = new linkedStack<int>();
    }

    void push(int elem) {
      sMain->push(elem);
      
      if (!sMin->isEmpty()) {
        sMin->push(std::min(elem, sMin->top()));
      }else {
        sMin->push(elem);
      }
    }

    int pop() {
      sMin->pop();
      return sMain->pop();
    }

    int top() {
      return sMain->top();
    }

    bool isEmpty() {
      return sMain->isEmpty();
    }

    void clean() {
      sMin->clean();
      sMain->clean();
    }

    int obterMinimo() {
      return sMin->top();
    }
};