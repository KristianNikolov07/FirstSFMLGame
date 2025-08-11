#pragma once
#include <SFML/Graphics.hpp>


class Timer{
    public:
    Timer();
    ~Timer();

    void update(float delta);
    void render(sf::RenderWindow& window) const;
    void reset();

    float getSeconds() const { return clock.getElapsedTime().asSeconds(); }

    private:
    sf::Clock clock;
    sf::Text text;


};
