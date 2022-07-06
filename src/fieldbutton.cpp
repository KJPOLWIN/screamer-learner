#include "fieldbutton.h"
#include <SFML/Graphics.hpp>
#include <string>

FieldButton::FieldButton(sf::Font& font, std::string text, unsigned int characterSize, 
                         sf::Vector2f position, sf::Vector2f size)
{
  FieldButton::text.setFont(font);
  FieldButton::text.setString(text);
  FieldButton::text.setCharacterSize(characterSize);

  background.setSize(size);
  background.setPosition(position);
  
  FieldButton::text.setPosition(background.getPosition().x + (size.x
                                                              - FieldButton::text.getGlobalBounds().width) / 2, 
                                background.getPosition().y + (size.y
                                                              - FieldButton::text.getGlobalBounds().height) / 2);

}

bool FieldButton::isClicked(sf::Vector2i clickPosition)
{
  //return text.getGlobalBounds().contains(clickPosition.x, clickPosition.y);
  return background.getGlobalBounds().contains(clickPosition.x, clickPosition.y);
}

void FieldButton::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(background);
  targetWindow.draw(text);
}
      
void FieldButton::setPosition(sf::Vector2f newPosition)
{
  background.setPosition(newPosition);
  text.setPosition(background.getPosition().x + (background.getSize().x
                                                 - text.getGlobalBounds().width) / 2, 
                   background.getPosition().y + (background.getSize().y
                                                 - text.getGlobalBounds().height) / 2);
}

void FieldButton::setPosition(double x, double y)
{
  setPosition(sf::Vector2f(x, y));
}

sf::Vector2f FieldButton::getPosition()
{
  return background.getPosition();
}

sf::Vector2f FieldButton::getSize()
{
  return background.getSize();
  //return sf::Vector2f(background.getGlobalBounds().width, 
  //                    background.getGlobalBounds().height);
}
      
void FieldButton::setText(std::string newText)
{
  text.setString(newText);
  setPosition(getPosition());
}
      
void FieldButton::setColor(sf::Color color)
{
  text.setFillColor(color);
}

void FieldButton::setBackgroundColor(sf::Color color)
{
  background.setFillColor(color);
}
