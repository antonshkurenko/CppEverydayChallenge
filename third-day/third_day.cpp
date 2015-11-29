//
// Created by cullycross on 11/27/15.
// Follow me (@tonyshkurenko)
//

#include <iostream>
#include <functional>
#include "third_day.h"
#include "../commons/utils.h"

void five() {
    int counter{0};
    utils::whileIncorrectExecute([&counter]() {
        int five;
        std::cout << "Input anything except five: ";
        utils::safeInput(five);

        if (five != 5) {
            counter++;
            if (counter % 10 == 0) {
                std::cout << "Wow, you're more patient then I am, you win.\n";
                return true;
            }
            return false;
        } else {
            std::cout << "You weren't supposed to enter five!\n";
            return true;
        }
    });
}

void counter() {
    int counter{0};
    static char outString[128];
    utils::whileIncorrectExecute([&counter]() { // is it better to mention every variable or just [&] ?
        int anything;
        sprintf(outString, "Input anything except %d: ", counter);
        std::cout << outString;
        utils::safeInput(anything);

        if (anything != counter) {
            counter++;
            return false;
        } else {
            sprintf(outString, "You weren't supposed to enter %d!\n", counter);
            std::cout << outString;
            return true;
        }
    });
}

void execute() {
    utils::whileIncorrectExecute([]() {
        std::cout << "\nChoose your hero:" <<
        "\n1 - It's about five;" <<
        "\n2 - It's about counter.\n";
        int choice;

        utils::safeInput(choice);
        bool breakFlag = true;
        switch (choice) {
            case 1:
                five();
                break;
            case 2:
                counter();
                break;
            default:
                breakFlag = false;
                break;
        }
        return breakFlag;
    });
}

void thirdDay() {

    std::cout << "It's third day excersize.\nYou're welcome!";
    execute();
}