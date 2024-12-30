#pragma once

#include "snake/snake.hpp"
#include "actions/actions.hpp"
#include "commands/commands.hpp"

using command_map = std::unordered_map<char, Command*>;

class InputHandler {
    public:
        InputHandler(Snake snake);

        void handleInput(char ch);

    private:
        Snake snake;

        command_map acceptedCommands;

        MoveUpCommand moveUpCommand;
        MoveLeftCommand moveLeftCommand;
        MoveDownCommand moveDownCommand;
        MoveRightCommand moveRightCommand;
};


