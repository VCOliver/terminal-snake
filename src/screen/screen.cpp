#include "screen/screen.hpp"
#include <ncurses.h>
#include <cstdlib>

void Screen::init() {
    initscr(); 
    noecho(); // Do not display the input
    nodelay(stdscr, TRUE); // Do not wait for user input
    curs_set(0); // Do not display the cursor
}

void Screen::clear() {
    ::clear();
}

void Screen::close() {
    curs_set(1);
    endwin();
}

Position Screen::getCenter() {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    return {cols / 2, rows / 2};
}

Position Screen::getScreenSize() {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    return {cols, rows};
}

void Screen::gameOver() {
    clear();
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    // Calculate start position for centered text
    int artHeight = gameOverArt.size();
    int artWidth = gameOverArt[0].size();
    int startY = (rows - artHeight) / 2;
    int startX = (cols - artWidth) / 2;

    // Print ASCII art
    for (size_t i = 0; i < gameOverArt.size(); ++i) {
        mvprintw(startY + i, startX, "%s", gameOverArt[i].c_str());
    }

    startY += artHeight + 2; // Move the cursor down
    mvprintw(startY, cols/2 -10, "Press any key to exit...");

    refresh();
    nodelay(stdscr, FALSE);
    getch();
}