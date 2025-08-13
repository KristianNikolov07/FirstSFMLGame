#include "Heart.h"
#include "Player.h"
#include "ResourceManager.h"

Heart::Heart(float x, float y): sprite(ResourceManager::heartTexture){
    sprite.setScale({0.2f, 0.2f});
    sprite.setPosition({x, y});
}

Heart::~Heart() {

}


void Heart::update(float delta, Player& player) {
    //Spinning
    sprite.rotate(sf::degrees(15 * delta));

    //Movement
    sprite.move({0, speed * delta});

    //Collision
    if (checkCollision(player)) {
        player.addHP();
        sprite.setPosition({0, 1000});
        ResourceManager::pickupSound.play();
    }
}

void Heart::render(sf::RenderWindow &window) {
    window.draw(sprite);
}


bool Heart::checkCollision(Player& player) {
    if (player.getGlobalBounds().findIntersection(sprite.getGlobalBounds())) {
        return true;
    }
    return false;
}