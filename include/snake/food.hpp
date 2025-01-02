#pragma once

#include "actions/position.hpp"

class Food{
    Position pos;

    public:
        Food(Position pos);

        void placeFood();
        Position getPosition();
};

class FoodGenerator {
    PositionMatrix& matrix;

    public:
        FoodGenerator(PositionMatrix& matrix);

        Food generateFood();
};