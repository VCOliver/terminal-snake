#pragma once

#include <string>
#include <vector>
#include "actions/position.hpp"

namespace Screen {

    const std::vector<std::string> gameOverArt = {
    "  SSSSSS   SSSSS  SSS    SSS SSSSSSS     SSSSSS   SS    SS SSSSSSS SSSSSS  ",
    " SS       SS   SS SSSS  SSSS SS        SS      SS SS    SS SS      SS   SS ",
    " SS   SSS SSSSSSS SS SSSS SS SSSSS     SS      SS SS    SS SSSSS   SSSSSS  ",
    " SS    SS SS   SS SS  SS  SS SS        SS      SS  SS  SS  SS      SS   SS ",
    "  SSSSSS  SS   SS SS      SS SSSSSSS     SSSSSS      SS    SSSSSSS SS   SS "
    };


    void init();

    // Add char at Position
    void addchat(char ch, Position Position, bool food = false);
    void clear();
    void close();
    Position getCenter();
    Position getScreenSize();

    void gameOver();
}