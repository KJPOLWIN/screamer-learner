#include "mainmenu.h"
#include <SFML/Graphics.hpp>

MainMenu::MainMenu(sf::Font& font)
  : title{ "Screamer\nLearner", font, 100 }
{
  title.setPosition(100.0f, 100.0f);
}

void MainMenu::run(sf::RenderWindow& window)
{
  window.draw(title);
}
