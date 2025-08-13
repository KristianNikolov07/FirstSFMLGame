#include "InvinsibilityPowerup.h"

#include <iostream>

#include "Player.h"
#include "ResourceManager.h"

InvinsibilityPowerup::InvinsibilityPowerup(float x, float y) {
    sprite.setSize({size, size});
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition({x, y});
}

InvinsibilityPowerup::~InvinsibilityPowerup() {
}

void InvinsibilityPowerup::update(float delta, Player& player) {
    sprite.move({0, speed * delta});

    if (CheckCollision(player)) {
        sprite.setPosition({0, 1200});
        player.startInvinsibility();
        ResourceManager::pickupSound.play();
    }
}

void InvinsibilityPowerup::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

bool InvinsibilityPowerup::CheckCollision(Player &player) {
    if (sprite.getGlobalBounds().findIntersection(player.getGlobalBounds())) {
        return true;
    }
    return false;
}
