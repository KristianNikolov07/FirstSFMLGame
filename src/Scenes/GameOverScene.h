#pragma once
#include <SFML/Graphics.hpp>

class Game;

class GameOverScene {
    public:
    GameOverScene();
    ~GameOverScene();

    void update(float delta, sf::RenderWindow& window, Game* game);
    void render(sf::RenderWindow& window);

    private:
    sf::Text GameOverText;
    sf::Text PlayAgainText;
};
