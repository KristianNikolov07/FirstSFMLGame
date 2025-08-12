#pragma once
#include "BlinkingText.h"
#include "SFML/Graphics.hpp"

class Game;

class GameOverScreen {
public:
    GameOverScreen();
    ~GameOverScreen();

    void update(float delta, Game* game);
    void render(sf::RenderWindow &window);

private:
    sf::Text gameOverText;
    BlinkingText playAgainText;
    sf::RectangleShape blur;
};
