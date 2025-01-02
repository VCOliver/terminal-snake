#include "actions/position.hpp"
#include "snake/snake.hpp"

bool Position::operator==(const Position& other) const {
    return this->x == other.x && this->y == other.y;
}

PositionMatrix::PositionMatrix(Position screenSize) : screenSize(screenSize) {
    using namespace std;
    int rows = screenSize.y;
    int cols = screenSize.x;
    this->matrix = vector<vector<int>>(rows, vector<int>(cols, FREE_SPACE));

    lastTailPosition = {screenSize.x/2, screenSize.y/2};
}

void PositionMatrix::setOccupied(Position pos) {
    this->matrix[pos.y][pos.x] = OCCUPIED_SPACE;
}

void PositionMatrix::setFree(Position pos) {
    this->matrix[pos.y][pos.x] = FREE_SPACE;
}

void PositionMatrix::updateMatrix(Snake snake) {
    auto head_pos = snake.getHeadPosition();
    auto tail_pos = snake.getTailPosition();

    setFree(lastTailPosition);

    setOccupied(head_pos);
    lastTailPosition = tail_pos;
}

bool PositionMatrix::isOccupied(Position pos) {
    return this->matrix[pos.y][pos.x] == OCCUPIED_SPACE;
}

void PositionMatrix::reset() {
    for (auto& row : this->matrix) {
        for (int& val : row) {
            val = FREE_SPACE;
        }
    }
}