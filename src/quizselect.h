#ifndef QUIZSELECT_H
#define QUIZSELECT_H

  #include "textbutton.h"
  #include "state.h"
  #include <SFML/Graphics.hpp>
  #include <vector>

  class QuizSelect
  {
    public:
      QuizSelect(sf::Font& font);

      void clickInput(sf::Vector2i clickPosition, State& state);
      void run(sf::RenderWindow& window);

      std::string getSelectedQuizFilename();

    private:
      sf::Text title{  };
      TextButton backButton{  };
      std::vector<TextButton> quizButtons{  };
      std::vector<std::string> filenames{  };

      std::size_t selectedQuizFilename{ 0 };
  };

#endif
