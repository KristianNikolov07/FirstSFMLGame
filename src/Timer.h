#pragma once
#include <SFML/Graphics.hpp>


class Timer{
    public:
    Timer();
    ~Timer();

    void update(float delta);
    void render(sf::RenderWindow& window) const;
    void reset();

    private:
    sf::Clock clock;
    sf::Text text;
};
