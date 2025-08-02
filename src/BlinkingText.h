#pragma once
#include "SFML/Graphics.hpp"

class BlinkingText : public sf::Text {
public:

    BlinkingText(float _delay, std::string text, int size);

    ~BlinkingText();

    void update(float delta);

    void render(sf::RenderWindow& window) const;

private:
    sf::Clock clock;
    float delay;
    bool visible = true;
};
