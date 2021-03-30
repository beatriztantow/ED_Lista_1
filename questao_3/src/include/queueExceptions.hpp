#ifndef QUEUEEXCEPTIONS_H
#define QUEUEEXCEPTIONS_H

#include <exception>

class emptyQueueException : public std::exception {
  public:
    const char * what () const throw () {
      return "Empty queue.\n";
    };
};

#endif