#ifndef MAINMENU_H
#define MAINMENU_H

  #include <SFML/Graphics.hpp>

  class MainMenu
  {
    public:
      MainMenu(sf::Font& font);

      void run(sf::RenderWindow& window);

    private:
      sf::Text title{  };

  };

#endif
