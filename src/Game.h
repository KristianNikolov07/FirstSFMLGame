#pragma once
#include <SFML/Graphics.hpp>

#include "BlinkingText.h"
#include "GameOverScreen.h"
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
    bool isGameOver() { return gameOver; }

    void setGameOver() { gameOver = true; }

    private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Clock spawnClock;

    bool gameOver = false;

    //Objects
    Player player;
    HPText hpText;
    Timer timer;
    std::vector<Enemy*> enemies;
    std::vector<Heart*> hearts;
    GameOverScreen gameOverScreen;


    //Properties
    float defaultEnemySpeed = 200;
    float defaultEnemyAmount = 1;
    float defaultSpawnDelay = 1.0;
    int defaultHeartSpawnChance = 5;

    float enemySpeed = defaultEnemySpeed;
    float enemyAmount = defaultEnemyAmount;
    float spawnDelay = defaultSpawnDelay;
    int heartSpawnChance = defaultHeartSpawnChance;

    //Functions
    void summoner();
    void addEnemy(float speed, int amount = 1);
    void clearEnemies();
    void addHeart();
    void clearHearts();
};
