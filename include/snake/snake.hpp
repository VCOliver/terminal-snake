#pragma once

#include <list>
#include <functional>
#include <ncurses.h>
#include "actions/actions.hpp"

struct BodyParts{
    char symbol;
    Position pos;
    ActionFunction nextMove;
};

class Snake {
    
    public:
        Snake(Position pos);

        void move(ActionFunction moveFunction);

        void grow();

        void update();

        Position getHeadPosition();

        Position getTailPosition();

        bool isSelfColliding();

    private:
        std::list<BodyParts> body;
        int size=2;

        BodyParts& head();

        void prepNextMove(ActionFunction moveFunction, ActionFunction prevHeadMove);
};