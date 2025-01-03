#pragma once

#include "actions/position.hpp"

namespace Screen {
    void init();
    void clear();
    void close();
    Position getCenter();
    Position getScreenSize();

    void gameOver();
}