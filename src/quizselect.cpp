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
    backButton{ font, "Go back", sf::Vector2f(100.0f, 930.0f), 50 },
    scrollMenuBegin{ sf::Vector2f(1920, 100) },
    scrollMenuEnd{ sf::Vector2f(1920, 100) }
{
  title.setPosition(100.0f, 100.0f);

  title.setFillColor(Style::textColor);
  backButton.setColor(Style::textColor);

  for(auto& file : std::filesystem::directory_iterator("quiz"))
  {
    filenames.push_back(file.path().u8string());
  }

  //Open files and get titles
  for(std::size_t iii{ 0 }; iii < filenames.size(); ++iii)
  {
    std::fstream file{ filenames.at(iii) };
    nlohmann::json data{  };
    file >> data;

    quizButtons.push_back(TextButton(font, 
                                     data["title"], 
                                     sf::Vector2f(150.0f, 250.0f + iii * 100.0f), 
                                     50));
    quizButtons.back().setColor(Style::textColor);
  }

  scrollMenuBegin.setPosition(0, scrollMenuDrawingBegin - 100);
  scrollMenuEnd.setPosition(0, scrollMenuDrawingEnd);

  scrollMenuBegin.setFillColor(Style::backgroundColor);
  scrollMenuEnd.setFillColor(Style::backgroundColor);

  double scrollMenuHeight{ scrollMenuDrawingEnd - scrollMenuDrawingBegin };
  double buttonsHeight{ 250.0f + quizButtons.size() * 100.0f };
  if(buttonsHeight < scrollMenuHeight)
  {
    scrollbar.setSize(sf::Vector2f(10, scrollMenuHeight));
  }
  else
  {
    scrollbar.setSize(sf::Vector2f(10, pow(scrollMenuHeight, 2) / buttonsHeight));
  }
  scrollbar.setPosition(1900.0f, scrollMenuDrawingBegin);
  scrollbar.setFillColor(Style::textColor);
}
      
void QuizSelect::clickInput(sf::Vector2i clickPosition, State& state)
{
  if(backButton.isClicked(clickPosition))
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
        state = State::Quiz;
      }
    }
  }
}

void QuizSelect::scrollInput(int direction)
{
  if((quizButtons.front().getPosition().y + 100 * direction) <= scrollMenuDrawingBegin + 10
  && (quizButtons.back().getPosition().y + 100 * direction) >= scrollMenuDrawingEnd - 110)
  {
    for(auto& button : quizButtons)
    {
      button.setPosition(sf::Vector2f(button.getPosition().x, 
                                      button.getPosition().y + 100 * direction));
    }

    scroll += 100 * direction;
    double scrollMenuHeight{ scrollMenuDrawingEnd - scrollMenuDrawingBegin };
    scrollbar.setPosition(scrollbar.getPosition().x, scrollMenuDrawingBegin - scroll);
  }
}

void QuizSelect::run(sf::RenderWindow& window)
{
  for(auto& button : quizButtons)
  {
    if(button.getPosition().y > scrollMenuDrawingBegin - 10 
    && button.getPosition().y < scrollMenuDrawingEnd + 10)
    {
      button.draw(window);
    }
  }
  window.draw(scrollMenuBegin);
  window.draw(scrollMenuEnd);
  window.draw(title);
  backButton.draw(window);
  window.draw(scrollbar);
}

std::string QuizSelect::getSelectedQuizFilename()
{
  return filenames.at(selectedQuizFilename);
}
