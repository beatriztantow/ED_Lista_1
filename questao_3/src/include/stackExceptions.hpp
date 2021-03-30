#ifndef STACKEXCEPTIONS_H
#define STACKEXCEPTIONS_H

#include <exception>

class emptyStackException : public std::exception {
  public:
    const char * what () const throw () {
      return "Empty stack.\n";
    };
};

#endif