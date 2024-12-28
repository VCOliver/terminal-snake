#pragma once

#include <ncurses.h>

struct Position {
    int x;
    int y;
};

using ActionFunction = void (*)(Position&);

// Actions
void moveUp(Position &pos);

void moveLeft(Position &pos); 

void moveDown(Position &pos);

void moveRight(Position &pos);