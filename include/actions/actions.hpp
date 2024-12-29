#pragma once

#include <ncurses.h>
#include <unordered_map>

struct Position {
    int x;
    int y;
};

using ActionFunction = void (*)(Position&);
using func_map = std::unordered_map<char, ActionFunction>;

// Actions
void moveUp(Position &pos);

void moveLeft(Position &pos); 

void moveDown(Position &pos);

void moveRight(Position &pos);