//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#include <functional>
#include <iostream>
#include <algorithm>
#include "utils.h"

// todo(cullycross), 11/28/15: still same question, what to do with <return_type>(*<func_name>)(<param_type>)

void utils::whileIncorrectExecute(const std::function<bool()> func) {
    while (true) {
        if (func()) {
            break;
        }
    }
}

// todo(cullycross), 11/27/15: rework it, to safeInput(std::istream cin, T &type)
// todo(cullycross), 11/29/15: rework it, add comparator, to check if value is safe/valid
template<typename T>
void utils::safeInput(T& type) {
    utils::whileIncorrectExecute([&]() {
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

template void utils::safeInput<int>(int& type);

int utils::random(int min, int max) { // todo(cullycross), 11/29/15: unreal thing, can't understand at all
    std::random_device rd; // instantiating an object

    // also why it can not be a const?
    std::mt19937 mt(rd()); // with () it works, but it doesn't with mt{std::random_device}, what is this?
    std::uniform_int_distribution<int> dist(min, max); // and here I can't use this as const
    return dist(mt); // and this is func call?
}