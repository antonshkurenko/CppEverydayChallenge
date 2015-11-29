//
// Created by cullycross on 11/25/15.
// Follow me (@tonyshkurenko)
//

#include <iostream>
#include <stdexcept>
#include "../commons/utils.h"

char checkGrade(int grade) {
    char mark; // todo(cullycross), 11/27/15: how to set default non-empty value? '' is not valid.
    if (grade < 0 || grade > 100) {
        throw std::runtime_error((char*) "Score is not in 0..100 bounds");
    } else if (grade < 60) {
        mark = 'F';
    } else if (grade < 70) {
        mark = 'D';
    } else if (grade < 80) {
        mark = 'C';
    } else if (grade < 89) {
        mark = 'B';
    } else if (grade <= 100) {
        mark = 'A';
    }
    return mark;
}

void firstDay() {

    std::cout << "It's first day excersize.\nYou're welcome!";
    try {
        int grade;
        std::cout << "\n\nInput your score (0..100): ";
        utils::safeInput(grade);
        std::cout << "\n";

        const char mark = checkGrade(grade);
        std::cout << "Your score is " << mark << "\n";
        if (mark == 'A') {
            std::cout << "Hey! Hey! Hey! Congratz!\n";
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Exception occured, message: " << e.what() << "\n";
    }
}

