#pragma once
#include "Game.h"

class Player final : public sf::RectangleShape {
    public:
    Player(float x, float y);
    ~Player();

    void update(float delta, const sf::RenderWindow& window);

    private:
    float size = 50;
    float speed = 150;
};
