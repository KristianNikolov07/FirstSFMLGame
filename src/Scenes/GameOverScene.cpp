#include "GameOverScene.h"
#include "../Game.h"

GameOverScene::GameOverScene(): GameOverText(font, "Game Over"), PlayAgainText(font, "Press Enter to play again") {
    GameOverText.setPosition({350, 100});
    PlayAgainText.setPosition({350, 150});
}

GameOverScene::~GameOverScene() {

}

void GameOverScene::update(float delta, sf::RenderWindow& window, Game* game) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        game->setScene(Scenes::GAME);
    }
}

void GameOverScene::render(sf::RenderWindow& window) {
    window.draw(GameOverText);
    window.draw(PlayAgainText);
}
