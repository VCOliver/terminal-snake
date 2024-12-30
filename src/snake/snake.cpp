#include "snake/snake.hpp"

Snake::Snake(Position start_pos) {
    this->body = {
        {'@', start_pos, moveDown}, // Head
        {'#', {start_pos.x, start_pos.y-1}, moveDown}
    };
}

BodyParts& Snake::head() {
    return this->body.front();
}

void Snake::move(move_function moveFunction) {
    auto temp = this->head().nextMove;
    this->head().nextMove(this->head().pos);
    this->head().nextMove = idle;

    for(auto &part : this->body) {
        part.nextMove(part.pos);
    }

    this->head().nextMove = temp;
    
    auto next = moveFunction;
    for(auto &part : this->body) {
        temp = part.nextMove;
        part.nextMove = next;
        next = temp;
    }

}

void Snake::grow() {
    auto &tail = this->body.back();
    BodyParts new_part = {tail.symbol, tail.pos, idle};
    this->body.push_back(new_part);
    this->size++;
}

void Snake::update() {
    for(auto &part : this->body) {
        ::move(part.pos.y, part.pos.x);
        addch(part.symbol);
    }
}