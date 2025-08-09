#pragma once
#include <SFML/Graphics.hpp>

#include "Heart.h"
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
    std::vector<Heart> hearts;

    void addEnemy();
    void clearEnemies();
    void addHeart();
    void clearHearts();

    sf::Clock clock;
    float spawnDelay = 1.0;
};
