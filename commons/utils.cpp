//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#include <functional>
#include <iostream>
#include <limits>
#include "utils.h"

/*void whileIncorrectExecute(bool (*function)()) {
    while (true) {
        if (function()) {
            break;
        }
    }
}*/

void whileIncorrectExecute(const std::function<bool()> func) {
    while (true) {
        if (func()) {
            break;
        }
    }
}

// todo(cullycross), 11/27/15: rework it, to safeInput(std::istream cin, T &type)
template<typename T>
void safeInput(T &type) {

    const std::function<bool()> func = [&]() {
        if (!(std::cin >> type)) {
            std::cout << "\nPlease enter a valid input:\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        } else {
            return true;
        }
    };
    whileIncorrectExecute(func);
}

template void safeInput<int> (int &type); // unbelievable, do I really need this? Pretty not flexible.
