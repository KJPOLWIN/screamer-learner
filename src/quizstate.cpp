#include "quizstate.h"
#include "quiz.h"
#include "question.h"
#include "textbutton.h"
#include "jumpscare.h"
#include "style.h"
#include "state.h"
#include "random.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "json.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

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
  questionCounter.setFillColor(Style::textColor);

  std::fstream file{ "jumpscare/jumpscares.json" };
  nlohmann::json jumpscareData{  };
  file >> jumpscareData;

  std::size_t jumpscareCount{ jumpscareData["jumpscares"].size() };

  for(std::size_t iii{ 0 }; iii < jumpscareCount; ++iii)
  {
    jumpscareTexture.push_back(sf::Texture());
    jumpscareTexture.at(iii).loadFromFile("jumpscare/image/" 
        + static_cast<std::string>(jumpscareData["jumpscares"][iii]["image"]));
    
    jumpscareSoundBuffer.push_back(sf::SoundBuffer());
    jumpscareSoundBuffer.at(iii).loadFromFile("jumpscare/audio/" 
        + static_cast<std::string>(jumpscareData["jumpscares"][iii]["audio"]));
  }
  //For some reason, not all sprites will load textures if adding jumpscares
  //to vector is placed in above loop
  for(std::size_t iii{ 0 }; iii < jumpscareCount; ++iii)
  {
    jumpscares.push_back(Jumpscare(jumpscareTexture.at(iii), jumpscareSoundBuffer.at(iii)));
  }
  
  yayBuffer.loadFromFile("ChildrenYaySoundEffect2.wav");
  yaySound.setBuffer(yayBuffer);
}

void QuizState::clickInput(sf::Vector2i clickInput)
{
  if(buttons.at(0).isClicked(clickInput))
  {
    timer = 0.0;
    phase = Phase::resultGlimpse;
    chosenAnswer = 0;
  }
  else if(buttons.at(1).isClicked(clickInput))
  {
    timer = 0.0;
    phase = Phase::resultGlimpse;
    chosenAnswer = 1;
  }
  else if(buttons.at(2).isClicked(clickInput))
  {
    timer = 0.0;
    phase = Phase::resultGlimpse;
    chosenAnswer = 2;
  }
  else if(buttons.at(3).isClicked(clickInput))
  {
    timer = 0.0;
    phase = Phase::resultGlimpse;
    chosenAnswer = 3;
  }
  
}

void QuizState::run(double elapsedTime, sf::RenderWindow& window, State& state)
{
  timer += elapsedTime;

  if(phase == Phase::resultGlimpse && timer > resultGlimpseDuration)
  {
    timer = 0.0;

    if(chosenAnswer == correctAnswer)
    {
      phase = Phase::resultDisplay;
      yaySound.play();
    }
    else
    {
      jumpscareId = static_cast<std::size_t>(Random::getRandomInt(0, jumpscares.size() - 1));
      phase = Phase::jumpscare;
      jumpscares.at(jumpscareId).play();
    }
  }
  
  if(phase == Phase::jumpscare && timer > jumpscareDuration)
  {
    jumpscares.at(jumpscareId).stop();
    timer = 0.0;
    phase = Phase::resultDisplay;
  }

  if(phase == Phase::resultDisplay && timer > resultDisplayDuration)
  {
    timer = 0.0;
    phase = Phase::answerSelect;
    ++currentQuestion;
    questionCounter.setString(std::to_string(currentQuestion + 1) 
                            + "/" 
                            + std::to_string(quiz.getQuestionCount()));
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

  if(phase == Phase::answerSelect)
  {
    sf::Vector2i mousePos{ sf::Mouse::getPosition(window) };
   
    buttons.at(0).setColor(Style::textColor);
    buttons.at(1).setColor(Style::textColor);
    buttons.at(2).setColor(Style::textColor);
    buttons.at(3).setColor(Style::textColor);

    if(buttons.at(0).isClicked(mousePos))
    {
      buttons.at(0).setBackgroundColor(Style::activeBackgroundColor);  
    }
    else
    {
      buttons.at(0).setBackgroundColor(Style::backgroundColor);
    }
    
    if(buttons.at(1).isClicked(mousePos))
    {
      buttons.at(1).setBackgroundColor(Style::activeBackgroundColor);  
    }
    else
    {
      buttons.at(1).setBackgroundColor(Style::backgroundColor);
    }
    
    if(buttons.at(2).isClicked(mousePos))
    {
      buttons.at(2).setBackgroundColor(Style::activeBackgroundColor);  
    }
    else
    {
      buttons.at(2).setBackgroundColor(Style::backgroundColor);
    }
      
    if(buttons.at(3).isClicked(mousePos))
    {
      buttons.at(3).setBackgroundColor(Style::activeBackgroundColor);  
    }
    else
    {
      buttons.at(3).setBackgroundColor(Style::backgroundColor);
    }
  }
  else
  {
    if(chosenAnswer != correctAnswer)
    {
      buttons.at(chosenAnswer).setColor(Style::wrongAnswerColor);
      buttons.at(chosenAnswer).setBackgroundColor(Style::wrongBackgroundColor);
    }
      
    buttons.at(correctAnswer).setColor(Style::correctAnswerColor);
    buttons.at(correctAnswer).setBackgroundColor(Style::correctBackgroundColor);
  }

  window.draw(question);
  for(auto& button : buttons)
  {
    button.draw(window);
  }
  window.draw(questionCounter);
  if(phase == Phase::jumpscare)
  {
    jumpscares.at(jumpscareId).draw(window);
  }
}

void QuizState::loadQuiz(std::string filename)
{
  quiz.loadFromFile(filename); 
  loadQuestion(currentQuestion);

  questionCounter.setString(std::to_string(currentQuestion + 1) 
                          + "/" 
                          + std::to_string(quiz.getQuestionCount()));
}
  
void QuizState::loadQuestion(std::size_t id)
{
  question.setString(quiz.getQuestion(id).getQuestion());
  
  std::vector<std::size_t> pos{ 0, 1, 2, 3 };
  std::shuffle(pos.begin(), pos.end(), Random::generator);

  for(std::size_t iii{ 0 }; iii <= 3; ++iii)
  {
    if(pos.at(iii) == 3)
    {
      buttons.at(iii).setText(quiz.getQuestion(id).getCorrectAnswer());
      correctAnswer = iii;
    }
    else
    {
      buttons.at(iii).setText(quiz.getQuestion(id).getDummyAnswer(pos.at(iii)));
    }
  }
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
