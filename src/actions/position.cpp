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
    matrixSize = rows * cols;
    for (int i = 0; i < matrixSize; i++) {
        availableNumberedPositions.insert(i);
    }
    lastTailPosition = {screenSize.x/2, screenSize.y/2};
}

void PositionMatrix::removeNumPosition(Position pos) {
    int nthPosition = pos.y * screenSize.x + pos.x;
    auto it = availableNumberedPositions.begin();
    std::advance(it, nthPosition);
    availableNumberedPositions.erase(it);
}

void PositionMatrix::addNumPosition(Position pos) {
    int value = pos.y * screenSize.x + pos.x;
    availableNumberedPositions.insert(value);
}

void PositionMatrix::setOccupied(Position pos) {
    this->matrix[pos.y][pos.x] = OCCUPIED_SPACE;
    removeNumPosition(pos);
    
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

Position PositionMatrix::getRandomFreePosition() {
    int randomIndex = rand() % availableNumberedPositions.size();
    auto it = availableNumberedPositions.begin();
    std::advance(it, randomIndex);
    int value = *it;
    int x = value % screenSize.x;
    int y = value / screenSize.x;
    return {x, y};
}

void PositionMatrix::reset() {
    for (auto& row : this->matrix) {
        for (int& val : row) {
            val = FREE_SPACE;
        }
    }
    availableNumberedPositions.clear();
    for (int i = 0; i < matrixSize; i++) {
        availableNumberedPositions.insert(i);
    }
}