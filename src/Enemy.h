#pragma once
#include "Game.h"
class Player;

class Enemy final : public sf::RectangleShape{
    public:
    Enemy(float x, float y);
    ~Enemy();

    void update(float delta, const Player& player);

    private:
    float size = 80;
    float speed = 200;

    bool checkCollision(const Player& player) const;
};
