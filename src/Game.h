#pragma once
#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "GameOverScene.h"


enum Scenes {
    MENU,
    GAME,
    GAME_OVER
};

inline sf::Font font("assets/fonts/RedAlert.ttf");

class Game {
    public:
    Game();
    ~Game();

    void HandleEvents();
    void Update();
    void Render();

    sf::RenderWindow& getWindow() { return window; }
    Scenes getScene() const { return scene; }

    void setScene(const Scenes _scene);

    private:
    sf::RenderWindow window;
    Scenes scene = Scenes::GAME;
    sf::Clock clock;

    //Scenes
    GameScene gameScene;
    GameOverScene gameOverScene;
};
