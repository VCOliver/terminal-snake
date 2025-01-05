#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <wchar.h>

#include "snake/food.hpp"

Food::Food(Position pos) : pos(pos) {}

Position Food::getPosition() {
    return this->pos;
}

void Food::placeFood() {
    Position pos = this->getPosition();
    ::move(pos.y, pos.x);
    attron(COLOR_PAIR(1) | A_ITALIC | A_BOLD);
    addch('O');
    attroff(COLOR_PAIR(1) | A_ITALIC | A_BOLD);
}

FoodGenerator::FoodGenerator(PositionMatrix& matrix) : matrix(matrix) {}

Food* FoodGenerator::generateFood() {
    Position position = matrix.getRandomFreePosition();

    return new Food(position);
}