#pragma once
#include <SFML/Graphics.hpp>

#include "HPText.h"
#include "Player.h"
#include "Timer.h"

class Heart;
class Enemy;
inline sf::Font font("assets/fonts/RedAlert.ttf");

class Game {
    public:
    Game();
    ~Game();

    void HandleEvents();
    void Update();
    void Render();
    void reset();

    sf::RenderWindow& getWindow() { return window; }

    private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Clock spawnClock;

    //Objects
    Player player;
    HPText hpText;
    Timer timer;
    std::vector<Enemy*> enemies;
    std::vector<Heart*> hearts;

    //Properties
    float enemySpeed = 200;
    float enemyAmount = 1;
    float spawnDelay = 1.0;
    int heartSpawnChance = 5;

    //Functions
    void summoner();
    void addEnemy(float speed, int amount = 1);
    void clearEnemies();
    void addHeart();
    void clearHearts();
};
