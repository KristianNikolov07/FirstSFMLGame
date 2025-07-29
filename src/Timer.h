#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>


class Timer final : public  sf::Text{
    public:
    Timer(const sf::Font &font, const sf::String &string, const unsigned int characterSize);

    ~Timer();

    void update(float delta);

    private:
    sf::Clock clock;
};
