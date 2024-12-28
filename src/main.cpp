#include <iostream>
#include <unordered_map>
#include <ncurses.h>

using ActionFunction = void (*)();
using hash_map = std::unordered_map<char, ActionFunction>;

// Actions
void moveUp() {
    printw("Moving up\n");
}

void moveLeft() {
    printw("Moving left\n");
}

void moveDown() {
    printw("Moving down\n");
}

void moveRight() {
    printw("Moving right\n");
}

int main() {
    // Initialize ncurses
    initscr();
	noecho();
    // Get the number of rows and columns
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    // Calculate the center position
    int center_row = rows / 2;
    int center_col = cols / 2;
    // Move the cursor to the center position
    move(center_row, center_col);
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

    while(true) {
        // Wait for user input
        char ch = getch();
        if(acceptedMoves.find(ch) != acceptedMoves.end()) {
            printw("You pressed %c\n", ch);
            auto moveFunction = acceptedMoves[ch];
            moveFunction();
        }
    }
    // End ncurses mode
    endwin();

    return 0;
}