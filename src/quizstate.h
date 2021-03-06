#ifndef QUIZSTATE_H
#define QUIZSTATE_H

  #include "quiz.h"
  #include "question.h"
  #include "fieldbutton.h"
  #include "jumpscare.h"
  #include "state.h"
  #include <SFML/Graphics.hpp>
  #include <SFML/Audio.hpp>
  #include <vector>

  enum class Phase
  {
    answerSelect,
    resultGlimpse,
    jumpscare,
    resultDisplay
  };

  class QuizState
  {
    public:
      QuizState(sf::Font& font);

      void clickInput(sf::Vector2i clickInput);
      void run(double elapsedTime, sf::RenderWindow& window, State& state);
      void loadQuiz(std::string filename);

    private:
      void loadQuestion(std::size_t id);
      void reset();

      Phase phase{ Phase::answerSelect };
      double timer{ 0.0 };

      double resultGlimpseDuration{ 0.5 };
      double jumpscareDuration{ 1.0 };
      double resultDisplayDuration{ 3.0 };

      Quiz quiz{  };
      std::size_t currentQuestion{ 0 };
      std::size_t correctAnswer{ 0 };
      std::size_t chosenAnswer{ 0 };

      sf::Text question{  };
      std::vector<FieldButton> buttons{  };

      sf::Text questionCounter{  };

      std::size_t jumpscareId{  }; 

      std::vector<sf::Texture> jumpscareTexture{  };
      std::vector<sf::SoundBuffer> jumpscareSoundBuffer{  };
      
      std::vector<Jumpscare> jumpscares{  };

      sf::SoundBuffer yayBuffer{  };
      sf::Sound yaySound{  };
  };

#endif
