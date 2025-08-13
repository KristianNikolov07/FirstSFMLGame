#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace ResourceManager {
    inline sf::Font font("assets/fonts/RedAlert.ttf");

    inline sf::Texture heartTexture("assets/textures/heart.png");

    //Sounds
    inline sf::SoundBuffer pickupSoundBuffer("assets/sound/pickup.mp3");
    inline sf::Sound pickupSound(pickupSoundBuffer);

    inline sf::SoundBuffer hitSoundBuffer("assets/sound/hit.mp3");
    inline sf::Sound hitSound(hitSoundBuffer);
}
