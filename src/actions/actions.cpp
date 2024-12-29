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

void idle(Position &pos) {
    return;
}

func_map acceptedMoves = {
    {'w', moveUp},
    {'a', moveLeft},
    {'s', moveDown},
    {'d', moveRight}
};