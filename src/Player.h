#pragma once
#include <SFML/Graphics.hpp>
class Game;

class Player final : public sf::RectangleShape {
    public:
    Player(float x, float y);
    ~Player() override;

    void update(float delta, const sf::RenderWindow& window, Game* game);

    int getHP(){return hp;}

    void addHP(int _hp = 1){hp += _hp;}
    void removeHP(int _hp = 1){hp -= _hp;}

    void reset();

    private:
    float size = 50;
    float speed = 150;
    int hp = 1;
};
