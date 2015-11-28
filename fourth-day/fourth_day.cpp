//
// Created by cullycross on 11/28/15.
// Follow me (@tonyshkurenko)
//

#include <iostream>
#include <bits/stl_algo.h>
#include "fourth_day.h"
#include "../commons/utils.h"

void setupPancakes() {

    char outString[128];
    std::pair<int, int> peopleAndPancakes[LENGTH]; // todo(cullycross), 11/28/15: arrays vs vector? Is vector same usual as ArrayList in Java?
    // todo(cullycross), 11/28/15: is there any foreach cycle?
    for (int i = 0; i < LENGTH; i++) {
        peopleAndPancakes[i].first = i + 1;
        sprintf(outString, "\nInput %d person's pancakes: ", peopleAndPancakes[i].first);
        std::cout << outString;
        whileIncorrectExecute([&peopleAndPancakes, i]() {
            safeInput(peopleAndPancakes[i].second);

            // todo(cullycross), 11/28/15: was it possible to use unsigned int? will it produce error, if I "cin >> -1"
            if (peopleAndPancakes[i].second < 0) {
                std::cout << "\nInput positive value: ";
                return false;
            } else {
                return true;
            }
        });
    }

    std::sort(std::begin(peopleAndPancakes), std::end(peopleAndPancakes),
              [](std::pair<int, int> first, std::pair<int, int> second) {
                  return first.second > second.second;
              });

    std::cout << "\nPeople and pancakes: ";
    std::cout << "\nThe highest and the lowest pancake count:";
    sprintf(outString, "\nPerson #%d ate %d pancake(s) (huh, pretty a lot).", peopleAndPancakes[0].first,
            peopleAndPancakes[0].second);
    std::cout << outString;
    sprintf(outString, "\nPerson #%d ate %d pancake(s) (feed him someone!).", peopleAndPancakes[LENGTH - 1].first,
            peopleAndPancakes[LENGTH - 1].second);
    std::cout << outString;
    std::cout << "\nOthers:";
    for (int i = 0; i < LENGTH; i++) {
        sprintf(outString, "\nPerson #%d ate %d pancake(s).", peopleAndPancakes[i].first,
                peopleAndPancakes[i].second);
        std::cout << outString;
    }
}

void fourthDay() {

    std::cout << "It's fourth day excersize.\nYou're welcome!";
    setupPancakes();
}
