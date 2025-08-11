#include "Enemy.h"
#include<iostream>

#include "Player.h"

Enemy::Enemy(float x, float y) {
    shape.setSize({size, size});
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color::Red);
}

Enemy::~Enemy() {

}

void Enemy::update(const float delta, Player& player, Game* game) {
    shape.move({0, speed * delta});

    if (checkCollision(player)) {
        player.removeHP(1, game);
        shape.setPosition({0, 1000});
    }
}

void Enemy::render(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Enemy::checkCollision(Player &player) const {
    if (shape.getGlobalBounds().findIntersection(player.getGlobalBounds())) {
        return true;
    }
    return false;
}


