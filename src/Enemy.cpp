#include "Enemy.h"
#include<iostream>


Enemy::Enemy(float x, float y) {
    setSize({size, size});
    setPosition({x, y});
    setFillColor(sf::Color::Red);
}

Enemy::~Enemy() {

}

void Enemy::update(const float delta, const Player& player) {
    move({0, speed * delta});

    if (checkCollision(player)) {
        std::cout << "Collision" << std::endl;
    }
}

bool Enemy::checkCollision(const Player &player) const {
    if (getGlobalBounds().findIntersection(player.getGlobalBounds())) {
        return true;
    }
    return false;
}


