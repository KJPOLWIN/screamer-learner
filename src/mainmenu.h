#ifndef MAINMENU_H
#define MAINMENU_H

  #include "textbutton.h"
  #include "state.h"
  #include <SFML/Graphics.hpp>

  class MainMenu
  {
    public:
      MainMenu(sf::Font& font);

      void clickInput(sf::Vector2i clickPosition, State& state);
      void run(sf::RenderWindow& window);

    private:
      sf::Text title{  };
      TextButton startButton{  };
      TextButton optionsButton{  };
      TextButton creditsButton{  };
      TextButton exitButton{  };
  };

#endif
