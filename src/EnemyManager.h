#pragma once
#include "Player.h"
#include <vector>

class EnemyManager {
    public:
    EnemyManager();
    ~EnemyManager();

    void update(float delta, const Player& player);
    void render(sf::RenderWindow& window);

    private:
    std::vector<Enemy> enemies;
    void addEnemy();
    void clearEnemies();
    sf::Clock clock;

    float spawnDelay = 1.0;
};
