#include "commands/commands.hpp"

void MoveUpCommand::execute(Snake& snake) {
    snake.move(moveUp);
}

void MoveDownCommand::execute(Snake& snake) {
    snake.move(moveDown);
}

void MoveLeftCommand::execute(Snake& snake) {
    snake.move(moveLeft);
}

void MoveRightCommand::execute(Snake& snake) {
    snake.move(moveRight);
}