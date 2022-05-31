#include "question.h"  
#include <string>
#include <vector>

Question::Question(std::string question, 
                   std::vector<std::string> dummyAnswers, 
                   std::string correctAnswer)
  : question{ question },
    dummyAnswers{ dummyAnswers },
    correctAnswer{ correctAnswer }
{
  
}

std::string Question::getQuestion()
{
  return question;
}

std::string Question::getDummyAnswer(std::size_t id)
{
  return dummyAnswers.at(id);
}

std::string Question::getCorrectAnswer()
{
  return correctAnswer;
}
