#pragma once
#include <SFML/Graphics.hpp>

#include "BlinkingText.h"

class Game;

class GameOverScene {
    public:
    GameOverScene();
    ~GameOverScene();

    void update(float delta, sf::RenderWindow& window, Game* game);
    void render(sf::RenderWindow& window);

    private:
    sf::Text GameOverText;
    BlinkingText PlayAgainText;
};
