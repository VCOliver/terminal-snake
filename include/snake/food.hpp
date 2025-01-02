#pragma once

#include "actions/position.hpp"

class Food{
    Position pos;

    public:
        Food(Position pos);

        Position getPosition();
};

class FoodGenerator {
    Position screenSize;

    public:
        FoodGenerator(Position screenSize);

        Food generateFood();
};