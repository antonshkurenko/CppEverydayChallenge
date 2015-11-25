//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#ifndef CPPEVERYDAYCHALLENGE_RUNTIMEEXCEPTION_H
#define CPPEVERYDAYCHALLENGE_RUNTIMEEXCEPTION_H

#include <exception>

class RuntimeException: public std::exception
{
public:
    RuntimeException(char* message);

    virtual const char* what() const noexcept;

private:
    char* message_;
};

#endif //CPPEVERYDAYCHALLENGE_RUNTIMEEXCEPTION_H
