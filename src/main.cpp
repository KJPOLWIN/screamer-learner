#include "state.h"
#include "mainmenu.h"
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "", sf::Style::Fullscreen);
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(true);

  sf::Font lato{  };
  lato.loadFromFile("font/Lato-Regular.ttf");

  State state{ State::MainMenu };
  MainMenu mainMenu{ lato };

  sf::Event event{  };
  
  while(window.isOpen())
  {
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
    }

    window.clear();

    switch(state)
    {
      case State::MainMenu:
        mainMenu.run(window);
      break;

      case State::QuizSelect:
      case State::Quiz:
      case State::Credits:
      case State::Options:
      break;
    }

    window.display();
  }

  return 0;
}
