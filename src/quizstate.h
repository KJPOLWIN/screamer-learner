#ifndef QUIZSTATE_H
#define QUIZSTATE_H

  #include "quiz.h"
  #include "question.h"
  #include "textbutton.h"
  #include "state.h"
  #include <SFML/Graphics.hpp>
  #include <vector>

  class QuizState
  {
    public:
      QuizState(sf::Font& font);

      void clickInput(sf::Vector2i clickInput, State& state);
      void run(sf::RenderWindow& window);

    private:
      void loadQuestion(std::size_t id);
      void reset();

      Quiz quiz{  };
      std::size_t currentQuestion{ 0 };

      sf::Text question{  };
      std::vector<TextButton> buttons{  };

      sf::Text questionCounter{  };
  };

#endif
