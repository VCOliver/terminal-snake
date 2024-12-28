#include <iostream>
#include <unordered_map>
#include <ncurses.h>
#include <unistd.h>
#include "actions/actions.hpp"

using hash_map = std::unordered_map<char, ActionFunction>;


int main() {
    // Initialize ncurses
    initscr();
	noecho();
    nodelay(stdscr, TRUE);
    // Get the number of rows and columns
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    // Calculate the center position
    int center_row = rows / 2;
    int center_col = cols / 2;
    Position pos = {center_col, center_row};
    // Move the cursor to the center position
    move(pos.y, pos.x);
    // Print a # character at the center
    addch('#');
    // Refresh the screen to show the character
    refresh();

    hash_map acceptedMoves = {
        {'w', moveUp},
        {'a', moveLeft},
        {'s', moveDown},
        {'d', moveRight}
    };

    auto moveFunction = moveDown;
    while(true) {
        // Wait for user input
        char ch = getch();
        if(acceptedMoves.find(ch) != acceptedMoves.end()) {
            moveFunction = acceptedMoves[ch];
        }

        moveFunction(pos);
        move(pos.y, pos.x);
        addch('#');
        sleep(1);
    }
    // End ncurses mode
    endwin();

    return 0;
}