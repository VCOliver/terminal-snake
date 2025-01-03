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
    mvprintw(0, 0, "Game Over!");
    printw("Press any key to exit...");
    refresh();
    nodelay(stdscr, FALSE);
    getch();
}