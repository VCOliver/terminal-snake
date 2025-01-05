#include "core/game.hpp"
#include "screen/screen.hpp"

// Define the msleep macro
#define msleep(ms) usleep((ms) * 1000)
#define WAIT_TIME 400

Game::Game(Position start_pos)
    : start_pos(start_pos),
      snake(Snake(start_pos)),
      inputHandler(snake){}

void Game::init(){
    Screen::init(); // Starts screen
    snake.update(); // Places snake on screen

    positionMatrix = new PositionMatrix(Screen::getScreenSize()); // Initializes position matrix
    positionMatrix->updateMatrix(snake); // Updates position matrix with snake's position

    foodGen = new FoodGenerator(*positionMatrix); // Initializes food generator
    food = foodGen->generateFood(); // Generates food
    food->placeFood(); // Places food on screen

    collisionHandler = new CollisionHandler(snake, food); // Initializes collision handler
    onCollisionEvent.addListener(collisionHandler); // Adds collision handler to the event listener
    collisionChecker = new CollisionChecker(snake, food, onCollisionEvent); // Initializes collision checker

    // Refresh the screen to show the characters
    refresh();
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
        positionMatrix->updateMatrix(snake);

        refresh();
        msleep(WAIT_TIME);
    }
}

void Game::close(){
    delete food;
    delete foodGen;
    delete positionMatrix;
    delete collisionHandler;
    delete collisionChecker;
    Screen::close();
}