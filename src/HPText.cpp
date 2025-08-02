#include "HPText.h"
#include "Game.h"

HPText::HPText(): Text(font, "Health: 1", 20) {
    setPosition({700, 0});
}

HPText::~HPText() {

}

void HPText::update(Player& player) {
    setString("Health: " + std::to_string(player.getHP()));
}


