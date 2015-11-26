//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#ifndef CPPEVERYDAYCHALLENGE_UTILS_H
#define CPPEVERYDAYCHALLENGE_UTILS_H

#include <istream>
#include <functional>

//void whileIncorrectExecute(bool (*function)());
void whileIncorrectExecute(const std::function<bool()> func);

template<typename T> void safeInput(T &type);

#endif //CPPEVERYDAYCHALLENGE_UTILS_H
