#pragma once

#include <list>
#include <functional>
#include <ncurses.h>
#include "actions/actions.hpp"

using move_function = std::function<void(Position&)>;

struct BodyParts{
    char symbol;
    Position pos;
    move_function nextMove;
};

class Snake {
    
    public:
        Snake(Position pos);

        void move(move_function moveFunction);

        void grow();

        void update();

    private:
        std::list<BodyParts> body;
        int size=2;

        BodyParts& head();
};