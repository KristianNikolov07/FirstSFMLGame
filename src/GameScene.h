#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "HPText.h"
#include "Timer.h"

class Game;
class Enemy;

class GameScene {
public:
    GameScene();
    ~GameScene();

    void update(float delta, const sf::RenderWindow& window, Game* game);
    void render(sf::RenderWindow& window);

    void reset();

private:
    Player player;
    HPText hpText;

    Timer timer;

    std::vector<Enemy> enemies;
    void addEnemy();
    void clearEnemies();
    sf::Clock clock;
    float spawnDelay = 1.0;
};
