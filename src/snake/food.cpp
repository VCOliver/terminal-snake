#include "snake/food.hpp"
#include <stdlib.h>

Food::Food(Position pos) : pos(pos) {}

Position Food::getPosition() {
    return pos;
}

FoodGenerator::FoodGenerator(Position screenSize) : screenSize(screenSize) {}

Food FoodGenerator::generateFood() {
    int x = rand() % screenSize.x;
    int y = rand() % screenSize.y;

    return Food({x, y});
}