#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Timer final : public  sf::Text{
    public:
    Timer(const sf::Font &font, const sf::String &string, const unsigned int characterSize) : Text(font, string, characterSize) {
        setPosition({350, 0});
    }
    ~Timer();

    void update(float delta);

    private:
    sf::Clock clock;
};
