#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"

class Player;

class Enemy {
public:
    Enemy(float x, float y, float _speed = 200 );
    ~Enemy();

    void update(float delta, Player& player, Game* game);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const { return shape.getPosition(); }

private:
    float size = 80;
    float speed = 200;
    sf::RectangleShape shape;

    bool checkCollision(Player& player) const;
};
