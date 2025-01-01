#pragma once

#include "snake/snake.hpp"

class Collision{
    public:
        virtual void handleCollision() = 0;
        virtual ~Collision() = default;
};

class WallCollision : public Collision {
    public:
        void handleCollision() override;
};

class SelfCollision : public Collision {
    public:
        void handleCollision() override;
};

class FoodCollision : public Collision {
    public:
        void handleCollision() override;
};

enum class CollisionType {
    WALL,
    SELF,
    FOOD
};

using collision_map = std::unordered_map<CollisionType, Collision*>;

class CollisionHandler {
    Snake snake;

    collision_map collisionHandlers;

    public:
        CollisionHandler(Snake snake);

        void handleCollision(CollisionType collisionType);
};