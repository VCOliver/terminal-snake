#include <stdlib.h>
#include <ncurses.h>
#include "screen/screen.hpp"

#include "snake/food.hpp"

Food::Food(Position pos) : pos(pos) {}

Position Food::getPosition() {
    return this->pos;
}

void Food::placeFood() {
    Position pos = this->getPosition();
    ::move(pos.y, pos.x);
    Screen::addchat('O', pos, true);
}

FoodGenerator::FoodGenerator(PositionMatrix& matrix) : matrix(matrix) {}

Food* FoodGenerator::generateFood() {
    Position position = matrix.getRandomFreePosition();

    return new Food(position);
}