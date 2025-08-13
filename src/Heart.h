#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Heart {
public:
    Heart(float x, float y);
    ~Heart();

    void update(float delta, Player& player);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() {return sprite.getPosition();}

private:
    sf::Sprite sprite;
    float speed = 100;

    bool checkCollision(Player& player);
};

