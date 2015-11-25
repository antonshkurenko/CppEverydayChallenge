//
// Created by cullycross on 11/25/15.
// Follow me (@tonyshkurenko)
//

#include "../commons/RuntimeException.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;

char checkGrade(int grade) {
    char mark = '';
    if (grade < 0 || grade > 100) {
        throw RuntimeException((char *) "Score is not in 0..100 bounds");
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

int main(int argc, char *argv[]) {

    int grade;
    cout << "Hello! It's first day excersize.\nMy name is Anton Shkurenko and you're welcome!";
    cout << "\n*** \nInput your score (0..100): ";
    cin >> grade;
    cout << "\n";

    try {
        const char mark = checkGrade(grade);
        cout << "Your score is " << mark << "\n";
        if (mark == 'A') {
            cout << "Hey! Hey! Hey! Congratz!\n";
        }
    } catch (const RuntimeException &e) {
        cout << "Exception occured, message: " << e.what() << "\n";
    }
}

