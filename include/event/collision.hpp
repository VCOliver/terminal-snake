#pragma once

#include "snake/snake.hpp"

enum CollisionType {
    WALL,
    SNAKE,
    FOOD
};

class CollisionObserver {
    public:
        CollisionType checkCollision(Snake snake);
};

class CollisionHandler {
    public:
        virtual void handleCollision(CollisionType type) = 0;
        virtual ~CollisionHandler() = default;
};

class WallCollisionHandler : public CollisionHandler {
    private:
        CollisionType type = WALL;
    public:
        void handleCollision(CollisionType type) override;
};

class SnakeCollisionHandler : public CollisionHandler {
    private:
        CollisionType type = SNAKE;
    public:
        void handleCollision(CollisionType type) override;
};

class FoodCollisionHandler : public CollisionHandler {
    private:
        CollisionType type = FOOD;
    public:
        void handleCollision(CollisionType type) override;
};