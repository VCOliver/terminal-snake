#include "actions/actions.hpp"

// Actions
void moveUp(Position &pos) {
    pos.y--;
}

void moveLeft(Position &pos) {
    pos.x--;
}

void moveDown(Position &pos) {
    pos.y++;
}

void moveRight(Position &pos) {
    pos.x++;
}