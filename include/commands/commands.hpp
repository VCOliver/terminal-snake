#pragma once

#include "snake/snake.hpp"

class Command {
    public:
        virtual void execute(Snake& snake) = 0;
        ~Command() {}
};

class MoveUpCommand : public Command {
    public:
        void execute(Snake& snake) override;
};

class MoveDownCommand : public Command {
    public:
        void execute(Snake& snake) override;
};

class MoveLeftCommand : public Command {
    public:
        void execute(Snake& snake) override;
};

class MoveRightCommand : public Command {
    public:
        void execute(Snake& snake) override;
};