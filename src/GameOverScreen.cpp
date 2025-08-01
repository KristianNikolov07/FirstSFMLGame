#include "GameOverScreen.h"

#include "Game.h"

GameOverScreen::GameOverScreen():font("assets/fonts/arial.ttf"), game_over_text(font, "Game Over", 50), play_again_text(font, "Press Enter to player again", 30) {
    game_over_text.setPosition({200, 0});
    play_again_text.setPosition({400, 300});
}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        Game::setState(Game::GameState::GAME);
    }
}

void GameOverScreen::render(sf::RenderWindow& window) {
    window.draw(game_over_text);
    window.draw(play_again_text);
}
