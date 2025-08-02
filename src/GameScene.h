#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "EnemyManager.h"
#include "Timer.h"

class Game;

class GameScene {
public:
    GameScene();
    ~GameScene();

    void update(float delta, const sf::RenderWindow& window, Game* game);
    void render(sf::RenderWindow& window);

    void reset();

private:
    Player player;
    EnemyManager enemy_manager;
    Timer timer;
};
