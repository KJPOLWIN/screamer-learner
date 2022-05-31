#ifndef OPTIONS_H
#define OPTIONS_H

  #include "textbutton.h"
  #include "state.h"
  #include <SFML/Graphics.hpp>

  class Options
  {
    public:
      Options(sf::Font& font);

      void clickInput(sf::Vector2i clickPosition, State& state);
      void run(sf::RenderWindow& window);

    private:
      sf::Text title{  };
      TextButton backButton{  };
  };

#endif
