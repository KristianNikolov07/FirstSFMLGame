#pragma once
#include <SFML/Graphics.hpp>

#include "EnemyManager.h"
#include "GameOverScreen.h"
#include "Player.h"
#include "Timer.h"

class Game {

public:
    Game();
    ~Game();

    void HandleEvents();
    void Update();
    void Render();

    enum GameState {
        START,
        GAME,
        GAME_OVER
    };

    sf::RenderWindow& getWindow() { return window; }
    static GameState getState() { return state; }
    static void setState(const GameState _state) { state = _state; }

    void GameOver();

private:
    sf::RenderWindow window;
    sf::Font font;

    //Game objects
    sf::Clock clock;
    Player player;
    EnemyManager enemy_manager;
    Timer timer;

    GameOverScreen game_over_screen;

    static GameState state;
};
