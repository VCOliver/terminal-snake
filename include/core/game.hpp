#pragma once

#include <iostream>
#include <unistd.h>
#include <ncurses.h>

struct Position;
class Snake;
class PositionMatrix;
class FoodGenerator;
class Food;
class CollisionHandler;
class CollisionEvent;
class CollisionChecker;
class InputHandler;

class Game {
    Position start_pos;
    Snake snake;

    PositionMatrix positionMatrix;

    FoodGenerator* foodGen;

    Food* food;

    CollisionHandler* collisionHandler;
    CollisionEvent onCollisionEvent;

    CollisionChecker* collisionChecker;

    InputHandler inputHandler;

public:
    void init();
    void run();
    void close();
};