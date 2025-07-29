#include <iostream>
#include "Game.h"

int main() {
    Game game;
    while (game.getWindow().isOpen()) {
        game.HandleEvents();
        game.Update();
        game.Render();
    }
    return 0;
}