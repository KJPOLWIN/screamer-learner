#include "state.h"
#include "mainmenu.h"
#include "options.h"
#include "quizselect.h"
#include "quizstate.h"
#include "style.h"
#include <SFML/Graphics.hpp>

  #include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "", sf::Style::Fullscreen);
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(true);

  sf::Font lato{  };
  lato.loadFromFile("font/Lato-Regular.ttf");

  State state{ State::MainMenu };
  State previousState{ State::MainMenu };
  MainMenu mainMenu{ lato };
  Options options{ lato };
  QuizSelect quizSelect{ lato };
  QuizState quizState{ lato };

  sf::Event event{  };
  sf::Clock clock{  };
  double elapsedTime{ 0.0 };
  
  while(window.isOpen())
  {
    elapsedTime = clock.restart().asSeconds();

    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
      else if(event.type == sf::Event::KeyPressed
           && event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }
      else if(event.type == sf::Event::MouseButtonReleased
          && event.mouseButton.button == sf::Mouse::Left)
      {
        sf::Vector2i clickPosition{ sf::Mouse::getPosition(window) };

        if(state == State::MainMenu)
        {
          mainMenu.clickInput(clickPosition, state);
        }
        else if(state == State::Options)
        {
          options.clickInput(clickPosition, state);
        }
        else if(state == State::QuizSelect)
        {
          quizSelect.clickInput(clickPosition, state);
        }
        else if(state == State::Quiz)
        {
          quizState.clickInput(clickPosition);
        }
      }
      else if(event.type == sf::Event::MouseWheelScrolled)
      {
        if(state == State::QuizSelect)
        {
          quizSelect.scrollInput(event.mouseWheelScroll.delta);
        }
      }
    }

    window.clear(Style::backgroundColor);

    switch(state)
    {
      case State::MainMenu:
        mainMenu.run(window);
      break;

      case State::QuizSelect:
        quizSelect.run(window);
      break;

      case State::Quiz:
        if(previousState == State::QuizSelect)
        {
          quizState.loadQuiz(quizSelect.getSelectedQuizFilename());
        }

        quizState.run(elapsedTime, window, state);
      break;

      case State::Credits:
      break;

      case State::Options:
        options.run(window);
      break;

      case State::Exit:
        window.close();
      break;
    }

    previousState = state;

    window.display();
  }

  return 0;
}
