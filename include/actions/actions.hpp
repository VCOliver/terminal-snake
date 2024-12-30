#pragma once

#include <ncurses.h>
#include <unordered_map>
#include "position.hpp"

using ActionFunction = void (*)(Position&);
using func_map = std::unordered_map<char, ActionFunction>;

// Actions
void moveUp(Position &pos);

void moveLeft(Position &pos); 

void moveDown(Position &pos);

void moveRight(Position &pos);

void idle(Position &pos);

extern func_map acceptedMoves;

