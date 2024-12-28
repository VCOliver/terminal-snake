#include <iostream>
#include <ncurses.h>

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
    // Wait for user input
    char ch = getch();
	if(ch == 's') {
		move(center_row+1, center_col);
		addch('#');
	}

	getch();
    // End ncurses mode
    endwin();

    return 0;
}