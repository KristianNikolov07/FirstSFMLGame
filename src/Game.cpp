#include "Game.h"


Game::Game(){
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
    if (getScene() == Scenes::GAME) {
        gameScene.update(delta, window);
    }

}

void Game::Render() {
    window.clear(sf::Color::Black);
    if (getScene() == Scenes::GAME) {
        gameScene.render(window);
    }

    window.display();
}


