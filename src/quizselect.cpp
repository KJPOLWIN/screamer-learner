#include "quizselect.h"
#include "textbutton.h"
#include "style.h"
#include "state.h"
#include <SFML/Graphics.hpp>

QuizSelect::QuizSelect(sf::Font& font)
  : title{ "Select quiz", font, 75 },
    startButton{ font, "Start", sf::Vector2f(1620.0f, 930.0f), 50 },
    backButton{ font, "Go back", sf::Vector2f(100.0f, 930.0f), 50 }
{
  title.setPosition(100.0f, 100.0f);

  title.setFillColor(Style::textColor);
  startButton.setColor(Style::textColor);
  backButton.setColor(Style::textColor);
}
      
void QuizSelect::clickInput(sf::Vector2i clickPosition, State& state)
{
  if(startButton.isClicked(clickPosition))
  {
    state = State::Quiz;
  }
  else if(backButton.isClicked(clickPosition))
  {
    state = State::MainMenu;
  }
}

void QuizSelect::run(sf::RenderWindow& window)
{
  window.draw(title);
  startButton.draw(window);
  backButton.draw(window);
}
