#pragma once
#include <SFML/Graphics.hpp>

class Player;

class InvinsibilityPowerup {
public:
    InvinsibilityPowerup(float x, float y);
    ~InvinsibilityPowerup();

    void update(float delta, Player& player);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() {return sprite.getPosition();};

private:
    sf::RectangleShape sprite;
    float size = 80;
    float speed = 150;

    bool CheckCollision(Player& player);
};
