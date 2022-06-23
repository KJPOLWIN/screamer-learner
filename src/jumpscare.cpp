#include "jumpscare.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

Jumpscare::Jumpscare(sf::Texture& image, sf::SoundBuffer& audio)
{
  sprite.setTexture(image);
  sound.setBuffer(audio);
}

void Jumpscare::draw(sf::RenderWindow& window)
{
  window.draw(sprite);
}

void Jumpscare::play()
{
  sound.play();
}

void Jumpscare::stop()
{
  sound.stop();
}
