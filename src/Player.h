#pragma once
#include <SFML/Graphics.hpp>
class Game;

class Player{
public:
    Player(float x, float y);
    ~Player();

    void update(float delta, const sf::RenderWindow& window, Game* game);
    void render(sf::RenderWindow& window);

    int getHP(){return hp;}
    sf::FloatRect getGlobalBounds(){ return shape.getGlobalBounds(); }

    void addHP(int _hp = 1){hp += _hp;}
    void removeHP(int _hp, Game* game);

    void reset();

private:
    float size = 50;
    float speed = 150;
    int hp = 1;

    sf::RectangleShape shape;
};
