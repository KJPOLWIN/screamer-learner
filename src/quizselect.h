#ifndef QUIZSELECT_H
#define QUIZSELECT_H

  #include "textbutton.h"
  #include "state.h"
  #include <SFML/Graphics.hpp>

  class QuizSelect
  {
    public:
      QuizSelect(sf::Font& font);

      void clickInput(sf::Vector2i clickPosition, State& state);
      void run(sf::RenderWindow& window);

    private:
      sf::Text title{  };
      TextButton startButton{  };
      TextButton backButton{  };
  };

#endif
