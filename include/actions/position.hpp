#pragma once

#include <vector>

#define FREE_SPACE 0
#define OCCUPIED_SPACE 1


struct Position {
    int x;
    int y;

    bool operator==(const Position& other) const;
};

class Snake;

class PositionMatrix {
    using Matrix = std::vector<std::vector<int>>;

    Position screenSize;
    Matrix matrix;
    Position lastTailPosition;

    void setOccupied(Position pos);
    void setFree(Position pos);

public:
    PositionMatrix(Position screenSize);
    
    // Checks the Snake's tail position and the head position to update matrix
    void updateMatrix(Snake snake);
    bool isOccupied(Position pos);
    void reset();
};