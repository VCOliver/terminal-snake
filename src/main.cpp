#include <iostream>
#include "core/game.hpp"

int main() {
    Game game;
    game.init();
    game.run();
    game.close();
    return 0;
}