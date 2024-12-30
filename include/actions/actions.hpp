#pragma once

#include <ncurses.h>
#include <unordered_map>
#include "position.hpp"

using ActionFunction = void (*)(Position&);

// Actions
void moveUp(Position &pos); // Start movement

void moveLeft(Position &pos); 

void moveDown(Position &pos);

void moveRight(Position &pos);

void idle(Position &pos);

