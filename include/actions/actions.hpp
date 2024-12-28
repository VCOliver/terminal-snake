#pragma once

#include <ncurses.h>

struct Position {
    int x;
    int y;
};

// Actions
void moveUp(Position &pos);

void moveLeft(Position &pos); 

void moveDown(Position &pos);

void moveRight(Position &pos);