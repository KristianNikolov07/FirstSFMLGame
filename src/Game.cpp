#include "Game.h"

Game::GameState Game::state = Game::GAME;

Game::Game(): font("assets/fonts/arial.ttf"), player(400, 500){
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

    if (getState() == GAME) {
        player.update(delta, window);
        enemy_manager.update(delta, player, this);
        timer.update(delta);
    }
    else if (getState() == GAME_OVER) {
        game_over_screen.update();
    }

}

void Game::Render() {

    if (getState() == GAME) {
        window.clear(sf::Color::Black);

        window.draw(player);
        enemy_manager.render(window);
        timer.render(window);

        window.display();
    }
    else if (getState() == GAME_OVER) {
        window.clear(sf::Color::Black);
        game_over_screen.render(window);
        window.display();
    }

}

void Game::GameOver() {
    timer.reset();
    enemy_manager.clearAllEnemies();
    setState(GAME_OVER);

}


