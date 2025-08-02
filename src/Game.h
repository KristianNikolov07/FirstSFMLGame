#pragma once
#include <SFML/Graphics.hpp>

#include "EnemyManager.h"
#include "Player.h"
#include "Timer.h"
#include "Scenes/GameScene.h"

enum Scenes {
    MENU,
    GAME,
    GAME_OVER
};

class Game {
    public:
    Game();
    ~Game();

    void HandleEvents();
    void Update();
    void Render();

    sf::RenderWindow& getWindow() { return window; }
    Scenes getScene() const { return scene; }

    void setScene(const Scenes _scene) { scene = _scene; }

    private:
    sf::RenderWindow window;
    Scenes scene = Scenes::GAME;
    sf::Clock clock;

    //Scenes
    GameScene gameScene;
};
