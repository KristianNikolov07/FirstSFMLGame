#pragma once
#include "SFML/Graphics.hpp"

class Player;

class HPText: public sf::Text{
    public:
    HPText();
    ~HPText();

    void update(Player& player);
};
