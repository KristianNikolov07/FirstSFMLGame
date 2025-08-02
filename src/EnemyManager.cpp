#include "EnemyManager.h"
#include <cstdlib>
#include <ctime>

#include "Enemy.h"

EnemyManager::EnemyManager() {
    srand(time(0));
}

EnemyManager::~EnemyManager() {

}

void EnemyManager::update(float delta, Player &player, Game* game) {
    if (clock.getElapsedTime().asSeconds() > spawnDelay) {
        clock.restart();
        addEnemy();
    }

    for (Enemy& enemy : enemies) {
        enemy.update(delta, player, game);
    }

    clearEnemies();
}

void EnemyManager::render(sf::RenderWindow &window) {
    for (Enemy& enemy : enemies) {
        window.draw(enemy);
    }
}

void EnemyManager::reset() {
    enemies.clear();
    clock.restart();
}

void EnemyManager::addEnemy() {
    const int randNum = rand() % 10;
    const int x = randNum * 80;

    const Enemy enemy(x, -120);
    enemies.push_back(enemy);
}

void EnemyManager::clearEnemies() {
    int i = 0;
    for (Enemy& enemy : enemies) {
        if (enemy.getPosition().y > 850) {
            enemies.erase(enemies.begin() + i);
        }
        i++;
    }
}
