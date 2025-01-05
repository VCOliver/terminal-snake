#pragma once

#include <set>
#include <vector>

#define FREE_SPACE 0
#define OCCUPIED_SPACE 1

/// @brief Represents a position in the screen
/// @struct Position
/// @param x The x coordinate
/// @param y The y coordinate
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
    int matrixSize;
    std::set<int> availableNumberedPositions;
    Position lastTailPosition;

    void removeNumPosition(Position pos);
    void addNumPosition(Position pos);
    void setOccupied(Position pos);
    void setFree(Position pos);

public:
    PositionMatrix(Position screenSize);
    
    // Checks the Snake's tail position and the head position to update matrix
    void updateMatrix(Snake snake);
    bool isOccupied(Position pos);

    Position getRandomFreePosition();

    void reset();
};