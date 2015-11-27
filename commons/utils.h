//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#ifndef CPPEVERYDAYCHALLENGE_UTILS_H
#define CPPEVERYDAYCHALLENGE_UTILS_H

#include <istream>
#include <functional>

// todo(cullycross), 11/28/15: I don't know where to save this todo, namespaces in util headers

void whileIncorrectExecute(const std::function<bool()> func);

template<typename T>
void safeInput(T& type);

#endif //CPPEVERYDAYCHALLENGE_UTILS_H
