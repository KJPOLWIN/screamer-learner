#include "mainmenu.h"
#include "style.h"
#include "state.h"
#include <SFML/Graphics.hpp>

MainMenu::MainMenu(sf::Font& font)
  : title{ "Screamer\nLearner", font, 100 },
    startButton{ font, "Start", sf::Vector2f(100.0f, 600.0f), 50 },
    optionsButton{ font, "Options", sf::Vector2f(100.0f, 600.0f), 50 },
    creditsButton{ font, "Credits", sf::Vector2f(100.0f, 700.0f), 50 },
    exitButton{ font, "Exit", sf::Vector2f(100.0f, 700.0f), 50 }
{
  title.setPosition(100.0f, 100.0f);

  title.setFillColor(Style::textColor);
  startButton.setColor(Style::textColor);
  optionsButton.setColor(Style::textColor);
  creditsButton.setColor(Style::textColor);
  exitButton.setColor(Style::textColor);
}
      
void MainMenu::clickInput(sf::Vector2i clickPosition, State& state)
{
  if(startButton.isClicked(clickPosition))
  {
    state = State::QuizSelect;
  }
  /*else if(optionsButton.isClicked(clickPosition))
  {
    state = State::Options;
  }
  else if(creditsButton.isClicked(clickPosition))
  {
    state = State::Credits;
  }*/
  else if(exitButton.isClicked(clickPosition))
  {
    state = State::Exit;
  }
}

void MainMenu::run(sf::RenderWindow& window)
{
  window.draw(title);
  startButton.draw(window);
  //optionsButton.draw(window);
  //creditsButton.draw(window);
  exitButton.draw(window);
}
