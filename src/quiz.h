#ifndef QUIZ_H
#define QUIZ_H

  #include "question.h"
  #include <string>
  #include <vector>

  class Quiz
  {
    public:
      Quiz();

      void loadFromFile(std::string filename);

      Question getQuestion(std::size_t id);
      std::size_t getQuestionCount();

    private:
      std::string title{ "" };
      std::vector<Question> questions{  };
  };

#endif
