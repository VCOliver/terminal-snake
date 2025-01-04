#pragma once

#include <iostream>
#include <unistd.h>
#include <ncurses.h>

#include "actions/position.hpp"
#include "snake/snake.hpp"
#include "snake/food.hpp"
#include "event/collision.hpp"
#include "event/event.hpp"
#include "input/inputHandler.hpp"

class Game {
    Position start_pos;
    Snake snake;

    PositionMatrix* positionMatrix;

    FoodGenerator* foodGen;

    Food* food;

    CollisionHandler* collisionHandler;
    CollisionEvent onCollisionEvent;

    CollisionChecker* collisionChecker;

    InputHandler inputHandler;

public:
    Game(Position start_pos = {40, 12});
    void init();
    void run();
    void close();
};