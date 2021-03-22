#ifndef QUEUEUSINGSTACKEXCEPTIONS_H
#define QUEUEUSINGSTACKEXCEPTIONS_H

#include "queueExceptions.hpp"

class emptyQueueUsingStackException : public emptyQueueException {
  public:
    const char * what () const throw () {
      return "Empty queue.\n";
    };
};

#endif