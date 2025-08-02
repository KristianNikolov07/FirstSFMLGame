#include "Game.h"


Game::Game(): player(400, 500){
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
    timer.render(window);

    window.display();
}


