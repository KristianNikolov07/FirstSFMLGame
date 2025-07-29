#include "Game.h"

#include "EnemyManager.h"
#include "Timer.h"


Player player(350, 600);

EnemyManager enemy_manager;

sf::Font font("assets/fonts/Arialn.ttf");
Timer timer(font, "0", 30);

Game::Game() {
    window.create(sf::VideoMode({800, 800}), "SFML Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

}

Game::~Game() {

}

void Game::HandleEvents() {
    while (const auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Game::Update() {
    const float delta = clock.restart().asSeconds();

    player.update(delta, window);
    enemy_manager.update(delta, player);
    timer.update(delta);
}

void Game::Render() {
    window.clear(sf::Color::Black);

    window.draw(player);
    enemy_manager.render(window);
    window.draw(timer);

    window.display();
}


