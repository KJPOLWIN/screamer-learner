#include "textbutton.h"
#include <SFML/Graphics.hpp>
#include <string>

TextButton::TextButton(sf::Font& font, std::string text, 
                       sf::Vector2f position, unsigned int size)
{
  TextButton::text.setFont(font);
  TextButton::text.setString(text);
  TextButton::text.setPosition(position);
  TextButton::text.setCharacterSize(size);

  background.setSize(sf::Vector2f(TextButton::text.getGlobalBounds().width + 20, 
                                  TextButton::text.getGlobalBounds().height + 20));
  background.setPosition(TextButton::text.getPosition());
}

bool TextButton::isClicked(sf::Vector2i clickPosition)
{
  return text.getGlobalBounds().contains(clickPosition.x, clickPosition.y);
}

void TextButton::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(background);
  targetWindow.draw(text);
}
      
void TextButton::setPosition(sf::Vector2f newPosition)
{
  text.setPosition(newPosition);
  background.setPosition(text.getPosition());
}

void TextButton::setPosition(double x, double y)
{
  text.setPosition(x, y);
  background.setPosition(text.getPosition());
}

sf::Vector2f TextButton::getPosition()
{
  return text.getPosition();
}

sf::Vector2f TextButton::getSize()
{
  return sf::Vector2f(text.getGlobalBounds().width, 
                      text.getGlobalBounds().height);
}
      
void TextButton::setText(std::string newText)
{
  text.setString(newText);
  background.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 
                                  text.getGlobalBounds().height + 20));
}
      
void TextButton::setColor(sf::Color color)
{
  text.setFillColor(color);
}

void TextButton::setBackgroundColor(sf::Color color)
{
  background.setFillColor(color);
}
