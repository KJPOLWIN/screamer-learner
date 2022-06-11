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
               TextButton(font, "", sf::Vector2f(100, 800), 50) } },
    questionCounter{ "", font, 50 }
{
  question.setPosition(100, 100);

  question.setFillColor(Style::textColor); 
  buttons.at(0).setColor(Style::textColor); 
  buttons.at(1).setColor(Style::textColor); 
  buttons.at(2).setColor(Style::textColor); 
  buttons.at(3).setColor(Style::textColor);

  questionCounter.setPosition(1700, 50);
  questionCounter.setColor(Style::textColor);

  quiz.loadFromFile("quiz/testquiz.json"); 
  loadQuestion(currentQuestion);

  questionCounter.setString(std::to_string(currentQuestion + 1) 
                          + "/" 
                          + std::to_string(quiz.getQuestionCount()));
}

void QuizState::clickInput(sf::Vector2i clickInput, State& state)
{
  if(buttons.at(0).isClicked(clickInput))
  {
    ++currentQuestion;
    if(currentQuestion >= quiz.getQuestionCount())
    {
      state = State::QuizSelect;
      reset();
    }
    else
    {
      loadQuestion(currentQuestion);
    }
  }
  else if(buttons.at(1).isClicked(clickInput))
  {
    ++currentQuestion;
    if(currentQuestion >= quiz.getQuestionCount())
    {
      state = State::QuizSelect;
      reset();
    }
    else
    {
      loadQuestion(currentQuestion);
    }
    
  }
  else if(buttons.at(2).isClicked(clickInput))
  {
    ++currentQuestion;
    if(currentQuestion >= quiz.getQuestionCount())
    {
      state = State::QuizSelect;
      reset();
    }
    else
    {
      loadQuestion(currentQuestion);
    }
    
  }
  else if(buttons.at(3).isClicked(clickInput))
  {
    ++currentQuestion;
    if(currentQuestion >= quiz.getQuestionCount())
    {
      state = State::QuizSelect;
      reset();
    }
    else
    {
      loadQuestion(currentQuestion);
    }
    
  }
  questionCounter.setString(std::to_string(currentQuestion + 1) 
                          + "/" 
                          + std::to_string(quiz.getQuestionCount()));
}

void QuizState::run(sf::RenderWindow& window)
{
  window.draw(question);
  for(auto& button : buttons)
  {
    button.draw(window);
  }
  window.draw(questionCounter);
}
  
void QuizState::loadQuestion(std::size_t id)
{
  question.setString(quiz.getQuestion(id).getQuestion());
  buttons.at(0).setText(quiz.getQuestion(id).getDummyAnswer(0));
  buttons.at(1).setText(quiz.getQuestion(id).getDummyAnswer(1));
  buttons.at(2).setText(quiz.getQuestion(id).getDummyAnswer(2));
  buttons.at(3).setText(quiz.getQuestion(id).getCorrectAnswer());
}

void QuizState::reset()
{
  quiz.loadFromFile("quiz/testquiz.json");
  currentQuestion = 0;
  loadQuestion(currentQuestion);
  questionCounter.setString(std::to_string(currentQuestion + 1) 
                          + "/" 
                          + std::to_string(quiz.getQuestionCount()));
}
