#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "actions/actions.hpp"
#include "snake/snake.hpp"
#include "utils/moves.hpp"

// Define the msleep macro
#define msleep(ms) usleep((ms) * 1000)

void init() {
    initscr();
    noecho();
    //nodelay(stdscr, TRUE);
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

    auto moveFunction = moveDown;
    while(true) {

        // Get user input
        char ch = getch();
        if(acceptedMoves.find(ch) != acceptedMoves.end()) {
            moveFunction = acceptedMoves[ch];

        }

        // Flush input buffer to discard any previous characters
        flushinp();

        snake.move(moveFunction);
        snake.update();
        refresh();
        msleep(500);
    }
    // End ncurses mode
    endwin();

    return 0;
}