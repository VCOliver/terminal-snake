#include "event/collision.hpp"
#include "screen/screen.hpp"

CollisionHandler::CollisionHandler(Snake snake) : snake(snake) {
    this->collisions = {
        {CollisionType::WALL, new WallCollision()},
        {CollisionType::SELF, new SelfCollision()},
        {CollisionType::FOOD, new FoodCollision()}
    };
}

void CollisionHandler::handleCollision(CollisionType collisionType) {
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

CollisionChecker::CollisionChecker(Snake& snake, CollisionEvent& onCollisionEvent) : snake(snake), onCollisionEvent(onCollisionEvent) {}

void CollisionChecker::checkForCollision() {
    auto head = snake.getHeadPosition();
    auto screenSize = Screen::getScreenSize();

    if(head.x < 0 || head.x > screenSize.x || head.y < 0 || head.y > screenSize.y) {
        onCollisionEvent.trigger(CollisionType::WALL);
    }

    if(snake.isSelfColliding()) {
        onCollisionEvent.trigger(CollisionType::SELF);
    }
}