#include "screen/screen.hpp"

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