//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#include <functional>
#include <iostream>
#include <limits>
#include "commons/utils.h"
#include "first-day/first_day.h"
#include "second-day/second_day.h"

int main(int argc, char **argv) {

    const std::function<bool()> func = [&]() {

        std::cout << "My name is Anton Shkurenko and you're welcome! This is my try to learn C++ in 21 days!";
        std::cout << "\nChoose task:" <<
        "\n1 - first day" <<
        "\n2 - second day\n";
        int day;

        safeInput<int>(day);

        bool breakFlag = true;
        switch (day) {
            case 1:
                firstDay();
                break;
            case 2:
                secondDay();
                break;
            default:
                breakFlag = false;
                break;
        }
        return breakFlag;
    };
    whileIncorrectExecute(func);

    return 1;
}
