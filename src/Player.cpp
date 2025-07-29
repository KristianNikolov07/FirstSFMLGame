#include "Player.h"

Player::Player(float x, float y) {
    setSize({size, size});
    setPosition({x, y});
}

Player::~Player() {

}

void Player::update(const float delta, const sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        move({0, -speed * delta});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        move({0, speed * delta});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        move({-speed * delta, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        move({speed * delta, 0});
    }

    if (getPosition().x < 0) {
        setPosition({0, getPosition().y});
    }
    if (getPosition().y < 0) {
        setPosition({getPosition().x, 0});
    }
    if (getPosition().x + size > window.getSize().x) {
        setPosition({window.getSize().x - size, getPosition().y});
    }
    if (getPosition().y + size > window.getSize().y) {
        setPosition({getPosition().x, window.getSize().y - size});
    }
}
