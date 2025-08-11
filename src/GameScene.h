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
    //Objects
    Player player;
    HPText hpText;
    Timer timer;
    std::vector<Enemy> enemies;
    std::vector<Heart*> hearts;
    sf::Clock clock;

    //Properties
    float spawnDelay = 1.0;
    int heartSpawnChance = 10;

    //Functions
    void addEnemy(float speed, int amount = 1);
    void clearEnemies();
    void addHeart();
    void clearHearts();



};
