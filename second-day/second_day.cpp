//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#include <stdexcept>
#include <iostream>
#include <functional>
#include "../commons/utils.h"
#include "second_day.h"

void inputBeverage(const std::function<bool(int)> f) {
    utils::whileIncorrectExecute([&]() {
        std::cout << "\nChoose your beverage:" <<
        "\n1 - Whiskey;" <<
        "\n2 - Wine;" <<
        "\n3 - Cognac;" <<
        "\n4 - Tequila;" <<
        "\n5 - Other.\n";
        int beverage;

        utils::safeInput(beverage);
        return f(beverage);
    });
}

bool switchBeverage(int beverage) {

    std::cout << "\nSwitch output: ";
    bool breakFlag{true};
    switch (beverage) {
        case 1:
            std::cout << CHOICE_WHISKEY;
            break;
        case 2:
            std::cout << CHOICE_WINE;
            break;
        case 3:
            std::cout << CHOICE_COGNAC;
            break;
        case 4:
            std::cout << CHOICE_TEQUILA;
            break;
        case 5:
            std::cout << CHOICE_OTHER;
            break;
        default:
            std::cout << CHOICE_BROKEN_HEART;
            breakFlag = false;
            break;
    }
    return breakFlag;
}

bool ifElseBeverage(int beverage) {

    std::cout << "\nIf-else output: ";
    bool breakFlag{true};
    if (beverage == 1) {
        std::cout << CHOICE_WHISKEY;
    } else if (beverage == 2) {
        std::cout << CHOICE_WINE;
    } else if (beverage == 3) {
        std::cout << CHOICE_COGNAC;
    } else if (beverage == 4) {
        std::cout << CHOICE_TEQUILA;
    } else if (beverage == 5) {
        std::cout << CHOICE_OTHER;
    } else {
        std::cout << CHOICE_BROKEN_HEART;
        breakFlag = false;
    }
    return breakFlag;
}

void chooseFlow() {

    int flow;

    utils::whileIncorrectExecute([&]() {
        std::cout << "\nChoose how program will execute.\n1 - switch;\n2 - if-else.\n";
        utils::safeInput(flow);
        return flow == 1 || flow == 2;
    });

    switch (flow) {
        case 1:
            inputBeverage(&switchBeverage);
            break;
        case 2:
            inputBeverage(&ifElseBeverage);
            break;
        default:
            // should never happen;
            std::cout << "\nYou visited Platform Nine and Three-Quarters";
            break;
    }
}

void secondDay() {

    std::cout << "It's second day excersize.\nYou're welcome!";
    chooseFlow();
}

