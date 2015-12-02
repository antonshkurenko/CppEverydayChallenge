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
#include "third-day/third_day.h"
#include "fourth-day/fourth_day.h"
#include "fifth-day/fifth_day.h"
#include "sixth-seventh-day/sixth_seventh_day.h"

int main(int argc, char** argv) {

    utils::whileIncorrectExecute([]() {

        std::cout << "My name is Anton Shkurenko and you're welcome! This is my try to learn C++ in 21 days!";
        std::cout << "\nChoose task:" <<
        "\n1 - first day" <<
        "\n2 - second day" <<
        "\n3 - third day" <<
        "\n4 - fourth day" <<
        "\n5 - fifth day" <<
        "\n6 - sixth day" <<
        "\n-1 - exit\n";
        int day;

        utils::safeInput<int>(day);

        bool breakFlag = false;
        switch (day) {
            case 1:
                firstDay();
                break;
            case 2:
                secondDay();
                break;
            case 3:
                thirdDay();
                break;
            case 4:
                fourthDay();
                break;
            case 5:
                fifthDay();
                break;
            case 6:
                sixthSeventhDay();
                break;
            case -1:
                breakFlag = true;
                break;
            default:
                break;
        }

        std::cout << "\n***\n\n";

        return breakFlag;
    });

    return 1;
}
