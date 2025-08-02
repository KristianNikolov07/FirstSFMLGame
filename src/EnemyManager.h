#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Player;
class Enemy;
class Game;

class EnemyManager {
    public:
    EnemyManager();
    ~EnemyManager();

    void update(float delta, const Player& player, Game* game);
    void render(sf::RenderWindow& window);

    void reset();

    private:
    std::vector<Enemy> enemies;
    void addEnemy();
    void clearEnemies();
    sf::Clock clock;

    float spawnDelay = 1.0;
};
