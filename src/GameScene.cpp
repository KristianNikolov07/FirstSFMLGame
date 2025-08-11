#include "GameScene.h"

#include <cstdlib>
#include <ctime>

#include "Enemy.h"

GameScene::GameScene(): player(375, 500) {
    srand(time(0));
}

GameScene::~GameScene() = default;

void GameScene::update(const float delta, const sf::RenderWindow& window, Game* game) {
    //Player
    player.update(delta, window, game);

    //Spawning stuff
    summoner();

    //Update hearts
    for (auto heart : hearts) {
        heart->update(delta, player);
    }
    clearHearts();

    //Update enemies
    for (Enemy& enemy : enemies) {
        enemy.update(delta, player, game);
    }
    clearEnemies();


    hpText.update(player);
    timer.update(delta);
}

void GameScene::render(sf::RenderWindow &window) {
    player.render(window);

    for (auto heart: hearts) {
        heart->render(window);
    }

    for (Enemy& enemy : enemies) {
        enemy.render(window);
    }

    window.draw(hpText);
    timer.render(window);


}

void GameScene::reset() {
    player.reset();
    timer.reset();

    enemies.clear();
    clock.restart();
}

void GameScene::summoner() {

    if (timer.getSeconds() > 30) {
        enemySpeed = 300;
        enemyAmount = 2;
    }

    if (timer.getSeconds() > 60) {
        enemySpeed = 500;
        enemyAmount = 3;
    }

    if (timer.getSeconds() > 90) {
        spawnDelay = 0.5;
        enemySpeed = 400;
        enemyAmount = 1;
    }

    if (clock.getElapsedTime().asSeconds() > spawnDelay) {
        clock.restart();
        const int randNum = rand() % 100;
        if (randNum <= heartSpawnChance) {
            addHeart();
        }
        addEnemy(enemySpeed, enemyAmount);

    }
}


void GameScene::addEnemy(float speed, int amount) {
    for (int i = 0; i < amount; i++) {
        const int randNum = rand() % 10;
        const int x = randNum * 80;
        const Enemy enemy(x, -120, speed);
        enemies.push_back(enemy);
    }

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

void GameScene::addHeart() {
    const int randNum = rand() % 10;
    const int x = randNum * 80;

    auto* heart = new Heart(x, -120);
    hearts.push_back(heart);
}

void GameScene::clearHearts() {
    int i = 0;
    for (auto heart : hearts) {
        if (heart->getPosition().y > 850) {
            delete heart;
            hearts.erase(hearts.begin() + i);
        }
        i++;
    }
}
