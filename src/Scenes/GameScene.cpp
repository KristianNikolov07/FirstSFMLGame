#include "GameScene.h"

GameScene::GameScene(): player(400, 500) {
}

GameScene::~GameScene() = default;

void GameScene::update(const float delta, const sf::RenderWindow& window) {
    player.update(delta, window);
    enemy_manager.update(delta, player);
    timer.update(delta);
}

void GameScene::render(sf::RenderWindow &window) {
    window.draw(player);
    enemy_manager.render(window);
    timer.render(window);
}
