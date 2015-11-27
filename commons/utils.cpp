//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#include <functional>
#include <iostream>
#include <limits>
#include "utils.h"

// todo(cullycross), 11/28/15: still same question, what to do with <return_type>(*<func_name>)(<param_type>)

void whileIncorrectExecute(const std::function<bool()> func) {
    while (true) {
        if (func()) {
            break;
        }
    }
}

// todo(cullycross), 11/27/15: rework it, to safeInput(std::istream cin, T &type)
template<typename T>
void safeInput(T& type) {
    whileIncorrectExecute([&]() {
        if (!(std::cin >> type)) {
            std::cout << "\nPlease enter a valid input:\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        } else {
            return true;
        }
    });
}

template void safeInput<int>(int& type);
