#include "event/collision.hpp"
#include "screen/screen.hpp"

CollisionHandler::CollisionHandler(Snake& snake, Food*& food) : snake(snake), food(food) {
    this->collisions = {
        {CollisionType::WALL, new WallCollision()},
        {CollisionType::SELF, new SelfCollision()},
        {CollisionType::FOOD, new FoodCollision()}
    };
}

void CollisionHandler::handleCollision(CollisionType collisionType) {
    if(collisionType == CollisionType::FOOD) {
        collisions[collisionType]->handleCollision(snake, food);
        return;
    }
    collisions[collisionType]->handleCollision();
}

void WallCollision::handleCollision() {
    Screen::gameOver();
}

void SelfCollision::handleCollision() {
    Screen::gameOver();
}

void FoodCollision::handleCollision() {
    return; // Does nothing for now
}

void FoodCollision::handleCollision(Snake& snake, Food*& food) {
    snake.grow();
    delete food;
    food = nullptr;
}

CollisionChecker::CollisionChecker(Snake& snake, Food*& food, CollisionEvent& onCollisionEvent) : snake(snake), food(food), onCollisionEvent(onCollisionEvent) {}

bool CollisionChecker::checkForCollision() {
    auto head = snake.getHeadPosition();
    auto screenSize = Screen::getScreenSize();
    auto x_max = screenSize.x-1;
    auto y_max = screenSize.y-1;
    bool collision = false;

    if(head.x < 0 || head.x > x_max || head.y < 0 || head.y > y_max) {
        onCollisionEvent.trigger(CollisionType::WALL);
        collision = true;
    }

    if(snake.isSelfColliding()) {
        onCollisionEvent.trigger(CollisionType::SELF);
        collision = true;
    }
    if(snake.getHeadPosition() == food->getPosition()) {
        onCollisionEvent.trigger(CollisionType::FOOD);
        collision = false;
    }

    return collision;
}