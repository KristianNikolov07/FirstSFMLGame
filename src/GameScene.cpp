#include "GameScene.h"

#include <cstdlib>
#include <ctime>

#include "Enemy.h"

GameScene::GameScene(): player(400, 500) {
    srand(time(0));
}

GameScene::~GameScene() = default;

void GameScene::update(const float delta, const sf::RenderWindow& window, Game* game) {
    player.update(delta, window, game);

    if (clock.getElapsedTime().asSeconds() > spawnDelay) {
        clock.restart();
        addEnemy();
    }

    for (Enemy& enemy : enemies) {
        enemy.update(delta, player, game);
    }
    clearEnemies();

    hpText.update(player);
    timer.update(delta);
}

void GameScene::render(sf::RenderWindow &window) {
    window.draw(player);
    window.draw(hpText);
    timer.render(window);

    for (Enemy& enemy : enemies) {
        window.draw(enemy);
    }
}

void GameScene::reset() {
    player.reset();
    timer.reset();

    enemies.clear();
    clock.restart();
}

void GameScene::addEnemy() {
    const int randNum = rand() % 10;
    const int x = randNum * 80;

    const Enemy enemy(x, -120);
    enemies.push_back(enemy);
}

void GameScene::clearEnemies() {
    int i = 0;
    for (Enemy& enemy : enemies) {
        if (enemy.getPosition().y > 850) {
            enemies.erase(enemies.begin() + i);
        }
        i++;
    }
}