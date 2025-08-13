#pragma once
#include <SFML/Graphics.hpp>

#include "BlinkingText.h"
#include "GameOverScreen.h"
#include "HPText.h"
#include "InvinsibilityPowerup.h"
#include "Player.h"
#include "Timer.h"

class Heart;
class Enemy;

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
    std::vector<Enemy> enemies;
    std::vector<Heart> hearts;
    std::vector<InvinsibilityPowerup> invinsibilityPowerups;
    GameOverScreen gameOverScreen;


    //Properties
    const float defaultEnemySpeed = 200;
    const float defaultEnemyAmount = 1;
    const float defaultSpawnDelay = 1.0;
    const int defaultHeartSpawnChance = 10;
    const int defaultInvinsibilityPowerupSpawnChange = 5;

    float enemySpeed = defaultEnemySpeed;
    float enemyAmount = defaultEnemyAmount;
    float spawnDelay = defaultSpawnDelay;
    int heartSpawnChance = defaultHeartSpawnChance;
    int invinsibilityPowerupSpawnChange = defaultInvinsibilityPowerupSpawnChange;

    //Functions
    void summoner();
    void addEnemy(float speed, int amount = 1);
    void clearEnemies();
    void addHeart();
    void clearHearts();
    void addInvinsibilityPowerup();
    void clearInvinsibilityPowerups();
};
