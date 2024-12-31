#include "input/inputHandler.hpp"

InputHandler::InputHandler(Snake& snake) : snake(snake) {
    this->acceptedCommands = {
        {'w', &moveUpCommand},
        {'a', &moveLeftCommand},
        {'s', &moveDownCommand},
        {'d', &moveRightCommand}
    };

    this->moveCommand = &moveDownCommand;
}

void InputHandler::handleInput(char ch) {
    if(acceptedCommands.find(ch) != acceptedCommands.end()) {
        moveCommand = acceptedCommands[ch];
    }

    moveCommand->execute(this->snake);
}