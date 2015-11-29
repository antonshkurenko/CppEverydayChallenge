//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#ifndef CPPEVERYDAYCHALLENGE_UTILS_H
#define CPPEVERYDAYCHALLENGE_UTILS_H

#include <istream>
#include <functional>

namespace utils {
    void whileIncorrectExecute(const std::function<bool()> func);

    template<typename T>
    void safeInput(T& type);

    int random(int min, int max);
}

#endif //CPPEVERYDAYCHALLENGE_UTILS_H
