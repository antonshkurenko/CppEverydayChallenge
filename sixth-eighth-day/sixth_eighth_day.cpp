//
// Created by cullycross on 11/30/15.
// Follow me (@tonyshkurenko)
//

#include <iostream>
#include <string.h>
#include "sixth_eighth_day.h"
#include "../libs/rlutil.h"
#include "../commons/utils.h"

static const int X = 1;
static const int O = -1;
static const int SPACE = -0;

static const int SIZE = 3;

static std::string const ROW = "row";
static std::string const COL = "col";
static std::string const DIAG = "diag";
static std::string const ANTI_DIAG = "antidiag";
int deck[SIZE][SIZE];

int row[SIZE], col[SIZE], diag, antiDiag;

bool player;

Point selected;

void init() {
    for (int i = 0; i < SIZE; i++) {
        row[i] = 0;
        col[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            deck[i][j] = SPACE;
        }
    }
    diag = antiDiag = 0;

    rlutil::hidecursor();
    player = utils::random(0, 2) > 0;
}

void draw() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            rlutil::locate(i + 1, j + 1);
            if (i == selected.x && j == selected.y) {
                rlutil::setColor(rlutil::RED);
            } else {
                rlutil::setColor(rlutil::GREY);
            }
            if (deck[i][j] == SPACE) {
                rlutil::setChar('.');
            } else if (deck[i][j] == X) {
                rlutil::setChar('X');
            } else if (deck[i][j] == O) {
                rlutil::setChar('O');
            }
        }
        std::cout << "\n";
    }
    rlutil::setColor(rlutil::GREY);
    std::cout<<"\nControls: wasd, place X : SPACE";
}

void invalidate() {
    rlutil::cls();
    draw();
}

void step(int x, int y) {
    int inc = player ? 1 : -1;

    col[x] += inc;
    row[y] += inc;

    if (x == y) {
        diag += inc;
    }

    if (y == SIZE - x - 1) {
        antiDiag += inc;
    }

}

std::pair<std::string, int>* getResultPair(std::string prefix, int index) {

    return new std::pair<std::string, int>(prefix, index);
}

std::pair<std::string, int>* checkSequence(int x, int y, int length) {

    if (row[y] == length || row[y] == -length) {
        return getResultPair(ROW, y);
    }
    if (col[x] == length || col[x] == -length) {
        return getResultPair(COL, x);
    }

    if (diag == length || diag == -length) {
        return getResultPair(DIAG, 0);
    }
    if (antiDiag == length || antiDiag == -length) {
        return getResultPair(ANTI_DIAG, 0);
    }

    return NULL;
}

bool playersStep() {

    utils::whileIncorrectExecute([]() {
        bool breakFlag = false;
        switch (getch()) {
            case 'w':
                selected.y == 0 ? selected.y = SIZE - 1 : selected.y--;
                break;
            case 's':
                selected.y == SIZE - 1 ? selected.y = 0 : selected.y++;
                break;
            case 'd':
                selected.x == SIZE - 1 ? selected.x = 0 : selected.x++;
                break;
            case 'a':
                selected.x == 0 ? selected.x = SIZE - 1 : selected.x--;
                break;
            case ' ':
                if (deck[selected.x][selected.y] == SPACE) {
                    deck[selected.x][selected.y] = X;
                    step(selected.x, selected.y);
                    breakFlag = true;
                }
                break;
            default:
                break;
        }

        invalidate();
        return breakFlag;
    });

    const std::pair<std::string, int>* win = checkSequence(selected.x, selected.y, SIZE);
    if (win != NULL) {
        const std::string type = win->first;
        //const int num = win->second;
        if (type == ROW) {
            // color the row with number
        } else if (type == COL) {
            // color the col with number
        } else if (type == DIAG) {
            // color the diag
        } else if (type == ANTI_DIAG) {
            // color the anti_diag
        }
        return true;
    } else {
        return false;
    }
}

Point* getSpaceCoords() {
    Point* point = nullptr;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (deck[i][j] == SPACE) {
                const int flag = utils::random(0, 3); // for 33%
                if (point == nullptr || !flag) {
                    point = new Point{i, j};
                }
            }
        }
    }
    return point; // if it's null -> no free space on the deck
}

Point getStepPoint() {
    for (int i = 0; i < SIZE; i++) {
        if (abs(row[i]) == SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                if (deck[j][i] == SPACE) {
                    return Point{j, i};
                }
            }
        }
        if (abs(col[i]) == SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                if (deck[i][j] == SPACE) {
                    return Point{i, j};
                }
            }
        }
    }

    if (abs(diag) == SIZE - 1) {
        for (int i = 0, j = 0; i < SIZE && j < SIZE; i++, j++) {
            if (deck[i][j] == SPACE) {
                return Point{i, j};
            }
        }
    }
    if (abs(antiDiag) == SIZE - 1) {
        for (int i = 0, j = SIZE - 1; i < SIZE && j >= 0; i++, j--) {
            if (deck[i][j] == SPACE) {
                return Point{i, j};
            }
        }
    }

    return *getSpaceCoords();
}

bool computersStep() {

    const Point stepPoint = getStepPoint();

    deck[stepPoint.x][stepPoint.y] = O;
    step(stepPoint.x, stepPoint.y);

    invalidate();
    std::pair<std::string, int>* win = checkSequence(stepPoint.x, stepPoint.y, SIZE);
    if (win != NULL) {
        const std::string type = win->first;
        //const int num = win->second;
        if (type == ROW) {
            // color the row with number
        } else if (type == COL) {
            // color the col with number
        } else if (type == DIAG) {
            // color the diag
        } else if (type == ANTI_DIAG) {
            // color the anti_diag
        }
        return true;
    } else {
        return false;
    }
}

void start() {
    rlutil::anykey("Press any key to continue...\n");
    init();

    utils::whileIncorrectExecute([]() {
        bool win;
        if (player) {
            win = playersStep();
        } else {
            win = computersStep();
        }

        if (win) {
            if (player) {
                std::cout << "\nPlayer won!";
            } else {
                std::cout << "\nComputer won!";
            }
            return true;
        } else {

            if (getSpaceCoords() == nullptr) {
                std::cout << "\nDraw!";
                return true;
            }

            player = !player; // toggle
            return false;
        }
    });

    rlutil::setColor(rlutil::GREY);
    rlutil::anykey();
}

void sixthEighthDay() {

    std::cout << "It's sixth-eighth day excersize.\nYou're welcome!";
    start();
}
