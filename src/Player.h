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
    bool isInvinsible() const { return invinsibility; }

    void addHP(int _hp = 1){hp += _hp;}
    void removeHP(int _hp, Game* game);

    void startInvinsibility();

    void reset();

private:
    float size = 50;
    float speed = 250;
    int hp = 1;
    bool invinsibility = false;
    float invinsibilityDuration = 3;
    sf::Clock invinsibilityTimer;

    sf::RectangleShape shape;
};
