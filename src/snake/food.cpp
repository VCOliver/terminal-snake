#include <stdlib.h>
#include <ncurses.h>
#include "snake/food.hpp"

Food::Food(Position pos) : pos(pos) {}

Position Food::getPosition() {
    return pos;
}

void Food::placeFood() {
    ::move(pos.y, pos.x);
    addch('$');
}

FoodGenerator::FoodGenerator(PositionMatrix& matrix) : matrix(matrix) {}

Food FoodGenerator::generateFood() {
    Position position = matrix.getRandomFreePosition();

    return Food(position);
}