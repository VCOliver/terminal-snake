#include "screen/screen.hpp"
#include <ncurses.h>
#include <cstdlib>

void Screen::init() {
    setlocale(LC_ALL, ""); // Enable UTF-8 support
    initscr(); 
    noecho(); // Do not display the input
    nodelay(stdscr, TRUE); // Do not wait for user input
    curs_set(0); // Do not display the cursor
    start_color(); // Initialize color functionality
    init_pair(1, COLOR_RED, COLOR_BLACK); // Define color pair 1 as red text on black background
}

void Screen::addchat(char ch, Position pos, bool food){
    if(food) attron(COLOR_PAIR(1) | A_ITALIC | A_BOLD);
    mvaddch(pos.y, pos.x, ch);
    if(food) attroff(COLOR_PAIR(1) | A_ITALIC | A_BOLD);
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
    std::string exitMessage = "Press any key to exit...";
    attron(A_BLINK);
    mvprintw(startY, cols/2 - exitMessage.size()/2, exitMessage.c_str());
    attroff(A_BLINK);

    refresh();
    nodelay(stdscr, FALSE);
    getch();
}