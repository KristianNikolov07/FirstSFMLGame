#include "Game.h"
#include "Enemy.h"
#include "Heart.h"

Game::Game(): player(375, 500){
    //Window
    window.create(sf::VideoMode({800, 800}), "SFML Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    //Seed
    srand(time(0));

}

Game::~Game() {

}

void Game::HandleEvents() {
    while (const auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Game::Update() {
    const float delta = clock.restart().asSeconds();

    if (gameOver == false) {

        //Player
        player.update(delta, window, this);

        //Spawning stuff
        summoner();

        //Update hearts
        for (auto heart : hearts) {
            heart->update(delta, player);
        }
        clearHearts();

        //Update enemies
        for (Enemy* enemy : enemies) {
            enemy->update(delta, player, this);
        }
        clearEnemies();


        hpText.update(player);
        timer.update(delta);
    }
    else {
        gameOverScreen.update(delta, this);
    }


}

void Game::Render() {
    window.clear(sf::Color::Black);

    player.render(window);

    for (Heart* heart: hearts) {
        heart->render(window);
    }

    for (Enemy* enemy : enemies) {
        enemy->render(window);
    }

    window.draw(hpText);
    timer.render(window);

    if (gameOver == true) {
        gameOverScreen.render(window);
    }


    window.display();
}

void Game::reset() {
    enemySpeed = defaultEnemySpeed;
    enemyAmount = defaultEnemyAmount;
    spawnDelay = defaultSpawnDelay;
    heartSpawnChance = defaultHeartSpawnChance;

    player.reset();
    timer.reset();

    for (Enemy* enemy : enemies) {
        delete enemy;
    }
    enemies.clear();

    for (Heart* heart: hearts) {
        delete heart;
    }
    hearts.clear();

    clock.restart();
    gameOver = false;
}

void Game::summoner() {

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

    if (spawnClock.getElapsedTime().asSeconds() > spawnDelay) {
        spawnClock.restart();
        const int randNum = rand() % 100;
        if (randNum <= heartSpawnChance) {
            addHeart();
        }
        addEnemy(enemySpeed, enemyAmount);

    }
}


void Game::addEnemy(float speed, int amount) {
    for (int i = 0; i < amount; i++) {
        const int randNum = rand() % 10;
        const int x = randNum * 80;
        auto * enemy =  new Enemy(x, -120, speed);
        enemies.push_back(enemy);
    }

}

void Game::clearEnemies() {
    int i = 0;
    for (Enemy* enemy : enemies) {
        if (enemy->getPosition().y > 850) {
            delete enemy;
            enemies.erase(enemies.begin() + i);
        }
        i++;
    }
}

void Game::addHeart() {
    const int randNum = rand() % 10;
    const int x = randNum * 80;

    auto* heart = new Heart(x, -120);
    hearts.push_back(heart);
}

void Game::clearHearts() {
    int i = 0;
    for (auto heart : hearts) {
        if (heart->getPosition().y > 850) {
            delete heart;
            hearts.erase(hearts.begin() + i);
        }
        i++;
    }
}