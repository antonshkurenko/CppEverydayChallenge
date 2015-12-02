//
// Created by cullycross on 11/30/15.
// Follow me (@tonyshkurenko)
//

#include <iostream>
#include <string.h>
#include "sixth_seventh_day.h"
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
        for (int j = 0; j < SIZE; j++) {
            deck[i][j] = SPACE;
        }
    }

    rlutil::hidecursor();
    player = utils::random(0, 2);
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
                rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
                rlutil::setChar('.');
            } else if (deck[i][j] == X) {
                rlutil::setChar('X');
            } else if (deck[i][j] == O) {
                rlutil::setChar('O');
            }
        }
        std::cout << "\n";
    }
}

void invalidate() {
    rlutil::cls();
    draw();
}

void step(int x, int y, int p) {
    if (p == 1) {
        row[y]++;
        col[x]++;

        if (x == y)
            diag++;

        if (y == SIZE - x)
            antiDiag++;
    } else {
        col[x]--;
        row[y]--;
        if (x == y)
            diag--;

        if (y == SIZE - x)
            antiDiag--;
    }
}

std::pair<std::string, int>* createString(std::string prefix, int index) {

    return new std::pair<std::string, int>(prefix, index);
}

std::pair<std::string, int>* checkSequence(int x, int y, int length) {

    if (row[y] == length || row[y] == -length) {
        return createString(ROW, y);
    }
    if (col[x] == length || col[x] == -length) {
        return createString(COL, x);
    }

    if (diag == length || diag == -length) {
        return createString(DIAG, 0);
    }
    if (antiDiag == length || antiDiag == -length) {
        return createString(ANTI_DIAG, 0);
    }

    return NULL;
}

void playersStep() {

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
                    step(selected.x, selected.y, X);
                    breakFlag = true;
                }
                break;
            default:
                break;
        }

        const std::pair<std::string, int>* win = checkSequence(selected.x, selected.y, SIZE);
        if (win != NULL) {
            const std::string type = win->first;
            const int num = win->second;
            if (type == ROW) {

            } else if (type == COL) {

            } else if (type == DIAG) {

            } else if (type == ANTI_DIAG) {

            }
        }

        invalidate();
        return breakFlag;
    });
}

Point getStepPoint() {
    // todo(cullycross), 12/2/15: seems like here is a bug, with rows->cols
    for (int i = 0; i < SIZE; i++) {
        if (abs(row[i]) == SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                if (deck[i][j] == SPACE) {
                    return Point{i, j};
                }
            }
        }
        if (abs(col[i]) == SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                if (deck[j][i] == SPACE) {
                    return Point{j, i};
                }
            }
        }
    }

    if (abs(diag) == SIZE - 1) {
        for (int i = 0, j = 0; i < SIZE && j < SIZE; i++, j++) {
            if (deck[i][j] == SPACE) {
                return Point{j, i};
            }
        }
    }
    if (abs(antiDiag) == SIZE - 1) {
        for (int i = 0, j = 0; i < SIZE && j < SIZE; i++, j++) {
            if (deck[i][j] == SPACE) {
                return Point{j, i};
            }
        }
    }

    Point* point = nullptr;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(deck[i][j] == SPACE) {

                const int flag = utils::random(0, 3); // for 33%

                if (point == nullptr || !flag) {
                    point = new Point{i, j};
                }
            }
        }
    }
    return *point; // todo(cullycross), 12/2/15: if it's null -> no free space on the deck
}

void computersStep() {

    const Point step = getStepPoint();
    deck[step.x][step.y] = O;

    std::pair<std::string, int>* win = checkSequence(selected.x, selected.y, SIZE);
    if (win != NULL) {
        const std::string type = win->first;
        const int num = win->second;
        if (type == ROW) {

        } else if (type == COL) {

        } else if (type == DIAG) {

        } else if (type == ANTI_DIAG) {

        }
    }

}

void start() {
    rlutil::anykey("Press any key to continue...\n");
    init();

    utils::whileIncorrectExecute([]() {
        if (player) {
            playersStep();
        } else {
            computersStep();
        }
        player = !player; // toggle
        return false;
    });
}

void sixthSeventhDay() {

    std::cout << "It's fourth day excersize.\nYou're welcome!";
    start();
}
