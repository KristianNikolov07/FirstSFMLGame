#include "Player.h"
#include "Game.h"

Player::Player(float x, float y) {
    setSize({size, size});
    setPosition({x, y});
}

Player::~Player() {

}

void Player::update(const float delta, const sf::RenderWindow& window, Game* game) {
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

void Player::removeHP(int _hp, Game *game) {
    hp -= _hp;
    if (hp <= 0) {
        game->setScene(Scenes::GAME_OVER);
    }
}

void Player::reset() {
    setPosition({300, 400});
    hp = 1;
}
