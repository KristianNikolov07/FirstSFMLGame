#include "GameScene.h"

GameScene::GameScene(): player(400, 500) {
}

GameScene::~GameScene() = default;

void GameScene::update(const float delta, const sf::RenderWindow& window, Game* game) {
    player.update(delta, window);
    enemy_manager.update(delta, player, game);
    timer.update(delta);
}

void GameScene::render(sf::RenderWindow &window) {
    window.draw(player);
    enemy_manager.render(window);
    timer.render(window);
}

void GameScene::reset() {
    player.setPosition({400, 500});
    enemy_manager.reset();
    timer.reset();
}
