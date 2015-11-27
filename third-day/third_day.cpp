//
// Created by cullycross on 11/27/15.
// Follow me (@tonyshkurenko)
//

#include <iostream>
#include <functional>
#include "third_day.h"
#include "../commons/utils.h"

void five() {
    int counter = 0;
    whileIncorrectExecute([&counter]() {
        int five;
        std::cout << "Input anything except five: ";
        safeInput(five);

        if (five != 5) {
            counter++;
            if (counter % 10 == 0) {
                std::cout << "Wow, you're more patient then I am, you win.\n";
                return true;
            }
            return false;
        } else {
            return true;
        }
    });
}

void counter() {
    int counter = 0;

    // todo(cullycross), 11/28/15: now memory allocating? now "new" or etc keyword? malloc etc?
    //                             just simple declaring?
    char outString[128];
    whileIncorrectExecute([&counter, &outString]() { // is it better to mention every variable or just [&] ?
        int anything;
        sprintf(outString, "Input anything except %d: ", counter);
        std::cout << outString;
        safeInput(anything);

        if (anything != counter) {
            counter++;
            return false;
        } else {
            return true;
        }
    });
}

void execute() {
    whileIncorrectExecute([]() {
        std::cout << "\nChoose your hero:" <<
        "\n1 - It's about five;" <<
        "\n2 - It's about counter.\n";
        int choice;

        safeInput(choice);
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