#ifndef FIELDBUTTON_H
#define FIELDBUTTON_H

  #include <SFML/Graphics.hpp>
  #include <string>

  class FieldButton
  {
    public:
      FieldButton(sf::Font& font, std::string text, unsigned int characterSize, 
                  sf::Vector2f position, sf::Vector2f size);
      FieldButton();
      
      bool isClicked(sf::Vector2i clickPosition);
      void draw(sf::RenderWindow& targetWindow);

      void setPosition(sf::Vector2f newPosition);
      void setPosition(double x, double y);
      sf::Vector2f getPosition();

      sf::Vector2f getSize();

      void setText(std::string newText);

      void setColor(sf::Color color);
      void setBackgroundColor(sf::Color color);

    private:
      sf::Text text{  };
      sf::RectangleShape background{  };
  };

#endif
