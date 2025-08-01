#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Game;
class Player;
class Enemy;

class EnemyManager {
    public:
    EnemyManager();
    ~EnemyManager();

    void update(float delta, const Player& player, Game* game);
    void render(sf::RenderWindow& window);
    void clearAllEnemies();

    private:
    std::vector<Enemy> enemies;
    void addEnemy();
    void clearEnemies();

    sf::Clock clock;

    float spawnDelay = 1.0;
};
