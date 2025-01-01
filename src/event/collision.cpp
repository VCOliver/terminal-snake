#include "event/collision.hpp"
#include "screen/screen.hpp"

CollisionHandler::CollisionHandler(Snake snake) : snake(snake) {
    this->collisionHandlers = {
        {CollisionType::WALL, new WallCollision()},
        {CollisionType::SELF, new SelfCollision()},
        {CollisionType::FOOD, new FoodCollision()}
    };
}

void CollisionHandler::handleCollision(CollisionType collisionType) {
    collisionHandlers[collisionType]->handleCollision();
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