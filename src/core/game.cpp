#include "core/game.hpp"
#include "screen/screen.hpp"
#include "snake/snake.hpp"
#include "snake/food.hpp"
#include "actions/position.hpp"
#include "event/collision.hpp"
#include "event/event.hpp"
#include "input/inputHandler.hpp"

// Define the msleep macro
#define msleep(ms) usleep((ms) * 1000)
#define WAIT_TIME 400

void Game::init(){
    this->start_pos = Screen::getCenter();
    this->snake = Snake(start_pos);
    snake.update();

    positionMatrix = PositionMatrix(Screen::getScreenSize());
    positionMatrix.updateMatrix(snake);

    foodGen = new FoodGenerator(positionMatrix);
    food = foodGen->generateFood();

    collisionHandler = new CollisionHandler(snake, food);
    onCollisionEvent.addListener(collisionHandler);
    collisionChecker = new CollisionChecker(snake, food, onCollisionEvent);

    // Refresh the screen to show the character
    refresh();

    InputHandler inputHandler = InputHandler(snake);
}

void Game::run(){
    while(true) {
        // Get user input
        char ch = getch();
        inputHandler.handleInput(ch);

        // Flush input buffer to discard any previous characters
        flushinp();

        // Clears screen
        Screen::clear();

        if(food == nullptr) {
            food = foodGen->generateFood();
        }
        food->placeFood();
        
        if(collisionChecker->checkForCollision()) break;
        
        snake.update();
        positionMatrix.updateMatrix(snake);

        refresh();
        msleep(WAIT_TIME);
    }
}

void Game::close(){
    Screen::close();
}