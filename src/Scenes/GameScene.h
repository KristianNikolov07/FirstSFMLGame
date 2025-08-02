#pragma once
#include <SFML\Graphics.hpp>
#include "../Player.h"
#include "../EnemyManager.h"
#include "../Timer.h"

class GameScene {
public:
    GameScene();
    ~GameScene();

    void update(float delta, const sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

private:
    Player player;
    EnemyManager enemy_manager;
    Timer timer;
};
