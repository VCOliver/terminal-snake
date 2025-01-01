#pragma once

#include <ncurses.h>
#include "actions/position.hpp"

namespace Screen {
    void init();
    void clear();
    void close();
    Position getCenter();
    Position getScreenSize();

    void gameOver();
}