#include "event/collision.hpp"
#include "screen/screen.hpp"
#include "snake/snake.hpp"

CollisionType CollisionObserver::checkCollision(Snake snake) {
    auto head_pos = snake.getHeadPosition();
    auto screenSize = Screen::getScreenSize();
    if(head_pos.x < 0 || head_pos.x > screenSize.x || head_pos.y < 0 || head_pos.y > screenSize.y) {
        return WALL;
    }
    return NONE;
}

void WallCollisionHandler::handleCollision(CollisionType type) {
    if(type == WALL) {
        Screen::clear();
        nodelay(stdscr, FALSE); // Wait for user input
        printw("Game Over! You hit the wall!\n");
        printw("Press any key to exit...");
        refresh();
        getch();
        Screen::close();
    }
}