#include "GameOverScene.h"
#include "Game.h"

GameOverScene::GameOverScene():
    GameOverText(font, "Game Over", 50),
    PlayAgainText(0.5, "Press Enter to play again", 30) {

        GameOverText.setPosition({270, 100});
        PlayAgainText.setPosition({240, 450});
}

GameOverScene::~GameOverScene() {

}

void GameOverScene::update(float delta, sf::RenderWindow& window, Game* game) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        game->setScene(Scenes::GAME);
    }

    PlayAgainText.update(delta);
}

void GameOverScene::render(sf::RenderWindow& window) {
    window.draw(GameOverText);
    PlayAgainText.render(window);
}
