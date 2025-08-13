#include "GameOverScreen.h"
#include "Game.h"
#include "ResourceManager.h"

GameOverScreen::GameOverScreen(): gameOverText(ResourceManager::font, "Game Over", 70), playAgainText(0.5, "Press Enter to Play Again", 20) {
    //Game Over Text
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition({250, 300});

    //Play Again Text
    playAgainText.setPosition({300, 500});

    //Game Over Blur
    blur.setSize({800, 800});
    blur.setFillColor(sf::Color(0, 0, 0, 150));
}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::update(float delta, Game *game) {
    playAgainText.update(delta);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        game->reset();
    }
}

void GameOverScreen::render(sf::RenderWindow &window) {
    window.draw(blur);
    window.draw(gameOverText);
    playAgainText.render(window);
}


