#include <iostream>
#include <unistd.h>
#include "screen/screen.hpp"
#include "snake/snake.hpp"
#include "snake/food.hpp"
#include "input/inputHandler.hpp"
#include "event/event.hpp"
#include "event/collision.hpp"

// Define the msleep macro
#define msleep(ms) usleep((ms) * 1000)
#define WAIT_TIME 400

int main() {
    // Initialize ncurses
    Screen::init();

    // Get the central coordinates of the screen
    const Position start_pos = Screen::getCenter();
    Snake snake = Snake(start_pos);
    snake.update();

    PositionMatrix positionMatrix = PositionMatrix(Screen::getScreenSize());
    positionMatrix.updateMatrix(snake);

    FoodGenerator foodGen = FoodGenerator(positionMatrix);

    Food* food = foodGen.generateFood();

    CollisionHandler collisionHandler = CollisionHandler(snake, food);
    CollisionEvent onCollisionEvent;

    onCollisionEvent.addListener(&collisionHandler);

    CollisionChecker collisionChecker = CollisionChecker(snake, food, onCollisionEvent);

    // Refresh the screen to show the character
    refresh();

    InputHandler inputHandler = InputHandler(snake);

    while(true) {

        // Get user input
        char ch = getch();
        inputHandler.handleInput(ch);

        // For debugging purposes
        if(ch == 'g') {
            snake.grow();
        }

        // Flush input buffer to discard any previous characters
        flushinp();

        // Clears screen
        clear();

        if(food == nullptr) {
            food = foodGen.generateFood();
        }
        food->placeFood();
        
        collisionChecker.checkForCollision();
        
        snake.update();
        positionMatrix.updateMatrix(snake);

        refresh();
        msleep(WAIT_TIME);
    }
    // End ncurses mode
    Screen::close();

    return 0;
}