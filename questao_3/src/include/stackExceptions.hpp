#ifndef STACKEXCEPTIONS_H
#define STACKEXCEPTIONS_H

class emptyStackException : public std::exception {
  public:
    const char * what () const throw () {
      return "Empty stack.\n";
    };
};

#endif