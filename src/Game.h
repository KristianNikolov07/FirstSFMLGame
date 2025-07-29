#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"

class Game {
    public:
    Game();
    ~Game();

    void HandleEvents();
    void Update();
    void Render();

    sf::RenderWindow& getWindow() { return window; }

    private:
    sf::RenderWindow window;

    sf::Clock clock;

};
