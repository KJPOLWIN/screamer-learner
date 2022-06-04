#include "quizstate.h"
#include "quiz.h"
#include "question.h"
#include "textbutton.h"
#include "style.h"
#include "state.h"
#include <SFML/Graphics.hpp>
#include <vector>

QuizState::QuizState(sf::Font& font)
  : question{ "", font, 75 },
    buttons{ { TextButton(font, "", sf::Vector2f(100, 500), 50),
               TextButton(font, "", sf::Vector2f(100, 600), 50),
               TextButton(font, "", sf::Vector2f(100, 700), 50),
               TextButton(font, "", sf::Vector2f(100, 800), 50) } }
{
  question.setPosition(100, 100);

  question.setFillColor(Style::textColor); 
  buttons.at(0).setColor(Style::textColor); 
  buttons.at(1).setColor(Style::textColor); 
  buttons.at(2).setColor(Style::textColor); 
  buttons.at(3).setColor(Style::textColor);

  quiz.loadFromFile("quiz/testquiz.json"); 
}

void QuizState::clickInput(sf::Vector2i clickInput, State& state)
{
  if(buttons.at(0).isClicked(clickInput))
  {
    
  }
  else if(buttons.at(1).isClicked(clickInput))
  {
    
  }
  else if(buttons.at(2).isClicked(clickInput))
  {
    
  }
  else if(buttons.at(3).isClicked(clickInput))
  {
    
  }
}

void QuizState::run(sf::RenderWindow& window)
{
  window.draw(question);
  for(auto& button : buttons)
  {
    button.draw(window);
  }
}
