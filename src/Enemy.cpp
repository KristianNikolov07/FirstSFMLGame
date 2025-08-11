#include "Enemy.h"
#include<iostream>

#include "Player.h"

Enemy::Enemy(float x, float y) {
    setSize({size, size});
    setPosition({x, y});
    setFillColor(sf::Color::Red);
}

Enemy::~Enemy() {

}

void Enemy::update(const float delta, Player& player, Game* game) {
    move({0, speed * delta});

    if (checkCollision(player)) {
        player.removeHP(1, game);
        setPosition({0, 1000});
    }
}

bool Enemy::checkCollision(Player &player) const {
    if (getGlobalBounds().findIntersection(player.getGlobalBounds())) {
        return true;
    }
    return false;
}


