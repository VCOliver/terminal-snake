#include "input/inputHandler.hpp"

InputHandler::InputHandler(Snake snake) {
    this->acceptedCommands = {
        {'w', &moveUpCommand},
        {'a', &moveLeftCommand},
        {'s', &moveDownCommand},
        {'d', &moveRightCommand}
    };
}

void InputHandler::handleInput(char ch) {
    Command* moveCommand = &moveDownCommand; // Default command
    if(acceptedCommands.find(ch) != acceptedCommands.end()) {
        moveCommand = acceptedCommands[ch];
    }

    moveCommand->execute(this->snake);
}