#pragma once

#include <ncurses.h>
#include "actions/position.hpp"

namespace Screen {
    void init();
    void close();
    Position getCenter();
    Position getScreenSize();
}