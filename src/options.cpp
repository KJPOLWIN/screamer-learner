#include "options.h"
#include "textbutton.h"
#include "style.h"
#include "state.h"
#include <SFML/Graphics.hpp>

Options::Options(sf::Font& font)
  : title{ "Options", font, 75 },
    backButton{ font, "Go back", sf::Vector2f(100.0f, 930.0f), 50 }
{
  title.setPosition(100.0f, 100.0f);

  title.setFillColor(Style::textColor);
  backButton.setColor(Style::textColor);

  backButton.setBackgroundColor(Style::backgroundColor);
}
      
void Options::clickInput(sf::Vector2i clickPosition, State& state)
{
  if(backButton.isClicked(clickPosition))
  {
    state = State::MainMenu;
  }
}

void Options::run(sf::RenderWindow& window)
{
  window.draw(title);
  backButton.draw(window);
}
