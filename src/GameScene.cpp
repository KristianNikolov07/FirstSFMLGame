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

    //Spawning stuff
    if (clock.getElapsedTime().asSeconds() > spawnDelay) {
        clock.restart();
        const int randNum = rand() % 50;
        if (randNum == 1) {
            addHeart();
        }
        else {
            addEnemy();
        }


    }

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
    window.draw(player);

    for (auto heart: hearts) {
        heart->render(window);
    }

    for (Enemy& enemy : enemies) {
        window.draw(enemy);
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
