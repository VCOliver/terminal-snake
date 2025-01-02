#include "event/collision.hpp"
#include "screen/screen.hpp"

CollisionHandler::CollisionHandler(Snake snake, Food* food) : snake(snake), food(food) {
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

void FoodCollision::handleCollision(Snake& snake, Food* food) {
    snake.grow();
    delete &food;
    food = nullptr;
}

CollisionChecker::CollisionChecker(Snake& snake, Food* food, CollisionEvent& onCollisionEvent) : snake(snake), food(food), onCollisionEvent(onCollisionEvent) {}

void CollisionChecker::checkForCollision() {
    auto head = snake.getHeadPosition();
    auto screenSize = Screen::getScreenSize();

    if(head.x < 0 || head.x > screenSize.x || head.y < 0 || head.y > screenSize.y) {
        onCollisionEvent.trigger(CollisionType::WALL);
    }

    if(snake.isSelfColliding()) {
        onCollisionEvent.trigger(CollisionType::SELF);
    }
    if(snake.getHeadPosition() == food->getPosition()) {
        onCollisionEvent.trigger(CollisionType::FOOD);
    }
}