#include <ncurses.h>
#include <vector>
#include <string>

const std::vector<std::string> gameOverArt = {
    "  SSSSSS   SSSSS  SSS    SSS SSSSSSS     SSSSSS   SS    SS SSSSSSS SSSSSS  ",
    " SS       SS   SS SSSS  SSSS SS        SS      SS SS    SS SS      SS   SS ",
    " SS   SSS SSSSSSS SS SSSS SS SSSSS     SS      SS SS    SS SSSSS   SSSSSS  ",
    " SS    SS SS   SS SS  SS  SS SS        SS      SS  SS  SS  SS      SS   SS ",
    "  SSSSSS  SS   SS SS      SS SSSSSSS     SSSSSS      SS    SSSSSSS SS   SS "
};

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    curs_set(0);

    // Get screen dimensions
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

    // Refresh screen to show changes
    refresh();

    // Wait for user input before exiting
    getch();

    // End ncurses
    endwin();
    return 0;
}
