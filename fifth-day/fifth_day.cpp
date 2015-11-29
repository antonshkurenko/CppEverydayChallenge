//
// Created by cullycross on 11/29/15.
// Follow me (@tonyshkurenko)
//

#include <iostream>
#include <cmath>
#include <limits.h>
#include "fifth_day.h"
#include "../commons/utils.h"

bool isRandomly() {
    bool random;
    utils::whileIncorrectExecute([&random]() {
        std::cout << "\nChoose the way, computer will guess:" <<
        "\n1 - Randomly;" <<
        "\n2 - Using it's brain.\n";
        int choice;

        utils::safeInput(choice);
        bool breakFlag = true;
        switch (choice) {
            case 1:
                random = true;
                break;
            case 2:
                random = false;
                break;
            default:
                breakFlag = false;
                break;
        }
        return breakFlag;
    });
    return random;
}

void userGuess() {
    std::cout << "\nComputer thought of a number...\n";

    int counter{0};
    static char outString[128];

    const auto number = utils::random(LOW_BOUND, std::nextafter(TOP_BOUND, INT_MAX));
    utils::whileIncorrectExecute([&counter, outString, number]() {
        int guess;

        sprintf(outString, "\nTry #%d", ++counter);
        std::cout << outString;
        std::cout<<"\n\nInput your expectations: ";
        utils::safeInput(guess);

        if (guess == number) {
            std::cout << "\nCongratz! You guessed right!";
        } else if (guess > number) {
            std::cout << "\nIt's larger!";
        } else {
            std::cout << "\nIt's less!";
        };
        return guess == number;
    });
}

void randomGuess(int number) {
    int lowBound{LOW_BOUND}, topBound{TOP_BOUND};
    int counter{0};
    static char outString[128]; // todo(cullycross), 11/29/15: is this a good decision?

    utils::whileIncorrectExecute([&counter, &lowBound, &topBound, outString, number]() {
        const int guess = utils::random(lowBound, std::nextafter(topBound, INT_MAX));

        sprintf(outString, "\nTry #%d", ++counter);
        std::cout << outString;
        sprintf(outString, "\nComputer tries number %d", guess);
        std::cout << outString;

        if (guess == number) {
            std::cout << "\nGuessed!!!";
        } else if (guess > number) {
            topBound = guess - 1;
        } else {
            lowBound = guess + 1;
        }

        return guess == number;
    });
}

void bitSearchGuess(int number) {
    int lowBound{LOW_BOUND}, topBound{TOP_BOUND};
    int counter{0};
    static char outString[128];

    utils::whileIncorrectExecute([&counter, &lowBound, &topBound, number]() {
        const int guess{(topBound + lowBound) >> 1};

        sprintf(outString, "\n\nTry #%d. ", ++counter);
        std::cout << outString;
        sprintf(outString, "Computer tries number %d", guess);
        std::cout << outString;

        if (guess == number) {
            std::cout << "\nGuessed!!!";
        } else if (guess > number) {
            topBound = guess - 1;
        } else {
            lowBound = guess + 1;
        }

        return guess == number;
    });
}

void computerGuess() {
    std::cout << "\nThink of a number (1..100)...\n";

    int number;
    utils::whileIncorrectExecute([&number]() {
        utils::safeInput(number);

        return number > 0 && number <= 100;
    });

    if (isRandomly()) {
        randomGuess(number);
    } else {
        bitSearchGuess(number);
    }
}

void startGuessing() {
    utils::whileIncorrectExecute([]() {
        std::cout << "\nChoose your way:" <<
        "\n1 - You guess;" <<
        "\n2 - Computer guesses.\n";
        int choice;

        utils::safeInput(choice);
        bool breakFlag = true;
        switch (choice) {
            case 1:
                userGuess();
                break;
            case 2:
                computerGuess();
                break;
            default:
                breakFlag = false;
                break;
        }
        return breakFlag;
    });
}

void fifthDay() {

    std::cout << "It's fifth day excersize.\nYou're welcome!";
    startGuessing();
}


