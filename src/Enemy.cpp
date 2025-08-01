#include "Enemy.h"
#include<iostream>

#include "Game.h"
#include "Player.h"

Enemy::Enemy(float x, float y) {
    setSize({size, size});
    setPosition({x, y});
    setFillColor(sf::Color::Red);
}

Enemy::~Enemy() {

}

void Enemy::update(const float delta, const Player& player, Game* game) {
    move({0, speed * delta});

    if (checkCollision(player)) {
        game->GameOver();
    }
}

bool Enemy::checkCollision(const Player &player) const {
    if (getGlobalBounds().findIntersection(player.getGlobalBounds())) {
        return true;
    }
    return false;
}


