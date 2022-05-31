#ifndef QUESTION_H
#define QUESTION_H

  #include <string>
  #include <vector>

  class Question
  {
    public:
      Question(std::string question, 
               std::vector<std::string> dummyAnswers, 
               std::string correctAnswer);

      std::string getQuestion();
      std::string getDummyAnswer(std::size_t id);
      std::string getCorrectAnswer();

    private:
      std::string question{ "" };
      std::vector<std::string> dummyAnswers{ 3 };
      std::string correctAnswer{ "" };
  };

#endif
