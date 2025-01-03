#pragma once

#include "snake/snake.hpp"
#include "snake/food.hpp"
#include "event/event.hpp"

class Collision{
    public:
        virtual void handleCollision() = 0;
        virtual void handleCollision(Snake& snake, Food* food) {}
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
        void handleCollision(Snake& snake, Food* food) override;
        void handleCollision() override;
};

enum class CollisionType {
    WALL,
    SELF,
    FOOD
};

using collision_map = std::unordered_map<CollisionType, Collision*>;

class Handler {
    public:
        virtual ~Handler() = default;
};

class CollisionHandler : public Handler {
    Snake& snake;
    Food* food;

    collision_map collisions;

    public:
        CollisionHandler(Snake& snake, Food* food);

        void handleCollision(CollisionType collisionType);
};

class CollisionChecker {
    Snake& snake;
    Food* food;
    CollisionEvent& onCollisionEvent;

    public:
        CollisionChecker(Snake& snake, Food* food, CollisionEvent& onCollisionEvent);

        void checkForCollision();
};