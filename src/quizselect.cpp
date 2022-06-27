#include "quizselect.h"
#include "textbutton.h"
#include "style.h"
#include "state.h"
#include "json.hpp"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <vector>
#include <fstream>

#include <iostream>

QuizSelect::QuizSelect(sf::Font& font)
  : title{ "Select quiz", font, 75 },
    startButton{ font, "Start", sf::Vector2f(1620.0f, 930.0f), 50 },
    backButton{ font, "Go back", sf::Vector2f(100.0f, 930.0f), 50 }
{
  title.setPosition(100.0f, 100.0f);

  title.setFillColor(Style::textColor);
  startButton.setColor(Style::textColor);
  backButton.setColor(Style::textColor);

  startButton.setBackgroundColor(Style::backgroundColor);
  backButton.setBackgroundColor(Style::backgroundColor);
  
  for(auto& file : std::filesystem::directory_iterator("quiz"))
  {
    filenames.push_back(file.path().u8string());
    std::cout << file << "\n";
  }

  //Open files and get titles
  for(std::size_t iii{ 0 }; iii < filenames.size(); ++iii)
  {
    std::fstream file{ filenames.at(iii) };
    nlohmann::json data{  };
    file >> data;

    quizButtons.push_back(TextButton(font, 
                                     data["title"], 
                                     sf::Vector2f(100.0f, 200.0f + iii * 100.0f), 
                                     50));
    quizButtons.at(iii).setBackgroundColor(Style::backgroundColor);
  }
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
  else
  {
    for(std::size_t iii{ 0 }; iii < quizButtons.size(); ++iii)
    {
      if(quizButtons.at(iii).isClicked(clickPosition))
      {
        selectedQuizFilename = iii;
        state == State::Quiz;
      }
    }
  }
}

void QuizSelect::run(sf::RenderWindow& window)
{
  window.draw(title);
  startButton.draw(window);
  backButton.draw(window);
  for(auto& button : quizButtons)
  {
    button.draw(window);
  }
}

std::string QuizSelect::getSelectedQuizFilename()
{
  return filenames.at(selectedQuizFilename);
}
