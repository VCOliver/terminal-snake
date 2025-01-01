#include "event/collision.hpp"
#include "screen/screen.hpp"
#include "snake/snake.hpp"

CollisionType CollisionObserver::checkCollision(Snake snake) {
    auto head_pos = snake.getHeadPosition();
    auto screenSize = Screen::getScreenSize();
    if(head_pos.x < 0 || head_pos.x > screenSize.x || head_pos.y < 0 || head_pos.y > screenSize.y) {
        return WALL;
    }
    return SNAKE;
}