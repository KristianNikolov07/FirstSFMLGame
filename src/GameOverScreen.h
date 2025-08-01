#pragma once
#include <SFML/Graphics.hpp>

class GameOverScreen {
    public:
    GameOverScreen();
    ~GameOverScreen();

    void update();
    void render(sf::RenderWindow& window);

    private:
    sf::Font font;
    sf::Text game_over_text;
    sf::Text play_again_text;
};
