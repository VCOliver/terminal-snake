#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "snake/snake.hpp"
#include "actions/actions.hpp"

// Define the msleep macro
#define msleep(ms) usleep((ms) * 1000)
#define WAIT_TIME 400

void init() {
    initscr(); 
    noecho(); // Do not display the input
    nodelay(stdscr, TRUE); // Do not wait for user input
    curs_set(0); // Do not display the cursor
}

Position getCenter() {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    return {cols / 2, rows / 2};
}

int main() {
    // Initialize ncurses
    init();
    // Get the central coordinates of the screen
    const Position start_pos = getCenter();
    Snake snake = Snake(start_pos);
    snake.update();

    // Refresh the screen to show the character
    refresh();

    ActionFunction moveFunction = moveDown;
    while(true) {

        // Get user input
        char ch = getch(); ///! Program dying here
        if(acceptedMoves.find(ch) != acceptedMoves.end()) {
            moveFunction = acceptedMoves[ch];
        }


        // Flush input buffer to discard any previous characters
        flushinp();

        // Clears screen
        clear();

        if(ch == 'g') {
            snake.grow();
        }
        snake.move(moveFunction);
        snake.update();
        refresh();
        msleep(WAIT_TIME);
    }
    // End ncurses mode
    endwin();

    return 0;
}