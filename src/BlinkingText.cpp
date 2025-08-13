#include "BlinkingText.h"

#include <iostream>

#include "Game.h"
#include "ResourceManager.h"

BlinkingText::BlinkingText(float _delay, std::string text, int size): Text(ResourceManager::font, text, size){
    delay = _delay;
}

BlinkingText::~BlinkingText() {

}

void BlinkingText::update(float delta) {
    if (clock.getElapsedTime().asSeconds() >= delay) {
        clock.restart();
        visible = !visible;
    }
}

void BlinkingText::render(sf::RenderWindow &window) const {
    if (visible) {
        window.draw(*this);
    }
}

