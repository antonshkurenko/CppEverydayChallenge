//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#include <stdexcept>
#include <iostream>
#include <functional>
#include "../commons/utils.h"

using std::cout;

void inputBeverage(bool (*f)(int)) {

    const std::function<bool()> func = [&]() {
        cout << "\nChoose your beverage:" <<
        "\n1 - Whiskey;" <<
        "\n2 - Wine;" <<
        "\n3 - Cognac;" <<
        "\n4 - Tequila;" <<
        "\n5 - Other.\n";
        int beverage;

        safeInput(beverage);

        return f(beverage);
    };
    whileIncorrectExecute(func);
}

bool switchBeverage(int beverage) {

    cout << "\nSwitch output\n";
    bool breakFlag = true;
    switch (beverage) {
        case 1:
            cout << "\nGreat choice! One whiskey for this gentleman!";
            break;
        case 2:
            cout << "\nNice one! Taste your wine!";
            break;
        case 3:
            cout << "\nCongratz! Would you like a cigar?";
            break;
        case 4:
            cout << "\nAmigo! Enjoy your tequila!";
            break;
        case 5:
            cout << "\nWould you like a cup of beer? Or maybe coffee?";
            break;
        default:
            cout << "\nYou broke my heart.";
            breakFlag = false;
            break;
    }
    return breakFlag;
}

bool ifElseBeverage(int beverage) {

    cout << "\nIf-else output\n";
    bool breakFlag = true;
    if (beverage == 1) {
        cout << "\nGreat choice! One whiskey for this gentleman!";
    } else if (beverage == 2) {
        cout << "\nNice one! Taste your wine!";
    } else if (beverage == 3) {
        cout << "\nCongratz! Cognac is same good as you, would you like a cigar?";
    } else if (beverage == 4) {
        cout << "\nAmigo! Enjoy your tequila!";
    } else if (beverage == 5) {
        cout << "\nWould you like a cup of beer? Or maybe coffee?";
    } else {
        cout << "\nYou broke my heart.";
        breakFlag = false;
    }

    return breakFlag;
}

void chooseFlow() {

    int flow;

    const std::function<bool()> f = [&]() {
        cout << "\nChoose how program will execute.\n1 - switch;\n2 - if-else.\n";
        safeInput(flow);
        return flow == 1 || flow == 2;
    };
    whileIncorrectExecute(f);

    switch (flow) {
        case 1:
            inputBeverage(&switchBeverage);
            break;
        case 2:
            inputBeverage(&ifElseBeverage);
            break;
        default:
            // should never happen;
            cout << "\nYou visited Platform Nine and Three-Quarters";
            break;
    }
}

void secondDay() {

    cout << "Hello! It's second day excersize.\nMy name is Anton Shkurenko and you're welcome!";
    chooseFlow();
}

