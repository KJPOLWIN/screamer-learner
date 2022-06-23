#ifndef JUMPSCARE_H
#define JUMPSCARE_H

  #include <SFML/Graphics.hpp>
  #include <SFML/Audio.hpp>

  class Jumpscare
  {
    public:
      Jumpscare(sf::Texture& image, sf::SoundBuffer& audio);

      void draw(sf::RenderWindow& window);
      void play();
      void stop();

    private:
      sf::Sprite sprite{  };
      sf::Sound sound{  };
  };

#endif
