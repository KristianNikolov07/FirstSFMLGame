#include "EnemyManager.h"
#include <cstdlib>
#include <ctime>

EnemyManager::EnemyManager() {
    srand(time(0));
}

EnemyManager::~EnemyManager() {

}

void EnemyManager::update(float delta, const Player &player) {
    if (clock.getElapsedTime().asSeconds() > spawnDelay) {
        clock.restart();
        addEnemy();
    }

    for (Enemy& enemy : enemies) {
        enemy.update(delta, player);
    }

    clearEnemies();
}

void EnemyManager::render(sf::RenderWindow &window) {
    for (Enemy& enemy : enemies) {
        window.draw(enemy);
    }
}

void EnemyManager::addEnemy() {
    const int randNum = rand() % 10;
    const int x = randNum * 80;

    const Enemy enemy(x, -20);
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
